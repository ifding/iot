
## upload files via telnet session

1. telnet a.b.c.d | tee telnet.log
2. login and go to the file
3. cat file.txt
4. close session
5. check the telnet.log file

## transfer files to embedded system over serial

For example, transfer "lrz" program and install it in OpenWrt

First thing download the package containing the lrz program([lrzsz_0.12.20-1_ar71xx.ipk](http://downloads.openwrt.org/backfire/10.03/ar71xx/packages/lrzsz_0.12.20-1_ar71xx.ipk)).

Convert it from binary to text:

```
$ xxd -g1 lrzsz_0.12.20-1_ar71xx.ipk > output.txt
```

We need to remove the "00xxxxxx:" from beginning of each line and the 16 chars representation at end of each line:

```
$ sed -i 's/^\(.\)\{9\}//g' output.txt
$ sed -i 's/\(.\)\{16\}$//g' output.txt
```

Now let us convert this text back to binary to confirm it works:

```
$ for i in $(cat output.txt) ; do printf "\x$i" ; done > mylrz
```

Let us check if they have same binary sequence:

```
$ md5sum mylrz 
43e743e2b7f5c34e07113ccd50c620a5  mylrz
$ md5sum lrzsz_0.12.20-1_ar71xx.ipk 
43e743e2b7f5c34e07113ccd50c620a5  lrzsz_0.12.20-1_ar71xx.ipk
```

Then the command become this long line:

```
$ j=0; echo -n -e "ec" > /dev/ttyUSB0; echo -n -e "ho" > /dev/ttyUSB0; echo -n -e " \"" > /dev/ttyUSB0; for i in $(cat output.txt); do j=$(($j+1)); echo -n -e "$i" > /dev/ttyUSB0; echo -n -e " " > /dev/ttyUSB0; if [ $(expr $j % 16) -eq 0 ]; then echo -n -e "\" " > /dev/ttyUSB0; echo -n -e ">>" > /dev/ttyUSB0; echo -n -e "lr" > /dev/ttyUSB0; echo -n -e "z" > /dev/ttyUSB0; echo " " > /dev/ttyUSB0; echo -n -e "ec" > /dev/ttyUSB0; echo -n -e "ho" > /dev/ttyUSB0; echo -n -e " \"" > /dev/ttyUSB0; fi; done; echo -n -e "ec" > /dev/ttyUSB0; echo -n -e "ho" > /dev/ttyUSB0; echo "\"" > /dev/ttyUSB0
```

Now run picocom and verify if file lrz file was created:

```
root@OpenWrt:/# ls -l lrz
-rw-r--r--    1 root     root        183113 Jan  1 01:19 lrz
```

Give it permission to execute and move to /usr/bin:

```
root@OpenWrt:/# chmod 555 lrz
root@OpenWrt:/# mv lrz /usr/bin/
```

Execute the lrz command to receive file:

```
root@OpenWrt:/# lrz -Z
```

Leave picocom program (Crl+A+X)

### Reference:

* [How to transfer files to a Linux embedded system over serial](https://acassis.wordpress.com/2012/10/21/how-to-transfer-files-to-a-linux-embedded-system-over-serial/)
