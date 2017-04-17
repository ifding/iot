# Firmware

### OpenWrt

* [How to create a firmware: three options](how-to-create-a-firmware.md)
* [buildroot: compiling-OpenWrt](compiling-OpenWrt-from-source.md)
* [SDK: compiling helloworld](compiling-helloworld-for-openwrt.md)
* [Image Builder: build custom firmware](build-custom-firmware-with-openwrt.md)

### Ralink

* [Install buildtools for Ralink](install-build-tools-Ralink.md)

### Operation

* [transfer files from/to embedded system](transfer-files-from-to-embedded-system.md)

### OpenWrt packages

- librdkafka for OpenWrt

1. Add `src-git librdkafka https://github.com/cloudify/openwrt-packages.git` to your `feeds.conf`

2. Update the feed: `./scripts/feeds update librdkafka`

3. And then install it: `./scripts/feeds install librdkafa`

4. Now your package should be aviable when you do: `make menuconfig`
