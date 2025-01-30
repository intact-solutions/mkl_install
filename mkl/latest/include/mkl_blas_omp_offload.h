/*******************************************************************************
* Copyright 2019-2023 Intel Corporation.
*
* This software and the related documents are Intel copyrighted  materials,  and
* your use of  them is  governed by the  express license  under which  they were
* provided to you (License).  Unless the License provides otherwise, you may not
* use, modify, copy, publish, distribute,  disclose or transmit this software or
* the related documents without Intel's prior written permission.
*
* This software and the related documents  are provided as  is,  with no express
* or implied  warranties,  other  than those  that are  expressly stated  in the
* License.
*******************************************************************************/

/*
!  Content:
!      Intel(R) oneAPI Math Kernel Library (oneMKL) C/C++ OpenMP offload
!      interface
!******************************************************************************/

#ifndef _MKL_BLAS_OMP_OFFLOAD_H_
#define _MKL_BLAS_OMP_OFFLOAD_H_

#include "mkl_types.h"
#include "mkl_blas_omp_variant.h"

#include <omp.h>

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

// Matrix transposition and copy API

#define mkl_simatcopy_batch_strided MKL_Simatcopy_batch_strided
#pragma omp declare variant (MKL_CBLAS_VARIANT_NAME(simatcopy_batch_strided)) match(construct={dispatch}, device={arch(gen)}) append_args(interop(prefer_type("sycl","level_zero"),targetsync)) adjust_args(need_device_ptr:AB)
void MKL_Simatcopy_batch_strided(const char ordering, const char trans,
                                 size_t rows, size_t cols,
                                 const float alpha,
                                 float * AB, size_t lda, size_t ldb,
                                 size_t stride, size_t batch_size) NOTHROW;

#define mkl_dimatcopy_batch_strided MKL_Dimatcopy_batch_strided
#pragma  omp declare variant (MKL_CBLAS_VARIANT_NAME(dimatcopy_batch_strided)) match(construct={dispatch}, device={arch(gen)}) \
    append_args(interop(prefer_type("sycl","level_zero"),targetsync)) \
    adjust_args(need_device_ptr:AB)
void MKL_Dimatcopy_batch_strided(const char ordering, const char trans,
                                 size_t rows, size_t cols,
                                 const double alpha,
                                 double * AB, size_t lda, size_t ldb,
                                 size_t stride, size_t batch_size) NOTHROW;

#define mkl_cimatcopy_batch_strided MKL_Cimatcopy_batch_strided
#pragma omp declare variant (MKL_CBLAS_VARIANT_NAME(cimatcopy_batch_strided)) match(construct={dispatch}, device={arch(gen)}) \
    append_args(interop(prefer_type("sycl","level_zero"),targetsync)) \
    adjust_args(need_device_ptr:AB)
void MKL_Cimatcopy_batch_strided(const char ordering, const char trans,
                                 size_t rows, size_t cols,
                                 const MKL_Complex8 alpha,
                                 MKL_Complex8 * AB, size_t lda, size_t ldb,
                                 size_t stride, size_t batch_size) NOTHROW;

#define mkl_zimatcopy_batch_strided MKL_Zimatcopy_batch_strided
#pragma omp declare variant (MKL_CBLAS_VARIANT_NAME(zimatcopy_batch_strided)) match(construct={dispatch}, device={arch(gen)}) \
    append_args(interop(prefer_type("sycl","level_zero"),targetsync)) \
    adjust_args(need_device_ptr:AB)
void MKL_Zimatcopy_batch_strided(const char ordering, const char trans,
                                 size_t rows, size_t cols,
                                 const MKL_Complex16 alpha,
                                 MKL_Complex16 * AB, size_t lda, size_t ldb,
                                 size_t stride, size_t batch_size) NOTHROW;

#define mkl_somatcopy_batch_strided MKL_Somatcopy_batch_strided
#pragma omp declare variant (MKL_CBLAS_VARIANT_NAME(somatcopy_batch_strided)) match(construct={dispatch}, device={arch(gen)}) \
    append_args(interop(prefer_type("sycl","level_zero"),targetsync)) \
    adjust_args(need_device_ptr:A,B)
void MKL_Somatcopy_batch_strided(char ordering, char trans,
                                 size_t rows, size_t cols,
                                 const float alpha,
                                 const float * A, size_t lda, size_t stridea,
                                 float *B, size_t ldb, size_t strideb, size_t batch_size) NOTHROW;

#define mkl_domatcopy_batch_strided MKL_Domatcopy_batch_strided
#pragma omp declare variant (MKL_CBLAS_VARIANT_NAME(domatcopy_batch_strided)) match(construct={dispatch}, device={arch(gen)}) \
    append_args(interop(prefer_type("sycl","level_zero"),targetsync)) \
    adjust_args(need_device_ptr:A,B)
void MKL_Domatcopy_batch_strided(char ordering, char trans,
                                 size_t rows, size_t cols,
                                 const double alpha,
                                 const double * A, size_t lda, size_t stridea,
                                 double *B, size_t ldb, size_t strideb, size_t batch_size) NOTHROW;

#define mkl_comatcopy_batch_strided MKL_Comatcopy_batch_strided
#pragma omp declare variant (MKL_CBLAS_VARIANT_NAME(comatcopy_batch_strided)) match(construct={dispatch}, device={arch(gen)}) \
    append_args(interop(prefer_type("sycl","level_zero"),targetsync)) \
    adjust_args(need_device_ptr:A,B)
void MKL_Comatcopy_batch_strided(char ordering, char trans,
                                 size_t rows, size_t cols,
                                 const MKL_Complex8 alpha,
                                 const MKL_Complex8 * A, size_t lda, size_t stridea,
                                 MKL_Complex8 *B, size_t ldb, size_t strideb, size_t batch_size) NOTHROW;

#define mkl_zomatcopy_batch_strided MKL_Zomatcopy_batch_strided
#pragma omp declare variant (MKL_CBLAS_VARIANT_NAME(zomatcopy_batch_strided)) match(construct={dispatch}, device={arch(gen)}) \
    append_args(interop(prefer_type("sycl","level_zero"),targetsync)) \
    adjust_args(need_device_ptr:A,B)
void MKL_Zomatcopy_batch_strided(char ordering, char trans,
                                 size_t rows, size_t cols,
                                 const MKL_Complex16 alpha,
                                 const MKL_Complex16 * A, size_t lda, size_t stridea,
                                 MKL_Complex16 *B, size_t ldb, size_t strideb, size_t batch_size) NOTHROW;

#define mkl_simatcopy_batch MKL_Simatcopy_batch
#pragma omp declare variant (MKL_CBLAS_VARIANT_NAME(simatcopy_batch)) match(construct={dispatch}, device={arch(gen)}) \
    append_args(interop(prefer_type("sycl","level_zero"),targetsync)) \
    adjust_args(need_device_ptr:AB_array)
void MKL_Simatcopy_batch(
    char ordering, const char * trans_array,
    const size_t * rows_array, const size_t * cols_array,
    const float * alpha_array, float ** AB_array,
    const size_t * lda_array, const size_t * ldb_array,
    size_t group_count, const size_t * group_size) NOTHROW;

#define mkl_dimatcopy_batch MKL_Dimatcopy_batch
#pragma omp declare variant (MKL_CBLAS_VARIANT_NAME(dimatcopy_batch)) match(construct={dispatch}, device={arch(gen)}) \
    append_args(interop(prefer_type("sycl","level_zero"),targetsync)) \
    adjust_args(need_device_ptr:AB_array)
void MKL_Dimatcopy_batch(
    char ordering, const char * trans_array,
    const size_t * rows_array, const size_t * cols_array,
    const double * alpha_array, double ** AB_array,
    const size_t * lda_array, const size_t * ldb_array,
    size_t group_count, const size_t * group_size) NOTHROW;

#define mkl_cimatcopy_batch MKL_Cimatcopy_batch
#pragma omp declare variant (MKL_CBLAS_VARIANT_NAME(cimatcopy_batch)) match(construct={dispatch}, device={arch(gen)}) \
    append_args(interop(prefer_type("sycl","level_zero"),targetsync)) \
    adjust_args(need_device_ptr:AB_array)
void MKL_Cimatcopy_batch(
    char ordering, const char * trans_array,
    const size_t * rows_array, const size_t * cols_array,
    const MKL_Complex8 * alpha_array, MKL_Complex8 ** AB_array,
    const size_t * lda_array, const size_t * ldb_array,
    size_t group_count, const size_t * group_size) NOTHROW;

#define mkl_zimatcopy_batch MKL_Zimatcopy_batch
#pragma omp declare variant (MKL_CBLAS_VARIANT_NAME(zimatcopy_batch)) match(construct={dispatch}, device={arch(gen)}) \
    append_args(interop(prefer_type("sycl","level_zero"),targetsync)) \
    adjust_args(need_device_ptr:AB_array)
void MKL_Zimatcopy_batch(
    char ordering, const char * trans_array,
    const size_t * rows_array, const size_t * cols_array,
    const MKL_Complex16 * alpha_array, MKL_Complex16 ** AB_array,
    const size_t * lda_array, const size_t * ldb_array,
    size_t group_count, const size_t * group_size) NOTHROW;

#define mkl_somatcopy_batch MKL_Somatcopy_batch
#pragma omp declare variant (MKL_CBLAS_VARIANT_NAME(somatcopy_batch)) match(construct={dispatch}, device={arch(gen)}) \
    append_args(interop(prefer_type("sycl","level_zero"),targetsync)) \
    adjust_args(need_device_ptr:A_array,B_array)
void MKL_Somatcopy_batch(
    char ordering, const char * trans_array,
    const size_t * rows_array, const size_t * cols_array,
    const float * alpha_array, const float ** A_array,
    const size_t * lda_array, float ** B_array,
    const size_t * ldb_array, size_t group_count,
    const size_t * group_size) NOTHROW;

#define mkl_domatcopy_batch MKL_Domatcopy_batch
#pragma omp declare variant (MKL_CBLAS_VARIANT_NAME(domatcopy_batch)) match(construct={dispatch}, device={arch(gen)}) \
    append_args(interop(prefer_type("sycl","level_zero"),targetsync)) \
    adjust_args(need_device_ptr:A_array,B_array)
void MKL_Domatcopy_batch(
    char ordering, const char * trans_array,
    const size_t * rows_array, const size_t * cols_array,
    const double * alpha_array, const double ** A_array,
    const size_t * lda_array, double ** B_array,
    const size_t * ldb_array, size_t group_count,
    const size_t * group_size) NOTHROW;

#define mkl_comatcopy_batch MKL_Comatcopy_batch
#pragma omp declare variant (MKL_CBLAS_VARIANT_NAME(comatcopy_batch)) match(construct={dispatch}, device={arch(gen)}) \
    append_args(interop(prefer_type("sycl","level_zero"),targetsync)) \
    adjust_args(need_device_ptr:A_array,B_array)
void MKL_Comatcopy_batch(
    char ordering, const char * trans_array,
    const size_t * rows_array, const size_t * cols_array,
    const MKL_Complex8 * alpha_array, const MKL_Complex8 ** A_array,
    const size_t * lda_array, MKL_Complex8 ** B_array,
    const size_t * ldb_array, size_t group_count,
    const size_t * group_size) NOTHROW;

#define mkl_zomatcopy_batch MKL_Zomatcopy_batch
#pragma omp declare variant (MKL_CBLAS_VARIANT_NAME(zomatcopy_batch)) match(construct={dispatch}, device={arch(gen)}) \
    append_args(interop(prefer_type("sycl","level_zero"),targetsync)) \
    adjust_args(need_device_ptr:A_array,B_array)
void MKL_Zomatcopy_batch(
    char ordering, const char * trans_array,
    const size_t * rows_array, const size_t * cols_array,
    const MKL_Complex16 * alpha_array, const MKL_Complex16 ** A_array,
    const size_t * lda_array, MKL_Complex16 ** B_array,
    const size_t * ldb_array, size_t group_count,
    const size_t * group_size) NOTHROW;

#define mkl_somatadd_batch_strided MKL_Somatadd_batch_strided
#pragma omp declare variant (MKL_CBLAS_VARIANT_NAME(somatadd_batch_strided)) \
    match(construct={dispatch}, device={arch(gen)}) append_args(interop(prefer_type("sycl","level_zero"),targetsync)) \
    adjust_args(need_device_ptr:A,B,C)
void MKL_Somatadd_batch_strided(
    char ordering, char transa, char transb,
    size_t rows, size_t cols,
    const float alpha, const float * A, size_t lda, size_t stridea,
    const float beta, const float * B, size_t ldb, size_t strideb,
    float * C, size_t ldc, size_t stridec, size_t batch_size) NOTHROW;

#define mkl_domatadd_batch_strided MKL_Domatadd_batch_strided
#pragma omp declare variant (MKL_CBLAS_VARIANT_NAME(domatadd_batch_strided)) \
    match(construct={dispatch}, device={arch(gen)}) append_args(interop(prefer_type("sycl","level_zero"),targetsync)) \
    adjust_args(need_device_ptr:A,B,C)
void MKL_Domatadd_batch_strided(
    char ordering, char transa, char transb,
    size_t rows, size_t cols,
    const double alpha, const double * A, size_t lda, size_t stridea,
    const double beta, const double * B, size_t ldb, size_t strideb,
    double * C, size_t ldc, size_t stridec, size_t batch_size) NOTHROW;

#define mkl_comatadd_batch_strided MKL_Comatadd_batch_strided
#pragma omp declare variant (MKL_CBLAS_VARIANT_NAME(comatadd_batch_strided)) \
    match(construct={dispatch}, device={arch(gen)}) append_args(interop(prefer_type("sycl","level_zero"),targetsync)) \
    adjust_args(need_device_ptr:A,B,C)
void MKL_Comatadd_batch_strided(
    char ordering, char transa, char transb,
    size_t rows, size_t cols,
    const MKL_Complex8 alpha, const MKL_Complex8 * A, size_t lda, size_t stridea,
    const MKL_Complex8 beta, const MKL_Complex8 * B, size_t ldb, size_t strideb,
    MKL_Complex8 * C, size_t ldc, size_t stridec, size_t batch_size) NOTHROW;

#define mkl_zomatadd_batch_strided MKL_Zomatadd_batch_strided
#pragma omp declare variant (MKL_CBLAS_VARIANT_NAME(zomatadd_batch_strided)) \
    match(construct={dispatch}, device={arch(gen)}) append_args(interop(prefer_type("sycl","level_zero"),targetsync)) \
    adjust_args(need_device_ptr:A,B,C)
void MKL_Zomatadd_batch_strided(
    char ordering, char transa, char transb,
    size_t rows, size_t cols,
    const MKL_Complex16 alpha, const MKL_Complex16 * A, size_t lda, size_t stridea,
    const MKL_Complex16 beta, const MKL_Complex16 * B, size_t ldb, size_t strideb,
    MKL_Complex16 * C, size_t ldc, size_t stridec, size_t batch_size) NOTHROW;


// BATCH APIs

// Level3

#pragma omp declare variant (MKL_CBLAS_VARIANT_NAME(sgemm_batch)) match(construct={dispatch}, device={arch(gen)}) \
    append_args(interop(prefer_type("sycl","level_zero"),targetsync)) \
    adjust_args(need_device_ptr:A_Array,B_Array,C_Array)
void cblas_sgemm_batch(const CBLAS_LAYOUT Layout, const CBLAS_TRANSPOSE *TransA_Array,
                       const CBLAS_TRANSPOSE *TransB_Array, const MKL_INT *M_Array, const MKL_INT *N_Array,
                       const MKL_INT *K_Array, const float *alpha_Array, const float **A_Array,
                       const MKL_INT *lda_Array, const float **B_Array, const MKL_INT *ldb_Array,
                       const float *beta_Array, float **C_Array, const MKL_INT *ldc_Array,
                       const MKL_INT group_count, const MKL_INT *group_size) NOTHROW;

#pragma omp declare variant (MKL_CBLAS_VARIANT_NAME(dgemm_batch)) match(construct={dispatch}, device={arch(gen)}) \
    append_args(interop(prefer_type("sycl","level_zero"),targetsync)) \
    adjust_args(need_device_ptr:A_Array,B_Array,C_Array)
void cblas_dgemm_batch(const CBLAS_LAYOUT Layout, const CBLAS_TRANSPOSE *TransA_Array,
                       const CBLAS_TRANSPOSE *TransB_Array, const MKL_INT *M_Array, const MKL_INT *N_Array,
                       const MKL_INT *K_Array, const double *alpha_Array, const double **A_Array,
                       const MKL_INT *lda_Array, const double **B_Array, const MKL_INT* ldb_Array,
                       const double *beta_Array, double **C_Array, const MKL_INT *ldc_Array,
                       const MKL_INT group_count, const MKL_INT *group_size) NOTHROW;

#pragma omp declare variant (MKL_CBLAS_VARIANT_NAME(cgemm_batch)) match(construct={dispatch}, device={arch(gen)}) \
    append_args(interop(prefer_type("sycl","level_zero"),targetsync)) \
    adjust_args(need_device_ptr:A_Array,B_Array,C_Array)
void cblas_cgemm_batch(const CBLAS_LAYOUT Layout, const CBLAS_TRANSPOSE *TransA_Array,
                       const CBLAS_TRANSPOSE *TransB_Array, const MKL_INT *M_Array, const MKL_INT *N_Array,
                       const MKL_INT *K_Array, const void *alpha_Array, const void **A_Array,
                       const MKL_INT *lda_Array, const void **B_Array, const MKL_INT* ldb_Array,
                       const void *beta_Array, void **C_Array, const MKL_INT *ldc_Array,
                       const MKL_INT group_count, const MKL_INT *group_size) NOTHROW;

#pragma omp declare variant (MKL_CBLAS_VARIANT_NAME(zgemm_batch)) match(construct={dispatch}, device={arch(gen)}) \
    append_args(interop(prefer_type("sycl","level_zero"),targetsync)) \
    adjust_args(need_device_ptr:A_Array,B_Array,C_Array)
void cblas_zgemm_batch(const CBLAS_LAYOUT Layout, const CBLAS_TRANSPOSE *TransA_Array,
                       const CBLAS_TRANSPOSE *TransB_Array, const MKL_INT *M_Array, const MKL_INT *N_Array,
                       const MKL_INT *K_Array, const void *alpha_Array, const void **A_Array,
                       const MKL_INT *lda_Array, const void **B_Array, const MKL_INT* ldb_Array,
                       const void *beta_Array, void **C_Array, const MKL_INT *ldc_Array,
                       const MKL_INT group_count, const MKL_INT *group_size) NOTHROW;

#pragma omp declare variant (MKL_CBLAS_VARIANT_NAME(cgemm3m_batch)) match(construct={dispatch}, device={arch(gen)}) \
    append_args(interop(prefer_type("sycl","level_zero"),targetsync)) \
    adjust_args(need_device_ptr:A_Array,B_Array,C_Array)
void cblas_cgemm3m_batch(const CBLAS_LAYOUT Layout, const CBLAS_TRANSPOSE *TransA_Array,
                       const CBLAS_TRANSPOSE *TransB_Array, const MKL_INT *M_Array, const MKL_INT *N_Array,
                       const MKL_INT *K_Array, const void *alpha_Array, const void **A_Array,
                       const MKL_INT *lda_Array, const void **B_Array, const MKL_INT* ldb_Array,
                       const void *beta_Array, void **C_Array, const MKL_INT *ldc_Array,
                       const MKL_INT group_count, const MKL_INT *group_size) NOTHROW;

#pragma omp declare variant (MKL_CBLAS_VARIANT_NAME(zgemm3m_batch)) match(construct={dispatch}, device={arch(gen)}) \
    append_args(interop(prefer_type("sycl","level_zero"),targetsync)) \
    adjust_args(need_device_ptr:A_Array,B_Array,C_Array)
void cblas_zgemm3m_batch(const CBLAS_LAYOUT Layout, const CBLAS_TRANSPOSE *TransA_Array,
                       const CBLAS_TRANSPOSE *TransB_Array, const MKL_INT *M_Array, const MKL_INT *N_Array,
                       const MKL_INT *K_Array, const void *alpha_Array, const void **A_Array,
                       const MKL_INT *lda_Array, const void **B_Array, const MKL_INT* ldb_Array,
                       const void *beta_Array, void **C_Array, const MKL_INT *ldc_Array,
                       const MKL_INT group_count, const MKL_INT *group_size) NOTHROW;

#pragma omp declare variant (MKL_BLAS_VARIANT_NAME(sgemm_batch)) match(construct={dispatch}, device={arch(gen)}) \
    append_args(interop(prefer_type("sycl","level_zero"),targetsync)) \
    adjust_args(need_device_ptr:a_array,b_array,c_array)
void sgemm_batch(const char *transa_array, const char *transb_array,
                 const MKL_INT *m_array, const MKL_INT *n_array, const MKL_INT *k_array,
                 const float *alpha_array, const float **a_array, const MKL_INT *lda_array,
                 const float **b_array, const MKL_INT *ldb_array,
                 const float *beta_array, float **c_array, const MKL_INT *ldc_array,
                 const MKL_INT *group_count, const MKL_INT *group_size) NOTHROW;

#pragma omp declare variant (MKL_BLAS_VARIANT_NAME(dgemm_batch)) match(construct={dispatch}, device={arch(gen)}) \
    append_args(interop(prefer_type("sycl","level_zero"),targetsync)) \
    adjust_args(need_device_ptr:a_array,b_array,c_array)
void dgemm_batch(const char *transa_array, const char *transb_array,
                 const MKL_INT *m_array, const MKL_INT *n_array, const MKL_INT *k_array,
                 const double *alpha_array, const double **a_array, const MKL_INT *lda_array,
                 const double **b_array, const MKL_INT *ldb_array,
                 const double *beta_array, double **c_array, const MKL_INT *ldc_array,
                 const MKL_INT *group_count, const MKL_INT *group_size) NOTHROW;

#pragma omp declare variant (MKL_BLAS_VARIANT_NAME(cgemm_batch)) match(construct={dispatch}, device={arch(gen)}) \
    append_args(interop(prefer_type("sycl","level_zero"),targetsync)) \
    adjust_args(need_device_ptr:a_array,b_array,c_array)
void cgemm_batch(const char *transa_array, const char *transb_array,
                 const MKL_INT *m_array, const MKL_INT *n_array, const MKL_INT *k_array,
                 const MKL_Complex8 *alpha_array, const MKL_Complex8 **a_array, const MKL_INT *lda_array,
                 const MKL_Complex8 **b_array, const MKL_INT *ldb_array,
                 const MKL_Complex8 *beta_array, MKL_Complex8 **c_array, const MKL_INT *ldc_array,
                 const MKL_INT *group_count, const MKL_INT *group_size) NOTHROW;

#pragma omp declare variant (MKL_BLAS_VARIANT_NAME(zgemm_batch)) match(construct={dispatch}, device={arch(gen)}) \
    append_args(interop(prefer_type("sycl","level_zero"),targetsync)) \
    adjust_args(need_device_ptr:a_array,b_array,c_array)
void zgemm_batch(const char *transa_array, const char *transb_array,
                 const MKL_INT *m_array, const MKL_INT *n_array, const MKL_INT *k_array,
                 const MKL_Complex16 *alpha_array, const MKL_Complex16 **a_array, const MKL_INT *lda_array,
                 const MKL_Complex16 **b_array, const MKL_INT *ldb_array,
                 const MKL_Complex16 *beta_array, MKL_Complex16 **c_array, const MKL_INT *ldc_array,
                 const MKL_INT *group_count, const MKL_INT *group_size) NOTHROW;

#pragma omp declare variant (MKL_BLAS_VARIANT_NAME(cgemm3m_batch)) match(construct={dispatch}, device={arch(gen)}) \
    append_args(interop(prefer_type("sycl","level_zero"),targetsync)) \
    adjust_args(need_device_ptr:a_array,b_array,c_array)
void cgemm3m_batch(const char *transa_array, const char *transb_array,
                 const MKL_INT *m_array, const MKL_INT *n_array, const MKL_INT *k_array,
                 const MKL_Complex8 *alpha_array, const MKL_Complex8 **a_array, const MKL_INT *lda_array,
                 const MKL_Complex8 **b_array, const MKL_INT *ldb_array,
                 const MKL_Complex8 *beta_array, MKL_Complex8 **c_array, const MKL_INT *ldc_array,
                 const MKL_INT *group_count, const MKL_INT *group_size) NOTHROW;

#pragma omp declare variant (MKL_BLAS_VARIANT_NAME(zgemm3m_batch)) match(construct={dispatch}, device={arch(gen)}) \
    append_args(interop(prefer_type("sycl","level_zero"),targetsync)) \
    adjust_args(need_device_ptr:a_array,b_array,c_array)
void zgemm3m_batch(const char *transa_array, const char *transb_array,
                 const MKL_INT *m_array, const MKL_INT *n_array, const MKL_INT *k_array,
                 const MKL_Complex16 *alpha_array, const MKL_Complex16 **a_array, const MKL_INT *lda_array,
                 const MKL_Complex16 **b_array, const MKL_INT *ldb_array,
                 const MKL_Complex16 *beta_array, MKL_Complex16 **c_array, const MKL_INT *ldc_array,
                 const MKL_INT *group_count, const MKL_INT *group_size) NOTHROW;

#pragma omp declare variant (MKL_CBLAS_VARIANT_NAME(sgemm_batch_strided)) match(construct={dispatch}, device={arch(gen)}) \
    append_args(interop(prefer_type("sycl","level_zero"),targetsync)) \
    adjust_args(need_device_ptr:A,B,C)
void cblas_sgemm_batch_strided(const CBLAS_LAYOUT Layout, const CBLAS_TRANSPOSE TransA,
                               const CBLAS_TRANSPOSE TransB, const MKL_INT M, const MKL_INT N,
                               const MKL_INT K, const float alpha, const float *A,
                               const MKL_INT lda, const MKL_INT stridea,
                               const float *B, const MKL_INT ldb, const MKL_INT strideb,
                               const float beta, float *C, const MKL_INT ldc, const MKL_INT stridec,
                               const MKL_INT batch_size) NOTHROW;

#pragma omp declare variant (MKL_CBLAS_VARIANT_NAME(dgemm_batch_strided)) match(construct={dispatch}, device={arch(gen)}) \
    append_args(interop(prefer_type("sycl","level_zero"),targetsync)) \
    adjust_args(need_device_ptr:A,B,C)
void cblas_dgemm_batch_strided(const CBLAS_LAYOUT Layout, const CBLAS_TRANSPOSE TransA,
                               const CBLAS_TRANSPOSE TransB, const MKL_INT M, const MKL_INT N,
                               const MKL_INT K, const double alpha, const double *A,
                               const MKL_INT lda, const MKL_INT stridea,
                               const double *B, const MKL_INT ldb, const MKL_INT strideb,
                               const double beta, double *C, const MKL_INT ldc, const MKL_INT stridec,
                               const MKL_INT batch_size) NOTHROW;

#pragma omp declare variant (MKL_CBLAS_VARIANT_NAME(cgemm_batch_strided)) match(construct={dispatch}, device={arch(gen)}) \
    append_args(interop(prefer_type("sycl","level_zero"),targetsync)) \
    adjust_args(need_device_ptr:A,B,C)
void cblas_cgemm_batch_strided(const CBLAS_LAYOUT Layout, const CBLAS_TRANSPOSE TransA,
                               const CBLAS_TRANSPOSE TransB, const MKL_INT M, const MKL_INT N,
                               const MKL_INT K, const void *alpha, const void *A,
                               const MKL_INT lda, const MKL_INT stridea,
                               const void *B, const MKL_INT ldb, const MKL_INT strideb,
                               const void *beta, void *C, const MKL_INT ldc, const MKL_INT stridec,
                               const MKL_INT batch_size) NOTHROW;

#pragma omp declare variant (MKL_CBLAS_VARIANT_NAME(zgemm_batch_strided)) match(construct={dispatch}, device={arch(gen)}) \
    append_args(interop(prefer_type("sycl","level_zero"),targetsync)) \
    adjust_args(need_device_ptr:A,B,C)
void cblas_zgemm_batch_strided(const CBLAS_LAYOUT Layout, const CBLAS_TRANSPOSE TransA,
                               const CBLAS_TRANSPOSE TransB, const MKL_INT M, const MKL_INT N,
                               const MKL_INT K, const void *alpha, const void *A,
                               const MKL_INT lda, const MKL_INT stridea,
                               const void *B, const MKL_INT ldb, const MKL_INT strideb,
                               const void *beta, void *C, const MKL_INT ldc, const MKL_INT stridec,
                               const MKL_INT batch_size) NOTHROW;

#pragma omp declare variant (MKL_CBLAS_VARIANT_NAME(cgemm_batch_strided)) match(construct={dispatch}, device={arch(gen)}) \
    append_args(interop(prefer_type("sycl","level_zero"),targetsync)) \
    adjust_args(need_device_ptr:A,B,C)
void cblas_cgemm3m_batch_strided(const CBLAS_LAYOUT Layout, const CBLAS_TRANSPOSE TransA,
                               const CBLAS_TRANSPOSE TransB, const MKL_INT M, const MKL_INT N,
                               const MKL_INT K, const void *alpha, const void *A,
                               const MKL_INT lda, const MKL_INT stridea,
                               const void *B, const MKL_INT ldb, const MKL_INT strideb,
                               const void *beta, void *C, const MKL_INT ldc, const MKL_INT stridec,
                               const MKL_INT batch_size) NOTHROW;

#pragma omp declare variant (MKL_CBLAS_VARIANT_NAME(zgemm3m_batch_strided)) match(construct={dispatch}, device={arch(gen)}) \
    append_args(interop(prefer_type("sycl","level_zero"),targetsync)) \
    adjust_args(need_device_ptr:A,B,C)
void cblas_zgemm3m_batch_strided(const CBLAS_LAYOUT Layout, const CBLAS_TRANSPOSE TransA,
                               const CBLAS_TRANSPOSE TransB, const MKL_INT M, const MKL_INT N,
                               const MKL_INT K, const void *alpha, const void *A,
                               const MKL_INT lda, const MKL_INT stridea,
                               const void *B, const MKL_INT ldb, const MKL_INT strideb,
                               const void *beta, void *C, const MKL_INT ldc, const MKL_INT stridec,
                               const MKL_INT batch_size) NOTHROW;

#pragma omp declare variant (MKL_BLAS_VARIANT_NAME(sgemm_batch_strided)) match(construct={dispatch}, device={arch(gen)}) \
    append_args(interop(prefer_type("sycl","level_zero"),targetsync)) \
    adjust_args(need_device_ptr:a,b,c)
void sgemm_batch_strided(const char *transa, const char *transb, const MKL_INT *m, const MKL_INT *n, const MKL_INT *k,
                 const float *alpha, const float *a, const MKL_INT *lda, const MKL_INT *stridea,
                 const float *b, const MKL_INT *ldb, const MKL_INT *strideb,
                 const float *beta, float *c, const MKL_INT *ldc, const MKL_INT *stridec,
                 const MKL_INT *batch_size) NOTHROW;

#pragma omp declare variant (MKL_BLAS_VARIANT_NAME(dgemm_batch_strided)) match(construct={dispatch}, device={arch(gen)}) \
    append_args(interop(prefer_type("sycl","level_zero"),targetsync)) \
    adjust_args(need_device_ptr:a,b,c)
void dgemm_batch_strided(const char *transa, const char *transb, const MKL_INT *m, const MKL_INT *n, const MKL_INT *k,
                 const double *alpha, const double *a, const MKL_INT *lda, const MKL_INT *stridea,
                 const double *b, const MKL_INT *ldb, const MKL_INT *strideb,
                 const double *beta, double *c, const MKL_INT *ldc, const MKL_INT *stridec,
                 const MKL_INT *batch_size) NOTHROW;

#pragma omp declare variant (MKL_BLAS_VARIANT_NAME(cgemm_batch_strided)) match(construct={dispatch}, device={arch(gen)}) \
    append_args(interop(prefer_type("sycl","level_zero"),targetsync)) \
    adjust_args(need_device_ptr:a,b,c)
void cgemm_batch_strided(const char *transa, const char *transb, const MKL_INT *m, const MKL_INT *n, const MKL_INT *k,
                 const MKL_Complex8 *alpha, const MKL_Complex8 *a, const MKL_INT *lda, const MKL_INT *stridea,
                 const MKL_Complex8 *b, const MKL_INT *ldb, const MKL_INT *strideb,
                 const MKL_Complex8 *beta, MKL_Complex8 *c, const MKL_INT *ldc, const MKL_INT *stridec,
                 const MKL_INT *batch_size) NOTHROW;

#pragma omp declare variant (MKL_BLAS_VARIANT_NAME(zgemm_batch_strided)) match(construct={dispatch}, device={arch(gen)}) \
    append_args(interop(prefer_type("sycl","level_zero"),targetsync)) \
    adjust_args(need_device_ptr:a,b,c)
void zgemm_batch_strided(const char *transa, const char *transb, const MKL_INT *m, const MKL_INT *n, const MKL_INT *k,
                 const MKL_Complex16 *alpha, const MKL_Complex16 *a, const MKL_INT *lda, const MKL_INT *stridea,
                 const MKL_Complex16 *b, const MKL_INT *ldb, const MKL_INT *strideb,
                 const MKL_Complex16 *beta, MKL_Complex16 *c, const MKL_INT *ldc, const MKL_INT *stridec,
                 const MKL_INT *batch_size) NOTHROW;

#pragma omp declare variant (MKL_BLAS_VARIANT_NAME(cgemm3m_batch_strided)) match(construct={dispatch}, device={arch(gen)}) \
    append_args(interop(prefer_type("sycl","level_zero"),targetsync)) \
    adjust_args(need_device_ptr:a,b,c)
void cgemm3m_batch_strided(const char *transa, const char *transb, const MKL_INT *m, const MKL_INT *n, const MKL_INT *k,
                 const MKL_Complex8 *alpha, const MKL_Complex8 *a, const MKL_INT *lda, const MKL_INT *stridea,
                 const MKL_Complex8 *b, const MKL_INT *ldb, const MKL_INT *strideb,
                 const MKL_Complex8 *beta, MKL_Complex8 *c, const MKL_INT *ldc, const MKL_INT *stridec,
                 const MKL_INT *batch_size) NOTHROW;

#pragma omp declare variant (MKL_BLAS_VARIANT_NAME(zgemm3m_batch_strided)) match(construct={dispatch}, device={arch(gen)}) \
    append_args(interop(prefer_type("sycl","level_zero"),targetsync)) \
    adjust_args(need_device_ptr:a,b,c)
void zgemm3m_batch_strided(const char *transa, const char *transb, const MKL_INT *m, const MKL_INT *n, const MKL_INT *k,
                 const MKL_Complex16 *alpha, const MKL_Complex16 *a, const MKL_INT *lda, const MKL_INT *stridea,
                 const MKL_Complex16 *b, const MKL_INT *ldb, const MKL_INT *strideb,
                 const MKL_Complex16 *beta, MKL_Complex16 *c, const MKL_INT *ldc, const MKL_INT *stridec,
                 const MKL_INT *batch_size) NOTHROW;

#pragma omp declare variant (MKL_CBLAS_VARIANT_NAME(ssyrk_batch)) match(construct={dispatch}, device={arch(gen)}) \
    append_args(interop(prefer_type("sycl","level_zero"),targetsync)) \
    adjust_args(need_device_ptr:A_Array,C_Array)
void cblas_ssyrk_batch(const CBLAS_LAYOUT Layout, const CBLAS_UPLO *Uplo_Array, const CBLAS_TRANSPOSE *Trans_Array,
                       const MKL_INT *N_Array, const MKL_INT *K_Array,
                       const float *alpha_Array, const float **A_Array, const MKL_INT *lda_Array,
                       const float *beta_Array, float **C_Array, const MKL_INT *ldc_Array,
                       const MKL_INT group_count, const MKL_INT *group_size) NOTHROW;

#pragma omp declare variant (MKL_CBLAS_VARIANT_NAME(dsyrk_batch)) match(construct={dispatch}, device={arch(gen)}) \
    append_args(interop(prefer_type("sycl","level_zero"),targetsync)) \
    adjust_args(need_device_ptr:A_Array,C_Array)
void cblas_dsyrk_batch(const CBLAS_LAYOUT Layout, const CBLAS_UPLO *Uplo_Array, const CBLAS_TRANSPOSE *Trans_Array,
                       const MKL_INT *N_Array, const MKL_INT *K_Array,
                       const double *alpha_Array, const double **A_Array, const MKL_INT *lda_Array,
                       const double *beta_Array, double **C_Array, const MKL_INT *ldc_Array,
                       const MKL_INT group_count, const MKL_INT *group_size) NOTHROW;

#pragma omp declare variant (MKL_CBLAS_VARIANT_NAME(csyrk_batch)) match(construct={dispatch}, device={arch(gen)}) \
    append_args(interop(prefer_type("sycl","level_zero"),targetsync)) \
    adjust_args(need_device_ptr:A_Array,C_Array)
void cblas_csyrk_batch(const CBLAS_LAYOUT Layout, const CBLAS_UPLO *Uplo_Array, const CBLAS_TRANSPOSE *Trans_Array,
                       const MKL_INT *N_Array, const MKL_INT *K_Array,
                       const void *alpha_Array, const void **A_Array, const MKL_INT *lda_Array,
                       const void *beta_Array, void **C_Array, const MKL_INT *ldc_Array,
                       const MKL_INT group_count, const MKL_INT *group_size) NOTHROW;

#pragma omp declare variant (MKL_CBLAS_VARIANT_NAME(zsyrk_batch)) match(construct={dispatch}, device={arch(gen)}) \
    append_args(interop(prefer_type("sycl","level_zero"),targetsync)) \
    adjust_args(need_device_ptr:A_Array,C_Array)
void cblas_zsyrk_batch(const CBLAS_LAYOUT Layout, const CBLAS_UPLO *Uplo_Array, const CBLAS_TRANSPOSE *Trans_Array,
                       const MKL_INT *N_Array, const MKL_INT *K_Array,
                       const void *alpha_Array, const void **A_Array, const MKL_INT *lda_Array,
                       const void *beta_Array, void **C_Array, const MKL_INT *ldc_Array,
                       const MKL_INT group_count, const MKL_INT *group_size) NOTHROW;

#pragma omp declare variant (MKL_CBLAS_VARIANT_NAME(ssyrk_batch_strided)) match(construct={dispatch}, device={arch(gen)}) \
    append_args(interop(prefer_type("sycl","level_zero"),targetsync)) \
    adjust_args(need_device_ptr:A,C)
void cblas_ssyrk_batch_strided(const CBLAS_LAYOUT Layout, const CBLAS_UPLO Uplo,
                               const CBLAS_TRANSPOSE Trans, const MKL_INT N,
                               const MKL_INT K, const float alpha, const float *A,
                               const MKL_INT lda, const MKL_INT stridea,
                               const float beta, float *C, const MKL_INT ldc, const MKL_INT stridec,
                               const MKL_INT batch_size) NOTHROW;

#pragma omp declare variant (MKL_CBLAS_VARIANT_NAME(dsyrk_batch_strided)) match(construct={dispatch}, device={arch(gen)}) \
    append_args(interop(prefer_type("sycl","level_zero"),targetsync)) \
    adjust_args(need_device_ptr:A,C)
void cblas_dsyrk_batch_strided(const CBLAS_LAYOUT Layout, const CBLAS_UPLO Uplo,
                               const CBLAS_TRANSPOSE Trans, const MKL_INT N,
                               const MKL_INT K, const double alpha, const double *A,
                               const MKL_INT lda, const MKL_INT stridea,
                               const double beta, double *C, const MKL_INT ldc, const MKL_INT stridec,
                               const MKL_INT batch_size) NOTHROW;

#pragma omp declare variant (MKL_CBLAS_VARIANT_NAME(csyrk_batch_strided)) match(construct={dispatch}, device={arch(gen)}) \
    append_args(interop(prefer_type("sycl","level_zero"),targetsync)) \
    adjust_args(need_device_ptr:A,C)
void cblas_csyrk_batch_strided(const CBLAS_LAYOUT Layout, const CBLAS_UPLO Uplo,
                               const CBLAS_TRANSPOSE Trans, const MKL_INT N,
                               const MKL_INT K, const void *alpha, const void *A,
                               const MKL_INT lda, const MKL_INT stridea,
                               const void *beta, void *C, const MKL_INT ldc, const MKL_INT stridec,
                               const MKL_INT batch_size) NOTHROW;

#pragma omp declare variant (MKL_CBLAS_VARIANT_NAME(zsyrk_batch_strided)) match(construct={dispatch}, device={arch(gen)}) \
    append_args(interop(prefer_type("sycl","level_zero"),targetsync)) \
    adjust_args(need_device_ptr:A,C)
void cblas_zsyrk_batch_strided(const CBLAS_LAYOUT Layout, const CBLAS_UPLO Uplo,
                               const CBLAS_TRANSPOSE Trans, const MKL_INT N,
                               const MKL_INT K, const void *alpha, const void *A,
                               const MKL_INT lda, const MKL_INT stridea,
                               const void *beta, void *C, const MKL_INT ldc, const MKL_INT stridec,
                               const MKL_INT batch_size) NOTHROW;

#pragma omp declare variant (MKL_BLAS_VARIANT_NAME(ssyrk_batch)) match(construct={dispatch}, device={arch(gen)}) \
    append_args(interop(prefer_type("sycl","level_zero"),targetsync)) \
    adjust_args(need_device_ptr:a_array,c_array)
void ssyrk_batch(const char *uplo_array, const char *trans_array,
                 const MKL_INT *n_array, const MKL_INT *k_array,
                 const float *alpha_array, const float **a_array, const MKL_INT *lda_array,
                 const float *beta_array, float **c_array, const MKL_INT *ldc_array,
                 const MKL_INT *group_count, const MKL_INT *group_size) NOTHROW;

#pragma omp declare variant (MKL_BLAS_VARIANT_NAME(dsyrk_batch)) match(construct={dispatch}, device={arch(gen)}) \
    append_args(interop(prefer_type("sycl","level_zero"),targetsync)) \
    adjust_args(need_device_ptr:a_array,c_array)
void dsyrk_batch(const char *uplo_array, const char *trans_array,
                 const MKL_INT *n_array, const MKL_INT *k_array,
                 const double *alpha_array, const double **a_array, const MKL_INT *lda_array,
                 const double *beta_array, double **c_array, const MKL_INT *ldc_array,
                 const MKL_INT *group_count, const MKL_INT *group_size) NOTHROW;

#pragma omp declare variant (MKL_BLAS_VARIANT_NAME(csyrk_batch)) match(construct={dispatch}, device={arch(gen)}) \
    append_args(interop(prefer_type("sycl","level_zero"),targetsync)) \
    adjust_args(need_device_ptr:a_array,c_array)
void csyrk_batch(const char *uplo_array, const char *trans_array,
                 const MKL_INT *n_array, const MKL_INT *k_array,
                 const MKL_Complex8 *alpha_array, const MKL_Complex8 **a_array, const MKL_INT *lda_array,
                 const MKL_Complex8 *beta_array, MKL_Complex8 **c_array, const MKL_INT *ldc_array,
                 const MKL_INT *group_count, const MKL_INT *group_size) NOTHROW;

#pragma omp declare variant (MKL_BLAS_VARIANT_NAME(zsyrk_batch)) match(construct={dispatch}, device={arch(gen)}) \
    append_args(interop(prefer_type("sycl","level_zero"),targetsync)) \
    adjust_args(need_device_ptr:a_array,c_array)
void zsyrk_batch(const char *uplo_array, const char *trans_array,
                 const MKL_INT *n_array, const MKL_INT *k_array,
                 const MKL_Complex16 *alpha_array, const MKL_Complex16 **a_array, const MKL_INT *lda_array,
                 const MKL_Complex16 *beta_array, MKL_Complex16 **c_array, const MKL_INT *ldc_array,
                 const MKL_INT *group_count, const MKL_INT *group_size) NOTHROW;

#pragma omp declare variant (MKL_BLAS_VARIANT_NAME(ssyrk_batch_strided)) match(construct={dispatch}, device={arch(gen)}) \
    append_args(interop(prefer_type("sycl","level_zero"),targetsync)) \
    adjust_args(need_device_ptr:A,C)
void ssyrk_batch_strided(const char *Uplo,
                         const char *Trans, const MKL_INT *N,
                         const MKL_INT *K, const float *alpha, const float *A,
                         const MKL_INT *lda, const MKL_INT *stridea,
                         const float *beta, float *C, const MKL_INT *ldc, const MKL_INT *stridec,
                         const MKL_INT *batch_size) NOTHROW;

#pragma omp declare variant (MKL_BLAS_VARIANT_NAME(dsyrk_batch_strided)) match(construct={dispatch}, device={arch(gen)}) \
    append_args(interop(prefer_type("sycl","level_zero"),targetsync)) \
    adjust_args(need_device_ptr:A,C)
void dsyrk_batch_strided(const char *Uplo,
                         const char *Trans, const MKL_INT *N,
                         const MKL_INT *K, const double *alpha, const double *A,
                         const MKL_INT *lda, const MKL_INT *stridea,
                         const double *beta, double *C, const MKL_INT *ldc, const MKL_INT *stridec,
                         const MKL_INT *batch_size) NOTHROW;

#pragma omp declare variant (MKL_BLAS_VARIANT_NAME(csyrk_batch_strided)) match(construct={dispatch}, device={arch(gen)}) \
    append_args(interop(prefer_type("sycl","level_zero"),targetsync)) \
    adjust_args(need_device_ptr:A,C)
void csyrk_batch_strided(const char *Uplo,
                         const char *Trans, const MKL_INT *N,
                         const MKL_INT *K, const MKL_Complex8 *alpha, const MKL_Complex8 *A,
                         const MKL_INT *lda, const MKL_INT *stridea,
                         const MKL_Complex8 *beta, MKL_Complex8 *C, const MKL_INT *ldc, const MKL_INT *stridec,
                         const MKL_INT *batch_size) NOTHROW;

#pragma omp declare variant (MKL_BLAS_VARIANT_NAME(zsyrk_batch_strided)) match(construct={dispatch}, device={arch(gen)}) \
    append_args(interop(prefer_type("sycl","level_zero"),targetsync)) \
    adjust_args(need_device_ptr:A,C)
void zsyrk_batch_strided(const char *Uplo,
                         const char *Trans, const MKL_INT *N,
                         const MKL_INT *K, const MKL_Complex16 *alpha, const MKL_Complex16 *A,
                         const MKL_INT *lda, const MKL_INT *stridea,
                         const MKL_Complex16 *beta, MKL_Complex16 *C, const MKL_INT *ldc, const MKL_INT *stridec,
                         const MKL_INT *batch_size) NOTHROW;

#pragma omp declare variant (MKL_CBLAS_VARIANT_NAME(strsm_batch)) match(construct={dispatch}, device={arch(gen)}) \
    append_args(interop(prefer_type("sycl","level_zero"),targetsync)) \
    adjust_args(need_device_ptr:A_Array,B_Array)
void cblas_strsm_batch(const CBLAS_LAYOUT Layout, const CBLAS_SIDE *Side_Array,
                           const CBLAS_UPLO *Uplo_Array, const CBLAS_TRANSPOSE *TransA_Array,
                           const CBLAS_DIAG *Diag_Array, const MKL_INT *M_Array,
                           const MKL_INT *N_Array, const float *alpha_Array,
                           const float **A_Array, const MKL_INT *lda_Array,
                           float **B_Array, const MKL_INT *ldb_Array,
                           const MKL_INT group_count, const MKL_INT *group_size) NOTHROW;

#pragma omp declare variant (MKL_CBLAS_VARIANT_NAME(dtrsm_batch)) match(construct={dispatch}, device={arch(gen)}) \
    append_args(interop(prefer_type("sycl","level_zero"),targetsync)) \
    adjust_args(need_device_ptr:A_Array,B_Array)
void cblas_dtrsm_batch(const CBLAS_LAYOUT Layout, const CBLAS_SIDE *Side_Array,
                           const CBLAS_UPLO *Uplo_Array, const CBLAS_TRANSPOSE *Transa_Array,
                           const CBLAS_DIAG *Diag_Array, const MKL_INT *M_Array,
                           const MKL_INT *N_Array, const double *alpha_Array,
                           const double **A_Array, const MKL_INT *lda_Array,
                           double **B_Array, const MKL_INT *ldb_Array,
                           const MKL_INT group_count, const MKL_INT *group_size) NOTHROW;

#pragma omp declare variant (MKL_CBLAS_VARIANT_NAME(ctrsm_batch)) match(construct={dispatch}, device={arch(gen)}) \
    append_args(interop(prefer_type("sycl","level_zero"),targetsync)) \
    adjust_args(need_device_ptr:A_Array,B_Array)
void cblas_ctrsm_batch(const CBLAS_LAYOUT Layout, const CBLAS_SIDE *Side_Array,
                           const CBLAS_UPLO *Uplo_Array, const CBLAS_TRANSPOSE *Transa_Array,
                           const CBLAS_DIAG *Diag_Array, const MKL_INT *M_Array,
                           const MKL_INT *N_Array, const void *alpha_Array,
                           const void **A_Array, const MKL_INT *lda_Array,
                           void **B_Array, const MKL_INT *ldb_Array,
                           const MKL_INT group_count, const MKL_INT *group_size) NOTHROW;

#pragma omp declare variant (MKL_CBLAS_VARIANT_NAME(ztrsm_batch)) match(construct={dispatch}, device={arch(gen)}) \
    append_args(interop(prefer_type("sycl","level_zero"),targetsync)) \
    adjust_args(need_device_ptr:A_Array,B_Array)
void cblas_ztrsm_batch(const CBLAS_LAYOUT Layout, const CBLAS_SIDE *Side_Array,
                           const CBLAS_UPLO *Uplo_Array, const CBLAS_TRANSPOSE *Transa_Array,
                           const CBLAS_DIAG *Diag_Array, const MKL_INT *M_Array,
                           const MKL_INT *N_Array, const void *alpha_Array,
                           const void **A_Array, const MKL_INT *lda_Array,
                           void **B_Array, const MKL_INT *ldb_Array,
                           const MKL_INT group_count, const MKL_INT *group_size) NOTHROW;

#pragma omp declare variant (MKL_CBLAS_VARIANT_NAME(strsm_batch_strided)) match(construct={dispatch}, device={arch(gen)}) \
    append_args(interop(prefer_type("sycl","level_zero"),targetsync)) \
    adjust_args(need_device_ptr:A,B)
void cblas_strsm_batch_strided(const CBLAS_LAYOUT Layout, const CBLAS_SIDE Side,
                                   const CBLAS_UPLO Uplo, const CBLAS_TRANSPOSE TransA,
                                   const CBLAS_DIAG Diag, const MKL_INT M,
                                   const MKL_INT N, const float alpha,
                                   const float *A, const MKL_INT lda, const MKL_INT stridea,
                                   float *B, const MKL_INT ldb, const MKL_INT strideb,
                                   const MKL_INT batch_size) NOTHROW;

#pragma omp declare variant (MKL_CBLAS_VARIANT_NAME(dtrsm_batch_strided)) match(construct={dispatch}, device={arch(gen)}) \
    append_args(interop(prefer_type("sycl","level_zero"),targetsync)) \
    adjust_args(need_device_ptr:A,B)
void cblas_dtrsm_batch_strided(const CBLAS_LAYOUT Layout, const CBLAS_SIDE Side,
                                   const CBLAS_UPLO Uplo, const CBLAS_TRANSPOSE TransA,
                                   const CBLAS_DIAG Diag, const MKL_INT M,
                                   const MKL_INT N, const double alpha,
                                   const double *A, const MKL_INT lda, const MKL_INT stridea,
                                   double *B, const MKL_INT ldb, const MKL_INT strideb,
                                   const MKL_INT batch_size) NOTHROW;

#pragma omp declare variant (MKL_CBLAS_VARIANT_NAME(ctrsm_batch_strided)) match(construct={dispatch}, device={arch(gen)}) \
    append_args(interop(prefer_type("sycl","level_zero"),targetsync)) \
    adjust_args(need_device_ptr:A,B)
void cblas_ctrsm_batch_strided(const CBLAS_LAYOUT Layout, const CBLAS_SIDE Side,
                                   const CBLAS_UPLO Uplo, const CBLAS_TRANSPOSE TransA,
                                   const CBLAS_DIAG Diag, const MKL_INT M,
                                   const MKL_INT N, const void *alpha,
                                   const void *A, const MKL_INT lda, const MKL_INT stridea,
                                   void *B, const MKL_INT ldb, const MKL_INT strideb,
                                   const MKL_INT batch_size) NOTHROW;

#pragma omp declare variant (MKL_CBLAS_VARIANT_NAME(ztrsm_batch_strided)) match(construct={dispatch}, device={arch(gen)}) \
    append_args(interop(prefer_type("sycl","level_zero"),targetsync)) \
    adjust_args(need_device_ptr:A,B)
void cblas_ztrsm_batch_strided(const CBLAS_LAYOUT Layout, const CBLAS_SIDE Side,
                                   const CBLAS_UPLO Uplo, const CBLAS_TRANSPOSE TransA,
                                   const CBLAS_DIAG Diag, const MKL_INT M,
                                   const MKL_INT N, const void *alpha,
                                   const void *A, const MKL_INT lda, const MKL_INT stridea,
                                   void *B, const MKL_INT ldb, const MKL_INT strideb,
                                   const MKL_INT batch_size) NOTHROW;

#pragma omp declare variant (MKL_BLAS_VARIANT_NAME(strsm_batch)) match(construct={dispatch}, device={arch(gen)}) \
    append_args(interop(prefer_type("sycl","level_zero"),targetsync)) \
    adjust_args(need_device_ptr:a_array,b_array)
void strsm_batch(const char *side_array, const char *uplo_array, const char *transa_array, const char *diag_array,
                     const MKL_INT *m_array, const MKL_INT *n_array, const float *alpha_array, const float **a_array,
                     const MKL_INT *lda_array, float **b_array, const MKL_INT *ldb_array, const MKL_INT *group_count, const MKL_INT *group_size) NOTHROW;

#pragma omp declare variant (MKL_BLAS_VARIANT_NAME(dtrsm_batch)) match(construct={dispatch}, device={arch(gen)}) \
    append_args(interop(prefer_type("sycl","level_zero"),targetsync)) \
    adjust_args(need_device_ptr:a_array,b_array)
void dtrsm_batch(const char *side_array, const char *uplo_array, const char *transa_array, const char *diag_array,
                     const MKL_INT *m_array, const MKL_INT *n_array, const double *alpha_array, const double **a_array,
                     const MKL_INT *lda_array, double **b_array, const MKL_INT *ldb_array, const MKL_INT *group_count, const MKL_INT *group_size) NOTHROW;

#pragma omp declare variant (MKL_BLAS_VARIANT_NAME(ctrsm_batch)) match(construct={dispatch}, device={arch(gen)}) \
    append_args(interop(prefer_type("sycl","level_zero"),targetsync)) \
    adjust_args(need_device_ptr:a_array,b_array)
void ctrsm_batch(const char *side_array, const char *uplo_array, const char *transa_array, const char *diag_array,
                     const MKL_INT *m_array, const MKL_INT *n_array, const MKL_Complex8 *alpha_array, const MKL_Complex8 **a_array,
                     const MKL_INT *lda_array, MKL_Complex8 **b_array, const MKL_INT *ldb_array, const MKL_INT *group_count, const MKL_INT *group_size) NOTHROW;

#pragma omp declare variant (MKL_BLAS_VARIANT_NAME(ztrsm_batch)) match(construct={dispatch}, device={arch(gen)}) \
    append_args(interop(prefer_type("sycl","level_zero"),targetsync)) \
    adjust_args(need_device_ptr:a_array,b_array)
void ztrsm_batch(const char *side_array, const char *uplo_array, const char *transa_array, const char *diag_array,
                     const MKL_INT *m_array, const MKL_INT *n_array, const MKL_Complex16 *alpha_array, const MKL_Complex16 **a_array,
                     const MKL_INT *lda_array, MKL_Complex16 **b_array, const MKL_INT *ldb_array, const MKL_INT *group_count, const MKL_INT *group_size) NOTHROW;

#pragma omp declare variant (MKL_BLAS_VARIANT_NAME(strsm_batch_strided)) match(construct={dispatch}, device={arch(gen)}) \
    append_args(interop(prefer_type("sycl","level_zero"),targetsync)) \
    adjust_args(need_device_ptr:a,b)
void strsm_batch_strided(const char *side, const char *uplo, const char *transa, const char *diag,
                             const MKL_INT *m, const MKL_INT *n, const float *alpha, const float *a,
                             const MKL_INT *lda, const MKL_INT *stridea, float *b, const MKL_INT *ldb, const MKL_INT *strideb, const MKL_INT *batch_size) NOTHROW;

#pragma omp declare variant (MKL_BLAS_VARIANT_NAME(dtrsm_batch_strided)) match(construct={dispatch}, device={arch(gen)}) \
    append_args(interop(prefer_type("sycl","level_zero"),targetsync)) \
    adjust_args(need_device_ptr:a,b)
void dtrsm_batch_strided(const char *side, const char *uplo, const char *transa, const char *diag,
                             const MKL_INT *m, const MKL_INT *n, const double *alpha, const double *a,
                             const MKL_INT *lda, const MKL_INT *stridea, double *b, const MKL_INT *ldb, const MKL_INT *strideb, const MKL_INT *batch_size) NOTHROW;

#pragma omp declare variant (MKL_BLAS_VARIANT_NAME(ctrsm_batch_strided)) match(construct={dispatch}, device={arch(gen)}) \
    append_args(interop(prefer_type("sycl","level_zero"),targetsync)) \
    adjust_args(need_device_ptr:a,b)
void ctrsm_batch_strided(const char *side, const char *uplo, const char *transa, const char *diag,
                             const MKL_INT *m, const MKL_INT *n, const MKL_Complex8 *alpha, const MKL_Complex8 *a,
                             const MKL_INT *lda, const MKL_INT *stridea, MKL_Complex8 *b, const MKL_INT *ldb, const MKL_INT *strideb, const MKL_INT *batch_size) NOTHROW;

#pragma omp declare variant (MKL_BLAS_VARIANT_NAME(ztrsm_batch_strided)) match(construct={dispatch}, device={arch(gen)}) \
    append_args(interop(prefer_type("sycl","level_zero"),targetsync)) \
    adjust_args(need_device_ptr:a,b)
void ztrsm_batch_strided(const char *side, const char *uplo, const char *transa, const char *diag,
                             const MKL_INT *m, const MKL_INT *n, const MKL_Complex16 *alpha, const MKL_Complex16 *a,
                             const MKL_INT *lda, const MKL_INT *stridea, MKL_Complex16 *b, const MKL_INT *ldb, const MKL_INT *strideb, const MKL_INT *batch_size) NOTHROW;

// Level2

#pragma omp declare variant (MKL_BLAS_VARIANT_NAME(sgemv_batch)) match(construct={dispatch}, device={arch(gen)}) \
    append_args(interop(prefer_type("sycl","level_zero"),targetsync)) \
    adjust_args(need_device_ptr:a,x,y)
void sgemv_batch(const char *trans, const MKL_INT *m, const MKL_INT *n, const float *alpha,
                 const float **a, const MKL_INT *lda, const float **x, const MKL_INT *incx,
                 const float *beta, float **y, const MKL_INT *incy,
                 const MKL_INT *group_count, const MKL_INT *group_size) NOTHROW;

#pragma omp declare variant (MKL_BLAS_VARIANT_NAME(sgemv_batch_strided)) match(construct={dispatch}, device={arch(gen)}) \
    append_args(interop(prefer_type("sycl","level_zero"),targetsync)) \
    adjust_args(need_device_ptr:a,x,y)
void sgemv_batch_strided(const char *trans, const MKL_INT *m, const MKL_INT *n, const float *alpha,
                         const float *a, const MKL_INT *lda, const MKL_INT *stridea,
                         const float *x, const MKL_INT *incx, const MKL_INT *stridex,
                         const float *beta, float *y, const MKL_INT *incy, const MKL_INT *stridey,
                         const MKL_INT *batch_size) NOTHROW;

#pragma omp declare variant (MKL_BLAS_VARIANT_NAME(dgemv_batch)) match(construct={dispatch}, device={arch(gen)}) \
    append_args(interop(prefer_type("sycl","level_zero"),targetsync)) \
    adjust_args(need_device_ptr:a,x,y)
void dgemv_batch(const char *trans, const MKL_INT *m, const MKL_INT *n, const double *alpha,
                 const double **a, const MKL_INT *lda, const double **x, const MKL_INT *incx,
                 const double *beta, double **y, const MKL_INT *incy,
                 const MKL_INT *group_count, const MKL_INT *group_size) NOTHROW;

#pragma omp declare variant (MKL_BLAS_VARIANT_NAME(dgemv_batch_strided)) match(construct={dispatch}, device={arch(gen)}) \
    append_args(interop(prefer_type("sycl","level_zero"),targetsync)) \
    adjust_args(need_device_ptr:a,x,y)
void dgemv_batch_strided(const char *trans, const MKL_INT *m, const MKL_INT *n, const double *alpha,
                         const double *a, const MKL_INT *lda, const MKL_INT *stridea,
                         const double *x, const MKL_INT *incx, const MKL_INT *stridex,
                         const double *beta, double *y, const MKL_INT *incy, const MKL_INT *stridey,
                         const MKL_INT *batch_size) NOTHROW;

#pragma omp declare variant (MKL_BLAS_VARIANT_NAME(cgemv_batch)) match(construct={dispatch}, device={arch(gen)}) \
    append_args(interop(prefer_type("sycl","level_zero"),targetsync)) \
    adjust_args(need_device_ptr:a,x,y)
void cgemv_batch(const char *trans, const MKL_INT *m, const MKL_INT *n, const MKL_Complex8 *alpha,
                 const MKL_Complex8 **a, const MKL_INT *lda, const MKL_Complex8 **x, const MKL_INT *incx,
                 const MKL_Complex8 *beta, MKL_Complex8 **y, const MKL_INT *incy,
                 const MKL_INT *group_count, const MKL_INT *group_size) NOTHROW;

#pragma omp declare variant (MKL_BLAS_VARIANT_NAME(cgemv_batch_strided)) match(construct={dispatch}, device={arch(gen)}) \
    append_args(interop(prefer_type("sycl","level_zero"),targetsync)) \
    adjust_args(need_device_ptr:a,x,y)
void cgemv_batch_strided(const char *trans, const MKL_INT *m, const MKL_INT *n, const MKL_Complex8 *alpha,
                         const MKL_Complex8 *a, const MKL_INT *lda, const MKL_INT *stridea,
                         const MKL_Complex8 *x, const MKL_INT *incx, const MKL_INT *stridex,
                         const MKL_Complex8 *beta, MKL_Complex8 *y, const MKL_INT *incy, const MKL_INT *stridey,
                         const MKL_INT *batch_size) NOTHROW;

#pragma omp declare variant (MKL_BLAS_VARIANT_NAME(zgemv_batch)) match(construct={dispatch}, device={arch(gen)}) \
    append_args(interop(prefer_type("sycl","level_zero"),targetsync)) \
    adjust_args(need_device_ptr:a,x,y)
void zgemv_batch(const char *trans, const MKL_INT *m, const MKL_INT *n, const MKL_Complex16 *alpha,
                 const MKL_Complex16 **a, const MKL_INT *lda, const MKL_Complex16 **x, const MKL_INT *incx,
                 const MKL_Complex16 *beta, MKL_Complex16 **y, const MKL_INT *incy,
                 const MKL_INT *group_count, const MKL_INT *group_size) NOTHROW;

#pragma omp declare variant (MKL_BLAS_VARIANT_NAME(zgemv_batch_strided)) match(construct={dispatch}, device={arch(gen)}) \
    append_args(interop(prefer_type("sycl","level_zero"),targetsync)) \
    adjust_args(need_device_ptr:a,x,y)
void zgemv_batch_strided(const char *trans, const MKL_INT *m, const MKL_INT *n, const MKL_Complex16 *alpha,
                         const MKL_Complex16 *a, const MKL_INT *lda, const MKL_INT *stridea,
                         const MKL_Complex16 *x, const MKL_INT *incx, const MKL_INT *stridex,
                         const MKL_Complex16 *beta, MKL_Complex16 *y, const MKL_INT *incy, const MKL_INT *stridey,
                         const MKL_INT *batch_size) NOTHROW;

#pragma omp declare variant (MKL_CBLAS_VARIANT_NAME(sgemv_batch)) match(construct={dispatch}, device={arch(gen)}) \
    append_args(interop(prefer_type("sycl","level_zero"),targetsync)) \
    adjust_args(need_device_ptr:A,X,Y)
void cblas_sgemv_batch(const CBLAS_LAYOUT Layout,
                       const CBLAS_TRANSPOSE *TransA, const MKL_INT *M, const MKL_INT *N,
                       const float *alpha, const float **A, const MKL_INT *lda,
                       const float **X, const MKL_INT *incX, const float *beta,
                       float **Y, const MKL_INT *incY,
                       const MKL_INT group_count, const MKL_INT *group_size) NOTHROW;

#pragma omp declare variant (MKL_CBLAS_VARIANT_NAME(sgemv_batch_strided)) match(construct={dispatch}, device={arch(gen)}) \
    append_args(interop(prefer_type("sycl","level_zero"),targetsync)) \
    adjust_args(need_device_ptr:A,X,Y)
void cblas_sgemv_batch_strided(const CBLAS_LAYOUT Layout,
                               const CBLAS_TRANSPOSE TransA, const MKL_INT M, const MKL_INT N,
                               const float alpha, const float *A, const MKL_INT lda, const MKL_INT stridea,
                               const float *X, const MKL_INT incX, const MKL_INT stridex, const float beta,
                               float *Y, const MKL_INT incY, const MKL_INT stridey,
                               const MKL_INT batch_size) NOTHROW;

#pragma omp declare variant (MKL_CBLAS_VARIANT_NAME(dgemv_batch)) match(construct={dispatch}, device={arch(gen)}) \
    append_args(interop(prefer_type("sycl","level_zero"),targetsync)) \
    adjust_args(need_device_ptr:A,X,Y)
void cblas_dgemv_batch(const CBLAS_LAYOUT Layout,
                       const CBLAS_TRANSPOSE *TransA, const MKL_INT *M, const MKL_INT *N,
                       const double *alpha, const double **A, const MKL_INT *lda,
                       const double **X, const MKL_INT *incX, const double *beta,
                       double **Y, const MKL_INT *incY,
                       const MKL_INT group_count, const MKL_INT *group_size) NOTHROW;

#pragma omp declare variant (MKL_CBLAS_VARIANT_NAME(dgemv_batch_strided)) match(construct={dispatch}, device={arch(gen)}) \
    append_args(interop(prefer_type("sycl","level_zero"),targetsync)) \
    adjust_args(need_device_ptr:A,X,Y)
void cblas_dgemv_batch_strided(const CBLAS_LAYOUT Layout,
                               const CBLAS_TRANSPOSE TransA, const MKL_INT M, const MKL_INT N,
                               const double alpha, const double *A, const MKL_INT lda, const MKL_INT stridea,
                               const double *X, const MKL_INT incX, const MKL_INT stridex, const double beta,
                               double *Y, const MKL_INT incY, const MKL_INT stridey,
                               const MKL_INT batch_size) NOTHROW;

#pragma omp declare variant (MKL_CBLAS_VARIANT_NAME(cgemv_batch)) match(construct={dispatch}, device={arch(gen)}) \
    append_args(interop(prefer_type("sycl","level_zero"),targetsync)) \
    adjust_args(need_device_ptr:A,X,Y)
void cblas_cgemv_batch(const CBLAS_LAYOUT Layout,
                       const CBLAS_TRANSPOSE *TransA, const MKL_INT *M, const MKL_INT *N,
                       const void *alpha, const void **A, const MKL_INT *lda,
                       const void **X, const MKL_INT *incX, const void *beta,
                       void **Y, const MKL_INT *incY,
                       const MKL_INT group_count, const MKL_INT *group_size) NOTHROW;

#pragma omp declare variant (MKL_CBLAS_VARIANT_NAME(cgemv_batch_strided)) match(construct={dispatch}, device={arch(gen)}) \
    append_args(interop(prefer_type("sycl","level_zero"),targetsync)) \
    adjust_args(need_device_ptr:A,X,Y)
void cblas_cgemv_batch_strided(const CBLAS_LAYOUT Layout,
                               const CBLAS_TRANSPOSE TransA, const MKL_INT M, const MKL_INT N,
                               const void *alpha, const void *A, const MKL_INT lda, const MKL_INT stridea,
                               const void *X, const MKL_INT incX, const MKL_INT stridex, const void *beta,
                               void *Y, const MKL_INT incY, const MKL_INT stridey,
                               const MKL_INT batch_size) NOTHROW;

#pragma omp declare variant (MKL_CBLAS_VARIANT_NAME(zgemv_batch)) match(construct={dispatch}, device={arch(gen)}) \
    append_args(interop(prefer_type("sycl","level_zero"),targetsync)) \
    adjust_args(need_device_ptr:A,X,Y)
void cblas_zgemv_batch(const CBLAS_LAYOUT Layout,
                       const CBLAS_TRANSPOSE *TransA, const MKL_INT *M, const MKL_INT *N,
                       const void *alpha, const void **A, const MKL_INT *lda,
                       const void **X, const MKL_INT *incX, const void *beta,
                       void **Y, const MKL_INT *incY,
                       const MKL_INT group_count, const MKL_INT *group_size) NOTHROW;

#pragma omp declare variant (MKL_CBLAS_VARIANT_NAME(zgemv_batch_strided)) match(construct={dispatch}, device={arch(gen)}) \
    append_args(interop(prefer_type("sycl","level_zero"),targetsync)) \
    adjust_args(need_device_ptr:A,X,Y)
void cblas_zgemv_batch_strided(const CBLAS_LAYOUT Layout,
                               const CBLAS_TRANSPOSE TransA, const MKL_INT M, const MKL_INT N,
                               const void *alpha, const void *A, const MKL_INT lda, const MKL_INT stridea,
                               const void *X, const MKL_INT incX, const MKL_INT stridex, const void *beta,
                               void *Y, const MKL_INT incY, const MKL_INT stridey,
                               const MKL_INT batch_size) NOTHROW;

#pragma omp declare variant (MKL_BLAS_VARIANT_NAME(sdgmm_batch)) match(construct={dispatch}, device={arch(gen)}) \
    append_args(interop(prefer_type("sycl","level_zero"),targetsync)) \
    adjust_args(need_device_ptr:a,x,c)
void sdgmm_batch(const char *side, const MKL_INT *m, const MKL_INT *n,
                 const float **a, const MKL_INT *lda,
                 const float **x, const MKL_INT *incx,
                 float **c, const MKL_INT *ldc,
                 const MKL_INT *group_count, const MKL_INT *group_size) NOTHROW;

#pragma omp declare variant (MKL_BLAS_VARIANT_NAME(sdgmm_batch_strided)) match(construct={dispatch}, device={arch(gen)}) \
    append_args(interop(prefer_type("sycl","level_zero"),targetsync)) \
    adjust_args(need_device_ptr:a,x,c)
void sdgmm_batch_strided(const char *side, const MKL_INT *m, const MKL_INT *n,
                         const float *a, const MKL_INT *lda, const MKL_INT *stridea,
                         const float *x, const MKL_INT *incx, const MKL_INT *stridex,
                         float *c, const MKL_INT *ldc, const MKL_INT *stridec,
                         const MKL_INT *batch_size) NOTHROW;

#pragma omp declare variant (MKL_BLAS_VARIANT_NAME(ddgmm_batch)) match(construct={dispatch}, device={arch(gen)}) \
    append_args(interop(prefer_type("sycl","level_zero"),targetsync)) \
    adjust_args(need_device_ptr:a,x,c)
void ddgmm_batch(const char *side, const MKL_INT *m, const MKL_INT *n,
                 const double **a, const MKL_INT *lda,
                 const double **x, const MKL_INT *incx,
                 double **c, const MKL_INT *ldc,
                 const MKL_INT *group_count, const MKL_INT *group_size) NOTHROW;

#pragma omp declare variant (MKL_BLAS_VARIANT_NAME(ddgmm_batch_strided)) match(construct={dispatch}, device={arch(gen)}) \
    append_args(interop(prefer_type("sycl","level_zero"),targetsync)) \
    adjust_args(need_device_ptr:a,x,c)
void ddgmm_batch_strided(const char *side, const MKL_INT *m, const MKL_INT *n,
                         const double *a, const MKL_INT *lda, const MKL_INT *stridea,
                         const double *x, const MKL_INT *incx, const MKL_INT *stridex,
                         double *c, const MKL_INT *ldc, const MKL_INT *stridec,
                         const MKL_INT *batch_size) NOTHROW;

#pragma omp declare variant (MKL_BLAS_VARIANT_NAME(cdgmm_batch)) match(construct={dispatch}, device={arch(gen)}) \
    append_args(interop(prefer_type("sycl","level_zero"),targetsync)) \
    adjust_args(need_device_ptr:a,x,c)
void cdgmm_batch(const char *side, const MKL_INT *m, const MKL_INT *n,
                 const MKL_Complex8 **a, const MKL_INT *lda,
                 const MKL_Complex8 **x, const MKL_INT *incx,
                 MKL_Complex8 **c, const MKL_INT *ldc,
                 const MKL_INT *group_count, const MKL_INT *group_size) NOTHROW;

#pragma omp declare variant (MKL_BLAS_VARIANT_NAME(cdgmm_batch_strided)) match(construct={dispatch}, device={arch(gen)}) \
    append_args(interop(prefer_type("sycl","level_zero"),targetsync)) \
    adjust_args(need_device_ptr:a,x,c)
void cdgmm_batch_strided(const char *side, const MKL_INT *m, const MKL_INT *n,
                         const MKL_Complex8 *a, const MKL_INT *lda, const MKL_INT *stridea,
                         const MKL_Complex8 *x, const MKL_INT *incx, const MKL_INT *stridex,
                         MKL_Complex8 *c, const MKL_INT *ldc, const MKL_INT *stridec,
                         const MKL_INT *batch_size) NOTHROW;

#pragma omp declare variant (MKL_BLAS_VARIANT_NAME(zdgmm_batch)) match(construct={dispatch}, device={arch(gen)}) \
    append_args(interop(prefer_type("sycl","level_zero"),targetsync)) \
    adjust_args(need_device_ptr:a,x,c)
void zdgmm_batch(const char *side, const MKL_INT *m, const MKL_INT *n,
                 const MKL_Complex16 **a, const MKL_INT *lda,
                 const MKL_Complex16 **x, const MKL_INT *incx,
                 MKL_Complex16 **c, const MKL_INT *ldc,
                 const MKL_INT *group_count, const MKL_INT *group_size) NOTHROW;

#pragma omp declare variant (MKL_BLAS_VARIANT_NAME(zdgmm_batch_strided)) match(construct={dispatch}, device={arch(gen)}) \
    append_args(interop(prefer_type("sycl","level_zero"),targetsync)) \
    adjust_args(need_device_ptr:a,x,c)
void zdgmm_batch_strided(const char *side, const MKL_INT *m, const MKL_INT *n,
                         const MKL_Complex16 *a, const MKL_INT *lda, const MKL_INT *stridea,
                         const MKL_Complex16 *x, const MKL_INT *incx, const MKL_INT *stridex,
                         MKL_Complex16 *c, const MKL_INT *ldc, const MKL_INT *stridec,
                         const MKL_INT *batch_size) NOTHROW;

#pragma omp declare variant (MKL_CBLAS_VARIANT_NAME(sdgmm_batch)) match(construct={dispatch}, device={arch(gen)}) \
    append_args(interop(prefer_type("sycl","level_zero"),targetsync)) \
    adjust_args(need_device_ptr:a,x,c)
void cblas_sdgmm_batch(const CBLAS_LAYOUT layout,
                       const CBLAS_SIDE *side, const MKL_INT *m, const MKL_INT *n,
                       const float **a, const MKL_INT *lda,
                       const float **x, const MKL_INT *incx,
                       float **c, const MKL_INT *ldc,
                       const MKL_INT group_count, const MKL_INT *group_size) NOTHROW;

#pragma omp declare variant (MKL_CBLAS_VARIANT_NAME(sdgmm_batch_strided)) match(construct={dispatch}, device={arch(gen)}) \
    append_args(interop(prefer_type("sycl","level_zero"),targetsync)) \
    adjust_args(need_device_ptr:a,x,c)
void cblas_sdgmm_batch_strided(const CBLAS_LAYOUT layout,
                               const CBLAS_SIDE side, const MKL_INT m, const MKL_INT n,
                               const float *a, const MKL_INT lda, const MKL_INT stridea,
                               const float *x, const MKL_INT incx, const MKL_INT stridex,
                               float *c, const MKL_INT ldc, const MKL_INT stridec,
                               const MKL_INT batch_size) NOTHROW;

#pragma omp declare variant (MKL_CBLAS_VARIANT_NAME(ddgmm_batch)) match(construct={dispatch}, device={arch(gen)}) \
    append_args(interop(prefer_type("sycl","level_zero"),targetsync)) \
    adjust_args(need_device_ptr:a,x,c)
void cblas_ddgmm_batch(const CBLAS_LAYOUT layout,
                       const CBLAS_SIDE *side, const MKL_INT *m, const MKL_INT *n,
                       const double **a, const MKL_INT *lda,
                       const double **x, const MKL_INT *incx,
                       double **c, const MKL_INT *ldc,
                       const MKL_INT group_count, const MKL_INT *group_size) NOTHROW;

#pragma omp declare variant (MKL_CBLAS_VARIANT_NAME(ddgmm_batch_strided)) match(construct={dispatch}, device={arch(gen)}) \
    append_args(interop(prefer_type("sycl","level_zero"),targetsync)) \
    adjust_args(need_device_ptr:a,x,c)
void cblas_ddgmm_batch_strided(const CBLAS_LAYOUT layout,
                               const CBLAS_SIDE side, const MKL_INT m, const MKL_INT n,
                               const double *a, const MKL_INT lda, const MKL_INT stridea,
                               const double *x, const MKL_INT incx, const MKL_INT stridex,
                               double *c, const MKL_INT ldc, const MKL_INT stridec,
                               const MKL_INT batch_size) NOTHROW;

#pragma omp declare variant (MKL_CBLAS_VARIANT_NAME(cdgmm_batch)) match(construct={dispatch}, device={arch(gen)}) \
    append_args(interop(prefer_type("sycl","level_zero"),targetsync)) \
    adjust_args(need_device_ptr:a,x,c)
void cblas_cdgmm_batch(const CBLAS_LAYOUT layout,
                       const CBLAS_SIDE *side, const MKL_INT *m, const MKL_INT *n,
                       const void **a, const MKL_INT *lda,
                       const void **x, const MKL_INT *incx,
                       void **c, const MKL_INT *ldc,
                       const MKL_INT group_count, const MKL_INT *group_size) NOTHROW;

#pragma omp declare variant (MKL_CBLAS_VARIANT_NAME(cdgmm_batch_strided)) match(construct={dispatch}, device={arch(gen)}) \
    append_args(interop(prefer_type("sycl","level_zero"),targetsync)) \
    adjust_args(need_device_ptr:a,x,c)
void cblas_cdgmm_batch_strided(const CBLAS_LAYOUT layout,
                               const CBLAS_SIDE side, const MKL_INT m, const MKL_INT n,
                               const void *a, const MKL_INT lda, const MKL_INT stridea,
                               const void *x, const MKL_INT incx, const MKL_INT stridex,
                               void *c, const MKL_INT ldc, const MKL_INT stridec,
                               const MKL_INT batch_size) NOTHROW;

#pragma omp declare variant (MKL_CBLAS_VARIANT_NAME(zdgmm_batch)) match(construct={dispatch}, device={arch(gen)}) \
    append_args(interop(prefer_type("sycl","level_zero"),targetsync)) \
    adjust_args(need_device_ptr:a,x,c)
void cblas_zdgmm_batch(const CBLAS_LAYOUT layout,
                       const CBLAS_SIDE *side, const MKL_INT *m, const MKL_INT *n,
                       const void **a, const MKL_INT *lda,
                       const void **x, const MKL_INT *incx,
                       void **c, const MKL_INT *ldc,
                       const MKL_INT group_count, const MKL_INT *group_size) NOTHROW;

#pragma omp declare variant (MKL_CBLAS_VARIANT_NAME(zdgmm_batch_strided)) match(construct={dispatch}, device={arch(gen)}) \
    append_args(interop(prefer_type("sycl","level_zero"),targetsync)) \
    adjust_args(need_device_ptr:a,x,c)
void cblas_zdgmm_batch_strided(const CBLAS_LAYOUT layout,
                               const CBLAS_SIDE side, const MKL_INT m, const MKL_INT n,
                               const void *a, const MKL_INT lda, const MKL_INT stridea,
                               const void *x, const MKL_INT incx, const MKL_INT stridex,
                               void *c, const MKL_INT ldc, const MKL_INT stridec,
                               const MKL_INT batch_size) NOTHROW;

// Level 1

#pragma omp declare variant (MKL_CBLAS_VARIANT_NAME(saxpy_batch)) match(construct={dispatch}, device={arch(gen)}) \
    append_args(interop(prefer_type("sycl","level_zero"),targetsync)) \
    adjust_args(need_device_ptr:x,y)
void cblas_saxpy_batch(const MKL_INT *n, const float *alpha,
                       const float **x, const MKL_INT *incx,
                       float **y, const MKL_INT *incy,
                       const MKL_INT group_count, const MKL_INT *group_size) NOTHROW;

#pragma omp declare variant (MKL_CBLAS_VARIANT_NAME(daxpy_batch)) match(construct={dispatch}, device={arch(gen)}) \
    append_args(interop(prefer_type("sycl","level_zero"),targetsync)) \
    adjust_args(need_device_ptr:x,y)
void cblas_daxpy_batch(const MKL_INT *n, const double *alpha,
                       const double **x, const MKL_INT *incx,
                       double **y, const MKL_INT *incy,
                       const MKL_INT group_count, const MKL_INT *group_size) NOTHROW;

#pragma omp declare variant (MKL_CBLAS_VARIANT_NAME(caxpy_batch)) match(construct={dispatch}, device={arch(gen)}) \
    append_args(interop(prefer_type("sycl","level_zero"),targetsync)) \
    adjust_args(need_device_ptr:x,y)
void cblas_caxpy_batch(const MKL_INT *n, const void *alpha,
                       const void **x, const MKL_INT *incx,
                       void **y, const MKL_INT *incy,
                       const MKL_INT group_count, const MKL_INT *group_size) NOTHROW;

#pragma omp declare variant (MKL_CBLAS_VARIANT_NAME(zaxpy_batch)) match(construct={dispatch}, device={arch(gen)}) \
    append_args(interop(prefer_type("sycl","level_zero"),targetsync)) \
    adjust_args(need_device_ptr:x,y)
void cblas_zaxpy_batch(const MKL_INT *n, const void *alpha,
                       const void **x, const MKL_INT *incx,
                       void **y, const MKL_INT *incy,
                       const MKL_INT group_count, const MKL_INT *group_size) NOTHROW;

#pragma omp declare variant (MKL_BLAS_VARIANT_NAME(saxpy_batch)) match(construct={dispatch}, device={arch(gen)}) \
    append_args(interop(prefer_type("sycl","level_zero"),targetsync)) \
    adjust_args(need_device_ptr:x,y)
void saxpy_batch(const MKL_INT *n, const float *alpha,
                 const float **x, const MKL_INT *incx,
                 float **y, const MKL_INT *incy,
                 const MKL_INT *group_count, const MKL_INT *group_size) NOTHROW;

#pragma omp declare variant (MKL_BLAS_VARIANT_NAME(daxpy_batch)) match(construct={dispatch}, device={arch(gen)}) \
    append_args(interop(prefer_type("sycl","level_zero"),targetsync)) \
    adjust_args(need_device_ptr:x,y)
void daxpy_batch(const MKL_INT *n, const double *alpha,
                 const double **x, const MKL_INT *incx,
                 double **y, const MKL_INT *incy,
                 const MKL_INT *group_count, const MKL_INT *group_size) NOTHROW;

#pragma omp declare variant (MKL_BLAS_VARIANT_NAME(caxpy_batch)) match(construct={dispatch}, device={arch(gen)}) \
    append_args(interop(prefer_type("sycl","level_zero"),targetsync)) \
    adjust_args(need_device_ptr:x,y)
void caxpy_batch(const MKL_INT *n, const MKL_Complex8 *alpha,
                 const MKL_Complex8 **x, const MKL_INT *incx,
                 MKL_Complex8 **y, const MKL_INT *incy,
                 const MKL_INT *group_count, const MKL_INT *group_size) NOTHROW;

#pragma omp declare variant (MKL_BLAS_VARIANT_NAME(zaxpy_batch)) match(construct={dispatch}, device={arch(gen)}) \
    append_args(interop(prefer_type("sycl","level_zero"),targetsync)) \
    adjust_args(need_device_ptr:x,y)
void zaxpy_batch(const MKL_INT *n, const MKL_Complex16 *alpha,
                 const MKL_Complex16 **x, const MKL_INT *incx,
                 MKL_Complex16 **y, const MKL_INT *incy,
                 const MKL_INT *group_count, const MKL_INT *group_size) NOTHROW;

#pragma omp declare variant (MKL_CBLAS_VARIANT_NAME(saxpy_batch_strided)) match(construct={dispatch}, device={arch(gen)}) \
    append_args(interop(prefer_type("sycl","level_zero"),targetsync)) \
    adjust_args(need_device_ptr:X,Y)
void cblas_saxpy_batch_strided(const MKL_INT N, const float alpha,
                               const float *X, const MKL_INT incX, const MKL_INT stridex,
                               float *Y, const MKL_INT incY, const MKL_INT stridey,
                               const MKL_INT batch_size) NOTHROW;

#pragma omp declare variant (MKL_CBLAS_VARIANT_NAME(daxpy_batch_strided)) match(construct={dispatch}, device={arch(gen)}) \
    append_args(interop(prefer_type("sycl","level_zero"),targetsync)) \
    adjust_args(need_device_ptr:X,Y)
void cblas_daxpy_batch_strided(const MKL_INT N, const double alpha,
                               const double *X, const MKL_INT incX, const MKL_INT stridex,
                               double *Y, const MKL_INT incY, const MKL_INT stridey,
                               const MKL_INT batch_size) NOTHROW;

#pragma omp declare variant (MKL_CBLAS_VARIANT_NAME(caxpy_batch_strided)) match(construct={dispatch}, device={arch(gen)}) \
    append_args(interop(prefer_type("sycl","level_zero"),targetsync)) \
    adjust_args(need_device_ptr:X,Y)
void cblas_caxpy_batch_strided(const MKL_INT N, const void *alpha,
                               const void *X, const MKL_INT incX, const MKL_INT stridex,
                               void *Y, const MKL_INT incY, const MKL_INT stridey,
                               const MKL_INT batch_size) NOTHROW;

#pragma omp declare variant (MKL_CBLAS_VARIANT_NAME(zaxpy_batch_strided)) match(construct={dispatch}, device={arch(gen)}) \
    append_args(interop(prefer_type("sycl","level_zero"),targetsync)) \
    adjust_args(need_device_ptr:X,Y)
void cblas_zaxpy_batch_strided(const MKL_INT N, const void *alpha,
                               const void *X, const MKL_INT incX, const MKL_INT stridex,
                               void *Y, const MKL_INT incY, const MKL_INT stridey,
                               const MKL_INT batch_size) NOTHROW;

#pragma omp declare variant (MKL_BLAS_VARIANT_NAME(saxpy_batch_strided)) match(construct={dispatch}, device={arch(gen)}) \
    append_args(interop(prefer_type("sycl","level_zero"),targetsync)) \
    adjust_args(need_device_ptr:x,y)
void saxpy_batch_strided(const MKL_INT *n, const float *alpha,
                         const float *x, const MKL_INT *incx, const MKL_INT *stridex,
                         float *y, const MKL_INT *incy, const MKL_INT *stridey,
                         const MKL_INT *batch_size) NOTHROW;

#pragma omp declare variant (MKL_BLAS_VARIANT_NAME(daxpy_batch_strided)) match(construct={dispatch}, device={arch(gen)}) \
    append_args(interop(prefer_type("sycl","level_zero"),targetsync)) \
    adjust_args(need_device_ptr:x,y)
void daxpy_batch_strided(const MKL_INT *n, const double *alpha,
                         const double *x, const MKL_INT *incx, const MKL_INT *stridex,
                         double *y, const MKL_INT *incy, const MKL_INT *stridey,
                         const MKL_INT *batch_size) NOTHROW;

#pragma omp declare variant (MKL_BLAS_VARIANT_NAME(caxpy_batch_strided)) match(construct={dispatch}, device={arch(gen)}) \
    append_args(interop(prefer_type("sycl","level_zero"),targetsync)) \
    adjust_args(need_device_ptr:x,y)
void caxpy_batch_strided(const MKL_INT *n, const MKL_Complex8 *alpha,
                         const MKL_Complex8 *x, const MKL_INT *incx, const MKL_INT *stridex,
                         MKL_Complex8 *y, const MKL_INT *incy, const MKL_INT *stridey,
                         const MKL_INT *batch_size) NOTHROW;

#pragma omp declare variant (MKL_BLAS_VARIANT_NAME(zaxpy_batch_strided)) match(construct={dispatch}, device={arch(gen)}) \
    append_args(interop(prefer_type("sycl","level_zero"),targetsync)) \
    adjust_args(need_device_ptr:x,y)
void zaxpy_batch_strided(const MKL_INT *n, const MKL_Complex16 *alpha,
                         const MKL_Complex16 *x, const MKL_INT *incx, const MKL_INT *stridex,
                         MKL_Complex16 *y, const MKL_INT *incy, const MKL_INT *stridey,
                         const MKL_INT *batch_size) NOTHROW;

#pragma omp declare variant (MKL_CBLAS_VARIANT_NAME(scopy_batch)) match(construct={dispatch}, device={arch(gen)}) \
    append_args(interop(prefer_type("sycl","level_zero"),targetsync)) \
    adjust_args(need_device_ptr:x,y)
void cblas_scopy_batch(const MKL_INT *n,
                       const float **x, const MKL_INT *incx,
                       float **y, const MKL_INT *incy,
                       const MKL_INT group_count, const MKL_INT *group_size) NOTHROW;

#pragma omp declare variant (MKL_CBLAS_VARIANT_NAME(dcopy_batch)) match(construct={dispatch}, device={arch(gen)}) \
    append_args(interop(prefer_type("sycl","level_zero"),targetsync)) \
    adjust_args(need_device_ptr:x,y)
void cblas_dcopy_batch(const MKL_INT *n,
                       const double **x, const MKL_INT *incx,
                       double **y, const MKL_INT *incy,
                       const MKL_INT group_count, const MKL_INT *group_size) NOTHROW;

#pragma omp declare variant (MKL_CBLAS_VARIANT_NAME(ccopy_batch)) match(construct={dispatch}, device={arch(gen)}) \
    append_args(interop(prefer_type("sycl","level_zero"),targetsync)) \
    adjust_args(need_device_ptr:x,y)
void cblas_ccopy_batch(const MKL_INT *n,
                       const void **x, const MKL_INT *incx,
                       void **y, const MKL_INT *incy,
                       const MKL_INT group_count, const MKL_INT *group_size) NOTHROW;

#pragma omp declare variant (MKL_CBLAS_VARIANT_NAME(zcopy_batch)) match(construct={dispatch}, device={arch(gen)}) \
    append_args(interop(prefer_type("sycl","level_zero"),targetsync)) \
    adjust_args(need_device_ptr:x,y)
void cblas_zcopy_batch(const MKL_INT *n,
                       const void **x, const MKL_INT *incx,
                       void **y, const MKL_INT *incy,
                       const MKL_INT group_count, const MKL_INT *group_size) NOTHROW;

#pragma omp declare variant (MKL_BLAS_VARIANT_NAME(scopy_batch)) match(construct={dispatch}, device={arch(gen)}) \
    append_args(interop(prefer_type("sycl","level_zero"),targetsync)) \
    adjust_args(need_device_ptr:x,y)
void scopy_batch(const MKL_INT *n,
                 const float **x, const MKL_INT *incx,
                 float **y, const MKL_INT *incy,
                 const MKL_INT *group_count, const MKL_INT *group_size) NOTHROW;

#pragma omp declare variant (MKL_BLAS_VARIANT_NAME(dcopy_batch)) match(construct={dispatch}, device={arch(gen)}) \
    append_args(interop(prefer_type("sycl","level_zero"),targetsync)) \
    adjust_args(need_device_ptr:x,y)
void dcopy_batch(const MKL_INT *n,
                 const double **x, const MKL_INT *incx,
                 double **y, const MKL_INT *incy,
                 const MKL_INT *group_count, const MKL_INT *group_size) NOTHROW;

#pragma omp declare variant (MKL_BLAS_VARIANT_NAME(ccopy_batch)) match(construct={dispatch}, device={arch(gen)}) \
    append_args(interop(prefer_type("sycl","level_zero"),targetsync)) \
    adjust_args(need_device_ptr:x,y)
void ccopy_batch(const MKL_INT *n,
                 const MKL_Complex8 **x, const MKL_INT *incx,
                 MKL_Complex8 **y, const MKL_INT *incy,
                 const MKL_INT *group_count, const MKL_INT *group_size) NOTHROW;

#pragma omp declare variant (MKL_BLAS_VARIANT_NAME(zcopy_batch)) match(construct={dispatch}, device={arch(gen)}) \
    append_args(interop(prefer_type("sycl","level_zero"),targetsync)) \
    adjust_args(need_device_ptr:x,y)
void zcopy_batch(const MKL_INT *n,
                 const MKL_Complex16 **x, const MKL_INT *incx,
                 MKL_Complex16 **y, const MKL_INT *incy,
                 const MKL_INT *group_count, const MKL_INT *group_size) NOTHROW;

#pragma omp declare variant (MKL_CBLAS_VARIANT_NAME(scopy_batch_strided)) match(construct={dispatch}, device={arch(gen)}) \
    append_args(interop(prefer_type("sycl","level_zero"),targetsync)) \
    adjust_args(need_device_ptr:X,Y)
void cblas_scopy_batch_strided(const MKL_INT N,
                               const float *X, const MKL_INT incX, const MKL_INT stridex,
                               float *Y, const MKL_INT incY, const MKL_INT stridey,
                               const MKL_INT batch_size) NOTHROW;

#pragma omp declare variant (MKL_CBLAS_VARIANT_NAME(dcopy_batch_strided)) match(construct={dispatch}, device={arch(gen)}) \
    append_args(interop(prefer_type("sycl","level_zero"),targetsync)) \
    adjust_args(need_device_ptr:X,Y)
void cblas_dcopy_batch_strided(const MKL_INT N,
                               const double *X, const MKL_INT incX, const MKL_INT stridex,
                               double *Y, const MKL_INT incY, const MKL_INT stridey,
                               const MKL_INT batch_size) NOTHROW;

#pragma omp declare variant (MKL_CBLAS_VARIANT_NAME(ccopy_batch_strided)) match(construct={dispatch}, device={arch(gen)}) \
    append_args(interop(prefer_type("sycl","level_zero"),targetsync)) \
    adjust_args(need_device_ptr:X,Y)
void cblas_ccopy_batch_strided(const MKL_INT N,
                               const void *X, const MKL_INT incX, const MKL_INT stridex,
                               void *Y, const MKL_INT incY, const MKL_INT stridey,
                               const MKL_INT batch_size) NOTHROW;

#pragma omp declare variant (MKL_CBLAS_VARIANT_NAME(zcopy_batch_strided)) match(construct={dispatch}, device={arch(gen)}) \
    append_args(interop(prefer_type("sycl","level_zero"),targetsync)) \
    adjust_args(need_device_ptr:X,Y)
void cblas_zcopy_batch_strided(const MKL_INT N,
                               const void *X, const MKL_INT incX, const MKL_INT stridex,
                               void *Y, const MKL_INT incY, const MKL_INT stridey,
                               const MKL_INT batch_size) NOTHROW;

#pragma omp declare variant (MKL_BLAS_VARIANT_NAME(scopy_batch_strided)) match(construct={dispatch}, device={arch(gen)}) \
    append_args(interop(prefer_type("sycl","level_zero"),targetsync)) \
    adjust_args(need_device_ptr:X,Y)
void scopy_batch_strided(const MKL_INT *N,
                         const float *X, const MKL_INT *incX, const MKL_INT *stridex,
                         float *Y, const MKL_INT *incY, const MKL_INT *stridey,
                         const MKL_INT *batch_size) NOTHROW;

#pragma omp declare variant (MKL_BLAS_VARIANT_NAME(dcopy_batch_strided)) match(construct={dispatch}, device={arch(gen)}) \
    append_args(interop(prefer_type("sycl","level_zero"),targetsync)) \
    adjust_args(need_device_ptr:X,Y)
void dcopy_batch_strided(const MKL_INT *N,
                         const double *X, const MKL_INT *incX, const MKL_INT *stridex,
                         double *Y, const MKL_INT *incY, const MKL_INT *stridey,
                         const MKL_INT *batch_size) NOTHROW;

#pragma omp declare variant (MKL_BLAS_VARIANT_NAME(ccopy_batch_strided)) match(construct={dispatch}, device={arch(gen)}) \
    append_args(interop(prefer_type("sycl","level_zero"),targetsync)) \
    adjust_args(need_device_ptr:X,Y)
void ccopy_batch_strided(const MKL_INT *N,
                         const MKL_Complex8 *X, const MKL_INT *incX, const MKL_INT *stridex,
                         MKL_Complex8 *Y, const MKL_INT *incY, const MKL_INT *stridey,
                         const MKL_INT *batch_size) NOTHROW;

#pragma omp declare variant (MKL_BLAS_VARIANT_NAME(zcopy_batch_strided)) match(construct={dispatch}, device={arch(gen)}) \
    append_args(interop(prefer_type("sycl","level_zero"),targetsync)) \
    adjust_args(need_device_ptr:X,Y)
void zcopy_batch_strided(const MKL_INT *N,
                         const MKL_Complex16 *X, const MKL_INT *incX, const MKL_INT *stridex,
                         MKL_Complex16 *Y, const MKL_INT *incY, const MKL_INT *stridey,
                         const MKL_INT *batch_size) NOTHROW;

// CBLAS API

// Level3

// Routines with S, D, C, Z prefixes (Standard)
#pragma omp declare variant (MKL_CBLAS_VARIANT_NAME(sgemm)) match(construct={dispatch}, device={arch(gen)}) \
    append_args(interop(prefer_type("sycl","level_zero"),targetsync)) \
    adjust_args(need_device_ptr:A,B,C)
void cblas_sgemm(const CBLAS_LAYOUT Layout, const CBLAS_TRANSPOSE TransA,
                 const CBLAS_TRANSPOSE TransB, const MKL_INT M, const MKL_INT N,
                 const MKL_INT K, const float alpha, const float *A,
                 const MKL_INT lda, const float *B, const MKL_INT ldb,
                 const float beta, float *C, const MKL_INT ldc) NOTHROW;

#pragma omp declare variant (MKL_CBLAS_VARIANT_NAME(sgemmt)) match(construct={dispatch}, device={arch(gen)}) \
    append_args(interop(prefer_type("sycl","level_zero"),targetsync)) \
    adjust_args(need_device_ptr:A,B,C)
void cblas_sgemmt(const CBLAS_LAYOUT Layout, const CBLAS_UPLO Uplo,
                  const CBLAS_TRANSPOSE TransA, const CBLAS_TRANSPOSE TransB,
                  const MKL_INT N, const MKL_INT K,
                  const float alpha, const float *A, const MKL_INT lda,
                  const float *B, const MKL_INT ldb, const float beta,
                  float *C, const MKL_INT ldc) NOTHROW;

#pragma omp declare variant (MKL_CBLAS_VARIANT_NAME(ssymm)) match(construct={dispatch}, device={arch(gen)}) \
    append_args(interop(prefer_type("sycl","level_zero"),targetsync)) \
    adjust_args(need_device_ptr:A,B,C)
void cblas_ssymm(const CBLAS_LAYOUT Layout, const CBLAS_SIDE Side,
                 const CBLAS_UPLO Uplo, const MKL_INT M, const MKL_INT N,
                 const float alpha, const float *A, const MKL_INT lda,
                 const float *B, const MKL_INT ldb, const float beta,
                 float *C, const MKL_INT ldc) NOTHROW;

#pragma omp declare variant (MKL_CBLAS_VARIANT_NAME(ssyr2k)) match(construct={dispatch}, device={arch(gen)}) \
    append_args(interop(prefer_type("sycl","level_zero"),targetsync)) \
    adjust_args(need_device_ptr:A,B,C)
void cblas_ssyr2k(const CBLAS_LAYOUT Layout, const CBLAS_UPLO Uplo,
                  const CBLAS_TRANSPOSE Trans, const MKL_INT N, const MKL_INT K,
                  const float alpha, const float *A, const MKL_INT lda,
                  const float *B, const MKL_INT ldb, const float beta,
                  float *C, const MKL_INT ldc) NOTHROW;

#pragma omp declare variant (MKL_CBLAS_VARIANT_NAME(ssyrk)) match(construct={dispatch}, device={arch(gen)}) \
    append_args(interop(prefer_type("sycl","level_zero"),targetsync)) \
    adjust_args(need_device_ptr:A,C)
void cblas_ssyrk(const CBLAS_LAYOUT Layout, const CBLAS_UPLO Uplo,
                 const CBLAS_TRANSPOSE Trans, const MKL_INT N, const MKL_INT K,
                 const float alpha, const float *A, const MKL_INT lda,
                 const float beta, float *C, const MKL_INT ldc) NOTHROW;

#pragma omp declare variant (MKL_CBLAS_VARIANT_NAME(strmm)) match(construct={dispatch}, device={arch(gen)}) \
    append_args(interop(prefer_type("sycl","level_zero"),targetsync)) \
    adjust_args(need_device_ptr:A,B)
void cblas_strmm(const CBLAS_LAYOUT Layout, const CBLAS_SIDE Side,
                 const CBLAS_UPLO Uplo, const CBLAS_TRANSPOSE TransA,
                 const CBLAS_DIAG Diag, const MKL_INT M, const MKL_INT N,
                 const float alpha, const float *A, const MKL_INT lda,
                 float *B, const MKL_INT ldb) NOTHROW;

#pragma omp declare variant (MKL_CBLAS_VARIANT_NAME(strmm_oop)) match(construct={dispatch}, device={arch(gen)}) \
    append_args(interop(prefer_type("sycl","level_zero"),targetsync)) \
    adjust_args(need_device_ptr:A,B,C)
void cblas_strmm_oop(const CBLAS_LAYOUT Layout, const CBLAS_SIDE Side,
                     const CBLAS_UPLO Uplo, const CBLAS_TRANSPOSE TransA,
                     const CBLAS_DIAG Diag, const MKL_INT M, const MKL_INT N,
                     const float alpha, const float *A, const MKL_INT lda,
                     const float *B, const MKL_INT ldb, const float beta,
                     float *C, const MKL_INT ldc) NOTHROW;

#pragma omp declare variant (MKL_CBLAS_VARIANT_NAME(strsm)) match(construct={dispatch}, device={arch(gen)}) \
    append_args(interop(prefer_type("sycl","level_zero"),targetsync)) \
    adjust_args(need_device_ptr:A,B)
void cblas_strsm(const CBLAS_LAYOUT Layout, const CBLAS_SIDE Side,
                 const CBLAS_UPLO Uplo, const CBLAS_TRANSPOSE TransA,
                 const CBLAS_DIAG Diag, const MKL_INT M, const MKL_INT N,
                 const float alpha, const float *A, const MKL_INT lda,
                 float *B, const MKL_INT ldb) NOTHROW;

#pragma omp declare variant (MKL_CBLAS_VARIANT_NAME(strsm_oop)) match(construct={dispatch}, device={arch(gen)}) \
    append_args(interop(prefer_type("sycl","level_zero"),targetsync)) \
    adjust_args(need_device_ptr:A,B,C)
void cblas_strsm_oop(const CBLAS_LAYOUT Layout, const CBLAS_SIDE Side,
                     const CBLAS_UPLO Uplo, const CBLAS_TRANSPOSE TransA,
                     const CBLAS_DIAG Diag, const MKL_INT M, const MKL_INT N,
                     const float alpha, const float *A, const MKL_INT lda,
                     const float *B, const MKL_INT ldb, const float beta,
                     float *C, const MKL_INT ldc) NOTHROW;

#pragma omp declare variant (MKL_CBLAS_VARIANT_NAME(dgemm)) match(construct={dispatch}, device={arch(gen)}) \
    append_args(interop(prefer_type("sycl","level_zero"),targetsync)) \
    adjust_args(need_device_ptr:A,B,C)
void cblas_dgemm(const CBLAS_LAYOUT Layout, const CBLAS_TRANSPOSE TransA,
                 const CBLAS_TRANSPOSE TransB, const MKL_INT M, const MKL_INT N,
                 const MKL_INT K, const double alpha, const double *A,
                 const MKL_INT lda, const double *B, const MKL_INT ldb,
                 const double beta, double *C, const MKL_INT ldc) NOTHROW;

#pragma omp declare variant (MKL_CBLAS_VARIANT_NAME(dgemmt)) match(construct={dispatch}, device={arch(gen)}) \
    append_args(interop(prefer_type("sycl","level_zero"),targetsync)) \
    adjust_args(need_device_ptr:A,B,C)
void cblas_dgemmt(const CBLAS_LAYOUT Layout, const CBLAS_UPLO Uplo,
                  const CBLAS_TRANSPOSE TransA, const CBLAS_TRANSPOSE TransB,
                  const MKL_INT N, const MKL_INT K,
                  const double alpha, const double *A, const MKL_INT lda,
                  const double *B, const MKL_INT ldb, const double beta,
                  double *C, const MKL_INT ldc) NOTHROW;

#pragma omp declare variant (MKL_CBLAS_VARIANT_NAME(dsymm)) match(construct={dispatch}, device={arch(gen)}) \
    append_args(interop(prefer_type("sycl","level_zero"),targetsync)) \
    adjust_args(need_device_ptr:A,B,C)
void cblas_dsymm(const CBLAS_LAYOUT Layout, const CBLAS_SIDE Side,
                 const CBLAS_UPLO Uplo, const MKL_INT M, const MKL_INT N,
                 const double alpha, const double *A, const MKL_INT lda,
                 const double *B, const MKL_INT ldb, const double beta,
                 double *C, const MKL_INT ldc) NOTHROW;

#pragma omp declare variant (MKL_CBLAS_VARIANT_NAME(dsyr2k)) match(construct={dispatch}, device={arch(gen)}) \
    append_args(interop(prefer_type("sycl","level_zero"),targetsync)) \
    adjust_args(need_device_ptr:A,B,C)
void cblas_dsyr2k(const CBLAS_LAYOUT Layout, const CBLAS_UPLO Uplo,
                  const CBLAS_TRANSPOSE Trans, const MKL_INT N, const MKL_INT K,
                  const double alpha, const double *A, const MKL_INT lda,
                  const double *B, const MKL_INT ldb, const double beta,
                  double *C, const MKL_INT ldc) NOTHROW;

#pragma omp declare variant (MKL_CBLAS_VARIANT_NAME(dsyrk)) match(construct={dispatch}, device={arch(gen)}) \
    append_args(interop(prefer_type("sycl","level_zero"),targetsync)) \
    adjust_args(need_device_ptr:A,C)
void cblas_dsyrk(const CBLAS_LAYOUT Layout, const CBLAS_UPLO Uplo,
                 const CBLAS_TRANSPOSE Trans, const MKL_INT N, const MKL_INT K,
                 const double alpha, const double *A, const MKL_INT lda,
                 const double beta, double *C, const MKL_INT ldc) NOTHROW;

#pragma omp declare variant (MKL_CBLAS_VARIANT_NAME(dtrmm)) match(construct={dispatch}, device={arch(gen)}) \
    append_args(interop(prefer_type("sycl","level_zero"),targetsync)) \
    adjust_args(need_device_ptr:A,B)
void cblas_dtrmm(const CBLAS_LAYOUT Layout, const CBLAS_SIDE Side,
                 const CBLAS_UPLO Uplo, const CBLAS_TRANSPOSE TransA,
                 const CBLAS_DIAG Diag, const MKL_INT M, const MKL_INT N,
                 const double alpha, const double *A, const MKL_INT lda,
                 double *B, const MKL_INT ldb) NOTHROW;

#pragma omp declare variant (MKL_CBLAS_VARIANT_NAME(dtrmm_oop)) match(construct={dispatch}, device={arch(gen)}) \
    append_args(interop(prefer_type("sycl","level_zero"),targetsync)) \
    adjust_args(need_device_ptr:A,B,C)
void cblas_dtrmm_oop(const CBLAS_LAYOUT Layout, const CBLAS_SIDE Side,
                     const CBLAS_UPLO Uplo, const CBLAS_TRANSPOSE TransA,
                     const CBLAS_DIAG Diag, const MKL_INT M, const MKL_INT N,
                     const double alpha, const double *A, const MKL_INT lda,
                     const double *B, const MKL_INT ldb, const double beta,
                     double *C, const MKL_INT ldc) NOTHROW;

#pragma omp declare variant (MKL_CBLAS_VARIANT_NAME(dtrsm)) match(construct={dispatch}, device={arch(gen)}) \
    append_args(interop(prefer_type("sycl","level_zero"),targetsync)) \
    adjust_args(need_device_ptr:A,B)
void cblas_dtrsm(const CBLAS_LAYOUT Layout, const CBLAS_SIDE Side,
                 const CBLAS_UPLO Uplo, const CBLAS_TRANSPOSE TransA,
                 const CBLAS_DIAG Diag, const MKL_INT M, const MKL_INT N,
                 const double alpha, const double *A, const MKL_INT lda,
                 double *B, const MKL_INT ldb) NOTHROW;

#pragma omp declare variant (MKL_CBLAS_VARIANT_NAME(dtrsm_oop)) match(construct={dispatch}, device={arch(gen)}) \
    append_args(interop(prefer_type("sycl","level_zero"),targetsync)) \
    adjust_args(need_device_ptr:A,B,C)
void cblas_dtrsm_oop(const CBLAS_LAYOUT Layout, const CBLAS_SIDE Side,
                     const CBLAS_UPLO Uplo, const CBLAS_TRANSPOSE TransA,
                     const CBLAS_DIAG Diag, const MKL_INT M, const MKL_INT N,
                     const double alpha, const double *A, const MKL_INT lda,
                     const double *B, const MKL_INT ldb, const double beta,
                     double *C, const MKL_INT ldc) NOTHROW;

#pragma omp declare variant (MKL_CBLAS_VARIANT_NAME(cgemm)) match(construct={dispatch}, device={arch(gen)}) \
    append_args(interop(prefer_type("sycl","level_zero"),targetsync)) \
    adjust_args(need_device_ptr:A,B,C)
void cblas_cgemm(const CBLAS_LAYOUT Layout, const CBLAS_TRANSPOSE TransA,
                 const CBLAS_TRANSPOSE TransB, const MKL_INT M, const MKL_INT N,
                 const MKL_INT K, const void *alpha, const void *A,
                 const MKL_INT lda, const void *B, const MKL_INT ldb,
                 const void *beta, void *C, const MKL_INT ldc) NOTHROW;

#pragma omp declare variant (MKL_CBLAS_VARIANT_NAME(cgemm)) match(construct={dispatch}, device={arch(gen)}) \
    append_args(interop(prefer_type("sycl","level_zero"),targetsync)) \
    adjust_args(need_device_ptr:A,B,C)
void cblas_cgemm3m(const CBLAS_LAYOUT Layout, const CBLAS_TRANSPOSE TransA,
                   const CBLAS_TRANSPOSE TransB, const MKL_INT M, const MKL_INT N,
                   const MKL_INT K, const void *alpha, const void *A,
                   const MKL_INT lda, const void *B, const MKL_INT ldb,
                   const void *beta, void *C, const MKL_INT ldc) NOTHROW;

#pragma omp declare variant (MKL_CBLAS_VARIANT_NAME(cgemmt)) match(construct={dispatch}, device={arch(gen)}) \
    append_args(interop(prefer_type("sycl","level_zero"),targetsync)) \
    adjust_args(need_device_ptr:A,B,C)
void cblas_cgemmt(const CBLAS_LAYOUT Layout, const CBLAS_UPLO Uplo,
                  const CBLAS_TRANSPOSE TransA, const CBLAS_TRANSPOSE TransB,
                  const MKL_INT N, const MKL_INT K,
                  const void *alpha, const void *A, const MKL_INT lda,
                  const void *B, const MKL_INT ldb, const void *beta,
                  void *C, const MKL_INT ldc) NOTHROW;

#pragma omp declare variant (MKL_CBLAS_VARIANT_NAME(csymm)) match(construct={dispatch}, device={arch(gen)}) \
    append_args(interop(prefer_type("sycl","level_zero"),targetsync)) \
    adjust_args(need_device_ptr:A,B,C)
void cblas_csymm(const CBLAS_LAYOUT Layout, const CBLAS_SIDE Side,
                 const CBLAS_UPLO Uplo, const MKL_INT M, const MKL_INT N,
                 const void *alpha, const void *A, const MKL_INT lda,
                 const void *B, const MKL_INT ldb, const void *beta,
                 void *C, const MKL_INT ldc) NOTHROW;

#pragma omp declare variant (MKL_CBLAS_VARIANT_NAME(csyr2k)) match(construct={dispatch}, device={arch(gen)}) \
    append_args(interop(prefer_type("sycl","level_zero"),targetsync)) \
    adjust_args(need_device_ptr:A,B,C)
void cblas_csyr2k(const CBLAS_LAYOUT Layout, const CBLAS_UPLO Uplo,
                  const CBLAS_TRANSPOSE Trans, const MKL_INT N, const MKL_INT K,
                  const void *alpha, const void *A, const MKL_INT lda,
                  const void *B, const MKL_INT ldb, const void *beta,
                  void *C, const MKL_INT ldc) NOTHROW;

#pragma omp declare variant (MKL_CBLAS_VARIANT_NAME(csyrk)) match(construct={dispatch}, device={arch(gen)}) \
    append_args(interop(prefer_type("sycl","level_zero"),targetsync)) \
    adjust_args(need_device_ptr:A,C)
void cblas_csyrk(const CBLAS_LAYOUT Layout, const CBLAS_UPLO Uplo,
                 const CBLAS_TRANSPOSE Trans, const MKL_INT N, const MKL_INT K,
                 const void *alpha, const void *A, const MKL_INT lda,
                 const void *beta, void *C, const MKL_INT ldc) NOTHROW;

#pragma omp declare variant (MKL_CBLAS_VARIANT_NAME(ctrmm)) match(construct={dispatch}, device={arch(gen)}) \
    append_args(interop(prefer_type("sycl","level_zero"),targetsync)) \
    adjust_args(need_device_ptr:A,B)
void cblas_ctrmm(const CBLAS_LAYOUT Layout, const CBLAS_SIDE Side,
                 const CBLAS_UPLO Uplo, const CBLAS_TRANSPOSE TransA,
                 const CBLAS_DIAG Diag, const MKL_INT M, const MKL_INT N,
                 const void *alpha, const void *A, const MKL_INT lda,
                 void *B, const MKL_INT ldb) NOTHROW;

#pragma omp declare variant (MKL_CBLAS_VARIANT_NAME(ctrmm_oop)) match(construct={dispatch}, device={arch(gen)}) \
    append_args(interop(prefer_type("sycl","level_zero"),targetsync)) \
    adjust_args(need_device_ptr:A,B,C)
void cblas_ctrmm_oop(const CBLAS_LAYOUT Layout, const CBLAS_SIDE Side,
                     const CBLAS_UPLO Uplo, const CBLAS_TRANSPOSE TransA,
                     const CBLAS_DIAG Diag, const MKL_INT M, const MKL_INT N,
                     const void *alpha, const void *A, const MKL_INT lda,
                     const void *B, const MKL_INT ldb, const void *beta,
                     void *C, const MKL_INT ldc) NOTHROW;

#pragma omp declare variant (MKL_CBLAS_VARIANT_NAME(ctrsm)) match(construct={dispatch}, device={arch(gen)}) \
    append_args(interop(prefer_type("sycl","level_zero"),targetsync)) \
    adjust_args(need_device_ptr:A,B)
void cblas_ctrsm(const CBLAS_LAYOUT Layout, const CBLAS_SIDE Side,
                 const CBLAS_UPLO Uplo, const CBLAS_TRANSPOSE TransA,
                 const CBLAS_DIAG Diag, const MKL_INT M, const MKL_INT N,
                 const void *alpha, const void *A, const MKL_INT lda,
                 void *B, const MKL_INT ldb) NOTHROW;

#pragma omp declare variant (MKL_CBLAS_VARIANT_NAME(ctrsm_oop)) match(construct={dispatch}, device={arch(gen)}) \
    append_args(interop(prefer_type("sycl","level_zero"),targetsync)) \
    adjust_args(need_device_ptr:A,B,C)
void cblas_ctrsm_oop(const CBLAS_LAYOUT Layout, const CBLAS_SIDE Side,
                     const CBLAS_UPLO Uplo, const CBLAS_TRANSPOSE TransA,
                     const CBLAS_DIAG Diag, const MKL_INT M, const MKL_INT N,
                     const void *alpha, const void *A, const MKL_INT lda,
                     const void *B, const MKL_INT ldb, const void *beta,
                     void *C, const MKL_INT ldc) NOTHROW;

#pragma omp declare variant (MKL_CBLAS_VARIANT_NAME(zgemm)) match(construct={dispatch}, device={arch(gen)}) \
    append_args(interop(prefer_type("sycl","level_zero"),targetsync)) \
    adjust_args(need_device_ptr:A,B,C)
void cblas_zgemm(const CBLAS_LAYOUT Layout, const CBLAS_TRANSPOSE TransA,
                 const CBLAS_TRANSPOSE TransB, const MKL_INT M, const MKL_INT N,
                 const MKL_INT K, const void *alpha, const void *A,
                 const MKL_INT lda, const void *B, const MKL_INT ldb,
                 const void *beta, void *C, const MKL_INT ldc) NOTHROW;

#pragma omp declare variant (MKL_CBLAS_VARIANT_NAME(zgemm)) match(construct={dispatch}, device={arch(gen)}) \
    append_args(interop(prefer_type("sycl","level_zero"),targetsync)) \
    adjust_args(need_device_ptr:A,B,C)
void cblas_zgemm3m(const CBLAS_LAYOUT Layout, const CBLAS_TRANSPOSE TransA,
                   const CBLAS_TRANSPOSE TransB, const MKL_INT M, const MKL_INT N,
                   const MKL_INT K, const void *alpha, const void *A,
                   const MKL_INT lda, const void *B, const MKL_INT ldb,
                   const void *beta, void *C, const MKL_INT ldc) NOTHROW;

#pragma omp declare variant (MKL_CBLAS_VARIANT_NAME(zgemmt)) match(construct={dispatch}, device={arch(gen)}) \
    append_args(interop(prefer_type("sycl","level_zero"),targetsync)) \
    adjust_args(need_device_ptr:A,B,C)
void cblas_zgemmt(const CBLAS_LAYOUT Layout, const CBLAS_UPLO Uplo,
                  const CBLAS_TRANSPOSE TransA, const CBLAS_TRANSPOSE TransB,
                  const MKL_INT N, const MKL_INT K,
                  const void *alpha, const void *A, const MKL_INT lda,
                  const void *B, const MKL_INT ldb, const void *beta,
                  void *C, const MKL_INT ldc) NOTHROW;

#pragma omp declare variant (MKL_CBLAS_VARIANT_NAME(zsymm)) match(construct={dispatch}, device={arch(gen)}) \
    append_args(interop(prefer_type("sycl","level_zero"),targetsync)) \
    adjust_args(need_device_ptr:A,B,C)
void cblas_zsymm(const CBLAS_LAYOUT Layout, const CBLAS_SIDE Side,
                 const CBLAS_UPLO Uplo, const MKL_INT M, const MKL_INT N,
                 const void *alpha, const void *A, const MKL_INT lda,
                 const void *B, const MKL_INT ldb, const void *beta,
                 void *C, const MKL_INT ldc) NOTHROW;

#pragma omp declare variant (MKL_CBLAS_VARIANT_NAME(zsyr2k)) match(construct={dispatch}, device={arch(gen)}) \
    append_args(interop(prefer_type("sycl","level_zero"),targetsync)) \
    adjust_args(need_device_ptr:A,B,C)
void cblas_zsyr2k(const CBLAS_LAYOUT Layout, const CBLAS_UPLO Uplo,
                  const CBLAS_TRANSPOSE Trans, const MKL_INT N, const MKL_INT K,
                  const void *alpha, const void *A, const MKL_INT lda,
                  const void *B, const MKL_INT ldb, const void *beta,
                  void *C, const MKL_INT ldc) NOTHROW;

#pragma omp declare variant (MKL_CBLAS_VARIANT_NAME(zsyrk)) match(construct={dispatch}, device={arch(gen)}) \
    append_args(interop(prefer_type("sycl","level_zero"),targetsync)) \
    adjust_args(need_device_ptr:A,C)
void cblas_zsyrk(const CBLAS_LAYOUT Layout, const CBLAS_UPLO Uplo,
                 const CBLAS_TRANSPOSE Trans, const MKL_INT N, const MKL_INT K,
                 const void *alpha, const void *A, const MKL_INT lda,
                 const void *beta, void *C, const MKL_INT ldc) NOTHROW;

#pragma omp declare variant (MKL_CBLAS_VARIANT_NAME(ztrmm)) match(construct={dispatch}, device={arch(gen)}) \
    append_args(interop(prefer_type("sycl","level_zero"),targetsync)) \
    adjust_args(need_device_ptr:A,B)
void cblas_ztrmm(const CBLAS_LAYOUT Layout, const CBLAS_SIDE Side,
                 const CBLAS_UPLO Uplo, const CBLAS_TRANSPOSE TransA,
                 const CBLAS_DIAG Diag, const MKL_INT M, const MKL_INT N,
                 const void *alpha, const void *A, const MKL_INT lda,
                 void *B, const MKL_INT ldb) NOTHROW;

#pragma omp declare variant (MKL_CBLAS_VARIANT_NAME(ztrmm_oop)) match(construct={dispatch}, device={arch(gen)}) \
    append_args(interop(prefer_type("sycl","level_zero"),targetsync)) \
    adjust_args(need_device_ptr:A,B,C)
void cblas_ztrmm_oop(const CBLAS_LAYOUT Layout, const CBLAS_SIDE Side,
                     const CBLAS_UPLO Uplo, const CBLAS_TRANSPOSE TransA,
                     const CBLAS_DIAG Diag, const MKL_INT M, const MKL_INT N,
                     const void *alpha, const void *A, const MKL_INT lda,
                     const void *B, const MKL_INT ldb, const void *beta,
                     void *C, const MKL_INT ldc) NOTHROW;

#pragma omp declare variant (MKL_CBLAS_VARIANT_NAME(ztrsm)) match(construct={dispatch}, device={arch(gen)}) \
    append_args(interop(prefer_type("sycl","level_zero"),targetsync)) \
    adjust_args(need_device_ptr:A,B)
void cblas_ztrsm(const CBLAS_LAYOUT Layout, const CBLAS_SIDE Side,
                 const CBLAS_UPLO Uplo, const CBLAS_TRANSPOSE TransA,
                 const CBLAS_DIAG Diag, const MKL_INT M, const MKL_INT N,
                 const void *alpha, const void *A, const MKL_INT lda,
                 void *B, const MKL_INT ldb) NOTHROW;

#pragma omp declare variant (MKL_CBLAS_VARIANT_NAME(ztrsm_oop)) match(construct={dispatch}, device={arch(gen)}) \
    append_args(interop(prefer_type("sycl","level_zero"),targetsync)) \
    adjust_args(need_device_ptr:A,B,C)
void cblas_ztrsm_oop(const CBLAS_LAYOUT Layout, const CBLAS_SIDE Side,
                     const CBLAS_UPLO Uplo, const CBLAS_TRANSPOSE TransA,
                     const CBLAS_DIAG Diag, const MKL_INT M, const MKL_INT N,
                     const void *alpha, const void *A, const MKL_INT lda,
                     const void *B, const MKL_INT ldb, const void *beta,
                     void *C, const MKL_INT ldc) NOTHROW;

// Routines with C, Z prefixes
#pragma omp declare variant (MKL_CBLAS_VARIANT_NAME(chemm)) match(construct={dispatch}, device={arch(gen)}) \
    append_args(interop(prefer_type("sycl","level_zero"),targetsync)) \
    adjust_args(need_device_ptr:A,B,C)
void cblas_chemm(const CBLAS_LAYOUT Layout, const CBLAS_SIDE Side,
                 const CBLAS_UPLO Uplo, const MKL_INT M, const MKL_INT N,
                 const void *alpha, const void *A, const MKL_INT lda,
                 const void *B, const MKL_INT ldb, const void *beta,
                 void *C, const MKL_INT ldc) NOTHROW;

#pragma omp declare variant (MKL_CBLAS_VARIANT_NAME(cher2k)) match(construct={dispatch}, device={arch(gen)}) \
    append_args(interop(prefer_type("sycl","level_zero"),targetsync)) \
    adjust_args(need_device_ptr:A,B,C)
void cblas_cher2k(const CBLAS_LAYOUT Layout, const CBLAS_UPLO Uplo,
                  const CBLAS_TRANSPOSE Trans, const MKL_INT N, const MKL_INT K,
                  const void *alpha, const void *A, const MKL_INT lda,
                  const void *B, const MKL_INT ldb, const float beta,
                  void *C, const MKL_INT ldc) NOTHROW;

#pragma omp declare variant (MKL_CBLAS_VARIANT_NAME(cherk)) match(construct={dispatch}, device={arch(gen)}) \
    append_args(interop(prefer_type("sycl","level_zero"),targetsync)) \
    adjust_args(need_device_ptr:A,C)
void cblas_cherk(const CBLAS_LAYOUT Layout, const CBLAS_UPLO Uplo,
                 const CBLAS_TRANSPOSE Trans, const MKL_INT N, const MKL_INT K,
                 const float alpha, const void *A, const MKL_INT lda,
                 const float beta, void *C, const MKL_INT ldc) NOTHROW;

#pragma omp declare variant (MKL_CBLAS_VARIANT_NAME(zhemm)) match(construct={dispatch}, device={arch(gen)}) \
    append_args(interop(prefer_type("sycl","level_zero"),targetsync)) \
    adjust_args(need_device_ptr:A,B,C)
void cblas_zhemm(const CBLAS_LAYOUT Layout, const CBLAS_SIDE Side,
                 const CBLAS_UPLO Uplo, const MKL_INT M, const MKL_INT N,
                 const void *alpha, const void *A, const MKL_INT lda,
                 const void *B, const MKL_INT ldb, const void *beta,
                 void *C, const MKL_INT ldc) NOTHROW;

#pragma omp declare variant (MKL_CBLAS_VARIANT_NAME(zher2k)) match(construct={dispatch}, device={arch(gen)}) \
    append_args(interop(prefer_type("sycl","level_zero"),targetsync)) \
    adjust_args(need_device_ptr:A,B,C)
void cblas_zher2k(const CBLAS_LAYOUT Layout, const CBLAS_UPLO Uplo,
                  const CBLAS_TRANSPOSE Trans, const MKL_INT N, const MKL_INT K,
                  const void *alpha, const void *A, const MKL_INT lda,
                  const void *B, const MKL_INT ldb, const double beta,
                  void *C, const MKL_INT ldc) NOTHROW;

#pragma omp declare variant (MKL_CBLAS_VARIANT_NAME(zherk)) match(construct={dispatch}, device={arch(gen)}) \
    append_args(interop(prefer_type("sycl","level_zero"),targetsync)) \
    adjust_args(need_device_ptr:A,C)
void cblas_zherk(const CBLAS_LAYOUT Layout, const CBLAS_UPLO Uplo,
                 const CBLAS_TRANSPOSE Trans, const MKL_INT N, const MKL_INT K,
                 const double alpha, const void *A, const MKL_INT lda,
                 const double beta, void *C, const MKL_INT ldc) NOTHROW;

// Other precisions

#pragma omp declare variant (MKL_CBLAS_VARIANT_NAME(hgemm)) match(construct={dispatch}, device={arch(gen)}) \
    append_args(interop(prefer_type("sycl","level_zero"),targetsync)) \
    adjust_args(need_device_ptr:A,B,C)
void cblas_hgemm(const CBLAS_LAYOUT Layout, const CBLAS_TRANSPOSE TransA,
                 const CBLAS_TRANSPOSE TransB, const MKL_INT M, const MKL_INT N,
                 const MKL_INT K, const MKL_F16 alpha, const MKL_F16 *A,
                 const MKL_INT lda, const MKL_F16 *B, const MKL_INT ldb,
                 const MKL_F16 beta, MKL_F16 *C, const MKL_INT ldc) NOTHROW;

#pragma omp declare variant (MKL_CBLAS_VARIANT_NAME(gemm_s8u8s32)) match(construct={dispatch}, device={arch(gen)}) \
    append_args(interop(prefer_type("sycl","level_zero"),targetsync)) \
    adjust_args(need_device_ptr:A,B,C,cb)
void cblas_gemm_s8u8s32(const CBLAS_LAYOUT Layout, const CBLAS_TRANSPOSE TransA,
                        const CBLAS_TRANSPOSE TransB, const CBLAS_OFFSET OffsetC,
                        const MKL_INT M, const MKL_INT N, const MKL_INT K,
                        const float alpha, const void *A, const MKL_INT lda, const MKL_INT8 ao,
                        const void *B, const MKL_INT ldb, const MKL_INT8 bo, const float beta,
                        MKL_INT32 *C, const MKL_INT ldc, const MKL_INT32 *cb) NOTHROW;

#pragma omp declare variant (MKL_CBLAS_VARIANT_NAME(gemm_f16f16f32)) match(construct={dispatch}, device={arch(gen)}) \
    append_args(interop(prefer_type("sycl","level_zero"),targetsync)) \
    adjust_args(need_device_ptr:A,B,C)
void cblas_gemm_f16f16f32(const CBLAS_LAYOUT Layout, const CBLAS_TRANSPOSE TransA,
                            const CBLAS_TRANSPOSE TransB,
                            const MKL_INT M, const MKL_INT N, const MKL_INT K,
                            const float alpha, const MKL_F16 *A, const MKL_INT lda,
                            const MKL_F16 *B, const MKL_INT ldb, const float beta,
                            float *C, const MKL_INT ldc) NOTHROW;

#pragma omp declare variant (MKL_CBLAS_VARIANT_NAME(gemm_bf16bf16f32)) match(construct={dispatch}, device={arch(gen)}) \
    append_args(interop(prefer_type("sycl","level_zero"),targetsync)) \
    adjust_args(need_device_ptr:A,B,C)
void cblas_gemm_bf16bf16f32(const CBLAS_LAYOUT Layout, const CBLAS_TRANSPOSE TransA,
                            const CBLAS_TRANSPOSE TransB,
                            const MKL_INT M, const MKL_INT N, const MKL_INT K,
                            const float alpha, const MKL_BF16 *A, const MKL_INT lda,
                            const MKL_BF16 *B, const MKL_INT ldb, const float beta,
                            float *C, const MKL_INT ldc) NOTHROW;

// Level2

// Routines with S, D, C, Z prefixes (Standard)
#pragma omp declare variant (MKL_CBLAS_VARIANT_NAME(sgemv)) match(construct={dispatch}, device={arch(gen)}) \
    append_args(interop(prefer_type("sycl","level_zero"),targetsync)) \
    adjust_args(need_device_ptr:A,X,Y)
void cblas_sgemv(const CBLAS_LAYOUT Layout,
                 const CBLAS_TRANSPOSE TransA, const MKL_INT M, const MKL_INT N,
                 const float alpha, const float *A, const MKL_INT lda,
                 const float *X, const MKL_INT incX, const float beta,
                 float *Y, const MKL_INT incY) NOTHROW;

#pragma omp declare variant (MKL_CBLAS_VARIANT_NAME(sgbmv)) match(construct={dispatch}, device={arch(gen)}) \
    append_args(interop(prefer_type("sycl","level_zero"),targetsync)) \
    adjust_args(need_device_ptr:A,X,Y)
void cblas_sgbmv(const CBLAS_LAYOUT Layout,
                 const CBLAS_TRANSPOSE TransA, const MKL_INT M, const MKL_INT N,
                 const MKL_INT KL, const MKL_INT KU, const float alpha,
                 const float *A, const MKL_INT lda, const float *X,
                 const MKL_INT incX, const float beta, float *Y, const MKL_INT incY) NOTHROW;

#pragma omp declare variant (MKL_CBLAS_VARIANT_NAME(strmv)) match(construct={dispatch}, device={arch(gen)}) \
    append_args(interop(prefer_type("sycl","level_zero"),targetsync)) \
    adjust_args(need_device_ptr:A,X)
void cblas_strmv(const CBLAS_LAYOUT Layout, const CBLAS_UPLO Uplo,
                 const CBLAS_TRANSPOSE TransA, const CBLAS_DIAG Diag,
                 const MKL_INT N, const float *A, const MKL_INT lda,
                 float *X, const MKL_INT incX) NOTHROW;

#pragma omp declare variant (MKL_CBLAS_VARIANT_NAME(stbmv)) match(construct={dispatch}, device={arch(gen)}) \
    append_args(interop(prefer_type("sycl","level_zero"),targetsync)) \
    adjust_args(need_device_ptr:A,X)
void cblas_stbmv(const CBLAS_LAYOUT Layout, const CBLAS_UPLO Uplo,
                 const CBLAS_TRANSPOSE TransA, const CBLAS_DIAG Diag,
                 const MKL_INT N, const MKL_INT K, const float *A, const MKL_INT lda,
                 float *X, const MKL_INT incX) NOTHROW;

#pragma omp declare variant (MKL_CBLAS_VARIANT_NAME(stpmv)) match(construct={dispatch}, device={arch(gen)}) \
    append_args(interop(prefer_type("sycl","level_zero"),targetsync)) \
    adjust_args(need_device_ptr:Ap,X)
void cblas_stpmv(const CBLAS_LAYOUT Layout, const CBLAS_UPLO Uplo,
                 const CBLAS_TRANSPOSE TransA, const CBLAS_DIAG Diag,
                 const MKL_INT N, const float *Ap, float *X, const MKL_INT incX) NOTHROW;

#pragma omp declare variant (MKL_CBLAS_VARIANT_NAME(strsv)) match(construct={dispatch}, device={arch(gen)}) \
    append_args(interop(prefer_type("sycl","level_zero"),targetsync)) \
    adjust_args(need_device_ptr:A,X)
void cblas_strsv(const CBLAS_LAYOUT Layout, const CBLAS_UPLO Uplo,
                 const CBLAS_TRANSPOSE TransA, const CBLAS_DIAG Diag,
                 const MKL_INT N, const float *A, const MKL_INT lda, float *X,
                 const MKL_INT incX) NOTHROW;

#pragma omp declare variant (MKL_CBLAS_VARIANT_NAME(stbsv)) match(construct={dispatch}, device={arch(gen)}) \
    append_args(interop(prefer_type("sycl","level_zero"),targetsync)) \
    adjust_args(need_device_ptr:A,X)
void cblas_stbsv(const CBLAS_LAYOUT Layout, const CBLAS_UPLO Uplo,
                 const CBLAS_TRANSPOSE TransA, const CBLAS_DIAG Diag,
                 const MKL_INT N, const MKL_INT K, const float *A, const MKL_INT lda,
                 float *X, const MKL_INT incX) NOTHROW;

#pragma omp declare variant (MKL_CBLAS_VARIANT_NAME(stpsv)) match(construct={dispatch}, device={arch(gen)}) \
    append_args(interop(prefer_type("sycl","level_zero"),targetsync)) \
    adjust_args(need_device_ptr:Ap,X)
void cblas_stpsv(const CBLAS_LAYOUT Layout, const CBLAS_UPLO Uplo,
                 const CBLAS_TRANSPOSE TransA, const CBLAS_DIAG Diag,
                 const MKL_INT N, const float *Ap, float *X, const MKL_INT incX) NOTHROW;

#pragma omp declare variant (MKL_CBLAS_VARIANT_NAME(dgemv)) match(construct={dispatch}, device={arch(gen)}) \
    append_args(interop(prefer_type("sycl","level_zero"),targetsync)) \
    adjust_args(need_device_ptr:A,X,Y)
void cblas_dgemv(const CBLAS_LAYOUT Layout,
                 const CBLAS_TRANSPOSE TransA, const MKL_INT M, const MKL_INT N,
                 const double alpha, const double *A, const MKL_INT lda,
                 const double *X, const MKL_INT incX, const double beta,
                 double *Y, const MKL_INT incY) NOTHROW;

#pragma omp declare variant (MKL_CBLAS_VARIANT_NAME(dgbmv)) match(construct={dispatch}, device={arch(gen)}) \
    append_args(interop(prefer_type("sycl","level_zero"),targetsync)) \
    adjust_args(need_device_ptr:A,X,Y)
void cblas_dgbmv(const CBLAS_LAYOUT Layout,
                 const CBLAS_TRANSPOSE TransA, const MKL_INT M, const MKL_INT N,
                 const MKL_INT KL, const MKL_INT KU, const double alpha,
                 const double *A, const MKL_INT lda, const double *X,
                 const MKL_INT incX, const double beta, double *Y, const MKL_INT incY) NOTHROW;

#pragma omp declare variant (MKL_CBLAS_VARIANT_NAME(dtrmv)) match(construct={dispatch}, device={arch(gen)}) \
    append_args(interop(prefer_type("sycl","level_zero"),targetsync)) \
    adjust_args(need_device_ptr:A,X)
void cblas_dtrmv(const CBLAS_LAYOUT Layout, const CBLAS_UPLO Uplo,
                 const CBLAS_TRANSPOSE TransA, const CBLAS_DIAG Diag,
                 const MKL_INT N, const double *A, const MKL_INT lda,
                 double *X, const MKL_INT incX) NOTHROW;

#pragma omp declare variant (MKL_CBLAS_VARIANT_NAME(dtbmv)) match(construct={dispatch}, device={arch(gen)}) \
    append_args(interop(prefer_type("sycl","level_zero"),targetsync)) \
    adjust_args(need_device_ptr:A,X)
void cblas_dtbmv(const CBLAS_LAYOUT Layout, const CBLAS_UPLO Uplo,
                 const CBLAS_TRANSPOSE TransA, const CBLAS_DIAG Diag,
                 const MKL_INT N, const MKL_INT K, const double *A, const MKL_INT lda,
                 double *X, const MKL_INT incX) NOTHROW;

#pragma omp declare variant (MKL_CBLAS_VARIANT_NAME(dtpmv)) match(construct={dispatch}, device={arch(gen)}) \
    append_args(interop(prefer_type("sycl","level_zero"),targetsync)) \
    adjust_args(need_device_ptr:Ap,X)
void cblas_dtpmv(const CBLAS_LAYOUT Layout, const CBLAS_UPLO Uplo,
                 const CBLAS_TRANSPOSE TransA, const CBLAS_DIAG Diag,
                 const MKL_INT N, const double *Ap, double *X, const MKL_INT incX) NOTHROW;

#pragma omp declare variant (MKL_CBLAS_VARIANT_NAME(dtrsv)) match(construct={dispatch}, device={arch(gen)}) \
    append_args(interop(prefer_type("sycl","level_zero"),targetsync)) \
    adjust_args(need_device_ptr:A,X)
void cblas_dtrsv(const CBLAS_LAYOUT Layout, const CBLAS_UPLO Uplo,
                 const CBLAS_TRANSPOSE TransA, const CBLAS_DIAG Diag,
                 const MKL_INT N, const double *A, const MKL_INT lda, double *X,
                 const MKL_INT incX) NOTHROW;

#pragma omp declare variant (MKL_CBLAS_VARIANT_NAME(dtbsv)) match(construct={dispatch}, device={arch(gen)}) \
    append_args(interop(prefer_type("sycl","level_zero"),targetsync)) \
    adjust_args(need_device_ptr:A,X)
void cblas_dtbsv(const CBLAS_LAYOUT Layout, const CBLAS_UPLO Uplo,
                 const CBLAS_TRANSPOSE TransA, const CBLAS_DIAG Diag,
                 const MKL_INT N, const MKL_INT K, const double *A, const MKL_INT lda,
                 double *X, const MKL_INT incX) NOTHROW;

#pragma omp declare variant (MKL_CBLAS_VARIANT_NAME(dtpsv)) match(construct={dispatch}, device={arch(gen)}) \
    append_args(interop(prefer_type("sycl","level_zero"),targetsync)) \
    adjust_args(need_device_ptr:Ap,X)
void cblas_dtpsv(const CBLAS_LAYOUT Layout, const CBLAS_UPLO Uplo,
                 const CBLAS_TRANSPOSE TransA, const CBLAS_DIAG Diag,
                 const MKL_INT N, const double *Ap, double *X, const MKL_INT incX) NOTHROW;

#pragma omp declare variant (MKL_CBLAS_VARIANT_NAME(cgemv)) match(construct={dispatch}, device={arch(gen)}) \
    append_args(interop(prefer_type("sycl","level_zero"),targetsync)) \
    adjust_args(need_device_ptr:A,X,Y)
void cblas_cgemv(const CBLAS_LAYOUT Layout,
                 const CBLAS_TRANSPOSE TransA, const MKL_INT M, const MKL_INT N,
                 const void *alpha, const void *A, const MKL_INT lda,
                 const void *X, const MKL_INT incX, const void *beta,
                 void *Y, const MKL_INT incY) NOTHROW;

#pragma omp declare variant (MKL_CBLAS_VARIANT_NAME(cgbmv)) match(construct={dispatch}, device={arch(gen)}) \
    append_args(interop(prefer_type("sycl","level_zero"),targetsync)) \
    adjust_args(need_device_ptr:A,X,Y)
void cblas_cgbmv(const CBLAS_LAYOUT Layout,
                 const CBLAS_TRANSPOSE TransA, const MKL_INT M, const MKL_INT N,
                 const MKL_INT KL, const MKL_INT KU, const void *alpha,
                 const void *A, const MKL_INT lda, const void *X,
                 const MKL_INT incX, const void *beta, void *Y, const MKL_INT incY) NOTHROW;

#pragma omp declare variant (MKL_CBLAS_VARIANT_NAME(ctrmv)) match(construct={dispatch}, device={arch(gen)}) \
    append_args(interop(prefer_type("sycl","level_zero"),targetsync)) \
    adjust_args(need_device_ptr:A,X)
void cblas_ctrmv(const CBLAS_LAYOUT Layout, const CBLAS_UPLO Uplo,
                 const CBLAS_TRANSPOSE TransA, const CBLAS_DIAG Diag,
                 const MKL_INT N, const void *A, const MKL_INT lda,
                 void *X, const MKL_INT incX) NOTHROW;

#pragma omp declare variant (MKL_CBLAS_VARIANT_NAME(ctbmv)) match(construct={dispatch}, device={arch(gen)}) \
    append_args(interop(prefer_type("sycl","level_zero"),targetsync)) \
    adjust_args(need_device_ptr:A,X)
void cblas_ctbmv(const CBLAS_LAYOUT Layout, const CBLAS_UPLO Uplo,
                 const CBLAS_TRANSPOSE TransA, const CBLAS_DIAG Diag,
                 const MKL_INT N, const MKL_INT K, const void *A, const MKL_INT lda,
                 void *X, const MKL_INT incX) NOTHROW;

#pragma omp declare variant (MKL_CBLAS_VARIANT_NAME(ctpmv)) match(construct={dispatch}, device={arch(gen)}) \
    append_args(interop(prefer_type("sycl","level_zero"),targetsync)) \
    adjust_args(need_device_ptr:Ap,X)
void cblas_ctpmv(const CBLAS_LAYOUT Layout, const CBLAS_UPLO Uplo,
                 const CBLAS_TRANSPOSE TransA, const CBLAS_DIAG Diag,
                 const MKL_INT N, const void *Ap, void *X, const MKL_INT incX) NOTHROW;

#pragma omp declare variant (MKL_CBLAS_VARIANT_NAME(ctrsv)) match(construct={dispatch}, device={arch(gen)}) \
    append_args(interop(prefer_type("sycl","level_zero"),targetsync)) \
    adjust_args(need_device_ptr:A,X)
void cblas_ctrsv(const CBLAS_LAYOUT Layout, const CBLAS_UPLO Uplo,
                 const CBLAS_TRANSPOSE TransA, const CBLAS_DIAG Diag,
                 const MKL_INT N, const void *A, const MKL_INT lda, void *X,
                 const MKL_INT incX) NOTHROW;

#pragma omp declare variant (MKL_CBLAS_VARIANT_NAME(ctbsv)) match(construct={dispatch}, device={arch(gen)}) \
    append_args(interop(prefer_type("sycl","level_zero"),targetsync)) \
    adjust_args(need_device_ptr:A,X)
void cblas_ctbsv(const CBLAS_LAYOUT Layout, const CBLAS_UPLO Uplo,
                 const CBLAS_TRANSPOSE TransA, const CBLAS_DIAG Diag,
                 const MKL_INT N, const MKL_INT K, const void *A, const MKL_INT lda,
                 void *X, const MKL_INT incX) NOTHROW;

#pragma omp declare variant (MKL_CBLAS_VARIANT_NAME(ctpsv)) match(construct={dispatch}, device={arch(gen)}) \
    append_args(interop(prefer_type("sycl","level_zero"),targetsync)) \
    adjust_args(need_device_ptr:Ap,X)
void cblas_ctpsv(const CBLAS_LAYOUT Layout, const CBLAS_UPLO Uplo,
                 const CBLAS_TRANSPOSE TransA, const CBLAS_DIAG Diag,
                 const MKL_INT N, const void *Ap, void *X, const MKL_INT incX) NOTHROW;

#pragma omp declare variant (MKL_CBLAS_VARIANT_NAME(zgemv)) match(construct={dispatch}, device={arch(gen)}) \
    append_args(interop(prefer_type("sycl","level_zero"),targetsync)) \
    adjust_args(need_device_ptr:A,X,Y)
void cblas_zgemv(const CBLAS_LAYOUT Layout,
                 const CBLAS_TRANSPOSE TransA, const MKL_INT M, const MKL_INT N,
                 const void *alpha, const void *A, const MKL_INT lda,
                 const void *X, const MKL_INT incX, const void *beta,
                 void *Y, const MKL_INT incY) NOTHROW;

#pragma omp declare variant (MKL_CBLAS_VARIANT_NAME(zgbmv)) match(construct={dispatch}, device={arch(gen)}) \
    append_args(interop(prefer_type("sycl","level_zero"),targetsync)) \
    adjust_args(need_device_ptr:A,X,Y)
void cblas_zgbmv(const CBLAS_LAYOUT Layout,
                 const CBLAS_TRANSPOSE TransA, const MKL_INT M, const MKL_INT N,
                 const MKL_INT KL, const MKL_INT KU, const void *alpha,
                 const void *A, const MKL_INT lda, const void *X,
                 const MKL_INT incX, const void *beta, void *Y, const MKL_INT incY) NOTHROW;

#pragma omp declare variant (MKL_CBLAS_VARIANT_NAME(ztrmv)) match(construct={dispatch}, device={arch(gen)}) \
    append_args(interop(prefer_type("sycl","level_zero"),targetsync)) \
    adjust_args(need_device_ptr:A,X)
void cblas_ztrmv(const CBLAS_LAYOUT Layout, const CBLAS_UPLO Uplo,
                 const CBLAS_TRANSPOSE TransA, const CBLAS_DIAG Diag,
                 const MKL_INT N, const void *A, const MKL_INT lda,
                 void *X, const MKL_INT incX) NOTHROW;

#pragma omp declare variant (MKL_CBLAS_VARIANT_NAME(ztbmv)) match(construct={dispatch}, device={arch(gen)}) \
    append_args(interop(prefer_type("sycl","level_zero"),targetsync)) \
    adjust_args(need_device_ptr:A,X)
void cblas_ztbmv(const CBLAS_LAYOUT Layout, const CBLAS_UPLO Uplo,
                 const CBLAS_TRANSPOSE TransA, const CBLAS_DIAG Diag,
                 const MKL_INT N, const MKL_INT K, const void *A, const MKL_INT lda,
                 void *X, const MKL_INT incX) NOTHROW;

#pragma omp declare variant (MKL_CBLAS_VARIANT_NAME(ztpmv)) match(construct={dispatch}, device={arch(gen)}) \
    append_args(interop(prefer_type("sycl","level_zero"),targetsync)) \
    adjust_args(need_device_ptr:Ap,X)
void cblas_ztpmv(const CBLAS_LAYOUT Layout, const CBLAS_UPLO Uplo,
                 const CBLAS_TRANSPOSE TransA, const CBLAS_DIAG Diag,
                 const MKL_INT N, const void *Ap, void *X, const MKL_INT incX) NOTHROW;

#pragma omp declare variant (MKL_CBLAS_VARIANT_NAME(ztrsv)) match(construct={dispatch}, device={arch(gen)}) \
    append_args(interop(prefer_type("sycl","level_zero"),targetsync)) \
    adjust_args(need_device_ptr:A,X)
void cblas_ztrsv(const CBLAS_LAYOUT Layout, const CBLAS_UPLO Uplo,
                 const CBLAS_TRANSPOSE TransA, const CBLAS_DIAG Diag,
                 const MKL_INT N, const void *A, const MKL_INT lda, void *X,
                 const MKL_INT incX) NOTHROW;

#pragma omp declare variant (MKL_CBLAS_VARIANT_NAME(ztbsv)) match(construct={dispatch}, device={arch(gen)}) \
    append_args(interop(prefer_type("sycl","level_zero"),targetsync)) \
    adjust_args(need_device_ptr:A,X)
void cblas_ztbsv(const CBLAS_LAYOUT Layout, const CBLAS_UPLO Uplo,
                 const CBLAS_TRANSPOSE TransA, const CBLAS_DIAG Diag,
                 const MKL_INT N, const MKL_INT K, const void *A, const MKL_INT lda,
                 void *X, const MKL_INT incX) NOTHROW;

#pragma omp declare variant (MKL_CBLAS_VARIANT_NAME(ztpsv)) match(construct={dispatch}, device={arch(gen)}) \
    append_args(interop(prefer_type("sycl","level_zero"),targetsync)) \
    adjust_args(need_device_ptr:Ap,X)
void cblas_ztpsv(const CBLAS_LAYOUT Layout, const CBLAS_UPLO Uplo,
                 const CBLAS_TRANSPOSE TransA, const CBLAS_DIAG Diag,
                 const MKL_INT N, const void *Ap, void *X, const MKL_INT incX) NOTHROW;

// Routines with S, D prefixes
#pragma omp declare variant (MKL_CBLAS_VARIANT_NAME(ssymv)) match(construct={dispatch}, device={arch(gen)}) \
    append_args(interop(prefer_type("sycl","level_zero"),targetsync)) \
    adjust_args(need_device_ptr:A,X,Y)
void cblas_ssymv(const CBLAS_LAYOUT Layout, const CBLAS_UPLO Uplo,
                 const MKL_INT N, const float alpha, const float *A,
                 const MKL_INT lda, const float *X, const MKL_INT incX,
                 const float beta, float *Y, const MKL_INT incY) NOTHROW;

#pragma omp declare variant (MKL_CBLAS_VARIANT_NAME(ssbmv)) match(construct={dispatch}, device={arch(gen)}) \
    append_args(interop(prefer_type("sycl","level_zero"),targetsync)) \
    adjust_args(need_device_ptr:A,X,Y)
void cblas_ssbmv(const CBLAS_LAYOUT Layout, const CBLAS_UPLO Uplo,
                 const MKL_INT N, const MKL_INT K, const float alpha, const float *A,
                 const MKL_INT lda, const float *X, const MKL_INT incX,
                 const float beta, float *Y, const MKL_INT incY) NOTHROW;

#pragma omp declare variant (MKL_CBLAS_VARIANT_NAME(sspmv)) match(construct={dispatch}, device={arch(gen)}) \
    append_args(interop(prefer_type("sycl","level_zero"),targetsync)) \
    adjust_args(need_device_ptr:Ap,X,Y)
void cblas_sspmv(const CBLAS_LAYOUT Layout, const CBLAS_UPLO Uplo,
                 const MKL_INT N, const float alpha, const float *Ap,
                 const float *X, const MKL_INT incX,
                 const float beta, float *Y, const MKL_INT incY) NOTHROW;

#pragma omp declare variant (MKL_CBLAS_VARIANT_NAME(sger)) match(construct={dispatch}, device={arch(gen)}) \
    append_args(interop(prefer_type("sycl","level_zero"),targetsync)) \
    adjust_args(need_device_ptr:A,X,Y)
void cblas_sger(const CBLAS_LAYOUT Layout, const MKL_INT M, const MKL_INT N,
                const float alpha, const float *X, const MKL_INT incX,
                const float *Y, const MKL_INT incY, float *A, const MKL_INT lda) NOTHROW;

#pragma omp declare variant (MKL_CBLAS_VARIANT_NAME(ssyr)) match(construct={dispatch}, device={arch(gen)}) \
    append_args(interop(prefer_type("sycl","level_zero"),targetsync)) \
    adjust_args(need_device_ptr:A,X)
void cblas_ssyr(const CBLAS_LAYOUT Layout, const CBLAS_UPLO Uplo,
                const MKL_INT N, const float alpha, const float *X,
                const MKL_INT incX, float *A, const MKL_INT lda) NOTHROW;

#pragma omp declare variant (MKL_CBLAS_VARIANT_NAME(sspr)) match(construct={dispatch}, device={arch(gen)}) \
    append_args(interop(prefer_type("sycl","level_zero"),targetsync)) \
    adjust_args(need_device_ptr:Ap,X)
void cblas_sspr(const CBLAS_LAYOUT Layout, const CBLAS_UPLO Uplo,
                const MKL_INT N, const float alpha, const float *X,
                const MKL_INT incX, float *Ap) NOTHROW;

#pragma omp declare variant (MKL_CBLAS_VARIANT_NAME(ssyr2)) match(construct={dispatch}, device={arch(gen)}) \
    append_args(interop(prefer_type("sycl","level_zero"),targetsync)) \
    adjust_args(need_device_ptr:A,X,Y)
void cblas_ssyr2(const CBLAS_LAYOUT Layout, const CBLAS_UPLO Uplo,
                 const MKL_INT N, const float alpha, const float *X,
                 const MKL_INT incX, const float *Y, const MKL_INT incY, float *A,
                 const MKL_INT lda) NOTHROW;

#pragma omp declare variant (MKL_CBLAS_VARIANT_NAME(sspr2)) match(construct={dispatch}, device={arch(gen)}) \
    append_args(interop(prefer_type("sycl","level_zero"),targetsync)) \
    adjust_args(need_device_ptr:A,X,Y)
void cblas_sspr2(const CBLAS_LAYOUT Layout, const CBLAS_UPLO Uplo,
                 const MKL_INT N, const float alpha, const float *X,
                 const MKL_INT incX, const float *Y, const MKL_INT incY, float *A) NOTHROW;

#pragma omp declare variant (MKL_CBLAS_VARIANT_NAME(dsymv)) match(construct={dispatch}, device={arch(gen)}) \
    append_args(interop(prefer_type("sycl","level_zero"),targetsync)) \
    adjust_args(need_device_ptr:A,X,Y)
void cblas_dsymv(const CBLAS_LAYOUT Layout, const CBLAS_UPLO Uplo,
                 const MKL_INT N, const double alpha, const double *A,
                 const MKL_INT lda, const double *X, const MKL_INT incX,
                 const double beta, double *Y, const MKL_INT incY) NOTHROW;

#pragma omp declare variant (MKL_CBLAS_VARIANT_NAME(dsbmv)) match(construct={dispatch}, device={arch(gen)}) \
    append_args(interop(prefer_type("sycl","level_zero"),targetsync)) \
    adjust_args(need_device_ptr:A,X,Y)
void cblas_dsbmv(const CBLAS_LAYOUT Layout, const CBLAS_UPLO Uplo,
                 const MKL_INT N, const MKL_INT K, const double alpha, const double *A,
                 const MKL_INT lda, const double *X, const MKL_INT incX,
                 const double beta, double *Y, const MKL_INT incY) NOTHROW;

#pragma omp declare variant (MKL_CBLAS_VARIANT_NAME(dspmv)) match(construct={dispatch}, device={arch(gen)}) \
    append_args(interop(prefer_type("sycl","level_zero"),targetsync)) \
    adjust_args(need_device_ptr:Ap,X,Y)
void cblas_dspmv(const CBLAS_LAYOUT Layout, const CBLAS_UPLO Uplo,
                 const MKL_INT N, const double alpha, const double *Ap,
                 const double *X, const MKL_INT incX,
                 const double beta, double *Y, const MKL_INT incY) NOTHROW;

#pragma omp declare variant (MKL_CBLAS_VARIANT_NAME(dger)) match(construct={dispatch}, device={arch(gen)}) \
    append_args(interop(prefer_type("sycl","level_zero"),targetsync)) \
    adjust_args(need_device_ptr:A,X,Y)
void cblas_dger(const CBLAS_LAYOUT Layout, const MKL_INT M, const MKL_INT N,
                const double alpha, const double *X, const MKL_INT incX,
                const double *Y, const MKL_INT incY, double *A, const MKL_INT lda) NOTHROW;

#pragma omp declare variant (MKL_CBLAS_VARIANT_NAME(dsyr)) match(construct={dispatch}, device={arch(gen)}) \
    append_args(interop(prefer_type("sycl","level_zero"),targetsync)) \
    adjust_args(need_device_ptr:A,X)
void cblas_dsyr(const CBLAS_LAYOUT Layout, const CBLAS_UPLO Uplo,
                const MKL_INT N, const double alpha, const double *X,
                const MKL_INT incX, double *A, const MKL_INT lda) NOTHROW;

#pragma omp declare variant (MKL_CBLAS_VARIANT_NAME(dspr)) match(construct={dispatch}, device={arch(gen)}) \
    append_args(interop(prefer_type("sycl","level_zero"),targetsync)) \
    adjust_args(need_device_ptr:Ap,X)
void cblas_dspr(const CBLAS_LAYOUT Layout, const CBLAS_UPLO Uplo,
                const MKL_INT N, const double alpha, const double *X,
                const MKL_INT incX, double *Ap) NOTHROW;

#pragma omp declare variant (MKL_CBLAS_VARIANT_NAME(dsyr2)) match(construct={dispatch}, device={arch(gen)}) \
    append_args(interop(prefer_type("sycl","level_zero"),targetsync)) \
    adjust_args(need_device_ptr:A,X,Y)
void cblas_dsyr2(const CBLAS_LAYOUT Layout, const CBLAS_UPLO Uplo,
                 const MKL_INT N, const double alpha, const double *X,
                 const MKL_INT incX, const double *Y, const MKL_INT incY, double *A,
                 const MKL_INT lda) NOTHROW;

#pragma omp declare variant (MKL_CBLAS_VARIANT_NAME(dspr2)) match(construct={dispatch}, device={arch(gen)}) \
    append_args(interop(prefer_type("sycl","level_zero"),targetsync)) \
    adjust_args(need_device_ptr:A,X,Y)
void cblas_dspr2(const CBLAS_LAYOUT Layout, const CBLAS_UPLO Uplo,
                 const MKL_INT N, const double alpha, const double *X,
                 const MKL_INT incX, const double *Y, const MKL_INT incY, double *A) NOTHROW;

// Routines with C, Z prefixes
#pragma omp declare variant (MKL_CBLAS_VARIANT_NAME(chemv)) match(construct={dispatch}, device={arch(gen)}) \
    append_args(interop(prefer_type("sycl","level_zero"),targetsync)) \
    adjust_args(need_device_ptr:A,X,Y)
void cblas_chemv(const CBLAS_LAYOUT Layout, const CBLAS_UPLO Uplo,
                 const MKL_INT N, const void *alpha, const void *A,
                 const MKL_INT lda, const void *X, const MKL_INT incX,
                 const void *beta, void *Y, const MKL_INT incY) NOTHROW;

#pragma omp declare variant (MKL_CBLAS_VARIANT_NAME(chbmv)) match(construct={dispatch}, device={arch(gen)}) \
    append_args(interop(prefer_type("sycl","level_zero"),targetsync)) \
    adjust_args(need_device_ptr:A,X,Y)
void cblas_chbmv(const CBLAS_LAYOUT Layout, const CBLAS_UPLO Uplo,
                 const MKL_INT N, const MKL_INT K, const void *alpha, const void *A,
                 const MKL_INT lda, const void *X, const MKL_INT incX,
                 const void *beta, void *Y, const MKL_INT incY) NOTHROW;

#pragma omp declare variant (MKL_CBLAS_VARIANT_NAME(chpmv)) match(construct={dispatch}, device={arch(gen)}) \
    append_args(interop(prefer_type("sycl","level_zero"),targetsync)) \
    adjust_args(need_device_ptr:Ap,X,Y)
void cblas_chpmv(const CBLAS_LAYOUT Layout, const CBLAS_UPLO Uplo,
                 const MKL_INT N, const void *alpha, const void *Ap,
                 const void *X, const MKL_INT incX,
                 const void *beta, void *Y, const MKL_INT incY) NOTHROW;

#pragma omp declare variant (MKL_CBLAS_VARIANT_NAME(cgeru)) match(construct={dispatch}, device={arch(gen)}) \
    append_args(interop(prefer_type("sycl","level_zero"),targetsync)) \
    adjust_args(need_device_ptr:A,X,Y)
void cblas_cgeru(const CBLAS_LAYOUT Layout, const MKL_INT M, const MKL_INT N,
                 const void *alpha, const void *X, const MKL_INT incX,
                 const void *Y, const MKL_INT incY, void *A, const MKL_INT lda) NOTHROW;

#pragma omp declare variant (MKL_CBLAS_VARIANT_NAME(cgerc)) match(construct={dispatch}, device={arch(gen)}) \
    append_args(interop(prefer_type("sycl","level_zero"),targetsync)) \
    adjust_args(need_device_ptr:A,X,Y)
void cblas_cgerc(const CBLAS_LAYOUT Layout, const MKL_INT M, const MKL_INT N,
                 const void *alpha, const void *X, const MKL_INT incX,
                 const void *Y, const MKL_INT incY, void *A, const MKL_INT lda) NOTHROW;

#pragma omp declare variant (MKL_CBLAS_VARIANT_NAME(cher)) match(construct={dispatch}, device={arch(gen)}) \
    append_args(interop(prefer_type("sycl","level_zero"),targetsync)) \
    adjust_args(need_device_ptr:A,X)
void cblas_cher(const CBLAS_LAYOUT Layout, const CBLAS_UPLO Uplo,
                const MKL_INT N, const float alpha, const void *X, const MKL_INT incX,
                void *A, const MKL_INT lda) NOTHROW;

#pragma omp declare variant (MKL_CBLAS_VARIANT_NAME(chpr)) match(construct={dispatch}, device={arch(gen)}) \
    append_args(interop(prefer_type("sycl","level_zero"),targetsync)) \
    adjust_args(need_device_ptr:A,X)
void cblas_chpr(const CBLAS_LAYOUT Layout, const CBLAS_UPLO Uplo,
                const MKL_INT N, const float alpha, const void *X,
                const MKL_INT incX, void *A) NOTHROW;

#pragma omp declare variant (MKL_CBLAS_VARIANT_NAME(cher2)) match(construct={dispatch}, device={arch(gen)}) \
    append_args(interop(prefer_type("sycl","level_zero"),targetsync)) \
    adjust_args(need_device_ptr:A,X,Y)
void cblas_cher2(const CBLAS_LAYOUT Layout, const CBLAS_UPLO Uplo, const MKL_INT N,
                 const void *alpha, const void *X, const MKL_INT incX,
                 const void *Y, const MKL_INT incY, void *A, const MKL_INT lda) NOTHROW;

#pragma omp declare variant (MKL_CBLAS_VARIANT_NAME(chpr2)) match(construct={dispatch}, device={arch(gen)}) \
    append_args(interop(prefer_type("sycl","level_zero"),targetsync)) \
    adjust_args(need_device_ptr:Ap,X,Y)
void cblas_chpr2(const CBLAS_LAYOUT Layout, const CBLAS_UPLO Uplo, const MKL_INT N,
                 const void *alpha, const void *X, const MKL_INT incX,
                 const void *Y, const MKL_INT incY, void *Ap) NOTHROW;

#pragma omp declare variant (MKL_CBLAS_VARIANT_NAME(zhemv)) match(construct={dispatch}, device={arch(gen)}) \
    append_args(interop(prefer_type("sycl","level_zero"),targetsync)) \
    adjust_args(need_device_ptr:A,X,Y)
void cblas_zhemv(const CBLAS_LAYOUT Layout, const CBLAS_UPLO Uplo,
                 const MKL_INT N, const void *alpha, const void *A,
                 const MKL_INT lda, const void *X, const MKL_INT incX,
                 const void *beta, void *Y, const MKL_INT incY) NOTHROW;

#pragma omp declare variant (MKL_CBLAS_VARIANT_NAME(zhbmv)) match(construct={dispatch}, device={arch(gen)}) \
    append_args(interop(prefer_type("sycl","level_zero"),targetsync)) \
    adjust_args(need_device_ptr:A,X,Y)
void cblas_zhbmv(const CBLAS_LAYOUT Layout, const CBLAS_UPLO Uplo,
                 const MKL_INT N, const MKL_INT K, const void *alpha, const void *A,
                 const MKL_INT lda, const void *X, const MKL_INT incX,
                 const void *beta, void *Y, const MKL_INT incY) NOTHROW;

#pragma omp declare variant (MKL_CBLAS_VARIANT_NAME(zhpmv)) match(construct={dispatch}, device={arch(gen)}) \
    append_args(interop(prefer_type("sycl","level_zero"),targetsync)) \
    adjust_args(need_device_ptr:Ap,X,Y)
void cblas_zhpmv(const CBLAS_LAYOUT Layout, const CBLAS_UPLO Uplo,
                 const MKL_INT N, const void *alpha, const void *Ap,
                 const void *X, const MKL_INT incX,
                 const void *beta, void *Y, const MKL_INT incY) NOTHROW;

#pragma omp declare variant (MKL_CBLAS_VARIANT_NAME(zgeru)) match(construct={dispatch}, device={arch(gen)}) \
    append_args(interop(prefer_type("sycl","level_zero"),targetsync)) \
    adjust_args(need_device_ptr:A,X,Y)
void cblas_zgeru(const CBLAS_LAYOUT Layout, const MKL_INT M, const MKL_INT N,
                 const void *alpha, const void *X, const MKL_INT incX,
                 const void *Y, const MKL_INT incY, void *A, const MKL_INT lda) NOTHROW;

#pragma omp declare variant (MKL_CBLAS_VARIANT_NAME(zgerc)) match(construct={dispatch}, device={arch(gen)}) \
    append_args(interop(prefer_type("sycl","level_zero"),targetsync)) \
    adjust_args(need_device_ptr:A,X,Y)
void cblas_zgerc(const CBLAS_LAYOUT Layout, const MKL_INT M, const MKL_INT N,
                 const void *alpha, const void *X, const MKL_INT incX,
                 const void *Y, const MKL_INT incY, void *A, const MKL_INT lda) NOTHROW;

#pragma omp declare variant (MKL_CBLAS_VARIANT_NAME(zher)) match(construct={dispatch}, device={arch(gen)}) \
    append_args(interop(prefer_type("sycl","level_zero"),targetsync)) \
    adjust_args(need_device_ptr:A,X)
void cblas_zher(const CBLAS_LAYOUT Layout, const CBLAS_UPLO Uplo,
                const MKL_INT N, const double alpha, const void *X, const MKL_INT incX,
                void *A, const MKL_INT lda) NOTHROW;

#pragma omp declare variant (MKL_CBLAS_VARIANT_NAME(zhpr)) match(construct={dispatch}, device={arch(gen)}) \
    append_args(interop(prefer_type("sycl","level_zero"),targetsync)) \
    adjust_args(need_device_ptr:A,X)
void cblas_zhpr(const CBLAS_LAYOUT Layout, const CBLAS_UPLO Uplo,
                const MKL_INT N, const double alpha, const void *X,
                const MKL_INT incX, void *A) NOTHROW;

#pragma omp declare variant (MKL_CBLAS_VARIANT_NAME(zher2)) match(construct={dispatch}, device={arch(gen)}) \
    append_args(interop(prefer_type("sycl","level_zero"),targetsync)) \
    adjust_args(need_device_ptr:A,X,Y)
void cblas_zher2(const CBLAS_LAYOUT Layout, const CBLAS_UPLO Uplo, const MKL_INT N,
                 const void *alpha, const void *X, const MKL_INT incX,
                 const void *Y, const MKL_INT incY, void *A, const MKL_INT lda) NOTHROW;

#pragma omp declare variant (MKL_CBLAS_VARIANT_NAME(zhpr2)) match(construct={dispatch}, device={arch(gen)}) \
    append_args(interop(prefer_type("sycl","level_zero"),targetsync)) \
    adjust_args(need_device_ptr:Ap,X,Y)
void cblas_zhpr2(const CBLAS_LAYOUT Layout, const CBLAS_UPLO Uplo, const MKL_INT N,
                 const void *alpha, const void *X, const MKL_INT incX,
                 const void *Y, const MKL_INT incY, void *Ap) NOTHROW;


// Level1

// Routines with S, D, DS, SDS prefixes
#pragma omp declare variant (MKL_CBLAS_VARIANT_NAME(sdot)) match(construct={dispatch}, device={arch(gen)}) \
    append_args(interop(prefer_type("sycl","level_zero"),targetsync)) \
    adjust_args(need_device_ptr:X,Y)
float cblas_sdot(const MKL_INT N, const float  *X, const MKL_INT incX,
                 const float  *Y, const MKL_INT incY) NOTHROW;

#pragma omp declare variant (MKL_CBLAS_VARIANT_NAME(ddot)) match(construct={dispatch}, device={arch(gen)}) \
    append_args(interop(prefer_type("sycl","level_zero"),targetsync)) \
    adjust_args(need_device_ptr:X,Y)
double cblas_ddot(const MKL_INT N, const double *X, const MKL_INT incX,
                  const double *Y, const MKL_INT incY) NOTHROW;

#pragma omp declare variant (MKL_CBLAS_VARIANT_NAME(dsdot)) match(construct={dispatch}, device={arch(gen)}) \
    append_args(interop(prefer_type("sycl","level_zero"),targetsync)) \
    adjust_args(need_device_ptr:X,Y)
double cblas_dsdot(const MKL_INT N, const float  *X, const MKL_INT incX,
                   const float  *Y, const MKL_INT incY) NOTHROW;

#pragma omp declare variant (MKL_CBLAS_VARIANT_NAME(sdsdot)) match(construct={dispatch}, device={arch(gen)}) \
    append_args(interop(prefer_type("sycl","level_zero"),targetsync)) \
    adjust_args(need_device_ptr:X,Y)
float cblas_sdsdot(const MKL_INT N, const float sb, const float  *X,
                   const MKL_INT incX, const float  *Y, const MKL_INT incY) NOTHROW;

// Routines with C, Z prefixes
#pragma omp declare variant (MKL_CBLAS_VARIANT_NAME(cdotu)) match(construct={dispatch}, device={arch(gen)}) \
    append_args(interop(prefer_type("sycl","level_zero"),targetsync)) \
    adjust_args(need_device_ptr:X,Y,dotu)
void cblas_cdotu_sub(const MKL_INT N, const void *X, const MKL_INT incX,
                     const void *Y, const MKL_INT incY, void *dotu) NOTHROW;

#pragma omp declare variant (MKL_CBLAS_VARIANT_NAME(cdotc)) match(construct={dispatch}, device={arch(gen)}) \
    append_args(interop(prefer_type("sycl","level_zero"),targetsync)) \
    adjust_args(need_device_ptr:X,Y,dotc)
void cblas_cdotc_sub(const MKL_INT N, const void *X, const MKL_INT incX,
                     const void *Y, const MKL_INT incY, void *dotc) NOTHROW;

#pragma omp declare variant (MKL_CBLAS_VARIANT_NAME(zdotu)) match(construct={dispatch}, device={arch(gen)}) \
    append_args(interop(prefer_type("sycl","level_zero"),targetsync)) \
    adjust_args(need_device_ptr:X,Y,dotu)
void cblas_zdotu_sub(const MKL_INT N, const void *X, const MKL_INT incX,
                     const void *Y, const MKL_INT incY, void *dotu) NOTHROW;

#pragma omp declare variant (MKL_CBLAS_VARIANT_NAME(zdotc)) match(construct={dispatch}, device={arch(gen)}) \
    append_args(interop(prefer_type("sycl","level_zero"),targetsync)) \
    adjust_args(need_device_ptr:X,Y,dotc)
void cblas_zdotc_sub(const MKL_INT N, const void *X, const MKL_INT incX,
                     const void *Y, const MKL_INT incY, void *dotc) NOTHROW;

// Routines with S, D, SC, DZ prefixes
#pragma omp declare variant (MKL_CBLAS_VARIANT_NAME(snrm2)) match(construct={dispatch}, device={arch(gen)}) \
    append_args(interop(prefer_type("sycl","level_zero"),targetsync)) \
    adjust_args(need_device_ptr:X)
float cblas_snrm2(const MKL_INT N, const float *X, const MKL_INT incX) NOTHROW;

#pragma omp declare variant (MKL_CBLAS_VARIANT_NAME(sasum)) match(construct={dispatch}, device={arch(gen)}) \
    append_args(interop(prefer_type("sycl","level_zero"),targetsync)) \
    adjust_args(need_device_ptr:X)
float cblas_sasum(const MKL_INT N, const float *X, const MKL_INT incX) NOTHROW;

#pragma omp declare variant (MKL_CBLAS_VARIANT_NAME(dnrm2)) match(construct={dispatch}, device={arch(gen)}) \
    append_args(interop(prefer_type("sycl","level_zero"),targetsync)) \
    adjust_args(need_device_ptr:X)
double cblas_dnrm2(const MKL_INT N, const double *X, const MKL_INT incX) NOTHROW;

#pragma omp declare variant (MKL_CBLAS_VARIANT_NAME(dasum)) match(construct={dispatch}, device={arch(gen)}) \
    append_args(interop(prefer_type("sycl","level_zero"),targetsync)) \
    adjust_args(need_device_ptr:X)
double cblas_dasum(const MKL_INT N, const double *X, const MKL_INT incX) NOTHROW;

#pragma omp declare variant (MKL_CBLAS_VARIANT_NAME(scnrm2)) match(construct={dispatch}, device={arch(gen)}) \
    append_args(interop(prefer_type("sycl","level_zero"),targetsync)) \
    adjust_args(need_device_ptr:X)
float cblas_scnrm2(const MKL_INT N, const void *X, const MKL_INT incX) NOTHROW;

#pragma omp declare variant (MKL_CBLAS_VARIANT_NAME(scasum)) match(construct={dispatch}, device={arch(gen)}) \
    append_args(interop(prefer_type("sycl","level_zero"),targetsync)) \
    adjust_args(need_device_ptr:X)
float cblas_scasum(const MKL_INT N, const void *X, const MKL_INT incX) NOTHROW;

#pragma omp declare variant (MKL_CBLAS_VARIANT_NAME(dznrm2)) match(construct={dispatch}, device={arch(gen)}) \
    append_args(interop(prefer_type("sycl","level_zero"),targetsync)) \
    adjust_args(need_device_ptr:X)
double cblas_dznrm2(const MKL_INT N, const void *X, const MKL_INT incX) NOTHROW;

#pragma omp declare variant (MKL_CBLAS_VARIANT_NAME(dzasum)) match(construct={dispatch}, device={arch(gen)}) \
    append_args(interop(prefer_type("sycl","level_zero"),targetsync)) \
    adjust_args(need_device_ptr:X)
double cblas_dzasum(const MKL_INT N, const void *X, const MKL_INT incX) NOTHROW;


// Routines with S, D, C, Z prefixes (Standard)

#pragma omp declare variant (MKL_CBLAS_VARIANT_NAME(isamax)) match(construct={dispatch}, device={arch(gen)}) \
    append_args(interop(prefer_type("sycl","level_zero"),targetsync)) \
    adjust_args(need_device_ptr:X)
CBLAS_INDEX cblas_isamax(const MKL_INT N, const float  *X, const MKL_INT incX) NOTHROW;

#pragma omp declare variant (MKL_CBLAS_VARIANT_NAME(idamax)) match(construct={dispatch}, device={arch(gen)}) \
    append_args(interop(prefer_type("sycl","level_zero"),targetsync)) \
    adjust_args(need_device_ptr:X)
CBLAS_INDEX cblas_idamax(const MKL_INT N, const double *X, const MKL_INT incX) NOTHROW;

#pragma omp declare variant (MKL_CBLAS_VARIANT_NAME(icamax)) match(construct={dispatch}, device={arch(gen)}) \
    append_args(interop(prefer_type("sycl","level_zero"),targetsync)) \
    adjust_args(need_device_ptr:X)
CBLAS_INDEX cblas_icamax(const MKL_INT N, const void *X, const MKL_INT incX) NOTHROW;

#pragma omp declare variant (MKL_CBLAS_VARIANT_NAME(izamax)) match(construct={dispatch}, device={arch(gen)}) \
    append_args(interop(prefer_type("sycl","level_zero"),targetsync)) \
    adjust_args(need_device_ptr:X)
CBLAS_INDEX cblas_izamax(const MKL_INT N, const void *X, const MKL_INT incX) NOTHROW;

#pragma omp declare variant (MKL_CBLAS_VARIANT_NAME(isamin)) match(construct={dispatch}, device={arch(gen)}) \
    append_args(interop(prefer_type("sycl","level_zero"),targetsync)) \
    adjust_args(need_device_ptr:X)
CBLAS_INDEX cblas_isamin(const MKL_INT N, const float  *X, const MKL_INT incX) NOTHROW;

#pragma omp declare variant (MKL_CBLAS_VARIANT_NAME(idamin)) match(construct={dispatch}, device={arch(gen)}) \
    append_args(interop(prefer_type("sycl","level_zero"),targetsync)) \
    adjust_args(need_device_ptr:X)
CBLAS_INDEX cblas_idamin(const MKL_INT N, const double *X, const MKL_INT incX) NOTHROW;

#pragma omp declare variant (MKL_CBLAS_VARIANT_NAME(icamin)) match(construct={dispatch}, device={arch(gen)}) \
    append_args(interop(prefer_type("sycl","level_zero"),targetsync)) \
    adjust_args(need_device_ptr:X)
CBLAS_INDEX cblas_icamin(const MKL_INT N, const void *X, const MKL_INT incX) NOTHROW;

#pragma omp declare variant (MKL_CBLAS_VARIANT_NAME(izamin)) match(construct={dispatch}, device={arch(gen)}) \
    append_args(interop(prefer_type("sycl","level_zero"),targetsync)) \
    adjust_args(need_device_ptr:X)
CBLAS_INDEX cblas_izamin(const MKL_INT N, const void *X, const MKL_INT incX) NOTHROW;

#pragma omp declare variant (MKL_CBLAS_VARIANT_NAME(sswap)) match(construct={dispatch}, device={arch(gen)}) \
    append_args(interop(prefer_type("sycl","level_zero"),targetsync)) \
    adjust_args(need_device_ptr:X,Y)
void cblas_sswap(const MKL_INT N, float *X, const MKL_INT incX,
                 float *Y, const MKL_INT incY) NOTHROW;

#pragma omp declare variant (MKL_CBLAS_VARIANT_NAME(scopy)) match(construct={dispatch}, device={arch(gen)}) \
    append_args(interop(prefer_type("sycl","level_zero"),targetsync)) \
    adjust_args(need_device_ptr:X,Y)
void cblas_scopy(const MKL_INT N, const float *X, const MKL_INT incX,
                 float *Y, const MKL_INT incY) NOTHROW;

#pragma omp declare variant (MKL_CBLAS_VARIANT_NAME(saxpy)) match(construct={dispatch}, device={arch(gen)}) \
    append_args(interop(prefer_type("sycl","level_zero"),targetsync)) \
    adjust_args(need_device_ptr:X,Y)
void cblas_saxpy(const MKL_INT N, const float alpha, const float *X,
                 const MKL_INT incX, float *Y, const MKL_INT incY) NOTHROW;

#pragma omp declare variant (MKL_CBLAS_VARIANT_NAME(srotg)) match(construct={dispatch}, device={arch(gen)}) \
    append_args(interop(prefer_type("sycl","level_zero"),targetsync)) \
    adjust_args(need_device_ptr:a,b,c,s)
void cblas_srotg(float *a, float *b, float *c, float *s) NOTHROW;

#pragma omp declare variant (MKL_CBLAS_VARIANT_NAME(dswap)) match(construct={dispatch}, device={arch(gen)}) \
    append_args(interop(prefer_type("sycl","level_zero"),targetsync)) \
    adjust_args(need_device_ptr:X,Y)
void cblas_dswap(const MKL_INT N, double *X, const MKL_INT incX,
                 double *Y, const MKL_INT incY) NOTHROW;

#pragma omp declare variant (MKL_CBLAS_VARIANT_NAME(dcopy)) match(construct={dispatch}, device={arch(gen)}) \
    append_args(interop(prefer_type("sycl","level_zero"),targetsync)) \
    adjust_args(need_device_ptr:X,Y)
void cblas_dcopy(const MKL_INT N, const double *X, const MKL_INT incX,
                 double *Y, const MKL_INT incY) NOTHROW;

#pragma omp declare variant (MKL_CBLAS_VARIANT_NAME(daxpy)) match(construct={dispatch}, device={arch(gen)}) \
    append_args(interop(prefer_type("sycl","level_zero"),targetsync)) \
    adjust_args(need_device_ptr:X,Y)
void cblas_daxpy(const MKL_INT N, const double alpha, const double *X,
                 const MKL_INT incX, double *Y, const MKL_INT incY) NOTHROW;

#pragma omp declare variant (MKL_CBLAS_VARIANT_NAME(drotg)) match(construct={dispatch}, device={arch(gen)}) \
    append_args(interop(prefer_type("sycl","level_zero"),targetsync)) \
    adjust_args(need_device_ptr:a,b,c,s)
void cblas_drotg(double *a, double *b, double *c, double *s) NOTHROW;

#pragma omp declare variant (MKL_CBLAS_VARIANT_NAME(cswap)) match(construct={dispatch}, device={arch(gen)}) \
    append_args(interop(prefer_type("sycl","level_zero"),targetsync)) \
    adjust_args(need_device_ptr:X,Y)
void cblas_cswap(const MKL_INT N, void *X, const MKL_INT incX,
                 void *Y, const MKL_INT incY) NOTHROW;

#pragma omp declare variant (MKL_CBLAS_VARIANT_NAME(ccopy)) match(construct={dispatch}, device={arch(gen)}) \
    append_args(interop(prefer_type("sycl","level_zero"),targetsync)) \
    adjust_args(need_device_ptr:X,Y)
void cblas_ccopy(const MKL_INT N, const void *X, const MKL_INT incX,
                 void *Y, const MKL_INT incY) NOTHROW;

#pragma omp declare variant (MKL_CBLAS_VARIANT_NAME(caxpy)) match(construct={dispatch}, device={arch(gen)}) \
    append_args(interop(prefer_type("sycl","level_zero"),targetsync)) \
    adjust_args(need_device_ptr:X,Y)
void cblas_caxpy(const MKL_INT N, const void *alpha, const void *X,
                 const MKL_INT incX, void *Y, const MKL_INT incY) NOTHROW;

#pragma omp declare variant (MKL_CBLAS_VARIANT_NAME(crotg)) match(construct={dispatch}, device={arch(gen)}) \
    append_args(interop(prefer_type("sycl","level_zero"),targetsync)) \
    adjust_args(need_device_ptr:a,b,c,s)
void cblas_crotg(void *a, const void *b, float *c, void *s) NOTHROW;

#pragma omp declare variant (MKL_CBLAS_VARIANT_NAME(zswap)) match(construct={dispatch}, device={arch(gen)}) \
    append_args(interop(prefer_type("sycl","level_zero"),targetsync)) \
    adjust_args(need_device_ptr:X,Y)
void cblas_zswap(const MKL_INT N, void *X, const MKL_INT incX,
                 void *Y, const MKL_INT incY) NOTHROW;

#pragma omp declare variant (MKL_CBLAS_VARIANT_NAME(zcopy)) match(construct={dispatch}, device={arch(gen)}) \
    append_args(interop(prefer_type("sycl","level_zero"),targetsync)) \
    adjust_args(need_device_ptr:X,Y)
void cblas_zcopy(const MKL_INT N, const void *X, const MKL_INT incX,
                 void *Y, const MKL_INT incY) NOTHROW;

#pragma omp declare variant (MKL_CBLAS_VARIANT_NAME(zaxpy)) match(construct={dispatch}, device={arch(gen)}) \
    append_args(interop(prefer_type("sycl","level_zero"),targetsync)) \
    adjust_args(need_device_ptr:X,Y)
void cblas_zaxpy(const MKL_INT N, const void *alpha, const void *X,
                 const MKL_INT incX, void *Y, const MKL_INT incY) NOTHROW;

#pragma omp declare variant (MKL_CBLAS_VARIANT_NAME(zrotg)) match(construct={dispatch}, device={arch(gen)}) \
    append_args(interop(prefer_type("sycl","level_zero"),targetsync)) \
    adjust_args(need_device_ptr:a,b,c,s)
void cblas_zrotg(void *a, const void *b, double *c, void *s) NOTHROW;

// Routines with S, D prefixes
#pragma omp declare variant (MKL_CBLAS_VARIANT_NAME(srotmg)) match(construct={dispatch}, device={arch(gen)}) \
    append_args(interop(prefer_type("sycl","level_zero"),targetsync)) \
    adjust_args(need_device_ptr:d1,d2,b1,P)
void cblas_srotmg(float *d1, float *d2, float *b1, const float b2, float *P) NOTHROW;

#pragma omp declare variant (MKL_CBLAS_VARIANT_NAME(srot)) match(construct={dispatch}, device={arch(gen)}) \
    append_args(interop(prefer_type("sycl","level_zero"),targetsync)) \
    adjust_args(need_device_ptr:X,Y)
void cblas_srot(const MKL_INT N, float *X, const MKL_INT incX,
                float *Y, const MKL_INT incY, const float c, const float s) NOTHROW;

#pragma omp declare variant (MKL_CBLAS_VARIANT_NAME(srotm)) match(construct={dispatch}, device={arch(gen)}) \
    append_args(interop(prefer_type("sycl","level_zero"),targetsync)) \
    adjust_args(need_device_ptr:X,Y,P)
void cblas_srotm(const MKL_INT N, float *X, const MKL_INT incX,
                 float *Y, const MKL_INT incY, const float *P) NOTHROW;

#pragma omp declare variant (MKL_CBLAS_VARIANT_NAME(drotmg)) match(construct={dispatch}, device={arch(gen)}) \
    append_args(interop(prefer_type("sycl","level_zero"),targetsync)) \
    adjust_args(need_device_ptr:d1,d2,b1,P)
void cblas_drotmg(double *d1, double *d2, double *b1, const double b2, double *P) NOTHROW;

#pragma omp declare variant (MKL_CBLAS_VARIANT_NAME(drot)) match(construct={dispatch}, device={arch(gen)}) \
    append_args(interop(prefer_type("sycl","level_zero"),targetsync)) \
    adjust_args(need_device_ptr:X,Y)
void cblas_drot(const MKL_INT N, double *X, const MKL_INT incX,
                double *Y, const MKL_INT incY, const double c, const double  s) NOTHROW;

#pragma omp declare variant (MKL_CBLAS_VARIANT_NAME(drotm)) match(construct={dispatch}, device={arch(gen)}) \
    append_args(interop(prefer_type("sycl","level_zero"),targetsync)) \
    adjust_args(need_device_ptr:X,Y,P)
void cblas_drotm(const MKL_INT N, double *X, const MKL_INT incX,
                 double *Y, const MKL_INT incY, const double *P) NOTHROW;

// Routines with CS, ZD prefixes
#pragma omp declare variant (MKL_CBLAS_VARIANT_NAME(csrot)) match(construct={dispatch}, device={arch(gen)}) \
    append_args(interop(prefer_type("sycl","level_zero"),targetsync)) \
    adjust_args(need_device_ptr:X,Y)
void cblas_csrot(const MKL_INT N, void *X, const MKL_INT incX,
                 void *Y, const MKL_INT incY, const float c, const float s) NOTHROW;

#pragma omp declare variant (MKL_CBLAS_VARIANT_NAME(zdrot)) match(construct={dispatch}, device={arch(gen)}) \
    append_args(interop(prefer_type("sycl","level_zero"),targetsync)) \
    adjust_args(need_device_ptr:X,Y)
void cblas_zdrot(const MKL_INT N, void *X, const MKL_INT incX,
                 void *Y, const MKL_INT incY, const double c, const double s) NOTHROW;

// Routines with S D C Z CS and ZD prefixes
#pragma omp declare variant (MKL_CBLAS_VARIANT_NAME(sscal)) match(construct={dispatch}, device={arch(gen)}) \
    append_args(interop(prefer_type("sycl","level_zero"),targetsync)) \
    adjust_args(need_device_ptr:X)
void cblas_sscal(const MKL_INT N, const float alpha, float *X, const MKL_INT incX) NOTHROW;

#pragma omp declare variant (MKL_CBLAS_VARIANT_NAME(dscal)) match(construct={dispatch}, device={arch(gen)}) \
    append_args(interop(prefer_type("sycl","level_zero"),targetsync)) \
    adjust_args(need_device_ptr:X)
void cblas_dscal(const MKL_INT N, const double alpha, double *X, const MKL_INT incX) NOTHROW;

#pragma omp declare variant (MKL_CBLAS_VARIANT_NAME(cscal)) match(construct={dispatch}, device={arch(gen)}) \
    append_args(interop(prefer_type("sycl","level_zero"),targetsync)) \
    adjust_args(need_device_ptr:X)
void cblas_cscal(const MKL_INT N, const void *alpha, void *X, const MKL_INT incX) NOTHROW;

#pragma omp declare variant (MKL_CBLAS_VARIANT_NAME(zscal)) match(construct={dispatch}, device={arch(gen)}) \
    append_args(interop(prefer_type("sycl","level_zero"),targetsync)) \
    adjust_args(need_device_ptr:X)
void cblas_zscal(const MKL_INT N, const void *alpha, void *X, const MKL_INT incX) NOTHROW;

#pragma omp declare variant (MKL_CBLAS_VARIANT_NAME(csscal)) match(construct={dispatch}, device={arch(gen)}) \
    append_args(interop(prefer_type("sycl","level_zero"),targetsync)) \
    adjust_args(need_device_ptr:X)
void cblas_csscal(const MKL_INT N, const float alpha, void *X, const MKL_INT incX) NOTHROW;

#pragma omp declare variant (MKL_CBLAS_VARIANT_NAME(zdscal)) match(construct={dispatch}, device={arch(gen)}) \
    append_args(interop(prefer_type("sycl","level_zero"),targetsync)) \
    adjust_args(need_device_ptr:X)
void cblas_zdscal(const MKL_INT N, const double alpha, void *X, const MKL_INT incX) NOTHROW;

#pragma omp declare variant (MKL_CBLAS_VARIANT_NAME(crot)) match(construct={dispatch}, device={arch(gen)}) \
    append_args(interop(prefer_type("sycl","level_zero"),targetsync)) \
    adjust_args(need_device_ptr:X,Y)
void cblas_crot(const MKL_INT N, void *X, const MKL_INT incX,
                 void *Y, const MKL_INT incY, const float c, const void* s) NOTHROW;

#pragma omp declare variant (MKL_CBLAS_VARIANT_NAME(zrot)) match(construct={dispatch}, device={arch(gen)}) \
    append_args(interop(prefer_type("sycl","level_zero"),targetsync)) \
    adjust_args(need_device_ptr:X,Y)
void cblas_zrot(const MKL_INT N, void *X, const MKL_INT incX,
                 void *Y, const MKL_INT incY, const double c, const void* s) NOTHROW;

// BLAS API

// Level3

// Routines with S, D, C, Z prefixes (Standard)
#pragma omp declare variant (MKL_BLAS_VARIANT_NAME(sgemm)) match(construct={dispatch}, device={arch(gen)}) \
    append_args(interop(prefer_type("sycl","level_zero"),targetsync)) \
    adjust_args(need_device_ptr:a,b,c)
void sgemm(const char *transa, const char *transb,
           const MKL_INT *m, const MKL_INT *n, const MKL_INT *k,
           const float *alpha, const float *a, const MKL_INT *lda,
           const float *b, const MKL_INT *ldb,
           const float *beta, float *c, const MKL_INT *ldc) NOTHROW;

#pragma omp declare variant (MKL_BLAS_VARIANT_NAME(sgemmt)) match(construct={dispatch}, device={arch(gen)}) \
    append_args(interop(prefer_type("sycl","level_zero"),targetsync)) \
    adjust_args(need_device_ptr:a,b,c)
void sgemmt(const char *uplo, const char *transa, const char *transb,
            const MKL_INT *n, const MKL_INT *k,
            const float *alpha, const float *a, const MKL_INT *lda,
            const float *b, const MKL_INT *ldb,
            const float *beta, float *c, const MKL_INT *ldc) NOTHROW;

#pragma omp declare variant (MKL_BLAS_VARIANT_NAME(ssymm)) match(construct={dispatch}, device={arch(gen)}) \
    append_args(interop(prefer_type("sycl","level_zero"),targetsync)) \
    adjust_args(need_device_ptr:a,b,c)
void ssymm(const char *side, const char *uplo,
           const MKL_INT *m, const MKL_INT *n,
           const float *alpha, const float *a, const MKL_INT *lda,
           const float *b, const MKL_INT *ldb,
           const float *beta, float *c, const MKL_INT *ldc) NOTHROW;

#pragma omp declare variant (MKL_BLAS_VARIANT_NAME(ssyr2k)) match(construct={dispatch}, device={arch(gen)}) \
    append_args(interop(prefer_type("sycl","level_zero"),targetsync)) \
    adjust_args(need_device_ptr:a,b,c)
void ssyr2k(const char *uplo, const char *trans,
            const MKL_INT *n, const MKL_INT *k,
            const float *alpha, const float *a, const MKL_INT *lda,
            const float *b, const MKL_INT *ldb,
            const float *beta, float *c, const MKL_INT *ldc) NOTHROW;

#pragma omp declare variant (MKL_BLAS_VARIANT_NAME(ssyrk)) match(construct={dispatch}, device={arch(gen)}) \
    append_args(interop(prefer_type("sycl","level_zero"),targetsync)) \
    adjust_args(need_device_ptr:a,c)
void ssyrk(const char *uplo, const char *trans,
           const MKL_INT *n, const MKL_INT *k,
           const float *alpha, const float *a, const MKL_INT *lda,
           const float *beta,
           float *c, const MKL_INT *ldc) NOTHROW;

#pragma omp declare variant (MKL_BLAS_VARIANT_NAME(strmm)) match(construct={dispatch}, device={arch(gen)}) \
    append_args(interop(prefer_type("sycl","level_zero"),targetsync)) \
    adjust_args(need_device_ptr:a,b)
void strmm(const char *side, const char *uplo, const char *transa,
           const char *diag, const MKL_INT *m, const MKL_INT *n,
           const float *alpha, const float *a, const MKL_INT *lda,
           float *b, const MKL_INT *ldb) NOTHROW;

#pragma omp declare variant (MKL_BLAS_VARIANT_NAME(strmm_oop)) match(construct={dispatch}, device={arch(gen)}) \
    append_args(interop(prefer_type("sycl","level_zero"),targetsync)) \
    adjust_args(need_device_ptr:a,b,c)
void strmm_oop(const char *side, const char *uplo, const char *transa,
               const char *diag, const MKL_INT *m, const MKL_INT *n,
               const float *alpha, const float *a, const MKL_INT *lda,
               const float *b, const MKL_INT *ldb, const float *beta,
               float *c, const MKL_INT *ldc) NOTHROW;

#pragma omp declare variant (MKL_BLAS_VARIANT_NAME(strsm)) match(construct={dispatch}, device={arch(gen)}) \
    append_args(interop(prefer_type("sycl","level_zero"),targetsync)) \
    adjust_args(need_device_ptr:a,b)
void strsm(const char *side, const char *uplo, const char *transa,
           const char *diag, const MKL_INT *m, const MKL_INT *n,
           const float *alpha, const float *a, const MKL_INT *lda,
           float *b, const MKL_INT *ldb) NOTHROW;

#pragma omp declare variant (MKL_BLAS_VARIANT_NAME(strsm_oop)) match(construct={dispatch}, device={arch(gen)}) \
    append_args(interop(prefer_type("sycl","level_zero"),targetsync)) \
    adjust_args(need_device_ptr:a,b,c)
void strsm_oop(const char *side, const char *uplo, const char *transa,
               const char *diag, const MKL_INT *m, const MKL_INT *n,
               const float *alpha, const float *a, const MKL_INT *lda,
               const float *b, const MKL_INT *ldb, const float *beta,
               float *c, const MKL_INT *ldc) NOTHROW;

#pragma omp declare variant (MKL_BLAS_VARIANT_NAME(dgemm)) match(construct={dispatch}, device={arch(gen)}) \
    append_args(interop(prefer_type("sycl","level_zero"),targetsync)) \
    adjust_args(need_device_ptr:a,b,c)
void dgemm(const char *transa, const char *transb,
           const MKL_INT *m, const MKL_INT *n, const MKL_INT *k,
           const double *alpha, const double *a, const MKL_INT *lda,
           const double *b, const MKL_INT *ldb,
           const double *beta, double *c, const MKL_INT *ldc) NOTHROW;

#pragma omp declare variant (MKL_BLAS_VARIANT_NAME(dgemmt)) match(construct={dispatch}, device={arch(gen)}) \
    append_args(interop(prefer_type("sycl","level_zero"),targetsync)) \
    adjust_args(need_device_ptr:a,b,c)
void dgemmt(const char *uplo, const char *transa, const char *transb,
            const MKL_INT *n, const MKL_INT *k,
            const double *alpha, const double *a, const MKL_INT *lda,
            const double *b, const MKL_INT *ldb,
            const double *beta, double *c, const MKL_INT *ldc) NOTHROW;

#pragma omp declare variant (MKL_BLAS_VARIANT_NAME(dsymm)) match(construct={dispatch}, device={arch(gen)}) \
    append_args(interop(prefer_type("sycl","level_zero"),targetsync)) \
    adjust_args(need_device_ptr:a,b,c)
void dsymm(const char *side, const char *uplo,
           const MKL_INT *m, const MKL_INT *n,
           const double *alpha, const double *a, const MKL_INT *lda,
           const double *b, const MKL_INT *ldb,
           const double *beta, double *c, const MKL_INT *ldc) NOTHROW;

#pragma omp declare variant (MKL_BLAS_VARIANT_NAME(dsyr2k)) match(construct={dispatch}, device={arch(gen)}) \
    append_args(interop(prefer_type("sycl","level_zero"),targetsync)) \
    adjust_args(need_device_ptr:a,b,c)
void dsyr2k(const char *uplo, const char *trans,
            const MKL_INT *n, const MKL_INT *k,
            const double *alpha, const double *a, const MKL_INT *lda,
            const double *b, const MKL_INT *ldb,
            const double *beta, double *c, const MKL_INT *ldc) NOTHROW;

#pragma omp declare variant (MKL_BLAS_VARIANT_NAME(dsyrk)) match(construct={dispatch}, device={arch(gen)}) \
    append_args(interop(prefer_type("sycl","level_zero"),targetsync)) \
    adjust_args(need_device_ptr:a,c)
void dsyrk(const char *uplo, const char *trans,
           const MKL_INT *n, const MKL_INT *k,
           const double *alpha, const double *a,
           const MKL_INT *lda, const double *beta,
           double *c, const MKL_INT *ldc) NOTHROW;

#pragma omp declare variant (MKL_BLAS_VARIANT_NAME(dtrmm)) match(construct={dispatch}, device={arch(gen)}) \
    append_args(interop(prefer_type("sycl","level_zero"),targetsync)) \
    adjust_args(need_device_ptr:a,b)
void dtrmm(const char *side, const char *uplo, const char *transa,
           const char *diag, const MKL_INT *m, const MKL_INT *n,
           const double *alpha, const double *a, const MKL_INT *lda,
           double *b, const MKL_INT *ldb) NOTHROW;

#pragma omp declare variant (MKL_BLAS_VARIANT_NAME(dtrmm_oop)) match(construct={dispatch}, device={arch(gen)}) \
    append_args(interop(prefer_type("sycl","level_zero"),targetsync)) \
    adjust_args(need_device_ptr:a,b,c)
void dtrmm_oop(const char *side, const char *uplo, const char *transa,
               const char *diag, const MKL_INT *m, const MKL_INT *n,
               const double *alpha, const double *a, const MKL_INT *lda,
               const double *b, const MKL_INT *ldb, const double *beta,
               double *c, const MKL_INT *ldc) NOTHROW;

#pragma omp declare variant (MKL_BLAS_VARIANT_NAME(dtrsm)) match(construct={dispatch}, device={arch(gen)}) \
    append_args(interop(prefer_type("sycl","level_zero"),targetsync)) \
    adjust_args(need_device_ptr:a,b)
void dtrsm(const char *side, const char *uplo, const char *transa,
           const char *diag, const MKL_INT *m, const MKL_INT *n,
           const double *alpha, const double *a, const MKL_INT *lda,
           double *b, const MKL_INT *ldb) NOTHROW;

#pragma omp declare variant (MKL_BLAS_VARIANT_NAME(dtrsm_oop)) match(construct={dispatch}, device={arch(gen)}) \
    append_args(interop(prefer_type("sycl","level_zero"),targetsync)) \
    adjust_args(need_device_ptr:a,b,c)
void dtrsm_oop(const char *side, const char *uplo, const char *transa,
               const char *diag, const MKL_INT *m, const MKL_INT *n,
               const double *alpha, const double *a, const MKL_INT *lda,
               const double *b, const MKL_INT *ldb, const double *beta,
               double *c, const MKL_INT *ldc) NOTHROW;

#pragma omp declare variant (MKL_BLAS_VARIANT_NAME(cgemm)) match(construct={dispatch}, device={arch(gen)}) \
    append_args(interop(prefer_type("sycl","level_zero"),targetsync)) \
    adjust_args(need_device_ptr:a,b,c)
void cgemm(const char *transa, const char *transb,
           const MKL_INT *m, const MKL_INT *n, const MKL_INT *k,
           const MKL_Complex8 *alpha, const MKL_Complex8 *a, const MKL_INT *lda,
           const MKL_Complex8 *b, const MKL_INT *ldb, const MKL_Complex8 *beta,
           MKL_Complex8 *c, const MKL_INT *ldc) NOTHROW;

#pragma omp declare variant (MKL_BLAS_VARIANT_NAME(cgemm3m)) match(construct={dispatch}, device={arch(gen)}) \
    append_args(interop(prefer_type("sycl","level_zero"),targetsync)) \
    adjust_args(need_device_ptr:a,b,c)
void cgemm3m(const char *transa, const char *transb,
           const MKL_INT *m, const MKL_INT *n, const MKL_INT *k,
           const MKL_Complex8 *alpha, const MKL_Complex8 *a, const MKL_INT *lda,
           const MKL_Complex8 *b, const MKL_INT *ldb, const MKL_Complex8 *beta,
           MKL_Complex8 *c, const MKL_INT *ldc) NOTHROW;

#pragma omp declare variant (MKL_BLAS_VARIANT_NAME(cgemmt)) match(construct={dispatch}, device={arch(gen)}) \
    append_args(interop(prefer_type("sycl","level_zero"),targetsync)) \
    adjust_args(need_device_ptr:a,b,c)
void cgemmt(const char *uplo, const char *transa, const char *transb,
            const MKL_INT *n, const MKL_INT *k,
            const MKL_Complex8 *alpha, const MKL_Complex8 *a, const MKL_INT *lda,
            const MKL_Complex8 *b, const MKL_INT *ldb, const MKL_Complex8 *beta,
            MKL_Complex8 *c, const MKL_INT *ldc) NOTHROW;

#pragma omp declare variant (MKL_BLAS_VARIANT_NAME(csymm)) match(construct={dispatch}, device={arch(gen)}) \
    append_args(interop(prefer_type("sycl","level_zero"),targetsync)) \
    adjust_args(need_device_ptr:a,b,c)
void csymm(const char *side, const char *uplo,
           const MKL_INT *m, const MKL_INT *n,
           const MKL_Complex8 *alpha, const MKL_Complex8 *a, const MKL_INT *lda,
           const MKL_Complex8 *b, const MKL_INT *ldb, const MKL_Complex8 *beta,
           MKL_Complex8 *c, const MKL_INT *ldc) NOTHROW;

#pragma omp declare variant (MKL_BLAS_VARIANT_NAME(csyr2k)) match(construct={dispatch}, device={arch(gen)}) \
    append_args(interop(prefer_type("sycl","level_zero"),targetsync)) \
    adjust_args(need_device_ptr:a,b,c)
void csyr2k(const char *uplo, const char *trans,
            const MKL_INT *n, const MKL_INT *k,
            const MKL_Complex8 *alpha, const MKL_Complex8 *a, const MKL_INT *lda,
            const MKL_Complex8 *b, const MKL_INT *ldb, const MKL_Complex8 *beta,
            MKL_Complex8 *c, const MKL_INT *ldc) NOTHROW;

#pragma omp declare variant (MKL_BLAS_VARIANT_NAME(csyrk)) match(construct={dispatch}, device={arch(gen)}) \
    append_args(interop(prefer_type("sycl","level_zero"),targetsync)) \
    adjust_args(need_device_ptr:a,c)
void csyrk(const char *uplo, const char *trans,
           const MKL_INT *n, const MKL_INT *k,
           const MKL_Complex8 *alpha, const MKL_Complex8 *a, const MKL_INT *lda,
           const MKL_Complex8 *beta, MKL_Complex8 *c, const MKL_INT *ldc) NOTHROW;

#pragma omp declare variant (MKL_BLAS_VARIANT_NAME(ctrmm)) match(construct={dispatch}, device={arch(gen)}) \
    append_args(interop(prefer_type("sycl","level_zero"),targetsync)) \
    adjust_args(need_device_ptr:a,b)
void ctrmm(const char *side, const char *uplo, const char *transa,
           const char *diag, const MKL_INT *m, const MKL_INT *n,
           const MKL_Complex8 *alpha, const MKL_Complex8 *a, const MKL_INT *lda,
           MKL_Complex8 *b, const MKL_INT *ldb) NOTHROW;

#pragma omp declare variant (MKL_BLAS_VARIANT_NAME(ctrmm_oop)) match(construct={dispatch}, device={arch(gen)}) \
    append_args(interop(prefer_type("sycl","level_zero"),targetsync)) \
    adjust_args(need_device_ptr:a,b,c)
void ctrmm_oop(const char *side, const char *uplo, const char *transa,
               const char *diag, const MKL_INT *m, const MKL_INT *n,
               const MKL_Complex8 *alpha, const MKL_Complex8 *a, const MKL_INT *lda,
               const MKL_Complex8 *b, const MKL_INT *ldb, const MKL_Complex8 *beta,
               MKL_Complex8 *c, const MKL_INT *ldc) NOTHROW;

#pragma omp declare variant (MKL_BLAS_VARIANT_NAME(ctrsm)) match(construct={dispatch}, device={arch(gen)}) \
    append_args(interop(prefer_type("sycl","level_zero"),targetsync)) \
    adjust_args(need_device_ptr:a,b)
void ctrsm(const char *side, const char *uplo, const char *transa,
           const char *diag, const MKL_INT *m, const MKL_INT *n,
           const MKL_Complex8 *alpha, const MKL_Complex8 *a, const MKL_INT *lda,
           MKL_Complex8 *b, const MKL_INT *ldb) NOTHROW;

#pragma omp declare variant (MKL_BLAS_VARIANT_NAME(ctrsm_oop)) match(construct={dispatch}, device={arch(gen)}) \
    append_args(interop(prefer_type("sycl","level_zero"),targetsync)) \
    adjust_args(need_device_ptr:a,b,c)
void ctrsm_oop(const char *side, const char *uplo, const char *transa,
               const char *diag, const MKL_INT *m, const MKL_INT *n,
               const MKL_Complex8 *alpha, const MKL_Complex8 *a, const MKL_INT *lda,
               const MKL_Complex8 *b, const MKL_INT *ldb, const MKL_Complex8 *beta,
               MKL_Complex8 *c, const MKL_INT *ldc) NOTHROW;

#pragma omp declare variant (MKL_BLAS_VARIANT_NAME(zgemm)) match(construct={dispatch}, device={arch(gen)}) \
    append_args(interop(prefer_type("sycl","level_zero"),targetsync)) \
    adjust_args(need_device_ptr:a,b,c)
void zgemm(const char *transa, const char *transb,
           const MKL_INT *m, const MKL_INT *n, const MKL_INT *k,
           const MKL_Complex16 *alpha, const MKL_Complex16 *a, const MKL_INT *lda,
           const MKL_Complex16 *b, const MKL_INT *ldb, const MKL_Complex16 *beta,
           MKL_Complex16 *c, const MKL_INT *ldc) NOTHROW;

#pragma omp declare variant (MKL_BLAS_VARIANT_NAME(zgemm3m)) match(construct={dispatch}, device={arch(gen)}) \
    append_args(interop(prefer_type("sycl","level_zero"),targetsync)) \
    adjust_args(need_device_ptr:a,b,c)
void zgemm3m(const char *transa, const char *transb,
           const MKL_INT *m, const MKL_INT *n, const MKL_INT *k,
           const MKL_Complex16 *alpha, const MKL_Complex16 *a, const MKL_INT *lda,
           const MKL_Complex16 *b, const MKL_INT *ldb, const MKL_Complex16 *beta,
           MKL_Complex16 *c, const MKL_INT *ldc) NOTHROW;

#pragma omp declare variant (MKL_BLAS_VARIANT_NAME(zgemmt)) match(construct={dispatch}, device={arch(gen)}) \
    append_args(interop(prefer_type("sycl","level_zero"),targetsync)) \
    adjust_args(need_device_ptr:a,b,c)
void zgemmt(const char *uplo, const char *transa, const char *transb,
            const MKL_INT *n, const MKL_INT *k,
            const MKL_Complex16 *alpha, const MKL_Complex16 *a, const MKL_INT *lda,
            const MKL_Complex16 *b, const MKL_INT *ldb, const MKL_Complex16 *beta,
            MKL_Complex16 *c, const MKL_INT *ldc) NOTHROW;

#pragma omp declare variant (MKL_BLAS_VARIANT_NAME(zsymm)) match(construct={dispatch}, device={arch(gen)}) \
    append_args(interop(prefer_type("sycl","level_zero"),targetsync)) \
    adjust_args(need_device_ptr:a,b,c)
void zsymm(const char *side, const char *uplo,
           const MKL_INT *m, const MKL_INT *n,
           const MKL_Complex16 *alpha, const MKL_Complex16 *a, const MKL_INT *lda,
           const MKL_Complex16 *b, const MKL_INT *ldb, const MKL_Complex16 *beta,
           MKL_Complex16 *c, const MKL_INT *ldc) NOTHROW;

#pragma omp declare variant (MKL_BLAS_VARIANT_NAME(zsyr2k)) match(construct={dispatch}, device={arch(gen)}) \
    append_args(interop(prefer_type("sycl","level_zero"),targetsync)) \
    adjust_args(need_device_ptr:a,b,c)
void zsyr2k(const char *uplo, const char *trans,
            const MKL_INT *n, const MKL_INT *k,
            const MKL_Complex16 *alpha, const MKL_Complex16 *a, const MKL_INT *lda,
            const MKL_Complex16 *b, const MKL_INT *ldb, const MKL_Complex16 *beta,
            MKL_Complex16 *c, const MKL_INT *ldc) NOTHROW;

#pragma omp declare variant (MKL_BLAS_VARIANT_NAME(zsyrk)) match(construct={dispatch}, device={arch(gen)}) \
    append_args(interop(prefer_type("sycl","level_zero"),targetsync)) \
    adjust_args(need_device_ptr:a,c)
void zsyrk(const char *uplo, const char *trans,
           const MKL_INT *n, const MKL_INT *k,
           const MKL_Complex16 *alpha, const MKL_Complex16 *a, const MKL_INT *lda,
           const MKL_Complex16 *beta, MKL_Complex16 *c, const MKL_INT *ldc) NOTHROW;

#pragma omp declare variant (MKL_BLAS_VARIANT_NAME(ztrmm)) match(construct={dispatch}, device={arch(gen)}) \
    append_args(interop(prefer_type("sycl","level_zero"),targetsync)) \
    adjust_args(need_device_ptr:a,b)
void ztrmm(const char *side, const char *uplo, const char *transa,
           const char *diag, const MKL_INT *m, const MKL_INT *n,
           const MKL_Complex16 *alpha, const MKL_Complex16 *a, const MKL_INT *lda,
           MKL_Complex16 *b, const MKL_INT *ldb) NOTHROW;

#pragma omp declare variant (MKL_BLAS_VARIANT_NAME(ztrmm_oop)) match(construct={dispatch}, device={arch(gen)}) \
    append_args(interop(prefer_type("sycl","level_zero"),targetsync)) \
    adjust_args(need_device_ptr:a,b,c)
void ztrmm_oop(const char *side, const char *uplo, const char *transa,
               const char *diag, const MKL_INT *m, const MKL_INT *n,
               const MKL_Complex16 *alpha, const MKL_Complex16 *a, const MKL_INT *lda,
               const MKL_Complex16 *b, const MKL_INT *ldb, const MKL_Complex16 *beta,
               MKL_Complex16 *c, const MKL_INT *ldc) NOTHROW;

#pragma omp declare variant (MKL_BLAS_VARIANT_NAME(ztrsm)) match(construct={dispatch}, device={arch(gen)}) \
    append_args(interop(prefer_type("sycl","level_zero"),targetsync)) \
    adjust_args(need_device_ptr:a,b)
void ztrsm(const char *side, const char *uplo, const char *transa,
           const char *diag, const MKL_INT *m, const MKL_INT *n,
           const MKL_Complex16 *alpha, const MKL_Complex16 *a, const MKL_INT *lda,
           MKL_Complex16 *b, const MKL_INT *ldb) NOTHROW;

#pragma omp declare variant (MKL_BLAS_VARIANT_NAME(ztrsm_oop)) match(construct={dispatch}, device={arch(gen)}) \
    append_args(interop(prefer_type("sycl","level_zero"),targetsync)) \
    adjust_args(need_device_ptr:a,b,c)
void ztrsm_oop(const char *side, const char *uplo, const char *transa,
               const char *diag, const MKL_INT *m, const MKL_INT *n,
               const MKL_Complex16 *alpha, const MKL_Complex16 *a, const MKL_INT *lda,
               const MKL_Complex16 *b, const MKL_INT *ldb, const MKL_Complex16 *beta,
               MKL_Complex16 *c, const MKL_INT *ldc) NOTHROW;

// Routines with C, Z prefixes

#pragma omp declare variant (MKL_BLAS_VARIANT_NAME(chemm)) match(construct={dispatch}, device={arch(gen)}) \
    append_args(interop(prefer_type("sycl","level_zero"),targetsync)) \
    adjust_args(need_device_ptr:a,b,c)
void chemm(const char *side, const char *uplo, const MKL_INT *m, const MKL_INT *n,
           const MKL_Complex8 *alpha, const MKL_Complex8 *a, const MKL_INT *lda,
           const MKL_Complex8 *b, const MKL_INT *ldb, const MKL_Complex8 *beta,
           MKL_Complex8 *c, const MKL_INT *ldc) NOTHROW;

#pragma omp declare variant (MKL_BLAS_VARIANT_NAME(cher2k)) match(construct={dispatch}, device={arch(gen)}) \
    append_args(interop(prefer_type("sycl","level_zero"),targetsync)) \
    adjust_args(need_device_ptr:a,b,c)
void cher2k(const char *uplo, const char *trans, const MKL_INT *n, const MKL_INT *k,
            const MKL_Complex8 *alpha, const MKL_Complex8 *a, const MKL_INT *lda,
            const MKL_Complex8 *b, const MKL_INT *ldb, const float *beta,
            MKL_Complex8 *c, const MKL_INT *ldc) NOTHROW;

#pragma omp declare variant (MKL_BLAS_VARIANT_NAME(cherk)) match(construct={dispatch}, device={arch(gen)}) \
    append_args(interop(prefer_type("sycl","level_zero"),targetsync)) \
    adjust_args(need_device_ptr:a,c)
void cherk(const char *uplo, const char *trans, const MKL_INT *n, const MKL_INT *k,
           const float *alpha, const MKL_Complex8 *a, const MKL_INT *lda, const float *beta,
           MKL_Complex8 *c, const MKL_INT *ldc) NOTHROW;

#pragma omp declare variant (MKL_BLAS_VARIANT_NAME(zhemm)) match(construct={dispatch}, device={arch(gen)}) \
    append_args(interop(prefer_type("sycl","level_zero"),targetsync)) \
    adjust_args(need_device_ptr:a,b,c)
void zhemm(const char *side, const char *uplo, const MKL_INT *m, const MKL_INT *n,
           const MKL_Complex16 *alpha, const MKL_Complex16 *a, const MKL_INT *lda,
           const MKL_Complex16 *b, const MKL_INT *ldb, const MKL_Complex16 *beta,
           MKL_Complex16 *c, const MKL_INT *ldc) NOTHROW;

#pragma omp declare variant (MKL_BLAS_VARIANT_NAME(zher2k)) match(construct={dispatch}, device={arch(gen)}) \
    append_args(interop(prefer_type("sycl","level_zero"),targetsync)) \
    adjust_args(need_device_ptr:a,b,c)
void zher2k(const char *uplo, const char *trans, const MKL_INT *n, const MKL_INT *k,
            const MKL_Complex16 *alpha, const MKL_Complex16 *a, const MKL_INT *lda,
            const MKL_Complex16 *b, const MKL_INT *ldb, const double *beta,
            MKL_Complex16 *c, const MKL_INT *ldc) NOTHROW;

#pragma omp declare variant (MKL_BLAS_VARIANT_NAME(zherk)) match(construct={dispatch}, device={arch(gen)}) \
    append_args(interop(prefer_type("sycl","level_zero"),targetsync)) \
    adjust_args(need_device_ptr:a,c)
void zherk(const char *uplo, const char *trans, const MKL_INT *n, const MKL_INT *k,
           const double *alpha, const MKL_Complex16 *a, const MKL_INT *lda,
           const double *beta, MKL_Complex16 *c, const MKL_INT *ldc) NOTHROW;

// Other precisions

#pragma omp declare variant (MKL_BLAS_VARIANT_NAME(hgemm)) match(construct={dispatch}, device={arch(gen)}) \
    append_args(interop(prefer_type("sycl","level_zero"),targetsync)) \
    adjust_args(need_device_ptr:a,b,c)
void hgemm(const char *transa, const char *transb,
           const MKL_INT *m, const MKL_INT *n, const MKL_INT *k,
           const MKL_F16 *alpha, const MKL_F16 *a, const MKL_INT *lda,
           const MKL_F16 *b, const MKL_INT *ldb,
           const MKL_F16 *beta, MKL_F16 *c, const MKL_INT *ldc) NOTHROW;

#pragma omp declare variant (MKL_BLAS_VARIANT_NAME(gemm_f16f16f32)) match(construct={dispatch}, device={arch(gen)}) \
    append_args(interop(prefer_type("sycl","level_zero"),targetsync)) \
    adjust_args(need_device_ptr:a,b,c)
void gemm_f16f16f32(const char *transa, const char *transb,
                    const MKL_INT *m, const MKL_INT *n, const MKL_INT *k,
                    const float *alpha, const MKL_F16 *a, const MKL_INT *lda,
                    const MKL_F16 *b, const MKL_INT *ldb,
                    const float *beta, float *c, const MKL_INT *ldc) NOTHROW;

#pragma omp declare variant (MKL_BLAS_VARIANT_NAME(gemm_bf16bf16f32)) match(construct={dispatch}, device={arch(gen)}) \
    append_args(interop(prefer_type("sycl","level_zero"),targetsync)) \
    adjust_args(need_device_ptr:a,b,c)
void gemm_bf16bf16f32(const char *transa, const char *transb,
                    const MKL_INT *m, const MKL_INT *n, const MKL_INT *k,
                    const float *alpha, const MKL_BF16 *a, const MKL_INT *lda,
                    const MKL_BF16 *b, const MKL_INT *ldb,
                    const float *beta, float *c, const MKL_INT *ldc) NOTHROW;

#pragma omp declare variant (MKL_BLAS_VARIANT_NAME(gemm_s8u8s32)) match(construct={dispatch}, device={arch(gen)}) \
    append_args(interop(prefer_type("sycl","level_zero"),targetsync)) \
    adjust_args(need_device_ptr:a,b,c,co)
void gemm_s8u8s32(const char *transa, const char *transb, const char *offsetc,
                  const MKL_INT *m, const MKL_INT *n, const MKL_INT *k,
                  const float *alpha, const MKL_INT8 *a, const MKL_INT *lda, const MKL_INT8 *ao,
                  const MKL_UINT8 *b, const MKL_INT *ldb, const MKL_INT8 *bo,
                  const float *beta, MKL_INT32 *c, const MKL_INT *ldc, const MKL_INT32 *co) NOTHROW;

// Level2

// Routines with S, D, C, Z prefixes (Standard)
#pragma omp declare variant (MKL_BLAS_VARIANT_NAME(sgemv)) match(construct={dispatch}, device={arch(gen)}) \
    append_args(interop(prefer_type("sycl","level_zero"),targetsync)) \
    adjust_args(need_device_ptr:a,x,y)
void sgemv(const char *trans, const MKL_INT *m, const MKL_INT *n,
           const float *alpha, const float *a, const MKL_INT *lda,
           const float *x, const MKL_INT *incx,
           const float *beta, float *y, const MKL_INT *incy) NOTHROW;

#pragma omp declare variant (MKL_BLAS_VARIANT_NAME(sgbmv)) match(construct={dispatch}, device={arch(gen)}) \
    append_args(interop(prefer_type("sycl","level_zero"),targetsync)) \
    adjust_args(need_device_ptr:a,x,y)
void sgbmv(const char *trans, const MKL_INT *m, const MKL_INT *n,
           const MKL_INT *kl, const MKL_INT *ku, const float *alpha,
           const float *a, const MKL_INT *lda, const float *x,
           const MKL_INT *incx,
           const float *beta, float *y, const MKL_INT *incy) NOTHROW;

#pragma omp declare variant (MKL_BLAS_VARIANT_NAME(strmv)) match(construct={dispatch}, device={arch(gen)}) \
    append_args(interop(prefer_type("sycl","level_zero"),targetsync)) \
    adjust_args(need_device_ptr:a,x)
void strmv(const char *uplo, const char *transa, const char *diag,
           const MKL_INT *n, const float *a,
           const MKL_INT *lda, float *x, const MKL_INT *incx) NOTHROW;

#pragma omp declare variant (MKL_BLAS_VARIANT_NAME(stbmv)) match(construct={dispatch}, device={arch(gen)}) \
    append_args(interop(prefer_type("sycl","level_zero"),targetsync)) \
    adjust_args(need_device_ptr:a,x)
void stbmv(const char *uplo, const char *trans, const char *diag,
           const MKL_INT *n, const MKL_INT *k, const float *a,
           const MKL_INT *lda, float *x, const MKL_INT *incx) NOTHROW;

#pragma omp declare variant (MKL_BLAS_VARIANT_NAME(stpmv)) match(construct={dispatch}, device={arch(gen)}) \
    append_args(interop(prefer_type("sycl","level_zero"),targetsync)) \
    adjust_args(need_device_ptr:ap,x)
void stpmv(const char *uplo, const char *trans, const char *diag,
           const MKL_INT *n, const float *ap,
           float *x, const MKL_INT *incx) NOTHROW;

#pragma omp declare variant (MKL_BLAS_VARIANT_NAME(strsv)) match(construct={dispatch}, device={arch(gen)}) \
    append_args(interop(prefer_type("sycl","level_zero"),targetsync)) \
    adjust_args(need_device_ptr:a,x)
void strsv(const char *uplo, const char *trans, const char *diag,
           const MKL_INT *n, const float *a, const MKL_INT *lda,
           float *x, const MKL_INT *incx) NOTHROW;

#pragma omp declare variant (MKL_BLAS_VARIANT_NAME(stbsv)) match(construct={dispatch}, device={arch(gen)}) \
    append_args(interop(prefer_type("sycl","level_zero"),targetsync)) \
    adjust_args(need_device_ptr:a,x)
void stbsv(const char *uplo, const char *trans, const char *diag,
           const MKL_INT *n, const MKL_INT *k, const float *a,
           const MKL_INT *lda, float *x, const MKL_INT *incx) NOTHROW;

#pragma omp declare variant (MKL_BLAS_VARIANT_NAME(stpsv)) match(construct={dispatch}, device={arch(gen)}) \
    append_args(interop(prefer_type("sycl","level_zero"),targetsync)) \
    adjust_args(need_device_ptr:ap,x)
void stpsv(const char *uplo, const char *trans, const char *diag,
           const MKL_INT *n, const float *ap,
           float *x, const MKL_INT *incx) NOTHROW;

#pragma omp declare variant (MKL_BLAS_VARIANT_NAME(dgemv)) match(construct={dispatch}, device={arch(gen)}) \
    append_args(interop(prefer_type("sycl","level_zero"),targetsync)) \
    adjust_args(need_device_ptr:a,x,y)
void dgemv(const char *trans, const MKL_INT *m, const MKL_INT *n,
           const double *alpha, const double *a, const MKL_INT *lda,
           const double *x, const MKL_INT *incx,
           const double *beta, double *y, const MKL_INT *incy) NOTHROW;

#pragma omp declare variant (MKL_BLAS_VARIANT_NAME(dgbmv)) match(construct={dispatch}, device={arch(gen)}) \
    append_args(interop(prefer_type("sycl","level_zero"),targetsync)) \
    adjust_args(need_device_ptr:a,x,y)
void dgbmv(const char *trans, const MKL_INT *m, const MKL_INT *n,
           const MKL_INT *kl, const MKL_INT *ku, const double *alpha,
           const double *a, const MKL_INT *lda, const double *x,
           const MKL_INT *incx,
           const double *beta, double *y, const MKL_INT *incy) NOTHROW;

#pragma omp declare variant (MKL_BLAS_VARIANT_NAME(dtrmv)) match(construct={dispatch}, device={arch(gen)}) \
    append_args(interop(prefer_type("sycl","level_zero"),targetsync)) \
    adjust_args(need_device_ptr:a,x)
void dtrmv(const char *uplo, const char *transa, const char *diag,
           const MKL_INT *n, const double *a,
           const MKL_INT *lda, double *x, const MKL_INT *incx) NOTHROW;

#pragma omp declare variant (MKL_BLAS_VARIANT_NAME(dtbmv)) match(construct={dispatch}, device={arch(gen)}) \
    append_args(interop(prefer_type("sycl","level_zero"),targetsync)) \
    adjust_args(need_device_ptr:a,x)
void dtbmv(const char *uplo, const char *trans, const char *diag,
           const MKL_INT *n, const MKL_INT *k, const double *a,
           const MKL_INT *lda, double *x, const MKL_INT *incx) NOTHROW;

#pragma omp declare variant (MKL_BLAS_VARIANT_NAME(dtpmv)) match(construct={dispatch}, device={arch(gen)}) \
    append_args(interop(prefer_type("sycl","level_zero"),targetsync)) \
    adjust_args(need_device_ptr:ap,x)
void dtpmv(const char *uplo, const char *trans, const char *diag,
           const MKL_INT *n, const double *ap,
           double *x, const MKL_INT *incx) NOTHROW;

#pragma omp declare variant (MKL_BLAS_VARIANT_NAME(dtrsv)) match(construct={dispatch}, device={arch(gen)}) \
    append_args(interop(prefer_type("sycl","level_zero"),targetsync)) \
    adjust_args(need_device_ptr:a,x)
void dtrsv(const char *uplo, const char *trans, const char *diag,
           const MKL_INT *n, const double *a, const MKL_INT *lda,
           double *x, const MKL_INT *incx) NOTHROW;

#pragma omp declare variant (MKL_BLAS_VARIANT_NAME(dtbsv)) match(construct={dispatch}, device={arch(gen)}) \
    append_args(interop(prefer_type("sycl","level_zero"),targetsync)) \
    adjust_args(need_device_ptr:a,x)
void dtbsv(const char *uplo, const char *trans, const char *diag,
           const MKL_INT *n, const MKL_INT *k, const double *a,
           const MKL_INT *lda, double *x, const MKL_INT *incx) NOTHROW;

#pragma omp declare variant (MKL_BLAS_VARIANT_NAME(dtpsv)) match(construct={dispatch}, device={arch(gen)}) \
    append_args(interop(prefer_type("sycl","level_zero"),targetsync)) \
    adjust_args(need_device_ptr:ap,x)
void dtpsv(const char *uplo, const char *trans, const char *diag,
           const MKL_INT *n, const double *ap,
           double *x, const MKL_INT *incx) NOTHROW;

#pragma omp declare variant (MKL_BLAS_VARIANT_NAME(cgemv)) match(construct={dispatch}, device={arch(gen)}) \
    append_args(interop(prefer_type("sycl","level_zero"),targetsync)) \
    adjust_args(need_device_ptr:a,x,y)
void cgemv(const char *trans, const MKL_INT *m, const MKL_INT *n,
           const MKL_Complex8 *alpha, const MKL_Complex8 *a,
           const MKL_INT *lda, const MKL_Complex8 *x,
           const MKL_INT *incx, const MKL_Complex8 *beta,
           MKL_Complex8 *y, const MKL_INT *incy) NOTHROW;

#pragma omp declare variant (MKL_BLAS_VARIANT_NAME(cgbmv)) match(construct={dispatch}, device={arch(gen)}) \
    append_args(interop(prefer_type("sycl","level_zero"),targetsync)) \
    adjust_args(need_device_ptr:a,x,y)
void cgbmv(const char *trans, const MKL_INT *m, const MKL_INT *n,
           const MKL_INT *kl, const MKL_INT *ku,
           const MKL_Complex8 *alpha, const MKL_Complex8 *a,
           const MKL_INT *lda,
           const MKL_Complex8 *x, const MKL_INT *incx, const
           MKL_Complex8 *beta, MKL_Complex8 *y, const MKL_INT *incy) NOTHROW;

#pragma omp declare variant (MKL_BLAS_VARIANT_NAME(ctrmv)) match(construct={dispatch}, device={arch(gen)}) \
    append_args(interop(prefer_type("sycl","level_zero"),targetsync)) \
    adjust_args(need_device_ptr:a,x)
void ctrmv(const char *uplo, const char *transa, const char *diag,
           const MKL_INT *n, const MKL_Complex8 *a, const MKL_INT *lda,
           MKL_Complex8 *x, const MKL_INT *incx) NOTHROW;

#pragma omp declare variant (MKL_BLAS_VARIANT_NAME(ctbmv)) match(construct={dispatch}, device={arch(gen)}) \
    append_args(interop(prefer_type("sycl","level_zero"),targetsync)) \
    adjust_args(need_device_ptr:a,x)
void ctbmv(const char *uplo, const char *trans, const char *diag,
           const MKL_INT *n, const MKL_INT *k,
           const MKL_Complex8 *a, const MKL_INT *lda,
           MKL_Complex8 *x, const MKL_INT *incx) NOTHROW;

#pragma omp declare variant (MKL_BLAS_VARIANT_NAME(ctpmv)) match(construct={dispatch}, device={arch(gen)}) \
    append_args(interop(prefer_type("sycl","level_zero"),targetsync)) \
    adjust_args(need_device_ptr:ap,x)
void ctpmv(const char *uplo, const char *trans, const char *diag,
           const MKL_INT *n, const MKL_Complex8 *ap, MKL_Complex8 *x,
           const MKL_INT *incx) NOTHROW;

#pragma omp declare variant (MKL_BLAS_VARIANT_NAME(ctrsv)) match(construct={dispatch}, device={arch(gen)}) \
    append_args(interop(prefer_type("sycl","level_zero"),targetsync)) \
    adjust_args(need_device_ptr:a,x)
void ctrsv(const char *uplo, const char *trans, const char *diag,
           const MKL_INT *n, const MKL_Complex8 *a, const MKL_INT *lda,
           MKL_Complex8 *x, const MKL_INT *incx) NOTHROW;

#pragma omp declare variant (MKL_BLAS_VARIANT_NAME(ctbsv)) match(construct={dispatch}, device={arch(gen)}) \
    append_args(interop(prefer_type("sycl","level_zero"),targetsync)) \
    adjust_args(need_device_ptr:a,x)
void ctbsv(const char *uplo, const char *trans, const char *diag,
           const MKL_INT *n, const MKL_INT *k,
           const MKL_Complex8 *a, const MKL_INT *lda,
           MKL_Complex8 *x, const MKL_INT *incx) NOTHROW;

#pragma omp declare variant (MKL_BLAS_VARIANT_NAME(ctpsv)) match(construct={dispatch}, device={arch(gen)}) \
    append_args(interop(prefer_type("sycl","level_zero"),targetsync)) \
    adjust_args(need_device_ptr:ap,x)
void ctpsv(const char *uplo, const char *trans, const char *diag,
           const MKL_INT *n, const MKL_Complex8 *ap, MKL_Complex8 *x,
           const MKL_INT *incx) NOTHROW;

#pragma omp declare variant (MKL_BLAS_VARIANT_NAME(zgemv)) match(construct={dispatch}, device={arch(gen)}) \
    append_args(interop(prefer_type("sycl","level_zero"),targetsync)) \
    adjust_args(need_device_ptr:a,x,y)
void zgemv(const char *trans, const MKL_INT *m, const MKL_INT *n,
           const MKL_Complex16 *alpha,
           const MKL_Complex16 *a, const MKL_INT *lda,
           const MKL_Complex16 *x, const MKL_INT *incx,
           const MKL_Complex16 *beta, MKL_Complex16 *y,
           const MKL_INT *incy) NOTHROW;

#pragma omp declare variant (MKL_BLAS_VARIANT_NAME(zgbmv)) match(construct={dispatch}, device={arch(gen)}) \
    append_args(interop(prefer_type("sycl","level_zero"),targetsync)) \
    adjust_args(need_device_ptr:a,x,y)
void zgbmv(const char *trans, const MKL_INT *m, const MKL_INT *n,
           const MKL_INT *kl, const MKL_INT *ku,
           const MKL_Complex16 *alpha, const MKL_Complex16 *a,
           const MKL_INT *lda,
           const MKL_Complex16 *x, const MKL_INT *incx,
           const MKL_Complex16 *beta,
           MKL_Complex16 *y, const MKL_INT *incy) NOTHROW;

#pragma omp declare variant (MKL_BLAS_VARIANT_NAME(ztrmv)) match(construct={dispatch}, device={arch(gen)}) \
    append_args(interop(prefer_type("sycl","level_zero"),targetsync)) \
    adjust_args(need_device_ptr:a,x)
void ztrmv(const char *uplo, const char *transa, const char *diag,
           const MKL_INT *n,
           const MKL_Complex16 *a, const MKL_INT *lda,
           MKL_Complex16 *x, const MKL_INT *incx) NOTHROW;

#pragma omp declare variant (MKL_BLAS_VARIANT_NAME(ztbmv)) match(construct={dispatch}, device={arch(gen)}) \
    append_args(interop(prefer_type("sycl","level_zero"),targetsync)) \
    adjust_args(need_device_ptr:a,x)
void ztbmv(const char *uplo, const char *trans, const char *diag,
           const MKL_INT *n, const MKL_INT *k,
           const MKL_Complex16 *a, const MKL_INT *lda,
           MKL_Complex16 *x, const MKL_INT *incx) NOTHROW;

#pragma omp declare variant (MKL_BLAS_VARIANT_NAME(ztpmv)) match(construct={dispatch}, device={arch(gen)}) \
    append_args(interop(prefer_type("sycl","level_zero"),targetsync)) \
    adjust_args(need_device_ptr:ap,x)
void ztpmv(const char *uplo, const char *trans, const char *diag,
           const MKL_INT *n, const MKL_Complex16 *ap, MKL_Complex16 *x,
           const MKL_INT *incx) NOTHROW;

#pragma omp declare variant (MKL_BLAS_VARIANT_NAME(ztrsv)) match(construct={dispatch}, device={arch(gen)}) \
    append_args(interop(prefer_type("sycl","level_zero"),targetsync)) \
    adjust_args(need_device_ptr:a,x)
void ztrsv(const char *uplo, const char *trans, const char *diag,
           const MKL_INT *n,
           const MKL_Complex16 *a, const MKL_INT *lda,
           MKL_Complex16 *x, const MKL_INT *incx) NOTHROW;

#pragma omp declare variant (MKL_BLAS_VARIANT_NAME(ztbsv)) match(construct={dispatch}, device={arch(gen)}) \
    append_args(interop(prefer_type("sycl","level_zero"),targetsync)) \
    adjust_args(need_device_ptr:a,x)
void ztbsv(const char *uplo, const char *trans, const char *diag,
           const MKL_INT *n, const MKL_INT *k,
           const MKL_Complex16 *a, const MKL_INT *lda,
           MKL_Complex16 *x, const MKL_INT *incx) NOTHROW;

#pragma omp declare variant (MKL_BLAS_VARIANT_NAME(ztpsv)) match(construct={dispatch}, device={arch(gen)}) \
    append_args(interop(prefer_type("sycl","level_zero"),targetsync)) \
    adjust_args(need_device_ptr:ap,x)
void ztpsv(const char *uplo, const char *trans, const char *diag,
           const MKL_INT *n, const MKL_Complex16 *ap, MKL_Complex16 *x,
           const MKL_INT *incx) NOTHROW;

// Routines with S, D prefixes
#pragma omp declare variant (MKL_BLAS_VARIANT_NAME(ssymv)) match(construct={dispatch}, device={arch(gen)}) \
    append_args(interop(prefer_type("sycl","level_zero"),targetsync)) \
    adjust_args(need_device_ptr:a,x,y)
void ssymv(const char *uplo, const MKL_INT *n, const float *alpha,
           const float *a, const MKL_INT *lda,
           const float *x, const MKL_INT *incx, const float *beta,
           float *y, const MKL_INT *incy) NOTHROW;

#pragma omp declare variant (MKL_BLAS_VARIANT_NAME(ssbmv)) match(construct={dispatch}, device={arch(gen)}) \
    append_args(interop(prefer_type("sycl","level_zero"),targetsync)) \
    adjust_args(need_device_ptr:a,x,y)
void ssbmv(const char *uplo, const MKL_INT *n, const MKL_INT *k,
           const float *alpha, const float *a, const MKL_INT *lda,
           const float *x, const MKL_INT *incx,
           const float *beta, float *y, const MKL_INT *incy) NOTHROW;

#pragma omp declare variant (MKL_BLAS_VARIANT_NAME(sspmv)) match(construct={dispatch}, device={arch(gen)}) \
    append_args(interop(prefer_type("sycl","level_zero"),targetsync)) \
    adjust_args(need_device_ptr:ap,x,y)
void sspmv(const char *uplo, const MKL_INT *n, const float *alpha,
           const float *ap, const float *x, const MKL_INT *incx,
           const float *beta, float *y, const MKL_INT *incy) NOTHROW;

#pragma omp declare variant (MKL_BLAS_VARIANT_NAME(sger)) match(construct={dispatch}, device={arch(gen)}) \
    append_args(interop(prefer_type("sycl","level_zero"),targetsync)) \
    adjust_args(need_device_ptr:a,x,y)
void sger(const MKL_INT *m, const MKL_INT *n, const float *alpha,
          const float *x, const MKL_INT *incx,
          const float *y, const MKL_INT *incy, float *a,
          const MKL_INT *lda) NOTHROW;

#pragma omp declare variant (MKL_BLAS_VARIANT_NAME(ssyr)) match(construct={dispatch}, device={arch(gen)}) \
    append_args(interop(prefer_type("sycl","level_zero"),targetsync)) \
    adjust_args(need_device_ptr:a,x)
void ssyr(const char *uplo, const MKL_INT *n, const float *alpha,
          const float *x, const MKL_INT *incx,
          float *a, const MKL_INT *lda) NOTHROW;

#pragma omp declare variant (MKL_BLAS_VARIANT_NAME(sspr)) match(construct={dispatch}, device={arch(gen)}) \
    append_args(interop(prefer_type("sycl","level_zero"),targetsync)) \
    adjust_args(need_device_ptr:ap,x)
void sspr(const char *uplo, const MKL_INT *n, const float *alpha,
          const float *x, const MKL_INT *incx, float *ap) NOTHROW;

#pragma omp declare variant (MKL_BLAS_VARIANT_NAME(ssyr2)) match(construct={dispatch}, device={arch(gen)}) \
    append_args(interop(prefer_type("sycl","level_zero"),targetsync)) \
    adjust_args(need_device_ptr:a,x,y)
void ssyr2(const char *uplo, const MKL_INT *n, const float *alpha,
           const float *x, const MKL_INT *incx,
           const float *y, const MKL_INT *incy, float *a,
           const MKL_INT *lda) NOTHROW;

#pragma omp declare variant (MKL_BLAS_VARIANT_NAME(sspr2)) match(construct={dispatch}, device={arch(gen)}) \
    append_args(interop(prefer_type("sycl","level_zero"),targetsync)) \
    adjust_args(need_device_ptr:ap,x,y)
void sspr2(const char *uplo, const MKL_INT *n, const float *alpha,
           const float *x, const MKL_INT *incx,
           const float *y, const MKL_INT *incy, float *ap) NOTHROW;

#pragma omp declare variant (MKL_BLAS_VARIANT_NAME(dsymv)) match(construct={dispatch}, device={arch(gen)}) \
    append_args(interop(prefer_type("sycl","level_zero"),targetsync)) \
    adjust_args(need_device_ptr:a,x,y)
void dsymv(const char *uplo, const MKL_INT *n, const double *alpha,
           const double *a, const MKL_INT *lda,
           const double *x, const MKL_INT *incx,
           const double *beta, double *y, const MKL_INT *incy) NOTHROW;

#pragma omp declare variant (MKL_BLAS_VARIANT_NAME(dsbmv)) match(construct={dispatch}, device={arch(gen)}) \
    append_args(interop(prefer_type("sycl","level_zero"),targetsync)) \
    adjust_args(need_device_ptr:a,x,y)
void dsbmv(const char *uplo, const MKL_INT *n, const MKL_INT *k,
           const double *alpha, const double *a, const MKL_INT *lda,
           const double *x, const MKL_INT *incx,
           const double *beta, double *y, const MKL_INT *incy) NOTHROW;

#pragma omp declare variant (MKL_BLAS_VARIANT_NAME(dspmv)) match(construct={dispatch}, device={arch(gen)}) \
    append_args(interop(prefer_type("sycl","level_zero"),targetsync)) \
    adjust_args(need_device_ptr:ap,x,y)
void dspmv(const char *uplo, const MKL_INT *n, const double *alpha,
           const double *ap, const double *x, const MKL_INT *incx,
           const double *beta, double *y, const MKL_INT *incy) NOTHROW;

#pragma omp declare variant (MKL_BLAS_VARIANT_NAME(dger)) match(construct={dispatch}, device={arch(gen)}) \
    append_args(interop(prefer_type("sycl","level_zero"),targetsync)) \
    adjust_args(need_device_ptr:a,x,y)
void dger(const MKL_INT *m, const MKL_INT *n, const double *alpha,
          const double *x, const MKL_INT *incx,
          const double *y, const MKL_INT *incy, double *a,
          const MKL_INT *lda) NOTHROW;

#pragma omp declare variant (MKL_BLAS_VARIANT_NAME(dsyr)) match(construct={dispatch}, device={arch(gen)}) \
    append_args(interop(prefer_type("sycl","level_zero"),targetsync)) \
    adjust_args(need_device_ptr:a,x)
void dsyr(const char *uplo, const MKL_INT *n, const double *alpha,
          const double *x, const MKL_INT *incx,
          double *a, const MKL_INT *lda) NOTHROW;

#pragma omp declare variant (MKL_BLAS_VARIANT_NAME(dspr)) match(construct={dispatch}, device={arch(gen)}) \
    append_args(interop(prefer_type("sycl","level_zero"),targetsync)) \
    adjust_args(need_device_ptr:ap,x)
void dspr(const char *uplo, const MKL_INT *n, const double *alpha,
          const double *x, const MKL_INT *incx, double *ap) NOTHROW;

#pragma omp declare variant (MKL_BLAS_VARIANT_NAME(dsyr2)) match(construct={dispatch}, device={arch(gen)}) \
    append_args(interop(prefer_type("sycl","level_zero"),targetsync)) \
    adjust_args(need_device_ptr:a,x,y)
void dsyr2(const char *uplo, const MKL_INT *n, const double *alpha,
           const double *x, const MKL_INT *incx,
           const double *y, const MKL_INT *incy, double *a,
           const MKL_INT *lda) NOTHROW;

#pragma omp declare variant (MKL_BLAS_VARIANT_NAME(dspr2)) match(construct={dispatch}, device={arch(gen)}) \
    append_args(interop(prefer_type("sycl","level_zero"),targetsync)) \
    adjust_args(need_device_ptr:ap,x,y)
void dspr2(const char *uplo, const MKL_INT *n, const double *alpha,
           const double *x, const MKL_INT *incx,
           const double *y, const MKL_INT *incy, double *ap) NOTHROW;

// Routines with C, Z prefixes
#pragma omp declare variant (MKL_BLAS_VARIANT_NAME(chemv)) match(construct={dispatch}, device={arch(gen)}) \
    append_args(interop(prefer_type("sycl","level_zero"),targetsync)) \
    adjust_args(need_device_ptr:a,x,y)
void chemv(const char *uplo, const MKL_INT *n, const MKL_Complex8 *alpha,
           const MKL_Complex8 *a, const MKL_INT *lda,
           const MKL_Complex8 *x, const MKL_INT *incx,
           const MKL_Complex8 *beta, MKL_Complex8 *y,
           const MKL_INT *incy) NOTHROW;

#pragma omp declare variant (MKL_BLAS_VARIANT_NAME(chbmv)) match(construct={dispatch}, device={arch(gen)}) \
    append_args(interop(prefer_type("sycl","level_zero"),targetsync)) \
    adjust_args(need_device_ptr:a,x,y)
void chbmv(const char *uplo, const MKL_INT *n, const MKL_INT *k,
           const MKL_Complex8 *alpha, const MKL_Complex8 *a,
           const MKL_INT *lda, const MKL_Complex8 *x,
           const MKL_INT *incx, const MKL_Complex8 *beta,
           MKL_Complex8 *y, const MKL_INT *incy) NOTHROW;

#pragma omp declare variant (MKL_BLAS_VARIANT_NAME(chpmv)) match(construct={dispatch}, device={arch(gen)}) \
    append_args(interop(prefer_type("sycl","level_zero"),targetsync)) \
    adjust_args(need_device_ptr:ap,x,y)
void chpmv(const char *uplo, const MKL_INT *n, const MKL_Complex8 *alpha,
           const MKL_Complex8 *ap, const MKL_Complex8 *x,
           const MKL_INT *incx, const MKL_Complex8 *beta,
           MKL_Complex8 *y, const MKL_INT *incy) NOTHROW;

#pragma omp declare variant (MKL_BLAS_VARIANT_NAME(cgeru)) match(construct={dispatch}, device={arch(gen)}) \
    append_args(interop(prefer_type("sycl","level_zero"),targetsync)) \
    adjust_args(need_device_ptr:a,x,y)
void cgeru(const MKL_INT *m, const MKL_INT *n, const  MKL_Complex8 *alpha,
           const MKL_Complex8 *x, const MKL_INT *incx,
           const MKL_Complex8 *y, const MKL_INT *incy,
           MKL_Complex8 *a, const MKL_INT *lda) NOTHROW;

#pragma omp declare variant (MKL_BLAS_VARIANT_NAME(cgerc)) match(construct={dispatch}, device={arch(gen)}) \
    append_args(interop(prefer_type("sycl","level_zero"),targetsync)) \
    adjust_args(need_device_ptr:a,x,y)
void cgerc(const MKL_INT *m, const MKL_INT *n, const MKL_Complex8 *alpha,
           const MKL_Complex8 *x, const MKL_INT *incx,
           const MKL_Complex8 *y, const MKL_INT *incy,
           MKL_Complex8 *a, const MKL_INT *lda) NOTHROW;

#pragma omp declare variant (MKL_BLAS_VARIANT_NAME(cher)) match(construct={dispatch}, device={arch(gen)}) \
    append_args(interop(prefer_type("sycl","level_zero"),targetsync)) \
    adjust_args(need_device_ptr:a,x)
void cher(const char *uplo, const MKL_INT *n, const float *alpha,
          const MKL_Complex8 *x, const MKL_INT *incx,
          MKL_Complex8 *a, const MKL_INT *lda) NOTHROW;

#pragma omp declare variant (MKL_BLAS_VARIANT_NAME(chpr)) match(construct={dispatch}, device={arch(gen)}) \
    append_args(interop(prefer_type("sycl","level_zero"),targetsync)) \
    adjust_args(need_device_ptr:ap,x)
void chpr(const char *uplo, const MKL_INT *n, const float *alpha,
          const MKL_Complex8 *x, const MKL_INT *incx, MKL_Complex8 *ap) NOTHROW;

#pragma omp declare variant (MKL_BLAS_VARIANT_NAME(cher2)) match(construct={dispatch}, device={arch(gen)}) \
    append_args(interop(prefer_type("sycl","level_zero"),targetsync)) \
    adjust_args(need_device_ptr:a,x,y)
void cher2(const char *uplo, const MKL_INT *n, const MKL_Complex8 *alpha,
           const MKL_Complex8 *x, const MKL_INT *incx,
           const MKL_Complex8 *y, const MKL_INT *incy,
           MKL_Complex8 *a, const MKL_INT *lda) NOTHROW;

#pragma omp declare variant (MKL_BLAS_VARIANT_NAME(chpr2)) match(construct={dispatch}, device={arch(gen)}) \
    append_args(interop(prefer_type("sycl","level_zero"),targetsync)) \
    adjust_args(need_device_ptr:ap,x,y)
void chpr2(const char *uplo, const MKL_INT *n, const MKL_Complex8 *alpha,
           const MKL_Complex8 *x, const MKL_INT *incx,
           const MKL_Complex8 *y, const MKL_INT *incy,
           MKL_Complex8 *ap) NOTHROW;

#pragma omp declare variant (MKL_BLAS_VARIANT_NAME(zhemv)) match(construct={dispatch}, device={arch(gen)}) \
    append_args(interop(prefer_type("sycl","level_zero"),targetsync)) \
    adjust_args(need_device_ptr:a,x,y)
void zhemv(const char *uplo, const MKL_INT *n, const MKL_Complex16 *alpha,
           const MKL_Complex16 *a, const MKL_INT *lda,
           const MKL_Complex16 *x, const MKL_INT *incx,
           const MKL_Complex16 *beta, MKL_Complex16 *y,
           const MKL_INT *incy) NOTHROW;

#pragma omp declare variant (MKL_BLAS_VARIANT_NAME(zhbmv)) match(construct={dispatch}, device={arch(gen)}) \
    append_args(interop(prefer_type("sycl","level_zero"),targetsync)) \
    adjust_args(need_device_ptr:a,x,y)
void zhbmv(const char *uplo, const MKL_INT *n, const MKL_INT *k,
           const MKL_Complex16 *alpha, const MKL_Complex16 *a,
           const MKL_INT *lda, const MKL_Complex16 *x, const MKL_INT *incx,
           const MKL_Complex16 *beta, MKL_Complex16 *y,
           const MKL_INT *incy) NOTHROW;

#pragma omp declare variant (MKL_BLAS_VARIANT_NAME(zhpmv)) match(construct={dispatch}, device={arch(gen)}) \
    append_args(interop(prefer_type("sycl","level_zero"),targetsync)) \
    adjust_args(need_device_ptr:ap,x,y)
void zhpmv(const char *uplo, const MKL_INT *n, const MKL_Complex16 *alpha,
           const MKL_Complex16 *ap, const MKL_Complex16 *x,
           const MKL_INT *incx, const MKL_Complex16 *beta,
           MKL_Complex16 *y, const MKL_INT *incy) NOTHROW;

#pragma omp declare variant (MKL_BLAS_VARIANT_NAME(zgeru)) match(construct={dispatch}, device={arch(gen)}) \
    append_args(interop(prefer_type("sycl","level_zero"),targetsync)) \
    adjust_args(need_device_ptr:a,x,y)
void zgeru(const MKL_INT *m, const MKL_INT *n, const MKL_Complex16 *alpha,
           const MKL_Complex16 *x, const MKL_INT *incx,
           const MKL_Complex16 *y, const MKL_INT *incy,
           MKL_Complex16 *a, const MKL_INT *lda) NOTHROW;

#pragma omp declare variant (MKL_BLAS_VARIANT_NAME(zgerc)) match(construct={dispatch}, device={arch(gen)}) \
    append_args(interop(prefer_type("sycl","level_zero"),targetsync)) \
    adjust_args(need_device_ptr:a,x,y)
void zgerc(const MKL_INT *m, const MKL_INT *n, const MKL_Complex16 *alpha,
           const MKL_Complex16 *x, const MKL_INT *incx,
           const MKL_Complex16 *y, const MKL_INT *incy,
           MKL_Complex16 *a, const MKL_INT *lda) NOTHROW;

#pragma omp declare variant (MKL_BLAS_VARIANT_NAME(zher)) match(construct={dispatch}, device={arch(gen)}) \
    append_args(interop(prefer_type("sycl","level_zero"),targetsync)) \
    adjust_args(need_device_ptr:a,x)
void zher(const char *uplo, const MKL_INT *n, const double *alpha,
          const MKL_Complex16 *x, const MKL_INT *incx,
          MKL_Complex16 *a, const MKL_INT *lda) NOTHROW;

#pragma omp declare variant (MKL_BLAS_VARIANT_NAME(zhpr)) match(construct={dispatch}, device={arch(gen)}) \
    append_args(interop(prefer_type("sycl","level_zero"),targetsync)) \
    adjust_args(need_device_ptr:ap,x)
void zhpr(const char *uplo, const MKL_INT *n, const double *alpha,
          const MKL_Complex16 *x, const MKL_INT *incx,
          MKL_Complex16 *ap) NOTHROW;

#pragma omp declare variant (MKL_BLAS_VARIANT_NAME(zher2)) match(construct={dispatch}, device={arch(gen)}) \
    append_args(interop(prefer_type("sycl","level_zero"),targetsync)) \
    adjust_args(need_device_ptr:a,x,y)
void zher2(const char *uplo, const MKL_INT *n, const MKL_Complex16 *alpha,
           const MKL_Complex16 *x, const MKL_INT *incx,
           const MKL_Complex16 *y, const MKL_INT *incy,
           MKL_Complex16 *a, const MKL_INT *lda) NOTHROW;

#pragma omp declare variant (MKL_BLAS_VARIANT_NAME(zhpr2)) match(construct={dispatch}, device={arch(gen)}) \
    append_args(interop(prefer_type("sycl","level_zero"),targetsync)) \
    adjust_args(need_device_ptr:ap,x,y)
void zhpr2(const char *uplo, const MKL_INT *n, const MKL_Complex16 *alpha,
           const MKL_Complex16 *x, const MKL_INT *incx,
           const MKL_Complex16 *y, const MKL_INT *incy,
           MKL_Complex16 *ap) NOTHROW;


// Level1

// Routines with S, D, DS, SDS prefixes
#pragma omp declare variant (MKL_BLAS_VARIANT_NAME(sdot)) match(construct={dispatch}, device={arch(gen)}) \
    append_args(interop(prefer_type("sycl","level_zero"),targetsync)) \
    adjust_args(need_device_ptr:x,y)
float sdot(const MKL_INT *n, const float *x, const MKL_INT *incx,
           const float *y, const MKL_INT *incy) NOTHROW;

#pragma omp declare variant (MKL_BLAS_VARIANT_NAME(ddot)) match(construct={dispatch}, device={arch(gen)}) \
    append_args(interop(prefer_type("sycl","level_zero"),targetsync)) \
    adjust_args(need_device_ptr:x,y)
double ddot(const MKL_INT *n, const double *x, const MKL_INT *incx,
            const double *y, const MKL_INT *incy) NOTHROW;

#pragma omp declare variant (MKL_BLAS_VARIANT_NAME(dsdot)) match(construct={dispatch}, device={arch(gen)}) \
    append_args(interop(prefer_type("sycl","level_zero"),targetsync)) \
    adjust_args(need_device_ptr:x,y)
double dsdot(const MKL_INT *n, const float *x, const MKL_INT *incx,
             const float *y, const MKL_INT *incy) NOTHROW;

#pragma omp declare variant (MKL_BLAS_VARIANT_NAME(sdsdot)) match(construct={dispatch}, device={arch(gen)}) \
    append_args(interop(prefer_type("sycl","level_zero"),targetsync)) \
    adjust_args(need_device_ptr:x,y)
float sdsdot(const MKL_INT *n, const float *sb, const float *x,
             const MKL_INT *incx, const float *y, const MKL_INT *incy) NOTHROW;

// Routines with C, Z prefixes
#pragma omp declare variant (MKL_BLAS_VARIANT_NAME(cdotc)) match(construct={dispatch}, device={arch(gen)}) \
    append_args(interop(prefer_type("sycl","level_zero"),targetsync)) \
    adjust_args(need_device_ptr:x,y)
void cdotc(MKL_Complex8 *pres, const MKL_INT *n, const MKL_Complex8 *x,
           const MKL_INT *incx, const MKL_Complex8 *y, const MKL_INT *incy) NOTHROW;

#pragma omp declare variant (MKL_BLAS_VARIANT_NAME(cdotu)) match(construct={dispatch}, device={arch(gen)}) \
    append_args(interop(prefer_type("sycl","level_zero"),targetsync)) \
    adjust_args(need_device_ptr:x,y)
void cdotu(MKL_Complex8 *pres, const MKL_INT *n, const MKL_Complex8 *x,
           const MKL_INT *incx, const MKL_Complex8 *y, const MKL_INT *incy) NOTHROW;

#pragma omp declare variant (MKL_BLAS_VARIANT_NAME(zdotc)) match(construct={dispatch}, device={arch(gen)}) \
    append_args(interop(prefer_type("sycl","level_zero"),targetsync)) \
    adjust_args(need_device_ptr:x,y)
void zdotc(MKL_Complex16 *pres, const MKL_INT *n, const MKL_Complex16 *x,
           const MKL_INT *incx, const MKL_Complex16 *y, const MKL_INT *incy) NOTHROW;

#pragma omp declare variant (MKL_BLAS_VARIANT_NAME(zdotu)) match(construct={dispatch}, device={arch(gen)}) \
    append_args(interop(prefer_type("sycl","level_zero"),targetsync)) \
    adjust_args(need_device_ptr:x,y)
void zdotu(MKL_Complex16 *pres, const MKL_INT *n, const MKL_Complex16 *x,
           const MKL_INT *incx, const MKL_Complex16 *y, const MKL_INT *incy) NOTHROW;

// Routines with S, D, SC, DZ prefixes
#pragma omp declare variant (MKL_BLAS_VARIANT_NAME(snrm2)) match(construct={dispatch}, device={arch(gen)}) \
    append_args(interop(prefer_type("sycl","level_zero"),targetsync)) \
    adjust_args(need_device_ptr:x)
float snrm2(const MKL_INT *n, const float *x, const MKL_INT *incx) NOTHROW;

#pragma omp declare variant (MKL_BLAS_VARIANT_NAME(sasum)) match(construct={dispatch}, device={arch(gen)}) \
    append_args(interop(prefer_type("sycl","level_zero"),targetsync)) \
    adjust_args(need_device_ptr:x)
float sasum(const MKL_INT *n, const float *x, const MKL_INT *incx) NOTHROW;

#pragma omp declare variant (MKL_BLAS_VARIANT_NAME(dnrm2)) match(construct={dispatch}, device={arch(gen)}) \
    append_args(interop(prefer_type("sycl","level_zero"),targetsync)) \
    adjust_args(need_device_ptr:x)
double dnrm2(const MKL_INT *n, const double *x, const MKL_INT *incx) NOTHROW;

#pragma omp declare variant (MKL_BLAS_VARIANT_NAME(dasum)) match(construct={dispatch}, device={arch(gen)}) \
    append_args(interop(prefer_type("sycl","level_zero"),targetsync)) \
    adjust_args(need_device_ptr:x)
double dasum(const MKL_INT *n, const double *x, const MKL_INT *incx) NOTHROW;

#pragma omp declare variant (MKL_BLAS_VARIANT_NAME(scnrm2)) match(construct={dispatch}, device={arch(gen)}) \
    append_args(interop(prefer_type("sycl","level_zero"),targetsync)) \
    adjust_args(need_device_ptr:x)
float scnrm2(const MKL_INT *n, const MKL_Complex8 *x, const MKL_INT *incx) NOTHROW;

#pragma omp declare variant (MKL_BLAS_VARIANT_NAME(scasum)) match(construct={dispatch}, device={arch(gen)}) \
    append_args(interop(prefer_type("sycl","level_zero"),targetsync)) \
    adjust_args(need_device_ptr:x)
float scasum(const MKL_INT *n, const MKL_Complex8 *x, const MKL_INT *incx) NOTHROW;

#pragma omp declare variant (MKL_BLAS_VARIANT_NAME(dznrm2)) match(construct={dispatch}, device={arch(gen)}) \
    append_args(interop(prefer_type("sycl","level_zero"),targetsync)) \
    adjust_args(need_device_ptr:x)
double dznrm2(const MKL_INT *n, const MKL_Complex16 *x, const MKL_INT *incx) NOTHROW;

#pragma omp declare variant (MKL_BLAS_VARIANT_NAME(dzasum)) match(construct={dispatch}, device={arch(gen)}) \
    append_args(interop(prefer_type("sycl","level_zero"),targetsync)) \
    adjust_args(need_device_ptr:x)
double dzasum(const MKL_INT *n, const MKL_Complex16 *x, const MKL_INT *incx) NOTHROW;

// Routines with S, D, C, Z prefixes (Standard)
#pragma omp declare variant (MKL_BLAS_VARIANT_NAME(isamax)) match(construct={dispatch}, device={arch(gen)}) \
    append_args(interop(prefer_type("sycl","level_zero"),targetsync)) \
    adjust_args(need_device_ptr:x)
MKL_INT isamax(const MKL_INT *n, const float *x, const MKL_INT *incx) NOTHROW;

#pragma omp declare variant (MKL_BLAS_VARIANT_NAME(idamax)) match(construct={dispatch}, device={arch(gen)}) \
    append_args(interop(prefer_type("sycl","level_zero"),targetsync)) \
    adjust_args(need_device_ptr:x)
MKL_INT idamax(const MKL_INT *n, const double *x, const MKL_INT *incx) NOTHROW;

#pragma omp declare variant (MKL_BLAS_VARIANT_NAME(icamax)) match(construct={dispatch}, device={arch(gen)}) \
    append_args(interop(prefer_type("sycl","level_zero"),targetsync)) \
    adjust_args(need_device_ptr:x)
MKL_INT icamax(const MKL_INT *n, const MKL_Complex8 *x, const MKL_INT *incx) NOTHROW;

#pragma omp declare variant (MKL_BLAS_VARIANT_NAME(izamax)) match(construct={dispatch}, device={arch(gen)}) \
    append_args(interop(prefer_type("sycl","level_zero"),targetsync)) \
    adjust_args(need_device_ptr:x)
MKL_INT izamax(const MKL_INT *n, const MKL_Complex16 *x, const MKL_INT *incx) NOTHROW;

#pragma omp declare variant (MKL_BLAS_VARIANT_NAME(isamin)) match(construct={dispatch}, device={arch(gen)}) \
    append_args(interop(prefer_type("sycl","level_zero"),targetsync)) \
    adjust_args(need_device_ptr:x)
MKL_INT isamin(const MKL_INT *n, const float *x, const MKL_INT *incx) NOTHROW;

#pragma omp declare variant (MKL_BLAS_VARIANT_NAME(icamin)) match(construct={dispatch}, device={arch(gen)}) \
    append_args(interop(prefer_type("sycl","level_zero"),targetsync)) \
    adjust_args(need_device_ptr:x)
MKL_INT icamin(const MKL_INT *n, const MKL_Complex8 *x, const MKL_INT *incx) NOTHROW;

#pragma omp declare variant (MKL_BLAS_VARIANT_NAME(idamin)) match(construct={dispatch}, device={arch(gen)}) \
    append_args(interop(prefer_type("sycl","level_zero"),targetsync)) \
    adjust_args(need_device_ptr:x)
MKL_INT idamin(const MKL_INT *n, const double *x, const MKL_INT *incx) NOTHROW;

#pragma omp declare variant (MKL_BLAS_VARIANT_NAME(izamin)) match(construct={dispatch}, device={arch(gen)}) \
    append_args(interop(prefer_type("sycl","level_zero"),targetsync)) \
    adjust_args(need_device_ptr:x)
MKL_INT izamin(const MKL_INT *n, const MKL_Complex16 *x, const MKL_INT *incx) NOTHROW;

#pragma omp declare variant (MKL_BLAS_VARIANT_NAME(sswap)) match(construct={dispatch}, device={arch(gen)}) \
    append_args(interop(prefer_type("sycl","level_zero"),targetsync)) \
    adjust_args(need_device_ptr:x,y)
void sswap(const MKL_INT *n, float *x, const MKL_INT *incx, float *y,
           const MKL_INT *incy) NOTHROW;

#pragma omp declare variant (MKL_BLAS_VARIANT_NAME(scopy)) match(construct={dispatch}, device={arch(gen)}) \
    append_args(interop(prefer_type("sycl","level_zero"),targetsync)) \
    adjust_args(need_device_ptr:x,y)
void scopy(const MKL_INT *n, const float *x, const MKL_INT *incx, float *y,
           const MKL_INT *incy) NOTHROW;

#pragma omp declare variant (MKL_BLAS_VARIANT_NAME(saxpy)) match(construct={dispatch}, device={arch(gen)}) \
    append_args(interop(prefer_type("sycl","level_zero"),targetsync)) \
    adjust_args(need_device_ptr:x,y)
void saxpy(const MKL_INT *n, const float *alpha, const float *x,
           const MKL_INT *incx, float *y, const MKL_INT *incy) NOTHROW;

#pragma omp declare variant (MKL_BLAS_VARIANT_NAME(srotg)) match(construct={dispatch}, device={arch(gen)}) \
    append_args(interop(prefer_type("sycl","level_zero"),targetsync)) \
    adjust_args(need_device_ptr:a,b,c,s)
void srotg(float *a,float *b,float *c,float *s) NOTHROW;

#pragma omp declare variant (MKL_BLAS_VARIANT_NAME(dswap)) match(construct={dispatch}, device={arch(gen)}) \
    append_args(interop(prefer_type("sycl","level_zero"),targetsync)) \
    adjust_args(need_device_ptr:x,y)
void dswap(const MKL_INT *n, double *x, const MKL_INT *incx, double *y,
           const MKL_INT *incy) NOTHROW;

#pragma omp declare variant (MKL_BLAS_VARIANT_NAME(dcopy)) match(construct={dispatch}, device={arch(gen)}) \
    append_args(interop(prefer_type("sycl","level_zero"),targetsync)) \
    adjust_args(need_device_ptr:x,y)
void dcopy(const MKL_INT *n, const double *x, const MKL_INT *incx, double *y,
           const MKL_INT *incy) NOTHROW;

#pragma omp declare variant (MKL_BLAS_VARIANT_NAME(daxpy)) match(construct={dispatch}, device={arch(gen)}) \
    append_args(interop(prefer_type("sycl","level_zero"),targetsync)) \
    adjust_args(need_device_ptr:x,y)
void daxpy(const MKL_INT *n, const double *alpha, const double *x, const MKL_INT *incx,
           double *y, const MKL_INT *incy) NOTHROW;

#pragma omp declare variant (MKL_BLAS_VARIANT_NAME(drotg)) match(construct={dispatch}, device={arch(gen)}) \
    append_args(interop(prefer_type("sycl","level_zero"),targetsync)) \
    adjust_args(need_device_ptr:a,b,c,s)
void drotg(double *a, double *b, double *c, double *s) NOTHROW;

#pragma omp declare variant (MKL_BLAS_VARIANT_NAME(cswap)) match(construct={dispatch}, device={arch(gen)}) \
    append_args(interop(prefer_type("sycl","level_zero"),targetsync)) \
    adjust_args(need_device_ptr:x,y)
void cswap(const MKL_INT *n, MKL_Complex8 *x, const MKL_INT *incx,
           MKL_Complex8 *y, const MKL_INT *incy) NOTHROW;

#pragma omp declare variant (MKL_BLAS_VARIANT_NAME(ccopy)) match(construct={dispatch}, device={arch(gen)}) \
    append_args(interop(prefer_type("sycl","level_zero"),targetsync)) \
    adjust_args(need_device_ptr:x,y)
void ccopy(const MKL_INT *n, const MKL_Complex8 *x, const MKL_INT *incx,
           MKL_Complex8 *y, const MKL_INT *incy) NOTHROW;

#pragma omp declare variant (MKL_BLAS_VARIANT_NAME(caxpy)) match(construct={dispatch}, device={arch(gen)}) \
    append_args(interop(prefer_type("sycl","level_zero"),targetsync)) \
    adjust_args(need_device_ptr:x,y)
void caxpy(const MKL_INT *n, const MKL_Complex8 *alpha, const MKL_Complex8 *x,
           const MKL_INT *incx, MKL_Complex8 *y, const MKL_INT *incy) NOTHROW;

#pragma omp declare variant (MKL_BLAS_VARIANT_NAME(crotg)) match(construct={dispatch}, device={arch(gen)}) \
    append_args(interop(prefer_type("sycl","level_zero"),targetsync)) \
    adjust_args(need_device_ptr:a,b,c,s)
void crotg(MKL_Complex8 *a, const MKL_Complex8 *b, float *c, MKL_Complex8 *s) NOTHROW;

#pragma omp declare variant (MKL_BLAS_VARIANT_NAME(zswap)) match(construct={dispatch}, device={arch(gen)}) \
    append_args(interop(prefer_type("sycl","level_zero"),targetsync)) \
    adjust_args(need_device_ptr:x,y)
void zswap(const MKL_INT *n, MKL_Complex16 *x, const MKL_INT *incx,
           MKL_Complex16 *y, const MKL_INT *incy) NOTHROW;

#pragma omp declare variant (MKL_BLAS_VARIANT_NAME(zcopy)) match(construct={dispatch}, device={arch(gen)}) \
    append_args(interop(prefer_type("sycl","level_zero"),targetsync)) \
    adjust_args(need_device_ptr:x,y)
void zcopy(const MKL_INT *n, const MKL_Complex16 *x, const MKL_INT *incx,
           MKL_Complex16 *y, const MKL_INT *incy) NOTHROW;

#pragma omp declare variant (MKL_BLAS_VARIANT_NAME(zaxpy)) match(construct={dispatch}, device={arch(gen)}) \
    append_args(interop(prefer_type("sycl","level_zero"),targetsync)) \
    adjust_args(need_device_ptr:x,y)
void zaxpy(const MKL_INT *n, const MKL_Complex16 *alpha, const MKL_Complex16 *x,
           const MKL_INT *incx, MKL_Complex16 *y, const MKL_INT *incy) NOTHROW;

#pragma omp declare variant (MKL_BLAS_VARIANT_NAME(zrotg)) match(construct={dispatch}, device={arch(gen)}) \
    append_args(interop(prefer_type("sycl","level_zero"),targetsync)) \
    adjust_args(need_device_ptr:a,b,c,s)
void zrotg(MKL_Complex16 *a, const MKL_Complex16 *b, double *c, MKL_Complex16 *s) NOTHROW;

// Routines with S, D prefixes
#pragma omp declare variant (MKL_BLAS_VARIANT_NAME(srotmg)) match(construct={dispatch}, device={arch(gen)}) \
    append_args(interop(prefer_type("sycl","level_zero"),targetsync)) \
    adjust_args(need_device_ptr:d1,d2,x1,param)
void srotmg(float *d1, float *d2, float *x1, const float *y1, float *param) NOTHROW;

#pragma omp declare variant (MKL_BLAS_VARIANT_NAME(srot)) match(construct={dispatch}, device={arch(gen)}) \
    append_args(interop(prefer_type("sycl","level_zero"),targetsync)) \
    adjust_args(need_device_ptr:x,y)
void srot(const MKL_INT *n, float *x, const MKL_INT *incx, float *y,
          const MKL_INT *incy, const float *c, const float *s) NOTHROW;

#pragma omp declare variant (MKL_BLAS_VARIANT_NAME(srotm)) match(construct={dispatch}, device={arch(gen)}) \
    append_args(interop(prefer_type("sycl","level_zero"),targetsync)) \
    adjust_args(need_device_ptr:x,y,param)
void srotm(const MKL_INT *n, float *x, const MKL_INT *incx, float *y,
           const MKL_INT *incy, const float *param) NOTHROW;

#pragma omp declare variant (MKL_BLAS_VARIANT_NAME(drotmg)) match(construct={dispatch}, device={arch(gen)}) \
    append_args(interop(prefer_type("sycl","level_zero"),targetsync)) \
    adjust_args(need_device_ptr:d1,d2,x1,param)
void drotmg(double *d1, double *d2, double *x1, const double *y1, double *param) NOTHROW;

#pragma omp declare variant (MKL_BLAS_VARIANT_NAME(drot)) match(construct={dispatch}, device={arch(gen)}) \
    append_args(interop(prefer_type("sycl","level_zero"),targetsync)) \
    adjust_args(need_device_ptr:x,y)
void drot(const MKL_INT *n, double *x, const MKL_INT *incx, double *y,
          const MKL_INT *incy, const double *c, const double *s) NOTHROW;

#pragma omp declare variant (MKL_BLAS_VARIANT_NAME(drotm)) match(construct={dispatch}, device={arch(gen)}) \
    append_args(interop(prefer_type("sycl","level_zero"),targetsync)) \
    adjust_args(need_device_ptr:x,y,param)
void drotm(const MKL_INT *n, double *x, const MKL_INT *incx, double *y,
           const MKL_INT *incy, const double *param) NOTHROW;

// Routines with CS, ZD prefixes
#pragma omp declare variant (MKL_BLAS_VARIANT_NAME(csrot)) match(construct={dispatch}, device={arch(gen)}) \
    append_args(interop(prefer_type("sycl","level_zero"),targetsync)) \
    adjust_args(need_device_ptr:x,y)
void csrot(const MKL_INT *n, MKL_Complex8 *x, const MKL_INT *incx, MKL_Complex8 *y,
           const MKL_INT *incy, const float *c, const float *s) NOTHROW;

#pragma omp declare variant (MKL_BLAS_VARIANT_NAME(zdrot)) match(construct={dispatch}, device={arch(gen)}) \
    append_args(interop(prefer_type("sycl","level_zero"),targetsync)) \
    adjust_args(need_device_ptr:x,y)
void zdrot(const MKL_INT *n, MKL_Complex16 *x, const MKL_INT *incx, MKL_Complex16 *y,
           const MKL_INT *incy, const double *c, const double *s) NOTHROW;

// Routines with S D C Z CS and ZD prefixes
#pragma omp declare variant (MKL_BLAS_VARIANT_NAME(sscal)) match(construct={dispatch}, device={arch(gen)}) \
    append_args(interop(prefer_type("sycl","level_zero"),targetsync)) \
    adjust_args(need_device_ptr:x)
void sscal(const MKL_INT *n, const float *a, float *x, const MKL_INT *incx) NOTHROW;

#pragma omp declare variant (MKL_BLAS_VARIANT_NAME(dscal)) match(construct={dispatch}, device={arch(gen)}) \
    append_args(interop(prefer_type("sycl","level_zero"),targetsync)) \
    adjust_args(need_device_ptr:x)
void dscal(const MKL_INT *n, const double *a, double *x, const MKL_INT *incx) NOTHROW;

#pragma omp declare variant (MKL_BLAS_VARIANT_NAME(cscal)) match(construct={dispatch}, device={arch(gen)}) \
    append_args(interop(prefer_type("sycl","level_zero"),targetsync)) \
    adjust_args(need_device_ptr:x)
void cscal(const MKL_INT *n, const MKL_Complex8 *a, MKL_Complex8 *x, const MKL_INT *incx) NOTHROW;

#pragma omp declare variant (MKL_BLAS_VARIANT_NAME(zscal)) match(construct={dispatch}, device={arch(gen)}) \
    append_args(interop(prefer_type("sycl","level_zero"),targetsync)) \
    adjust_args(need_device_ptr:x)
void zscal(const MKL_INT *n, const MKL_Complex16 *a, MKL_Complex16 *x, const MKL_INT *incx) NOTHROW;

#pragma omp declare variant (MKL_BLAS_VARIANT_NAME(csscal)) match(construct={dispatch}, device={arch(gen)}) \
    append_args(interop(prefer_type("sycl","level_zero"),targetsync)) \
    adjust_args(need_device_ptr:x)
void csscal(const MKL_INT *n, const float *a, MKL_Complex8 *x, const MKL_INT *incx) NOTHROW;

#pragma omp declare variant (MKL_BLAS_VARIANT_NAME(zdscal)) match(construct={dispatch}, device={arch(gen)}) \
    append_args(interop(prefer_type("sycl","level_zero"),targetsync)) \
    adjust_args(need_device_ptr:x)
void zdscal(const MKL_INT *n, const double *a, MKL_Complex16 *x, const MKL_INT *incx) NOTHROW;

#pragma omp declare variant (MKL_BLAS_VARIANT_NAME(zrot)) match(construct={dispatch}, device={arch(gen)}) \
    append_args(interop(prefer_type("sycl","level_zero"),targetsync)) \
    adjust_args(need_device_ptr:x,y)
void zrot(const MKL_INT *n, MKL_Complex16 *x, const MKL_INT *incx, MKL_Complex16 *y,
          const MKL_INT *incy, const double *c, const MKL_Complex16 *s) NOTHROW;

#pragma omp declare variant (MKL_BLAS_VARIANT_NAME(crot)) match(construct={dispatch}, device={arch(gen)}) \
    append_args(interop(prefer_type("sycl","level_zero"),targetsync)) \
    adjust_args(need_device_ptr:x,y)
void crot(const MKL_INT *n, MKL_Complex8 *x, const MKL_INT *incx, MKL_Complex8 *y,
          const MKL_INT *incy, const float *c, const MKL_Complex8 *s) NOTHROW;

#pragma omp declare variant (MKL_BLAS_VARIANT_NAME(saxpby)) match(construct={dispatch}, device={arch(gen)}) \
    append_args(interop(prefer_type("sycl","level_zero"),targetsync)) \
    adjust_args(need_device_ptr:x,y)
void saxpby(const MKL_INT *n, const float *alpha, const float *x, const MKL_INT *incx, const float *beta, float *y, const MKL_INT *incy) NOTHROW;

#pragma omp declare variant (MKL_BLAS_VARIANT_NAME(caxpby)) match(construct={dispatch}, device={arch(gen)}) \
    append_args(interop(prefer_type("sycl","level_zero"),targetsync)) \
    adjust_args(need_device_ptr:x,y)
void caxpby(const MKL_INT *n, const MKL_Complex8 *alpha, const MKL_Complex8 *x, const MKL_INT *incx, const MKL_Complex8 *beta, MKL_Complex8 *y, const MKL_INT *incy) NOTHROW;

#pragma omp declare variant (MKL_BLAS_VARIANT_NAME(daxpby)) match(construct={dispatch}, device={arch(gen)}) \
    append_args(interop(prefer_type("sycl","level_zero"),targetsync)) \
    adjust_args(need_device_ptr:x,y)
void daxpby(const MKL_INT *n, const double *alpha, const double *x, const MKL_INT *incx, const double *beta, double *y, const MKL_INT *incy) NOTHROW;

#pragma omp declare variant (MKL_BLAS_VARIANT_NAME(zaxpby)) match(construct={dispatch}, device={arch(gen)}) \
    append_args(interop(prefer_type("sycl","level_zero"),targetsync)) \
    adjust_args(need_device_ptr:x,y)
void zaxpby(const MKL_INT *n, const MKL_Complex16 *alpha, const MKL_Complex16 *x, const MKL_INT *incx, const MKL_Complex16 *beta, MKL_Complex16 *y, const MKL_INT *incy) NOTHROW;

#pragma omp declare variant (MKL_CBLAS_VARIANT_NAME(saxpby)) match(construct={dispatch}, device={arch(gen)}) \
    append_args(interop(prefer_type("sycl","level_zero"),targetsync)) \
    adjust_args(need_device_ptr:X,Y)
void cblas_saxpby(const MKL_INT N, const float alpha, const float *X,
                  const MKL_INT incX, const float beta, float *Y, const MKL_INT incY) NOTHROW;

#pragma omp declare variant (MKL_CBLAS_VARIANT_NAME(daxpby)) match(construct={dispatch}, device={arch(gen)}) \
    append_args(interop(prefer_type("sycl","level_zero"),targetsync)) \
    adjust_args(need_device_ptr:X,Y)
void cblas_daxpby(const MKL_INT N, const double alpha, const double *X,
                  const MKL_INT incX, const double beta, double *Y, const MKL_INT incY) NOTHROW;

#pragma omp declare variant (MKL_CBLAS_VARIANT_NAME(caxpby)) match(construct={dispatch}, device={arch(gen)}) \
    append_args(interop(prefer_type("sycl","level_zero"),targetsync)) \
    adjust_args(need_device_ptr:X,Y)
void cblas_caxpby(const MKL_INT N, const void *alpha, const void *X,
                  const MKL_INT incX, const void *beta, void *Y, const MKL_INT incY) NOTHROW;

#pragma omp declare variant (MKL_CBLAS_VARIANT_NAME(zaxpby)) match(construct={dispatch}, device={arch(gen)}) \
    append_args(interop(prefer_type("sycl","level_zero"),targetsync)) \
    adjust_args(need_device_ptr:X,Y)
void cblas_zaxpby(const MKL_INT N, const void *alpha, const void *X,
                  const MKL_INT incX, const void *beta, void *Y, const MKL_INT incY) NOTHROW ;

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif
