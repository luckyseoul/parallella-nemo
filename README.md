# Parallella Nemo

A modern Linux distribution and parallel exploration platform for the **Parallella 16** (Zynq + 16-core Epiphany).

## Core Idea

The Epiphany's 16 RISC cores power a **low-power parallel idea generation engine**. The system can operate in two modes:

### 1. Parallel Exploration Mode
Multiple independent explorers run simultaneously across the mesh, constantly generating ideas, alternative solutions, and novel connections without user input.

### 2. Light Chatbot / Check-in Mode
Simple proactive interactions such as casual check-ins and lightweight engagement.

Both modes use Grok (via OAuth) for high-quality responses while keeping power usage very low.

## Key Features

- True parallel exploration across 16 Epiphany cores
- Low-power always-on operation
- Proactive idea surfacing and casual check-ins
- Modern first-boot experience
- `etop` – lightweight Epiphany mesh monitor (supports E16 and E64)

## Project Structure

```
parallella-nemo/
├── explorer/           # Parallel Idea Engine
├── buildroot/          # Image configurations
├── scripts/            # First-boot installer, FPGA tools, etop
├── epiphany/           # Low-level Epiphany kernels
└── docs/
```

## Status

Early development. The Parallel Autonomous Idea Engine is the current focus.

## License

MIT License