/*
 * Tiled Matrix Multiplication Kernel for Epiphany
 * Basic blocking to improve data reuse within 32KB local memory.
 */

#include <stdio.h>
#include "e_lib.h"

#define TILE_SIZE 16   // Tuned for Epiphany local memory

void matmul_tiled(float *A, float *B, float *C, int M, int N, int K) {
    for (int i = 0; i < M; i += TILE_SIZE) {
        for (int j = 0; j < N; j += TILE_SIZE) {
            for (int ii = 0; ii < TILE_SIZE && (i + ii) < M; ii++) {
                for (int jj = 0; jj < TILE_SIZE && (j + jj) < N; jj++) {
                    float sum = 0.0f;
                    for (int k = 0; k < K; k++) {
                        sum += A[(i + ii) * K + k] * B[k * N + (j + jj)];
                    }
                    C[(i + ii) * N + (j + jj)] = sum;
                }
            }
        }
    }
}

int main(void) {
    // Shared memory addresses would be set up by host
    volatile float *A = (volatile float *)0x8e000000;
    volatile float *B = (volatile float *)0x8e010000;
    volatile float *C = (volatile float *)0x8e020000;

    int M = 32, N = 32, K = 32;

    matmul_tiled((float *)A, (float *)B, (float *)C, M, N, K);

    return 0;
}