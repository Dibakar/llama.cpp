// SPDX-FileCopyrightText: Copyright 2024 Arm Ltd.
#pragma once

#define GGML_COMMON_DECL_C
#include "ggml-common.h"

#include "ggml.h"

// GGML internal header

#ifdef __cplusplus
extern "C" {
#endif

// Quantization
void quantize_q8_0_4x4(const float * GGML_RESTRICT x, void * GGML_RESTRICT y, int64_t k);
void quantize_q8_0_4x8(const float * GGML_RESTRICT x, void * GGML_RESTRICT y, int64_t k);

// Quantization utilizing an importance matrix (a.k.a. "Activation aWare Quantization")
size_t quantize_q4_0_4x4(const float * GGML_RESTRICT src, void * GGML_RESTRICT dst, int64_t nrows, int64_t n_per_row, const float * imatrix);
size_t quantize_q4_0_4x8(const float * GGML_RESTRICT src, void * GGML_RESTRICT dst, int64_t nrows, int64_t n_per_row, const float * imatrix);
size_t quantize_q4_0_8x8(const float * GGML_RESTRICT src, void * GGML_RESTRICT dst, int64_t nrows, int64_t n_per_row, const float * imatrix);

// GEMV
void ggml_gemv_q4_0_4x4_q8_0  (int n, float * GGML_RESTRICT s, const void * GGML_RESTRICT vx, const void * GGML_RESTRICT vy, int nr, int nc, int ith, int nth);
void ggml_gemv_q4_0_4x8_q8_0  (int n, float * GGML_RESTRICT s, const void * GGML_RESTRICT vx, const void * GGML_RESTRICT vy, int nr, int nc, int ith, int nth);
void ggml_gemv_q4_0_8x8_q8_0  (int n, float * GGML_RESTRICT s, const void * GGML_RESTRICT vx, const void * GGML_RESTRICT vy, int nr, int nc, int ith, int nth);

// GEMM
void ggml_gemm_q4_0_4x4_q8_0  (int n, float * GGML_RESTRICT s, const void * GGML_RESTRICT vx, const void * GGML_RESTRICT vy, int nr, int nc, int ith, int nth);
void ggml_gemm_q4_0_4x8_q8_0  (int n, float * GGML_RESTRICT s, const void * GGML_RESTRICT vx, const void * GGML_RESTRICT vy, int nr, int nc, int ith, int nth);
void ggml_gemm_q4_0_8x8_q8_0  (int n, float * GGML_RESTRICT s, const void * GGML_RESTRICT vx, const void * GGML_RESTRICT vy, int nr, int nc, int ith, int nth);

#ifdef __cplusplus
}
#endif
