import paho.mqtt.client as mqtt

client=mqtt.Client()

# mqtt broker
client.connect('iot.eclipse.org',1883)

# topic
client.subscribe('iot/tiger')

def on_message(client, userdata, msg):
    print(msg)
    print "Topic: ", msg.topic+' Message: '+str(msg.payload)

client.on_message=on_message

# loop
client.loop_forever()
