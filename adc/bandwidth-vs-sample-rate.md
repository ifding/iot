
## Bandwidth vs Sample Rate

- Bandwidth is not how many measurements are taken per second, that is the sampe rate and they are different!
- Bandwidth is maximum frequency of an input signal which can pass through the analog front end of the scope with minimal amplitude loss (from the tip of the probe to the input of the oscilloscope ADC).

- Sample rate is the maximum number of samples the scope can take per second and will usually be across all of the channels (e.g. a 4Gsp/s 4 channel scope won't necessarily be able to do more than 1 Gsa/s on each indiviual channel - check the specs). This wasn't a specification for analog scopes, but is of course for digital scopes.
- Also take care with the exact wording of a scopes sample rate as there are various tricks a scope manufacturer can play to make the spec sound better - generally you are interested in the "real time" sample rate and not a repetitive signal sample rate.

Some general recommendations for scope bandwidth based on these issues:

- For general analog signals use a scope with a bandwidth specification at least 2x the highest frequency component in the signal.

- For digial signals where you care about seeing what noise is occuring - determine the fastest signal rise/fall time you are interested in and work out the bandwidth using the formula Bandwidth = 0.35/Rise time.
- Yes, rise time is what is important here not the frequency of the signal. How the signal changes state is what you need to be able to see in this case, not how often it changes state which will be a lower specification.
- To capture the true shape of the signal, you need a scope with 3x to 5x the bandwidth you calculated for your signal.
- For example the typical IO pin output rise and fall time for a PIC32MX7xx microcontroller is 5nS.  0.35 / 5nS (0.000000005) = 70000000 = 70MHz.  So a 200MHz scope would do very well at showing the real noise present at this switching speed and a 350MHz or faster scope would be fantastic.

- For digital signals where you only care about seeing what states the signal is changing between apply the general analog approach or just accept your signals will be getting rounded off corners and reduced amplitude as you reach or exceed the scopes bandwidth spec.
- If this is OK then you can happily exceed the bandwidth spec and care more about the scopes sample rate spec. 
- Just remember when you find yourself looking at a signal of some clocked bus which looks fine but which isn't working properly it will be because there is more happening in the signals than you can see, a typical example being ringing / bounce on a CLK signal extra clock events to be seen by a device being clocked.

As with all things in electronic design you are often working with balancing compromises, in this case what you can afford vs how accurate what you see is.  If you have less than ideal bandwidth then your scope is still fine for lots of electronics tasks but just remember that you will not necessarily be seeing all of the true peeks of your signals and the sharpness of the edges.

### Limit of sample rate

lets say we sample at 10 KHz with a 10 bit ADC.  This means we get 10,000 * 10 bits of data per second 100K/8 = 12.5KB (Kilo Bytes, not bits) per second.  The ATMEL 328 on an arduino uno has 2 KB of RAM which means we could fill the total ram on the microcontroller every .16 seconds.  The take away here is we cannot buffer much data on the Arduino.

Now lets look at the interface.  The Arduino Uno does serial over USB using another ATMEL 328 (or an FTDI on older boards).  There is some buffering and other stuff that is going to slow down your throughput but lets say you run at a baud rate of 115200 (or 115200 bits per second).  At 10KHz and 10 bits per sample we would need to transfer 100,000 bits per second, which is just under that limit, however the baud rate of 115200 does guarantee a throughput of 115200 bits per second, you have to take into acount start and stop bits, bus collisions since we are using USB (a non deterministic bus), and much more.  In addition there are things on the Arduino that are going to take some amount of time, preventing us from transfering at our maximum rate.  For example the time it takes for the ADC to settle, the time to get the data from the ADC register to SRAM then from SRAM to the UART send buffer, etc.

## Reference

- [Bandwidth vs Sample Rate](http://www.electronic-products-design.com/geek-area/electronics/test-and-measurement/oscilloscopes/bandwidth-vs-sample-rate)
- [How to have a sample rate over 10khz with arduino mega 2560 and labview?](https://forums.ni.com/t5/LabVIEW-Interface-for-Arduino/How-to-have-a-sample-rate-over-10khz-with-arduino-mega-2560-and/td-p/3412542)
