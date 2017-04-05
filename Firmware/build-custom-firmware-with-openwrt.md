
# Build Custom Firmware with OpenWrt

For example, TP-Link TL-WR740N, it has just 4 MB of flash storage, Image contains squashfs (which is compressed) that enable really efficient usage of storage. All additional packages are installed into overlay file-system, which doesn't support compression so you will root file-system really quick.

OpenWrt provides Image Builder which enables you to select packages which are included in base installation, and thus ends up in squash file-system nicely reducing need for flash storage. Even better, you can also exclude packages which you are not going to use. However, to make this really useful you also have to provide files directory which contains modifications needed to make your specific router configuration work (like IP address, OpenVPN keys, n2n keys and similar modification).

### 1. preparing build workstation

OpenWrt requires that gcc, g++, binutils, patch, bzip2, flex, bison, make, gettext, pkg-config, unzip, the glibc headers, the libz headers, the ncurses headers and the perl-XML-parser are installed on the build workstation. 

You need to install necessary dev tools:

```
sudo apt-get install subversion build-essential libncurses5-dev zlib1g-dev gawk git ccache gettext libssl-dev xsltproc wget
```

### 2.Download the OpenWrt image builder

First you need to determine the deivce platform, i.e. the CPU architecture, MIPS or ARM etc.

P-Link TL-WR740N, ar71xx.

Download the OpenWrt Chaos Calmer 15.05.1 image builder from:

```
https://downloads.openwrt.org/chaos_calmer/15.05.1/
```

Extract the image builder to wherever you want, i.e. the home folder

```
tar -xf OpenWrt-ImageBuilder-15.05.1-ar71xx-generic.Linux-x86_64.tar.bz2 -C ~/
cd ~/OpenWrt-ImageBuilder
```

### 3.Choose which packages to add and remove

If you want to remove the **LuCI** and related packages to build OpenWrt custom firmware, below the package list:

```
libiwinfo-lua liblua libubus-lua libuci-lua
lua luci luci-app-firewall luci-base luci-lib-ip
luci-lib-nixio luci-mod-admin-full luci-proto-ipv6
luci-proto-ppp luci-theme-bootstrap uhttpd uhttpd-mod-ubus
```

You can safely remove all IPv6 related packages to save some free space.

### 4.Build the installable OpenWrt image

The **PACKAGES** variable is used to add or remove the packages to the final build, add a minus(-) sign before the package you want to exclude.

`make info` command to get available build profile and select a suitable profile.

```
nano include/target.mk
	# Removed ppp pppoe from default_packages section
```

A complete make command:

```
make -j4 image PROFILE=TLWR740 PACKAGES=\
  "-libiwinfo-lua -liblua -libubus-lua -libuci-lua -lua \
   -luci -luci-app-firewall -luci-base -luci-lib-ip \
   -luci-lib-nixio -luci-mod-admin-full -luci-proto-ipv6 \
   -luci-proto-ppp -luci-theme-bootstrap -uhttpd -uhttpd-mod-ubus \
   -ip6tables -ppp"
```

You need to write down the files you modified. For example, you don't want to install dnsmasq (because ADSL modem will provide DHCP service for my network) ppp and nat but added openssl, n2n and muninlite (which is munin node written in C). You also modify /etc/config/wireless, create `files` directory, copy the content of wireless and put it in `files` folder, like this:

```
make image PROFILE=TLWR740 PACKAGES="-dnsmasq -ip6tables -ppp \
 -ppp-mod-pppoe -kmod-ipt-nathelper -odhcp6c \
 openvpn-openssl n2n muninlite" FILES=files/
````

When the build is complete you can get the flashable OpenWrt images under the image builder's bin folder, `~/OpenWrt-ImageBuilder/bin/ar71xx/`

### 5.Before flashing the OpenWrt custom firmware

Check the size of the flashable bin file, the **squashfs factory** image is around 3.8 MB for routers with 4 MB flash, precisely 3932160 bytes, double check it before flashing.

```
du -b openwrt-15.05.1-ar71xx-generic-tl-mr3220-v2-squashfs-factory.bin
```

Flash the new openwrt minimal build from the web interface or via serial port.

Also, you can copy the created image to router and start upgrade with

```
scp bin/ar71xx/openwrt-ar71xx-generic-tl-wr740n-v4-squashfs-sysupgrade.bin root@192.168.1.1:/tmp/
ssh root@192.168.1.1 sysupgrade -v /tmp/openwrt-ar71xx-generic-tl-wr740n-v4-squashfs-sysupgrade.bin
```

Install new firmware with mtd:

```
scp bin/ar71xx/openwrt-ar71xx-generic-tl-wr703n-v1-squashfs-factory.bin root@192.168.1.1:/tmp
root@@tp-router:/tmp# mtd -r write /tmp/openwrt-ar71xx-generic-tl-wr703n-v1-squas  
hfs-factory.bin firmware  
Unlocking firmware ...

Writing from /tmp/openwrt-ar71xx-generic-tl-wr703n-v1-squashfs-factory.bin to firmware ...  
Rebooting ...  
```

### Reference

* [Building custom OpenWRT image for home router](http://blog.rot13.org/2014/03/building-custom-openwrt-image-for-home-router.html)

* [Generating my own OpenWRT Custom Firmware](https://www.andrewklau.com/generating-my-own-openwrt-custom-firmware/)