#include <Arduino.h>
#include <EEPROM.h> 
#define  USE_SERIAL Serial
#include <ESP8266WiFi.h> 
#include <PubSubClient.h>

#define ORG "4taewe"
#define DEVICE_TYPE "WaterSensor"
#define DEVICE_ID "34512"
#define TOKEN "yjSl_cqB_yK7aI*6A7"
//-------- Customise the above values --------

char server[] = ORG ".messaging.internetofthings.ibmcloud.com";
char topic[] = "iot-2/evt/status/fmt/json";
char authMethod[] = "use-token-auth";
char token[] = TOKEN;
char clientId[] = "d:" ORG ":" DEVICE_TYPE ":" DEVICE_ID;


WiFiClient wifiClient;
PubSubClient client(server, 1883, NULL, wifiClient);


void  startWIFI (void);
// Variable init
const  int buttonPin = 4; // variable for D2 pin
const  int ledPin = LED_BUILTIN;
char push_data [ 200 ]; // string is used to send info to the server
int addr = 0 ; // endereço eeprom
byte sensorInterrupt = 0 ; // 0 = digital pin 2

// The hall-effect flow sensor outputs approximately 4.5 pulses per second per
// liter / minute of flow.
float calibrationFactor = 4.5 ;

volatile byte pulseCount;

float flowRate;
unsigned  int flowMilliLitres;
unsigned  long totalMilliLitres;

unsigned  long oldTime;
 
// SSID and PASSWORD for the AP (swap the XXXXX for real SSID and password)
const  char * ssid = "xxxxx" ;
const  char * password = "xxxxx";

void  ICACHE_RAM_ATTR pulseCounter (void);
void  setup () {
    Serial. begin (115200); // Start the Serial communication to send messages to the computer
    delay ( 10 );
    Serial. println ('\ n');

    startWIFI ();
  
    // Initialization of the variable "buttonPin" as INPUT (D2 pin)
    pinMode (buttonPin, INPUT);
  
    // Two types of blinking
    // 1: Connecting to Wifi
    // 2: Push data to the cloud
    pinMode (ledPin, OUTPUT);
    
    pulseCount = 0 ;
    flowRate = 0.0 ;
    flowMilliLitres = 0 ;
    totalMilliLitres = 0 ;
    oldTime = 0 ;

    digitalWrite (buttonPin, HIGH);
     attachInterrupt ( digitalPinToInterrupt (buttonPin), pulseCounter, RISING);

}

void  loop () 
{
    if (WiFi. status () == WL_CONNECTED && ( millis () - oldTime)> 1000 ) // Only process counters once per second
    {
        // Disable the interrupt while calculating flow rate and sending the value to
        // the host
        detachInterrupt (sensorInterrupt);

        // Because this loop may not complete in exactly 1 second intervals we calculate
        // the number of milliseconds that have passed since the last execution and use
        // that to scale the output. We also apply the calibration Factor to scale the output
        // based on the number of pulses per second per unit of measure (liters / minute in
        // this case) coming from the sensor.
        flowRate = (( 1000.0 / ( millis () - oldTime)) * pulseCount) / calibrationFactor;

        // Note the time this processing pass was executed. Note that because we've
        // disabled interrupts the millis () function won't actually be incrementing right
        // at this point, but it will still return the value it was set to just before
        // interrupts went away.
        oldTime = millis ();

        // Divide the flow rate in liters / minute by 60 to determine how many liters have
        // passed through the sensor in this 1 second interval, then multiply by 1000 to
        // convert to milliliters.
        flowMilliLitres = (flowRate / 60 ) * 1000 ;

        // Add the milliliters passed in this second to the total cumulative
        totalMilliLitres += flowMilliLitres;

        unsigned  int frac;

        // Print the flow rate for this second in liters / minute
        Serial. println ( " Flow rate: " );
        Serial. println ( int (flowRate)); // Print the integer part of the variable
        Serial. println ( " . " ); // Print the decimal point
        // Determine the fractional part. The 10 multiplier gives us 1 decimal place.
        frac = (flowRate - int (flowRate)) * 10 ;
        Serial. println(frac, DEC); // Print the fractional part of the variable
        Serial. print( " L / min " );
        // Print the number of liters flowed in this second
        Serial. println( "   Current Liquid Flowing: " ); // separator output
        Serial. print(flowMilliLitres);
        Serial. print( " mL / Sec " );

        // Print the cumulative total of liters flowed since starting
        Serial. println( "   Output Liquid Quantity: " ); // separator output
        Serial. print(totalMilliLitres);
        Serial. println( " mL " );

        if (!!!client.connected()) 
        {
            Serial.print("Reconnecting client to ");
            Serial.println(server);
            while (!!!client.connect(clientId, authMethod, token))
            {
              Serial.print(".");
              delay(500);
            }
            Serial.println();
        }

          String payload = "{\"myName\":\"ESP8266.WaterFlowMeasurement\",\"CurrentFlow.mlPerSec\":";
          payload += flowMilliLitres;
          payload+=",\"TotalFlow.mlPerSec\":";
          payload += totalMilliLitres;
          payload += "}}";
 
    Serial.print("Sending payload: ");
    Serial.println(payload);
 
    if (client.publish(topic, (char*) payload.c_str())) 
    {
        Serial.println("Publish ok");
    } 
    else 
    {
        Serial.println("Publish failed");
    }
    pulseCount = 0 ;
    attachInterrupt(sensorInterrupt, pulseCounter, FALLING); 
   }  
   else if (WiFi.status()!= WL_CONNECTED) 
   {
       startWIFI();
   }
}
/*
Insterrupt Service Routine
 */
void  pulseCounter () {
    // Increment the pulse counter
     pulseCount ++;
}

void  startWIFI ( void ) {
    digitalWrite (ledPin, HIGH);   // turn the LED on (HIGH is the voltage level)
    delay ( 100 );              
    
    WiFi. begin (ssid, password); // Connect to the network
    Serial. print ( " Connecting to " );
    Serial. print (ssid);
    Serial. println ( " ... " );
    oldTime = 0 ;
    int i = 0 ;
    digitalWrite (ledPin, LOW);    // turn the LED off by making the voltage LOW
    delay ( 100 );         
    
    while (WiFi.status()!= WL_CONNECTED) { // Wait for the Wi-Fi to connect
        digitalWrite (ledPin, HIGH);   // turn the LED on (HIGH is the voltage level)
        delay ( 2000 );
        Serial. print (++ i);
        Serial. print ( ' . ' );
        digitalWrite (ledPin, LOW);    // turn the LED off by making the voltage LOW
        delay ( 100 );  
    }
    delay ( 2000 );
    Serial. print ( '\n' );
    Serial. println ( " Connection established! " );
    Serial. println( " IP address: \t " );
    Serial. print(WiFi. localIP ()); // Send the IP address of the ESP8266 to the computer

}
