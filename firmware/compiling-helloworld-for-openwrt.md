# Compiling helloworld for OpenWrt

>Created by iFDING

>Create Date: 04/07/2017

It is a very simple program to build a program for OpenWrt

### 1. helloworld.c

First, Let's write a simple "hello world" program that we want to run on the router.

```
$ mkdir helloworld
$ mkdir helloworld/src
$ cd helloworld/src/
$ sudo nano helloworld.c
/****************
* helloworld.c
* The most simplistic C program ever written.
*****************/
#include <stdio.h>

int main(void)
{
        printf("Hello world, when you see this, it means it works!\n\n");
        return 0;
}
```

Note the location of this file, it should be `helloworld/src/helloworld.c`. Now, let's write a standard Unix Makefile in the same directory `helloworld/src/Makefile` to compile this code:

```
$ sudo nano Makefile
# build helloworld executable when user executes "make"
helloworld: helloworld.o
	$(CC) $(LDFLAGS) helloworld.o -o helloworld
helloworld.o: helloworld.c
	$(CC) $(CFLAGS) -c helloworld.c

# remove object files and executable when user executes "make clean"
clean:
	rm *.o helloworld
```

Note that instead od hard-coding "gcc" in the makefile to compile the program, we use a variable that holds the C compiler, $(CC). The use of the compiler variable is not necessary to compile the code locally, but in order to compile the code for OpenWrt it is critical because we won't be using the standard gcc compiler.

```
$ make
cc  -c helloworld.c
cc  helloworld.o -o helloworld

$ ls
helloworld  helloworld.c  helloworld.o  Makefile

$ ./helloworld 
Hello world, when you see this, it means it works!

$ make clean
rm *.o helloworld
```

Be sure to run `make clean` to remove the compiled binary, if the old object files aren't deleted, it will be used instead of the new one we need to generate that is compatible with OpenWrt.

### 2. OpenWrt SDK

Now we need a developement environment.

The router uses a distinctly different architecture than our linux development box. Because there isn't enough memory/disk space on the router to install a compiler and compile the code natively, we need to "cross-compile" the code on our development box for use on the router.

To do this we need a special compiler can development environment called OpenWrt SDK. You can download the SDK from [https://downloads.openwrt.org/](https://downloads.openwrt.org/). The SDK varies depending on the architecture of your development box, the architecture of your router and the version/release of OpenWrt your router is running. I currently use this one: OpenWrt-SDK-15.05.1-ramips-rt305x_gcc-4.8-linaro_uClibc-0.9.33.2.Linux-x86_64.tar.bz2,

```
$ wget https://downloads.openwrt.org/chaos_calmer/15.05.1/ramips/rt305x/OpenWrt-SDK-15.05.1-ramips-rt305x_gcc-4.8-linaro_uClibc-0.9.33.2.Linux-x86_64.tar.bz2

$ tar xfj OpenWrt-SDK-15.05.1-ramips-rt305x_gcc-4.8-linaro_uClibc-0.9.33.2.Linux-x86_64.tar.bz2 

$ cd OpenWrt-SDK-15.05.1-ramips-rt305x_gcc-4.8-linaro_uClibc-0.9.33.2.Linux-x86_64/

$ ls
build_dir        Config.in  docs                include  Makefile  prepare.mk  rules.mk  staging_dir
Config-build.in  dl         feeds.conf.default  LICENSE  package   README.SDK  scripts   target
```

Our goal is to build a package for OpenWrt using the source we already have. When you execute the `make` command in the SDK directory, the SDK will compile all properly configured packages in the `package` subdirectory under the SDK directory.

### 3. Compiling

Now comes the tricky part, compiling the code so that it will run on our router.

First, copy the `helloworld` directory we made earlier into the `package` subdirectory of the SDK, say, the full path of `helloworld` is: `~/helloworld`

```
$ cp -r ~/helloworld/ package/
```

In order to tell the OpenWrt SDK how to build our program we need to create a special Makefile in the `helloworld` directory, above the `src` directory which contains our conventional makefile. Below is an OpenWrt makefile for building the helloworld program, written by Eric Bishop. Each section is heavily commented so that it should be fairly clear what is going on.

```
$ cat package/helloworld/Makefile 
##############################################
# OpenWrt Makefile for helloworld program
#
#
# Most of the variables used here are defined in
# the include directives below. We just need to 
# specify a basic description of the package, 
# where to build our program, where to find 
# the source files, and where to install the 
# compiled program on the router. 
# 
# Be very careful of spacing in this file.
# Indents should be tabs, not spaces, and 
# there should be no trailing whitespace in
# lines that are not commented.
# 
##############################################

include $(TOPDIR)/rules.mk

# Name and release number of this package
PKG_NAME:=helloworld
PKG_RELEASE:=1


# This specifies the directory where we're going to build the program.  
# The root build directory, $(BUILD_DIR), is by default the build_mipsel 
# directory in your OpenWrt SDK directory
PKG_BUILD_DIR := $(BUILD_DIR)/$(PKG_NAME)


include $(INCLUDE_DIR)/package.mk



# Specify package information for this program. 
# The variables defined here should be self explanatory.
# If you are running Kamikaze, delete the DESCRIPTION 
# variable below and uncomment the Kamikaze define
# directive for the description below
define Package/helloworld
	SECTION:=utils
	CATEGORY:=Utilities
	TITLE:=Helloworld -- prints a snarky message
endef


# Uncomment portion below for Kamikaze and delete DESCRIPTION variable above
define Package/helloworld/description
	If you can't figure out what this program does, you're probably
	brain-dead and need immediate medical attention.
endef



# Specify what needs to be done to prepare for building the package.
# In our case, we need to copy the source files to the build directory.
# This is NOT the default.  The default uses the PKG_SOURCE_URL and the
# PKG_SOURCE which is not defined here to download the source from the web.
# In order to just build a simple program that we have just written, it is
# much easier to do it this way.
define Build/Prepare
	mkdir -p $(PKG_BUILD_DIR)
	$(CP) ./src/* $(PKG_BUILD_DIR)/
endef


# We do not need to define Build/Configure or Build/Compile directives
# The defaults are appropriate for compiling a simple program such as this one


# Specify where and how to install the program. Since we only have one file, 
# the helloworld executable, install it by copying it to the /bin directory on
# the router. The $(1) variable represents the root directory on the router running 
# OpenWrt. The $(INSTALL_DIR) variable contains a command to prepare the install 
# directory if it does not already exist.  Likewise $(INSTALL_BIN) contains the 
# command to copy the binary file from its current location (in our case the build
# directory) to the install directory.
define Package/helloworld/install
	$(INSTALL_DIR) $(1)/bin
	$(INSTALL_BIN) $(PKG_BUILD_DIR)/helloworld $(1)/bin/
endef


# This line executes the necessary commands to compile our program.
# The above define directives specify all the information needed, but this
# line calls BuildPackage which in turn actually uses this information to
# build a package.
$(eval $(call BuildPackage,helloworld))
``` 

As indicated, most OpenWrt make files specify how to download the source of an application from a URL, and most documentation assumes that you want to do this. However, if you're building your own application from scratch it doesn't make sense to download from a URL. It's much simpler to have tha source locally and use the Build/Prepare section to copy the source to the build directory, as shown above.

Also, be very careful of spacing in the Makefile. The indentation under the define sections should be tabs, not spaces and there should be no whitespace at the end of lines that are not comments. 

The trailing whitespace can be a problem when variables are being defined, as the compiler may think there is a space at the end of a directory name. If we're copying something to **dir_with_trailing_space/subdir** the copy command may be executed as `cp my.file dir_with_trailing_space /subdir`. Not only don't you want anything in `/subdir`, you probably don't have permission to create it and write to it.

Now we're all set to compile the helloworld package. Go to the root SDK directory (if you're not already there) and type `make V=99`. The `V=99` option is optional, but it is useful for debugging as it instructs the compiler to be "verbose" and output all the details of what it is doing.

```
$ make V=99
```

It compiled! The new package, **helloworld_1_ramips_24kec.ipk**, is now located in:

```
$ ls bin/ramips/packages/base/
helloworld_1_ramips_24kec.ipk  Packages  Packages.gz
```

The gargoyle-router.com said: copy this package onto the router, which is located at 192.168.1.1 on my network. And ssh into the router, use "opkg install helloworld_1_ramips_24kec.ipk". But this way doesn't work for me.

### Reference

* [Writing and Compiling A Simple Program For OpenWrt](https://www.gargoyle-router.com/old-openwrt-coding.html)
