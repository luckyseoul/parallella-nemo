"""
Simple quantization utilities for Epiphany LLM workloads
"""

import numpy as np

def quantize_to_int8(weights, scale=None):
    """Quantize float32 weights to INT8"""
    if scale is None:
        scale = np.max(np.abs(weights)) / 127.0
    q = np.round(weights / scale).astype(np.int8)
    return q, scale

def dequantize(q, scale):
    """Dequantize INT8 back to float32"""
    return q.astype(np.float32) * scale

def quantize_symmetric(weights, bits=8):
    """Symmetric quantization"""
    max_val = np.max(np.abs(weights))
    scale = max_val / (2**(bits-1) - 1)
    q = np.round(weights / scale).astype(np.int8)
    return q, scale