"""
Tiny MLP example for Epiphany LLM layer

This demonstrates running a very small quantized MLP using the Epiphany.
"""

from epiphany_llm import EpiphanyModel
from quantization import quantize_to_int8
import numpy as np

def main():
    # Create a tiny model (e.g. 784 -> 64 -> 10 for MNIST-like)
    model = EpiphanyModel()

    # Fake weights
    w1 = np.random.randn(784, 64).astype(np.float32)
    w2 = np.random.randn(64, 10).astype(np.float32)

    # Quantize
    w1_q, scale1 = quantize_to_int8(w1)
    w2_q, scale2 = quantize_to_int8(w2)

    print("Weights quantized. Loading onto Epiphany...")

    model.load()
    output = model.predict(np.random.randn(784).astype(np.float32))

    print("Inference complete. Output:", output)

if __name__ == "__main__":
    main()