/*
 * Basic Matrix Multiplication Kernel for Epiphany
 * This is a starting point. Will be optimized and tiled later.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "e_lib.h"

#define MAX_DIM 64   // Will be tuned based on local memory

int main(void) {
    // Placeholder for shared memory pointers
    volatile float *A = (volatile float *)0x8e000000;  // Example address
    volatile float *B = (volatile float *)0x8e010000;
    volatile float *C = (volatile float *)0x8e020000;

    int M = 32;
    int N = 32;
    int K = 32;

    // Very naive matmul for initial testing
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            float sum = 0.0f;
            for (int k = 0; k < K; k++) {
                sum += A[i*K + k] * B[k*N + j];
            }
            C[i*N + j] = sum;
        }
    }

    return 0;
}