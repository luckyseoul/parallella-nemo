# Technical Plan — Parallella Modern

## Overview

This document outlines the technical approach for building a modern, user-friendly Linux distribution for the Parallella 16 using Buildroot.

## Build System

- **Buildroot 2025.02+** as the core build system
- Single defconfig: `parallella_defconfig`
- External tree for custom packages and patches
- Focus on reproducibility and small image size

## Base System

- ARMv7 (Cortex-A9) target
- Linux kernel (latest stable that supports Zynq-7010)
- systemd (preferred) or OpenRC for service management
- Minimal BusyBox userspace + selected Debian packages where needed

## Desktop Environment

- **XFCE** as the target desktop (lightweight but modern)
- Fallback: Lightweight window manager (Openbox or i3) for lower-resource setups
- Goal: Usable desktop on 1GB RAM + SD card

## First-Boot Experience

A custom `parallella-setup` script will run on first boot and guide the user through:

1. Setting hostname
2. Creating / changing root password
3. Configuring WiFi (SSID + password)
4. Optional: Setting up Ethernet
5. Disabling itself after completion

This script will be written in shell and use `dialog` or simple prompts.

## WiFi Support

- Include `wpa_supplicant` and `dhcpcd`
- Provide a simple command: `parallella-wifi setup`
- Store configuration in `/etc/wpa_supplicant/wpa_supplicant.conf`

## Epiphany Integration

### Toolchain
- Package a modern cross-compiler + Epiphany SDK
- Provide both host and target components

### Python Support
- Create `python3-epiphany` package
- Expose basic matrix operations and inference helpers
- Goal: Allow users to run small ML models from Python

### Example Workloads
- Matrix multiplication kernel
- Small quantized neural networks (MLP / tiny CNN)
- Attention scoring primitives

## Update Mechanism

Simple but effective update system:

- `parallella-update` command
- Pulls latest packages and scripts from GitHub
- Can be extended later to support full image updates

## Image Output

- SD card image (`parallella-nemo.img`)
- Root filesystem tarball for advanced users
- Clear documentation on how to flash the image

## Development Workflow

1. Modify `buildroot/configs/parallella_defconfig`
2. Add packages under `buildroot/external/`
3. Test via QEMU or real hardware
4. Document changes in `docs/`

## Future Extensions

- Over-the-air update infrastructure
- Container support (Docker / podman)
- Expanded ML examples and benchmarks
- Community package repository

This plan will evolve as development progresses.