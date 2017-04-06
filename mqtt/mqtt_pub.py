import sys
import datetime
import time
import paho.mqtt.client as mqtt

client=mqtt.Client()

# mqtt broker
client.connect('iot.eclipse.org',1883)

# get the current timestamp
timestamp =datetime.datetime.strftime(datetime.datetime.now(), '%Y-%m-%d %H:%M:%S)

payload = "{\"device_id\": 001, \"timestamp\": " + str(timestamp) + ", \"message\": hellow world }"                                    
                                      
# topic, message 
client.publish('iot/tiger', payload)
