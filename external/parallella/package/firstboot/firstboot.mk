################################################################################
#
# firstboot
#
################################################################################

FIRSTBOOT_VERSION = 1.0
FIRSTBOOT_SITE = $(BR2_EXTERNAL_PARALLELLA_PATH)/../../scripts/firstboot
FIRSTBOOT_SITE_METHOD = local

define FIRSTBOOT_INSTALL_TARGET_CMDS
	$(INSTALL) -D -m 0755 $(@D)/installer.py $(TARGET_DIR)/usr/lib/firstboot/installer.py
	$(INSTALL) -D -m 0644 $(@D)/parallella-firstboot.service \
		$(TARGET_DIR)/usr/lib/systemd/system/parallella-firstboot.service
endef

define FIRSTBOOT_INSTALL_INIT_SYSTEMD
	$(INSTALL) -D -m 0644 $(@D)/parallella-firstboot.service \
		$(TARGET_DIR)/usr/lib/systemd/system/parallella-firstboot.service
endef

$(eval $(generic-package))