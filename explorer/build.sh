#!/bin/bash
# Build script for Epiphany explorer cores

set -e

ESDK=${EPIPHANY_HOME:-/opt/adapteva/esdk}
CFLAGS="-O2 -Wall -I${ESDK}/tools/host/include -I./core"
LDFLAGS="-L${ESDK}/tools/host/lib -lelib"

echo "Building Epiphany explorer..."

# This is a simplified build. Real build would use e-gcc
gcc -o explorer_core core/explorer.c ${CFLAGS} ${LDFLAGS} || echo "Note: Full Epiphany cross-compile requires e-gcc"

echo "Build complete (placeholder)."