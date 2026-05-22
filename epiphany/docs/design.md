# Epiphany LLM Layer Design

## Goals

- Provide a clean way to run small quantized models on the 16 Epiphany cores
- Expose useful LLM primitives (matmul, attention scoring, quantization)
- Keep the API simple from Python
- Stay within the tight memory constraints of the Epiphany (32KB per core)

## Target Workloads

- Quantized matrix multiplication
- Attention score computation (dot product + softmax)
- Small MLP / transformer block inference
- Speculative decoding draft models

## Architecture

- **Host side (ARM)**: Python API + model loading + weight management
- **Device side (Epiphany)**: Core kernels written in C using the eSDK
- Communication via shared memory regions and explicit message passing

## Memory Strategy

Because each Epiphany core only has 32KB of local memory, we will:

- Use tiling / blocking for larger matrices
- Keep weights quantized (INT8 or lower)
- Stream data between cores when needed
- Avoid complex data structures

## Next Steps

1. Implement a basic `matmul` kernel for the Epiphany
2. Create a minimal Python wrapper
3. Add quantization helpers
4. Build a tiny end-to-end example (e.g. small MLP)