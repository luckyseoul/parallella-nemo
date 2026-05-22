# Top-level build for Parallella Nemo

BR2_EXTERNAL := $(CURDIR)/external
BR2_DEFCONFIG := $(CURDIR)/external/parallella/defconfig

.PHONY: all clean

all:
	@echo "Building Parallella Nemo image..."
	@make -C $(BR2_EXTERNAL)/../buildroot BR2_EXTERNAL=$(BR2_EXTERNAL) defconfig BR2_DEFCONFIG=$(BR2_DEFCONFIG)
	@make -C $(BR2_EXTERNAL)/../buildroot BR2_EXTERNAL=$(BR2_EXTERNAL)

clean:
	@echo "Cleaning build artifacts..."