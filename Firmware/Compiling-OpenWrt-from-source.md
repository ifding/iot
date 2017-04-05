
# Compiling OpenWrt from source

Knowing how to build from source is important for developers and others that want to change the default installation image.

### 1. Prerequisites for Compiling OpenWrt

The first step is look at the [OpenWrt Source Repositories page](https://dev.openwrt.org/wiki/GetSource) for your preferred version of OpenWrt.

Next you'll need to find your router's configuration (`config.diff` or `config_generic`) at the [OpenWrt Downloads page](https://downloads.openwrt.org/). You can compile OpenWrt 15.05 for the TP-Link TL-WR1043NDv2.1 router (ar71xx board), [here](https://downloads.openwrt.org/chaos_calmer/15.05/ar71xx/generic/config.diff) is that config.

### 2. Compiling the Source

Install some required tools, make the build directory, and clone the source:

```
sudo apt-get -y install git openssl python libssl-dev unzip build-essential binutils flex bison autoconf gettext texinfo sharutils subversion libncurses5-dev ncurses-term zlib1g-dev gawk;  
mkdir ~/openwrt-chaoscalmer/ && cd ~/openwrt-chaoscalmer/;  
git clone git://git.openwrt.org/15.05/openwrt.git;  
cd openwrt; 
```

### 3. Background on Configuration

The build configuration (.config file) controls the target platform, packages to compile into firmware, packages to compile for opkg install, and many other options.

In the .config, a package is in one of three states:

* `y` means it is compiled and included in firmware
* `m` means it is compiled and not included in firmware
* 'n' means the package is not compiled

Since you can download and install packages post-flash using opkg, changes `m` package to `n`.
**NOTE:** DO NOT USE SPACEBAR to disable packages, use the `n` on the keyboard; spacebar switches the inclusion state which can unintentionally include (many) other packages. Disabling these makes the build MUCH faster. Read More [Here](https://wiki.openwrt.org/doc/howto/build#image_configuration).

### 4. Background on Feeds

OpenWrt describes feeds as "addiional predefined package build recipes for OpenWrt Buildroot", where each feed resides on a remote host and are downloaded from GitHub. The scripts/feeds script is used to fetch and enable("install") the packages in `menuconfig`, making them visible for selection.

It's easy to enable custom feeds to make your own packages or include others, i.e., Open vSwitch (OVS) to talk to a controller (such as [Floodlight](http://www.projectfloodlight.org/floodlight/) or [OpenDaylight](https://www.opendaylight.org/)). Those controllers let us manage lots of switches from a centralized location.

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

**Build issue tip**: 

* If it fails, try again using `make V=99`.
* To speed up, use more cores: `make -j 8`.
* Just retry the build if it fails. If it continues to fail use `V=s -j1`.

After the build is done, scp the file to your router and use `sysupgrade <build>.bin` (with -n to clear the config files). Read up on how to [configure OpenWrt](https://wiki.openwrt.org/doc/howto/basic.config) and have fun!

### Reference

* [Compiling OpenWrt from source](http://blog.ljdelight.com/compiling-openwrt-from-source/)