import paho.mqtt.client as mqtt

client=mqtt.Client()

# mqtt broker
client.connect('iot.eclipse.org',1883)

# topic, message 
client.publish('iot/tiger','Go Tigers!')
