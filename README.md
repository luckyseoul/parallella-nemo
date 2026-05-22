# Parallella Modern

A modern Linux distribution and parallel exploration platform for the **Parallella 16** (Zynq + 16-core Epiphany).

## Core Idea

The Epiphany's 16 RISC cores are used as a **low-power parallel idea generation engine**. Multiple independent explorers run simultaneously across the mesh, constantly generating ideas, alternative solutions, and novel connections without user initiation.

This is the key differentiator versus a normal Raspberry Pi or other single/quad-core boards.

## Key Features

- True parallel exploration across 16 Epiphany cores
- Low-power always-on operation
- Proactive idea surfacing (the system pings you)
- Uses Grok via OAuth for high-quality evaluation
- Modern first-boot experience and tooling

## Project Structure

```
parallella-modern/
├── explorer/           # Parallel Idea Engine
│   ├── core/           # Epiphany explorer kernels
│   ├── aggregator/     # ARM-side collection and orchestration
│   └── docs/
├── buildroot/          # Image configurations (headless + desktop)
├── scripts/            # First-boot installer, FPGA tools
├── epiphany/           # Lower-level Epiphany kernels and Python bindings
└── docs/
```

## Status

Early development. The Parallel Autonomous Idea Engine is the current focus.

## License

MIT License