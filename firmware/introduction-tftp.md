# An Introduction to TFTP

### What is TFTP

```sh
man tftp
```

```
NAME
	tftp  -- trivial file transfer program
SYNOPSIS
	tftp [-e] [host] [port]
DESCRIPITION
	The tftp utility is the user interface to the Internet TFTP (Trivial File Transfer Protocol), which allows users to transfer files to and from a remote machine. The remote host (and optional port) may be specified on the command line.

	The optional -e argument sets a binary transfer mode as well as setting the extended options as if tout, tsize, and blksize 65464, had been given.
```

### Why TFTP

* It is developed in the 1970s for computers lacking sufficient memory or disk space.

* Protocol of choice for the initial stages of any network booting strategy like BOOTP, PXE, BSDP, etc., when targeting from highly resourced computers to very low resourced Single-board computers (SBC) and System on a Chip (SoC).

* It is also used to transfer firmware images and configuration files to network appliances like routers, firewalls, IP phones, etc.

* Implemented on top of UDP/IP protocols using port number 69, FTP uses TCP ports 20 and 21.

* Simple and easy to implement, so it only reads and writes from or to a remote server.

* Unlike FTP, TFTP has no login feature.

* TFTP implemented using UDP, it is generally only used on local area networks (LAN).

### How TFTP works

* Uses client and server to make connections between two devices.

* From a client, individual files can be uploaded to or downloaded from the server.

* In this diagram green lines show interfaces available to users of the stack, red lines show internal to the TCP/IP system.

![Overview_TFTP.gif]({{ site.url }}images/posts/2017/3/Overview_TFTP.gif)
[Image source](https://doc.hcc-embedded.com/display/TFTP120/Introduction)

### Installing and Testing

* Install following packages

```
$ sudo apt-get install xinetd tftpd tftp
```

* Create /etc/xinetd.d/tftp and put this entry

```
service tftp
{
protocol        = udp
port            = 69
socket_type     = dgram
wait            = yes
user            = nobody
server          = /usr/sbin/in.tftpd
server_args     = /tftpboot
disable         = no
}
```

* Create a folder /tftpboot  this should match whatever you gave in server_args. mostly it will be tftpboot

```
$ sudo mkdir /tftpboot
$ sudo chmod -R 777 /tftpboot
$ sudo chown -R nobody /tftpboot
```

* Restart the xinetd service

```
$ sudo /etc/init.d/xinetd stop
$ sudo /etc/init.d/xinetd start
```

Now tftp server is up and running

* Create a file named test with some content in /tftpboot path of the tftp server

```
$ ls / > /tftpboot/testte
$ sudo chmod -R 777 /tftpboot
$ ls /tftpboot/test -lh
-rw-r--r-- 1 thalib thalib 159 2010-03-05 20:48 test
```

Obtain the ip address of the tftp server using ifconfig command, say, 192.168.1.2

* In some other system (a client) follow the following steps

```
$ tftp 192.168.1.2
tftp> get test
Sent 159 bytes in 0.0 seconds
tftp> quit
$ ls test -lh
-rw-r--r-- 1 thalib thalib 159 2010-03-05 20:48 test
```

Thats it. Our tftp server is working fine.

### Reference

* [wikipedia](https://en.wikipedia.org/wiki/Trivial_File_Transfer_Protocol)
* [TFTP - Definition of Trivial File Transfer Protocol](https://www.lifewire.com/definition-of-tftp-817576)
* [Installing and Testing TFTP Server in Ubuntu/Debian](https://mohammadthalif.wordpress.com/2010/03/05/installing-and-testing-tftpd-in-ubuntudebian/)
