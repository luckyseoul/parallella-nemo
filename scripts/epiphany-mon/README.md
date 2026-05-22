# epiphany-mon

Lightweight monitor for Epiphany mesh utilization.

Supports both Epiphany III (16 cores) and Epiphany IV (64 cores).

## Features

- Per-core utilization bars with color coding
- Shows ARM load and memory usage
- Reads from Parallel Idea Engine shared memory when available
- Very low resource usage
- Scales to 64 cores cleanly

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

## Color Legend

- Green: Low utilization (< 40%)
- Yellow: Medium utilization (40-70%)
- Red: High utilization (> 70%)