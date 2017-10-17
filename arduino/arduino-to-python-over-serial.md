# Arduino values to Python over Serial

## Arduino side

Send two bytes, a high byte, and a low byte, this concept is called most significant byte, and least significant byte.

```c
void setup() {
  // connect to serial
  Serial.begin(9600);
}
 
void loop() {
 
  // read value from analog pin
  int sensorValue = analogRead(A0);
  
  // get the high and low byte from value
  byte high = highByte(sensorValue);
  byte low = lowByte(sensorValue);
 
  // write the high and low byte to serial
  Serial.write(high);
  Serial.write(low);
 
}
```

## Python side

Then on the Python side, we can use pySerial to read two bytes, and convert using the formula Arduino gave us.

```py
import serial
 
# open our serial port at 9600 baud
dev = '/dev/cu.usbmodem1411'
with serial.Serial(dev, 9600, timeout=1) as ser:
 
  while True:
 
    # read 2 bytes from our serial connection
    raw = ser.read(size=2)
 
    if raw:
 
      # read the high and low byte
      high, low = raw
 
      # add up our bits from high and low byte
      # to get the final value
      val = ord(high) * 256 + ord(low)
 
      # print our voltage reading
      # https://www.arduino.cc/en/Tutorial/ReadAnalogVoltage
      print round(val * ( 5.0 / 1023.0), 2)
```

One thing to take into consideration is, if we do not have voltage sent to the analog pin the result will be random and invalid.


## Reference

- [Arduino values to Python over Serial](https://nessy.info/?p=1074)
