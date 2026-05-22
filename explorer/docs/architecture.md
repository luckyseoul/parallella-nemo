# Parallel Autonomous Idea Engine — Architecture

## Vision

A low-power, always-on system that uses the Epiphany's 16 RISC cores to run many independent "explorers" in parallel. These explorers constantly generate ideas, alternative solutions, and novel connections without requiring user initiation.

The key differentiator is **true parallel exploration** at very low power — something difficult to replicate efficiently on normal single/quad-core boards.

## System Components

- **Explorer Cores** (`explorer/core/`)
  - Run independently on each Epiphany core
  - Generate ideas using local logic or templates
  - Write results into shared memory

- **Aggregator** (`explorer/aggregator/`)
  - Runs on ARM side
  - Collects, deduplicates, and scores results
  - Forwards high-value ideas to Grok for refinement
  - Triggers notifications

- **Notifier** (`explorer/aggregator/notifier.py`)
  - Handles user notification across multiple channels

- **Communication Layer**
  - Shared memory protocol between Epiphany and ARM
  - Defined in `docs/communication.md`

## High-Level Flow

1. Epiphany cores run explorers in parallel
2. Results written to shared memory
3. Aggregator pulls and processes results
4. Promising ideas sent to Grok via OAuth
5. User is notified of high-value outputs

## Current Status

Scaffolding in place. Core explorer, aggregator, and communication protocol are being developed.