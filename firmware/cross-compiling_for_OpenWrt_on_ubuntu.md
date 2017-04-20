
# Cross-compiling For OpenWrt On Ubuntu

## 1. Building Cross-compilation Environment

### 1.1 Download Source Files

The cross-compiler environment will be installed in */usr/local/crosscompile/openwrt* so the first step is to use the git utility to copy the files from the [OpenWRT git repository](http://git.openwrt.org/)

```
$ cd /usr/local/crosscompile/
$ git clone git://git.openwrt.org/14.07/openwrt.git
```

You can install the package sources with:

```
$ git clone git://git.openwrt.org/14.07/packages.git
```

### 1.2 Building

Configuration is via a menu driven UI, this is done with the command:

```
$ cd openwrt
$ make menuconfig
```

The options can be left as the defaults, but ensure that you have the correct target system specified. For the TL-WR703N router, the target is Atheros AR7xxx/AR9xxx
To reset back to the default options, use the command:

```
$ make defconfig
```

Now, to compile the gcc toolchain, the kernel, and the OpenWRT image and its packages, issue the command

```
$ make
```

If the PC has multiple cores, the process can be sped up by telling make to run multiple processes, for example:

```
make -j 3
```

It is recommended that optimally, the -j option should be specified as the number of cores plus one, so 3 for a dual core machine etc.

make will take some time to complete (probably several hours) as it compiles the the gcc cross-compiler tools, as well as the kernel and utilites required for the OpenWRT squash-fs image that can be flashed to the router.

Once it is done, everything will be found in the /usr/local/cross-compile/openwrt/staging_dir diretory. The gcc tools, include files and shared libraries are found in /usr/local/cross-compile/openwrt/staging_dir/toolchain-mips_34kc_gcc-4.8-linaro_uClibc-0.9.33.2 (given the Atheros AR7xxx/AR9xxx that was used).


## 2. Cross-compiling

### 2.1 Compiling Hello World

Now that everything is in place, we can test that everything works by cross compiling the standard *helloworld.c* program.

Several environment variables can be set to tell gcc where everything is, using a script is the easiest way to do this:

```sh
# Set up paths and environment for cross compiling for openwrt
export STAGING_DIR=/usr/local/cross-compile/openwrt/staging_dir
export TOOLCHAIN_DIR=$STAGING_DIR/toolchain-mips_34kc_gcc-4.8-linaro_uClibc-0.9.33.2
export LDCFLAGS=$TOOLCHAIN_DIR/usr/lib
export LD_LIBRARY_PATH=$TOOLCHAIN_DIR/usr/lib
export PATH=$TOOLCHAIN_DIR/bin:$PATH
```

Then source this script prior to doing any cross-compiling:

```
$ . ~/bin/openwrt.config
$ cat helloworld.c
#include <stdio.h>

int main()
{
printf("Hello World!\n");
return 0;
}

$ mips-openwrt-linux-gcc -o helloworld helloworld.c

$ file helloworld
helloworld: ELF 32-bit MSB executable, MIPS, MIPS32 rel2 version 1, dynamically linked (uses shared libs),
with unknown capability 0x41000000 = 0xf676e75, with unknown capability 0x10000 = 0x70403, not stripped
```

This can be copied over to the router and executed to ensure that everytying has worked.

### 2.2 Using a Makefile

Here's an example of a Makefile used for cross compilation:

```
/*
Ensure that openwrt cross-compile environment variables are set prior to calling make:
~/bin/openwrt.config
*/
TOOLCHAIN_DIR=/usr/local/cross-compile/openwrt/staging_dir/toolchain-mips_34kc_gcc-4.8-linaro_uClibc-0.9.33.2
INCLUDE_DIR=$(TOOLCHAIN_DIR)/usr/include

CC=mips-openwrt-linux-gcc

CFLAGS= -std=gnu99
LDFLAGS=-lbluetooth

SOURCES=test.c sb.c logger.c btcom.c

OBJS=$(SOURCES:.c=.o)

all: test

test.o: test.c
$(CC) -c $(CFLAGS) -I $(INCLUDE_DIR) -o $@ $<

%.o: %.c %.h
$(CC) -c $(CFLAGS) -I $(INCLUDE_DIR) -o $@ $<

test: $(OBJS)
$(CC) $(LDFLAGS) $(CFLAGS) -o test $(OBJS)

clean:
rm *.o test
```

Note:

- The cross-compiler is specified with the line: `CC=mips-openwrt-linux-gcc`
- The bluetooth library is being linked to (this has already been cross-compiled and installed), and hence the include directory for the bluetooth header files is being explicity specified: `-I $(INCLUDE_DIR)`

Also, an existing Make file can be used by specifying the flags on the command line:

```
$ make CC=mips-openwrt-linux-uclibc-gcc LD=mips-openwrt-linux-uclibc-ld
```

## 3. Compiling Source Package

For example, assuming you want to compile the libmicrohttpd HTTP library, you need to compile it from source.

After downloading and extracting the source archive libmicrohttpd-0.9.38.tar.gz from the OpenWRT source code repository, it was built and installed as follows:

```
 ./configure --prefix=$TOOLCHAIN_DIR --build=mips-openwrt-linux-gnu --host=mips-openwrt-linux-uclibc
make
make install
```

Also we can build a script `build-libmicrohttpd.sh` like this:

```sh
#!/bin/bash
#
# compile libmicrohttpd for ar71xx (mipsbe)
#
 
export BASEDIR=$(pwd)
 
### begin configuration
 
# node src directory
export SRCDIR=libmicrohttpd-0.9.38
 
#adjust STAGING_DIR and TOOLDIR below based on location of your toolchain
#ToolChain
export STAGING_DIR=${BASEDIR}/OpenWrt-Toolchain-ar71xx-for-mips_r2-gcc-4.6-linaro_uClibc-0.9.33.2/toolchain-mips_r2_gcc-4.6-linaro_uClibc-0.9.33.2
#export STAGING_DIR=${BASEDIR}/openwrt/attitude_adjustment/staging_dir
 
export TOOLDIR=${STAGING_DIR}/toolchain-mips_r2_gcc-4.6-linaro_uClibc-0.9.33.2
 
### end configuration
 
  
export TARGET_PATH=${BASEDIR}/${SRCDIR}-mipsbe
export PREFIX=${TOOLDIR}/bin/mips-openwrt-linux-
export LIBPATH=${TOOLDIR}/lib/
  
# MIPS cross-compile exports
export CC=${PREFIX}gcc
export CXX=${PREFIX}g++
export AR=${PREFIX}ar
export RANLIB=${PREFIX}ranlib
export LINK=${PREFIX}g++
export CPP="${PREFIX}gcc -E"
export STRIP=${PREFIX}strip
export OBJCOPY=${PREFIX}objcopy
export LD=${PREFIX}g++
export OBJDUMP=${PREFIX}objdump
export NM=${PREFIX}nm
export AS=${PREFIX}as
export PS1="[${PREFIX}] \w$ "
export LDFLAGS='-Wl,-rpath-link '${LIBPATH}
  
rm -rf ${TARGET_PATH}
mkdir ${TARGET_PATH}
cd ${SRCDIR}
make clean
make distclean
./configure --prefix=${TARGET_PATH} --host=mips-openwrt-linux-uclibc --without-snapshot --with-mips-float-abi=soft
make
make install
```

If your toolchain is in a different place from the STAGING_DIR specified in the script, adjust it to point to the proper location. Finally, execute the build script:

```
$ sh build_libmicrohttpd_mipsbe.sh
```

After the build is complete, you can test it out by transferring one of the example files to your TL-WR703N running OpenWrt. A good candidate would be *src/examples/fileserver_example*. In addition to the executable, you also need to get the shared library onto your OpenWrt machine. It is built into a strange location: *src/examples/microhttpd/.libs/libmicrohttpd.so.10*. Put the file in */usr/lib/libmicrohttpd.so.10* on your target machine. Finally, you should be able to execute *fileserver_example* on the target machine.


## Reference

- [Cross Compiling For OpenWRT On Linux](http://telecnatron.com/articles/Cross-Compiling-For-OpenWRT-On-Linux/)
- [OpenWrt: Cross-compiling libmicrohttpd for TL-WR703N](http://blog.lincomatic.com/?p=1632)

