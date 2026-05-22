# Epiphany LLM / Parallel Layer

This directory contains the Epiphany-side code for running small, quantized, and parallel workloads — with a focus on modern LLM components that benefit from simple RISC cores.

## Philosophy

The Epiphany's strength is **predictable, regular, data-parallel execution** at very low power. We are not trying to run large models. Instead, we focus on:

- Quantized inference (INT8, INT4, binary)
- Attention scoring and KV cache operations
- Small draft models for speculative decoding
- Custom matrix and vector kernels

## Structure

```
epiphany/
├── kernels/      # Low-level C kernels for the Epiphany cores
├── python/       # Python bindings and high-level API
├── docs/         # Documentation and design notes
└── examples/     # Example models and workloads
```

## Current Status

Early scaffolding. Kernel and Python layer design in progress.