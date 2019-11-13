include $(TOPDIR)/rules.mk

PKG_NAME:=lightSensor-daemon
PKG_VERSION:=d3c50ee19a25
PKG_RELEASE:=1

PKG_BUILD_DIR:=$(BUILD_DIR)/lightSensor-daemon
PKG_SOURCE:=$(PKG_VERSION).tar.gz
PKG_SOURCE_URL:=http://www.aboehler.at/hg/lightSensor-daemon/archive/
PKG_MD5SUM:=1e313fa824d36792891887cd556d6de2
PKG_CAT:=zcat
TARGET_CFLAGS+=-D_GNU_SOURCE
include $(INCLUDE_DIR)/package.mk

define Package/lightSensor-daemon
	SECTION:=system
	CATEGORY:=Utilities
	DEFAULT:=n
	TITLE:=DCS932L Light Sensor Daemon
	URL:=http://www.aboehler.at
endef

define Package/lightSensor-daemon/description
	Light Sensor daemon for the D-Link DCS932L IP camera
endef

define Package/lightSensor-daemon/install
	$(INSTALL_DIR) $(1)/usr/bin
	$(INSTALL_BIN) $(PKG_BUILD_DIR)/lightSensor-daemon $(1)/usr/bin
	$(INSTALL_DIR) $(1)/etc/init.d
	$(INSTALL_BIN) ./files/lightSensor-daemon.init $(1)/etc/init.d/lightSensor-daemon
endef

$(eval $(call BuildPackage,lightSensor-daemon))
