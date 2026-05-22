# Epiphany LLM / Parallel Layer

This directory contains the Epiphany-side code for running small, quantized, and parallel workloads — with a focus on modern LLM components that benefit from simple RISC cores.

## Philosophy

The Epiphany's strength is **predictable, regular, data-parallel execution** at very low power. We are not trying to run large models. Instead, we focus on:

- Quantized inference (INT8, INT4, binary)
- Attention scoring and KV cache operations
- Small draft models for speculative decoding
- Custom matrix and vector kernels

## Current Progress

- Basic and tiled matrix multiplication kernels
- Quantization utilities (INT8 symmetric)
- High-level Python API skeleton
- Tiny MLP example

## Structure

```
epiphany/
├── kernels/          # Low-level C kernels
│   ├── matmul.c
│   └── matmul_tiled.c
├── python/           # Python bindings and helpers
│   ├── epiphany_llm.py
│   └── quantization.py
├── examples/         # End-to-end examples
│   └── tiny_mlp.py
└── docs/             # Design notes
```

## Next Goals

- Improve tiled matmul performance
- Add basic attention scoring kernel
- Better Python <-> Epiphany communication layer
- End-to-end quantized inference example