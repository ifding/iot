
# Compiling OpenWrt from source

Knowing how to build from source is important for developers and others that want to change the default installation image.

uClibc is a C library for developing embedded Linux systems. It is much smaller than the GNU C Library, but nearly all applications supported by blibc also work perfectly with uClibc.

Porting applications from glibc to uClibc typically involves just recompiling the source code. uClibc even supports shared libraries and threading.


### 1. Quick HOWTO

1) Get the OpenWRT environment:

```
$ git clone https://github.com/openwrt/openwrt.git
$ cd openwrt
```

2) Get the feeds

```
$ cp feeds.conf.default feeds.conf
$ echo "src-hg lightSensor-daemon http://www.aboehler.at/hg/lightSensor-daemon" >> feeds.conf

$ scripts/feeds update
$ scripts/feeds install lightSensor-daemon
```

3) Configure your image

```
$ make menuconfig
```

(set Target System and Target Profile as needed for your equipment)

- Network --->
   freeDiameter (M)
   freeDiameter-test (M)
   wpad (*)
   wpad-mini ( )
   
4) Set the C library to glibc instead of uClibc

- Advanced configuration options (for developers) --->
  - Toolchain Options ---->
    C Library implementation (Use eglibc)


5) Build the image and packages, this takes a while

```
$ make world
```

6) Export the bin/* directory through a webserver. 
   We assume it is available at http://192.168.1.25/openwrt
   
7) Flash the router with your new image -- THIS DESTROYS ALL CONFIG ON THE ROUTER!

```
$ ssh root@192.168.1.1
# cd /tmp
# wget http://192.168.1.5/openwrt/openwrt-brcm47xx-squashfs.trx
    ;; change the file name with yours
# mtd -r write openwrt-brcm47xx-squashfs.trx linux
    ;; wait for reboot
$ telnet 192.168.1.1
# passwd
# sync
# exit
```

8) Update the opkg router's config to get your new packages

```
ssh root@192.168.1.1
# echo "src/gz localrepo http://192.168.1.5/openwrt/packages" >> /etc/opkg.conf 
# opkg update
```

9) Install freeDiameter, you're done. Optionnaly, install also certtool on the router before, to 
   generate the TLS certificate automatically.

```   
# opkg install lightSensor-daemon
```

### 2. Add packages

There are some dependencies of one package already available in the OpenWRT packages repository. 
You can check for the available packages with the script:
$ ./scripts/feeds search <package>

We will now describe how to install these dependencies. At the time this HOWTO is written, 
the OpenWRT repositories contains packages for sctp, ipv6, gnutls, pthreads and hostapd. 
Follow these instructions to build them.

Alternatively, you can find these packages pre-compiled in the OpenWRT packages repository.

a) Add the packages
$ scripts/feeds install libgnutls
$ scripts/feeds install sctp

b) Select the following components in the menu:
$ make menuconfig
- Base system --->
   libpthread (M)
   
- Network --->
   sctp (M)
   hostapd (M)
   wpad-mini ( )

- Libraries --->
   SSL --->
     libgnutls (M)
   
- Kernel modules --->
   Network Support --->
     kmod-ipv6 (M)
     
Quit and save the new config, then:
$ make world

This will add a bunch of modules in your bin directory that will be required for freeDiameter.
Since we are removing the wpad-mini daemon from the base image, this image (trx or bin file) is also recompiled.

Note that if you are setting your device as WPA supplicant also (wireless client), you must select wpad instead of hostapd.
(in any case, the -mini version is not suitable since we will use the RADIUS authentication).

You should now reflash your routeur with the new firmware image. The simplest way to achieve if your routeur has enough
flash memory is to:
- copy the new trx image to your routeur's /tmp (using wget or scp)
- run this command (on the device) -- replace <newfile.trx> with your actual filename:
 root@OpenWrt:~# mtd -r write <newfile.trx> linux

WARNING: this will erase your existing configuration on the routeur. 
In case you need to save it, you may try the sysupgrade command instead.

This will reboot the device after writing the new image file.
Afterwards, if you have set up the http server on your development machine properly 
(let's assume it has IP address 192.168.1.5)
you can run the following command on your router:
 root@OpenWrt:~# echo "src/gz mydev http://192.168.1.5/openwrt/packages" >> /etc/opkg.conf 
 root@OpenWrt:~# opkg update

Install the newly compiled packages with:
 root@OpenWrt:~# opkg install kmod-ipv6 hostapd libpthread sctp

### 3. Prerequisites for Compiling OpenWrt

The first step is look at the [OpenWrt Source Repositories page](https://dev.openwrt.org/wiki/GetSource) for your preferred version of OpenWrt.

Next you'll need to find your router's configuration (`config.diff` or `config_generic`) at the [OpenWrt Downloads page](https://downloads.openwrt.org/). You can compile OpenWrt 15.05 for the TP-Link TL-WR1043NDv2.1 router (ar71xx board), [here](https://downloads.openwrt.org/chaos_calmer/15.05/ar71xx/generic/config.diff) is that config.

Install some required tools, make the build directory, and clone the source:

```
sudo apt-get -y install git openssl python libssl-dev unzip build-essential binutils flex bison autoconf gettext texinfo sharutils subversion libncurses5-dev ncurses-term zlib1g-dev gawk;  
mkdir ~/openwrt-chaoscalmer/ && cd ~/openwrt-chaoscalmer/;  
git clone git://git.openwrt.org/15.05/openwrt.git;  
cd openwrt; 
```

The build configuration (.config file) controls the target platform, packages to compile into firmware, packages to compile for opkg install, and many other options.

In the .config, a package is in one of three states:

* `y` means it is compiled and included in firmware
* `m` means it is compiled and not included in firmware
* 'n' means the package is not compiled

Since you can download and install packages post-flash using opkg, changes `m` package to `n`.
**NOTE:** DO NOT USE SPACEBAR to disable packages, use the `n` on the keyboard; spacebar switches the inclusion state which can unintentionally include (many) other packages. Disabling these makes the build MUCH faster. Read More [Here](https://wiki.openwrt.org/doc/howto/build#image_configuration).

### 4. Background on Feeds

OpenWrt describes feeds as "addiional predefined package build recipes for OpenWrt Buildroot", where each feed resides on a remote host and are downloaded from GitHub. The scripts/feeds script is used to fetch and enable("install") the packages in `menuconfig`, making them visible for selection.

If you are using git, you have to edit the feeds.conf file to use git as well for packages.
Do the following modifications in this case:
$ vi feeds.conf
 Comment out this line:
src-svn packages https://svn.openwrt.org/openwrt/packages
 Add this line instead:
src-git packages git://nbd.name/packages.git

You can leave uncommented the luci (for GNUTLS) and Xwrt (webif) repositories. Since these repositories
use svn over http, you can use subversion even if you are behind a proxy.
 
Then issue the following command to update the package list:
$ scripts/feeds update

More infromation about feeds is in [OpenWrt's wiki on feeds](https://wiki.openwrt.org/doc/devel/feeds).

### 5. Configure and Build

Install feeds, fetch the config file, select your target profile, disable compile-only packages, and verify that you have prereqs:

```
# Fetch feeds from remote repositories
# and make them visible to menuconfig
./scripts/feeds update -a
./scripts/feeds install -a

# Get the configuration for your router if you found it
wget -O .config https://downloads.openwrt.org/chaos_calmer/15.05/ar71xx/generic/config.diff  
make defconfig

# Select your router's profile then save & quit, i.e., TP-LINK TL-WR1043N/ND
# Feel free to browse here, if you mess up, just redo the steps in this code block
make menuconfig

# Disable the compile-only packages AND disable the SDK (for fast builds)
# and make sure you have build prereqs
sed --in-place=.bak -e 's/=m$/=n/g' -e 's/^CONFIG_SDK=y$/CONFIG_SDK=n/' .config  
make prereq 
```

After the configuration, We're ready to build, Use `-j` to run parallel jobs and `V=s` to capture the output.

```
# BUILD IT
time make V=s -j20 2>&1 | tee build.log | grep -i error
```
The resulting image and packages are stored in the "bin/" subdirectory.

For troubleshooting, please consult OpenWRT documentation directly.
"make prereq" may help you building the initial image also.
See http://downloads.openwrt.org/docs/buildroot-documentation.html for additional information
concerning this step.

**Build issue tip**: 

* If it fails, try again using `make V=99`.
* To speed up, use more cores: `make -j 8`.
* Just retry the build if it fails. If it continues to fail use `V=s -j1`.

After the build is done, scp the file to your router and use `sysupgrade <build>.bin` (with -n to clear the config files). Read up on how to [configure OpenWrt](https://wiki.openwrt.org/doc/howto/basic.config) and have fun!

You should now be able to login on your routeur with telnet (first time) or ssh (after setting a password).

### Reference

* [Compiling OpenWrt from source](http://blog.ljdelight.com/compiling-openwrt-from-source/)
