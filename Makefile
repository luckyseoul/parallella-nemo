# Top-level build for Parallella Nemo

BR2_EXTERNAL := $(CURDIR)/external/parallella
BR2_DEFCONFIG := $(CURDIR)/external/parallella/defconfig

.PHONY: all clean

all:
	@echo "Building Parallella Nemo image..."
	@if [ ! -d "../buildroot" ]; then \
		echo "Error: Buildroot not found at ../buildroot"; \
		echo "Please clone Buildroot first."; \
		exit 1; \
	fi
	@make -C ../buildroot BR2_EXTERNAL=$(BR2_EXTERNAL) defconfig BR2_DEFCONFIG=$(BR2_DEFCONFIG)
	@make -C ../buildroot BR2_EXTERNAL=$(BR2_EXTERNAL)

clean:
	@echo "Cleaning build artifacts..."