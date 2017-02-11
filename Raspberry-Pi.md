# Raspberry-Pi

=========
>02-10-2017

## Terminology

* GPIO - General Purpose Input/Output, many third party add-on boards that attach to the Raspberry Pi and extend its functionality: motor controllers, LEDs, buttons, sensors, microcontrollers, LCDs, ADCs and DACs.

* HAT - Hardware Added On Top, it standardizes the physcical form factor for add-on boards, and includes a provision for the B+ to automatically identify and initialize HATs at startup. It uses an I2C bus to read a EEPROM on the HAT.

* CSI Bus - The Camera Serial Interface (CSI) Bus is used to enable the R-Pi processor to use an external digital camera. Connection to the CSI bus is via a 15-way 'flat-flex' connector on the R-Pi that provides a MIPI CSI-2 hardware interface for a figital camera (used for stills or video). It is capable of extremely high data rates, adn it exclusively carries pixel data.

* HDMI - High Definition Multimedia Interface. One of the interfaces to the monitor

* Pi-Camera - The Raspberry pi Camera Module is a custom designed add-on for R-Pi. The camera is connectd to the processor on the R-Pi via the CSI bus, a higher bandwidtn link that carries pixel data from the camera back to processor. 

* I2C - Inter-Integrated-Circuit bus, a useful bus that allows data exchange between microcontrollers and peripherals with a minimum of wiring. I2C is a multi-device bus used to connect low-speed peripherals to computers and embedded systems. The R-Pi supports this interface on its GPIO header and it is a great way to connect sensors and devices.

* SPI - Serial Peripheral Interface (SPI) a cousin of I2C with similar applications. SPI on the Pi allows for up to two attached devices, while I2C potentially allows for many devices, as long as their addresses don't conflict.

## Connecting To the Ports

* 40-pin connector

The I2C and SPI interfaces each require some additional configuration and initialization.

(/images/pin-labels-on-pi-ver2.png)
Pi Serial Bus Pins

(/images/pin-labels-on-wedge.png)
Wedge Serial Bus Pins

(/images/bplus-gpio.png)
Schematic snippet for 40-Pin GPIO connector (J8)

## Reference

*[Raspberry Pi SPI and I2C Tutorial](https://learn.sparkfun.com/tutorials/raspberry-pi-spi-and-i2c-tutorial)
