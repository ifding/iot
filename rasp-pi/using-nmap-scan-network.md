# Using nmap to scan network to find a Raspberry Pi

### NMAP command

#### nmap IP scanning

The nmap command (Network Mapper) is a free and open-source tool for network discovery, available for Linux, Mac OS, and Windows. You can use it to scan entire network or selected host. It is useful to test the firewall rules. 

According to nmap man page:

Nmap uses raw IP packetsin novel ways to determine what hosts are available on the network,what services (application name and version) those hosts are offering,what operating systems (and OS versions) they are running, what type ofpacket filters/firewalls are in use, and dozens of othercharacteristics. While Nmap is commonly used for security audits, manysystems and network administrators find it useful for routine taskssuch as network inventory, managing service upgrade schedules, andmonitoring host or service uptime.

* To install on Linux: `apt-get install namp`
* To install on Mac Os: `brew install nmap`

To use nmap to scan the devices on your network, you need to know the subnet you are connected to. 

First find your own IP address, `ifconfig`, for example, if your IP address is `192.168.1.106`, this means that the Pi must be also within this range. The notation of this subnet range is `192.168.1.0/24` (from `192.168.1.0` to `192.168.1.255`).

Second use the `nmap` command with `-sn` flag (ping scan) on the whole subnet range.

```
nmap -sn 192.168.1.0/24
```

Ping scan just pings all the IP addresses to see if they respond. For each device that responds to the ping, the output shows the hostname and IP address.

```
Nmap scan report for 192.168.1.1
Host is up (0.0063s latency).
Nmap scan report for 192.168.1.2
Host is up (0.0034s latency).
Nmap scan report for 192.168.1.5
Host is up (0.0066s latency).
```

OR

```
nmap 192.168.1.0/24
```

The result of the command depends on the network:

```
Nmap scan report for 192.168.1.10
Host is up (0.045s latency).
Not shown: 999 closed ports
PORT STATE SERVICE
22/tcp open ssh
```

After you got the IP, you can use ssh to get access to the R-Pi:

```
ssh pi@192.168.1.10
```

I highly recommend to change password when you logged in at first time.


#### nmap port scanning

TCP Connect scanning for network 192.168.1.0/24

```
nmap -v -sT 192.168.1.0/24
```

nmap TCP FIN scanning

```
nmap -v -sF 192.168.1.0/24
```

nmap TCP SYN (half-open) scanning

```
nmap -v -sS 192.168.1.0/24
```

nmap TCP Null scanning
It is usefull to check if firewall protecting against this kind attack or not:

```
nmap -v -sN 192.168.1.0/24
```

nmap UDP scanning

```
nmap -v -O 192.168.1.0/24
```

nmap remote software version scanning (what software version opening the port)

```
nmap -v -sV 192.168.1.0/24
```

More information

```
man nmap
```
