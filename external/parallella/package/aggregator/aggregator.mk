################################################################################
#
# aggregator
#
################################################################################

AGGREGATOR_VERSION = 1.0
AGGREGATOR_SITE = $(BR2_EXTERNAL_PARALLELLA_PATH)/../../explorer/aggregator
AGGREGATOR_SITE_METHOD = local

define AGGREGATOR_INSTALL_TARGET_CMDS
	$(INSTALL) -d -m 0755 $(TARGET_DIR)/usr/lib/aggregator
	$(INSTALL) -D -m 0644 $(@D)/*.py $(TARGET_DIR)/usr/lib/aggregator/
	$(INSTALL) -D -m 0755 $(@D)/aggregator.py $(TARGET_DIR)/usr/bin/aggregator
endef

$(eval $(generic-package))