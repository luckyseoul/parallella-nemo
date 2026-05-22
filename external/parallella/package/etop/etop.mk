################################################################################
#
# etop
#
################################################################################

ETOP_VERSION = 1.0
ETOP_SITE = $(BR2_EXTERNAL_PARALLELLA_PATH)/../../scripts/etop
ETOP_SITE_METHOD = local

define ETOP_BUILD_CMDS
	$(MAKE) -C $(@D) CC="$(TARGET_CC)"
endef

define ETOP_INSTALL_TARGET_CMDS
	$(INSTALL) -D -m 0755 $(@D)/etop $(TARGET_DIR)/usr/bin/etop
endef

$(eval $(generic-package))