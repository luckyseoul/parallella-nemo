# Epiphany ↔ ARM Communication Protocol

## Overview

The Epiphany cores and ARM processor communicate through shared memory regions. This keeps overhead low and respects the Epiphany's architecture.

## Memory Layout (Proposed)

| Region | Address Range | Purpose | Access |
|--------|---------------|---------|--------|
| Explorer Output Buffer | 0x8f000000 - 0x8f00FFFF | Results from each core | Epiphany write, ARM read |
| Command Buffer | 0x8f010000 - 0x8f01FFFF | Commands from ARM to Epiphany | ARM write, Epiphany read |
| Status Flags | 0x8f020000 | Heartbeat + ready flags | Both |

## Message Format

Each explorer writes results in this simple structure:

```c
typedef struct {
    uint32_t core_id;
    uint32_t timestamp;
    char idea[128];
    float confidence;
} explorer_result_t;
```

## Synchronization

- Epiphany cores write results and increment a counter
- ARM side polls or uses interrupts (if available) to read new results
- Simple ring buffer or double buffering to avoid race conditions

This protocol will evolve as the system matures.