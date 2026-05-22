# epiphany-mon

Lightweight monitor for Epiphany mesh utilization.

Supports both Epiphany III (16 cores) and Epiphany IV (64 cores).

## Features

- Per-core utilization bars
- Works with the Parallel Idea Engine shared memory
- Very low resource usage
- Supports both E16 and E64

## Build

```bash
make
```

## Usage

```bash
./epiphany-mon          # 16 cores (default)
./epiphany-mon 64       # 64-core mode
```

Press `q` to quit.

## Notes

This tool reads from the shared memory regions used by the Parallel Idea Engine when available.