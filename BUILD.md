# Building Parallella Nemo

## Requirements

- Buildroot (auto-cloned by build.sh if missing)
- Host tools: make, gcc, git

## Quick Build

```bash
./build.sh
```

This will:
1. Clone Buildroot (shallow) to ../buildroot if not present
2. Configure with the Parallella Nemo defconfig-headless
3. Build the full image

## Manual Build

```bash
make -C ../buildroot BR2_EXTERNAL=$(pwd)/external/parallella \
    defconfig BR2_DEFCONFIG=$(pwd)/external/parallella/defconfig-headless

make -C ../buildroot BR2_EXTERNAL=$(pwd)/external/parallella
```

## Available Defconfigs

- `defconfig-headless` – minimal headless image (current default)
- `defconfig` – legacy / base config

## Packages included in external tree

- etop (Epiphany monitor)
- firstboot
- explorer
- aggregator
- fpga-loader (bitstream loading)

## Output

The resulting image will be in `../buildroot/output/images/`.