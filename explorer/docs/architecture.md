# Parallel Autonomous Idea Engine — Architecture

## Vision

A low-power, always-on system that uses the Epiphany's 16 RISC cores to run many independent "explorers" in parallel. These explorers constantly generate ideas, alternative solutions, and novel connections without requiring user initiation.

The key differentiator is **true parallel exploration** at very low power.

## Current Components

- `core/explorer.c` + `shared_mem.h` — Per-core explorer logic
- `aggregator/aggregator.py` — Main collection and orchestration loop
- `aggregator/notifier.py` — Multi-channel notification system
- `aggregator/config.py` — Engine configuration
- `aggregator/shared_memory.py` — ARM-side memory reader (stub)
- `docs/communication.md` — Shared memory protocol

## Runtime

The aggregator is intended to run as a systemd service (`parallella-idea-engine.service`).

## Next Priorities

1. Real shared memory implementation (mmap + Epiphany driver)
2. Grok OAuth integration for idea evaluation
3. Better explorer specialization across cores
4. Notification channel implementations (Telegram, etc.)

This architecture keeps the Epiphany's parallelism as the central value.