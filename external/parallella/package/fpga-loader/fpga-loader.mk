################################################################################
#
# fpga-loader
#
################################################################################

FPGA_LOADER_VERSION = 1.0
FPGA_LOADER_SITE = $(BR2_EXTERNAL_PARALLELLA_PATH)/../../scripts/fpga
FPGA_LOADER_SITE_METHOD = local

define FPGA_LOADER_INSTALL_TARGET_CMDS
	$(INSTALL) -D -m 0755 $(@D)/load-bitstream.sh $(TARGET_DIR)/usr/bin/parallella-load-bitstream
endef

$(eval $(generic-package))