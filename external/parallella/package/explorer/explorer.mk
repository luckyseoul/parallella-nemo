################################################################################
#
# explorer
#
################################################################################

EXPLORER_VERSION = 1.0
EXPLORER_SITE = $(BR2_EXTERNAL_PARALLELLA_PATH)/../../explorer/core
EXPLORER_SITE_METHOD = local

define EXPLORER_BUILD_CMDS
	$(MAKE) -C $(@D) CC="$(TARGET_CC)"
endef

define EXPLORER_INSTALL_TARGET_CMDS
	$(INSTALL) -D -m 0755 $(@D)/explorer $(TARGET_DIR)/usr/bin/explorer_core
endef

$(eval $(generic-package))