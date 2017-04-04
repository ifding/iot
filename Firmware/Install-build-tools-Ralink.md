# Ralink Toolchain

### 1. Install Build Tools

Open an terminal widow and issue the following command to install a few build essentials from a terminal command line.

```
sudo apt-get install synaptic automake libtool libncurses5-dev flex bison g++ zlib1g-dev gawk subversion git libssl-dev vsftpd gettext
```

Without these basic tools you will end up with endless errors when you try and proceed with compiling Uboot or OpenWRT.

### 2. Install the MIPs cross compiler

Ubuntu does not include a cross compiler for the MIPs processor, I have chosen to use the compiler that was provided in the Ralink SDK because that was fairly easy to do. This is a 32bit version of the compiler.

```
sudo cp buildroot-gcc342.tar.bz2 /opt
sudo cp buildroot-gdb-src-pkt.tar.bz2 /opt
cd /opt
sudo tar -jxvf buildroot-gcc342.tar.bz2
sudo tar -jxvf buildroot-gdb-src-pkt.tar.bz2
sudo mv buildroot builtroot-gdb
```

That’s it for now; you have installed all of the tools required to build your own images.

### 3. Install LZMA Utility

lzma is necessary to make the compressed kernel image.

```
wget http://tukaani.org/lzma/lzma-4.32.7.tar.bz2
sudo tar -jxvf lzma-4.32.7.tar.bz2
cd lzma-4.32.7/
./configure
make
sudo make install
```

install lzma to /usr/local/bin

Use gzip or lzma to compress the kernel image.

Make changes to RT288x_SDK/source/vendors/Ralink/{Platform}/Makefile

```
COMP = gzip
```

Use gzip to compress the linux kernel image

```
COMP = lzma
```

Use lzma to compress the linux kernel image

### 4. Install mksquashfs utility

mksquashfs-lzma is necessary to make the compressed rootfs. The Ralink AP SDK uses mksquashfs with lzma to compress the root filesystem.

**Linux-2.6.21.x Kernel Version**

```
cd RT288x_SDK/toolchain/mksquash_lzma-3.2
sudo make
sudo make install
```


### Reference

* [Step 3 Ubuntu12 Install](http://www.dnclabs.com/?p=1321)
