################################################################################
#
# epiphany
#
################################################################################

EPIPHANY_VERSION = 1.0
EPIPHANY_SITE = $(BR2_EXTERNAL_PARALLELLA_PATH)/../../epiphany
EPIPHANY_SITE_METHOD = local

define EPIPHANY_INSTALL_TARGET_CMDS
	$(INSTALL) -d -m 0755 $(TARGET_DIR)/usr/lib/epiphany/kernels
	$(INSTALL) -D -m 0644 $(@D)/kernels/*.c $(TARGET_DIR)/usr/lib/epiphany/kernels/ || true
	$(INSTALL) -D -m 0644 $(@D)/python/*.py $(TARGET_DIR)/usr/lib/epiphany/ || true
endef

$(eval $(generic-package))