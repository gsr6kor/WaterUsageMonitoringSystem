Water-Saver in Urban Households
     

Overview
Water, an essential commodity across the globe has overtime been exploited. In a country such as India with its many natural reservoirs of fresh water, still there are plenty of regions that face water scarcity. We never thought of running out of drinking water. But with Cape Town becoming the first global city to run out of drinking water, our metro cities like Bengaluru, Chennai, and Delhi are not far behind in this situation.
Added to this plight is our current pandemic situation of Covid-19 that has bought fears in to the minds of all households. We relentlessly wash our hands, wash ourselves whenever we step into our home after an unavoidable grocery and essential commodities shopping.
What is the problem?
So at times like these when personal hygiene is taking a forefront and we spend increasing amounts of time indoors, we need to really monitor and optimize usage of water in our households not only for conserving our natural resource but also not to burn a hole in one’s pocket. But how do we do that when we don’t have a system to offer us a transparent picture on our daily usage. Most of us are left clueless on large bills at the end of every month.
How can technology help?
We believe that technologies like cloud services, IoT , data analytics can help to gather the huge amount of data we receive from consumers, provide them with accurate details on quantity, usage and methods of optimization. This will give a transparent and holistic picture to the consumer.
Idea
The solution we propose is an IoT based water usage monitoring system.
When data packs were introduced, we had many apps to monitor how much data we use, to set an upper limit on the daily /weekly usage, to check what apps used more data. Similar is the story with Battery power consumption in our smartphones. We have analysis on its consumption. This has enabled consumers to be more aware of where their usage is exceeding and how they could optimize based on the suggestions.
We would like to extend this same principle to water usage and later on to other factors of consumption in households like electricity and LPG.
People largely are unaware of the amount of water they use to carry out their day to day activities. Using technology services like cloud, IoT, data analytics we create a software framework to present to the consumers how much water they consume categorically (Categories of usage. Kitchen—Drinking—Washing—Personal Hygiene-washrooms—misc.). The system will monitor the volume of water dispensed from all outlets in kitchen, water purifiers, washing machines, wash room area, wash basins. These details are then transferred to cloud network.
Data analytics and ML algorithms can be deployed to study the usage pattern in a family and provide an optimised plan for usage of water in our everyday activities. This would help to bring more transparency to our monthly bills, where we use more than is required and where we need to minimise.                                                                                                                 It would be like an energy and money saver solution for the family.
Architecture

1. Use a controller with sensor and a Wi-Fi interface module to calculate the volume of water dispensed. Send data over Wi-Fi using MQTT to IBM Watson IoT Platform.
For prototyping we have used NodeMCU.

2. Send the Optimized/Best Water Usage data collected from affiliated Organisation to create Prediction model. The model also takes input from delta factors that are sudden changes in society or climate such as pandemic situation that has brought an increased usage to maintain hygiene.

3. We provide an interactive web based dashboard application that fetches all the data from the cloud and provide the statistics to our customer for understanding their usage. The dashboard would present the day to day usages of water in different categories mentioned above in forms of bar-graphs and pie charts.



Demo Url
https://youtu.be/pNHuQizcIbI

Dashboard UI designed using NodeRed
https://watermoniterdecipher.eugb.mybluemix.net/ui/#!/1?socketid=r8GvHnwk1U0UgR4rAAAN#!%2F3%3Fsocketid=NqX7D1mWSim8GcNhAAAE

Built with:
NodeMCU - Arduino IDE with ESP8266library
IBM Watson IoT                                                           				             
IBM Cloud Foundry Apps								          
Node-Red										            
IBM Cloudant 											 
IBM API Connect 

Opportunities
The magnitude of opportunities that we can scale from this technology is quite large.
The system can replace the current meters.It would be like a smart meter that updates the databases of service providers and consumers.
We can extend the service to track Power usage and LPG consumption in all urban households.
We can bring Android/iOS Apps for smartphones to track usage apart from the web based dashboards.
What we want for the future is a Connected Energy Saver for Urban homes. We enter in partnership with service providers to allow customers to make their homes more sustainable.

Connected Energy Saver at Urban households
Conclusions 
This brings a cut-down not only on our consumption of natural resources but also on our monthly expenditure on the same now knowing where we could save. In these difficult times when most of our time is spent indoors heavily dependent on these, we tend to neglect the usage. But when we are aware of how much we consume, and if it’s more than what we should, then we will draw a line and be more sustainable. 

	

                                                 







