/* -== file: mkl_vml_omp_offload.h ==- */
/*******************************************************************************
* Copyright 2006-2023 Intel Corporation.
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

#ifndef MKL_VML_OMP_OFFLOAD
#define MKL_VML_OMP_OFFLOAD 1

#if (_OPENMP >= 202011)
#include <omp.h>
#endif

#include "mkl_types.h"
#include "mkl_vml_omp_variant.h"

#ifdef __cplusplus
extern "C" {
#endif // __cplusplus

#if (_OPENMP >= 202011)
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vmlsetmode))                  \
    match(construct = {dispatch}, device = {arch(gen)})                        \
        append_args(interop(prefer_type("sycl", "level_zero"), targetsync))
#endif
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vmlsetmode))                  \
    match(construct = {target variant dispatch}, device = {arch(gen)})
unsigned int vmlSetMode(const MKL_UINT mode) NOTHROW;

#if (_OPENMP >= 202011)
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vmlgetmode))                  \
    match(construct = {dispatch}, device = {arch(gen)})                        \
        append_args(interop(prefer_type("sycl", "level_zero"), targetsync))
#endif
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vmlgetmode))                  \
    match(construct = {target variant dispatch}, device = {arch(gen)})
unsigned int vmlGetMode() NOTHROW;

#if (_OPENMP >= 202011)
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vmlseterrstatus))             \
    match(construct = {dispatch}, device = {arch(gen)})                        \
        append_args(interop(prefer_type("sycl", "level_zero"), targetsync))
#endif
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vmlseterrstatus))             \
    match(construct = {target variant dispatch}, device = {arch(gen)})
int vmlSetErrStatus(MKL_INT new_status) NOTHROW;

#if (_OPENMP >= 202011)
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vmlgeterrstatus))             \
    match(construct = {dispatch}, device = {arch(gen)})                        \
        append_args(interop(prefer_type("sycl", "level_zero"), targetsync))
#endif
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vmlgeterrstatus))             \
    match(construct = {target variant dispatch}, device = {arch(gen)})
int vmlGetErrStatus() NOTHROW;

#if (_OPENMP >= 202011)
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vmlclearerrstatus))           \
    match(construct = {dispatch}, device = {arch(gen)})                        \
        append_args(interop(prefer_type("sycl", "level_zero"), targetsync))
#endif
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vmlclearerrstatus))           \
    match(construct = {target variant dispatch}, device = {arch(gen)})
int vmlClearErrStatus() NOTHROW;

// function abs
#if (_OPENMP >= 202011)
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vsabs))                       \
    match(construct = {dispatch}, device = {arch(gen)})                        \
        append_args(interop(prefer_type("sycl", "level_zero"), targetsync))    \
            adjust_args(need_device_ptr                                        \
                        : a) adjust_args(need_device_ptr                       \
                                         : y)
#endif
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vsabs))                       \
    match(construct = {target variant dispatch}, device = {arch(gen)})
void vsAbs(const MKL_INT n, const float* a, float* y) NOTHROW;

#if (_OPENMP >= 202011)
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vsabsi))                      \
    match(construct = {dispatch}, device = {arch(gen)})                        \
        append_args(interop(prefer_type("sycl", "level_zero"), targetsync))    \
            adjust_args(need_device_ptr                                        \
                        : a) adjust_args(need_device_ptr                       \
                                         : y)
#endif
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vsabsi))                      \
    match(construct = {target variant dispatch}, device = {arch(gen)})
void vsAbsI(const MKL_INT n, const float* a, MKL_INT inca, float* y,
            MKL_INT incy) NOTHROW;

#if (_OPENMP >= 202011)
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vmsabs))                      \
    match(construct = {dispatch}, device = {arch(gen)})                        \
        append_args(interop(prefer_type("sycl", "level_zero"), targetsync))    \
            adjust_args(need_device_ptr                                        \
                        : a) adjust_args(need_device_ptr                       \
                                         : y)
#endif
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vmsabs))                      \
    match(construct = {target variant dispatch}, device = {arch(gen)})
void vmsAbs(const MKL_INT n, const float* a, float* y, MKL_INT64 mode) NOTHROW;

#if (_OPENMP >= 202011)
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vmsabsi))                     \
    match(construct = {dispatch}, device = {arch(gen)})                        \
        append_args(interop(prefer_type("sycl", "level_zero"), targetsync))    \
            adjust_args(need_device_ptr                                        \
                        : a) adjust_args(need_device_ptr                       \
                                         : y)
#endif
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vmsabsi))                     \
    match(construct = {target variant dispatch}, device = {arch(gen)})
void vmsAbsI(const MKL_INT n, const float* a, MKL_INT inca, float* y,
             MKL_INT incy, MKL_INT64 mode) NOTHROW;

#if (_OPENMP >= 202011)
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vdabs))                       \
    match(construct = {dispatch}, device = {arch(gen)})                        \
        append_args(interop(prefer_type("sycl", "level_zero"), targetsync))    \
            adjust_args(need_device_ptr                                        \
                        : a) adjust_args(need_device_ptr                       \
                                         : y)
#endif
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vdabs))                       \
    match(construct = {target variant dispatch}, device = {arch(gen)})
void vdAbs(const MKL_INT n, const double* a, double* y) NOTHROW;

#if (_OPENMP >= 202011)
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vdabsi))                      \
    match(construct = {dispatch}, device = {arch(gen)})                        \
        append_args(interop(prefer_type("sycl", "level_zero"), targetsync))    \
            adjust_args(need_device_ptr                                        \
                        : a) adjust_args(need_device_ptr                       \
                                         : y)
#endif
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vdabsi))                      \
    match(construct = {target variant dispatch}, device = {arch(gen)})
void vdAbsI(const MKL_INT n, const double* a, MKL_INT inca, double* y,
            MKL_INT incy) NOTHROW;

#if (_OPENMP >= 202011)
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vmdabs))                      \
    match(construct = {dispatch}, device = {arch(gen)})                        \
        append_args(interop(prefer_type("sycl", "level_zero"), targetsync))    \
            adjust_args(need_device_ptr                                        \
                        : a) adjust_args(need_device_ptr                       \
                                         : y)
#endif
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vmdabs))                      \
    match(construct = {target variant dispatch}, device = {arch(gen)})
void vmdAbs(const MKL_INT n, const double* a, double* y,
            MKL_INT64 mode) NOTHROW;

#if (_OPENMP >= 202011)
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vmdabsi))                     \
    match(construct = {dispatch}, device = {arch(gen)})                        \
        append_args(interop(prefer_type("sycl", "level_zero"), targetsync))    \
            adjust_args(need_device_ptr                                        \
                        : a) adjust_args(need_device_ptr                       \
                                         : y)
#endif
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vmdabsi))                     \
    match(construct = {target variant dispatch}, device = {arch(gen)})
void vmdAbsI(const MKL_INT n, const double* a, MKL_INT inca, double* y,
             MKL_INT incy, MKL_INT64 mode) NOTHROW;

#if (_OPENMP >= 202011)
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vcabs))                       \
    match(construct = {dispatch}, device = {arch(gen)})                        \
        append_args(interop(prefer_type("sycl", "level_zero"), targetsync))    \
            adjust_args(need_device_ptr                                        \
                        : a) adjust_args(need_device_ptr                       \
                                         : y)
#endif
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vcabs))                       \
    match(construct = {target variant dispatch}, device = {arch(gen)})
void vcAbs(const MKL_INT n, const MKL_Complex8* a, float* y) NOTHROW;

#if (_OPENMP >= 202011)
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vcabsi))                      \
    match(construct = {dispatch}, device = {arch(gen)})                        \
        append_args(interop(prefer_type("sycl", "level_zero"), targetsync))    \
            adjust_args(need_device_ptr                                        \
                        : a) adjust_args(need_device_ptr                       \
                                         : y)
#endif
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vcabsi))                      \
    match(construct = {target variant dispatch}, device = {arch(gen)})
void vcAbsI(const MKL_INT n, const MKL_Complex8* a, MKL_INT inca, float* y,
            MKL_INT incy) NOTHROW;

#if (_OPENMP >= 202011)
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vmcabs))                      \
    match(construct = {dispatch}, device = {arch(gen)})                        \
        append_args(interop(prefer_type("sycl", "level_zero"), targetsync))    \
            adjust_args(need_device_ptr                                        \
                        : a) adjust_args(need_device_ptr                       \
                                         : y)
#endif
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vmcabs))                      \
    match(construct = {target variant dispatch}, device = {arch(gen)})
void vmcAbs(const MKL_INT n, const MKL_Complex8* a, float* y,
            MKL_INT64 mode) NOTHROW;

#if (_OPENMP >= 202011)
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vmcabsi))                     \
    match(construct = {dispatch}, device = {arch(gen)})                        \
        append_args(interop(prefer_type("sycl", "level_zero"), targetsync))    \
            adjust_args(need_device_ptr                                        \
                        : a) adjust_args(need_device_ptr                       \
                                         : y)
#endif
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vmcabsi))                     \
    match(construct = {target variant dispatch}, device = {arch(gen)})
void vmcAbsI(const MKL_INT n, const MKL_Complex8* a, MKL_INT inca, float* y,
             MKL_INT incy, MKL_INT64 mode) NOTHROW;

#if (_OPENMP >= 202011)
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vzabs))                       \
    match(construct = {dispatch}, device = {arch(gen)})                        \
        append_args(interop(prefer_type("sycl", "level_zero"), targetsync))    \
            adjust_args(need_device_ptr                                        \
                        : a) adjust_args(need_device_ptr                       \
                                         : y)
#endif
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vzabs))                       \
    match(construct = {target variant dispatch}, device = {arch(gen)})
void vzAbs(const MKL_INT n, const MKL_Complex16* a, double* y) NOTHROW;

#if (_OPENMP >= 202011)
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vzabsi))                      \
    match(construct = {dispatch}, device = {arch(gen)})                        \
        append_args(interop(prefer_type("sycl", "level_zero"), targetsync))    \
            adjust_args(need_device_ptr                                        \
                        : a) adjust_args(need_device_ptr                       \
                                         : y)
#endif
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vzabsi))                      \
    match(construct = {target variant dispatch}, device = {arch(gen)})
void vzAbsI(const MKL_INT n, const MKL_Complex16* a, MKL_INT inca, double* y,
            MKL_INT incy) NOTHROW;

#if (_OPENMP >= 202011)
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vmzabs))                      \
    match(construct = {dispatch}, device = {arch(gen)})                        \
        append_args(interop(prefer_type("sycl", "level_zero"), targetsync))    \
            adjust_args(need_device_ptr                                        \
                        : a) adjust_args(need_device_ptr                       \
                                         : y)
#endif
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vmzabs))                      \
    match(construct = {target variant dispatch}, device = {arch(gen)})
void vmzAbs(const MKL_INT n, const MKL_Complex16* a, double* y,
            MKL_INT64 mode) NOTHROW;

#if (_OPENMP >= 202011)
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vmzabsi))                     \
    match(construct = {dispatch}, device = {arch(gen)})                        \
        append_args(interop(prefer_type("sycl", "level_zero"), targetsync))    \
            adjust_args(need_device_ptr                                        \
                        : a) adjust_args(need_device_ptr                       \
                                         : y)
#endif
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vmzabsi))                     \
    match(construct = {target variant dispatch}, device = {arch(gen)})
void vmzAbsI(const MKL_INT n, const MKL_Complex16* a, MKL_INT inca, double* y,
             MKL_INT incy, MKL_INT64 mode) NOTHROW;

// function acos
#if (_OPENMP >= 202011)
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vsacos))                      \
    match(construct = {dispatch}, device = {arch(gen)})                        \
        append_args(interop(prefer_type("sycl", "level_zero"), targetsync))    \
            adjust_args(need_device_ptr                                        \
                        : a) adjust_args(need_device_ptr                       \
                                         : y)
#endif
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vsacos))                      \
    match(construct = {target variant dispatch}, device = {arch(gen)})
void vsAcos(const MKL_INT n, const float* a, float* y) NOTHROW;

#if (_OPENMP >= 202011)
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vsacosi))                     \
    match(construct = {dispatch}, device = {arch(gen)})                        \
        append_args(interop(prefer_type("sycl", "level_zero"), targetsync))    \
            adjust_args(need_device_ptr                                        \
                        : a) adjust_args(need_device_ptr                       \
                                         : y)
#endif
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vsacosi))                     \
    match(construct = {target variant dispatch}, device = {arch(gen)})
void vsAcosI(const MKL_INT n, const float* a, MKL_INT inca, float* y,
             MKL_INT incy) NOTHROW;

#if (_OPENMP >= 202011)
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vmsacos))                     \
    match(construct = {dispatch}, device = {arch(gen)})                        \
        append_args(interop(prefer_type("sycl", "level_zero"), targetsync))    \
            adjust_args(need_device_ptr                                        \
                        : a) adjust_args(need_device_ptr                       \
                                         : y)
#endif
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vmsacos))                     \
    match(construct = {target variant dispatch}, device = {arch(gen)})
void vmsAcos(const MKL_INT n, const float* a, float* y, MKL_INT64 mode) NOTHROW;

#if (_OPENMP >= 202011)
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vmsacosi))                    \
    match(construct = {dispatch}, device = {arch(gen)})                        \
        append_args(interop(prefer_type("sycl", "level_zero"), targetsync))    \
            adjust_args(need_device_ptr                                        \
                        : a) adjust_args(need_device_ptr                       \
                                         : y)
#endif
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vmsacosi))                    \
    match(construct = {target variant dispatch}, device = {arch(gen)})
void vmsAcosI(const MKL_INT n, const float* a, MKL_INT inca, float* y,
              MKL_INT incy, MKL_INT64 mode) NOTHROW;

#if (_OPENMP >= 202011)
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vdacos))                      \
    match(construct = {dispatch}, device = {arch(gen)})                        \
        append_args(interop(prefer_type("sycl", "level_zero"), targetsync))    \
            adjust_args(need_device_ptr                                        \
                        : a) adjust_args(need_device_ptr                       \
                                         : y)
#endif
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vdacos))                      \
    match(construct = {target variant dispatch}, device = {arch(gen)})
void vdAcos(const MKL_INT n, const double* a, double* y) NOTHROW;

#if (_OPENMP >= 202011)
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vdacosi))                     \
    match(construct = {dispatch}, device = {arch(gen)})                        \
        append_args(interop(prefer_type("sycl", "level_zero"), targetsync))    \
            adjust_args(need_device_ptr                                        \
                        : a) adjust_args(need_device_ptr                       \
                                         : y)
#endif
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vdacosi))                     \
    match(construct = {target variant dispatch}, device = {arch(gen)})
void vdAcosI(const MKL_INT n, const double* a, MKL_INT inca, double* y,
             MKL_INT incy) NOTHROW;

#if (_OPENMP >= 202011)
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vmdacos))                     \
    match(construct = {dispatch}, device = {arch(gen)})                        \
        append_args(interop(prefer_type("sycl", "level_zero"), targetsync))    \
            adjust_args(need_device_ptr                                        \
                        : a) adjust_args(need_device_ptr                       \
                                         : y)
#endif
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vmdacos))                     \
    match(construct = {target variant dispatch}, device = {arch(gen)})
void vmdAcos(const MKL_INT n, const double* a, double* y,
             MKL_INT64 mode) NOTHROW;

#if (_OPENMP >= 202011)
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vmdacosi))                    \
    match(construct = {dispatch}, device = {arch(gen)})                        \
        append_args(interop(prefer_type("sycl", "level_zero"), targetsync))    \
            adjust_args(need_device_ptr                                        \
                        : a) adjust_args(need_device_ptr                       \
                                         : y)
#endif
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vmdacosi))                    \
    match(construct = {target variant dispatch}, device = {arch(gen)})
void vmdAcosI(const MKL_INT n, const double* a, MKL_INT inca, double* y,
              MKL_INT incy, MKL_INT64 mode) NOTHROW;

#if (_OPENMP >= 202011)
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vcacos))                      \
    match(construct = {dispatch}, device = {arch(gen)})                        \
        append_args(interop(prefer_type("sycl", "level_zero"), targetsync))    \
            adjust_args(need_device_ptr                                        \
                        : a) adjust_args(need_device_ptr                       \
                                         : y)
#endif
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vcacos))                      \
    match(construct = {target variant dispatch}, device = {arch(gen)})
void vcAcos(const MKL_INT n, const MKL_Complex8* a, MKL_Complex8* y) NOTHROW;

#if (_OPENMP >= 202011)
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vcacosi))                     \
    match(construct = {dispatch}, device = {arch(gen)})                        \
        append_args(interop(prefer_type("sycl", "level_zero"), targetsync))    \
            adjust_args(need_device_ptr                                        \
                        : a) adjust_args(need_device_ptr                       \
                                         : y)
#endif
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vcacosi))                     \
    match(construct = {target variant dispatch}, device = {arch(gen)})
void vcAcosI(const MKL_INT n, const MKL_Complex8* a, MKL_INT inca,
             MKL_Complex8* y, MKL_INT incy) NOTHROW;

#if (_OPENMP >= 202011)
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vmcacos))                     \
    match(construct = {dispatch}, device = {arch(gen)})                        \
        append_args(interop(prefer_type("sycl", "level_zero"), targetsync))    \
            adjust_args(need_device_ptr                                        \
                        : a) adjust_args(need_device_ptr                       \
                                         : y)
#endif
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vmcacos))                     \
    match(construct = {target variant dispatch}, device = {arch(gen)})
void vmcAcos(const MKL_INT n, const MKL_Complex8* a, MKL_Complex8* y,
             MKL_INT64 mode) NOTHROW;

#if (_OPENMP >= 202011)
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vmcacosi))                    \
    match(construct = {dispatch}, device = {arch(gen)})                        \
        append_args(interop(prefer_type("sycl", "level_zero"), targetsync))    \
            adjust_args(need_device_ptr                                        \
                        : a) adjust_args(need_device_ptr                       \
                                         : y)
#endif
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vmcacosi))                    \
    match(construct = {target variant dispatch}, device = {arch(gen)})
void vmcAcosI(const MKL_INT n, const MKL_Complex8* a, MKL_INT inca,
              MKL_Complex8* y, MKL_INT incy, MKL_INT64 mode) NOTHROW;

#if (_OPENMP >= 202011)
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vzacos))                      \
    match(construct = {dispatch}, device = {arch(gen)})                        \
        append_args(interop(prefer_type("sycl", "level_zero"), targetsync))    \
            adjust_args(need_device_ptr                                        \
                        : a) adjust_args(need_device_ptr                       \
                                         : y)
#endif
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vzacos))                      \
    match(construct = {target variant dispatch}, device = {arch(gen)})
void vzAcos(const MKL_INT n, const MKL_Complex16* a, MKL_Complex16* y) NOTHROW;

#if (_OPENMP >= 202011)
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vzacosi))                     \
    match(construct = {dispatch}, device = {arch(gen)})                        \
        append_args(interop(prefer_type("sycl", "level_zero"), targetsync))    \
            adjust_args(need_device_ptr                                        \
                        : a) adjust_args(need_device_ptr                       \
                                         : y)
#endif
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vzacosi))                     \
    match(construct = {target variant dispatch}, device = {arch(gen)})
void vzAcosI(const MKL_INT n, const MKL_Complex16* a, MKL_INT inca,
             MKL_Complex16* y, MKL_INT incy) NOTHROW;

#if (_OPENMP >= 202011)
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vmzacos))                     \
    match(construct = {dispatch}, device = {arch(gen)})                        \
        append_args(interop(prefer_type("sycl", "level_zero"), targetsync))    \
            adjust_args(need_device_ptr                                        \
                        : a) adjust_args(need_device_ptr                       \
                                         : y)
#endif
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vmzacos))                     \
    match(construct = {target variant dispatch}, device = {arch(gen)})
void vmzAcos(const MKL_INT n, const MKL_Complex16* a, MKL_Complex16* y,
             MKL_INT64 mode) NOTHROW;

#if (_OPENMP >= 202011)
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vmzacosi))                    \
    match(construct = {dispatch}, device = {arch(gen)})                        \
        append_args(interop(prefer_type("sycl", "level_zero"), targetsync))    \
            adjust_args(need_device_ptr                                        \
                        : a) adjust_args(need_device_ptr                       \
                                         : y)
#endif
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vmzacosi))                    \
    match(construct = {target variant dispatch}, device = {arch(gen)})
void vmzAcosI(const MKL_INT n, const MKL_Complex16* a, MKL_INT inca,
              MKL_Complex16* y, MKL_INT incy, MKL_INT64 mode) NOTHROW;

// function acosh
#if (_OPENMP >= 202011)
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vsacosh))                     \
    match(construct = {dispatch}, device = {arch(gen)})                        \
        append_args(interop(prefer_type("sycl", "level_zero"), targetsync))    \
            adjust_args(need_device_ptr                                        \
                        : a) adjust_args(need_device_ptr                       \
                                         : y)
#endif
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vsacosh))                     \
    match(construct = {target variant dispatch}, device = {arch(gen)})
void vsAcosh(const MKL_INT n, const float* a, float* y) NOTHROW;

#if (_OPENMP >= 202011)
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vsacoshi))                    \
    match(construct = {dispatch}, device = {arch(gen)})                        \
        append_args(interop(prefer_type("sycl", "level_zero"), targetsync))    \
            adjust_args(need_device_ptr                                        \
                        : a) adjust_args(need_device_ptr                       \
                                         : y)
#endif
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vsacoshi))                    \
    match(construct = {target variant dispatch}, device = {arch(gen)})
void vsAcoshI(const MKL_INT n, const float* a, MKL_INT inca, float* y,
              MKL_INT incy) NOTHROW;

#if (_OPENMP >= 202011)
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vmsacosh))                    \
    match(construct = {dispatch}, device = {arch(gen)})                        \
        append_args(interop(prefer_type("sycl", "level_zero"), targetsync))    \
            adjust_args(need_device_ptr                                        \
                        : a) adjust_args(need_device_ptr                       \
                                         : y)
#endif
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vmsacosh))                    \
    match(construct = {target variant dispatch}, device = {arch(gen)})
void vmsAcosh(const MKL_INT n, const float* a, float* y,
              MKL_INT64 mode) NOTHROW;

#if (_OPENMP >= 202011)
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vmsacoshi))                   \
    match(construct = {dispatch}, device = {arch(gen)})                        \
        append_args(interop(prefer_type("sycl", "level_zero"), targetsync))    \
            adjust_args(need_device_ptr                                        \
                        : a) adjust_args(need_device_ptr                       \
                                         : y)
#endif
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vmsacoshi))                   \
    match(construct = {target variant dispatch}, device = {arch(gen)})
void vmsAcoshI(const MKL_INT n, const float* a, MKL_INT inca, float* y,
               MKL_INT incy, MKL_INT64 mode) NOTHROW;

#if (_OPENMP >= 202011)
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vdacosh))                     \
    match(construct = {dispatch}, device = {arch(gen)})                        \
        append_args(interop(prefer_type("sycl", "level_zero"), targetsync))    \
            adjust_args(need_device_ptr                                        \
                        : a) adjust_args(need_device_ptr                       \
                                         : y)
#endif
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vdacosh))                     \
    match(construct = {target variant dispatch}, device = {arch(gen)})
void vdAcosh(const MKL_INT n, const double* a, double* y) NOTHROW;

#if (_OPENMP >= 202011)
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vdacoshi))                    \
    match(construct = {dispatch}, device = {arch(gen)})                        \
        append_args(interop(prefer_type("sycl", "level_zero"), targetsync))    \
            adjust_args(need_device_ptr                                        \
                        : a) adjust_args(need_device_ptr                       \
                                         : y)
#endif
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vdacoshi))                    \
    match(construct = {target variant dispatch}, device = {arch(gen)})
void vdAcoshI(const MKL_INT n, const double* a, MKL_INT inca, double* y,
              MKL_INT incy) NOTHROW;

#if (_OPENMP >= 202011)
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vmdacosh))                    \
    match(construct = {dispatch}, device = {arch(gen)})                        \
        append_args(interop(prefer_type("sycl", "level_zero"), targetsync))    \
            adjust_args(need_device_ptr                                        \
                        : a) adjust_args(need_device_ptr                       \
                                         : y)
#endif
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vmdacosh))                    \
    match(construct = {target variant dispatch}, device = {arch(gen)})
void vmdAcosh(const MKL_INT n, const double* a, double* y,
              MKL_INT64 mode) NOTHROW;

#if (_OPENMP >= 202011)
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vmdacoshi))                   \
    match(construct = {dispatch}, device = {arch(gen)})                        \
        append_args(interop(prefer_type("sycl", "level_zero"), targetsync))    \
            adjust_args(need_device_ptr                                        \
                        : a) adjust_args(need_device_ptr                       \
                                         : y)
#endif
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vmdacoshi))                   \
    match(construct = {target variant dispatch}, device = {arch(gen)})
void vmdAcoshI(const MKL_INT n, const double* a, MKL_INT inca, double* y,
               MKL_INT incy, MKL_INT64 mode) NOTHROW;

#if (_OPENMP >= 202011)
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vcacosh))                     \
    match(construct = {dispatch}, device = {arch(gen)})                        \
        append_args(interop(prefer_type("sycl", "level_zero"), targetsync))    \
            adjust_args(need_device_ptr                                        \
                        : a) adjust_args(need_device_ptr                       \
                                         : y)
#endif
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vcacosh))                     \
    match(construct = {target variant dispatch}, device = {arch(gen)})
void vcAcosh(const MKL_INT n, const MKL_Complex8* a, MKL_Complex8* y) NOTHROW;

#if (_OPENMP >= 202011)
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vcacoshi))                    \
    match(construct = {dispatch}, device = {arch(gen)})                        \
        append_args(interop(prefer_type("sycl", "level_zero"), targetsync))    \
            adjust_args(need_device_ptr                                        \
                        : a) adjust_args(need_device_ptr                       \
                                         : y)
#endif
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vcacoshi))                    \
    match(construct = {target variant dispatch}, device = {arch(gen)})
void vcAcoshI(const MKL_INT n, const MKL_Complex8* a, MKL_INT inca,
              MKL_Complex8* y, MKL_INT incy) NOTHROW;

#if (_OPENMP >= 202011)
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vmcacosh))                    \
    match(construct = {dispatch}, device = {arch(gen)})                        \
        append_args(interop(prefer_type("sycl", "level_zero"), targetsync))    \
            adjust_args(need_device_ptr                                        \
                        : a) adjust_args(need_device_ptr                       \
                                         : y)
#endif
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vmcacosh))                    \
    match(construct = {target variant dispatch}, device = {arch(gen)})
void vmcAcosh(const MKL_INT n, const MKL_Complex8* a, MKL_Complex8* y,
              MKL_INT64 mode) NOTHROW;

#if (_OPENMP >= 202011)
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vmcacoshi))                   \
    match(construct = {dispatch}, device = {arch(gen)})                        \
        append_args(interop(prefer_type("sycl", "level_zero"), targetsync))    \
            adjust_args(need_device_ptr                                        \
                        : a) adjust_args(need_device_ptr                       \
                                         : y)
#endif
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vmcacoshi))                   \
    match(construct = {target variant dispatch}, device = {arch(gen)})
void vmcAcoshI(const MKL_INT n, const MKL_Complex8* a, MKL_INT inca,
               MKL_Complex8* y, MKL_INT incy, MKL_INT64 mode) NOTHROW;

#if (_OPENMP >= 202011)
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vzacosh))                     \
    match(construct = {dispatch}, device = {arch(gen)})                        \
        append_args(interop(prefer_type("sycl", "level_zero"), targetsync))    \
            adjust_args(need_device_ptr                                        \
                        : a) adjust_args(need_device_ptr                       \
                                         : y)
#endif
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vzacosh))                     \
    match(construct = {target variant dispatch}, device = {arch(gen)})
void vzAcosh(const MKL_INT n, const MKL_Complex16* a, MKL_Complex16* y) NOTHROW;

#if (_OPENMP >= 202011)
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vzacoshi))                    \
    match(construct = {dispatch}, device = {arch(gen)})                        \
        append_args(interop(prefer_type("sycl", "level_zero"), targetsync))    \
            adjust_args(need_device_ptr                                        \
                        : a) adjust_args(need_device_ptr                       \
                                         : y)
#endif
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vzacoshi))                    \
    match(construct = {target variant dispatch}, device = {arch(gen)})
void vzAcoshI(const MKL_INT n, const MKL_Complex16* a, MKL_INT inca,
              MKL_Complex16* y, MKL_INT incy) NOTHROW;

#if (_OPENMP >= 202011)
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vmzacosh))                    \
    match(construct = {dispatch}, device = {arch(gen)})                        \
        append_args(interop(prefer_type("sycl", "level_zero"), targetsync))    \
            adjust_args(need_device_ptr                                        \
                        : a) adjust_args(need_device_ptr                       \
                                         : y)
#endif
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vmzacosh))                    \
    match(construct = {target variant dispatch}, device = {arch(gen)})
void vmzAcosh(const MKL_INT n, const MKL_Complex16* a, MKL_Complex16* y,
              MKL_INT64 mode) NOTHROW;

#if (_OPENMP >= 202011)
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vmzacoshi))                   \
    match(construct = {dispatch}, device = {arch(gen)})                        \
        append_args(interop(prefer_type("sycl", "level_zero"), targetsync))    \
            adjust_args(need_device_ptr                                        \
                        : a) adjust_args(need_device_ptr                       \
                                         : y)
#endif
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vmzacoshi))                   \
    match(construct = {target variant dispatch}, device = {arch(gen)})
void vmzAcoshI(const MKL_INT n, const MKL_Complex16* a, MKL_INT inca,
               MKL_Complex16* y, MKL_INT incy, MKL_INT64 mode) NOTHROW;

// function acospi
#if (_OPENMP >= 202011)
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vsacospi))                    \
    match(construct = {dispatch}, device = {arch(gen)})                        \
        append_args(interop(prefer_type("sycl", "level_zero"), targetsync))    \
            adjust_args(need_device_ptr                                        \
                        : a) adjust_args(need_device_ptr                       \
                                         : y)
#endif
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vsacospi))                    \
    match(construct = {target variant dispatch}, device = {arch(gen)})
void vsAcospi(const MKL_INT n, const float* a, float* y) NOTHROW;

#if (_OPENMP >= 202011)
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vsacospii))                   \
    match(construct = {dispatch}, device = {arch(gen)})                        \
        append_args(interop(prefer_type("sycl", "level_zero"), targetsync))    \
            adjust_args(need_device_ptr                                        \
                        : a) adjust_args(need_device_ptr                       \
                                         : y)
#endif
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vsacospii))                   \
    match(construct = {target variant dispatch}, device = {arch(gen)})
void vsAcospiI(const MKL_INT n, const float* a, MKL_INT inca, float* y,
               MKL_INT incy) NOTHROW;

#if (_OPENMP >= 202011)
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vmsacospi))                   \
    match(construct = {dispatch}, device = {arch(gen)})                        \
        append_args(interop(prefer_type("sycl", "level_zero"), targetsync))    \
            adjust_args(need_device_ptr                                        \
                        : a) adjust_args(need_device_ptr                       \
                                         : y)
#endif
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vmsacospi))                   \
    match(construct = {target variant dispatch}, device = {arch(gen)})
void vmsAcospi(const MKL_INT n, const float* a, float* y,
               MKL_INT64 mode) NOTHROW;

#if (_OPENMP >= 202011)
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vmsacospii))                  \
    match(construct = {dispatch}, device = {arch(gen)})                        \
        append_args(interop(prefer_type("sycl", "level_zero"), targetsync))    \
            adjust_args(need_device_ptr                                        \
                        : a) adjust_args(need_device_ptr                       \
                                         : y)
#endif
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vmsacospii))                  \
    match(construct = {target variant dispatch}, device = {arch(gen)})
void vmsAcospiI(const MKL_INT n, const float* a, MKL_INT inca, float* y,
                MKL_INT incy, MKL_INT64 mode) NOTHROW;

#if (_OPENMP >= 202011)
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vdacospi))                    \
    match(construct = {dispatch}, device = {arch(gen)})                        \
        append_args(interop(prefer_type("sycl", "level_zero"), targetsync))    \
            adjust_args(need_device_ptr                                        \
                        : a) adjust_args(need_device_ptr                       \
                                         : y)
#endif
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vdacospi))                    \
    match(construct = {target variant dispatch}, device = {arch(gen)})
void vdAcospi(const MKL_INT n, const double* a, double* y) NOTHROW;

#if (_OPENMP >= 202011)
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vdacospii))                   \
    match(construct = {dispatch}, device = {arch(gen)})                        \
        append_args(interop(prefer_type("sycl", "level_zero"), targetsync))    \
            adjust_args(need_device_ptr                                        \
                        : a) adjust_args(need_device_ptr                       \
                                         : y)
#endif
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vdacospii))                   \
    match(construct = {target variant dispatch}, device = {arch(gen)})
void vdAcospiI(const MKL_INT n, const double* a, MKL_INT inca, double* y,
               MKL_INT incy) NOTHROW;

#if (_OPENMP >= 202011)
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vmdacospi))                   \
    match(construct = {dispatch}, device = {arch(gen)})                        \
        append_args(interop(prefer_type("sycl", "level_zero"), targetsync))    \
            adjust_args(need_device_ptr                                        \
                        : a) adjust_args(need_device_ptr                       \
                                         : y)
#endif
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vmdacospi))                   \
    match(construct = {target variant dispatch}, device = {arch(gen)})
void vmdAcospi(const MKL_INT n, const double* a, double* y,
               MKL_INT64 mode) NOTHROW;

#if (_OPENMP >= 202011)
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vmdacospii))                  \
    match(construct = {dispatch}, device = {arch(gen)})                        \
        append_args(interop(prefer_type("sycl", "level_zero"), targetsync))    \
            adjust_args(need_device_ptr                                        \
                        : a) adjust_args(need_device_ptr                       \
                                         : y)
#endif
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vmdacospii))                  \
    match(construct = {target variant dispatch}, device = {arch(gen)})
void vmdAcospiI(const MKL_INT n, const double* a, MKL_INT inca, double* y,
                MKL_INT incy, MKL_INT64 mode) NOTHROW;

// function add
#if (_OPENMP >= 202011)
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vsadd))                       \
    match(construct = {dispatch}, device = {arch(gen)})                        \
        append_args(interop(prefer_type("sycl", "level_zero"), targetsync))    \
            adjust_args(need_device_ptr                                        \
                        : a) adjust_args(need_device_ptr                       \
                                         : b) adjust_args(need_device_ptr      \
                                                          : y)
#endif
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vsadd))                       \
    match(construct = {target variant dispatch}, device = {arch(gen)})
void vsAdd(const MKL_INT n, const float* a, const float* b, float* y) NOTHROW;

#if (_OPENMP >= 202011)
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vsaddi))                      \
    match(construct = {dispatch}, device = {arch(gen)})                        \
        append_args(interop(prefer_type("sycl", "level_zero"), targetsync))    \
            adjust_args(need_device_ptr                                        \
                        : a) adjust_args(need_device_ptr                       \
                                         : b) adjust_args(need_device_ptr      \
                                                          : y)
#endif
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vsaddi))                      \
    match(construct = {target variant dispatch}, device = {arch(gen)})
void vsAddI(const MKL_INT n, const float* a, MKL_INT inca, const float* b,
            MKL_INT incb, float* y, MKL_INT incy) NOTHROW;

#if (_OPENMP >= 202011)
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vmsadd))                      \
    match(construct = {dispatch}, device = {arch(gen)})                        \
        append_args(interop(prefer_type("sycl", "level_zero"), targetsync))    \
            adjust_args(need_device_ptr                                        \
                        : a) adjust_args(need_device_ptr                       \
                                         : b) adjust_args(need_device_ptr      \
                                                          : y)
#endif
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vmsadd))                      \
    match(construct = {target variant dispatch}, device = {arch(gen)})
void vmsAdd(const MKL_INT n, const float* a, const float* b, float* y,
            MKL_INT64 mode) NOTHROW;

#if (_OPENMP >= 202011)
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vmsaddi))                     \
    match(construct = {dispatch}, device = {arch(gen)})                        \
        append_args(interop(prefer_type("sycl", "level_zero"), targetsync))    \
            adjust_args(need_device_ptr                                        \
                        : a) adjust_args(need_device_ptr                       \
                                         : b) adjust_args(need_device_ptr      \
                                                          : y)
#endif
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vmsaddi))                     \
    match(construct = {target variant dispatch}, device = {arch(gen)})
void vmsAddI(const MKL_INT n, const float* a, MKL_INT inca, const float* b,
             MKL_INT incb, float* y, MKL_INT incy, MKL_INT64 mode) NOTHROW;

#if (_OPENMP >= 202011)
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vdadd))                       \
    match(construct = {dispatch}, device = {arch(gen)})                        \
        append_args(interop(prefer_type("sycl", "level_zero"), targetsync))    \
            adjust_args(need_device_ptr                                        \
                        : a) adjust_args(need_device_ptr                       \
                                         : b) adjust_args(need_device_ptr      \
                                                          : y)
#endif
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vdadd))                       \
    match(construct = {target variant dispatch}, device = {arch(gen)})
void vdAdd(const MKL_INT n, const double* a, const double* b,
           double* y) NOTHROW;

#if (_OPENMP >= 202011)
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vdaddi))                      \
    match(construct = {dispatch}, device = {arch(gen)})                        \
        append_args(interop(prefer_type("sycl", "level_zero"), targetsync))    \
            adjust_args(need_device_ptr                                        \
                        : a) adjust_args(need_device_ptr                       \
                                         : b) adjust_args(need_device_ptr      \
                                                          : y)
#endif
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vdaddi))                      \
    match(construct = {target variant dispatch}, device = {arch(gen)})
void vdAddI(const MKL_INT n, const double* a, MKL_INT inca, const double* b,
            MKL_INT incb, double* y, MKL_INT incy) NOTHROW;

#if (_OPENMP >= 202011)
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vmdadd))                      \
    match(construct = {dispatch}, device = {arch(gen)})                        \
        append_args(interop(prefer_type("sycl", "level_zero"), targetsync))    \
            adjust_args(need_device_ptr                                        \
                        : a) adjust_args(need_device_ptr                       \
                                         : b) adjust_args(need_device_ptr      \
                                                          : y)
#endif
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vmdadd))                      \
    match(construct = {target variant dispatch}, device = {arch(gen)})
void vmdAdd(const MKL_INT n, const double* a, const double* b, double* y,
            MKL_INT64 mode) NOTHROW;

#if (_OPENMP >= 202011)
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vmdaddi))                     \
    match(construct = {dispatch}, device = {arch(gen)})                        \
        append_args(interop(prefer_type("sycl", "level_zero"), targetsync))    \
            adjust_args(need_device_ptr                                        \
                        : a) adjust_args(need_device_ptr                       \
                                         : b) adjust_args(need_device_ptr      \
                                                          : y)
#endif
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vmdaddi))                     \
    match(construct = {target variant dispatch}, device = {arch(gen)})
void vmdAddI(const MKL_INT n, const double* a, MKL_INT inca, const double* b,
             MKL_INT incb, double* y, MKL_INT incy, MKL_INT64 mode) NOTHROW;

#if (_OPENMP >= 202011)
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vcadd))                       \
    match(construct = {dispatch}, device = {arch(gen)})                        \
        append_args(interop(prefer_type("sycl", "level_zero"), targetsync))    \
            adjust_args(need_device_ptr                                        \
                        : a) adjust_args(need_device_ptr                       \
                                         : b) adjust_args(need_device_ptr      \
                                                          : y)
#endif
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vcadd))                       \
    match(construct = {target variant dispatch}, device = {arch(gen)})
void vcAdd(const MKL_INT n, const MKL_Complex8* a, const MKL_Complex8* b,
           MKL_Complex8* y) NOTHROW;

#if (_OPENMP >= 202011)
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vcaddi))                      \
    match(construct = {dispatch}, device = {arch(gen)})                        \
        append_args(interop(prefer_type("sycl", "level_zero"), targetsync))    \
            adjust_args(need_device_ptr                                        \
                        : a) adjust_args(need_device_ptr                       \
                                         : b) adjust_args(need_device_ptr      \
                                                          : y)
#endif
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vcaddi))                      \
    match(construct = {target variant dispatch}, device = {arch(gen)})
void vcAddI(const MKL_INT n, const MKL_Complex8* a, MKL_INT inca,
            const MKL_Complex8* b, MKL_INT incb, MKL_Complex8* y,
            MKL_INT incy) NOTHROW;

#if (_OPENMP >= 202011)
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vmcadd))                      \
    match(construct = {dispatch}, device = {arch(gen)})                        \
        append_args(interop(prefer_type("sycl", "level_zero"), targetsync))    \
            adjust_args(need_device_ptr                                        \
                        : a) adjust_args(need_device_ptr                       \
                                         : b) adjust_args(need_device_ptr      \
                                                          : y)
#endif
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vmcadd))                      \
    match(construct = {target variant dispatch}, device = {arch(gen)})
void vmcAdd(const MKL_INT n, const MKL_Complex8* a, const MKL_Complex8* b,
            MKL_Complex8* y, MKL_INT64 mode) NOTHROW;

#if (_OPENMP >= 202011)
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vmcaddi))                     \
    match(construct = {dispatch}, device = {arch(gen)})                        \
        append_args(interop(prefer_type("sycl", "level_zero"), targetsync))    \
            adjust_args(need_device_ptr                                        \
                        : a) adjust_args(need_device_ptr                       \
                                         : b) adjust_args(need_device_ptr      \
                                                          : y)
#endif
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vmcaddi))                     \
    match(construct = {target variant dispatch}, device = {arch(gen)})
void vmcAddI(const MKL_INT n, const MKL_Complex8* a, MKL_INT inca,
             const MKL_Complex8* b, MKL_INT incb, MKL_Complex8* y, MKL_INT incy,
             MKL_INT64 mode) NOTHROW;

#if (_OPENMP >= 202011)
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vzadd))                       \
    match(construct = {dispatch}, device = {arch(gen)})                        \
        append_args(interop(prefer_type("sycl", "level_zero"), targetsync))    \
            adjust_args(need_device_ptr                                        \
                        : a) adjust_args(need_device_ptr                       \
                                         : b) adjust_args(need_device_ptr      \
                                                          : y)
#endif
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vzadd))                       \
    match(construct = {target variant dispatch}, device = {arch(gen)})
void vzAdd(const MKL_INT n, const MKL_Complex16* a, const MKL_Complex16* b,
           MKL_Complex16* y) NOTHROW;

#if (_OPENMP >= 202011)
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vzaddi))                      \
    match(construct = {dispatch}, device = {arch(gen)})                        \
        append_args(interop(prefer_type("sycl", "level_zero"), targetsync))    \
            adjust_args(need_device_ptr                                        \
                        : a) adjust_args(need_device_ptr                       \
                                         : b) adjust_args(need_device_ptr      \
                                                          : y)
#endif
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vzaddi))                      \
    match(construct = {target variant dispatch}, device = {arch(gen)})
void vzAddI(const MKL_INT n, const MKL_Complex16* a, MKL_INT inca,
            const MKL_Complex16* b, MKL_INT incb, MKL_Complex16* y,
            MKL_INT incy) NOTHROW;

#if (_OPENMP >= 202011)
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vmzadd))                      \
    match(construct = {dispatch}, device = {arch(gen)})                        \
        append_args(interop(prefer_type("sycl", "level_zero"), targetsync))    \
            adjust_args(need_device_ptr                                        \
                        : a) adjust_args(need_device_ptr                       \
                                         : b) adjust_args(need_device_ptr      \
                                                          : y)
#endif
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vmzadd))                      \
    match(construct = {target variant dispatch}, device = {arch(gen)})
void vmzAdd(const MKL_INT n, const MKL_Complex16* a, const MKL_Complex16* b,
            MKL_Complex16* y, MKL_INT64 mode) NOTHROW;

#if (_OPENMP >= 202011)
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vmzaddi))                     \
    match(construct = {dispatch}, device = {arch(gen)})                        \
        append_args(interop(prefer_type("sycl", "level_zero"), targetsync))    \
            adjust_args(need_device_ptr                                        \
                        : a) adjust_args(need_device_ptr                       \
                                         : b) adjust_args(need_device_ptr      \
                                                          : y)
#endif
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vmzaddi))                     \
    match(construct = {target variant dispatch}, device = {arch(gen)})
void vmzAddI(const MKL_INT n, const MKL_Complex16* a, MKL_INT inca,
             const MKL_Complex16* b, MKL_INT incb, MKL_Complex16* y,
             MKL_INT incy, MKL_INT64 mode) NOTHROW;

// function arg
#if (_OPENMP >= 202011)
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vcarg))                       \
    match(construct = {dispatch}, device = {arch(gen)})                        \
        append_args(interop(prefer_type("sycl", "level_zero"), targetsync))    \
            adjust_args(need_device_ptr                                        \
                        : a) adjust_args(need_device_ptr                       \
                                         : y)
#endif
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vcarg))                       \
    match(construct = {target variant dispatch}, device = {arch(gen)})
void vcArg(const MKL_INT n, const MKL_Complex8* a, float* y) NOTHROW;

#if (_OPENMP >= 202011)
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vcargi))                      \
    match(construct = {dispatch}, device = {arch(gen)})                        \
        append_args(interop(prefer_type("sycl", "level_zero"), targetsync))    \
            adjust_args(need_device_ptr                                        \
                        : a) adjust_args(need_device_ptr                       \
                                         : y)
#endif
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vcargi))                      \
    match(construct = {target variant dispatch}, device = {arch(gen)})
void vcArgI(const MKL_INT n, const MKL_Complex8* a, MKL_INT inca, float* y,
            MKL_INT incy) NOTHROW;

#if (_OPENMP >= 202011)
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vmcarg))                      \
    match(construct = {dispatch}, device = {arch(gen)})                        \
        append_args(interop(prefer_type("sycl", "level_zero"), targetsync))    \
            adjust_args(need_device_ptr                                        \
                        : a) adjust_args(need_device_ptr                       \
                                         : y)
#endif
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vmcarg))                      \
    match(construct = {target variant dispatch}, device = {arch(gen)})
void vmcArg(const MKL_INT n, const MKL_Complex8* a, float* y,
            MKL_INT64 mode) NOTHROW;

#if (_OPENMP >= 202011)
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vmcargi))                     \
    match(construct = {dispatch}, device = {arch(gen)})                        \
        append_args(interop(prefer_type("sycl", "level_zero"), targetsync))    \
            adjust_args(need_device_ptr                                        \
                        : a) adjust_args(need_device_ptr                       \
                                         : y)
#endif
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vmcargi))                     \
    match(construct = {target variant dispatch}, device = {arch(gen)})
void vmcArgI(const MKL_INT n, const MKL_Complex8* a, MKL_INT inca, float* y,
             MKL_INT incy, MKL_INT64 mode) NOTHROW;

#if (_OPENMP >= 202011)
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vzarg))                       \
    match(construct = {dispatch}, device = {arch(gen)})                        \
        append_args(interop(prefer_type("sycl", "level_zero"), targetsync))    \
            adjust_args(need_device_ptr                                        \
                        : a) adjust_args(need_device_ptr                       \
                                         : y)
#endif
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vzarg))                       \
    match(construct = {target variant dispatch}, device = {arch(gen)})
void vzArg(const MKL_INT n, const MKL_Complex16* a, double* y) NOTHROW;

#if (_OPENMP >= 202011)
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vzargi))                      \
    match(construct = {dispatch}, device = {arch(gen)})                        \
        append_args(interop(prefer_type("sycl", "level_zero"), targetsync))    \
            adjust_args(need_device_ptr                                        \
                        : a) adjust_args(need_device_ptr                       \
                                         : y)
#endif
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vzargi))                      \
    match(construct = {target variant dispatch}, device = {arch(gen)})
void vzArgI(const MKL_INT n, const MKL_Complex16* a, MKL_INT inca, double* y,
            MKL_INT incy) NOTHROW;

#if (_OPENMP >= 202011)
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vmzarg))                      \
    match(construct = {dispatch}, device = {arch(gen)})                        \
        append_args(interop(prefer_type("sycl", "level_zero"), targetsync))    \
            adjust_args(need_device_ptr                                        \
                        : a) adjust_args(need_device_ptr                       \
                                         : y)
#endif
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vmzarg))                      \
    match(construct = {target variant dispatch}, device = {arch(gen)})
void vmzArg(const MKL_INT n, const MKL_Complex16* a, double* y,
            MKL_INT64 mode) NOTHROW;

#if (_OPENMP >= 202011)
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vmzargi))                     \
    match(construct = {dispatch}, device = {arch(gen)})                        \
        append_args(interop(prefer_type("sycl", "level_zero"), targetsync))    \
            adjust_args(need_device_ptr                                        \
                        : a) adjust_args(need_device_ptr                       \
                                         : y)
#endif
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vmzargi))                     \
    match(construct = {target variant dispatch}, device = {arch(gen)})
void vmzArgI(const MKL_INT n, const MKL_Complex16* a, MKL_INT inca, double* y,
             MKL_INT incy, MKL_INT64 mode) NOTHROW;

// function asin
#if (_OPENMP >= 202011)
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vsasin))                      \
    match(construct = {dispatch}, device = {arch(gen)})                        \
        append_args(interop(prefer_type("sycl", "level_zero"), targetsync))    \
            adjust_args(need_device_ptr                                        \
                        : a) adjust_args(need_device_ptr                       \
                                         : y)
#endif
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vsasin))                      \
    match(construct = {target variant dispatch}, device = {arch(gen)})
void vsAsin(const MKL_INT n, const float* a, float* y) NOTHROW;

#if (_OPENMP >= 202011)
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vsasini))                     \
    match(construct = {dispatch}, device = {arch(gen)})                        \
        append_args(interop(prefer_type("sycl", "level_zero"), targetsync))    \
            adjust_args(need_device_ptr                                        \
                        : a) adjust_args(need_device_ptr                       \
                                         : y)
#endif
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vsasini))                     \
    match(construct = {target variant dispatch}, device = {arch(gen)})
void vsAsinI(const MKL_INT n, const float* a, MKL_INT inca, float* y,
             MKL_INT incy) NOTHROW;

#if (_OPENMP >= 202011)
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vmsasin))                     \
    match(construct = {dispatch}, device = {arch(gen)})                        \
        append_args(interop(prefer_type("sycl", "level_zero"), targetsync))    \
            adjust_args(need_device_ptr                                        \
                        : a) adjust_args(need_device_ptr                       \
                                         : y)
#endif
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vmsasin))                     \
    match(construct = {target variant dispatch}, device = {arch(gen)})
void vmsAsin(const MKL_INT n, const float* a, float* y, MKL_INT64 mode) NOTHROW;

#if (_OPENMP >= 202011)
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vmsasini))                    \
    match(construct = {dispatch}, device = {arch(gen)})                        \
        append_args(interop(prefer_type("sycl", "level_zero"), targetsync))    \
            adjust_args(need_device_ptr                                        \
                        : a) adjust_args(need_device_ptr                       \
                                         : y)
#endif
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vmsasini))                    \
    match(construct = {target variant dispatch}, device = {arch(gen)})
void vmsAsinI(const MKL_INT n, const float* a, MKL_INT inca, float* y,
              MKL_INT incy, MKL_INT64 mode) NOTHROW;

#if (_OPENMP >= 202011)
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vdasin))                      \
    match(construct = {dispatch}, device = {arch(gen)})                        \
        append_args(interop(prefer_type("sycl", "level_zero"), targetsync))    \
            adjust_args(need_device_ptr                                        \
                        : a) adjust_args(need_device_ptr                       \
                                         : y)
#endif
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vdasin))                      \
    match(construct = {target variant dispatch}, device = {arch(gen)})
void vdAsin(const MKL_INT n, const double* a, double* y) NOTHROW;

#if (_OPENMP >= 202011)
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vdasini))                     \
    match(construct = {dispatch}, device = {arch(gen)})                        \
        append_args(interop(prefer_type("sycl", "level_zero"), targetsync))    \
            adjust_args(need_device_ptr                                        \
                        : a) adjust_args(need_device_ptr                       \
                                         : y)
#endif
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vdasini))                     \
    match(construct = {target variant dispatch}, device = {arch(gen)})
void vdAsinI(const MKL_INT n, const double* a, MKL_INT inca, double* y,
             MKL_INT incy) NOTHROW;

#if (_OPENMP >= 202011)
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vmdasin))                     \
    match(construct = {dispatch}, device = {arch(gen)})                        \
        append_args(interop(prefer_type("sycl", "level_zero"), targetsync))    \
            adjust_args(need_device_ptr                                        \
                        : a) adjust_args(need_device_ptr                       \
                                         : y)
#endif
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vmdasin))                     \
    match(construct = {target variant dispatch}, device = {arch(gen)})
void vmdAsin(const MKL_INT n, const double* a, double* y,
             MKL_INT64 mode) NOTHROW;

#if (_OPENMP >= 202011)
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vmdasini))                    \
    match(construct = {dispatch}, device = {arch(gen)})                        \
        append_args(interop(prefer_type("sycl", "level_zero"), targetsync))    \
            adjust_args(need_device_ptr                                        \
                        : a) adjust_args(need_device_ptr                       \
                                         : y)
#endif
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vmdasini))                    \
    match(construct = {target variant dispatch}, device = {arch(gen)})
void vmdAsinI(const MKL_INT n, const double* a, MKL_INT inca, double* y,
              MKL_INT incy, MKL_INT64 mode) NOTHROW;

#if (_OPENMP >= 202011)
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vcasin))                      \
    match(construct = {dispatch}, device = {arch(gen)})                        \
        append_args(interop(prefer_type("sycl", "level_zero"), targetsync))    \
            adjust_args(need_device_ptr                                        \
                        : a) adjust_args(need_device_ptr                       \
                                         : y)
#endif
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vcasin))                      \
    match(construct = {target variant dispatch}, device = {arch(gen)})
void vcAsin(const MKL_INT n, const MKL_Complex8* a, MKL_Complex8* y) NOTHROW;

#if (_OPENMP >= 202011)
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vcasini))                     \
    match(construct = {dispatch}, device = {arch(gen)})                        \
        append_args(interop(prefer_type("sycl", "level_zero"), targetsync))    \
            adjust_args(need_device_ptr                                        \
                        : a) adjust_args(need_device_ptr                       \
                                         : y)
#endif
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vcasini))                     \
    match(construct = {target variant dispatch}, device = {arch(gen)})
void vcAsinI(const MKL_INT n, const MKL_Complex8* a, MKL_INT inca,
             MKL_Complex8* y, MKL_INT incy) NOTHROW;

#if (_OPENMP >= 202011)
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vmcasin))                     \
    match(construct = {dispatch}, device = {arch(gen)})                        \
        append_args(interop(prefer_type("sycl", "level_zero"), targetsync))    \
            adjust_args(need_device_ptr                                        \
                        : a) adjust_args(need_device_ptr                       \
                                         : y)
#endif
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vmcasin))                     \
    match(construct = {target variant dispatch}, device = {arch(gen)})
void vmcAsin(const MKL_INT n, const MKL_Complex8* a, MKL_Complex8* y,
             MKL_INT64 mode) NOTHROW;

#if (_OPENMP >= 202011)
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vmcasini))                    \
    match(construct = {dispatch}, device = {arch(gen)})                        \
        append_args(interop(prefer_type("sycl", "level_zero"), targetsync))    \
            adjust_args(need_device_ptr                                        \
                        : a) adjust_args(need_device_ptr                       \
                                         : y)
#endif
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vmcasini))                    \
    match(construct = {target variant dispatch}, device = {arch(gen)})
void vmcAsinI(const MKL_INT n, const MKL_Complex8* a, MKL_INT inca,
              MKL_Complex8* y, MKL_INT incy, MKL_INT64 mode) NOTHROW;

#if (_OPENMP >= 202011)
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vzasin))                      \
    match(construct = {dispatch}, device = {arch(gen)})                        \
        append_args(interop(prefer_type("sycl", "level_zero"), targetsync))    \
            adjust_args(need_device_ptr                                        \
                        : a) adjust_args(need_device_ptr                       \
                                         : y)
#endif
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vzasin))                      \
    match(construct = {target variant dispatch}, device = {arch(gen)})
void vzAsin(const MKL_INT n, const MKL_Complex16* a, MKL_Complex16* y) NOTHROW;

#if (_OPENMP >= 202011)
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vzasini))                     \
    match(construct = {dispatch}, device = {arch(gen)})                        \
        append_args(interop(prefer_type("sycl", "level_zero"), targetsync))    \
            adjust_args(need_device_ptr                                        \
                        : a) adjust_args(need_device_ptr                       \
                                         : y)
#endif
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vzasini))                     \
    match(construct = {target variant dispatch}, device = {arch(gen)})
void vzAsinI(const MKL_INT n, const MKL_Complex16* a, MKL_INT inca,
             MKL_Complex16* y, MKL_INT incy) NOTHROW;

#if (_OPENMP >= 202011)
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vmzasin))                     \
    match(construct = {dispatch}, device = {arch(gen)})                        \
        append_args(interop(prefer_type("sycl", "level_zero"), targetsync))    \
            adjust_args(need_device_ptr                                        \
                        : a) adjust_args(need_device_ptr                       \
                                         : y)
#endif
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vmzasin))                     \
    match(construct = {target variant dispatch}, device = {arch(gen)})
void vmzAsin(const MKL_INT n, const MKL_Complex16* a, MKL_Complex16* y,
             MKL_INT64 mode) NOTHROW;

#if (_OPENMP >= 202011)
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vmzasini))                    \
    match(construct = {dispatch}, device = {arch(gen)})                        \
        append_args(interop(prefer_type("sycl", "level_zero"), targetsync))    \
            adjust_args(need_device_ptr                                        \
                        : a) adjust_args(need_device_ptr                       \
                                         : y)
#endif
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vmzasini))                    \
    match(construct = {target variant dispatch}, device = {arch(gen)})
void vmzAsinI(const MKL_INT n, const MKL_Complex16* a, MKL_INT inca,
              MKL_Complex16* y, MKL_INT incy, MKL_INT64 mode) NOTHROW;

// function asinh
#if (_OPENMP >= 202011)
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vsasinh))                     \
    match(construct = {dispatch}, device = {arch(gen)})                        \
        append_args(interop(prefer_type("sycl", "level_zero"), targetsync))    \
            adjust_args(need_device_ptr                                        \
                        : a) adjust_args(need_device_ptr                       \
                                         : y)
#endif
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vsasinh))                     \
    match(construct = {target variant dispatch}, device = {arch(gen)})
void vsAsinh(const MKL_INT n, const float* a, float* y) NOTHROW;

#if (_OPENMP >= 202011)
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vsasinhi))                    \
    match(construct = {dispatch}, device = {arch(gen)})                        \
        append_args(interop(prefer_type("sycl", "level_zero"), targetsync))    \
            adjust_args(need_device_ptr                                        \
                        : a) adjust_args(need_device_ptr                       \
                                         : y)
#endif
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vsasinhi))                    \
    match(construct = {target variant dispatch}, device = {arch(gen)})
void vsAsinhI(const MKL_INT n, const float* a, MKL_INT inca, float* y,
              MKL_INT incy) NOTHROW;

#if (_OPENMP >= 202011)
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vmsasinh))                    \
    match(construct = {dispatch}, device = {arch(gen)})                        \
        append_args(interop(prefer_type("sycl", "level_zero"), targetsync))    \
            adjust_args(need_device_ptr                                        \
                        : a) adjust_args(need_device_ptr                       \
                                         : y)
#endif
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vmsasinh))                    \
    match(construct = {target variant dispatch}, device = {arch(gen)})
void vmsAsinh(const MKL_INT n, const float* a, float* y,
              MKL_INT64 mode) NOTHROW;

#if (_OPENMP >= 202011)
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vmsasinhi))                   \
    match(construct = {dispatch}, device = {arch(gen)})                        \
        append_args(interop(prefer_type("sycl", "level_zero"), targetsync))    \
            adjust_args(need_device_ptr                                        \
                        : a) adjust_args(need_device_ptr                       \
                                         : y)
#endif
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vmsasinhi))                   \
    match(construct = {target variant dispatch}, device = {arch(gen)})
void vmsAsinhI(const MKL_INT n, const float* a, MKL_INT inca, float* y,
               MKL_INT incy, MKL_INT64 mode) NOTHROW;

#if (_OPENMP >= 202011)
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vdasinh))                     \
    match(construct = {dispatch}, device = {arch(gen)})                        \
        append_args(interop(prefer_type("sycl", "level_zero"), targetsync))    \
            adjust_args(need_device_ptr                                        \
                        : a) adjust_args(need_device_ptr                       \
                                         : y)
#endif
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vdasinh))                     \
    match(construct = {target variant dispatch}, device = {arch(gen)})
void vdAsinh(const MKL_INT n, const double* a, double* y) NOTHROW;

#if (_OPENMP >= 202011)
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vdasinhi))                    \
    match(construct = {dispatch}, device = {arch(gen)})                        \
        append_args(interop(prefer_type("sycl", "level_zero"), targetsync))    \
            adjust_args(need_device_ptr                                        \
                        : a) adjust_args(need_device_ptr                       \
                                         : y)
#endif
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vdasinhi))                    \
    match(construct = {target variant dispatch}, device = {arch(gen)})
void vdAsinhI(const MKL_INT n, const double* a, MKL_INT inca, double* y,
              MKL_INT incy) NOTHROW;

#if (_OPENMP >= 202011)
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vmdasinh))                    \
    match(construct = {dispatch}, device = {arch(gen)})                        \
        append_args(interop(prefer_type("sycl", "level_zero"), targetsync))    \
            adjust_args(need_device_ptr                                        \
                        : a) adjust_args(need_device_ptr                       \
                                         : y)
#endif
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vmdasinh))                    \
    match(construct = {target variant dispatch}, device = {arch(gen)})
void vmdAsinh(const MKL_INT n, const double* a, double* y,
              MKL_INT64 mode) NOTHROW;

#if (_OPENMP >= 202011)
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vmdasinhi))                   \
    match(construct = {dispatch}, device = {arch(gen)})                        \
        append_args(interop(prefer_type("sycl", "level_zero"), targetsync))    \
            adjust_args(need_device_ptr                                        \
                        : a) adjust_args(need_device_ptr                       \
                                         : y)
#endif
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vmdasinhi))                   \
    match(construct = {target variant dispatch}, device = {arch(gen)})
void vmdAsinhI(const MKL_INT n, const double* a, MKL_INT inca, double* y,
               MKL_INT incy, MKL_INT64 mode) NOTHROW;

#if (_OPENMP >= 202011)
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vcasinh))                     \
    match(construct = {dispatch}, device = {arch(gen)})                        \
        append_args(interop(prefer_type("sycl", "level_zero"), targetsync))    \
            adjust_args(need_device_ptr                                        \
                        : a) adjust_args(need_device_ptr                       \
                                         : y)
#endif
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vcasinh))                     \
    match(construct = {target variant dispatch}, device = {arch(gen)})
void vcAsinh(const MKL_INT n, const MKL_Complex8* a, MKL_Complex8* y) NOTHROW;

#if (_OPENMP >= 202011)
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vcasinhi))                    \
    match(construct = {dispatch}, device = {arch(gen)})                        \
        append_args(interop(prefer_type("sycl", "level_zero"), targetsync))    \
            adjust_args(need_device_ptr                                        \
                        : a) adjust_args(need_device_ptr                       \
                                         : y)
#endif
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vcasinhi))                    \
    match(construct = {target variant dispatch}, device = {arch(gen)})
void vcAsinhI(const MKL_INT n, const MKL_Complex8* a, MKL_INT inca,
              MKL_Complex8* y, MKL_INT incy) NOTHROW;

#if (_OPENMP >= 202011)
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vmcasinh))                    \
    match(construct = {dispatch}, device = {arch(gen)})                        \
        append_args(interop(prefer_type("sycl", "level_zero"), targetsync))    \
            adjust_args(need_device_ptr                                        \
                        : a) adjust_args(need_device_ptr                       \
                                         : y)
#endif
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vmcasinh))                    \
    match(construct = {target variant dispatch}, device = {arch(gen)})
void vmcAsinh(const MKL_INT n, const MKL_Complex8* a, MKL_Complex8* y,
              MKL_INT64 mode) NOTHROW;

#if (_OPENMP >= 202011)
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vmcasinhi))                   \
    match(construct = {dispatch}, device = {arch(gen)})                        \
        append_args(interop(prefer_type("sycl", "level_zero"), targetsync))    \
            adjust_args(need_device_ptr                                        \
                        : a) adjust_args(need_device_ptr                       \
                                         : y)
#endif
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vmcasinhi))                   \
    match(construct = {target variant dispatch}, device = {arch(gen)})
void vmcAsinhI(const MKL_INT n, const MKL_Complex8* a, MKL_INT inca,
               MKL_Complex8* y, MKL_INT incy, MKL_INT64 mode) NOTHROW;

#if (_OPENMP >= 202011)
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vzasinh))                     \
    match(construct = {dispatch}, device = {arch(gen)})                        \
        append_args(interop(prefer_type("sycl", "level_zero"), targetsync))    \
            adjust_args(need_device_ptr                                        \
                        : a) adjust_args(need_device_ptr                       \
                                         : y)
#endif
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vzasinh))                     \
    match(construct = {target variant dispatch}, device = {arch(gen)})
void vzAsinh(const MKL_INT n, const MKL_Complex16* a, MKL_Complex16* y) NOTHROW;

#if (_OPENMP >= 202011)
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vzasinhi))                    \
    match(construct = {dispatch}, device = {arch(gen)})                        \
        append_args(interop(prefer_type("sycl", "level_zero"), targetsync))    \
            adjust_args(need_device_ptr                                        \
                        : a) adjust_args(need_device_ptr                       \
                                         : y)
#endif
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vzasinhi))                    \
    match(construct = {target variant dispatch}, device = {arch(gen)})
void vzAsinhI(const MKL_INT n, const MKL_Complex16* a, MKL_INT inca,
              MKL_Complex16* y, MKL_INT incy) NOTHROW;

#if (_OPENMP >= 202011)
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vmzasinh))                    \
    match(construct = {dispatch}, device = {arch(gen)})                        \
        append_args(interop(prefer_type("sycl", "level_zero"), targetsync))    \
            adjust_args(need_device_ptr                                        \
                        : a) adjust_args(need_device_ptr                       \
                                         : y)
#endif
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vmzasinh))                    \
    match(construct = {target variant dispatch}, device = {arch(gen)})
void vmzAsinh(const MKL_INT n, const MKL_Complex16* a, MKL_Complex16* y,
              MKL_INT64 mode) NOTHROW;

#if (_OPENMP >= 202011)
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vmzasinhi))                   \
    match(construct = {dispatch}, device = {arch(gen)})                        \
        append_args(interop(prefer_type("sycl", "level_zero"), targetsync))    \
            adjust_args(need_device_ptr                                        \
                        : a) adjust_args(need_device_ptr                       \
                                         : y)
#endif
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vmzasinhi))                   \
    match(construct = {target variant dispatch}, device = {arch(gen)})
void vmzAsinhI(const MKL_INT n, const MKL_Complex16* a, MKL_INT inca,
               MKL_Complex16* y, MKL_INT incy, MKL_INT64 mode) NOTHROW;

// function asinpi
#if (_OPENMP >= 202011)
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vsasinpi))                    \
    match(construct = {dispatch}, device = {arch(gen)})                        \
        append_args(interop(prefer_type("sycl", "level_zero"), targetsync))    \
            adjust_args(need_device_ptr                                        \
                        : a) adjust_args(need_device_ptr                       \
                                         : y)
#endif
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vsasinpi))                    \
    match(construct = {target variant dispatch}, device = {arch(gen)})
void vsAsinpi(const MKL_INT n, const float* a, float* y) NOTHROW;

#if (_OPENMP >= 202011)
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vsasinpii))                   \
    match(construct = {dispatch}, device = {arch(gen)})                        \
        append_args(interop(prefer_type("sycl", "level_zero"), targetsync))    \
            adjust_args(need_device_ptr                                        \
                        : a) adjust_args(need_device_ptr                       \
                                         : y)
#endif
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vsasinpii))                   \
    match(construct = {target variant dispatch}, device = {arch(gen)})
void vsAsinpiI(const MKL_INT n, const float* a, MKL_INT inca, float* y,
               MKL_INT incy) NOTHROW;

#if (_OPENMP >= 202011)
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vmsasinpi))                   \
    match(construct = {dispatch}, device = {arch(gen)})                        \
        append_args(interop(prefer_type("sycl", "level_zero"), targetsync))    \
            adjust_args(need_device_ptr                                        \
                        : a) adjust_args(need_device_ptr                       \
                                         : y)
#endif
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vmsasinpi))                   \
    match(construct = {target variant dispatch}, device = {arch(gen)})
void vmsAsinpi(const MKL_INT n, const float* a, float* y,
               MKL_INT64 mode) NOTHROW;

#if (_OPENMP >= 202011)
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vmsasinpii))                  \
    match(construct = {dispatch}, device = {arch(gen)})                        \
        append_args(interop(prefer_type("sycl", "level_zero"), targetsync))    \
            adjust_args(need_device_ptr                                        \
                        : a) adjust_args(need_device_ptr                       \
                                         : y)
#endif
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vmsasinpii))                  \
    match(construct = {target variant dispatch}, device = {arch(gen)})
void vmsAsinpiI(const MKL_INT n, const float* a, MKL_INT inca, float* y,
                MKL_INT incy, MKL_INT64 mode) NOTHROW;

#if (_OPENMP >= 202011)
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vdasinpi))                    \
    match(construct = {dispatch}, device = {arch(gen)})                        \
        append_args(interop(prefer_type("sycl", "level_zero"), targetsync))    \
            adjust_args(need_device_ptr                                        \
                        : a) adjust_args(need_device_ptr                       \
                                         : y)
#endif
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vdasinpi))                    \
    match(construct = {target variant dispatch}, device = {arch(gen)})
void vdAsinpi(const MKL_INT n, const double* a, double* y) NOTHROW;

#if (_OPENMP >= 202011)
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vdasinpii))                   \
    match(construct = {dispatch}, device = {arch(gen)})                        \
        append_args(interop(prefer_type("sycl", "level_zero"), targetsync))    \
            adjust_args(need_device_ptr                                        \
                        : a) adjust_args(need_device_ptr                       \
                                         : y)
#endif
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vdasinpii))                   \
    match(construct = {target variant dispatch}, device = {arch(gen)})
void vdAsinpiI(const MKL_INT n, const double* a, MKL_INT inca, double* y,
               MKL_INT incy) NOTHROW;

#if (_OPENMP >= 202011)
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vmdasinpi))                   \
    match(construct = {dispatch}, device = {arch(gen)})                        \
        append_args(interop(prefer_type("sycl", "level_zero"), targetsync))    \
            adjust_args(need_device_ptr                                        \
                        : a) adjust_args(need_device_ptr                       \
                                         : y)
#endif
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vmdasinpi))                   \
    match(construct = {target variant dispatch}, device = {arch(gen)})
void vmdAsinpi(const MKL_INT n, const double* a, double* y,
               MKL_INT64 mode) NOTHROW;

#if (_OPENMP >= 202011)
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vmdasinpii))                  \
    match(construct = {dispatch}, device = {arch(gen)})                        \
        append_args(interop(prefer_type("sycl", "level_zero"), targetsync))    \
            adjust_args(need_device_ptr                                        \
                        : a) adjust_args(need_device_ptr                       \
                                         : y)
#endif
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vmdasinpii))                  \
    match(construct = {target variant dispatch}, device = {arch(gen)})
void vmdAsinpiI(const MKL_INT n, const double* a, MKL_INT inca, double* y,
                MKL_INT incy, MKL_INT64 mode) NOTHROW;

// function atan
#if (_OPENMP >= 202011)
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vsatan))                      \
    match(construct = {dispatch}, device = {arch(gen)})                        \
        append_args(interop(prefer_type("sycl", "level_zero"), targetsync))    \
            adjust_args(need_device_ptr                                        \
                        : a) adjust_args(need_device_ptr                       \
                                         : y)
#endif
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vsatan))                      \
    match(construct = {target variant dispatch}, device = {arch(gen)})
void vsAtan(const MKL_INT n, const float* a, float* y) NOTHROW;

#if (_OPENMP >= 202011)
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vsatani))                     \
    match(construct = {dispatch}, device = {arch(gen)})                        \
        append_args(interop(prefer_type("sycl", "level_zero"), targetsync))    \
            adjust_args(need_device_ptr                                        \
                        : a) adjust_args(need_device_ptr                       \
                                         : y)
#endif
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vsatani))                     \
    match(construct = {target variant dispatch}, device = {arch(gen)})
void vsAtanI(const MKL_INT n, const float* a, MKL_INT inca, float* y,
             MKL_INT incy) NOTHROW;

#if (_OPENMP >= 202011)
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vmsatan))                     \
    match(construct = {dispatch}, device = {arch(gen)})                        \
        append_args(interop(prefer_type("sycl", "level_zero"), targetsync))    \
            adjust_args(need_device_ptr                                        \
                        : a) adjust_args(need_device_ptr                       \
                                         : y)
#endif
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vmsatan))                     \
    match(construct = {target variant dispatch}, device = {arch(gen)})
void vmsAtan(const MKL_INT n, const float* a, float* y, MKL_INT64 mode) NOTHROW;

#if (_OPENMP >= 202011)
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vmsatani))                    \
    match(construct = {dispatch}, device = {arch(gen)})                        \
        append_args(interop(prefer_type("sycl", "level_zero"), targetsync))    \
            adjust_args(need_device_ptr                                        \
                        : a) adjust_args(need_device_ptr                       \
                                         : y)
#endif
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vmsatani))                    \
    match(construct = {target variant dispatch}, device = {arch(gen)})
void vmsAtanI(const MKL_INT n, const float* a, MKL_INT inca, float* y,
              MKL_INT incy, MKL_INT64 mode) NOTHROW;

#if (_OPENMP >= 202011)
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vdatan))                      \
    match(construct = {dispatch}, device = {arch(gen)})                        \
        append_args(interop(prefer_type("sycl", "level_zero"), targetsync))    \
            adjust_args(need_device_ptr                                        \
                        : a) adjust_args(need_device_ptr                       \
                                         : y)
#endif
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vdatan))                      \
    match(construct = {target variant dispatch}, device = {arch(gen)})
void vdAtan(const MKL_INT n, const double* a, double* y) NOTHROW;

#if (_OPENMP >= 202011)
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vdatani))                     \
    match(construct = {dispatch}, device = {arch(gen)})                        \
        append_args(interop(prefer_type("sycl", "level_zero"), targetsync))    \
            adjust_args(need_device_ptr                                        \
                        : a) adjust_args(need_device_ptr                       \
                                         : y)
#endif
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vdatani))                     \
    match(construct = {target variant dispatch}, device = {arch(gen)})
void vdAtanI(const MKL_INT n, const double* a, MKL_INT inca, double* y,
             MKL_INT incy) NOTHROW;

#if (_OPENMP >= 202011)
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vmdatan))                     \
    match(construct = {dispatch}, device = {arch(gen)})                        \
        append_args(interop(prefer_type("sycl", "level_zero"), targetsync))    \
            adjust_args(need_device_ptr                                        \
                        : a) adjust_args(need_device_ptr                       \
                                         : y)
#endif
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vmdatan))                     \
    match(construct = {target variant dispatch}, device = {arch(gen)})
void vmdAtan(const MKL_INT n, const double* a, double* y,
             MKL_INT64 mode) NOTHROW;

#if (_OPENMP >= 202011)
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vmdatani))                    \
    match(construct = {dispatch}, device = {arch(gen)})                        \
        append_args(interop(prefer_type("sycl", "level_zero"), targetsync))    \
            adjust_args(need_device_ptr                                        \
                        : a) adjust_args(need_device_ptr                       \
                                         : y)
#endif
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vmdatani))                    \
    match(construct = {target variant dispatch}, device = {arch(gen)})
void vmdAtanI(const MKL_INT n, const double* a, MKL_INT inca, double* y,
              MKL_INT incy, MKL_INT64 mode) NOTHROW;

#if (_OPENMP >= 202011)
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vcatan))                      \
    match(construct = {dispatch}, device = {arch(gen)})                        \
        append_args(interop(prefer_type("sycl", "level_zero"), targetsync))    \
            adjust_args(need_device_ptr                                        \
                        : a) adjust_args(need_device_ptr                       \
                                         : y)
#endif
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vcatan))                      \
    match(construct = {target variant dispatch}, device = {arch(gen)})
void vcAtan(const MKL_INT n, const MKL_Complex8* a, MKL_Complex8* y) NOTHROW;

#if (_OPENMP >= 202011)
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vcatani))                     \
    match(construct = {dispatch}, device = {arch(gen)})                        \
        append_args(interop(prefer_type("sycl", "level_zero"), targetsync))    \
            adjust_args(need_device_ptr                                        \
                        : a) adjust_args(need_device_ptr                       \
                                         : y)
#endif
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vcatani))                     \
    match(construct = {target variant dispatch}, device = {arch(gen)})
void vcAtanI(const MKL_INT n, const MKL_Complex8* a, MKL_INT inca,
             MKL_Complex8* y, MKL_INT incy) NOTHROW;

#if (_OPENMP >= 202011)
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vmcatan))                     \
    match(construct = {dispatch}, device = {arch(gen)})                        \
        append_args(interop(prefer_type("sycl", "level_zero"), targetsync))    \
            adjust_args(need_device_ptr                                        \
                        : a) adjust_args(need_device_ptr                       \
                                         : y)
#endif
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vmcatan))                     \
    match(construct = {target variant dispatch}, device = {arch(gen)})
void vmcAtan(const MKL_INT n, const MKL_Complex8* a, MKL_Complex8* y,
             MKL_INT64 mode) NOTHROW;

#if (_OPENMP >= 202011)
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vmcatani))                    \
    match(construct = {dispatch}, device = {arch(gen)})                        \
        append_args(interop(prefer_type("sycl", "level_zero"), targetsync))    \
            adjust_args(need_device_ptr                                        \
                        : a) adjust_args(need_device_ptr                       \
                                         : y)
#endif
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vmcatani))                    \
    match(construct = {target variant dispatch}, device = {arch(gen)})
void vmcAtanI(const MKL_INT n, const MKL_Complex8* a, MKL_INT inca,
              MKL_Complex8* y, MKL_INT incy, MKL_INT64 mode) NOTHROW;

#if (_OPENMP >= 202011)
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vzatan))                      \
    match(construct = {dispatch}, device = {arch(gen)})                        \
        append_args(interop(prefer_type("sycl", "level_zero"), targetsync))    \
            adjust_args(need_device_ptr                                        \
                        : a) adjust_args(need_device_ptr                       \
                                         : y)
#endif
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vzatan))                      \
    match(construct = {target variant dispatch}, device = {arch(gen)})
void vzAtan(const MKL_INT n, const MKL_Complex16* a, MKL_Complex16* y) NOTHROW;

#if (_OPENMP >= 202011)
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vzatani))                     \
    match(construct = {dispatch}, device = {arch(gen)})                        \
        append_args(interop(prefer_type("sycl", "level_zero"), targetsync))    \
            adjust_args(need_device_ptr                                        \
                        : a) adjust_args(need_device_ptr                       \
                                         : y)
#endif
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vzatani))                     \
    match(construct = {target variant dispatch}, device = {arch(gen)})
void vzAtanI(const MKL_INT n, const MKL_Complex16* a, MKL_INT inca,
             MKL_Complex16* y, MKL_INT incy) NOTHROW;

#if (_OPENMP >= 202011)
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vmzatan))                     \
    match(construct = {dispatch}, device = {arch(gen)})                        \
        append_args(interop(prefer_type("sycl", "level_zero"), targetsync))    \
            adjust_args(need_device_ptr                                        \
                        : a) adjust_args(need_device_ptr                       \
                                         : y)
#endif
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vmzatan))                     \
    match(construct = {target variant dispatch}, device = {arch(gen)})
void vmzAtan(const MKL_INT n, const MKL_Complex16* a, MKL_Complex16* y,
             MKL_INT64 mode) NOTHROW;

#if (_OPENMP >= 202011)
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vmzatani))                    \
    match(construct = {dispatch}, device = {arch(gen)})                        \
        append_args(interop(prefer_type("sycl", "level_zero"), targetsync))    \
            adjust_args(need_device_ptr                                        \
                        : a) adjust_args(need_device_ptr                       \
                                         : y)
#endif
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vmzatani))                    \
    match(construct = {target variant dispatch}, device = {arch(gen)})
void vmzAtanI(const MKL_INT n, const MKL_Complex16* a, MKL_INT inca,
              MKL_Complex16* y, MKL_INT incy, MKL_INT64 mode) NOTHROW;

// function atan2
#if (_OPENMP >= 202011)
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vsatan2))                     \
    match(construct = {dispatch}, device = {arch(gen)})                        \
        append_args(interop(prefer_type("sycl", "level_zero"), targetsync))    \
            adjust_args(need_device_ptr                                        \
                        : a) adjust_args(need_device_ptr                       \
                                         : b) adjust_args(need_device_ptr      \
                                                          : y)
#endif
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vsatan2))                     \
    match(construct = {target variant dispatch}, device = {arch(gen)})
void vsAtan2(const MKL_INT n, const float* a, const float* b, float* y) NOTHROW;

#if (_OPENMP >= 202011)
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vsatan2i))                    \
    match(construct = {dispatch}, device = {arch(gen)})                        \
        append_args(interop(prefer_type("sycl", "level_zero"), targetsync))    \
            adjust_args(need_device_ptr                                        \
                        : a) adjust_args(need_device_ptr                       \
                                         : b) adjust_args(need_device_ptr      \
                                                          : y)
#endif
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vsatan2i))                    \
    match(construct = {target variant dispatch}, device = {arch(gen)})
void vsAtan2I(const MKL_INT n, const float* a, MKL_INT inca, const float* b,
              MKL_INT incb, float* y, MKL_INT incy) NOTHROW;

#if (_OPENMP >= 202011)
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vmsatan2))                    \
    match(construct = {dispatch}, device = {arch(gen)})                        \
        append_args(interop(prefer_type("sycl", "level_zero"), targetsync))    \
            adjust_args(need_device_ptr                                        \
                        : a) adjust_args(need_device_ptr                       \
                                         : b) adjust_args(need_device_ptr      \
                                                          : y)
#endif
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vmsatan2))                    \
    match(construct = {target variant dispatch}, device = {arch(gen)})
void vmsAtan2(const MKL_INT n, const float* a, const float* b, float* y,
              MKL_INT64 mode) NOTHROW;

#if (_OPENMP >= 202011)
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vmsatan2i))                   \
    match(construct = {dispatch}, device = {arch(gen)})                        \
        append_args(interop(prefer_type("sycl", "level_zero"), targetsync))    \
            adjust_args(need_device_ptr                                        \
                        : a) adjust_args(need_device_ptr                       \
                                         : b) adjust_args(need_device_ptr      \
                                                          : y)
#endif
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vmsatan2i))                   \
    match(construct = {target variant dispatch}, device = {arch(gen)})
void vmsAtan2I(const MKL_INT n, const float* a, MKL_INT inca, const float* b,
               MKL_INT incb, float* y, MKL_INT incy, MKL_INT64 mode) NOTHROW;

#if (_OPENMP >= 202011)
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vdatan2))                     \
    match(construct = {dispatch}, device = {arch(gen)})                        \
        append_args(interop(prefer_type("sycl", "level_zero"), targetsync))    \
            adjust_args(need_device_ptr                                        \
                        : a) adjust_args(need_device_ptr                       \
                                         : b) adjust_args(need_device_ptr      \
                                                          : y)
#endif
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vdatan2))                     \
    match(construct = {target variant dispatch}, device = {arch(gen)})
void vdAtan2(const MKL_INT n, const double* a, const double* b,
             double* y) NOTHROW;

#if (_OPENMP >= 202011)
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vdatan2i))                    \
    match(construct = {dispatch}, device = {arch(gen)})                        \
        append_args(interop(prefer_type("sycl", "level_zero"), targetsync))    \
            adjust_args(need_device_ptr                                        \
                        : a) adjust_args(need_device_ptr                       \
                                         : b) adjust_args(need_device_ptr      \
                                                          : y)
#endif
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vdatan2i))                    \
    match(construct = {target variant dispatch}, device = {arch(gen)})
void vdAtan2I(const MKL_INT n, const double* a, MKL_INT inca, const double* b,
              MKL_INT incb, double* y, MKL_INT incy) NOTHROW;

#if (_OPENMP >= 202011)
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vmdatan2))                    \
    match(construct = {dispatch}, device = {arch(gen)})                        \
        append_args(interop(prefer_type("sycl", "level_zero"), targetsync))    \
            adjust_args(need_device_ptr                                        \
                        : a) adjust_args(need_device_ptr                       \
                                         : b) adjust_args(need_device_ptr      \
                                                          : y)
#endif
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vmdatan2))                    \
    match(construct = {target variant dispatch}, device = {arch(gen)})
void vmdAtan2(const MKL_INT n, const double* a, const double* b, double* y,
              MKL_INT64 mode) NOTHROW;

#if (_OPENMP >= 202011)
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vmdatan2i))                   \
    match(construct = {dispatch}, device = {arch(gen)})                        \
        append_args(interop(prefer_type("sycl", "level_zero"), targetsync))    \
            adjust_args(need_device_ptr                                        \
                        : a) adjust_args(need_device_ptr                       \
                                         : b) adjust_args(need_device_ptr      \
                                                          : y)
#endif
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vmdatan2i))                   \
    match(construct = {target variant dispatch}, device = {arch(gen)})
void vmdAtan2I(const MKL_INT n, const double* a, MKL_INT inca, const double* b,
               MKL_INT incb, double* y, MKL_INT incy, MKL_INT64 mode) NOTHROW;

// function atan2pi
#if (_OPENMP >= 202011)
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vsatan2pi))                   \
    match(construct = {dispatch}, device = {arch(gen)})                        \
        append_args(interop(prefer_type("sycl", "level_zero"), targetsync))    \
            adjust_args(need_device_ptr                                        \
                        : a) adjust_args(need_device_ptr                       \
                                         : b) adjust_args(need_device_ptr      \
                                                          : y)
#endif
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vsatan2pi))                   \
    match(construct = {target variant dispatch}, device = {arch(gen)})
void vsAtan2pi(const MKL_INT n, const float* a, const float* b,
               float* y) NOTHROW;

#if (_OPENMP >= 202011)
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vsatan2pii))                  \
    match(construct = {dispatch}, device = {arch(gen)})                        \
        append_args(interop(prefer_type("sycl", "level_zero"), targetsync))    \
            adjust_args(need_device_ptr                                        \
                        : a) adjust_args(need_device_ptr                       \
                                         : b) adjust_args(need_device_ptr      \
                                                          : y)
#endif
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vsatan2pii))                  \
    match(construct = {target variant dispatch}, device = {arch(gen)})
void vsAtan2piI(const MKL_INT n, const float* a, MKL_INT inca, const float* b,
                MKL_INT incb, float* y, MKL_INT incy) NOTHROW;

#if (_OPENMP >= 202011)
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vmsatan2pi))                  \
    match(construct = {dispatch}, device = {arch(gen)})                        \
        append_args(interop(prefer_type("sycl", "level_zero"), targetsync))    \
            adjust_args(need_device_ptr                                        \
                        : a) adjust_args(need_device_ptr                       \
                                         : b) adjust_args(need_device_ptr      \
                                                          : y)
#endif
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vmsatan2pi))                  \
    match(construct = {target variant dispatch}, device = {arch(gen)})
void vmsAtan2pi(const MKL_INT n, const float* a, const float* b, float* y,
                MKL_INT64 mode) NOTHROW;

#if (_OPENMP >= 202011)
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vmsatan2pii))                 \
    match(construct = {dispatch}, device = {arch(gen)})                        \
        append_args(interop(prefer_type("sycl", "level_zero"), targetsync))    \
            adjust_args(need_device_ptr                                        \
                        : a) adjust_args(need_device_ptr                       \
                                         : b) adjust_args(need_device_ptr      \
                                                          : y)
#endif
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vmsatan2pii))                 \
    match(construct = {target variant dispatch}, device = {arch(gen)})
void vmsAtan2piI(const MKL_INT n, const float* a, MKL_INT inca, const float* b,
                 MKL_INT incb, float* y, MKL_INT incy, MKL_INT64 mode) NOTHROW;

#if (_OPENMP >= 202011)
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vdatan2pi))                   \
    match(construct = {dispatch}, device = {arch(gen)})                        \
        append_args(interop(prefer_type("sycl", "level_zero"), targetsync))    \
            adjust_args(need_device_ptr                                        \
                        : a) adjust_args(need_device_ptr                       \
                                         : b) adjust_args(need_device_ptr      \
                                                          : y)
#endif
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vdatan2pi))                   \
    match(construct = {target variant dispatch}, device = {arch(gen)})
void vdAtan2pi(const MKL_INT n, const double* a, const double* b,
               double* y) NOTHROW;

#if (_OPENMP >= 202011)
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vdatan2pii))                  \
    match(construct = {dispatch}, device = {arch(gen)})                        \
        append_args(interop(prefer_type("sycl", "level_zero"), targetsync))    \
            adjust_args(need_device_ptr                                        \
                        : a) adjust_args(need_device_ptr                       \
                                         : b) adjust_args(need_device_ptr      \
                                                          : y)
#endif
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vdatan2pii))                  \
    match(construct = {target variant dispatch}, device = {arch(gen)})
void vdAtan2piI(const MKL_INT n, const double* a, MKL_INT inca, const double* b,
                MKL_INT incb, double* y, MKL_INT incy) NOTHROW;

#if (_OPENMP >= 202011)
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vmdatan2pi))                  \
    match(construct = {dispatch}, device = {arch(gen)})                        \
        append_args(interop(prefer_type("sycl", "level_zero"), targetsync))    \
            adjust_args(need_device_ptr                                        \
                        : a) adjust_args(need_device_ptr                       \
                                         : b) adjust_args(need_device_ptr      \
                                                          : y)
#endif
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vmdatan2pi))                  \
    match(construct = {target variant dispatch}, device = {arch(gen)})
void vmdAtan2pi(const MKL_INT n, const double* a, const double* b, double* y,
                MKL_INT64 mode) NOTHROW;

#if (_OPENMP >= 202011)
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vmdatan2pii))                 \
    match(construct = {dispatch}, device = {arch(gen)})                        \
        append_args(interop(prefer_type("sycl", "level_zero"), targetsync))    \
            adjust_args(need_device_ptr                                        \
                        : a) adjust_args(need_device_ptr                       \
                                         : b) adjust_args(need_device_ptr      \
                                                          : y)
#endif
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vmdatan2pii))                 \
    match(construct = {target variant dispatch}, device = {arch(gen)})
void vmdAtan2piI(const MKL_INT n, const double* a, MKL_INT inca,
                 const double* b, MKL_INT incb, double* y, MKL_INT incy,
                 MKL_INT64 mode) NOTHROW;

// function atanh
#if (_OPENMP >= 202011)
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vsatanh))                     \
    match(construct = {dispatch}, device = {arch(gen)})                        \
        append_args(interop(prefer_type("sycl", "level_zero"), targetsync))    \
            adjust_args(need_device_ptr                                        \
                        : a) adjust_args(need_device_ptr                       \
                                         : y)
#endif
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vsatanh))                     \
    match(construct = {target variant dispatch}, device = {arch(gen)})
void vsAtanh(const MKL_INT n, const float* a, float* y) NOTHROW;

#if (_OPENMP >= 202011)
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vsatanhi))                    \
    match(construct = {dispatch}, device = {arch(gen)})                        \
        append_args(interop(prefer_type("sycl", "level_zero"), targetsync))    \
            adjust_args(need_device_ptr                                        \
                        : a) adjust_args(need_device_ptr                       \
                                         : y)
#endif
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vsatanhi))                    \
    match(construct = {target variant dispatch}, device = {arch(gen)})
void vsAtanhI(const MKL_INT n, const float* a, MKL_INT inca, float* y,
              MKL_INT incy) NOTHROW;

#if (_OPENMP >= 202011)
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vmsatanh))                    \
    match(construct = {dispatch}, device = {arch(gen)})                        \
        append_args(interop(prefer_type("sycl", "level_zero"), targetsync))    \
            adjust_args(need_device_ptr                                        \
                        : a) adjust_args(need_device_ptr                       \
                                         : y)
#endif
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vmsatanh))                    \
    match(construct = {target variant dispatch}, device = {arch(gen)})
void vmsAtanh(const MKL_INT n, const float* a, float* y,
              MKL_INT64 mode) NOTHROW;

#if (_OPENMP >= 202011)
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vmsatanhi))                   \
    match(construct = {dispatch}, device = {arch(gen)})                        \
        append_args(interop(prefer_type("sycl", "level_zero"), targetsync))    \
            adjust_args(need_device_ptr                                        \
                        : a) adjust_args(need_device_ptr                       \
                                         : y)
#endif
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vmsatanhi))                   \
    match(construct = {target variant dispatch}, device = {arch(gen)})
void vmsAtanhI(const MKL_INT n, const float* a, MKL_INT inca, float* y,
               MKL_INT incy, MKL_INT64 mode) NOTHROW;

#if (_OPENMP >= 202011)
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vdatanh))                     \
    match(construct = {dispatch}, device = {arch(gen)})                        \
        append_args(interop(prefer_type("sycl", "level_zero"), targetsync))    \
            adjust_args(need_device_ptr                                        \
                        : a) adjust_args(need_device_ptr                       \
                                         : y)
#endif
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vdatanh))                     \
    match(construct = {target variant dispatch}, device = {arch(gen)})
void vdAtanh(const MKL_INT n, const double* a, double* y) NOTHROW;

#if (_OPENMP >= 202011)
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vdatanhi))                    \
    match(construct = {dispatch}, device = {arch(gen)})                        \
        append_args(interop(prefer_type("sycl", "level_zero"), targetsync))    \
            adjust_args(need_device_ptr                                        \
                        : a) adjust_args(need_device_ptr                       \
                                         : y)
#endif
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vdatanhi))                    \
    match(construct = {target variant dispatch}, device = {arch(gen)})
void vdAtanhI(const MKL_INT n, const double* a, MKL_INT inca, double* y,
              MKL_INT incy) NOTHROW;

#if (_OPENMP >= 202011)
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vmdatanh))                    \
    match(construct = {dispatch}, device = {arch(gen)})                        \
        append_args(interop(prefer_type("sycl", "level_zero"), targetsync))    \
            adjust_args(need_device_ptr                                        \
                        : a) adjust_args(need_device_ptr                       \
                                         : y)
#endif
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vmdatanh))                    \
    match(construct = {target variant dispatch}, device = {arch(gen)})
void vmdAtanh(const MKL_INT n, const double* a, double* y,
              MKL_INT64 mode) NOTHROW;

#if (_OPENMP >= 202011)
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vmdatanhi))                   \
    match(construct = {dispatch}, device = {arch(gen)})                        \
        append_args(interop(prefer_type("sycl", "level_zero"), targetsync))    \
            adjust_args(need_device_ptr                                        \
                        : a) adjust_args(need_device_ptr                       \
                                         : y)
#endif
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vmdatanhi))                   \
    match(construct = {target variant dispatch}, device = {arch(gen)})
void vmdAtanhI(const MKL_INT n, const double* a, MKL_INT inca, double* y,
               MKL_INT incy, MKL_INT64 mode) NOTHROW;

#if (_OPENMP >= 202011)
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vcatanh))                     \
    match(construct = {dispatch}, device = {arch(gen)})                        \
        append_args(interop(prefer_type("sycl", "level_zero"), targetsync))    \
            adjust_args(need_device_ptr                                        \
                        : a) adjust_args(need_device_ptr                       \
                                         : y)
#endif
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vcatanh))                     \
    match(construct = {target variant dispatch}, device = {arch(gen)})
void vcAtanh(const MKL_INT n, const MKL_Complex8* a, MKL_Complex8* y) NOTHROW;

#if (_OPENMP >= 202011)
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vcatanhi))                    \
    match(construct = {dispatch}, device = {arch(gen)})                        \
        append_args(interop(prefer_type("sycl", "level_zero"), targetsync))    \
            adjust_args(need_device_ptr                                        \
                        : a) adjust_args(need_device_ptr                       \
                                         : y)
#endif
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vcatanhi))                    \
    match(construct = {target variant dispatch}, device = {arch(gen)})
void vcAtanhI(const MKL_INT n, const MKL_Complex8* a, MKL_INT inca,
              MKL_Complex8* y, MKL_INT incy) NOTHROW;

#if (_OPENMP >= 202011)
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vmcatanh))                    \
    match(construct = {dispatch}, device = {arch(gen)})                        \
        append_args(interop(prefer_type("sycl", "level_zero"), targetsync))    \
            adjust_args(need_device_ptr                                        \
                        : a) adjust_args(need_device_ptr                       \
                                         : y)
#endif
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vmcatanh))                    \
    match(construct = {target variant dispatch}, device = {arch(gen)})
void vmcAtanh(const MKL_INT n, const MKL_Complex8* a, MKL_Complex8* y,
              MKL_INT64 mode) NOTHROW;

#if (_OPENMP >= 202011)
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vmcatanhi))                   \
    match(construct = {dispatch}, device = {arch(gen)})                        \
        append_args(interop(prefer_type("sycl", "level_zero"), targetsync))    \
            adjust_args(need_device_ptr                                        \
                        : a) adjust_args(need_device_ptr                       \
                                         : y)
#endif
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vmcatanhi))                   \
    match(construct = {target variant dispatch}, device = {arch(gen)})
void vmcAtanhI(const MKL_INT n, const MKL_Complex8* a, MKL_INT inca,
               MKL_Complex8* y, MKL_INT incy, MKL_INT64 mode) NOTHROW;

#if (_OPENMP >= 202011)
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vzatanh))                     \
    match(construct = {dispatch}, device = {arch(gen)})                        \
        append_args(interop(prefer_type("sycl", "level_zero"), targetsync))    \
            adjust_args(need_device_ptr                                        \
                        : a) adjust_args(need_device_ptr                       \
                                         : y)
#endif
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vzatanh))                     \
    match(construct = {target variant dispatch}, device = {arch(gen)})
void vzAtanh(const MKL_INT n, const MKL_Complex16* a, MKL_Complex16* y) NOTHROW;

#if (_OPENMP >= 202011)
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vzatanhi))                    \
    match(construct = {dispatch}, device = {arch(gen)})                        \
        append_args(interop(prefer_type("sycl", "level_zero"), targetsync))    \
            adjust_args(need_device_ptr                                        \
                        : a) adjust_args(need_device_ptr                       \
                                         : y)
#endif
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vzatanhi))                    \
    match(construct = {target variant dispatch}, device = {arch(gen)})
void vzAtanhI(const MKL_INT n, const MKL_Complex16* a, MKL_INT inca,
              MKL_Complex16* y, MKL_INT incy) NOTHROW;

#if (_OPENMP >= 202011)
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vmzatanh))                    \
    match(construct = {dispatch}, device = {arch(gen)})                        \
        append_args(interop(prefer_type("sycl", "level_zero"), targetsync))    \
            adjust_args(need_device_ptr                                        \
                        : a) adjust_args(need_device_ptr                       \
                                         : y)
#endif
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vmzatanh))                    \
    match(construct = {target variant dispatch}, device = {arch(gen)})
void vmzAtanh(const MKL_INT n, const MKL_Complex16* a, MKL_Complex16* y,
              MKL_INT64 mode) NOTHROW;

#if (_OPENMP >= 202011)
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vmzatanhi))                   \
    match(construct = {dispatch}, device = {arch(gen)})                        \
        append_args(interop(prefer_type("sycl", "level_zero"), targetsync))    \
            adjust_args(need_device_ptr                                        \
                        : a) adjust_args(need_device_ptr                       \
                                         : y)
#endif
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vmzatanhi))                   \
    match(construct = {target variant dispatch}, device = {arch(gen)})
void vmzAtanhI(const MKL_INT n, const MKL_Complex16* a, MKL_INT inca,
               MKL_Complex16* y, MKL_INT incy, MKL_INT64 mode) NOTHROW;

// function atanpi
#if (_OPENMP >= 202011)
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vsatanpi))                    \
    match(construct = {dispatch}, device = {arch(gen)})                        \
        append_args(interop(prefer_type("sycl", "level_zero"), targetsync))    \
            adjust_args(need_device_ptr                                        \
                        : a) adjust_args(need_device_ptr                       \
                                         : y)
#endif
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vsatanpi))                    \
    match(construct = {target variant dispatch}, device = {arch(gen)})
void vsAtanpi(const MKL_INT n, const float* a, float* y) NOTHROW;

#if (_OPENMP >= 202011)
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vsatanpii))                   \
    match(construct = {dispatch}, device = {arch(gen)})                        \
        append_args(interop(prefer_type("sycl", "level_zero"), targetsync))    \
            adjust_args(need_device_ptr                                        \
                        : a) adjust_args(need_device_ptr                       \
                                         : y)
#endif
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vsatanpii))                   \
    match(construct = {target variant dispatch}, device = {arch(gen)})
void vsAtanpiI(const MKL_INT n, const float* a, MKL_INT inca, float* y,
               MKL_INT incy) NOTHROW;

#if (_OPENMP >= 202011)
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vmsatanpi))                   \
    match(construct = {dispatch}, device = {arch(gen)})                        \
        append_args(interop(prefer_type("sycl", "level_zero"), targetsync))    \
            adjust_args(need_device_ptr                                        \
                        : a) adjust_args(need_device_ptr                       \
                                         : y)
#endif
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vmsatanpi))                   \
    match(construct = {target variant dispatch}, device = {arch(gen)})
void vmsAtanpi(const MKL_INT n, const float* a, float* y,
               MKL_INT64 mode) NOTHROW;

#if (_OPENMP >= 202011)
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vmsatanpii))                  \
    match(construct = {dispatch}, device = {arch(gen)})                        \
        append_args(interop(prefer_type("sycl", "level_zero"), targetsync))    \
            adjust_args(need_device_ptr                                        \
                        : a) adjust_args(need_device_ptr                       \
                                         : y)
#endif
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vmsatanpii))                  \
    match(construct = {target variant dispatch}, device = {arch(gen)})
void vmsAtanpiI(const MKL_INT n, const float* a, MKL_INT inca, float* y,
                MKL_INT incy, MKL_INT64 mode) NOTHROW;

#if (_OPENMP >= 202011)
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vdatanpi))                    \
    match(construct = {dispatch}, device = {arch(gen)})                        \
        append_args(interop(prefer_type("sycl", "level_zero"), targetsync))    \
            adjust_args(need_device_ptr                                        \
                        : a) adjust_args(need_device_ptr                       \
                                         : y)
#endif
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vdatanpi))                    \
    match(construct = {target variant dispatch}, device = {arch(gen)})
void vdAtanpi(const MKL_INT n, const double* a, double* y) NOTHROW;

#if (_OPENMP >= 202011)
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vdatanpii))                   \
    match(construct = {dispatch}, device = {arch(gen)})                        \
        append_args(interop(prefer_type("sycl", "level_zero"), targetsync))    \
            adjust_args(need_device_ptr                                        \
                        : a) adjust_args(need_device_ptr                       \
                                         : y)
#endif
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vdatanpii))                   \
    match(construct = {target variant dispatch}, device = {arch(gen)})
void vdAtanpiI(const MKL_INT n, const double* a, MKL_INT inca, double* y,
               MKL_INT incy) NOTHROW;

#if (_OPENMP >= 202011)
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vmdatanpi))                   \
    match(construct = {dispatch}, device = {arch(gen)})                        \
        append_args(interop(prefer_type("sycl", "level_zero"), targetsync))    \
            adjust_args(need_device_ptr                                        \
                        : a) adjust_args(need_device_ptr                       \
                                         : y)
#endif
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vmdatanpi))                   \
    match(construct = {target variant dispatch}, device = {arch(gen)})
void vmdAtanpi(const MKL_INT n, const double* a, double* y,
               MKL_INT64 mode) NOTHROW;

#if (_OPENMP >= 202011)
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vmdatanpii))                  \
    match(construct = {dispatch}, device = {arch(gen)})                        \
        append_args(interop(prefer_type("sycl", "level_zero"), targetsync))    \
            adjust_args(need_device_ptr                                        \
                        : a) adjust_args(need_device_ptr                       \
                                         : y)
#endif
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vmdatanpii))                  \
    match(construct = {target variant dispatch}, device = {arch(gen)})
void vmdAtanpiI(const MKL_INT n, const double* a, MKL_INT inca, double* y,
                MKL_INT incy, MKL_INT64 mode) NOTHROW;

// function cbrt
#if (_OPENMP >= 202011)
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vscbrt))                      \
    match(construct = {dispatch}, device = {arch(gen)})                        \
        append_args(interop(prefer_type("sycl", "level_zero"), targetsync))    \
            adjust_args(need_device_ptr                                        \
                        : a) adjust_args(need_device_ptr                       \
                                         : y)
#endif
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vscbrt))                      \
    match(construct = {target variant dispatch}, device = {arch(gen)})
void vsCbrt(const MKL_INT n, const float* a, float* y) NOTHROW;

#if (_OPENMP >= 202011)
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vscbrti))                     \
    match(construct = {dispatch}, device = {arch(gen)})                        \
        append_args(interop(prefer_type("sycl", "level_zero"), targetsync))    \
            adjust_args(need_device_ptr                                        \
                        : a) adjust_args(need_device_ptr                       \
                                         : y)
#endif
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vscbrti))                     \
    match(construct = {target variant dispatch}, device = {arch(gen)})
void vsCbrtI(const MKL_INT n, const float* a, MKL_INT inca, float* y,
             MKL_INT incy) NOTHROW;

#if (_OPENMP >= 202011)
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vmscbrt))                     \
    match(construct = {dispatch}, device = {arch(gen)})                        \
        append_args(interop(prefer_type("sycl", "level_zero"), targetsync))    \
            adjust_args(need_device_ptr                                        \
                        : a) adjust_args(need_device_ptr                       \
                                         : y)
#endif
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vmscbrt))                     \
    match(construct = {target variant dispatch}, device = {arch(gen)})
void vmsCbrt(const MKL_INT n, const float* a, float* y, MKL_INT64 mode) NOTHROW;

#if (_OPENMP >= 202011)
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vmscbrti))                    \
    match(construct = {dispatch}, device = {arch(gen)})                        \
        append_args(interop(prefer_type("sycl", "level_zero"), targetsync))    \
            adjust_args(need_device_ptr                                        \
                        : a) adjust_args(need_device_ptr                       \
                                         : y)
#endif
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vmscbrti))                    \
    match(construct = {target variant dispatch}, device = {arch(gen)})
void vmsCbrtI(const MKL_INT n, const float* a, MKL_INT inca, float* y,
              MKL_INT incy, MKL_INT64 mode) NOTHROW;

#if (_OPENMP >= 202011)
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vdcbrt))                      \
    match(construct = {dispatch}, device = {arch(gen)})                        \
        append_args(interop(prefer_type("sycl", "level_zero"), targetsync))    \
            adjust_args(need_device_ptr                                        \
                        : a) adjust_args(need_device_ptr                       \
                                         : y)
#endif
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vdcbrt))                      \
    match(construct = {target variant dispatch}, device = {arch(gen)})
void vdCbrt(const MKL_INT n, const double* a, double* y) NOTHROW;

#if (_OPENMP >= 202011)
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vdcbrti))                     \
    match(construct = {dispatch}, device = {arch(gen)})                        \
        append_args(interop(prefer_type("sycl", "level_zero"), targetsync))    \
            adjust_args(need_device_ptr                                        \
                        : a) adjust_args(need_device_ptr                       \
                                         : y)
#endif
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vdcbrti))                     \
    match(construct = {target variant dispatch}, device = {arch(gen)})
void vdCbrtI(const MKL_INT n, const double* a, MKL_INT inca, double* y,
             MKL_INT incy) NOTHROW;

#if (_OPENMP >= 202011)
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vmdcbrt))                     \
    match(construct = {dispatch}, device = {arch(gen)})                        \
        append_args(interop(prefer_type("sycl", "level_zero"), targetsync))    \
            adjust_args(need_device_ptr                                        \
                        : a) adjust_args(need_device_ptr                       \
                                         : y)
#endif
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vmdcbrt))                     \
    match(construct = {target variant dispatch}, device = {arch(gen)})
void vmdCbrt(const MKL_INT n, const double* a, double* y,
             MKL_INT64 mode) NOTHROW;

#if (_OPENMP >= 202011)
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vmdcbrti))                    \
    match(construct = {dispatch}, device = {arch(gen)})                        \
        append_args(interop(prefer_type("sycl", "level_zero"), targetsync))    \
            adjust_args(need_device_ptr                                        \
                        : a) adjust_args(need_device_ptr                       \
                                         : y)
#endif
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vmdcbrti))                    \
    match(construct = {target variant dispatch}, device = {arch(gen)})
void vmdCbrtI(const MKL_INT n, const double* a, MKL_INT inca, double* y,
              MKL_INT incy, MKL_INT64 mode) NOTHROW;

// function cdfnorm
#if (_OPENMP >= 202011)
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vscdfnorm))                   \
    match(construct = {dispatch}, device = {arch(gen)})                        \
        append_args(interop(prefer_type("sycl", "level_zero"), targetsync))    \
            adjust_args(need_device_ptr                                        \
                        : a) adjust_args(need_device_ptr                       \
                                         : y)
#endif
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vscdfnorm))                   \
    match(construct = {target variant dispatch}, device = {arch(gen)})
void vsCdfNorm(const MKL_INT n, const float* a, float* y) NOTHROW;

#if (_OPENMP >= 202011)
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vscdfnormi))                  \
    match(construct = {dispatch}, device = {arch(gen)})                        \
        append_args(interop(prefer_type("sycl", "level_zero"), targetsync))    \
            adjust_args(need_device_ptr                                        \
                        : a) adjust_args(need_device_ptr                       \
                                         : y)
#endif
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vscdfnormi))                  \
    match(construct = {target variant dispatch}, device = {arch(gen)})
void vsCdfNormI(const MKL_INT n, const float* a, MKL_INT inca, float* y,
                MKL_INT incy) NOTHROW;

#if (_OPENMP >= 202011)
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vmscdfnorm))                  \
    match(construct = {dispatch}, device = {arch(gen)})                        \
        append_args(interop(prefer_type("sycl", "level_zero"), targetsync))    \
            adjust_args(need_device_ptr                                        \
                        : a) adjust_args(need_device_ptr                       \
                                         : y)
#endif
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vmscdfnorm))                  \
    match(construct = {target variant dispatch}, device = {arch(gen)})
void vmsCdfNorm(const MKL_INT n, const float* a, float* y,
                MKL_INT64 mode) NOTHROW;

#if (_OPENMP >= 202011)
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vmscdfnormi))                 \
    match(construct = {dispatch}, device = {arch(gen)})                        \
        append_args(interop(prefer_type("sycl", "level_zero"), targetsync))    \
            adjust_args(need_device_ptr                                        \
                        : a) adjust_args(need_device_ptr                       \
                                         : y)
#endif
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vmscdfnormi))                 \
    match(construct = {target variant dispatch}, device = {arch(gen)})
void vmsCdfNormI(const MKL_INT n, const float* a, MKL_INT inca, float* y,
                 MKL_INT incy, MKL_INT64 mode) NOTHROW;

#if (_OPENMP >= 202011)
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vdcdfnorm))                   \
    match(construct = {dispatch}, device = {arch(gen)})                        \
        append_args(interop(prefer_type("sycl", "level_zero"), targetsync))    \
            adjust_args(need_device_ptr                                        \
                        : a) adjust_args(need_device_ptr                       \
                                         : y)
#endif
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vdcdfnorm))                   \
    match(construct = {target variant dispatch}, device = {arch(gen)})
void vdCdfNorm(const MKL_INT n, const double* a, double* y) NOTHROW;

#if (_OPENMP >= 202011)
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vdcdfnormi))                  \
    match(construct = {dispatch}, device = {arch(gen)})                        \
        append_args(interop(prefer_type("sycl", "level_zero"), targetsync))    \
            adjust_args(need_device_ptr                                        \
                        : a) adjust_args(need_device_ptr                       \
                                         : y)
#endif
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vdcdfnormi))                  \
    match(construct = {target variant dispatch}, device = {arch(gen)})
void vdCdfNormI(const MKL_INT n, const double* a, MKL_INT inca, double* y,
                MKL_INT incy) NOTHROW;

#if (_OPENMP >= 202011)
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vmdcdfnorm))                  \
    match(construct = {dispatch}, device = {arch(gen)})                        \
        append_args(interop(prefer_type("sycl", "level_zero"), targetsync))    \
            adjust_args(need_device_ptr                                        \
                        : a) adjust_args(need_device_ptr                       \
                                         : y)
#endif
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vmdcdfnorm))                  \
    match(construct = {target variant dispatch}, device = {arch(gen)})
void vmdCdfNorm(const MKL_INT n, const double* a, double* y,
                MKL_INT64 mode) NOTHROW;

#if (_OPENMP >= 202011)
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vmdcdfnormi))                 \
    match(construct = {dispatch}, device = {arch(gen)})                        \
        append_args(interop(prefer_type("sycl", "level_zero"), targetsync))    \
            adjust_args(need_device_ptr                                        \
                        : a) adjust_args(need_device_ptr                       \
                                         : y)
#endif
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vmdcdfnormi))                 \
    match(construct = {target variant dispatch}, device = {arch(gen)})
void vmdCdfNormI(const MKL_INT n, const double* a, MKL_INT inca, double* y,
                 MKL_INT incy, MKL_INT64 mode) NOTHROW;

// function cdfnorminv
#if (_OPENMP >= 202011)
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vscdfnorminv))                \
    match(construct = {dispatch}, device = {arch(gen)})                        \
        append_args(interop(prefer_type("sycl", "level_zero"), targetsync))    \
            adjust_args(need_device_ptr                                        \
                        : a) adjust_args(need_device_ptr                       \
                                         : y)
#endif
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vscdfnorminv))                \
    match(construct = {target variant dispatch}, device = {arch(gen)})
void vsCdfNormInv(const MKL_INT n, const float* a, float* y) NOTHROW;

#if (_OPENMP >= 202011)
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vscdfnorminvi))               \
    match(construct = {dispatch}, device = {arch(gen)})                        \
        append_args(interop(prefer_type("sycl", "level_zero"), targetsync))    \
            adjust_args(need_device_ptr                                        \
                        : a) adjust_args(need_device_ptr                       \
                                         : y)
#endif
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vscdfnorminvi))               \
    match(construct = {target variant dispatch}, device = {arch(gen)})
void vsCdfNormInvI(const MKL_INT n, const float* a, MKL_INT inca, float* y,
                   MKL_INT incy) NOTHROW;

#if (_OPENMP >= 202011)
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vmscdfnorminv))               \
    match(construct = {dispatch}, device = {arch(gen)})                        \
        append_args(interop(prefer_type("sycl", "level_zero"), targetsync))    \
            adjust_args(need_device_ptr                                        \
                        : a) adjust_args(need_device_ptr                       \
                                         : y)
#endif
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vmscdfnorminv))               \
    match(construct = {target variant dispatch}, device = {arch(gen)})
void vmsCdfNormInv(const MKL_INT n, const float* a, float* y,
                   MKL_INT64 mode) NOTHROW;

#if (_OPENMP >= 202011)
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vmscdfnorminvi))              \
    match(construct = {dispatch}, device = {arch(gen)})                        \
        append_args(interop(prefer_type("sycl", "level_zero"), targetsync))    \
            adjust_args(need_device_ptr                                        \
                        : a) adjust_args(need_device_ptr                       \
                                         : y)
#endif
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vmscdfnorminvi))              \
    match(construct = {target variant dispatch}, device = {arch(gen)})
void vmsCdfNormInvI(const MKL_INT n, const float* a, MKL_INT inca, float* y,
                    MKL_INT incy, MKL_INT64 mode) NOTHROW;

#if (_OPENMP >= 202011)
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vdcdfnorminv))                \
    match(construct = {dispatch}, device = {arch(gen)})                        \
        append_args(interop(prefer_type("sycl", "level_zero"), targetsync))    \
            adjust_args(need_device_ptr                                        \
                        : a) adjust_args(need_device_ptr                       \
                                         : y)
#endif
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vdcdfnorminv))                \
    match(construct = {target variant dispatch}, device = {arch(gen)})
void vdCdfNormInv(const MKL_INT n, const double* a, double* y) NOTHROW;

#if (_OPENMP >= 202011)
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vdcdfnorminvi))               \
    match(construct = {dispatch}, device = {arch(gen)})                        \
        append_args(interop(prefer_type("sycl", "level_zero"), targetsync))    \
            adjust_args(need_device_ptr                                        \
                        : a) adjust_args(need_device_ptr                       \
                                         : y)
#endif
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vdcdfnorminvi))               \
    match(construct = {target variant dispatch}, device = {arch(gen)})
void vdCdfNormInvI(const MKL_INT n, const double* a, MKL_INT inca, double* y,
                   MKL_INT incy) NOTHROW;

#if (_OPENMP >= 202011)
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vmdcdfnorminv))               \
    match(construct = {dispatch}, device = {arch(gen)})                        \
        append_args(interop(prefer_type("sycl", "level_zero"), targetsync))    \
            adjust_args(need_device_ptr                                        \
                        : a) adjust_args(need_device_ptr                       \
                                         : y)
#endif
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vmdcdfnorminv))               \
    match(construct = {target variant dispatch}, device = {arch(gen)})
void vmdCdfNormInv(const MKL_INT n, const double* a, double* y,
                   MKL_INT64 mode) NOTHROW;

#if (_OPENMP >= 202011)
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vmdcdfnorminvi))              \
    match(construct = {dispatch}, device = {arch(gen)})                        \
        append_args(interop(prefer_type("sycl", "level_zero"), targetsync))    \
            adjust_args(need_device_ptr                                        \
                        : a) adjust_args(need_device_ptr                       \
                                         : y)
#endif
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vmdcdfnorminvi))              \
    match(construct = {target variant dispatch}, device = {arch(gen)})
void vmdCdfNormInvI(const MKL_INT n, const double* a, MKL_INT inca, double* y,
                    MKL_INT incy, MKL_INT64 mode) NOTHROW;

// function ceil
#if (_OPENMP >= 202011)
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vsceil))                      \
    match(construct = {dispatch}, device = {arch(gen)})                        \
        append_args(interop(prefer_type("sycl", "level_zero"), targetsync))    \
            adjust_args(need_device_ptr                                        \
                        : a) adjust_args(need_device_ptr                       \
                                         : y)
#endif
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vsceil))                      \
    match(construct = {target variant dispatch}, device = {arch(gen)})
void vsCeil(const MKL_INT n, const float* a, float* y) NOTHROW;

#if (_OPENMP >= 202011)
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vsceili))                     \
    match(construct = {dispatch}, device = {arch(gen)})                        \
        append_args(interop(prefer_type("sycl", "level_zero"), targetsync))    \
            adjust_args(need_device_ptr                                        \
                        : a) adjust_args(need_device_ptr                       \
                                         : y)
#endif
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vsceili))                     \
    match(construct = {target variant dispatch}, device = {arch(gen)})
void vsCeilI(const MKL_INT n, const float* a, MKL_INT inca, float* y,
             MKL_INT incy) NOTHROW;

#if (_OPENMP >= 202011)
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vmsceil))                     \
    match(construct = {dispatch}, device = {arch(gen)})                        \
        append_args(interop(prefer_type("sycl", "level_zero"), targetsync))    \
            adjust_args(need_device_ptr                                        \
                        : a) adjust_args(need_device_ptr                       \
                                         : y)
#endif
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vmsceil))                     \
    match(construct = {target variant dispatch}, device = {arch(gen)})
void vmsCeil(const MKL_INT n, const float* a, float* y, MKL_INT64 mode) NOTHROW;

#if (_OPENMP >= 202011)
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vmsceili))                    \
    match(construct = {dispatch}, device = {arch(gen)})                        \
        append_args(interop(prefer_type("sycl", "level_zero"), targetsync))    \
            adjust_args(need_device_ptr                                        \
                        : a) adjust_args(need_device_ptr                       \
                                         : y)
#endif
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vmsceili))                    \
    match(construct = {target variant dispatch}, device = {arch(gen)})
void vmsCeilI(const MKL_INT n, const float* a, MKL_INT inca, float* y,
              MKL_INT incy, MKL_INT64 mode) NOTHROW;

#if (_OPENMP >= 202011)
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vdceil))                      \
    match(construct = {dispatch}, device = {arch(gen)})                        \
        append_args(interop(prefer_type("sycl", "level_zero"), targetsync))    \
            adjust_args(need_device_ptr                                        \
                        : a) adjust_args(need_device_ptr                       \
                                         : y)
#endif
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vdceil))                      \
    match(construct = {target variant dispatch}, device = {arch(gen)})
void vdCeil(const MKL_INT n, const double* a, double* y) NOTHROW;

#if (_OPENMP >= 202011)
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vdceili))                     \
    match(construct = {dispatch}, device = {arch(gen)})                        \
        append_args(interop(prefer_type("sycl", "level_zero"), targetsync))    \
            adjust_args(need_device_ptr                                        \
                        : a) adjust_args(need_device_ptr                       \
                                         : y)
#endif
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vdceili))                     \
    match(construct = {target variant dispatch}, device = {arch(gen)})
void vdCeilI(const MKL_INT n, const double* a, MKL_INT inca, double* y,
             MKL_INT incy) NOTHROW;

#if (_OPENMP >= 202011)
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vmdceil))                     \
    match(construct = {dispatch}, device = {arch(gen)})                        \
        append_args(interop(prefer_type("sycl", "level_zero"), targetsync))    \
            adjust_args(need_device_ptr                                        \
                        : a) adjust_args(need_device_ptr                       \
                                         : y)
#endif
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vmdceil))                     \
    match(construct = {target variant dispatch}, device = {arch(gen)})
void vmdCeil(const MKL_INT n, const double* a, double* y,
             MKL_INT64 mode) NOTHROW;

#if (_OPENMP >= 202011)
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vmdceili))                    \
    match(construct = {dispatch}, device = {arch(gen)})                        \
        append_args(interop(prefer_type("sycl", "level_zero"), targetsync))    \
            adjust_args(need_device_ptr                                        \
                        : a) adjust_args(need_device_ptr                       \
                                         : y)
#endif
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vmdceili))                    \
    match(construct = {target variant dispatch}, device = {arch(gen)})
void vmdCeilI(const MKL_INT n, const double* a, MKL_INT inca, double* y,
              MKL_INT incy, MKL_INT64 mode) NOTHROW;

// function cis
#if (_OPENMP >= 202011)
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vccis))                       \
    match(construct = {dispatch}, device = {arch(gen)})                        \
        append_args(interop(prefer_type("sycl", "level_zero"), targetsync))    \
            adjust_args(need_device_ptr                                        \
                        : a) adjust_args(need_device_ptr                       \
                                         : y)
#endif
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vccis))                       \
    match(construct = {target variant dispatch}, device = {arch(gen)})
void vcCIS(const MKL_INT n, const float* a, MKL_Complex8* y) NOTHROW;

#if (_OPENMP >= 202011)
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vccisi))                      \
    match(construct = {dispatch}, device = {arch(gen)})                        \
        append_args(interop(prefer_type("sycl", "level_zero"), targetsync))    \
            adjust_args(need_device_ptr                                        \
                        : a) adjust_args(need_device_ptr                       \
                                         : y)
#endif
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vccisi))                      \
    match(construct = {target variant dispatch}, device = {arch(gen)})
void vcCISI(const MKL_INT n, const float* a, MKL_INT inca, MKL_Complex8* y,
            MKL_INT incy) NOTHROW;

#if (_OPENMP >= 202011)
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vmccis))                      \
    match(construct = {dispatch}, device = {arch(gen)})                        \
        append_args(interop(prefer_type("sycl", "level_zero"), targetsync))    \
            adjust_args(need_device_ptr                                        \
                        : a) adjust_args(need_device_ptr                       \
                                         : y)
#endif
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vmccis))                      \
    match(construct = {target variant dispatch}, device = {arch(gen)})
void vmcCIS(const MKL_INT n, const float* a, MKL_Complex8* y,
            MKL_INT64 mode) NOTHROW;

#if (_OPENMP >= 202011)
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vmccisi))                     \
    match(construct = {dispatch}, device = {arch(gen)})                        \
        append_args(interop(prefer_type("sycl", "level_zero"), targetsync))    \
            adjust_args(need_device_ptr                                        \
                        : a) adjust_args(need_device_ptr                       \
                                         : y)
#endif
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vmccisi))                     \
    match(construct = {target variant dispatch}, device = {arch(gen)})
void vmcCISI(const MKL_INT n, const float* a, MKL_INT inca, MKL_Complex8* y,
             MKL_INT incy, MKL_INT64 mode) NOTHROW;

#if (_OPENMP >= 202011)
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vzcis))                       \
    match(construct = {dispatch}, device = {arch(gen)})                        \
        append_args(interop(prefer_type("sycl", "level_zero"), targetsync))    \
            adjust_args(need_device_ptr                                        \
                        : a) adjust_args(need_device_ptr                       \
                                         : y)
#endif
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vzcis))                       \
    match(construct = {target variant dispatch}, device = {arch(gen)})
void vzCIS(const MKL_INT n, const double* a, MKL_Complex16* y) NOTHROW;

#if (_OPENMP >= 202011)
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vzcisi))                      \
    match(construct = {dispatch}, device = {arch(gen)})                        \
        append_args(interop(prefer_type("sycl", "level_zero"), targetsync))    \
            adjust_args(need_device_ptr                                        \
                        : a) adjust_args(need_device_ptr                       \
                                         : y)
#endif
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vzcisi))                      \
    match(construct = {target variant dispatch}, device = {arch(gen)})
void vzCISI(const MKL_INT n, const double* a, MKL_INT inca, MKL_Complex16* y,
            MKL_INT incy) NOTHROW;

#if (_OPENMP >= 202011)
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vmzcis))                      \
    match(construct = {dispatch}, device = {arch(gen)})                        \
        append_args(interop(prefer_type("sycl", "level_zero"), targetsync))    \
            adjust_args(need_device_ptr                                        \
                        : a) adjust_args(need_device_ptr                       \
                                         : y)
#endif
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vmzcis))                      \
    match(construct = {target variant dispatch}, device = {arch(gen)})
void vmzCIS(const MKL_INT n, const double* a, MKL_Complex16* y,
            MKL_INT64 mode) NOTHROW;

#if (_OPENMP >= 202011)
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vmzcisi))                     \
    match(construct = {dispatch}, device = {arch(gen)})                        \
        append_args(interop(prefer_type("sycl", "level_zero"), targetsync))    \
            adjust_args(need_device_ptr                                        \
                        : a) adjust_args(need_device_ptr                       \
                                         : y)
#endif
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vmzcisi))                     \
    match(construct = {target variant dispatch}, device = {arch(gen)})
void vmzCISI(const MKL_INT n, const double* a, MKL_INT inca, MKL_Complex16* y,
             MKL_INT incy, MKL_INT64 mode) NOTHROW;

// function conj
#if (_OPENMP >= 202011)
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vcconj))                      \
    match(construct = {dispatch}, device = {arch(gen)})                        \
        append_args(interop(prefer_type("sycl", "level_zero"), targetsync))    \
            adjust_args(need_device_ptr                                        \
                        : a) adjust_args(need_device_ptr                       \
                                         : y)
#endif
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vcconj))                      \
    match(construct = {target variant dispatch}, device = {arch(gen)})
void vcConj(const MKL_INT n, const MKL_Complex8* a, MKL_Complex8* y) NOTHROW;

#if (_OPENMP >= 202011)
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vcconji))                     \
    match(construct = {dispatch}, device = {arch(gen)})                        \
        append_args(interop(prefer_type("sycl", "level_zero"), targetsync))    \
            adjust_args(need_device_ptr                                        \
                        : a) adjust_args(need_device_ptr                       \
                                         : y)
#endif
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vcconji))                     \
    match(construct = {target variant dispatch}, device = {arch(gen)})
void vcConjI(const MKL_INT n, const MKL_Complex8* a, MKL_INT inca,
             MKL_Complex8* y, MKL_INT incy) NOTHROW;

#if (_OPENMP >= 202011)
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vmcconj))                     \
    match(construct = {dispatch}, device = {arch(gen)})                        \
        append_args(interop(prefer_type("sycl", "level_zero"), targetsync))    \
            adjust_args(need_device_ptr                                        \
                        : a) adjust_args(need_device_ptr                       \
                                         : y)
#endif
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vmcconj))                     \
    match(construct = {target variant dispatch}, device = {arch(gen)})
void vmcConj(const MKL_INT n, const MKL_Complex8* a, MKL_Complex8* y,
             MKL_INT64 mode) NOTHROW;

#if (_OPENMP >= 202011)
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vmcconji))                    \
    match(construct = {dispatch}, device = {arch(gen)})                        \
        append_args(interop(prefer_type("sycl", "level_zero"), targetsync))    \
            adjust_args(need_device_ptr                                        \
                        : a) adjust_args(need_device_ptr                       \
                                         : y)
#endif
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vmcconji))                    \
    match(construct = {target variant dispatch}, device = {arch(gen)})
void vmcConjI(const MKL_INT n, const MKL_Complex8* a, MKL_INT inca,
              MKL_Complex8* y, MKL_INT incy, MKL_INT64 mode) NOTHROW;

#if (_OPENMP >= 202011)
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vzconj))                      \
    match(construct = {dispatch}, device = {arch(gen)})                        \
        append_args(interop(prefer_type("sycl", "level_zero"), targetsync))    \
            adjust_args(need_device_ptr                                        \
                        : a) adjust_args(need_device_ptr                       \
                                         : y)
#endif
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vzconj))                      \
    match(construct = {target variant dispatch}, device = {arch(gen)})
void vzConj(const MKL_INT n, const MKL_Complex16* a, MKL_Complex16* y) NOTHROW;

#if (_OPENMP >= 202011)
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vzconji))                     \
    match(construct = {dispatch}, device = {arch(gen)})                        \
        append_args(interop(prefer_type("sycl", "level_zero"), targetsync))    \
            adjust_args(need_device_ptr                                        \
                        : a) adjust_args(need_device_ptr                       \
                                         : y)
#endif
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vzconji))                     \
    match(construct = {target variant dispatch}, device = {arch(gen)})
void vzConjI(const MKL_INT n, const MKL_Complex16* a, MKL_INT inca,
             MKL_Complex16* y, MKL_INT incy) NOTHROW;

#if (_OPENMP >= 202011)
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vmzconj))                     \
    match(construct = {dispatch}, device = {arch(gen)})                        \
        append_args(interop(prefer_type("sycl", "level_zero"), targetsync))    \
            adjust_args(need_device_ptr                                        \
                        : a) adjust_args(need_device_ptr                       \
                                         : y)
#endif
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vmzconj))                     \
    match(construct = {target variant dispatch}, device = {arch(gen)})
void vmzConj(const MKL_INT n, const MKL_Complex16* a, MKL_Complex16* y,
             MKL_INT64 mode) NOTHROW;

#if (_OPENMP >= 202011)
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vmzconji))                    \
    match(construct = {dispatch}, device = {arch(gen)})                        \
        append_args(interop(prefer_type("sycl", "level_zero"), targetsync))    \
            adjust_args(need_device_ptr                                        \
                        : a) adjust_args(need_device_ptr                       \
                                         : y)
#endif
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vmzconji))                    \
    match(construct = {target variant dispatch}, device = {arch(gen)})
void vmzConjI(const MKL_INT n, const MKL_Complex16* a, MKL_INT inca,
              MKL_Complex16* y, MKL_INT incy, MKL_INT64 mode) NOTHROW;

// function copysign
#if (_OPENMP >= 202011)
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vscopysign))                  \
    match(construct = {dispatch}, device = {arch(gen)})                        \
        append_args(interop(prefer_type("sycl", "level_zero"), targetsync))    \
            adjust_args(need_device_ptr                                        \
                        : a) adjust_args(need_device_ptr                       \
                                         : b) adjust_args(need_device_ptr      \
                                                          : y)
#endif
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vscopysign))                  \
    match(construct = {target variant dispatch}, device = {arch(gen)})
void vsCopySign(const MKL_INT n, const float* a, const float* b,
                float* y) NOTHROW;

#if (_OPENMP >= 202011)
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vscopysigni))                 \
    match(construct = {dispatch}, device = {arch(gen)})                        \
        append_args(interop(prefer_type("sycl", "level_zero"), targetsync))    \
            adjust_args(need_device_ptr                                        \
                        : a) adjust_args(need_device_ptr                       \
                                         : b) adjust_args(need_device_ptr      \
                                                          : y)
#endif
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vscopysigni))                 \
    match(construct = {target variant dispatch}, device = {arch(gen)})
void vsCopySignI(const MKL_INT n, const float* a, MKL_INT inca, const float* b,
                 MKL_INT incb, float* y, MKL_INT incy) NOTHROW;

#if (_OPENMP >= 202011)
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vmscopysign))                 \
    match(construct = {dispatch}, device = {arch(gen)})                        \
        append_args(interop(prefer_type("sycl", "level_zero"), targetsync))    \
            adjust_args(need_device_ptr                                        \
                        : a) adjust_args(need_device_ptr                       \
                                         : b) adjust_args(need_device_ptr      \
                                                          : y)
#endif
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vmscopysign))                 \
    match(construct = {target variant dispatch}, device = {arch(gen)})
void vmsCopySign(const MKL_INT n, const float* a, const float* b, float* y,
                 MKL_INT64 mode) NOTHROW;

#if (_OPENMP >= 202011)
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vmscopysigni))                \
    match(construct = {dispatch}, device = {arch(gen)})                        \
        append_args(interop(prefer_type("sycl", "level_zero"), targetsync))    \
            adjust_args(need_device_ptr                                        \
                        : a) adjust_args(need_device_ptr                       \
                                         : b) adjust_args(need_device_ptr      \
                                                          : y)
#endif
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vmscopysigni))                \
    match(construct = {target variant dispatch}, device = {arch(gen)})
void vmsCopySignI(const MKL_INT n, const float* a, MKL_INT inca, const float* b,
                  MKL_INT incb, float* y, MKL_INT incy, MKL_INT64 mode) NOTHROW;

#if (_OPENMP >= 202011)
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vdcopysign))                  \
    match(construct = {dispatch}, device = {arch(gen)})                        \
        append_args(interop(prefer_type("sycl", "level_zero"), targetsync))    \
            adjust_args(need_device_ptr                                        \
                        : a) adjust_args(need_device_ptr                       \
                                         : b) adjust_args(need_device_ptr      \
                                                          : y)
#endif
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vdcopysign))                  \
    match(construct = {target variant dispatch}, device = {arch(gen)})
void vdCopySign(const MKL_INT n, const double* a, const double* b,
                double* y) NOTHROW;

#if (_OPENMP >= 202011)
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vdcopysigni))                 \
    match(construct = {dispatch}, device = {arch(gen)})                        \
        append_args(interop(prefer_type("sycl", "level_zero"), targetsync))    \
            adjust_args(need_device_ptr                                        \
                        : a) adjust_args(need_device_ptr                       \
                                         : b) adjust_args(need_device_ptr      \
                                                          : y)
#endif
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vdcopysigni))                 \
    match(construct = {target variant dispatch}, device = {arch(gen)})
void vdCopySignI(const MKL_INT n, const double* a, MKL_INT inca,
                 const double* b, MKL_INT incb, double* y,
                 MKL_INT incy) NOTHROW;

#if (_OPENMP >= 202011)
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vmdcopysign))                 \
    match(construct = {dispatch}, device = {arch(gen)})                        \
        append_args(interop(prefer_type("sycl", "level_zero"), targetsync))    \
            adjust_args(need_device_ptr                                        \
                        : a) adjust_args(need_device_ptr                       \
                                         : b) adjust_args(need_device_ptr      \
                                                          : y)
#endif
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vmdcopysign))                 \
    match(construct = {target variant dispatch}, device = {arch(gen)})
void vmdCopySign(const MKL_INT n, const double* a, const double* b, double* y,
                 MKL_INT64 mode) NOTHROW;

#if (_OPENMP >= 202011)
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vmdcopysigni))                \
    match(construct = {dispatch}, device = {arch(gen)})                        \
        append_args(interop(prefer_type("sycl", "level_zero"), targetsync))    \
            adjust_args(need_device_ptr                                        \
                        : a) adjust_args(need_device_ptr                       \
                                         : b) adjust_args(need_device_ptr      \
                                                          : y)
#endif
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vmdcopysigni))                \
    match(construct = {target variant dispatch}, device = {arch(gen)})
void vmdCopySignI(const MKL_INT n, const double* a, MKL_INT inca,
                  const double* b, MKL_INT incb, double* y, MKL_INT incy,
                  MKL_INT64 mode) NOTHROW;

// function cos
#if (_OPENMP >= 202011)
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vscos))                       \
    match(construct = {dispatch}, device = {arch(gen)})                        \
        append_args(interop(prefer_type("sycl", "level_zero"), targetsync))    \
            adjust_args(need_device_ptr                                        \
                        : a) adjust_args(need_device_ptr                       \
                                         : y)
#endif
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vscos))                       \
    match(construct = {target variant dispatch}, device = {arch(gen)})
void vsCos(const MKL_INT n, const float* a, float* y) NOTHROW;

#if (_OPENMP >= 202011)
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vscosi))                      \
    match(construct = {dispatch}, device = {arch(gen)})                        \
        append_args(interop(prefer_type("sycl", "level_zero"), targetsync))    \
            adjust_args(need_device_ptr                                        \
                        : a) adjust_args(need_device_ptr                       \
                                         : y)
#endif
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vscosi))                      \
    match(construct = {target variant dispatch}, device = {arch(gen)})
void vsCosI(const MKL_INT n, const float* a, MKL_INT inca, float* y,
            MKL_INT incy) NOTHROW;

#if (_OPENMP >= 202011)
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vmscos))                      \
    match(construct = {dispatch}, device = {arch(gen)})                        \
        append_args(interop(prefer_type("sycl", "level_zero"), targetsync))    \
            adjust_args(need_device_ptr                                        \
                        : a) adjust_args(need_device_ptr                       \
                                         : y)
#endif
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vmscos))                      \
    match(construct = {target variant dispatch}, device = {arch(gen)})
void vmsCos(const MKL_INT n, const float* a, float* y, MKL_INT64 mode) NOTHROW;

#if (_OPENMP >= 202011)
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vmscosi))                     \
    match(construct = {dispatch}, device = {arch(gen)})                        \
        append_args(interop(prefer_type("sycl", "level_zero"), targetsync))    \
            adjust_args(need_device_ptr                                        \
                        : a) adjust_args(need_device_ptr                       \
                                         : y)
#endif
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vmscosi))                     \
    match(construct = {target variant dispatch}, device = {arch(gen)})
void vmsCosI(const MKL_INT n, const float* a, MKL_INT inca, float* y,
             MKL_INT incy, MKL_INT64 mode) NOTHROW;

#if (_OPENMP >= 202011)
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vdcos))                       \
    match(construct = {dispatch}, device = {arch(gen)})                        \
        append_args(interop(prefer_type("sycl", "level_zero"), targetsync))    \
            adjust_args(need_device_ptr                                        \
                        : a) adjust_args(need_device_ptr                       \
                                         : y)
#endif
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vdcos))                       \
    match(construct = {target variant dispatch}, device = {arch(gen)})
void vdCos(const MKL_INT n, const double* a, double* y) NOTHROW;

#if (_OPENMP >= 202011)
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vdcosi))                      \
    match(construct = {dispatch}, device = {arch(gen)})                        \
        append_args(interop(prefer_type("sycl", "level_zero"), targetsync))    \
            adjust_args(need_device_ptr                                        \
                        : a) adjust_args(need_device_ptr                       \
                                         : y)
#endif
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vdcosi))                      \
    match(construct = {target variant dispatch}, device = {arch(gen)})
void vdCosI(const MKL_INT n, const double* a, MKL_INT inca, double* y,
            MKL_INT incy) NOTHROW;

#if (_OPENMP >= 202011)
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vmdcos))                      \
    match(construct = {dispatch}, device = {arch(gen)})                        \
        append_args(interop(prefer_type("sycl", "level_zero"), targetsync))    \
            adjust_args(need_device_ptr                                        \
                        : a) adjust_args(need_device_ptr                       \
                                         : y)
#endif
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vmdcos))                      \
    match(construct = {target variant dispatch}, device = {arch(gen)})
void vmdCos(const MKL_INT n, const double* a, double* y,
            MKL_INT64 mode) NOTHROW;

#if (_OPENMP >= 202011)
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vmdcosi))                     \
    match(construct = {dispatch}, device = {arch(gen)})                        \
        append_args(interop(prefer_type("sycl", "level_zero"), targetsync))    \
            adjust_args(need_device_ptr                                        \
                        : a) adjust_args(need_device_ptr                       \
                                         : y)
#endif
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vmdcosi))                     \
    match(construct = {target variant dispatch}, device = {arch(gen)})
void vmdCosI(const MKL_INT n, const double* a, MKL_INT inca, double* y,
             MKL_INT incy, MKL_INT64 mode) NOTHROW;

#if (_OPENMP >= 202011)
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vccos))                       \
    match(construct = {dispatch}, device = {arch(gen)})                        \
        append_args(interop(prefer_type("sycl", "level_zero"), targetsync))    \
            adjust_args(need_device_ptr                                        \
                        : a) adjust_args(need_device_ptr                       \
                                         : y)
#endif
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vccos))                       \
    match(construct = {target variant dispatch}, device = {arch(gen)})
void vcCos(const MKL_INT n, const MKL_Complex8* a, MKL_Complex8* y) NOTHROW;

#if (_OPENMP >= 202011)
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vccosi))                      \
    match(construct = {dispatch}, device = {arch(gen)})                        \
        append_args(interop(prefer_type("sycl", "level_zero"), targetsync))    \
            adjust_args(need_device_ptr                                        \
                        : a) adjust_args(need_device_ptr                       \
                                         : y)
#endif
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vccosi))                      \
    match(construct = {target variant dispatch}, device = {arch(gen)})
void vcCosI(const MKL_INT n, const MKL_Complex8* a, MKL_INT inca,
            MKL_Complex8* y, MKL_INT incy) NOTHROW;

#if (_OPENMP >= 202011)
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vmccos))                      \
    match(construct = {dispatch}, device = {arch(gen)})                        \
        append_args(interop(prefer_type("sycl", "level_zero"), targetsync))    \
            adjust_args(need_device_ptr                                        \
                        : a) adjust_args(need_device_ptr                       \
                                         : y)
#endif
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vmccos))                      \
    match(construct = {target variant dispatch}, device = {arch(gen)})
void vmcCos(const MKL_INT n, const MKL_Complex8* a, MKL_Complex8* y,
            MKL_INT64 mode) NOTHROW;

#if (_OPENMP >= 202011)
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vmccosi))                     \
    match(construct = {dispatch}, device = {arch(gen)})                        \
        append_args(interop(prefer_type("sycl", "level_zero"), targetsync))    \
            adjust_args(need_device_ptr                                        \
                        : a) adjust_args(need_device_ptr                       \
                                         : y)
#endif
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vmccosi))                     \
    match(construct = {target variant dispatch}, device = {arch(gen)})
void vmcCosI(const MKL_INT n, const MKL_Complex8* a, MKL_INT inca,
             MKL_Complex8* y, MKL_INT incy, MKL_INT64 mode) NOTHROW;

#if (_OPENMP >= 202011)
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vzcos))                       \
    match(construct = {dispatch}, device = {arch(gen)})                        \
        append_args(interop(prefer_type("sycl", "level_zero"), targetsync))    \
            adjust_args(need_device_ptr                                        \
                        : a) adjust_args(need_device_ptr                       \
                                         : y)
#endif
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vzcos))                       \
    match(construct = {target variant dispatch}, device = {arch(gen)})
void vzCos(const MKL_INT n, const MKL_Complex16* a, MKL_Complex16* y) NOTHROW;

#if (_OPENMP >= 202011)
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vzcosi))                      \
    match(construct = {dispatch}, device = {arch(gen)})                        \
        append_args(interop(prefer_type("sycl", "level_zero"), targetsync))    \
            adjust_args(need_device_ptr                                        \
                        : a) adjust_args(need_device_ptr                       \
                                         : y)
#endif
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vzcosi))                      \
    match(construct = {target variant dispatch}, device = {arch(gen)})
void vzCosI(const MKL_INT n, const MKL_Complex16* a, MKL_INT inca,
            MKL_Complex16* y, MKL_INT incy) NOTHROW;

#if (_OPENMP >= 202011)
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vmzcos))                      \
    match(construct = {dispatch}, device = {arch(gen)})                        \
        append_args(interop(prefer_type("sycl", "level_zero"), targetsync))    \
            adjust_args(need_device_ptr                                        \
                        : a) adjust_args(need_device_ptr                       \
                                         : y)
#endif
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vmzcos))                      \
    match(construct = {target variant dispatch}, device = {arch(gen)})
void vmzCos(const MKL_INT n, const MKL_Complex16* a, MKL_Complex16* y,
            MKL_INT64 mode) NOTHROW;

#if (_OPENMP >= 202011)
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vmzcosi))                     \
    match(construct = {dispatch}, device = {arch(gen)})                        \
        append_args(interop(prefer_type("sycl", "level_zero"), targetsync))    \
            adjust_args(need_device_ptr                                        \
                        : a) adjust_args(need_device_ptr                       \
                                         : y)
#endif
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vmzcosi))                     \
    match(construct = {target variant dispatch}, device = {arch(gen)})
void vmzCosI(const MKL_INT n, const MKL_Complex16* a, MKL_INT inca,
             MKL_Complex16* y, MKL_INT incy, MKL_INT64 mode) NOTHROW;

// function cosd
#if (_OPENMP >= 202011)
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vscosd))                      \
    match(construct = {dispatch}, device = {arch(gen)})                        \
        append_args(interop(prefer_type("sycl", "level_zero"), targetsync))    \
            adjust_args(need_device_ptr                                        \
                        : a) adjust_args(need_device_ptr                       \
                                         : y)
#endif
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vscosd))                      \
    match(construct = {target variant dispatch}, device = {arch(gen)})
void vsCosd(const MKL_INT n, const float* a, float* y) NOTHROW;

#if (_OPENMP >= 202011)
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vscosdi))                     \
    match(construct = {dispatch}, device = {arch(gen)})                        \
        append_args(interop(prefer_type("sycl", "level_zero"), targetsync))    \
            adjust_args(need_device_ptr                                        \
                        : a) adjust_args(need_device_ptr                       \
                                         : y)
#endif
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vscosdi))                     \
    match(construct = {target variant dispatch}, device = {arch(gen)})
void vsCosdI(const MKL_INT n, const float* a, MKL_INT inca, float* y,
             MKL_INT incy) NOTHROW;

#if (_OPENMP >= 202011)
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vmscosd))                     \
    match(construct = {dispatch}, device = {arch(gen)})                        \
        append_args(interop(prefer_type("sycl", "level_zero"), targetsync))    \
            adjust_args(need_device_ptr                                        \
                        : a) adjust_args(need_device_ptr                       \
                                         : y)
#endif
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vmscosd))                     \
    match(construct = {target variant dispatch}, device = {arch(gen)})
void vmsCosd(const MKL_INT n, const float* a, float* y, MKL_INT64 mode) NOTHROW;

#if (_OPENMP >= 202011)
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vmscosdi))                    \
    match(construct = {dispatch}, device = {arch(gen)})                        \
        append_args(interop(prefer_type("sycl", "level_zero"), targetsync))    \
            adjust_args(need_device_ptr                                        \
                        : a) adjust_args(need_device_ptr                       \
                                         : y)
#endif
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vmscosdi))                    \
    match(construct = {target variant dispatch}, device = {arch(gen)})
void vmsCosdI(const MKL_INT n, const float* a, MKL_INT inca, float* y,
              MKL_INT incy, MKL_INT64 mode) NOTHROW;

#if (_OPENMP >= 202011)
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vdcosd))                      \
    match(construct = {dispatch}, device = {arch(gen)})                        \
        append_args(interop(prefer_type("sycl", "level_zero"), targetsync))    \
            adjust_args(need_device_ptr                                        \
                        : a) adjust_args(need_device_ptr                       \
                                         : y)
#endif
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vdcosd))                      \
    match(construct = {target variant dispatch}, device = {arch(gen)})
void vdCosd(const MKL_INT n, const double* a, double* y) NOTHROW;

#if (_OPENMP >= 202011)
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vdcosdi))                     \
    match(construct = {dispatch}, device = {arch(gen)})                        \
        append_args(interop(prefer_type("sycl", "level_zero"), targetsync))    \
            adjust_args(need_device_ptr                                        \
                        : a) adjust_args(need_device_ptr                       \
                                         : y)
#endif
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vdcosdi))                     \
    match(construct = {target variant dispatch}, device = {arch(gen)})
void vdCosdI(const MKL_INT n, const double* a, MKL_INT inca, double* y,
             MKL_INT incy) NOTHROW;

#if (_OPENMP >= 202011)
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vmdcosd))                     \
    match(construct = {dispatch}, device = {arch(gen)})                        \
        append_args(interop(prefer_type("sycl", "level_zero"), targetsync))    \
            adjust_args(need_device_ptr                                        \
                        : a) adjust_args(need_device_ptr                       \
                                         : y)
#endif
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vmdcosd))                     \
    match(construct = {target variant dispatch}, device = {arch(gen)})
void vmdCosd(const MKL_INT n, const double* a, double* y,
             MKL_INT64 mode) NOTHROW;

#if (_OPENMP >= 202011)
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vmdcosdi))                    \
    match(construct = {dispatch}, device = {arch(gen)})                        \
        append_args(interop(prefer_type("sycl", "level_zero"), targetsync))    \
            adjust_args(need_device_ptr                                        \
                        : a) adjust_args(need_device_ptr                       \
                                         : y)
#endif
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vmdcosdi))                    \
    match(construct = {target variant dispatch}, device = {arch(gen)})
void vmdCosdI(const MKL_INT n, const double* a, MKL_INT inca, double* y,
              MKL_INT incy, MKL_INT64 mode) NOTHROW;

// function cosh
#if (_OPENMP >= 202011)
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vscosh))                      \
    match(construct = {dispatch}, device = {arch(gen)})                        \
        append_args(interop(prefer_type("sycl", "level_zero"), targetsync))    \
            adjust_args(need_device_ptr                                        \
                        : a) adjust_args(need_device_ptr                       \
                                         : y)
#endif
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vscosh))                      \
    match(construct = {target variant dispatch}, device = {arch(gen)})
void vsCosh(const MKL_INT n, const float* a, float* y) NOTHROW;

#if (_OPENMP >= 202011)
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vscoshi))                     \
    match(construct = {dispatch}, device = {arch(gen)})                        \
        append_args(interop(prefer_type("sycl", "level_zero"), targetsync))    \
            adjust_args(need_device_ptr                                        \
                        : a) adjust_args(need_device_ptr                       \
                                         : y)
#endif
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vscoshi))                     \
    match(construct = {target variant dispatch}, device = {arch(gen)})
void vsCoshI(const MKL_INT n, const float* a, MKL_INT inca, float* y,
             MKL_INT incy) NOTHROW;

#if (_OPENMP >= 202011)
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vmscosh))                     \
    match(construct = {dispatch}, device = {arch(gen)})                        \
        append_args(interop(prefer_type("sycl", "level_zero"), targetsync))    \
            adjust_args(need_device_ptr                                        \
                        : a) adjust_args(need_device_ptr                       \
                                         : y)
#endif
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vmscosh))                     \
    match(construct = {target variant dispatch}, device = {arch(gen)})
void vmsCosh(const MKL_INT n, const float* a, float* y, MKL_INT64 mode) NOTHROW;

#if (_OPENMP >= 202011)
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vmscoshi))                    \
    match(construct = {dispatch}, device = {arch(gen)})                        \
        append_args(interop(prefer_type("sycl", "level_zero"), targetsync))    \
            adjust_args(need_device_ptr                                        \
                        : a) adjust_args(need_device_ptr                       \
                                         : y)
#endif
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vmscoshi))                    \
    match(construct = {target variant dispatch}, device = {arch(gen)})
void vmsCoshI(const MKL_INT n, const float* a, MKL_INT inca, float* y,
              MKL_INT incy, MKL_INT64 mode) NOTHROW;

#if (_OPENMP >= 202011)
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vdcosh))                      \
    match(construct = {dispatch}, device = {arch(gen)})                        \
        append_args(interop(prefer_type("sycl", "level_zero"), targetsync))    \
            adjust_args(need_device_ptr                                        \
                        : a) adjust_args(need_device_ptr                       \
                                         : y)
#endif
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vdcosh))                      \
    match(construct = {target variant dispatch}, device = {arch(gen)})
void vdCosh(const MKL_INT n, const double* a, double* y) NOTHROW;

#if (_OPENMP >= 202011)
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vdcoshi))                     \
    match(construct = {dispatch}, device = {arch(gen)})                        \
        append_args(interop(prefer_type("sycl", "level_zero"), targetsync))    \
            adjust_args(need_device_ptr                                        \
                        : a) adjust_args(need_device_ptr                       \
                                         : y)
#endif
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vdcoshi))                     \
    match(construct = {target variant dispatch}, device = {arch(gen)})
void vdCoshI(const MKL_INT n, const double* a, MKL_INT inca, double* y,
             MKL_INT incy) NOTHROW;

#if (_OPENMP >= 202011)
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vmdcosh))                     \
    match(construct = {dispatch}, device = {arch(gen)})                        \
        append_args(interop(prefer_type("sycl", "level_zero"), targetsync))    \
            adjust_args(need_device_ptr                                        \
                        : a) adjust_args(need_device_ptr                       \
                                         : y)
#endif
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vmdcosh))                     \
    match(construct = {target variant dispatch}, device = {arch(gen)})
void vmdCosh(const MKL_INT n, const double* a, double* y,
             MKL_INT64 mode) NOTHROW;

#if (_OPENMP >= 202011)
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vmdcoshi))                    \
    match(construct = {dispatch}, device = {arch(gen)})                        \
        append_args(interop(prefer_type("sycl", "level_zero"), targetsync))    \
            adjust_args(need_device_ptr                                        \
                        : a) adjust_args(need_device_ptr                       \
                                         : y)
#endif
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vmdcoshi))                    \
    match(construct = {target variant dispatch}, device = {arch(gen)})
void vmdCoshI(const MKL_INT n, const double* a, MKL_INT inca, double* y,
              MKL_INT incy, MKL_INT64 mode) NOTHROW;

#if (_OPENMP >= 202011)
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vccosh))                      \
    match(construct = {dispatch}, device = {arch(gen)})                        \
        append_args(interop(prefer_type("sycl", "level_zero"), targetsync))    \
            adjust_args(need_device_ptr                                        \
                        : a) adjust_args(need_device_ptr                       \
                                         : y)
#endif
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vccosh))                      \
    match(construct = {target variant dispatch}, device = {arch(gen)})
void vcCosh(const MKL_INT n, const MKL_Complex8* a, MKL_Complex8* y) NOTHROW;

#if (_OPENMP >= 202011)
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vccoshi))                     \
    match(construct = {dispatch}, device = {arch(gen)})                        \
        append_args(interop(prefer_type("sycl", "level_zero"), targetsync))    \
            adjust_args(need_device_ptr                                        \
                        : a) adjust_args(need_device_ptr                       \
                                         : y)
#endif
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vccoshi))                     \
    match(construct = {target variant dispatch}, device = {arch(gen)})
void vcCoshI(const MKL_INT n, const MKL_Complex8* a, MKL_INT inca,
             MKL_Complex8* y, MKL_INT incy) NOTHROW;

#if (_OPENMP >= 202011)
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vmccosh))                     \
    match(construct = {dispatch}, device = {arch(gen)})                        \
        append_args(interop(prefer_type("sycl", "level_zero"), targetsync))    \
            adjust_args(need_device_ptr                                        \
                        : a) adjust_args(need_device_ptr                       \
                                         : y)
#endif
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vmccosh))                     \
    match(construct = {target variant dispatch}, device = {arch(gen)})
void vmcCosh(const MKL_INT n, const MKL_Complex8* a, MKL_Complex8* y,
             MKL_INT64 mode) NOTHROW;

#if (_OPENMP >= 202011)
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vmccoshi))                    \
    match(construct = {dispatch}, device = {arch(gen)})                        \
        append_args(interop(prefer_type("sycl", "level_zero"), targetsync))    \
            adjust_args(need_device_ptr                                        \
                        : a) adjust_args(need_device_ptr                       \
                                         : y)
#endif
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vmccoshi))                    \
    match(construct = {target variant dispatch}, device = {arch(gen)})
void vmcCoshI(const MKL_INT n, const MKL_Complex8* a, MKL_INT inca,
              MKL_Complex8* y, MKL_INT incy, MKL_INT64 mode) NOTHROW;

#if (_OPENMP >= 202011)
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vzcosh))                      \
    match(construct = {dispatch}, device = {arch(gen)})                        \
        append_args(interop(prefer_type("sycl", "level_zero"), targetsync))    \
            adjust_args(need_device_ptr                                        \
                        : a) adjust_args(need_device_ptr                       \
                                         : y)
#endif
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vzcosh))                      \
    match(construct = {target variant dispatch}, device = {arch(gen)})
void vzCosh(const MKL_INT n, const MKL_Complex16* a, MKL_Complex16* y) NOTHROW;

#if (_OPENMP >= 202011)
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vzcoshi))                     \
    match(construct = {dispatch}, device = {arch(gen)})                        \
        append_args(interop(prefer_type("sycl", "level_zero"), targetsync))    \
            adjust_args(need_device_ptr                                        \
                        : a) adjust_args(need_device_ptr                       \
                                         : y)
#endif
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vzcoshi))                     \
    match(construct = {target variant dispatch}, device = {arch(gen)})
void vzCoshI(const MKL_INT n, const MKL_Complex16* a, MKL_INT inca,
             MKL_Complex16* y, MKL_INT incy) NOTHROW;

#if (_OPENMP >= 202011)
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vmzcosh))                     \
    match(construct = {dispatch}, device = {arch(gen)})                        \
        append_args(interop(prefer_type("sycl", "level_zero"), targetsync))    \
            adjust_args(need_device_ptr                                        \
                        : a) adjust_args(need_device_ptr                       \
                                         : y)
#endif
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vmzcosh))                     \
    match(construct = {target variant dispatch}, device = {arch(gen)})
void vmzCosh(const MKL_INT n, const MKL_Complex16* a, MKL_Complex16* y,
             MKL_INT64 mode) NOTHROW;

#if (_OPENMP >= 202011)
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vmzcoshi))                    \
    match(construct = {dispatch}, device = {arch(gen)})                        \
        append_args(interop(prefer_type("sycl", "level_zero"), targetsync))    \
            adjust_args(need_device_ptr                                        \
                        : a) adjust_args(need_device_ptr                       \
                                         : y)
#endif
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vmzcoshi))                    \
    match(construct = {target variant dispatch}, device = {arch(gen)})
void vmzCoshI(const MKL_INT n, const MKL_Complex16* a, MKL_INT inca,
              MKL_Complex16* y, MKL_INT incy, MKL_INT64 mode) NOTHROW;

// function cospi
#if (_OPENMP >= 202011)
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vscospi))                     \
    match(construct = {dispatch}, device = {arch(gen)})                        \
        append_args(interop(prefer_type("sycl", "level_zero"), targetsync))    \
            adjust_args(need_device_ptr                                        \
                        : a) adjust_args(need_device_ptr                       \
                                         : y)
#endif
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vscospi))                     \
    match(construct = {target variant dispatch}, device = {arch(gen)})
void vsCospi(const MKL_INT n, const float* a, float* y) NOTHROW;

#if (_OPENMP >= 202011)
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vscospii))                    \
    match(construct = {dispatch}, device = {arch(gen)})                        \
        append_args(interop(prefer_type("sycl", "level_zero"), targetsync))    \
            adjust_args(need_device_ptr                                        \
                        : a) adjust_args(need_device_ptr                       \
                                         : y)
#endif
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vscospii))                    \
    match(construct = {target variant dispatch}, device = {arch(gen)})
void vsCospiI(const MKL_INT n, const float* a, MKL_INT inca, float* y,
              MKL_INT incy) NOTHROW;

#if (_OPENMP >= 202011)
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vmscospi))                    \
    match(construct = {dispatch}, device = {arch(gen)})                        \
        append_args(interop(prefer_type("sycl", "level_zero"), targetsync))    \
            adjust_args(need_device_ptr                                        \
                        : a) adjust_args(need_device_ptr                       \
                                         : y)
#endif
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vmscospi))                    \
    match(construct = {target variant dispatch}, device = {arch(gen)})
void vmsCospi(const MKL_INT n, const float* a, float* y,
              MKL_INT64 mode) NOTHROW;

#if (_OPENMP >= 202011)
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vmscospii))                   \
    match(construct = {dispatch}, device = {arch(gen)})                        \
        append_args(interop(prefer_type("sycl", "level_zero"), targetsync))    \
            adjust_args(need_device_ptr                                        \
                        : a) adjust_args(need_device_ptr                       \
                                         : y)
#endif
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vmscospii))                   \
    match(construct = {target variant dispatch}, device = {arch(gen)})
void vmsCospiI(const MKL_INT n, const float* a, MKL_INT inca, float* y,
               MKL_INT incy, MKL_INT64 mode) NOTHROW;

#if (_OPENMP >= 202011)
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vdcospi))                     \
    match(construct = {dispatch}, device = {arch(gen)})                        \
        append_args(interop(prefer_type("sycl", "level_zero"), targetsync))    \
            adjust_args(need_device_ptr                                        \
                        : a) adjust_args(need_device_ptr                       \
                                         : y)
#endif
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vdcospi))                     \
    match(construct = {target variant dispatch}, device = {arch(gen)})
void vdCospi(const MKL_INT n, const double* a, double* y) NOTHROW;

#if (_OPENMP >= 202011)
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vdcospii))                    \
    match(construct = {dispatch}, device = {arch(gen)})                        \
        append_args(interop(prefer_type("sycl", "level_zero"), targetsync))    \
            adjust_args(need_device_ptr                                        \
                        : a) adjust_args(need_device_ptr                       \
                                         : y)
#endif
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vdcospii))                    \
    match(construct = {target variant dispatch}, device = {arch(gen)})
void vdCospiI(const MKL_INT n, const double* a, MKL_INT inca, double* y,
              MKL_INT incy) NOTHROW;

#if (_OPENMP >= 202011)
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vmdcospi))                    \
    match(construct = {dispatch}, device = {arch(gen)})                        \
        append_args(interop(prefer_type("sycl", "level_zero"), targetsync))    \
            adjust_args(need_device_ptr                                        \
                        : a) adjust_args(need_device_ptr                       \
                                         : y)
#endif
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vmdcospi))                    \
    match(construct = {target variant dispatch}, device = {arch(gen)})
void vmdCospi(const MKL_INT n, const double* a, double* y,
              MKL_INT64 mode) NOTHROW;

#if (_OPENMP >= 202011)
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vmdcospii))                   \
    match(construct = {dispatch}, device = {arch(gen)})                        \
        append_args(interop(prefer_type("sycl", "level_zero"), targetsync))    \
            adjust_args(need_device_ptr                                        \
                        : a) adjust_args(need_device_ptr                       \
                                         : y)
#endif
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vmdcospii))                   \
    match(construct = {target variant dispatch}, device = {arch(gen)})
void vmdCospiI(const MKL_INT n, const double* a, MKL_INT inca, double* y,
               MKL_INT incy, MKL_INT64 mode) NOTHROW;

// function div
#if (_OPENMP >= 202011)
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vsdiv))                       \
    match(construct = {dispatch}, device = {arch(gen)})                        \
        append_args(interop(prefer_type("sycl", "level_zero"), targetsync))    \
            adjust_args(need_device_ptr                                        \
                        : a) adjust_args(need_device_ptr                       \
                                         : b) adjust_args(need_device_ptr      \
                                                          : y)
#endif
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vsdiv))                       \
    match(construct = {target variant dispatch}, device = {arch(gen)})
void vsDiv(const MKL_INT n, const float* a, const float* b, float* y) NOTHROW;

#if (_OPENMP >= 202011)
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vsdivi))                      \
    match(construct = {dispatch}, device = {arch(gen)})                        \
        append_args(interop(prefer_type("sycl", "level_zero"), targetsync))    \
            adjust_args(need_device_ptr                                        \
                        : a) adjust_args(need_device_ptr                       \
                                         : b) adjust_args(need_device_ptr      \
                                                          : y)
#endif
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vsdivi))                      \
    match(construct = {target variant dispatch}, device = {arch(gen)})
void vsDivI(const MKL_INT n, const float* a, MKL_INT inca, const float* b,
            MKL_INT incb, float* y, MKL_INT incy) NOTHROW;

#if (_OPENMP >= 202011)
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vmsdiv))                      \
    match(construct = {dispatch}, device = {arch(gen)})                        \
        append_args(interop(prefer_type("sycl", "level_zero"), targetsync))    \
            adjust_args(need_device_ptr                                        \
                        : a) adjust_args(need_device_ptr                       \
                                         : b) adjust_args(need_device_ptr      \
                                                          : y)
#endif
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vmsdiv))                      \
    match(construct = {target variant dispatch}, device = {arch(gen)})
void vmsDiv(const MKL_INT n, const float* a, const float* b, float* y,
            MKL_INT64 mode) NOTHROW;

#if (_OPENMP >= 202011)
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vmsdivi))                     \
    match(construct = {dispatch}, device = {arch(gen)})                        \
        append_args(interop(prefer_type("sycl", "level_zero"), targetsync))    \
            adjust_args(need_device_ptr                                        \
                        : a) adjust_args(need_device_ptr                       \
                                         : b) adjust_args(need_device_ptr      \
                                                          : y)
#endif
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vmsdivi))                     \
    match(construct = {target variant dispatch}, device = {arch(gen)})
void vmsDivI(const MKL_INT n, const float* a, MKL_INT inca, const float* b,
             MKL_INT incb, float* y, MKL_INT incy, MKL_INT64 mode) NOTHROW;

#if (_OPENMP >= 202011)
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vddiv))                       \
    match(construct = {dispatch}, device = {arch(gen)})                        \
        append_args(interop(prefer_type("sycl", "level_zero"), targetsync))    \
            adjust_args(need_device_ptr                                        \
                        : a) adjust_args(need_device_ptr                       \
                                         : b) adjust_args(need_device_ptr      \
                                                          : y)
#endif
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vddiv))                       \
    match(construct = {target variant dispatch}, device = {arch(gen)})
void vdDiv(const MKL_INT n, const double* a, const double* b,
           double* y) NOTHROW;

#if (_OPENMP >= 202011)
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vddivi))                      \
    match(construct = {dispatch}, device = {arch(gen)})                        \
        append_args(interop(prefer_type("sycl", "level_zero"), targetsync))    \
            adjust_args(need_device_ptr                                        \
                        : a) adjust_args(need_device_ptr                       \
                                         : b) adjust_args(need_device_ptr      \
                                                          : y)
#endif
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vddivi))                      \
    match(construct = {target variant dispatch}, device = {arch(gen)})
void vdDivI(const MKL_INT n, const double* a, MKL_INT inca, const double* b,
            MKL_INT incb, double* y, MKL_INT incy) NOTHROW;

#if (_OPENMP >= 202011)
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vmddiv))                      \
    match(construct = {dispatch}, device = {arch(gen)})                        \
        append_args(interop(prefer_type("sycl", "level_zero"), targetsync))    \
            adjust_args(need_device_ptr                                        \
                        : a) adjust_args(need_device_ptr                       \
                                         : b) adjust_args(need_device_ptr      \
                                                          : y)
#endif
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vmddiv))                      \
    match(construct = {target variant dispatch}, device = {arch(gen)})
void vmdDiv(const MKL_INT n, const double* a, const double* b, double* y,
            MKL_INT64 mode) NOTHROW;

#if (_OPENMP >= 202011)
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vmddivi))                     \
    match(construct = {dispatch}, device = {arch(gen)})                        \
        append_args(interop(prefer_type("sycl", "level_zero"), targetsync))    \
            adjust_args(need_device_ptr                                        \
                        : a) adjust_args(need_device_ptr                       \
                                         : b) adjust_args(need_device_ptr      \
                                                          : y)
#endif
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vmddivi))                     \
    match(construct = {target variant dispatch}, device = {arch(gen)})
void vmdDivI(const MKL_INT n, const double* a, MKL_INT inca, const double* b,
             MKL_INT incb, double* y, MKL_INT incy, MKL_INT64 mode) NOTHROW;

#if (_OPENMP >= 202011)
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vcdiv))                       \
    match(construct = {dispatch}, device = {arch(gen)})                        \
        append_args(interop(prefer_type("sycl", "level_zero"), targetsync))    \
            adjust_args(need_device_ptr                                        \
                        : a) adjust_args(need_device_ptr                       \
                                         : b) adjust_args(need_device_ptr      \
                                                          : y)
#endif
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vcdiv))                       \
    match(construct = {target variant dispatch}, device = {arch(gen)})
void vcDiv(const MKL_INT n, const MKL_Complex8* a, const MKL_Complex8* b,
           MKL_Complex8* y) NOTHROW;

#if (_OPENMP >= 202011)
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vcdivi))                      \
    match(construct = {dispatch}, device = {arch(gen)})                        \
        append_args(interop(prefer_type("sycl", "level_zero"), targetsync))    \
            adjust_args(need_device_ptr                                        \
                        : a) adjust_args(need_device_ptr                       \
                                         : b) adjust_args(need_device_ptr      \
                                                          : y)
#endif
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vcdivi))                      \
    match(construct = {target variant dispatch}, device = {arch(gen)})
void vcDivI(const MKL_INT n, const MKL_Complex8* a, MKL_INT inca,
            const MKL_Complex8* b, MKL_INT incb, MKL_Complex8* y,
            MKL_INT incy) NOTHROW;

#if (_OPENMP >= 202011)
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vmcdiv))                      \
    match(construct = {dispatch}, device = {arch(gen)})                        \
        append_args(interop(prefer_type("sycl", "level_zero"), targetsync))    \
            adjust_args(need_device_ptr                                        \
                        : a) adjust_args(need_device_ptr                       \
                                         : b) adjust_args(need_device_ptr      \
                                                          : y)
#endif
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vmcdiv))                      \
    match(construct = {target variant dispatch}, device = {arch(gen)})
void vmcDiv(const MKL_INT n, const MKL_Complex8* a, const MKL_Complex8* b,
            MKL_Complex8* y, MKL_INT64 mode) NOTHROW;

#if (_OPENMP >= 202011)
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vmcdivi))                     \
    match(construct = {dispatch}, device = {arch(gen)})                        \
        append_args(interop(prefer_type("sycl", "level_zero"), targetsync))    \
            adjust_args(need_device_ptr                                        \
                        : a) adjust_args(need_device_ptr                       \
                                         : b) adjust_args(need_device_ptr      \
                                                          : y)
#endif
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vmcdivi))                     \
    match(construct = {target variant dispatch}, device = {arch(gen)})
void vmcDivI(const MKL_INT n, const MKL_Complex8* a, MKL_INT inca,
             const MKL_Complex8* b, MKL_INT incb, MKL_Complex8* y, MKL_INT incy,
             MKL_INT64 mode) NOTHROW;

#if (_OPENMP >= 202011)
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vzdiv))                       \
    match(construct = {dispatch}, device = {arch(gen)})                        \
        append_args(interop(prefer_type("sycl", "level_zero"), targetsync))    \
            adjust_args(need_device_ptr                                        \
                        : a) adjust_args(need_device_ptr                       \
                                         : b) adjust_args(need_device_ptr      \
                                                          : y)
#endif
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vzdiv))                       \
    match(construct = {target variant dispatch}, device = {arch(gen)})
void vzDiv(const MKL_INT n, const MKL_Complex16* a, const MKL_Complex16* b,
           MKL_Complex16* y) NOTHROW;

#if (_OPENMP >= 202011)
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vzdivi))                      \
    match(construct = {dispatch}, device = {arch(gen)})                        \
        append_args(interop(prefer_type("sycl", "level_zero"), targetsync))    \
            adjust_args(need_device_ptr                                        \
                        : a) adjust_args(need_device_ptr                       \
                                         : b) adjust_args(need_device_ptr      \
                                                          : y)
#endif
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vzdivi))                      \
    match(construct = {target variant dispatch}, device = {arch(gen)})
void vzDivI(const MKL_INT n, const MKL_Complex16* a, MKL_INT inca,
            const MKL_Complex16* b, MKL_INT incb, MKL_Complex16* y,
            MKL_INT incy) NOTHROW;

#if (_OPENMP >= 202011)
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vmzdiv))                      \
    match(construct = {dispatch}, device = {arch(gen)})                        \
        append_args(interop(prefer_type("sycl", "level_zero"), targetsync))    \
            adjust_args(need_device_ptr                                        \
                        : a) adjust_args(need_device_ptr                       \
                                         : b) adjust_args(need_device_ptr      \
                                                          : y)
#endif
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vmzdiv))                      \
    match(construct = {target variant dispatch}, device = {arch(gen)})
void vmzDiv(const MKL_INT n, const MKL_Complex16* a, const MKL_Complex16* b,
            MKL_Complex16* y, MKL_INT64 mode) NOTHROW;

#if (_OPENMP >= 202011)
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vmzdivi))                     \
    match(construct = {dispatch}, device = {arch(gen)})                        \
        append_args(interop(prefer_type("sycl", "level_zero"), targetsync))    \
            adjust_args(need_device_ptr                                        \
                        : a) adjust_args(need_device_ptr                       \
                                         : b) adjust_args(need_device_ptr      \
                                                          : y)
#endif
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vmzdivi))                     \
    match(construct = {target variant dispatch}, device = {arch(gen)})
void vmzDivI(const MKL_INT n, const MKL_Complex16* a, MKL_INT inca,
             const MKL_Complex16* b, MKL_INT incb, MKL_Complex16* y,
             MKL_INT incy, MKL_INT64 mode) NOTHROW;

// function erf
#if (_OPENMP >= 202011)
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vserf))                       \
    match(construct = {dispatch}, device = {arch(gen)})                        \
        append_args(interop(prefer_type("sycl", "level_zero"), targetsync))    \
            adjust_args(need_device_ptr                                        \
                        : a) adjust_args(need_device_ptr                       \
                                         : y)
#endif
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vserf))                       \
    match(construct = {target variant dispatch}, device = {arch(gen)})
void vsErf(const MKL_INT n, const float* a, float* y) NOTHROW;

#if (_OPENMP >= 202011)
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vserfi))                      \
    match(construct = {dispatch}, device = {arch(gen)})                        \
        append_args(interop(prefer_type("sycl", "level_zero"), targetsync))    \
            adjust_args(need_device_ptr                                        \
                        : a) adjust_args(need_device_ptr                       \
                                         : y)
#endif
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vserfi))                      \
    match(construct = {target variant dispatch}, device = {arch(gen)})
void vsErfI(const MKL_INT n, const float* a, MKL_INT inca, float* y,
            MKL_INT incy) NOTHROW;

#if (_OPENMP >= 202011)
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vmserf))                      \
    match(construct = {dispatch}, device = {arch(gen)})                        \
        append_args(interop(prefer_type("sycl", "level_zero"), targetsync))    \
            adjust_args(need_device_ptr                                        \
                        : a) adjust_args(need_device_ptr                       \
                                         : y)
#endif
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vmserf))                      \
    match(construct = {target variant dispatch}, device = {arch(gen)})
void vmsErf(const MKL_INT n, const float* a, float* y, MKL_INT64 mode) NOTHROW;

#if (_OPENMP >= 202011)
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vmserfi))                     \
    match(construct = {dispatch}, device = {arch(gen)})                        \
        append_args(interop(prefer_type("sycl", "level_zero"), targetsync))    \
            adjust_args(need_device_ptr                                        \
                        : a) adjust_args(need_device_ptr                       \
                                         : y)
#endif
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vmserfi))                     \
    match(construct = {target variant dispatch}, device = {arch(gen)})
void vmsErfI(const MKL_INT n, const float* a, MKL_INT inca, float* y,
             MKL_INT incy, MKL_INT64 mode) NOTHROW;

#if (_OPENMP >= 202011)
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vderf))                       \
    match(construct = {dispatch}, device = {arch(gen)})                        \
        append_args(interop(prefer_type("sycl", "level_zero"), targetsync))    \
            adjust_args(need_device_ptr                                        \
                        : a) adjust_args(need_device_ptr                       \
                                         : y)
#endif
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vderf))                       \
    match(construct = {target variant dispatch}, device = {arch(gen)})
void vdErf(const MKL_INT n, const double* a, double* y) NOTHROW;

#if (_OPENMP >= 202011)
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vderfi))                      \
    match(construct = {dispatch}, device = {arch(gen)})                        \
        append_args(interop(prefer_type("sycl", "level_zero"), targetsync))    \
            adjust_args(need_device_ptr                                        \
                        : a) adjust_args(need_device_ptr                       \
                                         : y)
#endif
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vderfi))                      \
    match(construct = {target variant dispatch}, device = {arch(gen)})
void vdErfI(const MKL_INT n, const double* a, MKL_INT inca, double* y,
            MKL_INT incy) NOTHROW;

#if (_OPENMP >= 202011)
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vmderf))                      \
    match(construct = {dispatch}, device = {arch(gen)})                        \
        append_args(interop(prefer_type("sycl", "level_zero"), targetsync))    \
            adjust_args(need_device_ptr                                        \
                        : a) adjust_args(need_device_ptr                       \
                                         : y)
#endif
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vmderf))                      \
    match(construct = {target variant dispatch}, device = {arch(gen)})
void vmdErf(const MKL_INT n, const double* a, double* y,
            MKL_INT64 mode) NOTHROW;

#if (_OPENMP >= 202011)
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vmderfi))                     \
    match(construct = {dispatch}, device = {arch(gen)})                        \
        append_args(interop(prefer_type("sycl", "level_zero"), targetsync))    \
            adjust_args(need_device_ptr                                        \
                        : a) adjust_args(need_device_ptr                       \
                                         : y)
#endif
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vmderfi))                     \
    match(construct = {target variant dispatch}, device = {arch(gen)})
void vmdErfI(const MKL_INT n, const double* a, MKL_INT inca, double* y,
             MKL_INT incy, MKL_INT64 mode) NOTHROW;

// function erfc
#if (_OPENMP >= 202011)
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vserfc))                      \
    match(construct = {dispatch}, device = {arch(gen)})                        \
        append_args(interop(prefer_type("sycl", "level_zero"), targetsync))    \
            adjust_args(need_device_ptr                                        \
                        : a) adjust_args(need_device_ptr                       \
                                         : y)
#endif
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vserfc))                      \
    match(construct = {target variant dispatch}, device = {arch(gen)})
void vsErfc(const MKL_INT n, const float* a, float* y) NOTHROW;

#if (_OPENMP >= 202011)
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vserfci))                     \
    match(construct = {dispatch}, device = {arch(gen)})                        \
        append_args(interop(prefer_type("sycl", "level_zero"), targetsync))    \
            adjust_args(need_device_ptr                                        \
                        : a) adjust_args(need_device_ptr                       \
                                         : y)
#endif
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vserfci))                     \
    match(construct = {target variant dispatch}, device = {arch(gen)})
void vsErfcI(const MKL_INT n, const float* a, MKL_INT inca, float* y,
             MKL_INT incy) NOTHROW;

#if (_OPENMP >= 202011)
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vmserfc))                     \
    match(construct = {dispatch}, device = {arch(gen)})                        \
        append_args(interop(prefer_type("sycl", "level_zero"), targetsync))    \
            adjust_args(need_device_ptr                                        \
                        : a) adjust_args(need_device_ptr                       \
                                         : y)
#endif
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vmserfc))                     \
    match(construct = {target variant dispatch}, device = {arch(gen)})
void vmsErfc(const MKL_INT n, const float* a, float* y, MKL_INT64 mode) NOTHROW;

#if (_OPENMP >= 202011)
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vmserfci))                    \
    match(construct = {dispatch}, device = {arch(gen)})                        \
        append_args(interop(prefer_type("sycl", "level_zero"), targetsync))    \
            adjust_args(need_device_ptr                                        \
                        : a) adjust_args(need_device_ptr                       \
                                         : y)
#endif
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vmserfci))                    \
    match(construct = {target variant dispatch}, device = {arch(gen)})
void vmsErfcI(const MKL_INT n, const float* a, MKL_INT inca, float* y,
              MKL_INT incy, MKL_INT64 mode) NOTHROW;

#if (_OPENMP >= 202011)
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vderfc))                      \
    match(construct = {dispatch}, device = {arch(gen)})                        \
        append_args(interop(prefer_type("sycl", "level_zero"), targetsync))    \
            adjust_args(need_device_ptr                                        \
                        : a) adjust_args(need_device_ptr                       \
                                         : y)
#endif
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vderfc))                      \
    match(construct = {target variant dispatch}, device = {arch(gen)})
void vdErfc(const MKL_INT n, const double* a, double* y) NOTHROW;

#if (_OPENMP >= 202011)
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vderfci))                     \
    match(construct = {dispatch}, device = {arch(gen)})                        \
        append_args(interop(prefer_type("sycl", "level_zero"), targetsync))    \
            adjust_args(need_device_ptr                                        \
                        : a) adjust_args(need_device_ptr                       \
                                         : y)
#endif
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vderfci))                     \
    match(construct = {target variant dispatch}, device = {arch(gen)})
void vdErfcI(const MKL_INT n, const double* a, MKL_INT inca, double* y,
             MKL_INT incy) NOTHROW;

#if (_OPENMP >= 202011)
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vmderfc))                     \
    match(construct = {dispatch}, device = {arch(gen)})                        \
        append_args(interop(prefer_type("sycl", "level_zero"), targetsync))    \
            adjust_args(need_device_ptr                                        \
                        : a) adjust_args(need_device_ptr                       \
                                         : y)
#endif
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vmderfc))                     \
    match(construct = {target variant dispatch}, device = {arch(gen)})
void vmdErfc(const MKL_INT n, const double* a, double* y,
             MKL_INT64 mode) NOTHROW;

#if (_OPENMP >= 202011)
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vmderfci))                    \
    match(construct = {dispatch}, device = {arch(gen)})                        \
        append_args(interop(prefer_type("sycl", "level_zero"), targetsync))    \
            adjust_args(need_device_ptr                                        \
                        : a) adjust_args(need_device_ptr                       \
                                         : y)
#endif
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vmderfci))                    \
    match(construct = {target variant dispatch}, device = {arch(gen)})
void vmdErfcI(const MKL_INT n, const double* a, MKL_INT inca, double* y,
              MKL_INT incy, MKL_INT64 mode) NOTHROW;

// function erfcinv
#if (_OPENMP >= 202011)
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vserfcinv))                   \
    match(construct = {dispatch}, device = {arch(gen)})                        \
        append_args(interop(prefer_type("sycl", "level_zero"), targetsync))    \
            adjust_args(need_device_ptr                                        \
                        : a) adjust_args(need_device_ptr                       \
                                         : y)
#endif
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vserfcinv))                   \
    match(construct = {target variant dispatch}, device = {arch(gen)})
void vsErfcInv(const MKL_INT n, const float* a, float* y) NOTHROW;

#if (_OPENMP >= 202011)
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vserfcinvi))                  \
    match(construct = {dispatch}, device = {arch(gen)})                        \
        append_args(interop(prefer_type("sycl", "level_zero"), targetsync))    \
            adjust_args(need_device_ptr                                        \
                        : a) adjust_args(need_device_ptr                       \
                                         : y)
#endif
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vserfcinvi))                  \
    match(construct = {target variant dispatch}, device = {arch(gen)})
void vsErfcInvI(const MKL_INT n, const float* a, MKL_INT inca, float* y,
                MKL_INT incy) NOTHROW;

#if (_OPENMP >= 202011)
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vmserfcinv))                  \
    match(construct = {dispatch}, device = {arch(gen)})                        \
        append_args(interop(prefer_type("sycl", "level_zero"), targetsync))    \
            adjust_args(need_device_ptr                                        \
                        : a) adjust_args(need_device_ptr                       \
                                         : y)
#endif
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vmserfcinv))                  \
    match(construct = {target variant dispatch}, device = {arch(gen)})
void vmsErfcInv(const MKL_INT n, const float* a, float* y,
                MKL_INT64 mode) NOTHROW;

#if (_OPENMP >= 202011)
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vmserfcinvi))                 \
    match(construct = {dispatch}, device = {arch(gen)})                        \
        append_args(interop(prefer_type("sycl", "level_zero"), targetsync))    \
            adjust_args(need_device_ptr                                        \
                        : a) adjust_args(need_device_ptr                       \
                                         : y)
#endif
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vmserfcinvi))                 \
    match(construct = {target variant dispatch}, device = {arch(gen)})
void vmsErfcInvI(const MKL_INT n, const float* a, MKL_INT inca, float* y,
                 MKL_INT incy, MKL_INT64 mode) NOTHROW;

#if (_OPENMP >= 202011)
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vderfcinv))                   \
    match(construct = {dispatch}, device = {arch(gen)})                        \
        append_args(interop(prefer_type("sycl", "level_zero"), targetsync))    \
            adjust_args(need_device_ptr                                        \
                        : a) adjust_args(need_device_ptr                       \
                                         : y)
#endif
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vderfcinv))                   \
    match(construct = {target variant dispatch}, device = {arch(gen)})
void vdErfcInv(const MKL_INT n, const double* a, double* y) NOTHROW;

#if (_OPENMP >= 202011)
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vderfcinvi))                  \
    match(construct = {dispatch}, device = {arch(gen)})                        \
        append_args(interop(prefer_type("sycl", "level_zero"), targetsync))    \
            adjust_args(need_device_ptr                                        \
                        : a) adjust_args(need_device_ptr                       \
                                         : y)
#endif
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vderfcinvi))                  \
    match(construct = {target variant dispatch}, device = {arch(gen)})
void vdErfcInvI(const MKL_INT n, const double* a, MKL_INT inca, double* y,
                MKL_INT incy) NOTHROW;

#if (_OPENMP >= 202011)
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vmderfcinv))                  \
    match(construct = {dispatch}, device = {arch(gen)})                        \
        append_args(interop(prefer_type("sycl", "level_zero"), targetsync))    \
            adjust_args(need_device_ptr                                        \
                        : a) adjust_args(need_device_ptr                       \
                                         : y)
#endif
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vmderfcinv))                  \
    match(construct = {target variant dispatch}, device = {arch(gen)})
void vmdErfcInv(const MKL_INT n, const double* a, double* y,
                MKL_INT64 mode) NOTHROW;

#if (_OPENMP >= 202011)
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vmderfcinvi))                 \
    match(construct = {dispatch}, device = {arch(gen)})                        \
        append_args(interop(prefer_type("sycl", "level_zero"), targetsync))    \
            adjust_args(need_device_ptr                                        \
                        : a) adjust_args(need_device_ptr                       \
                                         : y)
#endif
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vmderfcinvi))                 \
    match(construct = {target variant dispatch}, device = {arch(gen)})
void vmdErfcInvI(const MKL_INT n, const double* a, MKL_INT inca, double* y,
                 MKL_INT incy, MKL_INT64 mode) NOTHROW;

// function erfcx
#if (_OPENMP >= 202011)
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vserfcx))                     \
    match(construct = {dispatch}, device = {arch(gen)})                        \
        append_args(interop(prefer_type("sycl", "level_zero"), targetsync))    \
            adjust_args(need_device_ptr                                        \
                        : a) adjust_args(need_device_ptr                       \
                                         : y)
#endif
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vserfcx))                     \
    match(construct = {target variant dispatch}, device = {arch(gen)})
void vsErfcx(const MKL_INT n, const float* a, float* y) NOTHROW;

#if (_OPENMP >= 202011)
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vserfcxi))                    \
    match(construct = {dispatch}, device = {arch(gen)})                        \
        append_args(interop(prefer_type("sycl", "level_zero"), targetsync))    \
            adjust_args(need_device_ptr                                        \
                        : a) adjust_args(need_device_ptr                       \
                                         : y)
#endif
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vserfcxi))                    \
    match(construct = {target variant dispatch}, device = {arch(gen)})
void vsErfcxI(const MKL_INT n, const float* a, MKL_INT inca, float* y,
              MKL_INT incy) NOTHROW;

#if (_OPENMP >= 202011)
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vmserfcx))                    \
    match(construct = {dispatch}, device = {arch(gen)})                        \
        append_args(interop(prefer_type("sycl", "level_zero"), targetsync))    \
            adjust_args(need_device_ptr                                        \
                        : a) adjust_args(need_device_ptr                       \
                                         : y)
#endif
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vmserfcx))                    \
    match(construct = {target variant dispatch}, device = {arch(gen)})
void vmsErfcx(const MKL_INT n, const float* a, float* y,
              MKL_INT64 mode) NOTHROW;

#if (_OPENMP >= 202011)
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vmserfcxi))                   \
    match(construct = {dispatch}, device = {arch(gen)})                        \
        append_args(interop(prefer_type("sycl", "level_zero"), targetsync))    \
            adjust_args(need_device_ptr                                        \
                        : a) adjust_args(need_device_ptr                       \
                                         : y)
#endif
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vmserfcxi))                   \
    match(construct = {target variant dispatch}, device = {arch(gen)})
void vmsErfcxI(const MKL_INT n, const float* a, MKL_INT inca, float* y,
               MKL_INT incy, MKL_INT64 mode) NOTHROW;

#if (_OPENMP >= 202011)
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vderfcx))                     \
    match(construct = {dispatch}, device = {arch(gen)})                        \
        append_args(interop(prefer_type("sycl", "level_zero"), targetsync))    \
            adjust_args(need_device_ptr                                        \
                        : a) adjust_args(need_device_ptr                       \
                                         : y)
#endif
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vderfcx))                     \
    match(construct = {target variant dispatch}, device = {arch(gen)})
void vdErfcx(const MKL_INT n, const double* a, double* y) NOTHROW;

#if (_OPENMP >= 202011)
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vderfcxi))                    \
    match(construct = {dispatch}, device = {arch(gen)})                        \
        append_args(interop(prefer_type("sycl", "level_zero"), targetsync))    \
            adjust_args(need_device_ptr                                        \
                        : a) adjust_args(need_device_ptr                       \
                                         : y)
#endif
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vderfcxi))                    \
    match(construct = {target variant dispatch}, device = {arch(gen)})
void vdErfcxI(const MKL_INT n, const double* a, MKL_INT inca, double* y,
              MKL_INT incy) NOTHROW;

#if (_OPENMP >= 202011)
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vmderfcx))                    \
    match(construct = {dispatch}, device = {arch(gen)})                        \
        append_args(interop(prefer_type("sycl", "level_zero"), targetsync))    \
            adjust_args(need_device_ptr                                        \
                        : a) adjust_args(need_device_ptr                       \
                                         : y)
#endif
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vmderfcx))                    \
    match(construct = {target variant dispatch}, device = {arch(gen)})
void vmdErfcx(const MKL_INT n, const double* a, double* y,
              MKL_INT64 mode) NOTHROW;

#if (_OPENMP >= 202011)
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vmderfcxi))                   \
    match(construct = {dispatch}, device = {arch(gen)})                        \
        append_args(interop(prefer_type("sycl", "level_zero"), targetsync))    \
            adjust_args(need_device_ptr                                        \
                        : a) adjust_args(need_device_ptr                       \
                                         : y)
#endif
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vmderfcxi))                   \
    match(construct = {target variant dispatch}, device = {arch(gen)})
void vmdErfcxI(const MKL_INT n, const double* a, MKL_INT inca, double* y,
               MKL_INT incy, MKL_INT64 mode) NOTHROW;

// function erfinv
#if (_OPENMP >= 202011)
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vserfinv))                    \
    match(construct = {dispatch}, device = {arch(gen)})                        \
        append_args(interop(prefer_type("sycl", "level_zero"), targetsync))    \
            adjust_args(need_device_ptr                                        \
                        : a) adjust_args(need_device_ptr                       \
                                         : y)
#endif
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vserfinv))                    \
    match(construct = {target variant dispatch}, device = {arch(gen)})
void vsErfInv(const MKL_INT n, const float* a, float* y) NOTHROW;

#if (_OPENMP >= 202011)
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vserfinvi))                   \
    match(construct = {dispatch}, device = {arch(gen)})                        \
        append_args(interop(prefer_type("sycl", "level_zero"), targetsync))    \
            adjust_args(need_device_ptr                                        \
                        : a) adjust_args(need_device_ptr                       \
                                         : y)
#endif
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vserfinvi))                   \
    match(construct = {target variant dispatch}, device = {arch(gen)})
void vsErfInvI(const MKL_INT n, const float* a, MKL_INT inca, float* y,
               MKL_INT incy) NOTHROW;

#if (_OPENMP >= 202011)
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vmserfinv))                   \
    match(construct = {dispatch}, device = {arch(gen)})                        \
        append_args(interop(prefer_type("sycl", "level_zero"), targetsync))    \
            adjust_args(need_device_ptr                                        \
                        : a) adjust_args(need_device_ptr                       \
                                         : y)
#endif
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vmserfinv))                   \
    match(construct = {target variant dispatch}, device = {arch(gen)})
void vmsErfInv(const MKL_INT n, const float* a, float* y,
               MKL_INT64 mode) NOTHROW;

#if (_OPENMP >= 202011)
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vmserfinvi))                  \
    match(construct = {dispatch}, device = {arch(gen)})                        \
        append_args(interop(prefer_type("sycl", "level_zero"), targetsync))    \
            adjust_args(need_device_ptr                                        \
                        : a) adjust_args(need_device_ptr                       \
                                         : y)
#endif
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vmserfinvi))                  \
    match(construct = {target variant dispatch}, device = {arch(gen)})
void vmsErfInvI(const MKL_INT n, const float* a, MKL_INT inca, float* y,
                MKL_INT incy, MKL_INT64 mode) NOTHROW;

#if (_OPENMP >= 202011)
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vderfinv))                    \
    match(construct = {dispatch}, device = {arch(gen)})                        \
        append_args(interop(prefer_type("sycl", "level_zero"), targetsync))    \
            adjust_args(need_device_ptr                                        \
                        : a) adjust_args(need_device_ptr                       \
                                         : y)
#endif
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vderfinv))                    \
    match(construct = {target variant dispatch}, device = {arch(gen)})
void vdErfInv(const MKL_INT n, const double* a, double* y) NOTHROW;

#if (_OPENMP >= 202011)
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vderfinvi))                   \
    match(construct = {dispatch}, device = {arch(gen)})                        \
        append_args(interop(prefer_type("sycl", "level_zero"), targetsync))    \
            adjust_args(need_device_ptr                                        \
                        : a) adjust_args(need_device_ptr                       \
                                         : y)
#endif
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vderfinvi))                   \
    match(construct = {target variant dispatch}, device = {arch(gen)})
void vdErfInvI(const MKL_INT n, const double* a, MKL_INT inca, double* y,
               MKL_INT incy) NOTHROW;

#if (_OPENMP >= 202011)
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vmderfinv))                   \
    match(construct = {dispatch}, device = {arch(gen)})                        \
        append_args(interop(prefer_type("sycl", "level_zero"), targetsync))    \
            adjust_args(need_device_ptr                                        \
                        : a) adjust_args(need_device_ptr                       \
                                         : y)
#endif
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vmderfinv))                   \
    match(construct = {target variant dispatch}, device = {arch(gen)})
void vmdErfInv(const MKL_INT n, const double* a, double* y,
               MKL_INT64 mode) NOTHROW;

#if (_OPENMP >= 202011)
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vmderfinvi))                  \
    match(construct = {dispatch}, device = {arch(gen)})                        \
        append_args(interop(prefer_type("sycl", "level_zero"), targetsync))    \
            adjust_args(need_device_ptr                                        \
                        : a) adjust_args(need_device_ptr                       \
                                         : y)
#endif
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vmderfinvi))                  \
    match(construct = {target variant dispatch}, device = {arch(gen)})
void vmdErfInvI(const MKL_INT n, const double* a, MKL_INT inca, double* y,
                MKL_INT incy, MKL_INT64 mode) NOTHROW;

// function exp
#if (_OPENMP >= 202011)
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vsexp))                       \
    match(construct = {dispatch}, device = {arch(gen)})                        \
        append_args(interop(prefer_type("sycl", "level_zero"), targetsync))    \
            adjust_args(need_device_ptr                                        \
                        : a) adjust_args(need_device_ptr                       \
                                         : y)
#endif
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vsexp))                       \
    match(construct = {target variant dispatch}, device = {arch(gen)})
void vsExp(const MKL_INT n, const float* a, float* y) NOTHROW;

#if (_OPENMP >= 202011)
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vsexpi))                      \
    match(construct = {dispatch}, device = {arch(gen)})                        \
        append_args(interop(prefer_type("sycl", "level_zero"), targetsync))    \
            adjust_args(need_device_ptr                                        \
                        : a) adjust_args(need_device_ptr                       \
                                         : y)
#endif
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vsexpi))                      \
    match(construct = {target variant dispatch}, device = {arch(gen)})
void vsExpI(const MKL_INT n, const float* a, MKL_INT inca, float* y,
            MKL_INT incy) NOTHROW;

#if (_OPENMP >= 202011)
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vmsexp))                      \
    match(construct = {dispatch}, device = {arch(gen)})                        \
        append_args(interop(prefer_type("sycl", "level_zero"), targetsync))    \
            adjust_args(need_device_ptr                                        \
                        : a) adjust_args(need_device_ptr                       \
                                         : y)
#endif
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vmsexp))                      \
    match(construct = {target variant dispatch}, device = {arch(gen)})
void vmsExp(const MKL_INT n, const float* a, float* y, MKL_INT64 mode) NOTHROW;

#if (_OPENMP >= 202011)
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vmsexpi))                     \
    match(construct = {dispatch}, device = {arch(gen)})                        \
        append_args(interop(prefer_type("sycl", "level_zero"), targetsync))    \
            adjust_args(need_device_ptr                                        \
                        : a) adjust_args(need_device_ptr                       \
                                         : y)
#endif
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vmsexpi))                     \
    match(construct = {target variant dispatch}, device = {arch(gen)})
void vmsExpI(const MKL_INT n, const float* a, MKL_INT inca, float* y,
             MKL_INT incy, MKL_INT64 mode) NOTHROW;

#if (_OPENMP >= 202011)
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vdexp))                       \
    match(construct = {dispatch}, device = {arch(gen)})                        \
        append_args(interop(prefer_type("sycl", "level_zero"), targetsync))    \
            adjust_args(need_device_ptr                                        \
                        : a) adjust_args(need_device_ptr                       \
                                         : y)
#endif
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vdexp))                       \
    match(construct = {target variant dispatch}, device = {arch(gen)})
void vdExp(const MKL_INT n, const double* a, double* y) NOTHROW;

#if (_OPENMP >= 202011)
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vdexpi))                      \
    match(construct = {dispatch}, device = {arch(gen)})                        \
        append_args(interop(prefer_type("sycl", "level_zero"), targetsync))    \
            adjust_args(need_device_ptr                                        \
                        : a) adjust_args(need_device_ptr                       \
                                         : y)
#endif
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vdexpi))                      \
    match(construct = {target variant dispatch}, device = {arch(gen)})
void vdExpI(const MKL_INT n, const double* a, MKL_INT inca, double* y,
            MKL_INT incy) NOTHROW;

#if (_OPENMP >= 202011)
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vmdexp))                      \
    match(construct = {dispatch}, device = {arch(gen)})                        \
        append_args(interop(prefer_type("sycl", "level_zero"), targetsync))    \
            adjust_args(need_device_ptr                                        \
                        : a) adjust_args(need_device_ptr                       \
                                         : y)
#endif
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vmdexp))                      \
    match(construct = {target variant dispatch}, device = {arch(gen)})
void vmdExp(const MKL_INT n, const double* a, double* y,
            MKL_INT64 mode) NOTHROW;

#if (_OPENMP >= 202011)
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vmdexpi))                     \
    match(construct = {dispatch}, device = {arch(gen)})                        \
        append_args(interop(prefer_type("sycl", "level_zero"), targetsync))    \
            adjust_args(need_device_ptr                                        \
                        : a) adjust_args(need_device_ptr                       \
                                         : y)
#endif
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vmdexpi))                     \
    match(construct = {target variant dispatch}, device = {arch(gen)})
void vmdExpI(const MKL_INT n, const double* a, MKL_INT inca, double* y,
             MKL_INT incy, MKL_INT64 mode) NOTHROW;

#if (_OPENMP >= 202011)
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vcexp))                       \
    match(construct = {dispatch}, device = {arch(gen)})                        \
        append_args(interop(prefer_type("sycl", "level_zero"), targetsync))    \
            adjust_args(need_device_ptr                                        \
                        : a) adjust_args(need_device_ptr                       \
                                         : y)
#endif
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vcexp))                       \
    match(construct = {target variant dispatch}, device = {arch(gen)})
void vcExp(const MKL_INT n, const MKL_Complex8* a, MKL_Complex8* y) NOTHROW;

#if (_OPENMP >= 202011)
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vcexpi))                      \
    match(construct = {dispatch}, device = {arch(gen)})                        \
        append_args(interop(prefer_type("sycl", "level_zero"), targetsync))    \
            adjust_args(need_device_ptr                                        \
                        : a) adjust_args(need_device_ptr                       \
                                         : y)
#endif
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vcexpi))                      \
    match(construct = {target variant dispatch}, device = {arch(gen)})
void vcExpI(const MKL_INT n, const MKL_Complex8* a, MKL_INT inca,
            MKL_Complex8* y, MKL_INT incy) NOTHROW;

#if (_OPENMP >= 202011)
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vmcexp))                      \
    match(construct = {dispatch}, device = {arch(gen)})                        \
        append_args(interop(prefer_type("sycl", "level_zero"), targetsync))    \
            adjust_args(need_device_ptr                                        \
                        : a) adjust_args(need_device_ptr                       \
                                         : y)
#endif
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vmcexp))                      \
    match(construct = {target variant dispatch}, device = {arch(gen)})
void vmcExp(const MKL_INT n, const MKL_Complex8* a, MKL_Complex8* y,
            MKL_INT64 mode) NOTHROW;

#if (_OPENMP >= 202011)
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vmcexpi))                     \
    match(construct = {dispatch}, device = {arch(gen)})                        \
        append_args(interop(prefer_type("sycl", "level_zero"), targetsync))    \
            adjust_args(need_device_ptr                                        \
                        : a) adjust_args(need_device_ptr                       \
                                         : y)
#endif
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vmcexpi))                     \
    match(construct = {target variant dispatch}, device = {arch(gen)})
void vmcExpI(const MKL_INT n, const MKL_Complex8* a, MKL_INT inca,
             MKL_Complex8* y, MKL_INT incy, MKL_INT64 mode) NOTHROW;

#if (_OPENMP >= 202011)
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vzexp))                       \
    match(construct = {dispatch}, device = {arch(gen)})                        \
        append_args(interop(prefer_type("sycl", "level_zero"), targetsync))    \
            adjust_args(need_device_ptr                                        \
                        : a) adjust_args(need_device_ptr                       \
                                         : y)
#endif
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vzexp))                       \
    match(construct = {target variant dispatch}, device = {arch(gen)})
void vzExp(const MKL_INT n, const MKL_Complex16* a, MKL_Complex16* y) NOTHROW;

#if (_OPENMP >= 202011)
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vzexpi))                      \
    match(construct = {dispatch}, device = {arch(gen)})                        \
        append_args(interop(prefer_type("sycl", "level_zero"), targetsync))    \
            adjust_args(need_device_ptr                                        \
                        : a) adjust_args(need_device_ptr                       \
                                         : y)
#endif
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vzexpi))                      \
    match(construct = {target variant dispatch}, device = {arch(gen)})
void vzExpI(const MKL_INT n, const MKL_Complex16* a, MKL_INT inca,
            MKL_Complex16* y, MKL_INT incy) NOTHROW;

#if (_OPENMP >= 202011)
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vmzexp))                      \
    match(construct = {dispatch}, device = {arch(gen)})                        \
        append_args(interop(prefer_type("sycl", "level_zero"), targetsync))    \
            adjust_args(need_device_ptr                                        \
                        : a) adjust_args(need_device_ptr                       \
                                         : y)
#endif
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vmzexp))                      \
    match(construct = {target variant dispatch}, device = {arch(gen)})
void vmzExp(const MKL_INT n, const MKL_Complex16* a, MKL_Complex16* y,
            MKL_INT64 mode) NOTHROW;

#if (_OPENMP >= 202011)
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vmzexpi))                     \
    match(construct = {dispatch}, device = {arch(gen)})                        \
        append_args(interop(prefer_type("sycl", "level_zero"), targetsync))    \
            adjust_args(need_device_ptr                                        \
                        : a) adjust_args(need_device_ptr                       \
                                         : y)
#endif
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vmzexpi))                     \
    match(construct = {target variant dispatch}, device = {arch(gen)})
void vmzExpI(const MKL_INT n, const MKL_Complex16* a, MKL_INT inca,
             MKL_Complex16* y, MKL_INT incy, MKL_INT64 mode) NOTHROW;

// function exp10
#if (_OPENMP >= 202011)
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vsexp10))                     \
    match(construct = {dispatch}, device = {arch(gen)})                        \
        append_args(interop(prefer_type("sycl", "level_zero"), targetsync))    \
            adjust_args(need_device_ptr                                        \
                        : a) adjust_args(need_device_ptr                       \
                                         : y)
#endif
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vsexp10))                     \
    match(construct = {target variant dispatch}, device = {arch(gen)})
void vsExp10(const MKL_INT n, const float* a, float* y) NOTHROW;

#if (_OPENMP >= 202011)
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vsexp10i))                    \
    match(construct = {dispatch}, device = {arch(gen)})                        \
        append_args(interop(prefer_type("sycl", "level_zero"), targetsync))    \
            adjust_args(need_device_ptr                                        \
                        : a) adjust_args(need_device_ptr                       \
                                         : y)
#endif
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vsexp10i))                    \
    match(construct = {target variant dispatch}, device = {arch(gen)})
void vsExp10I(const MKL_INT n, const float* a, MKL_INT inca, float* y,
              MKL_INT incy) NOTHROW;

#if (_OPENMP >= 202011)
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vmsexp10))                    \
    match(construct = {dispatch}, device = {arch(gen)})                        \
        append_args(interop(prefer_type("sycl", "level_zero"), targetsync))    \
            adjust_args(need_device_ptr                                        \
                        : a) adjust_args(need_device_ptr                       \
                                         : y)
#endif
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vmsexp10))                    \
    match(construct = {target variant dispatch}, device = {arch(gen)})
void vmsExp10(const MKL_INT n, const float* a, float* y,
              MKL_INT64 mode) NOTHROW;

#if (_OPENMP >= 202011)
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vmsexp10i))                   \
    match(construct = {dispatch}, device = {arch(gen)})                        \
        append_args(interop(prefer_type("sycl", "level_zero"), targetsync))    \
            adjust_args(need_device_ptr                                        \
                        : a) adjust_args(need_device_ptr                       \
                                         : y)
#endif
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vmsexp10i))                   \
    match(construct = {target variant dispatch}, device = {arch(gen)})
void vmsExp10I(const MKL_INT n, const float* a, MKL_INT inca, float* y,
               MKL_INT incy, MKL_INT64 mode) NOTHROW;

#if (_OPENMP >= 202011)
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vdexp10))                     \
    match(construct = {dispatch}, device = {arch(gen)})                        \
        append_args(interop(prefer_type("sycl", "level_zero"), targetsync))    \
            adjust_args(need_device_ptr                                        \
                        : a) adjust_args(need_device_ptr                       \
                                         : y)
#endif
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vdexp10))                     \
    match(construct = {target variant dispatch}, device = {arch(gen)})
void vdExp10(const MKL_INT n, const double* a, double* y) NOTHROW;

#if (_OPENMP >= 202011)
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vdexp10i))                    \
    match(construct = {dispatch}, device = {arch(gen)})                        \
        append_args(interop(prefer_type("sycl", "level_zero"), targetsync))    \
            adjust_args(need_device_ptr                                        \
                        : a) adjust_args(need_device_ptr                       \
                                         : y)
#endif
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vdexp10i))                    \
    match(construct = {target variant dispatch}, device = {arch(gen)})
void vdExp10I(const MKL_INT n, const double* a, MKL_INT inca, double* y,
              MKL_INT incy) NOTHROW;

#if (_OPENMP >= 202011)
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vmdexp10))                    \
    match(construct = {dispatch}, device = {arch(gen)})                        \
        append_args(interop(prefer_type("sycl", "level_zero"), targetsync))    \
            adjust_args(need_device_ptr                                        \
                        : a) adjust_args(need_device_ptr                       \
                                         : y)
#endif
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vmdexp10))                    \
    match(construct = {target variant dispatch}, device = {arch(gen)})
void vmdExp10(const MKL_INT n, const double* a, double* y,
              MKL_INT64 mode) NOTHROW;

#if (_OPENMP >= 202011)
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vmdexp10i))                   \
    match(construct = {dispatch}, device = {arch(gen)})                        \
        append_args(interop(prefer_type("sycl", "level_zero"), targetsync))    \
            adjust_args(need_device_ptr                                        \
                        : a) adjust_args(need_device_ptr                       \
                                         : y)
#endif
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vmdexp10i))                   \
    match(construct = {target variant dispatch}, device = {arch(gen)})
void vmdExp10I(const MKL_INT n, const double* a, MKL_INT inca, double* y,
               MKL_INT incy, MKL_INT64 mode) NOTHROW;

// function exp2
#if (_OPENMP >= 202011)
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vsexp2))                      \
    match(construct = {dispatch}, device = {arch(gen)})                        \
        append_args(interop(prefer_type("sycl", "level_zero"), targetsync))    \
            adjust_args(need_device_ptr                                        \
                        : a) adjust_args(need_device_ptr                       \
                                         : y)
#endif
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vsexp2))                      \
    match(construct = {target variant dispatch}, device = {arch(gen)})
void vsExp2(const MKL_INT n, const float* a, float* y) NOTHROW;

#if (_OPENMP >= 202011)
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vsexp2i))                     \
    match(construct = {dispatch}, device = {arch(gen)})                        \
        append_args(interop(prefer_type("sycl", "level_zero"), targetsync))    \
            adjust_args(need_device_ptr                                        \
                        : a) adjust_args(need_device_ptr                       \
                                         : y)
#endif
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vsexp2i))                     \
    match(construct = {target variant dispatch}, device = {arch(gen)})
void vsExp2I(const MKL_INT n, const float* a, MKL_INT inca, float* y,
             MKL_INT incy) NOTHROW;

#if (_OPENMP >= 202011)
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vmsexp2))                     \
    match(construct = {dispatch}, device = {arch(gen)})                        \
        append_args(interop(prefer_type("sycl", "level_zero"), targetsync))    \
            adjust_args(need_device_ptr                                        \
                        : a) adjust_args(need_device_ptr                       \
                                         : y)
#endif
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vmsexp2))                     \
    match(construct = {target variant dispatch}, device = {arch(gen)})
void vmsExp2(const MKL_INT n, const float* a, float* y, MKL_INT64 mode) NOTHROW;

#if (_OPENMP >= 202011)
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vmsexp2i))                    \
    match(construct = {dispatch}, device = {arch(gen)})                        \
        append_args(interop(prefer_type("sycl", "level_zero"), targetsync))    \
            adjust_args(need_device_ptr                                        \
                        : a) adjust_args(need_device_ptr                       \
                                         : y)
#endif
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vmsexp2i))                    \
    match(construct = {target variant dispatch}, device = {arch(gen)})
void vmsExp2I(const MKL_INT n, const float* a, MKL_INT inca, float* y,
              MKL_INT incy, MKL_INT64 mode) NOTHROW;

#if (_OPENMP >= 202011)
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vdexp2))                      \
    match(construct = {dispatch}, device = {arch(gen)})                        \
        append_args(interop(prefer_type("sycl", "level_zero"), targetsync))    \
            adjust_args(need_device_ptr                                        \
                        : a) adjust_args(need_device_ptr                       \
                                         : y)
#endif
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vdexp2))                      \
    match(construct = {target variant dispatch}, device = {arch(gen)})
void vdExp2(const MKL_INT n, const double* a, double* y) NOTHROW;

#if (_OPENMP >= 202011)
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vdexp2i))                     \
    match(construct = {dispatch}, device = {arch(gen)})                        \
        append_args(interop(prefer_type("sycl", "level_zero"), targetsync))    \
            adjust_args(need_device_ptr                                        \
                        : a) adjust_args(need_device_ptr                       \
                                         : y)
#endif
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vdexp2i))                     \
    match(construct = {target variant dispatch}, device = {arch(gen)})
void vdExp2I(const MKL_INT n, const double* a, MKL_INT inca, double* y,
             MKL_INT incy) NOTHROW;

#if (_OPENMP >= 202011)
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vmdexp2))                     \
    match(construct = {dispatch}, device = {arch(gen)})                        \
        append_args(interop(prefer_type("sycl", "level_zero"), targetsync))    \
            adjust_args(need_device_ptr                                        \
                        : a) adjust_args(need_device_ptr                       \
                                         : y)
#endif
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vmdexp2))                     \
    match(construct = {target variant dispatch}, device = {arch(gen)})
void vmdExp2(const MKL_INT n, const double* a, double* y,
             MKL_INT64 mode) NOTHROW;

#if (_OPENMP >= 202011)
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vmdexp2i))                    \
    match(construct = {dispatch}, device = {arch(gen)})                        \
        append_args(interop(prefer_type("sycl", "level_zero"), targetsync))    \
            adjust_args(need_device_ptr                                        \
                        : a) adjust_args(need_device_ptr                       \
                                         : y)
#endif
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vmdexp2i))                    \
    match(construct = {target variant dispatch}, device = {arch(gen)})
void vmdExp2I(const MKL_INT n, const double* a, MKL_INT inca, double* y,
              MKL_INT incy, MKL_INT64 mode) NOTHROW;

// function expint1
#if (_OPENMP >= 202011)
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vsexpint1))                   \
    match(construct = {dispatch}, device = {arch(gen)})                        \
        append_args(interop(prefer_type("sycl", "level_zero"), targetsync))    \
            adjust_args(need_device_ptr                                        \
                        : a) adjust_args(need_device_ptr                       \
                                         : y)
#endif
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vsexpint1))                   \
    match(construct = {target variant dispatch}, device = {arch(gen)})
void vsExpInt1(const MKL_INT n, const float* a, float* y) NOTHROW;

#if (_OPENMP >= 202011)
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vsexpint1i))                  \
    match(construct = {dispatch}, device = {arch(gen)})                        \
        append_args(interop(prefer_type("sycl", "level_zero"), targetsync))    \
            adjust_args(need_device_ptr                                        \
                        : a) adjust_args(need_device_ptr                       \
                                         : y)
#endif
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vsexpint1i))                  \
    match(construct = {target variant dispatch}, device = {arch(gen)})
void vsExpInt1I(const MKL_INT n, const float* a, MKL_INT inca, float* y,
                MKL_INT incy) NOTHROW;

#if (_OPENMP >= 202011)
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vmsexpint1))                  \
    match(construct = {dispatch}, device = {arch(gen)})                        \
        append_args(interop(prefer_type("sycl", "level_zero"), targetsync))    \
            adjust_args(need_device_ptr                                        \
                        : a) adjust_args(need_device_ptr                       \
                                         : y)
#endif
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vmsexpint1))                  \
    match(construct = {target variant dispatch}, device = {arch(gen)})
void vmsExpInt1(const MKL_INT n, const float* a, float* y,
                MKL_INT64 mode) NOTHROW;

#if (_OPENMP >= 202011)
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vmsexpint1i))                 \
    match(construct = {dispatch}, device = {arch(gen)})                        \
        append_args(interop(prefer_type("sycl", "level_zero"), targetsync))    \
            adjust_args(need_device_ptr                                        \
                        : a) adjust_args(need_device_ptr                       \
                                         : y)
#endif
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vmsexpint1i))                 \
    match(construct = {target variant dispatch}, device = {arch(gen)})
void vmsExpInt1I(const MKL_INT n, const float* a, MKL_INT inca, float* y,
                 MKL_INT incy, MKL_INT64 mode) NOTHROW;

#if (_OPENMP >= 202011)
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vdexpint1))                   \
    match(construct = {dispatch}, device = {arch(gen)})                        \
        append_args(interop(prefer_type("sycl", "level_zero"), targetsync))    \
            adjust_args(need_device_ptr                                        \
                        : a) adjust_args(need_device_ptr                       \
                                         : y)
#endif
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vdexpint1))                   \
    match(construct = {target variant dispatch}, device = {arch(gen)})
void vdExpInt1(const MKL_INT n, const double* a, double* y) NOTHROW;

#if (_OPENMP >= 202011)
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vdexpint1i))                  \
    match(construct = {dispatch}, device = {arch(gen)})                        \
        append_args(interop(prefer_type("sycl", "level_zero"), targetsync))    \
            adjust_args(need_device_ptr                                        \
                        : a) adjust_args(need_device_ptr                       \
                                         : y)
#endif
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vdexpint1i))                  \
    match(construct = {target variant dispatch}, device = {arch(gen)})
void vdExpInt1I(const MKL_INT n, const double* a, MKL_INT inca, double* y,
                MKL_INT incy) NOTHROW;

#if (_OPENMP >= 202011)
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vmdexpint1))                  \
    match(construct = {dispatch}, device = {arch(gen)})                        \
        append_args(interop(prefer_type("sycl", "level_zero"), targetsync))    \
            adjust_args(need_device_ptr                                        \
                        : a) adjust_args(need_device_ptr                       \
                                         : y)
#endif
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vmdexpint1))                  \
    match(construct = {target variant dispatch}, device = {arch(gen)})
void vmdExpInt1(const MKL_INT n, const double* a, double* y,
                MKL_INT64 mode) NOTHROW;

#if (_OPENMP >= 202011)
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vmdexpint1i))                 \
    match(construct = {dispatch}, device = {arch(gen)})                        \
        append_args(interop(prefer_type("sycl", "level_zero"), targetsync))    \
            adjust_args(need_device_ptr                                        \
                        : a) adjust_args(need_device_ptr                       \
                                         : y)
#endif
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vmdexpint1i))                 \
    match(construct = {target variant dispatch}, device = {arch(gen)})
void vmdExpInt1I(const MKL_INT n, const double* a, MKL_INT inca, double* y,
                 MKL_INT incy, MKL_INT64 mode) NOTHROW;

// function expm1
#if (_OPENMP >= 202011)
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vsexpm1))                     \
    match(construct = {dispatch}, device = {arch(gen)})                        \
        append_args(interop(prefer_type("sycl", "level_zero"), targetsync))    \
            adjust_args(need_device_ptr                                        \
                        : a) adjust_args(need_device_ptr                       \
                                         : y)
#endif
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vsexpm1))                     \
    match(construct = {target variant dispatch}, device = {arch(gen)})
void vsExpm1(const MKL_INT n, const float* a, float* y) NOTHROW;

#if (_OPENMP >= 202011)
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vsexpm1i))                    \
    match(construct = {dispatch}, device = {arch(gen)})                        \
        append_args(interop(prefer_type("sycl", "level_zero"), targetsync))    \
            adjust_args(need_device_ptr                                        \
                        : a) adjust_args(need_device_ptr                       \
                                         : y)
#endif
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vsexpm1i))                    \
    match(construct = {target variant dispatch}, device = {arch(gen)})
void vsExpm1I(const MKL_INT n, const float* a, MKL_INT inca, float* y,
              MKL_INT incy) NOTHROW;

#if (_OPENMP >= 202011)
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vmsexpm1))                    \
    match(construct = {dispatch}, device = {arch(gen)})                        \
        append_args(interop(prefer_type("sycl", "level_zero"), targetsync))    \
            adjust_args(need_device_ptr                                        \
                        : a) adjust_args(need_device_ptr                       \
                                         : y)
#endif
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vmsexpm1))                    \
    match(construct = {target variant dispatch}, device = {arch(gen)})
void vmsExpm1(const MKL_INT n, const float* a, float* y,
              MKL_INT64 mode) NOTHROW;

#if (_OPENMP >= 202011)
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vmsexpm1i))                   \
    match(construct = {dispatch}, device = {arch(gen)})                        \
        append_args(interop(prefer_type("sycl", "level_zero"), targetsync))    \
            adjust_args(need_device_ptr                                        \
                        : a) adjust_args(need_device_ptr                       \
                                         : y)
#endif
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vmsexpm1i))                   \
    match(construct = {target variant dispatch}, device = {arch(gen)})
void vmsExpm1I(const MKL_INT n, const float* a, MKL_INT inca, float* y,
               MKL_INT incy, MKL_INT64 mode) NOTHROW;

#if (_OPENMP >= 202011)
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vdexpm1))                     \
    match(construct = {dispatch}, device = {arch(gen)})                        \
        append_args(interop(prefer_type("sycl", "level_zero"), targetsync))    \
            adjust_args(need_device_ptr                                        \
                        : a) adjust_args(need_device_ptr                       \
                                         : y)
#endif
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vdexpm1))                     \
    match(construct = {target variant dispatch}, device = {arch(gen)})
void vdExpm1(const MKL_INT n, const double* a, double* y) NOTHROW;

#if (_OPENMP >= 202011)
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vdexpm1i))                    \
    match(construct = {dispatch}, device = {arch(gen)})                        \
        append_args(interop(prefer_type("sycl", "level_zero"), targetsync))    \
            adjust_args(need_device_ptr                                        \
                        : a) adjust_args(need_device_ptr                       \
                                         : y)
#endif
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vdexpm1i))                    \
    match(construct = {target variant dispatch}, device = {arch(gen)})
void vdExpm1I(const MKL_INT n, const double* a, MKL_INT inca, double* y,
              MKL_INT incy) NOTHROW;

#if (_OPENMP >= 202011)
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vmdexpm1))                    \
    match(construct = {dispatch}, device = {arch(gen)})                        \
        append_args(interop(prefer_type("sycl", "level_zero"), targetsync))    \
            adjust_args(need_device_ptr                                        \
                        : a) adjust_args(need_device_ptr                       \
                                         : y)
#endif
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vmdexpm1))                    \
    match(construct = {target variant dispatch}, device = {arch(gen)})
void vmdExpm1(const MKL_INT n, const double* a, double* y,
              MKL_INT64 mode) NOTHROW;

#if (_OPENMP >= 202011)
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vmdexpm1i))                   \
    match(construct = {dispatch}, device = {arch(gen)})                        \
        append_args(interop(prefer_type("sycl", "level_zero"), targetsync))    \
            adjust_args(need_device_ptr                                        \
                        : a) adjust_args(need_device_ptr                       \
                                         : y)
#endif
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vmdexpm1i))                   \
    match(construct = {target variant dispatch}, device = {arch(gen)})
void vmdExpm1I(const MKL_INT n, const double* a, MKL_INT inca, double* y,
               MKL_INT incy, MKL_INT64 mode) NOTHROW;

// function fdim
#if (_OPENMP >= 202011)
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vsfdim))                      \
    match(construct = {dispatch}, device = {arch(gen)})                        \
        append_args(interop(prefer_type("sycl", "level_zero"), targetsync))    \
            adjust_args(need_device_ptr                                        \
                        : a) adjust_args(need_device_ptr                       \
                                         : b) adjust_args(need_device_ptr      \
                                                          : y)
#endif
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vsfdim))                      \
    match(construct = {target variant dispatch}, device = {arch(gen)})
void vsFdim(const MKL_INT n, const float* a, const float* b, float* y) NOTHROW;

#if (_OPENMP >= 202011)
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vsfdimi))                     \
    match(construct = {dispatch}, device = {arch(gen)})                        \
        append_args(interop(prefer_type("sycl", "level_zero"), targetsync))    \
            adjust_args(need_device_ptr                                        \
                        : a) adjust_args(need_device_ptr                       \
                                         : b) adjust_args(need_device_ptr      \
                                                          : y)
#endif
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vsfdimi))                     \
    match(construct = {target variant dispatch}, device = {arch(gen)})
void vsFdimI(const MKL_INT n, const float* a, MKL_INT inca, const float* b,
             MKL_INT incb, float* y, MKL_INT incy) NOTHROW;

#if (_OPENMP >= 202011)
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vmsfdim))                     \
    match(construct = {dispatch}, device = {arch(gen)})                        \
        append_args(interop(prefer_type("sycl", "level_zero"), targetsync))    \
            adjust_args(need_device_ptr                                        \
                        : a) adjust_args(need_device_ptr                       \
                                         : b) adjust_args(need_device_ptr      \
                                                          : y)
#endif
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vmsfdim))                     \
    match(construct = {target variant dispatch}, device = {arch(gen)})
void vmsFdim(const MKL_INT n, const float* a, const float* b, float* y,
             MKL_INT64 mode) NOTHROW;

#if (_OPENMP >= 202011)
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vmsfdimi))                    \
    match(construct = {dispatch}, device = {arch(gen)})                        \
        append_args(interop(prefer_type("sycl", "level_zero"), targetsync))    \
            adjust_args(need_device_ptr                                        \
                        : a) adjust_args(need_device_ptr                       \
                                         : b) adjust_args(need_device_ptr      \
                                                          : y)
#endif
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vmsfdimi))                    \
    match(construct = {target variant dispatch}, device = {arch(gen)})
void vmsFdimI(const MKL_INT n, const float* a, MKL_INT inca, const float* b,
              MKL_INT incb, float* y, MKL_INT incy, MKL_INT64 mode) NOTHROW;

#if (_OPENMP >= 202011)
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vdfdim))                      \
    match(construct = {dispatch}, device = {arch(gen)})                        \
        append_args(interop(prefer_type("sycl", "level_zero"), targetsync))    \
            adjust_args(need_device_ptr                                        \
                        : a) adjust_args(need_device_ptr                       \
                                         : b) adjust_args(need_device_ptr      \
                                                          : y)
#endif
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vdfdim))                      \
    match(construct = {target variant dispatch}, device = {arch(gen)})
void vdFdim(const MKL_INT n, const double* a, const double* b,
            double* y) NOTHROW;

#if (_OPENMP >= 202011)
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vdfdimi))                     \
    match(construct = {dispatch}, device = {arch(gen)})                        \
        append_args(interop(prefer_type("sycl", "level_zero"), targetsync))    \
            adjust_args(need_device_ptr                                        \
                        : a) adjust_args(need_device_ptr                       \
                                         : b) adjust_args(need_device_ptr      \
                                                          : y)
#endif
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vdfdimi))                     \
    match(construct = {target variant dispatch}, device = {arch(gen)})
void vdFdimI(const MKL_INT n, const double* a, MKL_INT inca, const double* b,
             MKL_INT incb, double* y, MKL_INT incy) NOTHROW;

#if (_OPENMP >= 202011)
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vmdfdim))                     \
    match(construct = {dispatch}, device = {arch(gen)})                        \
        append_args(interop(prefer_type("sycl", "level_zero"), targetsync))    \
            adjust_args(need_device_ptr                                        \
                        : a) adjust_args(need_device_ptr                       \
                                         : b) adjust_args(need_device_ptr      \
                                                          : y)
#endif
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vmdfdim))                     \
    match(construct = {target variant dispatch}, device = {arch(gen)})
void vmdFdim(const MKL_INT n, const double* a, const double* b, double* y,
             MKL_INT64 mode) NOTHROW;

#if (_OPENMP >= 202011)
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vmdfdimi))                    \
    match(construct = {dispatch}, device = {arch(gen)})                        \
        append_args(interop(prefer_type("sycl", "level_zero"), targetsync))    \
            adjust_args(need_device_ptr                                        \
                        : a) adjust_args(need_device_ptr                       \
                                         : b) adjust_args(need_device_ptr      \
                                                          : y)
#endif
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vmdfdimi))                    \
    match(construct = {target variant dispatch}, device = {arch(gen)})
void vmdFdimI(const MKL_INT n, const double* a, MKL_INT inca, const double* b,
              MKL_INT incb, double* y, MKL_INT incy, MKL_INT64 mode) NOTHROW;

// function floor
#if (_OPENMP >= 202011)
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vsfloor))                     \
    match(construct = {dispatch}, device = {arch(gen)})                        \
        append_args(interop(prefer_type("sycl", "level_zero"), targetsync))    \
            adjust_args(need_device_ptr                                        \
                        : a) adjust_args(need_device_ptr                       \
                                         : y)
#endif
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vsfloor))                     \
    match(construct = {target variant dispatch}, device = {arch(gen)})
void vsFloor(const MKL_INT n, const float* a, float* y) NOTHROW;

#if (_OPENMP >= 202011)
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vsfloori))                    \
    match(construct = {dispatch}, device = {arch(gen)})                        \
        append_args(interop(prefer_type("sycl", "level_zero"), targetsync))    \
            adjust_args(need_device_ptr                                        \
                        : a) adjust_args(need_device_ptr                       \
                                         : y)
#endif
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vsfloori))                    \
    match(construct = {target variant dispatch}, device = {arch(gen)})
void vsFloorI(const MKL_INT n, const float* a, MKL_INT inca, float* y,
              MKL_INT incy) NOTHROW;

#if (_OPENMP >= 202011)
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vmsfloor))                    \
    match(construct = {dispatch}, device = {arch(gen)})                        \
        append_args(interop(prefer_type("sycl", "level_zero"), targetsync))    \
            adjust_args(need_device_ptr                                        \
                        : a) adjust_args(need_device_ptr                       \
                                         : y)
#endif
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vmsfloor))                    \
    match(construct = {target variant dispatch}, device = {arch(gen)})
void vmsFloor(const MKL_INT n, const float* a, float* y,
              MKL_INT64 mode) NOTHROW;

#if (_OPENMP >= 202011)
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vmsfloori))                   \
    match(construct = {dispatch}, device = {arch(gen)})                        \
        append_args(interop(prefer_type("sycl", "level_zero"), targetsync))    \
            adjust_args(need_device_ptr                                        \
                        : a) adjust_args(need_device_ptr                       \
                                         : y)
#endif
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vmsfloori))                   \
    match(construct = {target variant dispatch}, device = {arch(gen)})
void vmsFloorI(const MKL_INT n, const float* a, MKL_INT inca, float* y,
               MKL_INT incy, MKL_INT64 mode) NOTHROW;

#if (_OPENMP >= 202011)
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vdfloor))                     \
    match(construct = {dispatch}, device = {arch(gen)})                        \
        append_args(interop(prefer_type("sycl", "level_zero"), targetsync))    \
            adjust_args(need_device_ptr                                        \
                        : a) adjust_args(need_device_ptr                       \
                                         : y)
#endif
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vdfloor))                     \
    match(construct = {target variant dispatch}, device = {arch(gen)})
void vdFloor(const MKL_INT n, const double* a, double* y) NOTHROW;

#if (_OPENMP >= 202011)
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vdfloori))                    \
    match(construct = {dispatch}, device = {arch(gen)})                        \
        append_args(interop(prefer_type("sycl", "level_zero"), targetsync))    \
            adjust_args(need_device_ptr                                        \
                        : a) adjust_args(need_device_ptr                       \
                                         : y)
#endif
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vdfloori))                    \
    match(construct = {target variant dispatch}, device = {arch(gen)})
void vdFloorI(const MKL_INT n, const double* a, MKL_INT inca, double* y,
              MKL_INT incy) NOTHROW;

#if (_OPENMP >= 202011)
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vmdfloor))                    \
    match(construct = {dispatch}, device = {arch(gen)})                        \
        append_args(interop(prefer_type("sycl", "level_zero"), targetsync))    \
            adjust_args(need_device_ptr                                        \
                        : a) adjust_args(need_device_ptr                       \
                                         : y)
#endif
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vmdfloor))                    \
    match(construct = {target variant dispatch}, device = {arch(gen)})
void vmdFloor(const MKL_INT n, const double* a, double* y,
              MKL_INT64 mode) NOTHROW;

#if (_OPENMP >= 202011)
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vmdfloori))                   \
    match(construct = {dispatch}, device = {arch(gen)})                        \
        append_args(interop(prefer_type("sycl", "level_zero"), targetsync))    \
            adjust_args(need_device_ptr                                        \
                        : a) adjust_args(need_device_ptr                       \
                                         : y)
#endif
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vmdfloori))                   \
    match(construct = {target variant dispatch}, device = {arch(gen)})
void vmdFloorI(const MKL_INT n, const double* a, MKL_INT inca, double* y,
               MKL_INT incy, MKL_INT64 mode) NOTHROW;

// function fmax
#if (_OPENMP >= 202011)
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vsfmax))                      \
    match(construct = {dispatch}, device = {arch(gen)})                        \
        append_args(interop(prefer_type("sycl", "level_zero"), targetsync))    \
            adjust_args(need_device_ptr                                        \
                        : a) adjust_args(need_device_ptr                       \
                                         : b) adjust_args(need_device_ptr      \
                                                          : y)
#endif
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vsfmax))                      \
    match(construct = {target variant dispatch}, device = {arch(gen)})
void vsFmax(const MKL_INT n, const float* a, const float* b, float* y) NOTHROW;

#if (_OPENMP >= 202011)
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vsfmaxi))                     \
    match(construct = {dispatch}, device = {arch(gen)})                        \
        append_args(interop(prefer_type("sycl", "level_zero"), targetsync))    \
            adjust_args(need_device_ptr                                        \
                        : a) adjust_args(need_device_ptr                       \
                                         : b) adjust_args(need_device_ptr      \
                                                          : y)
#endif
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vsfmaxi))                     \
    match(construct = {target variant dispatch}, device = {arch(gen)})
void vsFmaxI(const MKL_INT n, const float* a, MKL_INT inca, const float* b,
             MKL_INT incb, float* y, MKL_INT incy) NOTHROW;

#if (_OPENMP >= 202011)
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vmsfmax))                     \
    match(construct = {dispatch}, device = {arch(gen)})                        \
        append_args(interop(prefer_type("sycl", "level_zero"), targetsync))    \
            adjust_args(need_device_ptr                                        \
                        : a) adjust_args(need_device_ptr                       \
                                         : b) adjust_args(need_device_ptr      \
                                                          : y)
#endif
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vmsfmax))                     \
    match(construct = {target variant dispatch}, device = {arch(gen)})
void vmsFmax(const MKL_INT n, const float* a, const float* b, float* y,
             MKL_INT64 mode) NOTHROW;

#if (_OPENMP >= 202011)
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vmsfmaxi))                    \
    match(construct = {dispatch}, device = {arch(gen)})                        \
        append_args(interop(prefer_type("sycl", "level_zero"), targetsync))    \
            adjust_args(need_device_ptr                                        \
                        : a) adjust_args(need_device_ptr                       \
                                         : b) adjust_args(need_device_ptr      \
                                                          : y)
#endif
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vmsfmaxi))                    \
    match(construct = {target variant dispatch}, device = {arch(gen)})
void vmsFmaxI(const MKL_INT n, const float* a, MKL_INT inca, const float* b,
              MKL_INT incb, float* y, MKL_INT incy, MKL_INT64 mode) NOTHROW;

#if (_OPENMP >= 202011)
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vdfmax))                      \
    match(construct = {dispatch}, device = {arch(gen)})                        \
        append_args(interop(prefer_type("sycl", "level_zero"), targetsync))    \
            adjust_args(need_device_ptr                                        \
                        : a) adjust_args(need_device_ptr                       \
                                         : b) adjust_args(need_device_ptr      \
                                                          : y)
#endif
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vdfmax))                      \
    match(construct = {target variant dispatch}, device = {arch(gen)})
void vdFmax(const MKL_INT n, const double* a, const double* b,
            double* y) NOTHROW;

#if (_OPENMP >= 202011)
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vdfmaxi))                     \
    match(construct = {dispatch}, device = {arch(gen)})                        \
        append_args(interop(prefer_type("sycl", "level_zero"), targetsync))    \
            adjust_args(need_device_ptr                                        \
                        : a) adjust_args(need_device_ptr                       \
                                         : b) adjust_args(need_device_ptr      \
                                                          : y)
#endif
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vdfmaxi))                     \
    match(construct = {target variant dispatch}, device = {arch(gen)})
void vdFmaxI(const MKL_INT n, const double* a, MKL_INT inca, const double* b,
             MKL_INT incb, double* y, MKL_INT incy) NOTHROW;

#if (_OPENMP >= 202011)
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vmdfmax))                     \
    match(construct = {dispatch}, device = {arch(gen)})                        \
        append_args(interop(prefer_type("sycl", "level_zero"), targetsync))    \
            adjust_args(need_device_ptr                                        \
                        : a) adjust_args(need_device_ptr                       \
                                         : b) adjust_args(need_device_ptr      \
                                                          : y)
#endif
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vmdfmax))                     \
    match(construct = {target variant dispatch}, device = {arch(gen)})
void vmdFmax(const MKL_INT n, const double* a, const double* b, double* y,
             MKL_INT64 mode) NOTHROW;

#if (_OPENMP >= 202011)
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vmdfmaxi))                    \
    match(construct = {dispatch}, device = {arch(gen)})                        \
        append_args(interop(prefer_type("sycl", "level_zero"), targetsync))    \
            adjust_args(need_device_ptr                                        \
                        : a) adjust_args(need_device_ptr                       \
                                         : b) adjust_args(need_device_ptr      \
                                                          : y)
#endif
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vmdfmaxi))                    \
    match(construct = {target variant dispatch}, device = {arch(gen)})
void vmdFmaxI(const MKL_INT n, const double* a, MKL_INT inca, const double* b,
              MKL_INT incb, double* y, MKL_INT incy, MKL_INT64 mode) NOTHROW;

// function fmin
#if (_OPENMP >= 202011)
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vsfmin))                      \
    match(construct = {dispatch}, device = {arch(gen)})                        \
        append_args(interop(prefer_type("sycl", "level_zero"), targetsync))    \
            adjust_args(need_device_ptr                                        \
                        : a) adjust_args(need_device_ptr                       \
                                         : b) adjust_args(need_device_ptr      \
                                                          : y)
#endif
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vsfmin))                      \
    match(construct = {target variant dispatch}, device = {arch(gen)})
void vsFmin(const MKL_INT n, const float* a, const float* b, float* y) NOTHROW;

#if (_OPENMP >= 202011)
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vsfmini))                     \
    match(construct = {dispatch}, device = {arch(gen)})                        \
        append_args(interop(prefer_type("sycl", "level_zero"), targetsync))    \
            adjust_args(need_device_ptr                                        \
                        : a) adjust_args(need_device_ptr                       \
                                         : b) adjust_args(need_device_ptr      \
                                                          : y)
#endif
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vsfmini))                     \
    match(construct = {target variant dispatch}, device = {arch(gen)})
void vsFminI(const MKL_INT n, const float* a, MKL_INT inca, const float* b,
             MKL_INT incb, float* y, MKL_INT incy) NOTHROW;

#if (_OPENMP >= 202011)
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vmsfmin))                     \
    match(construct = {dispatch}, device = {arch(gen)})                        \
        append_args(interop(prefer_type("sycl", "level_zero"), targetsync))    \
            adjust_args(need_device_ptr                                        \
                        : a) adjust_args(need_device_ptr                       \
                                         : b) adjust_args(need_device_ptr      \
                                                          : y)
#endif
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vmsfmin))                     \
    match(construct = {target variant dispatch}, device = {arch(gen)})
void vmsFmin(const MKL_INT n, const float* a, const float* b, float* y,
             MKL_INT64 mode) NOTHROW;

#if (_OPENMP >= 202011)
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vmsfmini))                    \
    match(construct = {dispatch}, device = {arch(gen)})                        \
        append_args(interop(prefer_type("sycl", "level_zero"), targetsync))    \
            adjust_args(need_device_ptr                                        \
                        : a) adjust_args(need_device_ptr                       \
                                         : b) adjust_args(need_device_ptr      \
                                                          : y)
#endif
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vmsfmini))                    \
    match(construct = {target variant dispatch}, device = {arch(gen)})
void vmsFminI(const MKL_INT n, const float* a, MKL_INT inca, const float* b,
              MKL_INT incb, float* y, MKL_INT incy, MKL_INT64 mode) NOTHROW;

#if (_OPENMP >= 202011)
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vdfmin))                      \
    match(construct = {dispatch}, device = {arch(gen)})                        \
        append_args(interop(prefer_type("sycl", "level_zero"), targetsync))    \
            adjust_args(need_device_ptr                                        \
                        : a) adjust_args(need_device_ptr                       \
                                         : b) adjust_args(need_device_ptr      \
                                                          : y)
#endif
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vdfmin))                      \
    match(construct = {target variant dispatch}, device = {arch(gen)})
void vdFmin(const MKL_INT n, const double* a, const double* b,
            double* y) NOTHROW;

#if (_OPENMP >= 202011)
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vdfmini))                     \
    match(construct = {dispatch}, device = {arch(gen)})                        \
        append_args(interop(prefer_type("sycl", "level_zero"), targetsync))    \
            adjust_args(need_device_ptr                                        \
                        : a) adjust_args(need_device_ptr                       \
                                         : b) adjust_args(need_device_ptr      \
                                                          : y)
#endif
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vdfmini))                     \
    match(construct = {target variant dispatch}, device = {arch(gen)})
void vdFminI(const MKL_INT n, const double* a, MKL_INT inca, const double* b,
             MKL_INT incb, double* y, MKL_INT incy) NOTHROW;

#if (_OPENMP >= 202011)
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vmdfmin))                     \
    match(construct = {dispatch}, device = {arch(gen)})                        \
        append_args(interop(prefer_type("sycl", "level_zero"), targetsync))    \
            adjust_args(need_device_ptr                                        \
                        : a) adjust_args(need_device_ptr                       \
                                         : b) adjust_args(need_device_ptr      \
                                                          : y)
#endif
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vmdfmin))                     \
    match(construct = {target variant dispatch}, device = {arch(gen)})
void vmdFmin(const MKL_INT n, const double* a, const double* b, double* y,
             MKL_INT64 mode) NOTHROW;

#if (_OPENMP >= 202011)
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vmdfmini))                    \
    match(construct = {dispatch}, device = {arch(gen)})                        \
        append_args(interop(prefer_type("sycl", "level_zero"), targetsync))    \
            adjust_args(need_device_ptr                                        \
                        : a) adjust_args(need_device_ptr                       \
                                         : b) adjust_args(need_device_ptr      \
                                                          : y)
#endif
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vmdfmini))                    \
    match(construct = {target variant dispatch}, device = {arch(gen)})
void vmdFminI(const MKL_INT n, const double* a, MKL_INT inca, const double* b,
              MKL_INT incb, double* y, MKL_INT incy, MKL_INT64 mode) NOTHROW;

// function fmod
#if (_OPENMP >= 202011)
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vsfmod))                      \
    match(construct = {dispatch}, device = {arch(gen)})                        \
        append_args(interop(prefer_type("sycl", "level_zero"), targetsync))    \
            adjust_args(need_device_ptr                                        \
                        : a) adjust_args(need_device_ptr                       \
                                         : b) adjust_args(need_device_ptr      \
                                                          : y)
#endif
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vsfmod))                      \
    match(construct = {target variant dispatch}, device = {arch(gen)})
void vsFmod(const MKL_INT n, const float* a, const float* b, float* y) NOTHROW;

#if (_OPENMP >= 202011)
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vsfmodi))                     \
    match(construct = {dispatch}, device = {arch(gen)})                        \
        append_args(interop(prefer_type("sycl", "level_zero"), targetsync))    \
            adjust_args(need_device_ptr                                        \
                        : a) adjust_args(need_device_ptr                       \
                                         : b) adjust_args(need_device_ptr      \
                                                          : y)
#endif
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vsfmodi))                     \
    match(construct = {target variant dispatch}, device = {arch(gen)})
void vsFmodI(const MKL_INT n, const float* a, MKL_INT inca, const float* b,
             MKL_INT incb, float* y, MKL_INT incy) NOTHROW;

#if (_OPENMP >= 202011)
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vmsfmod))                     \
    match(construct = {dispatch}, device = {arch(gen)})                        \
        append_args(interop(prefer_type("sycl", "level_zero"), targetsync))    \
            adjust_args(need_device_ptr                                        \
                        : a) adjust_args(need_device_ptr                       \
                                         : b) adjust_args(need_device_ptr      \
                                                          : y)
#endif
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vmsfmod))                     \
    match(construct = {target variant dispatch}, device = {arch(gen)})
void vmsFmod(const MKL_INT n, const float* a, const float* b, float* y,
             MKL_INT64 mode) NOTHROW;

#if (_OPENMP >= 202011)
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vmsfmodi))                    \
    match(construct = {dispatch}, device = {arch(gen)})                        \
        append_args(interop(prefer_type("sycl", "level_zero"), targetsync))    \
            adjust_args(need_device_ptr                                        \
                        : a) adjust_args(need_device_ptr                       \
                                         : b) adjust_args(need_device_ptr      \
                                                          : y)
#endif
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vmsfmodi))                    \
    match(construct = {target variant dispatch}, device = {arch(gen)})
void vmsFmodI(const MKL_INT n, const float* a, MKL_INT inca, const float* b,
              MKL_INT incb, float* y, MKL_INT incy, MKL_INT64 mode) NOTHROW;

#if (_OPENMP >= 202011)
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vdfmod))                      \
    match(construct = {dispatch}, device = {arch(gen)})                        \
        append_args(interop(prefer_type("sycl", "level_zero"), targetsync))    \
            adjust_args(need_device_ptr                                        \
                        : a) adjust_args(need_device_ptr                       \
                                         : b) adjust_args(need_device_ptr      \
                                                          : y)
#endif
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vdfmod))                      \
    match(construct = {target variant dispatch}, device = {arch(gen)})
void vdFmod(const MKL_INT n, const double* a, const double* b,
            double* y) NOTHROW;

#if (_OPENMP >= 202011)
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vdfmodi))                     \
    match(construct = {dispatch}, device = {arch(gen)})                        \
        append_args(interop(prefer_type("sycl", "level_zero"), targetsync))    \
            adjust_args(need_device_ptr                                        \
                        : a) adjust_args(need_device_ptr                       \
                                         : b) adjust_args(need_device_ptr      \
                                                          : y)
#endif
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vdfmodi))                     \
    match(construct = {target variant dispatch}, device = {arch(gen)})
void vdFmodI(const MKL_INT n, const double* a, MKL_INT inca, const double* b,
             MKL_INT incb, double* y, MKL_INT incy) NOTHROW;

#if (_OPENMP >= 202011)
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vmdfmod))                     \
    match(construct = {dispatch}, device = {arch(gen)})                        \
        append_args(interop(prefer_type("sycl", "level_zero"), targetsync))    \
            adjust_args(need_device_ptr                                        \
                        : a) adjust_args(need_device_ptr                       \
                                         : b) adjust_args(need_device_ptr      \
                                                          : y)
#endif
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vmdfmod))                     \
    match(construct = {target variant dispatch}, device = {arch(gen)})
void vmdFmod(const MKL_INT n, const double* a, const double* b, double* y,
             MKL_INT64 mode) NOTHROW;

#if (_OPENMP >= 202011)
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vmdfmodi))                    \
    match(construct = {dispatch}, device = {arch(gen)})                        \
        append_args(interop(prefer_type("sycl", "level_zero"), targetsync))    \
            adjust_args(need_device_ptr                                        \
                        : a) adjust_args(need_device_ptr                       \
                                         : b) adjust_args(need_device_ptr      \
                                                          : y)
#endif
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vmdfmodi))                    \
    match(construct = {target variant dispatch}, device = {arch(gen)})
void vmdFmodI(const MKL_INT n, const double* a, MKL_INT inca, const double* b,
              MKL_INT incb, double* y, MKL_INT incy, MKL_INT64 mode) NOTHROW;

// function frac
#if (_OPENMP >= 202011)
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vsfrac))                      \
    match(construct = {dispatch}, device = {arch(gen)})                        \
        append_args(interop(prefer_type("sycl", "level_zero"), targetsync))    \
            adjust_args(need_device_ptr                                        \
                        : a) adjust_args(need_device_ptr                       \
                                         : y)
#endif
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vsfrac))                      \
    match(construct = {target variant dispatch}, device = {arch(gen)})
void vsFrac(const MKL_INT n, const float* a, float* y) NOTHROW;

#if (_OPENMP >= 202011)
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vsfraci))                     \
    match(construct = {dispatch}, device = {arch(gen)})                        \
        append_args(interop(prefer_type("sycl", "level_zero"), targetsync))    \
            adjust_args(need_device_ptr                                        \
                        : a) adjust_args(need_device_ptr                       \
                                         : y)
#endif
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vsfraci))                     \
    match(construct = {target variant dispatch}, device = {arch(gen)})
void vsFracI(const MKL_INT n, const float* a, MKL_INT inca, float* y,
             MKL_INT incy) NOTHROW;

#if (_OPENMP >= 202011)
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vmsfrac))                     \
    match(construct = {dispatch}, device = {arch(gen)})                        \
        append_args(interop(prefer_type("sycl", "level_zero"), targetsync))    \
            adjust_args(need_device_ptr                                        \
                        : a) adjust_args(need_device_ptr                       \
                                         : y)
#endif
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vmsfrac))                     \
    match(construct = {target variant dispatch}, device = {arch(gen)})
void vmsFrac(const MKL_INT n, const float* a, float* y, MKL_INT64 mode) NOTHROW;

#if (_OPENMP >= 202011)
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vmsfraci))                    \
    match(construct = {dispatch}, device = {arch(gen)})                        \
        append_args(interop(prefer_type("sycl", "level_zero"), targetsync))    \
            adjust_args(need_device_ptr                                        \
                        : a) adjust_args(need_device_ptr                       \
                                         : y)
#endif
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vmsfraci))                    \
    match(construct = {target variant dispatch}, device = {arch(gen)})
void vmsFracI(const MKL_INT n, const float* a, MKL_INT inca, float* y,
              MKL_INT incy, MKL_INT64 mode) NOTHROW;

#if (_OPENMP >= 202011)
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vdfrac))                      \
    match(construct = {dispatch}, device = {arch(gen)})                        \
        append_args(interop(prefer_type("sycl", "level_zero"), targetsync))    \
            adjust_args(need_device_ptr                                        \
                        : a) adjust_args(need_device_ptr                       \
                                         : y)
#endif
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vdfrac))                      \
    match(construct = {target variant dispatch}, device = {arch(gen)})
void vdFrac(const MKL_INT n, const double* a, double* y) NOTHROW;

#if (_OPENMP >= 202011)
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vdfraci))                     \
    match(construct = {dispatch}, device = {arch(gen)})                        \
        append_args(interop(prefer_type("sycl", "level_zero"), targetsync))    \
            adjust_args(need_device_ptr                                        \
                        : a) adjust_args(need_device_ptr                       \
                                         : y)
#endif
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vdfraci))                     \
    match(construct = {target variant dispatch}, device = {arch(gen)})
void vdFracI(const MKL_INT n, const double* a, MKL_INT inca, double* y,
             MKL_INT incy) NOTHROW;

#if (_OPENMP >= 202011)
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vmdfrac))                     \
    match(construct = {dispatch}, device = {arch(gen)})                        \
        append_args(interop(prefer_type("sycl", "level_zero"), targetsync))    \
            adjust_args(need_device_ptr                                        \
                        : a) adjust_args(need_device_ptr                       \
                                         : y)
#endif
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vmdfrac))                     \
    match(construct = {target variant dispatch}, device = {arch(gen)})
void vmdFrac(const MKL_INT n, const double* a, double* y,
             MKL_INT64 mode) NOTHROW;

#if (_OPENMP >= 202011)
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vmdfraci))                    \
    match(construct = {dispatch}, device = {arch(gen)})                        \
        append_args(interop(prefer_type("sycl", "level_zero"), targetsync))    \
            adjust_args(need_device_ptr                                        \
                        : a) adjust_args(need_device_ptr                       \
                                         : y)
#endif
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vmdfraci))                    \
    match(construct = {target variant dispatch}, device = {arch(gen)})
void vmdFracI(const MKL_INT n, const double* a, MKL_INT inca, double* y,
              MKL_INT incy, MKL_INT64 mode) NOTHROW;

// function hypot
#if (_OPENMP >= 202011)
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vshypot))                     \
    match(construct = {dispatch}, device = {arch(gen)})                        \
        append_args(interop(prefer_type("sycl", "level_zero"), targetsync))    \
            adjust_args(need_device_ptr                                        \
                        : a) adjust_args(need_device_ptr                       \
                                         : b) adjust_args(need_device_ptr      \
                                                          : y)
#endif
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vshypot))                     \
    match(construct = {target variant dispatch}, device = {arch(gen)})
void vsHypot(const MKL_INT n, const float* a, const float* b, float* y) NOTHROW;

#if (_OPENMP >= 202011)
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vshypoti))                    \
    match(construct = {dispatch}, device = {arch(gen)})                        \
        append_args(interop(prefer_type("sycl", "level_zero"), targetsync))    \
            adjust_args(need_device_ptr                                        \
                        : a) adjust_args(need_device_ptr                       \
                                         : b) adjust_args(need_device_ptr      \
                                                          : y)
#endif
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vshypoti))                    \
    match(construct = {target variant dispatch}, device = {arch(gen)})
void vsHypotI(const MKL_INT n, const float* a, MKL_INT inca, const float* b,
              MKL_INT incb, float* y, MKL_INT incy) NOTHROW;

#if (_OPENMP >= 202011)
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vmshypot))                    \
    match(construct = {dispatch}, device = {arch(gen)})                        \
        append_args(interop(prefer_type("sycl", "level_zero"), targetsync))    \
            adjust_args(need_device_ptr                                        \
                        : a) adjust_args(need_device_ptr                       \
                                         : b) adjust_args(need_device_ptr      \
                                                          : y)
#endif
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vmshypot))                    \
    match(construct = {target variant dispatch}, device = {arch(gen)})
void vmsHypot(const MKL_INT n, const float* a, const float* b, float* y,
              MKL_INT64 mode) NOTHROW;

#if (_OPENMP >= 202011)
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vmshypoti))                   \
    match(construct = {dispatch}, device = {arch(gen)})                        \
        append_args(interop(prefer_type("sycl", "level_zero"), targetsync))    \
            adjust_args(need_device_ptr                                        \
                        : a) adjust_args(need_device_ptr                       \
                                         : b) adjust_args(need_device_ptr      \
                                                          : y)
#endif
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vmshypoti))                   \
    match(construct = {target variant dispatch}, device = {arch(gen)})
void vmsHypotI(const MKL_INT n, const float* a, MKL_INT inca, const float* b,
               MKL_INT incb, float* y, MKL_INT incy, MKL_INT64 mode) NOTHROW;

#if (_OPENMP >= 202011)
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vdhypot))                     \
    match(construct = {dispatch}, device = {arch(gen)})                        \
        append_args(interop(prefer_type("sycl", "level_zero"), targetsync))    \
            adjust_args(need_device_ptr                                        \
                        : a) adjust_args(need_device_ptr                       \
                                         : b) adjust_args(need_device_ptr      \
                                                          : y)
#endif
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vdhypot))                     \
    match(construct = {target variant dispatch}, device = {arch(gen)})
void vdHypot(const MKL_INT n, const double* a, const double* b,
             double* y) NOTHROW;

#if (_OPENMP >= 202011)
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vdhypoti))                    \
    match(construct = {dispatch}, device = {arch(gen)})                        \
        append_args(interop(prefer_type("sycl", "level_zero"), targetsync))    \
            adjust_args(need_device_ptr                                        \
                        : a) adjust_args(need_device_ptr                       \
                                         : b) adjust_args(need_device_ptr      \
                                                          : y)
#endif
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vdhypoti))                    \
    match(construct = {target variant dispatch}, device = {arch(gen)})
void vdHypotI(const MKL_INT n, const double* a, MKL_INT inca, const double* b,
              MKL_INT incb, double* y, MKL_INT incy) NOTHROW;

#if (_OPENMP >= 202011)
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vmdhypot))                    \
    match(construct = {dispatch}, device = {arch(gen)})                        \
        append_args(interop(prefer_type("sycl", "level_zero"), targetsync))    \
            adjust_args(need_device_ptr                                        \
                        : a) adjust_args(need_device_ptr                       \
                                         : b) adjust_args(need_device_ptr      \
                                                          : y)
#endif
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vmdhypot))                    \
    match(construct = {target variant dispatch}, device = {arch(gen)})
void vmdHypot(const MKL_INT n, const double* a, const double* b, double* y,
              MKL_INT64 mode) NOTHROW;

#if (_OPENMP >= 202011)
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vmdhypoti))                   \
    match(construct = {dispatch}, device = {arch(gen)})                        \
        append_args(interop(prefer_type("sycl", "level_zero"), targetsync))    \
            adjust_args(need_device_ptr                                        \
                        : a) adjust_args(need_device_ptr                       \
                                         : b) adjust_args(need_device_ptr      \
                                                          : y)
#endif
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vmdhypoti))                   \
    match(construct = {target variant dispatch}, device = {arch(gen)})
void vmdHypotI(const MKL_INT n, const double* a, MKL_INT inca, const double* b,
               MKL_INT incb, double* y, MKL_INT incy, MKL_INT64 mode) NOTHROW;

// function i0
#if (_OPENMP >= 202011)
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vsi0))                        \
    match(construct = {dispatch}, device = {arch(gen)})                        \
        append_args(interop(prefer_type("sycl", "level_zero"), targetsync))    \
            adjust_args(need_device_ptr                                        \
                        : a) adjust_args(need_device_ptr                       \
                                         : y)
#endif
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vsi0))                        \
    match(construct = {target variant dispatch}, device = {arch(gen)})
void vsI0(const MKL_INT n, const float* a, float* y) NOTHROW;

#if (_OPENMP >= 202011)
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vsi0i))                       \
    match(construct = {dispatch}, device = {arch(gen)})                        \
        append_args(interop(prefer_type("sycl", "level_zero"), targetsync))    \
            adjust_args(need_device_ptr                                        \
                        : a) adjust_args(need_device_ptr                       \
                                         : y)
#endif
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vsi0i))                       \
    match(construct = {target variant dispatch}, device = {arch(gen)})
void vsI0I(const MKL_INT n, const float* a, MKL_INT inca, float* y,
           MKL_INT incy) NOTHROW;

#if (_OPENMP >= 202011)
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vmsi0))                       \
    match(construct = {dispatch}, device = {arch(gen)})                        \
        append_args(interop(prefer_type("sycl", "level_zero"), targetsync))    \
            adjust_args(need_device_ptr                                        \
                        : a) adjust_args(need_device_ptr                       \
                                         : y)
#endif
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vmsi0))                       \
    match(construct = {target variant dispatch}, device = {arch(gen)})
void vmsI0(const MKL_INT n, const float* a, float* y, MKL_INT64 mode) NOTHROW;

#if (_OPENMP >= 202011)
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vmsi0i))                      \
    match(construct = {dispatch}, device = {arch(gen)})                        \
        append_args(interop(prefer_type("sycl", "level_zero"), targetsync))    \
            adjust_args(need_device_ptr                                        \
                        : a) adjust_args(need_device_ptr                       \
                                         : y)
#endif
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vmsi0i))                      \
    match(construct = {target variant dispatch}, device = {arch(gen)})
void vmsI0I(const MKL_INT n, const float* a, MKL_INT inca, float* y,
            MKL_INT incy, MKL_INT64 mode) NOTHROW;

#if (_OPENMP >= 202011)
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vdi0))                        \
    match(construct = {dispatch}, device = {arch(gen)})                        \
        append_args(interop(prefer_type("sycl", "level_zero"), targetsync))    \
            adjust_args(need_device_ptr                                        \
                        : a) adjust_args(need_device_ptr                       \
                                         : y)
#endif
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vdi0))                        \
    match(construct = {target variant dispatch}, device = {arch(gen)})
void vdI0(const MKL_INT n, const double* a, double* y) NOTHROW;

#if (_OPENMP >= 202011)
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vdi0i))                       \
    match(construct = {dispatch}, device = {arch(gen)})                        \
        append_args(interop(prefer_type("sycl", "level_zero"), targetsync))    \
            adjust_args(need_device_ptr                                        \
                        : a) adjust_args(need_device_ptr                       \
                                         : y)
#endif
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vdi0i))                       \
    match(construct = {target variant dispatch}, device = {arch(gen)})
void vdI0I(const MKL_INT n, const double* a, MKL_INT inca, double* y,
           MKL_INT incy) NOTHROW;

#if (_OPENMP >= 202011)
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vmdi0))                       \
    match(construct = {dispatch}, device = {arch(gen)})                        \
        append_args(interop(prefer_type("sycl", "level_zero"), targetsync))    \
            adjust_args(need_device_ptr                                        \
                        : a) adjust_args(need_device_ptr                       \
                                         : y)
#endif
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vmdi0))                       \
    match(construct = {target variant dispatch}, device = {arch(gen)})
void vmdI0(const MKL_INT n, const double* a, double* y, MKL_INT64 mode) NOTHROW;

#if (_OPENMP >= 202011)
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vmdi0i))                      \
    match(construct = {dispatch}, device = {arch(gen)})                        \
        append_args(interop(prefer_type("sycl", "level_zero"), targetsync))    \
            adjust_args(need_device_ptr                                        \
                        : a) adjust_args(need_device_ptr                       \
                                         : y)
#endif
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vmdi0i))                      \
    match(construct = {target variant dispatch}, device = {arch(gen)})
void vmdI0I(const MKL_INT n, const double* a, MKL_INT inca, double* y,
            MKL_INT incy, MKL_INT64 mode) NOTHROW;

// function i1
#if (_OPENMP >= 202011)
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vsi1))                        \
    match(construct = {dispatch}, device = {arch(gen)})                        \
        append_args(interop(prefer_type("sycl", "level_zero"), targetsync))    \
            adjust_args(need_device_ptr                                        \
                        : a) adjust_args(need_device_ptr                       \
                                         : y)
#endif
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vsi1))                        \
    match(construct = {target variant dispatch}, device = {arch(gen)})
void vsI1(const MKL_INT n, const float* a, float* y) NOTHROW;

#if (_OPENMP >= 202011)
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vsi1i))                       \
    match(construct = {dispatch}, device = {arch(gen)})                        \
        append_args(interop(prefer_type("sycl", "level_zero"), targetsync))    \
            adjust_args(need_device_ptr                                        \
                        : a) adjust_args(need_device_ptr                       \
                                         : y)
#endif
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vsi1i))                       \
    match(construct = {target variant dispatch}, device = {arch(gen)})
void vsI1I(const MKL_INT n, const float* a, MKL_INT inca, float* y,
           MKL_INT incy) NOTHROW;

#if (_OPENMP >= 202011)
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vmsi1))                       \
    match(construct = {dispatch}, device = {arch(gen)})                        \
        append_args(interop(prefer_type("sycl", "level_zero"), targetsync))    \
            adjust_args(need_device_ptr                                        \
                        : a) adjust_args(need_device_ptr                       \
                                         : y)
#endif
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vmsi1))                       \
    match(construct = {target variant dispatch}, device = {arch(gen)})
void vmsI1(const MKL_INT n, const float* a, float* y, MKL_INT64 mode) NOTHROW;

#if (_OPENMP >= 202011)
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vmsi1i))                      \
    match(construct = {dispatch}, device = {arch(gen)})                        \
        append_args(interop(prefer_type("sycl", "level_zero"), targetsync))    \
            adjust_args(need_device_ptr                                        \
                        : a) adjust_args(need_device_ptr                       \
                                         : y)
#endif
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vmsi1i))                      \
    match(construct = {target variant dispatch}, device = {arch(gen)})
void vmsI1I(const MKL_INT n, const float* a, MKL_INT inca, float* y,
            MKL_INT incy, MKL_INT64 mode) NOTHROW;

#if (_OPENMP >= 202011)
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vdi1))                        \
    match(construct = {dispatch}, device = {arch(gen)})                        \
        append_args(interop(prefer_type("sycl", "level_zero"), targetsync))    \
            adjust_args(need_device_ptr                                        \
                        : a) adjust_args(need_device_ptr                       \
                                         : y)
#endif
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vdi1))                        \
    match(construct = {target variant dispatch}, device = {arch(gen)})
void vdI1(const MKL_INT n, const double* a, double* y) NOTHROW;

#if (_OPENMP >= 202011)
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vdi1i))                       \
    match(construct = {dispatch}, device = {arch(gen)})                        \
        append_args(interop(prefer_type("sycl", "level_zero"), targetsync))    \
            adjust_args(need_device_ptr                                        \
                        : a) adjust_args(need_device_ptr                       \
                                         : y)
#endif
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vdi1i))                       \
    match(construct = {target variant dispatch}, device = {arch(gen)})
void vdI1I(const MKL_INT n, const double* a, MKL_INT inca, double* y,
           MKL_INT incy) NOTHROW;

#if (_OPENMP >= 202011)
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vmdi1))                       \
    match(construct = {dispatch}, device = {arch(gen)})                        \
        append_args(interop(prefer_type("sycl", "level_zero"), targetsync))    \
            adjust_args(need_device_ptr                                        \
                        : a) adjust_args(need_device_ptr                       \
                                         : y)
#endif
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vmdi1))                       \
    match(construct = {target variant dispatch}, device = {arch(gen)})
void vmdI1(const MKL_INT n, const double* a, double* y, MKL_INT64 mode) NOTHROW;

#if (_OPENMP >= 202011)
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vmdi1i))                      \
    match(construct = {dispatch}, device = {arch(gen)})                        \
        append_args(interop(prefer_type("sycl", "level_zero"), targetsync))    \
            adjust_args(need_device_ptr                                        \
                        : a) adjust_args(need_device_ptr                       \
                                         : y)
#endif
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vmdi1i))                      \
    match(construct = {target variant dispatch}, device = {arch(gen)})
void vmdI1I(const MKL_INT n, const double* a, MKL_INT inca, double* y,
            MKL_INT incy, MKL_INT64 mode) NOTHROW;

// function inv
#if (_OPENMP >= 202011)
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vsinv))                       \
    match(construct = {dispatch}, device = {arch(gen)})                        \
        append_args(interop(prefer_type("sycl", "level_zero"), targetsync))    \
            adjust_args(need_device_ptr                                        \
                        : a) adjust_args(need_device_ptr                       \
                                         : y)
#endif
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vsinv))                       \
    match(construct = {target variant dispatch}, device = {arch(gen)})
void vsInv(const MKL_INT n, const float* a, float* y) NOTHROW;

#if (_OPENMP >= 202011)
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vsinvi))                      \
    match(construct = {dispatch}, device = {arch(gen)})                        \
        append_args(interop(prefer_type("sycl", "level_zero"), targetsync))    \
            adjust_args(need_device_ptr                                        \
                        : a) adjust_args(need_device_ptr                       \
                                         : y)
#endif
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vsinvi))                      \
    match(construct = {target variant dispatch}, device = {arch(gen)})
void vsInvI(const MKL_INT n, const float* a, MKL_INT inca, float* y,
            MKL_INT incy) NOTHROW;

#if (_OPENMP >= 202011)
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vmsinv))                      \
    match(construct = {dispatch}, device = {arch(gen)})                        \
        append_args(interop(prefer_type("sycl", "level_zero"), targetsync))    \
            adjust_args(need_device_ptr                                        \
                        : a) adjust_args(need_device_ptr                       \
                                         : y)
#endif
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vmsinv))                      \
    match(construct = {target variant dispatch}, device = {arch(gen)})
void vmsInv(const MKL_INT n, const float* a, float* y, MKL_INT64 mode) NOTHROW;

#if (_OPENMP >= 202011)
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vmsinvi))                     \
    match(construct = {dispatch}, device = {arch(gen)})                        \
        append_args(interop(prefer_type("sycl", "level_zero"), targetsync))    \
            adjust_args(need_device_ptr                                        \
                        : a) adjust_args(need_device_ptr                       \
                                         : y)
#endif
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vmsinvi))                     \
    match(construct = {target variant dispatch}, device = {arch(gen)})
void vmsInvI(const MKL_INT n, const float* a, MKL_INT inca, float* y,
             MKL_INT incy, MKL_INT64 mode) NOTHROW;

#if (_OPENMP >= 202011)
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vdinv))                       \
    match(construct = {dispatch}, device = {arch(gen)})                        \
        append_args(interop(prefer_type("sycl", "level_zero"), targetsync))    \
            adjust_args(need_device_ptr                                        \
                        : a) adjust_args(need_device_ptr                       \
                                         : y)
#endif
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vdinv))                       \
    match(construct = {target variant dispatch}, device = {arch(gen)})
void vdInv(const MKL_INT n, const double* a, double* y) NOTHROW;

#if (_OPENMP >= 202011)
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vdinvi))                      \
    match(construct = {dispatch}, device = {arch(gen)})                        \
        append_args(interop(prefer_type("sycl", "level_zero"), targetsync))    \
            adjust_args(need_device_ptr                                        \
                        : a) adjust_args(need_device_ptr                       \
                                         : y)
#endif
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vdinvi))                      \
    match(construct = {target variant dispatch}, device = {arch(gen)})
void vdInvI(const MKL_INT n, const double* a, MKL_INT inca, double* y,
            MKL_INT incy) NOTHROW;

#if (_OPENMP >= 202011)
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vmdinv))                      \
    match(construct = {dispatch}, device = {arch(gen)})                        \
        append_args(interop(prefer_type("sycl", "level_zero"), targetsync))    \
            adjust_args(need_device_ptr                                        \
                        : a) adjust_args(need_device_ptr                       \
                                         : y)
#endif
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vmdinv))                      \
    match(construct = {target variant dispatch}, device = {arch(gen)})
void vmdInv(const MKL_INT n, const double* a, double* y,
            MKL_INT64 mode) NOTHROW;

#if (_OPENMP >= 202011)
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vmdinvi))                     \
    match(construct = {dispatch}, device = {arch(gen)})                        \
        append_args(interop(prefer_type("sycl", "level_zero"), targetsync))    \
            adjust_args(need_device_ptr                                        \
                        : a) adjust_args(need_device_ptr                       \
                                         : y)
#endif
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vmdinvi))                     \
    match(construct = {target variant dispatch}, device = {arch(gen)})
void vmdInvI(const MKL_INT n, const double* a, MKL_INT inca, double* y,
             MKL_INT incy, MKL_INT64 mode) NOTHROW;

// function invcbrt
#if (_OPENMP >= 202011)
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vsinvcbrt))                   \
    match(construct = {dispatch}, device = {arch(gen)})                        \
        append_args(interop(prefer_type("sycl", "level_zero"), targetsync))    \
            adjust_args(need_device_ptr                                        \
                        : a) adjust_args(need_device_ptr                       \
                                         : y)
#endif
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vsinvcbrt))                   \
    match(construct = {target variant dispatch}, device = {arch(gen)})
void vsInvCbrt(const MKL_INT n, const float* a, float* y) NOTHROW;

#if (_OPENMP >= 202011)
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vsinvcbrti))                  \
    match(construct = {dispatch}, device = {arch(gen)})                        \
        append_args(interop(prefer_type("sycl", "level_zero"), targetsync))    \
            adjust_args(need_device_ptr                                        \
                        : a) adjust_args(need_device_ptr                       \
                                         : y)
#endif
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vsinvcbrti))                  \
    match(construct = {target variant dispatch}, device = {arch(gen)})
void vsInvCbrtI(const MKL_INT n, const float* a, MKL_INT inca, float* y,
                MKL_INT incy) NOTHROW;

#if (_OPENMP >= 202011)
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vmsinvcbrt))                  \
    match(construct = {dispatch}, device = {arch(gen)})                        \
        append_args(interop(prefer_type("sycl", "level_zero"), targetsync))    \
            adjust_args(need_device_ptr                                        \
                        : a) adjust_args(need_device_ptr                       \
                                         : y)
#endif
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vmsinvcbrt))                  \
    match(construct = {target variant dispatch}, device = {arch(gen)})
void vmsInvCbrt(const MKL_INT n, const float* a, float* y,
                MKL_INT64 mode) NOTHROW;

#if (_OPENMP >= 202011)
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vmsinvcbrti))                 \
    match(construct = {dispatch}, device = {arch(gen)})                        \
        append_args(interop(prefer_type("sycl", "level_zero"), targetsync))    \
            adjust_args(need_device_ptr                                        \
                        : a) adjust_args(need_device_ptr                       \
                                         : y)
#endif
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vmsinvcbrti))                 \
    match(construct = {target variant dispatch}, device = {arch(gen)})
void vmsInvCbrtI(const MKL_INT n, const float* a, MKL_INT inca, float* y,
                 MKL_INT incy, MKL_INT64 mode) NOTHROW;

#if (_OPENMP >= 202011)
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vdinvcbrt))                   \
    match(construct = {dispatch}, device = {arch(gen)})                        \
        append_args(interop(prefer_type("sycl", "level_zero"), targetsync))    \
            adjust_args(need_device_ptr                                        \
                        : a) adjust_args(need_device_ptr                       \
                                         : y)
#endif
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vdinvcbrt))                   \
    match(construct = {target variant dispatch}, device = {arch(gen)})
void vdInvCbrt(const MKL_INT n, const double* a, double* y) NOTHROW;

#if (_OPENMP >= 202011)
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vdinvcbrti))                  \
    match(construct = {dispatch}, device = {arch(gen)})                        \
        append_args(interop(prefer_type("sycl", "level_zero"), targetsync))    \
            adjust_args(need_device_ptr                                        \
                        : a) adjust_args(need_device_ptr                       \
                                         : y)
#endif
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vdinvcbrti))                  \
    match(construct = {target variant dispatch}, device = {arch(gen)})
void vdInvCbrtI(const MKL_INT n, const double* a, MKL_INT inca, double* y,
                MKL_INT incy) NOTHROW;

#if (_OPENMP >= 202011)
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vmdinvcbrt))                  \
    match(construct = {dispatch}, device = {arch(gen)})                        \
        append_args(interop(prefer_type("sycl", "level_zero"), targetsync))    \
            adjust_args(need_device_ptr                                        \
                        : a) adjust_args(need_device_ptr                       \
                                         : y)
#endif
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vmdinvcbrt))                  \
    match(construct = {target variant dispatch}, device = {arch(gen)})
void vmdInvCbrt(const MKL_INT n, const double* a, double* y,
                MKL_INT64 mode) NOTHROW;

#if (_OPENMP >= 202011)
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vmdinvcbrti))                 \
    match(construct = {dispatch}, device = {arch(gen)})                        \
        append_args(interop(prefer_type("sycl", "level_zero"), targetsync))    \
            adjust_args(need_device_ptr                                        \
                        : a) adjust_args(need_device_ptr                       \
                                         : y)
#endif
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vmdinvcbrti))                 \
    match(construct = {target variant dispatch}, device = {arch(gen)})
void vmdInvCbrtI(const MKL_INT n, const double* a, MKL_INT inca, double* y,
                 MKL_INT incy, MKL_INT64 mode) NOTHROW;

// function invsqrt
#if (_OPENMP >= 202011)
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vsinvsqrt))                   \
    match(construct = {dispatch}, device = {arch(gen)})                        \
        append_args(interop(prefer_type("sycl", "level_zero"), targetsync))    \
            adjust_args(need_device_ptr                                        \
                        : a) adjust_args(need_device_ptr                       \
                                         : y)
#endif
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vsinvsqrt))                   \
    match(construct = {target variant dispatch}, device = {arch(gen)})
void vsInvSqrt(const MKL_INT n, const float* a, float* y) NOTHROW;

#if (_OPENMP >= 202011)
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vsinvsqrti))                  \
    match(construct = {dispatch}, device = {arch(gen)})                        \
        append_args(interop(prefer_type("sycl", "level_zero"), targetsync))    \
            adjust_args(need_device_ptr                                        \
                        : a) adjust_args(need_device_ptr                       \
                                         : y)
#endif
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vsinvsqrti))                  \
    match(construct = {target variant dispatch}, device = {arch(gen)})
void vsInvSqrtI(const MKL_INT n, const float* a, MKL_INT inca, float* y,
                MKL_INT incy) NOTHROW;

#if (_OPENMP >= 202011)
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vmsinvsqrt))                  \
    match(construct = {dispatch}, device = {arch(gen)})                        \
        append_args(interop(prefer_type("sycl", "level_zero"), targetsync))    \
            adjust_args(need_device_ptr                                        \
                        : a) adjust_args(need_device_ptr                       \
                                         : y)
#endif
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vmsinvsqrt))                  \
    match(construct = {target variant dispatch}, device = {arch(gen)})
void vmsInvSqrt(const MKL_INT n, const float* a, float* y,
                MKL_INT64 mode) NOTHROW;

#if (_OPENMP >= 202011)
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vmsinvsqrti))                 \
    match(construct = {dispatch}, device = {arch(gen)})                        \
        append_args(interop(prefer_type("sycl", "level_zero"), targetsync))    \
            adjust_args(need_device_ptr                                        \
                        : a) adjust_args(need_device_ptr                       \
                                         : y)
#endif
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vmsinvsqrti))                 \
    match(construct = {target variant dispatch}, device = {arch(gen)})
void vmsInvSqrtI(const MKL_INT n, const float* a, MKL_INT inca, float* y,
                 MKL_INT incy, MKL_INT64 mode) NOTHROW;

#if (_OPENMP >= 202011)
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vdinvsqrt))                   \
    match(construct = {dispatch}, device = {arch(gen)})                        \
        append_args(interop(prefer_type("sycl", "level_zero"), targetsync))    \
            adjust_args(need_device_ptr                                        \
                        : a) adjust_args(need_device_ptr                       \
                                         : y)
#endif
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vdinvsqrt))                   \
    match(construct = {target variant dispatch}, device = {arch(gen)})
void vdInvSqrt(const MKL_INT n, const double* a, double* y) NOTHROW;

#if (_OPENMP >= 202011)
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vdinvsqrti))                  \
    match(construct = {dispatch}, device = {arch(gen)})                        \
        append_args(interop(prefer_type("sycl", "level_zero"), targetsync))    \
            adjust_args(need_device_ptr                                        \
                        : a) adjust_args(need_device_ptr                       \
                                         : y)
#endif
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vdinvsqrti))                  \
    match(construct = {target variant dispatch}, device = {arch(gen)})
void vdInvSqrtI(const MKL_INT n, const double* a, MKL_INT inca, double* y,
                MKL_INT incy) NOTHROW;

#if (_OPENMP >= 202011)
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vmdinvsqrt))                  \
    match(construct = {dispatch}, device = {arch(gen)})                        \
        append_args(interop(prefer_type("sycl", "level_zero"), targetsync))    \
            adjust_args(need_device_ptr                                        \
                        : a) adjust_args(need_device_ptr                       \
                                         : y)
#endif
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vmdinvsqrt))                  \
    match(construct = {target variant dispatch}, device = {arch(gen)})
void vmdInvSqrt(const MKL_INT n, const double* a, double* y,
                MKL_INT64 mode) NOTHROW;

#if (_OPENMP >= 202011)
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vmdinvsqrti))                 \
    match(construct = {dispatch}, device = {arch(gen)})                        \
        append_args(interop(prefer_type("sycl", "level_zero"), targetsync))    \
            adjust_args(need_device_ptr                                        \
                        : a) adjust_args(need_device_ptr                       \
                                         : y)
#endif
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vmdinvsqrti))                 \
    match(construct = {target variant dispatch}, device = {arch(gen)})
void vmdInvSqrtI(const MKL_INT n, const double* a, MKL_INT inca, double* y,
                 MKL_INT incy, MKL_INT64 mode) NOTHROW;

// function j0
#if (_OPENMP >= 202011)
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vsj0))                        \
    match(construct = {dispatch}, device = {arch(gen)})                        \
        append_args(interop(prefer_type("sycl", "level_zero"), targetsync))    \
            adjust_args(need_device_ptr                                        \
                        : a) adjust_args(need_device_ptr                       \
                                         : y)
#endif
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vsj0))                        \
    match(construct = {target variant dispatch}, device = {arch(gen)})
void vsJ0(const MKL_INT n, const float* a, float* y) NOTHROW;

#if (_OPENMP >= 202011)
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vsj0i))                       \
    match(construct = {dispatch}, device = {arch(gen)})                        \
        append_args(interop(prefer_type("sycl", "level_zero"), targetsync))    \
            adjust_args(need_device_ptr                                        \
                        : a) adjust_args(need_device_ptr                       \
                                         : y)
#endif
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vsj0i))                       \
    match(construct = {target variant dispatch}, device = {arch(gen)})
void vsJ0I(const MKL_INT n, const float* a, MKL_INT inca, float* y,
           MKL_INT incy) NOTHROW;

#if (_OPENMP >= 202011)
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vmsj0))                       \
    match(construct = {dispatch}, device = {arch(gen)})                        \
        append_args(interop(prefer_type("sycl", "level_zero"), targetsync))    \
            adjust_args(need_device_ptr                                        \
                        : a) adjust_args(need_device_ptr                       \
                                         : y)
#endif
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vmsj0))                       \
    match(construct = {target variant dispatch}, device = {arch(gen)})
void vmsJ0(const MKL_INT n, const float* a, float* y, MKL_INT64 mode) NOTHROW;

#if (_OPENMP >= 202011)
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vmsj0i))                      \
    match(construct = {dispatch}, device = {arch(gen)})                        \
        append_args(interop(prefer_type("sycl", "level_zero"), targetsync))    \
            adjust_args(need_device_ptr                                        \
                        : a) adjust_args(need_device_ptr                       \
                                         : y)
#endif
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vmsj0i))                      \
    match(construct = {target variant dispatch}, device = {arch(gen)})
void vmsJ0I(const MKL_INT n, const float* a, MKL_INT inca, float* y,
            MKL_INT incy, MKL_INT64 mode) NOTHROW;

#if (_OPENMP >= 202011)
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vdj0))                        \
    match(construct = {dispatch}, device = {arch(gen)})                        \
        append_args(interop(prefer_type("sycl", "level_zero"), targetsync))    \
            adjust_args(need_device_ptr                                        \
                        : a) adjust_args(need_device_ptr                       \
                                         : y)
#endif
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vdj0))                        \
    match(construct = {target variant dispatch}, device = {arch(gen)})
void vdJ0(const MKL_INT n, const double* a, double* y) NOTHROW;

#if (_OPENMP >= 202011)
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vdj0i))                       \
    match(construct = {dispatch}, device = {arch(gen)})                        \
        append_args(interop(prefer_type("sycl", "level_zero"), targetsync))    \
            adjust_args(need_device_ptr                                        \
                        : a) adjust_args(need_device_ptr                       \
                                         : y)
#endif
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vdj0i))                       \
    match(construct = {target variant dispatch}, device = {arch(gen)})
void vdJ0I(const MKL_INT n, const double* a, MKL_INT inca, double* y,
           MKL_INT incy) NOTHROW;

#if (_OPENMP >= 202011)
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vmdj0))                       \
    match(construct = {dispatch}, device = {arch(gen)})                        \
        append_args(interop(prefer_type("sycl", "level_zero"), targetsync))    \
            adjust_args(need_device_ptr                                        \
                        : a) adjust_args(need_device_ptr                       \
                                         : y)
#endif
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vmdj0))                       \
    match(construct = {target variant dispatch}, device = {arch(gen)})
void vmdJ0(const MKL_INT n, const double* a, double* y, MKL_INT64 mode) NOTHROW;

#if (_OPENMP >= 202011)
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vmdj0i))                      \
    match(construct = {dispatch}, device = {arch(gen)})                        \
        append_args(interop(prefer_type("sycl", "level_zero"), targetsync))    \
            adjust_args(need_device_ptr                                        \
                        : a) adjust_args(need_device_ptr                       \
                                         : y)
#endif
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vmdj0i))                      \
    match(construct = {target variant dispatch}, device = {arch(gen)})
void vmdJ0I(const MKL_INT n, const double* a, MKL_INT inca, double* y,
            MKL_INT incy, MKL_INT64 mode) NOTHROW;

// function j1
#if (_OPENMP >= 202011)
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vsj1))                        \
    match(construct = {dispatch}, device = {arch(gen)})                        \
        append_args(interop(prefer_type("sycl", "level_zero"), targetsync))    \
            adjust_args(need_device_ptr                                        \
                        : a) adjust_args(need_device_ptr                       \
                                         : y)
#endif
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vsj1))                        \
    match(construct = {target variant dispatch}, device = {arch(gen)})
void vsJ1(const MKL_INT n, const float* a, float* y) NOTHROW;

#if (_OPENMP >= 202011)
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vsj1i))                       \
    match(construct = {dispatch}, device = {arch(gen)})                        \
        append_args(interop(prefer_type("sycl", "level_zero"), targetsync))    \
            adjust_args(need_device_ptr                                        \
                        : a) adjust_args(need_device_ptr                       \
                                         : y)
#endif
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vsj1i))                       \
    match(construct = {target variant dispatch}, device = {arch(gen)})
void vsJ1I(const MKL_INT n, const float* a, MKL_INT inca, float* y,
           MKL_INT incy) NOTHROW;

#if (_OPENMP >= 202011)
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vmsj1))                       \
    match(construct = {dispatch}, device = {arch(gen)})                        \
        append_args(interop(prefer_type("sycl", "level_zero"), targetsync))    \
            adjust_args(need_device_ptr                                        \
                        : a) adjust_args(need_device_ptr                       \
                                         : y)
#endif
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vmsj1))                       \
    match(construct = {target variant dispatch}, device = {arch(gen)})
void vmsJ1(const MKL_INT n, const float* a, float* y, MKL_INT64 mode) NOTHROW;

#if (_OPENMP >= 202011)
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vmsj1i))                      \
    match(construct = {dispatch}, device = {arch(gen)})                        \
        append_args(interop(prefer_type("sycl", "level_zero"), targetsync))    \
            adjust_args(need_device_ptr                                        \
                        : a) adjust_args(need_device_ptr                       \
                                         : y)
#endif
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vmsj1i))                      \
    match(construct = {target variant dispatch}, device = {arch(gen)})
void vmsJ1I(const MKL_INT n, const float* a, MKL_INT inca, float* y,
            MKL_INT incy, MKL_INT64 mode) NOTHROW;

#if (_OPENMP >= 202011)
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vdj1))                        \
    match(construct = {dispatch}, device = {arch(gen)})                        \
        append_args(interop(prefer_type("sycl", "level_zero"), targetsync))    \
            adjust_args(need_device_ptr                                        \
                        : a) adjust_args(need_device_ptr                       \
                                         : y)
#endif
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vdj1))                        \
    match(construct = {target variant dispatch}, device = {arch(gen)})
void vdJ1(const MKL_INT n, const double* a, double* y) NOTHROW;

#if (_OPENMP >= 202011)
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vdj1i))                       \
    match(construct = {dispatch}, device = {arch(gen)})                        \
        append_args(interop(prefer_type("sycl", "level_zero"), targetsync))    \
            adjust_args(need_device_ptr                                        \
                        : a) adjust_args(need_device_ptr                       \
                                         : y)
#endif
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vdj1i))                       \
    match(construct = {target variant dispatch}, device = {arch(gen)})
void vdJ1I(const MKL_INT n, const double* a, MKL_INT inca, double* y,
           MKL_INT incy) NOTHROW;

#if (_OPENMP >= 202011)
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vmdj1))                       \
    match(construct = {dispatch}, device = {arch(gen)})                        \
        append_args(interop(prefer_type("sycl", "level_zero"), targetsync))    \
            adjust_args(need_device_ptr                                        \
                        : a) adjust_args(need_device_ptr                       \
                                         : y)
#endif
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vmdj1))                       \
    match(construct = {target variant dispatch}, device = {arch(gen)})
void vmdJ1(const MKL_INT n, const double* a, double* y, MKL_INT64 mode) NOTHROW;

#if (_OPENMP >= 202011)
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vmdj1i))                      \
    match(construct = {dispatch}, device = {arch(gen)})                        \
        append_args(interop(prefer_type("sycl", "level_zero"), targetsync))    \
            adjust_args(need_device_ptr                                        \
                        : a) adjust_args(need_device_ptr                       \
                                         : y)
#endif
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vmdj1i))                      \
    match(construct = {target variant dispatch}, device = {arch(gen)})
void vmdJ1I(const MKL_INT n, const double* a, MKL_INT inca, double* y,
            MKL_INT incy, MKL_INT64 mode) NOTHROW;

// function jn
#if (_OPENMP >= 202011)
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vsjn))                        \
    match(construct = {dispatch}, device = {arch(gen)})                        \
        append_args(interop(prefer_type("sycl", "level_zero"), targetsync))    \
            adjust_args(need_device_ptr                                        \
                        : a) adjust_args(need_device_ptr                       \
                                         : y)
#endif
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vsjn))                        \
    match(construct = {target variant dispatch}, device = {arch(gen)})
void vsJn(const MKL_INT n, const float* a, const float b, float* y) NOTHROW;

#if (_OPENMP >= 202011)
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vsjni))                       \
    match(construct = {dispatch}, device = {arch(gen)})                        \
        append_args(interop(prefer_type("sycl", "level_zero"), targetsync))    \
            adjust_args(need_device_ptr                                        \
                        : a) adjust_args(need_device_ptr                       \
                                         : y)
#endif
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vsjni))                       \
    match(construct = {target variant dispatch}, device = {arch(gen)})
void vsJnI(const MKL_INT n, const float* a, MKL_INT inca, const float b,
           float* y, MKL_INT incy) NOTHROW;

#if (_OPENMP >= 202011)
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vmsjn))                       \
    match(construct = {dispatch}, device = {arch(gen)})                        \
        append_args(interop(prefer_type("sycl", "level_zero"), targetsync))    \
            adjust_args(need_device_ptr                                        \
                        : a) adjust_args(need_device_ptr                       \
                                         : y)
#endif
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vmsjn))                       \
    match(construct = {target variant dispatch}, device = {arch(gen)})
void vmsJn(const MKL_INT n, const float* a, const float b, float* y,
           MKL_INT64 mode) NOTHROW;

#if (_OPENMP >= 202011)
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vmsjni))                      \
    match(construct = {dispatch}, device = {arch(gen)})                        \
        append_args(interop(prefer_type("sycl", "level_zero"), targetsync))    \
            adjust_args(need_device_ptr                                        \
                        : a) adjust_args(need_device_ptr                       \
                                         : y)
#endif
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vmsjni))                      \
    match(construct = {target variant dispatch}, device = {arch(gen)})
void vmsJnI(const MKL_INT n, const float* a, MKL_INT inca, const float b,
            float* y, MKL_INT incy, MKL_INT64 mode) NOTHROW;

#if (_OPENMP >= 202011)
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vdjn))                        \
    match(construct = {dispatch}, device = {arch(gen)})                        \
        append_args(interop(prefer_type("sycl", "level_zero"), targetsync))    \
            adjust_args(need_device_ptr                                        \
                        : a) adjust_args(need_device_ptr                       \
                                         : y)
#endif
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vdjn))                        \
    match(construct = {target variant dispatch}, device = {arch(gen)})
void vdJn(const MKL_INT n, const double* a, const double b, double* y) NOTHROW;

#if (_OPENMP >= 202011)
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vdjni))                       \
    match(construct = {dispatch}, device = {arch(gen)})                        \
        append_args(interop(prefer_type("sycl", "level_zero"), targetsync))    \
            adjust_args(need_device_ptr                                        \
                        : a) adjust_args(need_device_ptr                       \
                                         : y)
#endif
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vdjni))                       \
    match(construct = {target variant dispatch}, device = {arch(gen)})
void vdJnI(const MKL_INT n, const double* a, MKL_INT inca, const double b,
           double* y, MKL_INT incy) NOTHROW;

#if (_OPENMP >= 202011)
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vmdjn))                       \
    match(construct = {dispatch}, device = {arch(gen)})                        \
        append_args(interop(prefer_type("sycl", "level_zero"), targetsync))    \
            adjust_args(need_device_ptr                                        \
                        : a) adjust_args(need_device_ptr                       \
                                         : y)
#endif
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vmdjn))                       \
    match(construct = {target variant dispatch}, device = {arch(gen)})
void vmdJn(const MKL_INT n, const double* a, const double b, double* y,
           MKL_INT64 mode) NOTHROW;

#if (_OPENMP >= 202011)
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vmdjni))                      \
    match(construct = {dispatch}, device = {arch(gen)})                        \
        append_args(interop(prefer_type("sycl", "level_zero"), targetsync))    \
            adjust_args(need_device_ptr                                        \
                        : a) adjust_args(need_device_ptr                       \
                                         : y)
#endif
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vmdjni))                      \
    match(construct = {target variant dispatch}, device = {arch(gen)})
void vmdJnI(const MKL_INT n, const double* a, MKL_INT inca, const double b,
            double* y, MKL_INT incy, MKL_INT64 mode) NOTHROW;

// function lgamma
#if (_OPENMP >= 202011)
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vslgamma))                    \
    match(construct = {dispatch}, device = {arch(gen)})                        \
        append_args(interop(prefer_type("sycl", "level_zero"), targetsync))    \
            adjust_args(need_device_ptr                                        \
                        : a) adjust_args(need_device_ptr                       \
                                         : y)
#endif
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vslgamma))                    \
    match(construct = {target variant dispatch}, device = {arch(gen)})
void vsLGamma(const MKL_INT n, const float* a, float* y) NOTHROW;

#if (_OPENMP >= 202011)
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vslgammai))                   \
    match(construct = {dispatch}, device = {arch(gen)})                        \
        append_args(interop(prefer_type("sycl", "level_zero"), targetsync))    \
            adjust_args(need_device_ptr                                        \
                        : a) adjust_args(need_device_ptr                       \
                                         : y)
#endif
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vslgammai))                   \
    match(construct = {target variant dispatch}, device = {arch(gen)})
void vsLGammaI(const MKL_INT n, const float* a, MKL_INT inca, float* y,
               MKL_INT incy) NOTHROW;

#if (_OPENMP >= 202011)
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vmslgamma))                   \
    match(construct = {dispatch}, device = {arch(gen)})                        \
        append_args(interop(prefer_type("sycl", "level_zero"), targetsync))    \
            adjust_args(need_device_ptr                                        \
                        : a) adjust_args(need_device_ptr                       \
                                         : y)
#endif
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vmslgamma))                   \
    match(construct = {target variant dispatch}, device = {arch(gen)})
void vmsLGamma(const MKL_INT n, const float* a, float* y,
               MKL_INT64 mode) NOTHROW;

#if (_OPENMP >= 202011)
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vmslgammai))                  \
    match(construct = {dispatch}, device = {arch(gen)})                        \
        append_args(interop(prefer_type("sycl", "level_zero"), targetsync))    \
            adjust_args(need_device_ptr                                        \
                        : a) adjust_args(need_device_ptr                       \
                                         : y)
#endif
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vmslgammai))                  \
    match(construct = {target variant dispatch}, device = {arch(gen)})
void vmsLGammaI(const MKL_INT n, const float* a, MKL_INT inca, float* y,
                MKL_INT incy, MKL_INT64 mode) NOTHROW;

#if (_OPENMP >= 202011)
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vdlgamma))                    \
    match(construct = {dispatch}, device = {arch(gen)})                        \
        append_args(interop(prefer_type("sycl", "level_zero"), targetsync))    \
            adjust_args(need_device_ptr                                        \
                        : a) adjust_args(need_device_ptr                       \
                                         : y)
#endif
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vdlgamma))                    \
    match(construct = {target variant dispatch}, device = {arch(gen)})
void vdLGamma(const MKL_INT n, const double* a, double* y) NOTHROW;

#if (_OPENMP >= 202011)
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vdlgammai))                   \
    match(construct = {dispatch}, device = {arch(gen)})                        \
        append_args(interop(prefer_type("sycl", "level_zero"), targetsync))    \
            adjust_args(need_device_ptr                                        \
                        : a) adjust_args(need_device_ptr                       \
                                         : y)
#endif
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vdlgammai))                   \
    match(construct = {target variant dispatch}, device = {arch(gen)})
void vdLGammaI(const MKL_INT n, const double* a, MKL_INT inca, double* y,
               MKL_INT incy) NOTHROW;

#if (_OPENMP >= 202011)
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vmdlgamma))                   \
    match(construct = {dispatch}, device = {arch(gen)})                        \
        append_args(interop(prefer_type("sycl", "level_zero"), targetsync))    \
            adjust_args(need_device_ptr                                        \
                        : a) adjust_args(need_device_ptr                       \
                                         : y)
#endif
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vmdlgamma))                   \
    match(construct = {target variant dispatch}, device = {arch(gen)})
void vmdLGamma(const MKL_INT n, const double* a, double* y,
               MKL_INT64 mode) NOTHROW;

#if (_OPENMP >= 202011)
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vmdlgammai))                  \
    match(construct = {dispatch}, device = {arch(gen)})                        \
        append_args(interop(prefer_type("sycl", "level_zero"), targetsync))    \
            adjust_args(need_device_ptr                                        \
                        : a) adjust_args(need_device_ptr                       \
                                         : y)
#endif
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vmdlgammai))                  \
    match(construct = {target variant dispatch}, device = {arch(gen)})
void vmdLGammaI(const MKL_INT n, const double* a, MKL_INT inca, double* y,
                MKL_INT incy, MKL_INT64 mode) NOTHROW;

// function linearfrac
#if (_OPENMP >= 202011)
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vslinearfrac))                \
    match(construct = {dispatch}, device = {arch(gen)})                        \
        append_args(interop(prefer_type("sycl", "level_zero"), targetsync))    \
            adjust_args(need_device_ptr                                        \
                        : a) adjust_args(need_device_ptr                       \
                                         : b) adjust_args(need_device_ptr      \
                                                          : y)
#endif
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vslinearfrac))                \
    match(construct = {target variant dispatch}, device = {arch(gen)})
void vsLinearFrac(const MKL_INT n, const float* a, const float* b,
                  const float c, const float d, const float e, const float f,
                  float* y) NOTHROW;

#if (_OPENMP >= 202011)
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vslinearfraci))               \
    match(construct = {dispatch}, device = {arch(gen)})                        \
        append_args(interop(prefer_type("sycl", "level_zero"), targetsync))    \
            adjust_args(need_device_ptr                                        \
                        : a) adjust_args(need_device_ptr                       \
                                         : b) adjust_args(need_device_ptr      \
                                                          : y)
#endif
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vslinearfraci))               \
    match(construct = {target variant dispatch}, device = {arch(gen)})
void vsLinearFracI(const MKL_INT n, const float* a, MKL_INT inca,
                   const float* b, MKL_INT incb, const float c, const float d,
                   const float e, const float f, float* y,
                   MKL_INT incy) NOTHROW;

#if (_OPENMP >= 202011)
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vmslinearfrac))               \
    match(construct = {dispatch}, device = {arch(gen)})                        \
        append_args(interop(prefer_type("sycl", "level_zero"), targetsync))    \
            adjust_args(need_device_ptr                                        \
                        : a) adjust_args(need_device_ptr                       \
                                         : b) adjust_args(need_device_ptr      \
                                                          : y)
#endif
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vmslinearfrac))               \
    match(construct = {target variant dispatch}, device = {arch(gen)})
void vmsLinearFrac(const MKL_INT n, const float* a, const float* b,
                   const float c, const float d, const float e, const float f,
                   float* y, MKL_INT64 mode) NOTHROW;

#if (_OPENMP >= 202011)
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vmslinearfraci))              \
    match(construct = {dispatch}, device = {arch(gen)})                        \
        append_args(interop(prefer_type("sycl", "level_zero"), targetsync))    \
            adjust_args(need_device_ptr                                        \
                        : a) adjust_args(need_device_ptr                       \
                                         : b) adjust_args(need_device_ptr      \
                                                          : y)
#endif
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vmslinearfraci))              \
    match(construct = {target variant dispatch}, device = {arch(gen)})
void vmsLinearFracI(const MKL_INT n, const float* a, MKL_INT inca,
                    const float* b, MKL_INT incb, const float c, const float d,
                    const float e, const float f, float* y, MKL_INT incy,
                    MKL_INT64 mode) NOTHROW;

#if (_OPENMP >= 202011)
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vdlinearfrac))                \
    match(construct = {dispatch}, device = {arch(gen)})                        \
        append_args(interop(prefer_type("sycl", "level_zero"), targetsync))    \
            adjust_args(need_device_ptr                                        \
                        : a) adjust_args(need_device_ptr                       \
                                         : b) adjust_args(need_device_ptr      \
                                                          : y)
#endif
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vdlinearfrac))                \
    match(construct = {target variant dispatch}, device = {arch(gen)})
void vdLinearFrac(const MKL_INT n, const double* a, const double* b,
                  const double c, const double d, const double e,
                  const double f, double* y) NOTHROW;

#if (_OPENMP >= 202011)
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vdlinearfraci))               \
    match(construct = {dispatch}, device = {arch(gen)})                        \
        append_args(interop(prefer_type("sycl", "level_zero"), targetsync))    \
            adjust_args(need_device_ptr                                        \
                        : a) adjust_args(need_device_ptr                       \
                                         : b) adjust_args(need_device_ptr      \
                                                          : y)
#endif
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vdlinearfraci))               \
    match(construct = {target variant dispatch}, device = {arch(gen)})
void vdLinearFracI(const MKL_INT n, const double* a, MKL_INT inca,
                   const double* b, MKL_INT incb, const double c,
                   const double d, const double e, const double f, double* y,
                   MKL_INT incy) NOTHROW;

#if (_OPENMP >= 202011)
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vmdlinearfrac))               \
    match(construct = {dispatch}, device = {arch(gen)})                        \
        append_args(interop(prefer_type("sycl", "level_zero"), targetsync))    \
            adjust_args(need_device_ptr                                        \
                        : a) adjust_args(need_device_ptr                       \
                                         : b) adjust_args(need_device_ptr      \
                                                          : y)
#endif
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vmdlinearfrac))               \
    match(construct = {target variant dispatch}, device = {arch(gen)})
void vmdLinearFrac(const MKL_INT n, const double* a, const double* b,
                   const double c, const double d, const double e,
                   const double f, double* y, MKL_INT64 mode) NOTHROW;

#if (_OPENMP >= 202011)
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vmdlinearfraci))              \
    match(construct = {dispatch}, device = {arch(gen)})                        \
        append_args(interop(prefer_type("sycl", "level_zero"), targetsync))    \
            adjust_args(need_device_ptr                                        \
                        : a) adjust_args(need_device_ptr                       \
                                         : b) adjust_args(need_device_ptr      \
                                                          : y)
#endif
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vmdlinearfraci))              \
    match(construct = {target variant dispatch}, device = {arch(gen)})
void vmdLinearFracI(const MKL_INT n, const double* a, MKL_INT inca,
                    const double* b, MKL_INT incb, const double c,
                    const double d, const double e, const double f, double* y,
                    MKL_INT incy, MKL_INT64 mode) NOTHROW;

// function ln
#if (_OPENMP >= 202011)
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vsln))                        \
    match(construct = {dispatch}, device = {arch(gen)})                        \
        append_args(interop(prefer_type("sycl", "level_zero"), targetsync))    \
            adjust_args(need_device_ptr                                        \
                        : a) adjust_args(need_device_ptr                       \
                                         : y)
#endif
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vsln))                        \
    match(construct = {target variant dispatch}, device = {arch(gen)})
void vsLn(const MKL_INT n, const float* a, float* y) NOTHROW;

#if (_OPENMP >= 202011)
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vslni))                       \
    match(construct = {dispatch}, device = {arch(gen)})                        \
        append_args(interop(prefer_type("sycl", "level_zero"), targetsync))    \
            adjust_args(need_device_ptr                                        \
                        : a) adjust_args(need_device_ptr                       \
                                         : y)
#endif
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vslni))                       \
    match(construct = {target variant dispatch}, device = {arch(gen)})
void vsLnI(const MKL_INT n, const float* a, MKL_INT inca, float* y,
           MKL_INT incy) NOTHROW;

#if (_OPENMP >= 202011)
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vmsln))                       \
    match(construct = {dispatch}, device = {arch(gen)})                        \
        append_args(interop(prefer_type("sycl", "level_zero"), targetsync))    \
            adjust_args(need_device_ptr                                        \
                        : a) adjust_args(need_device_ptr                       \
                                         : y)
#endif
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vmsln))                       \
    match(construct = {target variant dispatch}, device = {arch(gen)})
void vmsLn(const MKL_INT n, const float* a, float* y, MKL_INT64 mode) NOTHROW;

#if (_OPENMP >= 202011)
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vmslni))                      \
    match(construct = {dispatch}, device = {arch(gen)})                        \
        append_args(interop(prefer_type("sycl", "level_zero"), targetsync))    \
            adjust_args(need_device_ptr                                        \
                        : a) adjust_args(need_device_ptr                       \
                                         : y)
#endif
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vmslni))                      \
    match(construct = {target variant dispatch}, device = {arch(gen)})
void vmsLnI(const MKL_INT n, const float* a, MKL_INT inca, float* y,
            MKL_INT incy, MKL_INT64 mode) NOTHROW;

#if (_OPENMP >= 202011)
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vdln))                        \
    match(construct = {dispatch}, device = {arch(gen)})                        \
        append_args(interop(prefer_type("sycl", "level_zero"), targetsync))    \
            adjust_args(need_device_ptr                                        \
                        : a) adjust_args(need_device_ptr                       \
                                         : y)
#endif
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vdln))                        \
    match(construct = {target variant dispatch}, device = {arch(gen)})
void vdLn(const MKL_INT n, const double* a, double* y) NOTHROW;

#if (_OPENMP >= 202011)
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vdlni))                       \
    match(construct = {dispatch}, device = {arch(gen)})                        \
        append_args(interop(prefer_type("sycl", "level_zero"), targetsync))    \
            adjust_args(need_device_ptr                                        \
                        : a) adjust_args(need_device_ptr                       \
                                         : y)
#endif
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vdlni))                       \
    match(construct = {target variant dispatch}, device = {arch(gen)})
void vdLnI(const MKL_INT n, const double* a, MKL_INT inca, double* y,
           MKL_INT incy) NOTHROW;

#if (_OPENMP >= 202011)
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vmdln))                       \
    match(construct = {dispatch}, device = {arch(gen)})                        \
        append_args(interop(prefer_type("sycl", "level_zero"), targetsync))    \
            adjust_args(need_device_ptr                                        \
                        : a) adjust_args(need_device_ptr                       \
                                         : y)
#endif
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vmdln))                       \
    match(construct = {target variant dispatch}, device = {arch(gen)})
void vmdLn(const MKL_INT n, const double* a, double* y, MKL_INT64 mode) NOTHROW;

#if (_OPENMP >= 202011)
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vmdlni))                      \
    match(construct = {dispatch}, device = {arch(gen)})                        \
        append_args(interop(prefer_type("sycl", "level_zero"), targetsync))    \
            adjust_args(need_device_ptr                                        \
                        : a) adjust_args(need_device_ptr                       \
                                         : y)
#endif
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vmdlni))                      \
    match(construct = {target variant dispatch}, device = {arch(gen)})
void vmdLnI(const MKL_INT n, const double* a, MKL_INT inca, double* y,
            MKL_INT incy, MKL_INT64 mode) NOTHROW;

#if (_OPENMP >= 202011)
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vcln))                        \
    match(construct = {dispatch}, device = {arch(gen)})                        \
        append_args(interop(prefer_type("sycl", "level_zero"), targetsync))    \
            adjust_args(need_device_ptr                                        \
                        : a) adjust_args(need_device_ptr                       \
                                         : y)
#endif
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vcln))                        \
    match(construct = {target variant dispatch}, device = {arch(gen)})
void vcLn(const MKL_INT n, const MKL_Complex8* a, MKL_Complex8* y) NOTHROW;

#if (_OPENMP >= 202011)
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vclni))                       \
    match(construct = {dispatch}, device = {arch(gen)})                        \
        append_args(interop(prefer_type("sycl", "level_zero"), targetsync))    \
            adjust_args(need_device_ptr                                        \
                        : a) adjust_args(need_device_ptr                       \
                                         : y)
#endif
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vclni))                       \
    match(construct = {target variant dispatch}, device = {arch(gen)})
void vcLnI(const MKL_INT n, const MKL_Complex8* a, MKL_INT inca,
           MKL_Complex8* y, MKL_INT incy) NOTHROW;

#if (_OPENMP >= 202011)
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vmcln))                       \
    match(construct = {dispatch}, device = {arch(gen)})                        \
        append_args(interop(prefer_type("sycl", "level_zero"), targetsync))    \
            adjust_args(need_device_ptr                                        \
                        : a) adjust_args(need_device_ptr                       \
                                         : y)
#endif
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vmcln))                       \
    match(construct = {target variant dispatch}, device = {arch(gen)})
void vmcLn(const MKL_INT n, const MKL_Complex8* a, MKL_Complex8* y,
           MKL_INT64 mode) NOTHROW;

#if (_OPENMP >= 202011)
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vmclni))                      \
    match(construct = {dispatch}, device = {arch(gen)})                        \
        append_args(interop(prefer_type("sycl", "level_zero"), targetsync))    \
            adjust_args(need_device_ptr                                        \
                        : a) adjust_args(need_device_ptr                       \
                                         : y)
#endif
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vmclni))                      \
    match(construct = {target variant dispatch}, device = {arch(gen)})
void vmcLnI(const MKL_INT n, const MKL_Complex8* a, MKL_INT inca,
            MKL_Complex8* y, MKL_INT incy, MKL_INT64 mode) NOTHROW;

#if (_OPENMP >= 202011)
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vzln))                        \
    match(construct = {dispatch}, device = {arch(gen)})                        \
        append_args(interop(prefer_type("sycl", "level_zero"), targetsync))    \
            adjust_args(need_device_ptr                                        \
                        : a) adjust_args(need_device_ptr                       \
                                         : y)
#endif
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vzln))                        \
    match(construct = {target variant dispatch}, device = {arch(gen)})
void vzLn(const MKL_INT n, const MKL_Complex16* a, MKL_Complex16* y) NOTHROW;

#if (_OPENMP >= 202011)
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vzlni))                       \
    match(construct = {dispatch}, device = {arch(gen)})                        \
        append_args(interop(prefer_type("sycl", "level_zero"), targetsync))    \
            adjust_args(need_device_ptr                                        \
                        : a) adjust_args(need_device_ptr                       \
                                         : y)
#endif
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vzlni))                       \
    match(construct = {target variant dispatch}, device = {arch(gen)})
void vzLnI(const MKL_INT n, const MKL_Complex16* a, MKL_INT inca,
           MKL_Complex16* y, MKL_INT incy) NOTHROW;

#if (_OPENMP >= 202011)
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vmzln))                       \
    match(construct = {dispatch}, device = {arch(gen)})                        \
        append_args(interop(prefer_type("sycl", "level_zero"), targetsync))    \
            adjust_args(need_device_ptr                                        \
                        : a) adjust_args(need_device_ptr                       \
                                         : y)
#endif
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vmzln))                       \
    match(construct = {target variant dispatch}, device = {arch(gen)})
void vmzLn(const MKL_INT n, const MKL_Complex16* a, MKL_Complex16* y,
           MKL_INT64 mode) NOTHROW;

#if (_OPENMP >= 202011)
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vmzlni))                      \
    match(construct = {dispatch}, device = {arch(gen)})                        \
        append_args(interop(prefer_type("sycl", "level_zero"), targetsync))    \
            adjust_args(need_device_ptr                                        \
                        : a) adjust_args(need_device_ptr                       \
                                         : y)
#endif
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vmzlni))                      \
    match(construct = {target variant dispatch}, device = {arch(gen)})
void vmzLnI(const MKL_INT n, const MKL_Complex16* a, MKL_INT inca,
            MKL_Complex16* y, MKL_INT incy, MKL_INT64 mode) NOTHROW;

// function log10
#if (_OPENMP >= 202011)
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vslog10))                     \
    match(construct = {dispatch}, device = {arch(gen)})                        \
        append_args(interop(prefer_type("sycl", "level_zero"), targetsync))    \
            adjust_args(need_device_ptr                                        \
                        : a) adjust_args(need_device_ptr                       \
                                         : y)
#endif
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vslog10))                     \
    match(construct = {target variant dispatch}, device = {arch(gen)})
void vsLog10(const MKL_INT n, const float* a, float* y) NOTHROW;

#if (_OPENMP >= 202011)
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vslog10i))                    \
    match(construct = {dispatch}, device = {arch(gen)})                        \
        append_args(interop(prefer_type("sycl", "level_zero"), targetsync))    \
            adjust_args(need_device_ptr                                        \
                        : a) adjust_args(need_device_ptr                       \
                                         : y)
#endif
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vslog10i))                    \
    match(construct = {target variant dispatch}, device = {arch(gen)})
void vsLog10I(const MKL_INT n, const float* a, MKL_INT inca, float* y,
              MKL_INT incy) NOTHROW;

#if (_OPENMP >= 202011)
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vmslog10))                    \
    match(construct = {dispatch}, device = {arch(gen)})                        \
        append_args(interop(prefer_type("sycl", "level_zero"), targetsync))    \
            adjust_args(need_device_ptr                                        \
                        : a) adjust_args(need_device_ptr                       \
                                         : y)
#endif
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vmslog10))                    \
    match(construct = {target variant dispatch}, device = {arch(gen)})
void vmsLog10(const MKL_INT n, const float* a, float* y,
              MKL_INT64 mode) NOTHROW;

#if (_OPENMP >= 202011)
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vmslog10i))                   \
    match(construct = {dispatch}, device = {arch(gen)})                        \
        append_args(interop(prefer_type("sycl", "level_zero"), targetsync))    \
            adjust_args(need_device_ptr                                        \
                        : a) adjust_args(need_device_ptr                       \
                                         : y)
#endif
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vmslog10i))                   \
    match(construct = {target variant dispatch}, device = {arch(gen)})
void vmsLog10I(const MKL_INT n, const float* a, MKL_INT inca, float* y,
               MKL_INT incy, MKL_INT64 mode) NOTHROW;

#if (_OPENMP >= 202011)
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vdlog10))                     \
    match(construct = {dispatch}, device = {arch(gen)})                        \
        append_args(interop(prefer_type("sycl", "level_zero"), targetsync))    \
            adjust_args(need_device_ptr                                        \
                        : a) adjust_args(need_device_ptr                       \
                                         : y)
#endif
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vdlog10))                     \
    match(construct = {target variant dispatch}, device = {arch(gen)})
void vdLog10(const MKL_INT n, const double* a, double* y) NOTHROW;

#if (_OPENMP >= 202011)
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vdlog10i))                    \
    match(construct = {dispatch}, device = {arch(gen)})                        \
        append_args(interop(prefer_type("sycl", "level_zero"), targetsync))    \
            adjust_args(need_device_ptr                                        \
                        : a) adjust_args(need_device_ptr                       \
                                         : y)
#endif
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vdlog10i))                    \
    match(construct = {target variant dispatch}, device = {arch(gen)})
void vdLog10I(const MKL_INT n, const double* a, MKL_INT inca, double* y,
              MKL_INT incy) NOTHROW;

#if (_OPENMP >= 202011)
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vmdlog10))                    \
    match(construct = {dispatch}, device = {arch(gen)})                        \
        append_args(interop(prefer_type("sycl", "level_zero"), targetsync))    \
            adjust_args(need_device_ptr                                        \
                        : a) adjust_args(need_device_ptr                       \
                                         : y)
#endif
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vmdlog10))                    \
    match(construct = {target variant dispatch}, device = {arch(gen)})
void vmdLog10(const MKL_INT n, const double* a, double* y,
              MKL_INT64 mode) NOTHROW;

#if (_OPENMP >= 202011)
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vmdlog10i))                   \
    match(construct = {dispatch}, device = {arch(gen)})                        \
        append_args(interop(prefer_type("sycl", "level_zero"), targetsync))    \
            adjust_args(need_device_ptr                                        \
                        : a) adjust_args(need_device_ptr                       \
                                         : y)
#endif
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vmdlog10i))                   \
    match(construct = {target variant dispatch}, device = {arch(gen)})
void vmdLog10I(const MKL_INT n, const double* a, MKL_INT inca, double* y,
               MKL_INT incy, MKL_INT64 mode) NOTHROW;

#if (_OPENMP >= 202011)
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vclog10))                     \
    match(construct = {dispatch}, device = {arch(gen)})                        \
        append_args(interop(prefer_type("sycl", "level_zero"), targetsync))    \
            adjust_args(need_device_ptr                                        \
                        : a) adjust_args(need_device_ptr                       \
                                         : y)
#endif
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vclog10))                     \
    match(construct = {target variant dispatch}, device = {arch(gen)})
void vcLog10(const MKL_INT n, const MKL_Complex8* a, MKL_Complex8* y) NOTHROW;

#if (_OPENMP >= 202011)
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vclog10i))                    \
    match(construct = {dispatch}, device = {arch(gen)})                        \
        append_args(interop(prefer_type("sycl", "level_zero"), targetsync))    \
            adjust_args(need_device_ptr                                        \
                        : a) adjust_args(need_device_ptr                       \
                                         : y)
#endif
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vclog10i))                    \
    match(construct = {target variant dispatch}, device = {arch(gen)})
void vcLog10I(const MKL_INT n, const MKL_Complex8* a, MKL_INT inca,
              MKL_Complex8* y, MKL_INT incy) NOTHROW;

#if (_OPENMP >= 202011)
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vmclog10))                    \
    match(construct = {dispatch}, device = {arch(gen)})                        \
        append_args(interop(prefer_type("sycl", "level_zero"), targetsync))    \
            adjust_args(need_device_ptr                                        \
                        : a) adjust_args(need_device_ptr                       \
                                         : y)
#endif
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vmclog10))                    \
    match(construct = {target variant dispatch}, device = {arch(gen)})
void vmcLog10(const MKL_INT n, const MKL_Complex8* a, MKL_Complex8* y,
              MKL_INT64 mode) NOTHROW;

#if (_OPENMP >= 202011)
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vmclog10i))                   \
    match(construct = {dispatch}, device = {arch(gen)})                        \
        append_args(interop(prefer_type("sycl", "level_zero"), targetsync))    \
            adjust_args(need_device_ptr                                        \
                        : a) adjust_args(need_device_ptr                       \
                                         : y)
#endif
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vmclog10i))                   \
    match(construct = {target variant dispatch}, device = {arch(gen)})
void vmcLog10I(const MKL_INT n, const MKL_Complex8* a, MKL_INT inca,
               MKL_Complex8* y, MKL_INT incy, MKL_INT64 mode) NOTHROW;

#if (_OPENMP >= 202011)
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vzlog10))                     \
    match(construct = {dispatch}, device = {arch(gen)})                        \
        append_args(interop(prefer_type("sycl", "level_zero"), targetsync))    \
            adjust_args(need_device_ptr                                        \
                        : a) adjust_args(need_device_ptr                       \
                                         : y)
#endif
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vzlog10))                     \
    match(construct = {target variant dispatch}, device = {arch(gen)})
void vzLog10(const MKL_INT n, const MKL_Complex16* a, MKL_Complex16* y) NOTHROW;

#if (_OPENMP >= 202011)
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vzlog10i))                    \
    match(construct = {dispatch}, device = {arch(gen)})                        \
        append_args(interop(prefer_type("sycl", "level_zero"), targetsync))    \
            adjust_args(need_device_ptr                                        \
                        : a) adjust_args(need_device_ptr                       \
                                         : y)
#endif
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vzlog10i))                    \
    match(construct = {target variant dispatch}, device = {arch(gen)})
void vzLog10I(const MKL_INT n, const MKL_Complex16* a, MKL_INT inca,
              MKL_Complex16* y, MKL_INT incy) NOTHROW;

#if (_OPENMP >= 202011)
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vmzlog10))                    \
    match(construct = {dispatch}, device = {arch(gen)})                        \
        append_args(interop(prefer_type("sycl", "level_zero"), targetsync))    \
            adjust_args(need_device_ptr                                        \
                        : a) adjust_args(need_device_ptr                       \
                                         : y)
#endif
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vmzlog10))                    \
    match(construct = {target variant dispatch}, device = {arch(gen)})
void vmzLog10(const MKL_INT n, const MKL_Complex16* a, MKL_Complex16* y,
              MKL_INT64 mode) NOTHROW;

#if (_OPENMP >= 202011)
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vmzlog10i))                   \
    match(construct = {dispatch}, device = {arch(gen)})                        \
        append_args(interop(prefer_type("sycl", "level_zero"), targetsync))    \
            adjust_args(need_device_ptr                                        \
                        : a) adjust_args(need_device_ptr                       \
                                         : y)
#endif
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vmzlog10i))                   \
    match(construct = {target variant dispatch}, device = {arch(gen)})
void vmzLog10I(const MKL_INT n, const MKL_Complex16* a, MKL_INT inca,
               MKL_Complex16* y, MKL_INT incy, MKL_INT64 mode) NOTHROW;

// function log1p
#if (_OPENMP >= 202011)
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vslog1p))                     \
    match(construct = {dispatch}, device = {arch(gen)})                        \
        append_args(interop(prefer_type("sycl", "level_zero"), targetsync))    \
            adjust_args(need_device_ptr                                        \
                        : a) adjust_args(need_device_ptr                       \
                                         : y)
#endif
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vslog1p))                     \
    match(construct = {target variant dispatch}, device = {arch(gen)})
void vsLog1p(const MKL_INT n, const float* a, float* y) NOTHROW;

#if (_OPENMP >= 202011)
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vslog1pi))                    \
    match(construct = {dispatch}, device = {arch(gen)})                        \
        append_args(interop(prefer_type("sycl", "level_zero"), targetsync))    \
            adjust_args(need_device_ptr                                        \
                        : a) adjust_args(need_device_ptr                       \
                                         : y)
#endif
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vslog1pi))                    \
    match(construct = {target variant dispatch}, device = {arch(gen)})
void vsLog1pI(const MKL_INT n, const float* a, MKL_INT inca, float* y,
              MKL_INT incy) NOTHROW;

#if (_OPENMP >= 202011)
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vmslog1p))                    \
    match(construct = {dispatch}, device = {arch(gen)})                        \
        append_args(interop(prefer_type("sycl", "level_zero"), targetsync))    \
            adjust_args(need_device_ptr                                        \
                        : a) adjust_args(need_device_ptr                       \
                                         : y)
#endif
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vmslog1p))                    \
    match(construct = {target variant dispatch}, device = {arch(gen)})
void vmsLog1p(const MKL_INT n, const float* a, float* y,
              MKL_INT64 mode) NOTHROW;

#if (_OPENMP >= 202011)
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vmslog1pi))                   \
    match(construct = {dispatch}, device = {arch(gen)})                        \
        append_args(interop(prefer_type("sycl", "level_zero"), targetsync))    \
            adjust_args(need_device_ptr                                        \
                        : a) adjust_args(need_device_ptr                       \
                                         : y)
#endif
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vmslog1pi))                   \
    match(construct = {target variant dispatch}, device = {arch(gen)})
void vmsLog1pI(const MKL_INT n, const float* a, MKL_INT inca, float* y,
               MKL_INT incy, MKL_INT64 mode) NOTHROW;

#if (_OPENMP >= 202011)
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vdlog1p))                     \
    match(construct = {dispatch}, device = {arch(gen)})                        \
        append_args(interop(prefer_type("sycl", "level_zero"), targetsync))    \
            adjust_args(need_device_ptr                                        \
                        : a) adjust_args(need_device_ptr                       \
                                         : y)
#endif
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vdlog1p))                     \
    match(construct = {target variant dispatch}, device = {arch(gen)})
void vdLog1p(const MKL_INT n, const double* a, double* y) NOTHROW;

#if (_OPENMP >= 202011)
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vdlog1pi))                    \
    match(construct = {dispatch}, device = {arch(gen)})                        \
        append_args(interop(prefer_type("sycl", "level_zero"), targetsync))    \
            adjust_args(need_device_ptr                                        \
                        : a) adjust_args(need_device_ptr                       \
                                         : y)
#endif
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vdlog1pi))                    \
    match(construct = {target variant dispatch}, device = {arch(gen)})
void vdLog1pI(const MKL_INT n, const double* a, MKL_INT inca, double* y,
              MKL_INT incy) NOTHROW;

#if (_OPENMP >= 202011)
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vmdlog1p))                    \
    match(construct = {dispatch}, device = {arch(gen)})                        \
        append_args(interop(prefer_type("sycl", "level_zero"), targetsync))    \
            adjust_args(need_device_ptr                                        \
                        : a) adjust_args(need_device_ptr                       \
                                         : y)
#endif
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vmdlog1p))                    \
    match(construct = {target variant dispatch}, device = {arch(gen)})
void vmdLog1p(const MKL_INT n, const double* a, double* y,
              MKL_INT64 mode) NOTHROW;

#if (_OPENMP >= 202011)
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vmdlog1pi))                   \
    match(construct = {dispatch}, device = {arch(gen)})                        \
        append_args(interop(prefer_type("sycl", "level_zero"), targetsync))    \
            adjust_args(need_device_ptr                                        \
                        : a) adjust_args(need_device_ptr                       \
                                         : y)
#endif
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vmdlog1pi))                   \
    match(construct = {target variant dispatch}, device = {arch(gen)})
void vmdLog1pI(const MKL_INT n, const double* a, MKL_INT inca, double* y,
               MKL_INT incy, MKL_INT64 mode) NOTHROW;

// function log2
#if (_OPENMP >= 202011)
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vslog2))                      \
    match(construct = {dispatch}, device = {arch(gen)})                        \
        append_args(interop(prefer_type("sycl", "level_zero"), targetsync))    \
            adjust_args(need_device_ptr                                        \
                        : a) adjust_args(need_device_ptr                       \
                                         : y)
#endif
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vslog2))                      \
    match(construct = {target variant dispatch}, device = {arch(gen)})
void vsLog2(const MKL_INT n, const float* a, float* y) NOTHROW;

#if (_OPENMP >= 202011)
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vslog2i))                     \
    match(construct = {dispatch}, device = {arch(gen)})                        \
        append_args(interop(prefer_type("sycl", "level_zero"), targetsync))    \
            adjust_args(need_device_ptr                                        \
                        : a) adjust_args(need_device_ptr                       \
                                         : y)
#endif
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vslog2i))                     \
    match(construct = {target variant dispatch}, device = {arch(gen)})
void vsLog2I(const MKL_INT n, const float* a, MKL_INT inca, float* y,
             MKL_INT incy) NOTHROW;

#if (_OPENMP >= 202011)
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vmslog2))                     \
    match(construct = {dispatch}, device = {arch(gen)})                        \
        append_args(interop(prefer_type("sycl", "level_zero"), targetsync))    \
            adjust_args(need_device_ptr                                        \
                        : a) adjust_args(need_device_ptr                       \
                                         : y)
#endif
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vmslog2))                     \
    match(construct = {target variant dispatch}, device = {arch(gen)})
void vmsLog2(const MKL_INT n, const float* a, float* y, MKL_INT64 mode) NOTHROW;

#if (_OPENMP >= 202011)
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vmslog2i))                    \
    match(construct = {dispatch}, device = {arch(gen)})                        \
        append_args(interop(prefer_type("sycl", "level_zero"), targetsync))    \
            adjust_args(need_device_ptr                                        \
                        : a) adjust_args(need_device_ptr                       \
                                         : y)
#endif
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vmslog2i))                    \
    match(construct = {target variant dispatch}, device = {arch(gen)})
void vmsLog2I(const MKL_INT n, const float* a, MKL_INT inca, float* y,
              MKL_INT incy, MKL_INT64 mode) NOTHROW;

#if (_OPENMP >= 202011)
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vdlog2))                      \
    match(construct = {dispatch}, device = {arch(gen)})                        \
        append_args(interop(prefer_type("sycl", "level_zero"), targetsync))    \
            adjust_args(need_device_ptr                                        \
                        : a) adjust_args(need_device_ptr                       \
                                         : y)
#endif
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vdlog2))                      \
    match(construct = {target variant dispatch}, device = {arch(gen)})
void vdLog2(const MKL_INT n, const double* a, double* y) NOTHROW;

#if (_OPENMP >= 202011)
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vdlog2i))                     \
    match(construct = {dispatch}, device = {arch(gen)})                        \
        append_args(interop(prefer_type("sycl", "level_zero"), targetsync))    \
            adjust_args(need_device_ptr                                        \
                        : a) adjust_args(need_device_ptr                       \
                                         : y)
#endif
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vdlog2i))                     \
    match(construct = {target variant dispatch}, device = {arch(gen)})
void vdLog2I(const MKL_INT n, const double* a, MKL_INT inca, double* y,
             MKL_INT incy) NOTHROW;

#if (_OPENMP >= 202011)
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vmdlog2))                     \
    match(construct = {dispatch}, device = {arch(gen)})                        \
        append_args(interop(prefer_type("sycl", "level_zero"), targetsync))    \
            adjust_args(need_device_ptr                                        \
                        : a) adjust_args(need_device_ptr                       \
                                         : y)
#endif
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vmdlog2))                     \
    match(construct = {target variant dispatch}, device = {arch(gen)})
void vmdLog2(const MKL_INT n, const double* a, double* y,
             MKL_INT64 mode) NOTHROW;

#if (_OPENMP >= 202011)
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vmdlog2i))                    \
    match(construct = {dispatch}, device = {arch(gen)})                        \
        append_args(interop(prefer_type("sycl", "level_zero"), targetsync))    \
            adjust_args(need_device_ptr                                        \
                        : a) adjust_args(need_device_ptr                       \
                                         : y)
#endif
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vmdlog2i))                    \
    match(construct = {target variant dispatch}, device = {arch(gen)})
void vmdLog2I(const MKL_INT n, const double* a, MKL_INT inca, double* y,
              MKL_INT incy, MKL_INT64 mode) NOTHROW;

// function logb
#if (_OPENMP >= 202011)
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vslogb))                      \
    match(construct = {dispatch}, device = {arch(gen)})                        \
        append_args(interop(prefer_type("sycl", "level_zero"), targetsync))    \
            adjust_args(need_device_ptr                                        \
                        : a) adjust_args(need_device_ptr                       \
                                         : y)
#endif
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vslogb))                      \
    match(construct = {target variant dispatch}, device = {arch(gen)})
void vsLogb(const MKL_INT n, const float* a, float* y) NOTHROW;

#if (_OPENMP >= 202011)
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vslogbi))                     \
    match(construct = {dispatch}, device = {arch(gen)})                        \
        append_args(interop(prefer_type("sycl", "level_zero"), targetsync))    \
            adjust_args(need_device_ptr                                        \
                        : a) adjust_args(need_device_ptr                       \
                                         : y)
#endif
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vslogbi))                     \
    match(construct = {target variant dispatch}, device = {arch(gen)})
void vsLogbI(const MKL_INT n, const float* a, MKL_INT inca, float* y,
             MKL_INT incy) NOTHROW;

#if (_OPENMP >= 202011)
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vmslogb))                     \
    match(construct = {dispatch}, device = {arch(gen)})                        \
        append_args(interop(prefer_type("sycl", "level_zero"), targetsync))    \
            adjust_args(need_device_ptr                                        \
                        : a) adjust_args(need_device_ptr                       \
                                         : y)
#endif
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vmslogb))                     \
    match(construct = {target variant dispatch}, device = {arch(gen)})
void vmsLogb(const MKL_INT n, const float* a, float* y, MKL_INT64 mode) NOTHROW;

#if (_OPENMP >= 202011)
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vmslogbi))                    \
    match(construct = {dispatch}, device = {arch(gen)})                        \
        append_args(interop(prefer_type("sycl", "level_zero"), targetsync))    \
            adjust_args(need_device_ptr                                        \
                        : a) adjust_args(need_device_ptr                       \
                                         : y)
#endif
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vmslogbi))                    \
    match(construct = {target variant dispatch}, device = {arch(gen)})
void vmsLogbI(const MKL_INT n, const float* a, MKL_INT inca, float* y,
              MKL_INT incy, MKL_INT64 mode) NOTHROW;

#if (_OPENMP >= 202011)
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vdlogb))                      \
    match(construct = {dispatch}, device = {arch(gen)})                        \
        append_args(interop(prefer_type("sycl", "level_zero"), targetsync))    \
            adjust_args(need_device_ptr                                        \
                        : a) adjust_args(need_device_ptr                       \
                                         : y)
#endif
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vdlogb))                      \
    match(construct = {target variant dispatch}, device = {arch(gen)})
void vdLogb(const MKL_INT n, const double* a, double* y) NOTHROW;

#if (_OPENMP >= 202011)
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vdlogbi))                     \
    match(construct = {dispatch}, device = {arch(gen)})                        \
        append_args(interop(prefer_type("sycl", "level_zero"), targetsync))    \
            adjust_args(need_device_ptr                                        \
                        : a) adjust_args(need_device_ptr                       \
                                         : y)
#endif
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vdlogbi))                     \
    match(construct = {target variant dispatch}, device = {arch(gen)})
void vdLogbI(const MKL_INT n, const double* a, MKL_INT inca, double* y,
             MKL_INT incy) NOTHROW;

#if (_OPENMP >= 202011)
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vmdlogb))                     \
    match(construct = {dispatch}, device = {arch(gen)})                        \
        append_args(interop(prefer_type("sycl", "level_zero"), targetsync))    \
            adjust_args(need_device_ptr                                        \
                        : a) adjust_args(need_device_ptr                       \
                                         : y)
#endif
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vmdlogb))                     \
    match(construct = {target variant dispatch}, device = {arch(gen)})
void vmdLogb(const MKL_INT n, const double* a, double* y,
             MKL_INT64 mode) NOTHROW;

#if (_OPENMP >= 202011)
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vmdlogbi))                    \
    match(construct = {dispatch}, device = {arch(gen)})                        \
        append_args(interop(prefer_type("sycl", "level_zero"), targetsync))    \
            adjust_args(need_device_ptr                                        \
                        : a) adjust_args(need_device_ptr                       \
                                         : y)
#endif
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vmdlogbi))                    \
    match(construct = {target variant dispatch}, device = {arch(gen)})
void vmdLogbI(const MKL_INT n, const double* a, MKL_INT inca, double* y,
              MKL_INT incy, MKL_INT64 mode) NOTHROW;

// function maxmag
#if (_OPENMP >= 202011)
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vsmaxmag))                    \
    match(construct = {dispatch}, device = {arch(gen)})                        \
        append_args(interop(prefer_type("sycl", "level_zero"), targetsync))    \
            adjust_args(need_device_ptr                                        \
                        : a) adjust_args(need_device_ptr                       \
                                         : b) adjust_args(need_device_ptr      \
                                                          : y)
#endif
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vsmaxmag))                    \
    match(construct = {target variant dispatch}, device = {arch(gen)})
void vsMaxMag(const MKL_INT n, const float* a, const float* b,
              float* y) NOTHROW;

#if (_OPENMP >= 202011)
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vsmaxmagi))                   \
    match(construct = {dispatch}, device = {arch(gen)})                        \
        append_args(interop(prefer_type("sycl", "level_zero"), targetsync))    \
            adjust_args(need_device_ptr                                        \
                        : a) adjust_args(need_device_ptr                       \
                                         : b) adjust_args(need_device_ptr      \
                                                          : y)
#endif
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vsmaxmagi))                   \
    match(construct = {target variant dispatch}, device = {arch(gen)})
void vsMaxMagI(const MKL_INT n, const float* a, MKL_INT inca, const float* b,
               MKL_INT incb, float* y, MKL_INT incy) NOTHROW;

#if (_OPENMP >= 202011)
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vmsmaxmag))                   \
    match(construct = {dispatch}, device = {arch(gen)})                        \
        append_args(interop(prefer_type("sycl", "level_zero"), targetsync))    \
            adjust_args(need_device_ptr                                        \
                        : a) adjust_args(need_device_ptr                       \
                                         : b) adjust_args(need_device_ptr      \
                                                          : y)
#endif
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vmsmaxmag))                   \
    match(construct = {target variant dispatch}, device = {arch(gen)})
void vmsMaxMag(const MKL_INT n, const float* a, const float* b, float* y,
               MKL_INT64 mode) NOTHROW;

#if (_OPENMP >= 202011)
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vmsmaxmagi))                  \
    match(construct = {dispatch}, device = {arch(gen)})                        \
        append_args(interop(prefer_type("sycl", "level_zero"), targetsync))    \
            adjust_args(need_device_ptr                                        \
                        : a) adjust_args(need_device_ptr                       \
                                         : b) adjust_args(need_device_ptr      \
                                                          : y)
#endif
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vmsmaxmagi))                  \
    match(construct = {target variant dispatch}, device = {arch(gen)})
void vmsMaxMagI(const MKL_INT n, const float* a, MKL_INT inca, const float* b,
                MKL_INT incb, float* y, MKL_INT incy, MKL_INT64 mode) NOTHROW;

#if (_OPENMP >= 202011)
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vdmaxmag))                    \
    match(construct = {dispatch}, device = {arch(gen)})                        \
        append_args(interop(prefer_type("sycl", "level_zero"), targetsync))    \
            adjust_args(need_device_ptr                                        \
                        : a) adjust_args(need_device_ptr                       \
                                         : b) adjust_args(need_device_ptr      \
                                                          : y)
#endif
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vdmaxmag))                    \
    match(construct = {target variant dispatch}, device = {arch(gen)})
void vdMaxMag(const MKL_INT n, const double* a, const double* b,
              double* y) NOTHROW;

#if (_OPENMP >= 202011)
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vdmaxmagi))                   \
    match(construct = {dispatch}, device = {arch(gen)})                        \
        append_args(interop(prefer_type("sycl", "level_zero"), targetsync))    \
            adjust_args(need_device_ptr                                        \
                        : a) adjust_args(need_device_ptr                       \
                                         : b) adjust_args(need_device_ptr      \
                                                          : y)
#endif
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vdmaxmagi))                   \
    match(construct = {target variant dispatch}, device = {arch(gen)})
void vdMaxMagI(const MKL_INT n, const double* a, MKL_INT inca, const double* b,
               MKL_INT incb, double* y, MKL_INT incy) NOTHROW;

#if (_OPENMP >= 202011)
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vmdmaxmag))                   \
    match(construct = {dispatch}, device = {arch(gen)})                        \
        append_args(interop(prefer_type("sycl", "level_zero"), targetsync))    \
            adjust_args(need_device_ptr                                        \
                        : a) adjust_args(need_device_ptr                       \
                                         : b) adjust_args(need_device_ptr      \
                                                          : y)
#endif
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vmdmaxmag))                   \
    match(construct = {target variant dispatch}, device = {arch(gen)})
void vmdMaxMag(const MKL_INT n, const double* a, const double* b, double* y,
               MKL_INT64 mode) NOTHROW;

#if (_OPENMP >= 202011)
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vmdmaxmagi))                  \
    match(construct = {dispatch}, device = {arch(gen)})                        \
        append_args(interop(prefer_type("sycl", "level_zero"), targetsync))    \
            adjust_args(need_device_ptr                                        \
                        : a) adjust_args(need_device_ptr                       \
                                         : b) adjust_args(need_device_ptr      \
                                                          : y)
#endif
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vmdmaxmagi))                  \
    match(construct = {target variant dispatch}, device = {arch(gen)})
void vmdMaxMagI(const MKL_INT n, const double* a, MKL_INT inca, const double* b,
                MKL_INT incb, double* y, MKL_INT incy, MKL_INT64 mode) NOTHROW;

// function minmag
#if (_OPENMP >= 202011)
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vsminmag))                    \
    match(construct = {dispatch}, device = {arch(gen)})                        \
        append_args(interop(prefer_type("sycl", "level_zero"), targetsync))    \
            adjust_args(need_device_ptr                                        \
                        : a) adjust_args(need_device_ptr                       \
                                         : b) adjust_args(need_device_ptr      \
                                                          : y)
#endif
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vsminmag))                    \
    match(construct = {target variant dispatch}, device = {arch(gen)})
void vsMinMag(const MKL_INT n, const float* a, const float* b,
              float* y) NOTHROW;

#if (_OPENMP >= 202011)
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vsminmagi))                   \
    match(construct = {dispatch}, device = {arch(gen)})                        \
        append_args(interop(prefer_type("sycl", "level_zero"), targetsync))    \
            adjust_args(need_device_ptr                                        \
                        : a) adjust_args(need_device_ptr                       \
                                         : b) adjust_args(need_device_ptr      \
                                                          : y)
#endif
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vsminmagi))                   \
    match(construct = {target variant dispatch}, device = {arch(gen)})
void vsMinMagI(const MKL_INT n, const float* a, MKL_INT inca, const float* b,
               MKL_INT incb, float* y, MKL_INT incy) NOTHROW;

#if (_OPENMP >= 202011)
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vmsminmag))                   \
    match(construct = {dispatch}, device = {arch(gen)})                        \
        append_args(interop(prefer_type("sycl", "level_zero"), targetsync))    \
            adjust_args(need_device_ptr                                        \
                        : a) adjust_args(need_device_ptr                       \
                                         : b) adjust_args(need_device_ptr      \
                                                          : y)
#endif
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vmsminmag))                   \
    match(construct = {target variant dispatch}, device = {arch(gen)})
void vmsMinMag(const MKL_INT n, const float* a, const float* b, float* y,
               MKL_INT64 mode) NOTHROW;

#if (_OPENMP >= 202011)
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vmsminmagi))                  \
    match(construct = {dispatch}, device = {arch(gen)})                        \
        append_args(interop(prefer_type("sycl", "level_zero"), targetsync))    \
            adjust_args(need_device_ptr                                        \
                        : a) adjust_args(need_device_ptr                       \
                                         : b) adjust_args(need_device_ptr      \
                                                          : y)
#endif
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vmsminmagi))                  \
    match(construct = {target variant dispatch}, device = {arch(gen)})
void vmsMinMagI(const MKL_INT n, const float* a, MKL_INT inca, const float* b,
                MKL_INT incb, float* y, MKL_INT incy, MKL_INT64 mode) NOTHROW;

#if (_OPENMP >= 202011)
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vdminmag))                    \
    match(construct = {dispatch}, device = {arch(gen)})                        \
        append_args(interop(prefer_type("sycl", "level_zero"), targetsync))    \
            adjust_args(need_device_ptr                                        \
                        : a) adjust_args(need_device_ptr                       \
                                         : b) adjust_args(need_device_ptr      \
                                                          : y)
#endif
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vdminmag))                    \
    match(construct = {target variant dispatch}, device = {arch(gen)})
void vdMinMag(const MKL_INT n, const double* a, const double* b,
              double* y) NOTHROW;

#if (_OPENMP >= 202011)
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vdminmagi))                   \
    match(construct = {dispatch}, device = {arch(gen)})                        \
        append_args(interop(prefer_type("sycl", "level_zero"), targetsync))    \
            adjust_args(need_device_ptr                                        \
                        : a) adjust_args(need_device_ptr                       \
                                         : b) adjust_args(need_device_ptr      \
                                                          : y)
#endif
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vdminmagi))                   \
    match(construct = {target variant dispatch}, device = {arch(gen)})
void vdMinMagI(const MKL_INT n, const double* a, MKL_INT inca, const double* b,
               MKL_INT incb, double* y, MKL_INT incy) NOTHROW;

#if (_OPENMP >= 202011)
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vmdminmag))                   \
    match(construct = {dispatch}, device = {arch(gen)})                        \
        append_args(interop(prefer_type("sycl", "level_zero"), targetsync))    \
            adjust_args(need_device_ptr                                        \
                        : a) adjust_args(need_device_ptr                       \
                                         : b) adjust_args(need_device_ptr      \
                                                          : y)
#endif
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vmdminmag))                   \
    match(construct = {target variant dispatch}, device = {arch(gen)})
void vmdMinMag(const MKL_INT n, const double* a, const double* b, double* y,
               MKL_INT64 mode) NOTHROW;

#if (_OPENMP >= 202011)
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vmdminmagi))                  \
    match(construct = {dispatch}, device = {arch(gen)})                        \
        append_args(interop(prefer_type("sycl", "level_zero"), targetsync))    \
            adjust_args(need_device_ptr                                        \
                        : a) adjust_args(need_device_ptr                       \
                                         : b) adjust_args(need_device_ptr      \
                                                          : y)
#endif
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vmdminmagi))                  \
    match(construct = {target variant dispatch}, device = {arch(gen)})
void vmdMinMagI(const MKL_INT n, const double* a, MKL_INT inca, const double* b,
                MKL_INT incb, double* y, MKL_INT incy, MKL_INT64 mode) NOTHROW;

// function modf
#if (_OPENMP >= 202011)
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vsmodf))                      \
    match(construct = {dispatch}, device = {arch(gen)})                        \
        append_args(interop(prefer_type("sycl", "level_zero"), targetsync))    \
            adjust_args(need_device_ptr                                        \
                        : a) adjust_args(need_device_ptr                       \
                                         : y) adjust_args(need_device_ptr      \
                                                          : z)
#endif
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vsmodf))                      \
    match(construct = {target variant dispatch}, device = {arch(gen)})
void vsModf(const MKL_INT n, const float* a, float* y, float* z) NOTHROW;

#if (_OPENMP >= 202011)
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vsmodfi))                     \
    match(construct = {dispatch}, device = {arch(gen)})                        \
        append_args(interop(prefer_type("sycl", "level_zero"), targetsync))    \
            adjust_args(need_device_ptr                                        \
                        : a) adjust_args(need_device_ptr                       \
                                         : y) adjust_args(need_device_ptr      \
                                                          : z)
#endif
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vsmodfi))                     \
    match(construct = {target variant dispatch}, device = {arch(gen)})
void vsModfI(const MKL_INT n, const float* a, MKL_INT inca, float* y,
             MKL_INT incy, float* z, MKL_INT incz) NOTHROW;

#if (_OPENMP >= 202011)
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vmsmodf))                     \
    match(construct = {dispatch}, device = {arch(gen)})                        \
        append_args(interop(prefer_type("sycl", "level_zero"), targetsync))    \
            adjust_args(need_device_ptr                                        \
                        : a) adjust_args(need_device_ptr                       \
                                         : y) adjust_args(need_device_ptr      \
                                                          : z)
#endif
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vmsmodf))                     \
    match(construct = {target variant dispatch}, device = {arch(gen)})
void vmsModf(const MKL_INT n, const float* a, float* y, float* z,
             MKL_INT64 mode) NOTHROW;

#if (_OPENMP >= 202011)
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vmsmodfi))                    \
    match(construct = {dispatch}, device = {arch(gen)})                        \
        append_args(interop(prefer_type("sycl", "level_zero"), targetsync))    \
            adjust_args(need_device_ptr                                        \
                        : a) adjust_args(need_device_ptr                       \
                                         : y) adjust_args(need_device_ptr      \
                                                          : z)
#endif
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vmsmodfi))                    \
    match(construct = {target variant dispatch}, device = {arch(gen)})
void vmsModfI(const MKL_INT n, const float* a, MKL_INT inca, float* y,
              MKL_INT incy, float* z, MKL_INT incz, MKL_INT64 mode) NOTHROW;

#if (_OPENMP >= 202011)
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vdmodf))                      \
    match(construct = {dispatch}, device = {arch(gen)})                        \
        append_args(interop(prefer_type("sycl", "level_zero"), targetsync))    \
            adjust_args(need_device_ptr                                        \
                        : a) adjust_args(need_device_ptr                       \
                                         : y) adjust_args(need_device_ptr      \
                                                          : z)
#endif
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vdmodf))                      \
    match(construct = {target variant dispatch}, device = {arch(gen)})
void vdModf(const MKL_INT n, const double* a, double* y, double* z) NOTHROW;

#if (_OPENMP >= 202011)
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vdmodfi))                     \
    match(construct = {dispatch}, device = {arch(gen)})                        \
        append_args(interop(prefer_type("sycl", "level_zero"), targetsync))    \
            adjust_args(need_device_ptr                                        \
                        : a) adjust_args(need_device_ptr                       \
                                         : y) adjust_args(need_device_ptr      \
                                                          : z)
#endif
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vdmodfi))                     \
    match(construct = {target variant dispatch}, device = {arch(gen)})
void vdModfI(const MKL_INT n, const double* a, MKL_INT inca, double* y,
             MKL_INT incy, double* z, MKL_INT incz) NOTHROW;

#if (_OPENMP >= 202011)
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vmdmodf))                     \
    match(construct = {dispatch}, device = {arch(gen)})                        \
        append_args(interop(prefer_type("sycl", "level_zero"), targetsync))    \
            adjust_args(need_device_ptr                                        \
                        : a) adjust_args(need_device_ptr                       \
                                         : y) adjust_args(need_device_ptr      \
                                                          : z)
#endif
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vmdmodf))                     \
    match(construct = {target variant dispatch}, device = {arch(gen)})
void vmdModf(const MKL_INT n, const double* a, double* y, double* z,
             MKL_INT64 mode) NOTHROW;

#if (_OPENMP >= 202011)
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vmdmodfi))                    \
    match(construct = {dispatch}, device = {arch(gen)})                        \
        append_args(interop(prefer_type("sycl", "level_zero"), targetsync))    \
            adjust_args(need_device_ptr                                        \
                        : a) adjust_args(need_device_ptr                       \
                                         : y) adjust_args(need_device_ptr      \
                                                          : z)
#endif
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vmdmodfi))                    \
    match(construct = {target variant dispatch}, device = {arch(gen)})
void vmdModfI(const MKL_INT n, const double* a, MKL_INT inca, double* y,
              MKL_INT incy, double* z, MKL_INT incz, MKL_INT64 mode) NOTHROW;

// function mul
#if (_OPENMP >= 202011)
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vsmul))                       \
    match(construct = {dispatch}, device = {arch(gen)})                        \
        append_args(interop(prefer_type("sycl", "level_zero"), targetsync))    \
            adjust_args(need_device_ptr                                        \
                        : a) adjust_args(need_device_ptr                       \
                                         : b) adjust_args(need_device_ptr      \
                                                          : y)
#endif
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vsmul))                       \
    match(construct = {target variant dispatch}, device = {arch(gen)})
void vsMul(const MKL_INT n, const float* a, const float* b, float* y) NOTHROW;

#if (_OPENMP >= 202011)
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vsmuli))                      \
    match(construct = {dispatch}, device = {arch(gen)})                        \
        append_args(interop(prefer_type("sycl", "level_zero"), targetsync))    \
            adjust_args(need_device_ptr                                        \
                        : a) adjust_args(need_device_ptr                       \
                                         : b) adjust_args(need_device_ptr      \
                                                          : y)
#endif
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vsmuli))                      \
    match(construct = {target variant dispatch}, device = {arch(gen)})
void vsMulI(const MKL_INT n, const float* a, MKL_INT inca, const float* b,
            MKL_INT incb, float* y, MKL_INT incy) NOTHROW;

#if (_OPENMP >= 202011)
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vmsmul))                      \
    match(construct = {dispatch}, device = {arch(gen)})                        \
        append_args(interop(prefer_type("sycl", "level_zero"), targetsync))    \
            adjust_args(need_device_ptr                                        \
                        : a) adjust_args(need_device_ptr                       \
                                         : b) adjust_args(need_device_ptr      \
                                                          : y)
#endif
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vmsmul))                      \
    match(construct = {target variant dispatch}, device = {arch(gen)})
void vmsMul(const MKL_INT n, const float* a, const float* b, float* y,
            MKL_INT64 mode) NOTHROW;

#if (_OPENMP >= 202011)
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vmsmuli))                     \
    match(construct = {dispatch}, device = {arch(gen)})                        \
        append_args(interop(prefer_type("sycl", "level_zero"), targetsync))    \
            adjust_args(need_device_ptr                                        \
                        : a) adjust_args(need_device_ptr                       \
                                         : b) adjust_args(need_device_ptr      \
                                                          : y)
#endif
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vmsmuli))                     \
    match(construct = {target variant dispatch}, device = {arch(gen)})
void vmsMulI(const MKL_INT n, const float* a, MKL_INT inca, const float* b,
             MKL_INT incb, float* y, MKL_INT incy, MKL_INT64 mode) NOTHROW;

#if (_OPENMP >= 202011)
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vdmul))                       \
    match(construct = {dispatch}, device = {arch(gen)})                        \
        append_args(interop(prefer_type("sycl", "level_zero"), targetsync))    \
            adjust_args(need_device_ptr                                        \
                        : a) adjust_args(need_device_ptr                       \
                                         : b) adjust_args(need_device_ptr      \
                                                          : y)
#endif
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vdmul))                       \
    match(construct = {target variant dispatch}, device = {arch(gen)})
void vdMul(const MKL_INT n, const double* a, const double* b,
           double* y) NOTHROW;

#if (_OPENMP >= 202011)
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vdmuli))                      \
    match(construct = {dispatch}, device = {arch(gen)})                        \
        append_args(interop(prefer_type("sycl", "level_zero"), targetsync))    \
            adjust_args(need_device_ptr                                        \
                        : a) adjust_args(need_device_ptr                       \
                                         : b) adjust_args(need_device_ptr      \
                                                          : y)
#endif
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vdmuli))                      \
    match(construct = {target variant dispatch}, device = {arch(gen)})
void vdMulI(const MKL_INT n, const double* a, MKL_INT inca, const double* b,
            MKL_INT incb, double* y, MKL_INT incy) NOTHROW;

#if (_OPENMP >= 202011)
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vmdmul))                      \
    match(construct = {dispatch}, device = {arch(gen)})                        \
        append_args(interop(prefer_type("sycl", "level_zero"), targetsync))    \
            adjust_args(need_device_ptr                                        \
                        : a) adjust_args(need_device_ptr                       \
                                         : b) adjust_args(need_device_ptr      \
                                                          : y)
#endif
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vmdmul))                      \
    match(construct = {target variant dispatch}, device = {arch(gen)})
void vmdMul(const MKL_INT n, const double* a, const double* b, double* y,
            MKL_INT64 mode) NOTHROW;

#if (_OPENMP >= 202011)
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vmdmuli))                     \
    match(construct = {dispatch}, device = {arch(gen)})                        \
        append_args(interop(prefer_type("sycl", "level_zero"), targetsync))    \
            adjust_args(need_device_ptr                                        \
                        : a) adjust_args(need_device_ptr                       \
                                         : b) adjust_args(need_device_ptr      \
                                                          : y)
#endif
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vmdmuli))                     \
    match(construct = {target variant dispatch}, device = {arch(gen)})
void vmdMulI(const MKL_INT n, const double* a, MKL_INT inca, const double* b,
             MKL_INT incb, double* y, MKL_INT incy, MKL_INT64 mode) NOTHROW;

#if (_OPENMP >= 202011)
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vcmul))                       \
    match(construct = {dispatch}, device = {arch(gen)})                        \
        append_args(interop(prefer_type("sycl", "level_zero"), targetsync))    \
            adjust_args(need_device_ptr                                        \
                        : a) adjust_args(need_device_ptr                       \
                                         : b) adjust_args(need_device_ptr      \
                                                          : y)
#endif
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vcmul))                       \
    match(construct = {target variant dispatch}, device = {arch(gen)})
void vcMul(const MKL_INT n, const MKL_Complex8* a, const MKL_Complex8* b,
           MKL_Complex8* y) NOTHROW;

#if (_OPENMP >= 202011)
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vcmuli))                      \
    match(construct = {dispatch}, device = {arch(gen)})                        \
        append_args(interop(prefer_type("sycl", "level_zero"), targetsync))    \
            adjust_args(need_device_ptr                                        \
                        : a) adjust_args(need_device_ptr                       \
                                         : b) adjust_args(need_device_ptr      \
                                                          : y)
#endif
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vcmuli))                      \
    match(construct = {target variant dispatch}, device = {arch(gen)})
void vcMulI(const MKL_INT n, const MKL_Complex8* a, MKL_INT inca,
            const MKL_Complex8* b, MKL_INT incb, MKL_Complex8* y,
            MKL_INT incy) NOTHROW;

#if (_OPENMP >= 202011)
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vmcmul))                      \
    match(construct = {dispatch}, device = {arch(gen)})                        \
        append_args(interop(prefer_type("sycl", "level_zero"), targetsync))    \
            adjust_args(need_device_ptr                                        \
                        : a) adjust_args(need_device_ptr                       \
                                         : b) adjust_args(need_device_ptr      \
                                                          : y)
#endif
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vmcmul))                      \
    match(construct = {target variant dispatch}, device = {arch(gen)})
void vmcMul(const MKL_INT n, const MKL_Complex8* a, const MKL_Complex8* b,
            MKL_Complex8* y, MKL_INT64 mode) NOTHROW;

#if (_OPENMP >= 202011)
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vmcmuli))                     \
    match(construct = {dispatch}, device = {arch(gen)})                        \
        append_args(interop(prefer_type("sycl", "level_zero"), targetsync))    \
            adjust_args(need_device_ptr                                        \
                        : a) adjust_args(need_device_ptr                       \
                                         : b) adjust_args(need_device_ptr      \
                                                          : y)
#endif
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vmcmuli))                     \
    match(construct = {target variant dispatch}, device = {arch(gen)})
void vmcMulI(const MKL_INT n, const MKL_Complex8* a, MKL_INT inca,
             const MKL_Complex8* b, MKL_INT incb, MKL_Complex8* y, MKL_INT incy,
             MKL_INT64 mode) NOTHROW;

#if (_OPENMP >= 202011)
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vzmul))                       \
    match(construct = {dispatch}, device = {arch(gen)})                        \
        append_args(interop(prefer_type("sycl", "level_zero"), targetsync))    \
            adjust_args(need_device_ptr                                        \
                        : a) adjust_args(need_device_ptr                       \
                                         : b) adjust_args(need_device_ptr      \
                                                          : y)
#endif
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vzmul))                       \
    match(construct = {target variant dispatch}, device = {arch(gen)})
void vzMul(const MKL_INT n, const MKL_Complex16* a, const MKL_Complex16* b,
           MKL_Complex16* y) NOTHROW;

#if (_OPENMP >= 202011)
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vzmuli))                      \
    match(construct = {dispatch}, device = {arch(gen)})                        \
        append_args(interop(prefer_type("sycl", "level_zero"), targetsync))    \
            adjust_args(need_device_ptr                                        \
                        : a) adjust_args(need_device_ptr                       \
                                         : b) adjust_args(need_device_ptr      \
                                                          : y)
#endif
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vzmuli))                      \
    match(construct = {target variant dispatch}, device = {arch(gen)})
void vzMulI(const MKL_INT n, const MKL_Complex16* a, MKL_INT inca,
            const MKL_Complex16* b, MKL_INT incb, MKL_Complex16* y,
            MKL_INT incy) NOTHROW;

#if (_OPENMP >= 202011)
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vmzmul))                      \
    match(construct = {dispatch}, device = {arch(gen)})                        \
        append_args(interop(prefer_type("sycl", "level_zero"), targetsync))    \
            adjust_args(need_device_ptr                                        \
                        : a) adjust_args(need_device_ptr                       \
                                         : b) adjust_args(need_device_ptr      \
                                                          : y)
#endif
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vmzmul))                      \
    match(construct = {target variant dispatch}, device = {arch(gen)})
void vmzMul(const MKL_INT n, const MKL_Complex16* a, const MKL_Complex16* b,
            MKL_Complex16* y, MKL_INT64 mode) NOTHROW;

#if (_OPENMP >= 202011)
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vmzmuli))                     \
    match(construct = {dispatch}, device = {arch(gen)})                        \
        append_args(interop(prefer_type("sycl", "level_zero"), targetsync))    \
            adjust_args(need_device_ptr                                        \
                        : a) adjust_args(need_device_ptr                       \
                                         : b) adjust_args(need_device_ptr      \
                                                          : y)
#endif
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vmzmuli))                     \
    match(construct = {target variant dispatch}, device = {arch(gen)})
void vmzMulI(const MKL_INT n, const MKL_Complex16* a, MKL_INT inca,
             const MKL_Complex16* b, MKL_INT incb, MKL_Complex16* y,
             MKL_INT incy, MKL_INT64 mode) NOTHROW;

// function mulbyconj
#if (_OPENMP >= 202011)
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vcmulbyconj))                 \
    match(construct = {dispatch}, device = {arch(gen)})                        \
        append_args(interop(prefer_type("sycl", "level_zero"), targetsync))    \
            adjust_args(need_device_ptr                                        \
                        : a) adjust_args(need_device_ptr                       \
                                         : b) adjust_args(need_device_ptr      \
                                                          : y)
#endif
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vcmulbyconj))                 \
    match(construct = {target variant dispatch}, device = {arch(gen)})
void vcMulByConj(const MKL_INT n, const MKL_Complex8* a, const MKL_Complex8* b,
                 MKL_Complex8* y) NOTHROW;

#if (_OPENMP >= 202011)
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vcmulbyconji))                \
    match(construct = {dispatch}, device = {arch(gen)})                        \
        append_args(interop(prefer_type("sycl", "level_zero"), targetsync))    \
            adjust_args(need_device_ptr                                        \
                        : a) adjust_args(need_device_ptr                       \
                                         : b) adjust_args(need_device_ptr      \
                                                          : y)
#endif
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vcmulbyconji))                \
    match(construct = {target variant dispatch}, device = {arch(gen)})
void vcMulByConjI(const MKL_INT n, const MKL_Complex8* a, MKL_INT inca,
                  const MKL_Complex8* b, MKL_INT incb, MKL_Complex8* y,
                  MKL_INT incy) NOTHROW;

#if (_OPENMP >= 202011)
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vmcmulbyconj))                \
    match(construct = {dispatch}, device = {arch(gen)})                        \
        append_args(interop(prefer_type("sycl", "level_zero"), targetsync))    \
            adjust_args(need_device_ptr                                        \
                        : a) adjust_args(need_device_ptr                       \
                                         : b) adjust_args(need_device_ptr      \
                                                          : y)
#endif
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vmcmulbyconj))                \
    match(construct = {target variant dispatch}, device = {arch(gen)})
void vmcMulByConj(const MKL_INT n, const MKL_Complex8* a, const MKL_Complex8* b,
                  MKL_Complex8* y, MKL_INT64 mode) NOTHROW;

#if (_OPENMP >= 202011)
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vmcmulbyconji))               \
    match(construct = {dispatch}, device = {arch(gen)})                        \
        append_args(interop(prefer_type("sycl", "level_zero"), targetsync))    \
            adjust_args(need_device_ptr                                        \
                        : a) adjust_args(need_device_ptr                       \
                                         : b) adjust_args(need_device_ptr      \
                                                          : y)
#endif
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vmcmulbyconji))               \
    match(construct = {target variant dispatch}, device = {arch(gen)})
void vmcMulByConjI(const MKL_INT n, const MKL_Complex8* a, MKL_INT inca,
                   const MKL_Complex8* b, MKL_INT incb, MKL_Complex8* y,
                   MKL_INT incy, MKL_INT64 mode) NOTHROW;

#if (_OPENMP >= 202011)
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vzmulbyconj))                 \
    match(construct = {dispatch}, device = {arch(gen)})                        \
        append_args(interop(prefer_type("sycl", "level_zero"), targetsync))    \
            adjust_args(need_device_ptr                                        \
                        : a) adjust_args(need_device_ptr                       \
                                         : b) adjust_args(need_device_ptr      \
                                                          : y)
#endif
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vzmulbyconj))                 \
    match(construct = {target variant dispatch}, device = {arch(gen)})
void vzMulByConj(const MKL_INT n, const MKL_Complex16* a,
                 const MKL_Complex16* b, MKL_Complex16* y) NOTHROW;

#if (_OPENMP >= 202011)
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vzmulbyconji))                \
    match(construct = {dispatch}, device = {arch(gen)})                        \
        append_args(interop(prefer_type("sycl", "level_zero"), targetsync))    \
            adjust_args(need_device_ptr                                        \
                        : a) adjust_args(need_device_ptr                       \
                                         : b) adjust_args(need_device_ptr      \
                                                          : y)
#endif
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vzmulbyconji))                \
    match(construct = {target variant dispatch}, device = {arch(gen)})
void vzMulByConjI(const MKL_INT n, const MKL_Complex16* a, MKL_INT inca,
                  const MKL_Complex16* b, MKL_INT incb, MKL_Complex16* y,
                  MKL_INT incy) NOTHROW;

#if (_OPENMP >= 202011)
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vmzmulbyconj))                \
    match(construct = {dispatch}, device = {arch(gen)})                        \
        append_args(interop(prefer_type("sycl", "level_zero"), targetsync))    \
            adjust_args(need_device_ptr                                        \
                        : a) adjust_args(need_device_ptr                       \
                                         : b) adjust_args(need_device_ptr      \
                                                          : y)
#endif
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vmzmulbyconj))                \
    match(construct = {target variant dispatch}, device = {arch(gen)})
void vmzMulByConj(const MKL_INT n, const MKL_Complex16* a,
                  const MKL_Complex16* b, MKL_Complex16* y,
                  MKL_INT64 mode) NOTHROW;

#if (_OPENMP >= 202011)
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vmzmulbyconji))               \
    match(construct = {dispatch}, device = {arch(gen)})                        \
        append_args(interop(prefer_type("sycl", "level_zero"), targetsync))    \
            adjust_args(need_device_ptr                                        \
                        : a) adjust_args(need_device_ptr                       \
                                         : b) adjust_args(need_device_ptr      \
                                                          : y)
#endif
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vmzmulbyconji))               \
    match(construct = {target variant dispatch}, device = {arch(gen)})
void vmzMulByConjI(const MKL_INT n, const MKL_Complex16* a, MKL_INT inca,
                   const MKL_Complex16* b, MKL_INT incb, MKL_Complex16* y,
                   MKL_INT incy, MKL_INT64 mode) NOTHROW;

// function nearbyint
#if (_OPENMP >= 202011)
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vsnearbyint))                 \
    match(construct = {dispatch}, device = {arch(gen)})                        \
        append_args(interop(prefer_type("sycl", "level_zero"), targetsync))    \
            adjust_args(need_device_ptr                                        \
                        : a) adjust_args(need_device_ptr                       \
                                         : y)
#endif
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vsnearbyint))                 \
    match(construct = {target variant dispatch}, device = {arch(gen)})
void vsNearbyInt(const MKL_INT n, const float* a, float* y) NOTHROW;

#if (_OPENMP >= 202011)
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vsnearbyinti))                \
    match(construct = {dispatch}, device = {arch(gen)})                        \
        append_args(interop(prefer_type("sycl", "level_zero"), targetsync))    \
            adjust_args(need_device_ptr                                        \
                        : a) adjust_args(need_device_ptr                       \
                                         : y)
#endif
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vsnearbyinti))                \
    match(construct = {target variant dispatch}, device = {arch(gen)})
void vsNearbyIntI(const MKL_INT n, const float* a, MKL_INT inca, float* y,
                  MKL_INT incy) NOTHROW;

#if (_OPENMP >= 202011)
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vmsnearbyint))                \
    match(construct = {dispatch}, device = {arch(gen)})                        \
        append_args(interop(prefer_type("sycl", "level_zero"), targetsync))    \
            adjust_args(need_device_ptr                                        \
                        : a) adjust_args(need_device_ptr                       \
                                         : y)
#endif
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vmsnearbyint))                \
    match(construct = {target variant dispatch}, device = {arch(gen)})
void vmsNearbyInt(const MKL_INT n, const float* a, float* y,
                  MKL_INT64 mode) NOTHROW;

#if (_OPENMP >= 202011)
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vmsnearbyinti))               \
    match(construct = {dispatch}, device = {arch(gen)})                        \
        append_args(interop(prefer_type("sycl", "level_zero"), targetsync))    \
            adjust_args(need_device_ptr                                        \
                        : a) adjust_args(need_device_ptr                       \
                                         : y)
#endif
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vmsnearbyinti))               \
    match(construct = {target variant dispatch}, device = {arch(gen)})
void vmsNearbyIntI(const MKL_INT n, const float* a, MKL_INT inca, float* y,
                   MKL_INT incy, MKL_INT64 mode) NOTHROW;

#if (_OPENMP >= 202011)
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vdnearbyint))                 \
    match(construct = {dispatch}, device = {arch(gen)})                        \
        append_args(interop(prefer_type("sycl", "level_zero"), targetsync))    \
            adjust_args(need_device_ptr                                        \
                        : a) adjust_args(need_device_ptr                       \
                                         : y)
#endif
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vdnearbyint))                 \
    match(construct = {target variant dispatch}, device = {arch(gen)})
void vdNearbyInt(const MKL_INT n, const double* a, double* y) NOTHROW;

#if (_OPENMP >= 202011)
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vdnearbyinti))                \
    match(construct = {dispatch}, device = {arch(gen)})                        \
        append_args(interop(prefer_type("sycl", "level_zero"), targetsync))    \
            adjust_args(need_device_ptr                                        \
                        : a) adjust_args(need_device_ptr                       \
                                         : y)
#endif
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vdnearbyinti))                \
    match(construct = {target variant dispatch}, device = {arch(gen)})
void vdNearbyIntI(const MKL_INT n, const double* a, MKL_INT inca, double* y,
                  MKL_INT incy) NOTHROW;

#if (_OPENMP >= 202011)
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vmdnearbyint))                \
    match(construct = {dispatch}, device = {arch(gen)})                        \
        append_args(interop(prefer_type("sycl", "level_zero"), targetsync))    \
            adjust_args(need_device_ptr                                        \
                        : a) adjust_args(need_device_ptr                       \
                                         : y)
#endif
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vmdnearbyint))                \
    match(construct = {target variant dispatch}, device = {arch(gen)})
void vmdNearbyInt(const MKL_INT n, const double* a, double* y,
                  MKL_INT64 mode) NOTHROW;

#if (_OPENMP >= 202011)
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vmdnearbyinti))               \
    match(construct = {dispatch}, device = {arch(gen)})                        \
        append_args(interop(prefer_type("sycl", "level_zero"), targetsync))    \
            adjust_args(need_device_ptr                                        \
                        : a) adjust_args(need_device_ptr                       \
                                         : y)
#endif
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vmdnearbyinti))               \
    match(construct = {target variant dispatch}, device = {arch(gen)})
void vmdNearbyIntI(const MKL_INT n, const double* a, MKL_INT inca, double* y,
                   MKL_INT incy, MKL_INT64 mode) NOTHROW;

// function nextafter
#if (_OPENMP >= 202011)
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vsnextafter))                 \
    match(construct = {dispatch}, device = {arch(gen)})                        \
        append_args(interop(prefer_type("sycl", "level_zero"), targetsync))    \
            adjust_args(need_device_ptr                                        \
                        : a) adjust_args(need_device_ptr                       \
                                         : b) adjust_args(need_device_ptr      \
                                                          : y)
#endif
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vsnextafter))                 \
    match(construct = {target variant dispatch}, device = {arch(gen)})
void vsNextAfter(const MKL_INT n, const float* a, const float* b,
                 float* y) NOTHROW;

#if (_OPENMP >= 202011)
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vsnextafteri))                \
    match(construct = {dispatch}, device = {arch(gen)})                        \
        append_args(interop(prefer_type("sycl", "level_zero"), targetsync))    \
            adjust_args(need_device_ptr                                        \
                        : a) adjust_args(need_device_ptr                       \
                                         : b) adjust_args(need_device_ptr      \
                                                          : y)
#endif
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vsnextafteri))                \
    match(construct = {target variant dispatch}, device = {arch(gen)})
void vsNextAfterI(const MKL_INT n, const float* a, MKL_INT inca, const float* b,
                  MKL_INT incb, float* y, MKL_INT incy) NOTHROW;

#if (_OPENMP >= 202011)
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vmsnextafter))                \
    match(construct = {dispatch}, device = {arch(gen)})                        \
        append_args(interop(prefer_type("sycl", "level_zero"), targetsync))    \
            adjust_args(need_device_ptr                                        \
                        : a) adjust_args(need_device_ptr                       \
                                         : b) adjust_args(need_device_ptr      \
                                                          : y)
#endif
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vmsnextafter))                \
    match(construct = {target variant dispatch}, device = {arch(gen)})
void vmsNextAfter(const MKL_INT n, const float* a, const float* b, float* y,
                  MKL_INT64 mode) NOTHROW;

#if (_OPENMP >= 202011)
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vmsnextafteri))               \
    match(construct = {dispatch}, device = {arch(gen)})                        \
        append_args(interop(prefer_type("sycl", "level_zero"), targetsync))    \
            adjust_args(need_device_ptr                                        \
                        : a) adjust_args(need_device_ptr                       \
                                         : b) adjust_args(need_device_ptr      \
                                                          : y)
#endif
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vmsnextafteri))               \
    match(construct = {target variant dispatch}, device = {arch(gen)})
void vmsNextAfterI(const MKL_INT n, const float* a, MKL_INT inca,
                   const float* b, MKL_INT incb, float* y, MKL_INT incy,
                   MKL_INT64 mode) NOTHROW;

#if (_OPENMP >= 202011)
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vdnextafter))                 \
    match(construct = {dispatch}, device = {arch(gen)})                        \
        append_args(interop(prefer_type("sycl", "level_zero"), targetsync))    \
            adjust_args(need_device_ptr                                        \
                        : a) adjust_args(need_device_ptr                       \
                                         : b) adjust_args(need_device_ptr      \
                                                          : y)
#endif
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vdnextafter))                 \
    match(construct = {target variant dispatch}, device = {arch(gen)})
void vdNextAfter(const MKL_INT n, const double* a, const double* b,
                 double* y) NOTHROW;

#if (_OPENMP >= 202011)
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vdnextafteri))                \
    match(construct = {dispatch}, device = {arch(gen)})                        \
        append_args(interop(prefer_type("sycl", "level_zero"), targetsync))    \
            adjust_args(need_device_ptr                                        \
                        : a) adjust_args(need_device_ptr                       \
                                         : b) adjust_args(need_device_ptr      \
                                                          : y)
#endif
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vdnextafteri))                \
    match(construct = {target variant dispatch}, device = {arch(gen)})
void vdNextAfterI(const MKL_INT n, const double* a, MKL_INT inca,
                  const double* b, MKL_INT incb, double* y,
                  MKL_INT incy) NOTHROW;

#if (_OPENMP >= 202011)
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vmdnextafter))                \
    match(construct = {dispatch}, device = {arch(gen)})                        \
        append_args(interop(prefer_type("sycl", "level_zero"), targetsync))    \
            adjust_args(need_device_ptr                                        \
                        : a) adjust_args(need_device_ptr                       \
                                         : b) adjust_args(need_device_ptr      \
                                                          : y)
#endif
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vmdnextafter))                \
    match(construct = {target variant dispatch}, device = {arch(gen)})
void vmdNextAfter(const MKL_INT n, const double* a, const double* b, double* y,
                  MKL_INT64 mode) NOTHROW;

#if (_OPENMP >= 202011)
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vmdnextafteri))               \
    match(construct = {dispatch}, device = {arch(gen)})                        \
        append_args(interop(prefer_type("sycl", "level_zero"), targetsync))    \
            adjust_args(need_device_ptr                                        \
                        : a) adjust_args(need_device_ptr                       \
                                         : b) adjust_args(need_device_ptr      \
                                                          : y)
#endif
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vmdnextafteri))               \
    match(construct = {target variant dispatch}, device = {arch(gen)})
void vmdNextAfterI(const MKL_INT n, const double* a, MKL_INT inca,
                   const double* b, MKL_INT incb, double* y, MKL_INT incy,
                   MKL_INT64 mode) NOTHROW;

// function pow
#if (_OPENMP >= 202011)
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vspow))                       \
    match(construct = {dispatch}, device = {arch(gen)})                        \
        append_args(interop(prefer_type("sycl", "level_zero"), targetsync))    \
            adjust_args(need_device_ptr                                        \
                        : a) adjust_args(need_device_ptr                       \
                                         : b) adjust_args(need_device_ptr      \
                                                          : y)
#endif
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vspow))                       \
    match(construct = {target variant dispatch}, device = {arch(gen)})
void vsPow(const MKL_INT n, const float* a, const float* b, float* y) NOTHROW;

#if (_OPENMP >= 202011)
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vspowi))                      \
    match(construct = {dispatch}, device = {arch(gen)})                        \
        append_args(interop(prefer_type("sycl", "level_zero"), targetsync))    \
            adjust_args(need_device_ptr                                        \
                        : a) adjust_args(need_device_ptr                       \
                                         : b) adjust_args(need_device_ptr      \
                                                          : y)
#endif
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vspowi))                      \
    match(construct = {target variant dispatch}, device = {arch(gen)})
void vsPowI(const MKL_INT n, const float* a, MKL_INT inca, const float* b,
            MKL_INT incb, float* y, MKL_INT incy) NOTHROW;

#if (_OPENMP >= 202011)
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vmspow))                      \
    match(construct = {dispatch}, device = {arch(gen)})                        \
        append_args(interop(prefer_type("sycl", "level_zero"), targetsync))    \
            adjust_args(need_device_ptr                                        \
                        : a) adjust_args(need_device_ptr                       \
                                         : b) adjust_args(need_device_ptr      \
                                                          : y)
#endif
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vmspow))                      \
    match(construct = {target variant dispatch}, device = {arch(gen)})
void vmsPow(const MKL_INT n, const float* a, const float* b, float* y,
            MKL_INT64 mode) NOTHROW;

#if (_OPENMP >= 202011)
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vmspowi))                     \
    match(construct = {dispatch}, device = {arch(gen)})                        \
        append_args(interop(prefer_type("sycl", "level_zero"), targetsync))    \
            adjust_args(need_device_ptr                                        \
                        : a) adjust_args(need_device_ptr                       \
                                         : b) adjust_args(need_device_ptr      \
                                                          : y)
#endif
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vmspowi))                     \
    match(construct = {target variant dispatch}, device = {arch(gen)})
void vmsPowI(const MKL_INT n, const float* a, MKL_INT inca, const float* b,
             MKL_INT incb, float* y, MKL_INT incy, MKL_INT64 mode) NOTHROW;

#if (_OPENMP >= 202011)
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vdpow))                       \
    match(construct = {dispatch}, device = {arch(gen)})                        \
        append_args(interop(prefer_type("sycl", "level_zero"), targetsync))    \
            adjust_args(need_device_ptr                                        \
                        : a) adjust_args(need_device_ptr                       \
                                         : b) adjust_args(need_device_ptr      \
                                                          : y)
#endif
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vdpow))                       \
    match(construct = {target variant dispatch}, device = {arch(gen)})
void vdPow(const MKL_INT n, const double* a, const double* b,
           double* y) NOTHROW;

#if (_OPENMP >= 202011)
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vdpowi))                      \
    match(construct = {dispatch}, device = {arch(gen)})                        \
        append_args(interop(prefer_type("sycl", "level_zero"), targetsync))    \
            adjust_args(need_device_ptr                                        \
                        : a) adjust_args(need_device_ptr                       \
                                         : b) adjust_args(need_device_ptr      \
                                                          : y)
#endif
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vdpowi))                      \
    match(construct = {target variant dispatch}, device = {arch(gen)})
void vdPowI(const MKL_INT n, const double* a, MKL_INT inca, const double* b,
            MKL_INT incb, double* y, MKL_INT incy) NOTHROW;

#if (_OPENMP >= 202011)
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vmdpow))                      \
    match(construct = {dispatch}, device = {arch(gen)})                        \
        append_args(interop(prefer_type("sycl", "level_zero"), targetsync))    \
            adjust_args(need_device_ptr                                        \
                        : a) adjust_args(need_device_ptr                       \
                                         : b) adjust_args(need_device_ptr      \
                                                          : y)
#endif
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vmdpow))                      \
    match(construct = {target variant dispatch}, device = {arch(gen)})
void vmdPow(const MKL_INT n, const double* a, const double* b, double* y,
            MKL_INT64 mode) NOTHROW;

#if (_OPENMP >= 202011)
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vmdpowi))                     \
    match(construct = {dispatch}, device = {arch(gen)})                        \
        append_args(interop(prefer_type("sycl", "level_zero"), targetsync))    \
            adjust_args(need_device_ptr                                        \
                        : a) adjust_args(need_device_ptr                       \
                                         : b) adjust_args(need_device_ptr      \
                                                          : y)
#endif
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vmdpowi))                     \
    match(construct = {target variant dispatch}, device = {arch(gen)})
void vmdPowI(const MKL_INT n, const double* a, MKL_INT inca, const double* b,
             MKL_INT incb, double* y, MKL_INT incy, MKL_INT64 mode) NOTHROW;

#if (_OPENMP >= 202011)
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vcpow))                       \
    match(construct = {dispatch}, device = {arch(gen)})                        \
        append_args(interop(prefer_type("sycl", "level_zero"), targetsync))    \
            adjust_args(need_device_ptr                                        \
                        : a) adjust_args(need_device_ptr                       \
                                         : b) adjust_args(need_device_ptr      \
                                                          : y)
#endif
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vcpow))                       \
    match(construct = {target variant dispatch}, device = {arch(gen)})
void vcPow(const MKL_INT n, const MKL_Complex8* a, const MKL_Complex8* b,
           MKL_Complex8* y) NOTHROW;

#if (_OPENMP >= 202011)
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vcpowi))                      \
    match(construct = {dispatch}, device = {arch(gen)})                        \
        append_args(interop(prefer_type("sycl", "level_zero"), targetsync))    \
            adjust_args(need_device_ptr                                        \
                        : a) adjust_args(need_device_ptr                       \
                                         : b) adjust_args(need_device_ptr      \
                                                          : y)
#endif
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vcpowi))                      \
    match(construct = {target variant dispatch}, device = {arch(gen)})
void vcPowI(const MKL_INT n, const MKL_Complex8* a, MKL_INT inca,
            const MKL_Complex8* b, MKL_INT incb, MKL_Complex8* y,
            MKL_INT incy) NOTHROW;

#if (_OPENMP >= 202011)
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vmcpow))                      \
    match(construct = {dispatch}, device = {arch(gen)})                        \
        append_args(interop(prefer_type("sycl", "level_zero"), targetsync))    \
            adjust_args(need_device_ptr                                        \
                        : a) adjust_args(need_device_ptr                       \
                                         : b) adjust_args(need_device_ptr      \
                                                          : y)
#endif
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vmcpow))                      \
    match(construct = {target variant dispatch}, device = {arch(gen)})
void vmcPow(const MKL_INT n, const MKL_Complex8* a, const MKL_Complex8* b,
            MKL_Complex8* y, MKL_INT64 mode) NOTHROW;

#if (_OPENMP >= 202011)
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vmcpowi))                     \
    match(construct = {dispatch}, device = {arch(gen)})                        \
        append_args(interop(prefer_type("sycl", "level_zero"), targetsync))    \
            adjust_args(need_device_ptr                                        \
                        : a) adjust_args(need_device_ptr                       \
                                         : b) adjust_args(need_device_ptr      \
                                                          : y)
#endif
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vmcpowi))                     \
    match(construct = {target variant dispatch}, device = {arch(gen)})
void vmcPowI(const MKL_INT n, const MKL_Complex8* a, MKL_INT inca,
             const MKL_Complex8* b, MKL_INT incb, MKL_Complex8* y, MKL_INT incy,
             MKL_INT64 mode) NOTHROW;

#if (_OPENMP >= 202011)
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vzpow))                       \
    match(construct = {dispatch}, device = {arch(gen)})                        \
        append_args(interop(prefer_type("sycl", "level_zero"), targetsync))    \
            adjust_args(need_device_ptr                                        \
                        : a) adjust_args(need_device_ptr                       \
                                         : b) adjust_args(need_device_ptr      \
                                                          : y)
#endif
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vzpow))                       \
    match(construct = {target variant dispatch}, device = {arch(gen)})
void vzPow(const MKL_INT n, const MKL_Complex16* a, const MKL_Complex16* b,
           MKL_Complex16* y) NOTHROW;

#if (_OPENMP >= 202011)
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vzpowi))                      \
    match(construct = {dispatch}, device = {arch(gen)})                        \
        append_args(interop(prefer_type("sycl", "level_zero"), targetsync))    \
            adjust_args(need_device_ptr                                        \
                        : a) adjust_args(need_device_ptr                       \
                                         : b) adjust_args(need_device_ptr      \
                                                          : y)
#endif
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vzpowi))                      \
    match(construct = {target variant dispatch}, device = {arch(gen)})
void vzPowI(const MKL_INT n, const MKL_Complex16* a, MKL_INT inca,
            const MKL_Complex16* b, MKL_INT incb, MKL_Complex16* y,
            MKL_INT incy) NOTHROW;

#if (_OPENMP >= 202011)
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vmzpow))                      \
    match(construct = {dispatch}, device = {arch(gen)})                        \
        append_args(interop(prefer_type("sycl", "level_zero"), targetsync))    \
            adjust_args(need_device_ptr                                        \
                        : a) adjust_args(need_device_ptr                       \
                                         : b) adjust_args(need_device_ptr      \
                                                          : y)
#endif
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vmzpow))                      \
    match(construct = {target variant dispatch}, device = {arch(gen)})
void vmzPow(const MKL_INT n, const MKL_Complex16* a, const MKL_Complex16* b,
            MKL_Complex16* y, MKL_INT64 mode) NOTHROW;

#if (_OPENMP >= 202011)
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vmzpowi))                     \
    match(construct = {dispatch}, device = {arch(gen)})                        \
        append_args(interop(prefer_type("sycl", "level_zero"), targetsync))    \
            adjust_args(need_device_ptr                                        \
                        : a) adjust_args(need_device_ptr                       \
                                         : b) adjust_args(need_device_ptr      \
                                                          : y)
#endif
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vmzpowi))                     \
    match(construct = {target variant dispatch}, device = {arch(gen)})
void vmzPowI(const MKL_INT n, const MKL_Complex16* a, MKL_INT inca,
             const MKL_Complex16* b, MKL_INT incb, MKL_Complex16* y,
             MKL_INT incy, MKL_INT64 mode) NOTHROW;

// function pow2o3
#if (_OPENMP >= 202011)
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vspow2o3))                    \
    match(construct = {dispatch}, device = {arch(gen)})                        \
        append_args(interop(prefer_type("sycl", "level_zero"), targetsync))    \
            adjust_args(need_device_ptr                                        \
                        : a) adjust_args(need_device_ptr                       \
                                         : y)
#endif
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vspow2o3))                    \
    match(construct = {target variant dispatch}, device = {arch(gen)})
void vsPow2o3(const MKL_INT n, const float* a, float* y) NOTHROW;

#if (_OPENMP >= 202011)
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vspow2o3i))                   \
    match(construct = {dispatch}, device = {arch(gen)})                        \
        append_args(interop(prefer_type("sycl", "level_zero"), targetsync))    \
            adjust_args(need_device_ptr                                        \
                        : a) adjust_args(need_device_ptr                       \
                                         : y)
#endif
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vspow2o3i))                   \
    match(construct = {target variant dispatch}, device = {arch(gen)})
void vsPow2o3I(const MKL_INT n, const float* a, MKL_INT inca, float* y,
               MKL_INT incy) NOTHROW;

#if (_OPENMP >= 202011)
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vmspow2o3))                   \
    match(construct = {dispatch}, device = {arch(gen)})                        \
        append_args(interop(prefer_type("sycl", "level_zero"), targetsync))    \
            adjust_args(need_device_ptr                                        \
                        : a) adjust_args(need_device_ptr                       \
                                         : y)
#endif
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vmspow2o3))                   \
    match(construct = {target variant dispatch}, device = {arch(gen)})
void vmsPow2o3(const MKL_INT n, const float* a, float* y,
               MKL_INT64 mode) NOTHROW;

#if (_OPENMP >= 202011)
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vmspow2o3i))                  \
    match(construct = {dispatch}, device = {arch(gen)})                        \
        append_args(interop(prefer_type("sycl", "level_zero"), targetsync))    \
            adjust_args(need_device_ptr                                        \
                        : a) adjust_args(need_device_ptr                       \
                                         : y)
#endif
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vmspow2o3i))                  \
    match(construct = {target variant dispatch}, device = {arch(gen)})
void vmsPow2o3I(const MKL_INT n, const float* a, MKL_INT inca, float* y,
                MKL_INT incy, MKL_INT64 mode) NOTHROW;

#if (_OPENMP >= 202011)
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vdpow2o3))                    \
    match(construct = {dispatch}, device = {arch(gen)})                        \
        append_args(interop(prefer_type("sycl", "level_zero"), targetsync))    \
            adjust_args(need_device_ptr                                        \
                        : a) adjust_args(need_device_ptr                       \
                                         : y)
#endif
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vdpow2o3))                    \
    match(construct = {target variant dispatch}, device = {arch(gen)})
void vdPow2o3(const MKL_INT n, const double* a, double* y) NOTHROW;

#if (_OPENMP >= 202011)
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vdpow2o3i))                   \
    match(construct = {dispatch}, device = {arch(gen)})                        \
        append_args(interop(prefer_type("sycl", "level_zero"), targetsync))    \
            adjust_args(need_device_ptr                                        \
                        : a) adjust_args(need_device_ptr                       \
                                         : y)
#endif
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vdpow2o3i))                   \
    match(construct = {target variant dispatch}, device = {arch(gen)})
void vdPow2o3I(const MKL_INT n, const double* a, MKL_INT inca, double* y,
               MKL_INT incy) NOTHROW;

#if (_OPENMP >= 202011)
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vmdpow2o3))                   \
    match(construct = {dispatch}, device = {arch(gen)})                        \
        append_args(interop(prefer_type("sycl", "level_zero"), targetsync))    \
            adjust_args(need_device_ptr                                        \
                        : a) adjust_args(need_device_ptr                       \
                                         : y)
#endif
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vmdpow2o3))                   \
    match(construct = {target variant dispatch}, device = {arch(gen)})
void vmdPow2o3(const MKL_INT n, const double* a, double* y,
               MKL_INT64 mode) NOTHROW;

#if (_OPENMP >= 202011)
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vmdpow2o3i))                  \
    match(construct = {dispatch}, device = {arch(gen)})                        \
        append_args(interop(prefer_type("sycl", "level_zero"), targetsync))    \
            adjust_args(need_device_ptr                                        \
                        : a) adjust_args(need_device_ptr                       \
                                         : y)
#endif
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vmdpow2o3i))                  \
    match(construct = {target variant dispatch}, device = {arch(gen)})
void vmdPow2o3I(const MKL_INT n, const double* a, MKL_INT inca, double* y,
                MKL_INT incy, MKL_INT64 mode) NOTHROW;

// function pow3o2
#if (_OPENMP >= 202011)
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vspow3o2))                    \
    match(construct = {dispatch}, device = {arch(gen)})                        \
        append_args(interop(prefer_type("sycl", "level_zero"), targetsync))    \
            adjust_args(need_device_ptr                                        \
                        : a) adjust_args(need_device_ptr                       \
                                         : y)
#endif
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vspow3o2))                    \
    match(construct = {target variant dispatch}, device = {arch(gen)})
void vsPow3o2(const MKL_INT n, const float* a, float* y) NOTHROW;

#if (_OPENMP >= 202011)
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vspow3o2i))                   \
    match(construct = {dispatch}, device = {arch(gen)})                        \
        append_args(interop(prefer_type("sycl", "level_zero"), targetsync))    \
            adjust_args(need_device_ptr                                        \
                        : a) adjust_args(need_device_ptr                       \
                                         : y)
#endif
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vspow3o2i))                   \
    match(construct = {target variant dispatch}, device = {arch(gen)})
void vsPow3o2I(const MKL_INT n, const float* a, MKL_INT inca, float* y,
               MKL_INT incy) NOTHROW;

#if (_OPENMP >= 202011)
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vmspow3o2))                   \
    match(construct = {dispatch}, device = {arch(gen)})                        \
        append_args(interop(prefer_type("sycl", "level_zero"), targetsync))    \
            adjust_args(need_device_ptr                                        \
                        : a) adjust_args(need_device_ptr                       \
                                         : y)
#endif
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vmspow3o2))                   \
    match(construct = {target variant dispatch}, device = {arch(gen)})
void vmsPow3o2(const MKL_INT n, const float* a, float* y,
               MKL_INT64 mode) NOTHROW;

#if (_OPENMP >= 202011)
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vmspow3o2i))                  \
    match(construct = {dispatch}, device = {arch(gen)})                        \
        append_args(interop(prefer_type("sycl", "level_zero"), targetsync))    \
            adjust_args(need_device_ptr                                        \
                        : a) adjust_args(need_device_ptr                       \
                                         : y)
#endif
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vmspow3o2i))                  \
    match(construct = {target variant dispatch}, device = {arch(gen)})
void vmsPow3o2I(const MKL_INT n, const float* a, MKL_INT inca, float* y,
                MKL_INT incy, MKL_INT64 mode) NOTHROW;

#if (_OPENMP >= 202011)
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vdpow3o2))                    \
    match(construct = {dispatch}, device = {arch(gen)})                        \
        append_args(interop(prefer_type("sycl", "level_zero"), targetsync))    \
            adjust_args(need_device_ptr                                        \
                        : a) adjust_args(need_device_ptr                       \
                                         : y)
#endif
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vdpow3o2))                    \
    match(construct = {target variant dispatch}, device = {arch(gen)})
void vdPow3o2(const MKL_INT n, const double* a, double* y) NOTHROW;

#if (_OPENMP >= 202011)
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vdpow3o2i))                   \
    match(construct = {dispatch}, device = {arch(gen)})                        \
        append_args(interop(prefer_type("sycl", "level_zero"), targetsync))    \
            adjust_args(need_device_ptr                                        \
                        : a) adjust_args(need_device_ptr                       \
                                         : y)
#endif
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vdpow3o2i))                   \
    match(construct = {target variant dispatch}, device = {arch(gen)})
void vdPow3o2I(const MKL_INT n, const double* a, MKL_INT inca, double* y,
               MKL_INT incy) NOTHROW;

#if (_OPENMP >= 202011)
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vmdpow3o2))                   \
    match(construct = {dispatch}, device = {arch(gen)})                        \
        append_args(interop(prefer_type("sycl", "level_zero"), targetsync))    \
            adjust_args(need_device_ptr                                        \
                        : a) adjust_args(need_device_ptr                       \
                                         : y)
#endif
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vmdpow3o2))                   \
    match(construct = {target variant dispatch}, device = {arch(gen)})
void vmdPow3o2(const MKL_INT n, const double* a, double* y,
               MKL_INT64 mode) NOTHROW;

#if (_OPENMP >= 202011)
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vmdpow3o2i))                  \
    match(construct = {dispatch}, device = {arch(gen)})                        \
        append_args(interop(prefer_type("sycl", "level_zero"), targetsync))    \
            adjust_args(need_device_ptr                                        \
                        : a) adjust_args(need_device_ptr                       \
                                         : y)
#endif
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vmdpow3o2i))                  \
    match(construct = {target variant dispatch}, device = {arch(gen)})
void vmdPow3o2I(const MKL_INT n, const double* a, MKL_INT inca, double* y,
                MKL_INT incy, MKL_INT64 mode) NOTHROW;

// function powr
#if (_OPENMP >= 202011)
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vspowr))                      \
    match(construct = {dispatch}, device = {arch(gen)})                        \
        append_args(interop(prefer_type("sycl", "level_zero"), targetsync))    \
            adjust_args(need_device_ptr                                        \
                        : a) adjust_args(need_device_ptr                       \
                                         : b) adjust_args(need_device_ptr      \
                                                          : y)
#endif
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vspowr))                      \
    match(construct = {target variant dispatch}, device = {arch(gen)})
void vsPowr(const MKL_INT n, const float* a, const float* b, float* y) NOTHROW;

#if (_OPENMP >= 202011)
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vspowri))                     \
    match(construct = {dispatch}, device = {arch(gen)})                        \
        append_args(interop(prefer_type("sycl", "level_zero"), targetsync))    \
            adjust_args(need_device_ptr                                        \
                        : a) adjust_args(need_device_ptr                       \
                                         : b) adjust_args(need_device_ptr      \
                                                          : y)
#endif
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vspowri))                     \
    match(construct = {target variant dispatch}, device = {arch(gen)})
void vsPowrI(const MKL_INT n, const float* a, MKL_INT inca, const float* b,
             MKL_INT incb, float* y, MKL_INT incy) NOTHROW;

#if (_OPENMP >= 202011)
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vmspowr))                     \
    match(construct = {dispatch}, device = {arch(gen)})                        \
        append_args(interop(prefer_type("sycl", "level_zero"), targetsync))    \
            adjust_args(need_device_ptr                                        \
                        : a) adjust_args(need_device_ptr                       \
                                         : b) adjust_args(need_device_ptr      \
                                                          : y)
#endif
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vmspowr))                     \
    match(construct = {target variant dispatch}, device = {arch(gen)})
void vmsPowr(const MKL_INT n, const float* a, const float* b, float* y,
             MKL_INT64 mode) NOTHROW;

#if (_OPENMP >= 202011)
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vmspowri))                    \
    match(construct = {dispatch}, device = {arch(gen)})                        \
        append_args(interop(prefer_type("sycl", "level_zero"), targetsync))    \
            adjust_args(need_device_ptr                                        \
                        : a) adjust_args(need_device_ptr                       \
                                         : b) adjust_args(need_device_ptr      \
                                                          : y)
#endif
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vmspowri))                    \
    match(construct = {target variant dispatch}, device = {arch(gen)})
void vmsPowrI(const MKL_INT n, const float* a, MKL_INT inca, const float* b,
              MKL_INT incb, float* y, MKL_INT incy, MKL_INT64 mode) NOTHROW;

#if (_OPENMP >= 202011)
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vdpowr))                      \
    match(construct = {dispatch}, device = {arch(gen)})                        \
        append_args(interop(prefer_type("sycl", "level_zero"), targetsync))    \
            adjust_args(need_device_ptr                                        \
                        : a) adjust_args(need_device_ptr                       \
                                         : b) adjust_args(need_device_ptr      \
                                                          : y)
#endif
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vdpowr))                      \
    match(construct = {target variant dispatch}, device = {arch(gen)})
void vdPowr(const MKL_INT n, const double* a, const double* b,
            double* y) NOTHROW;

#if (_OPENMP >= 202011)
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vdpowri))                     \
    match(construct = {dispatch}, device = {arch(gen)})                        \
        append_args(interop(prefer_type("sycl", "level_zero"), targetsync))    \
            adjust_args(need_device_ptr                                        \
                        : a) adjust_args(need_device_ptr                       \
                                         : b) adjust_args(need_device_ptr      \
                                                          : y)
#endif
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vdpowri))                     \
    match(construct = {target variant dispatch}, device = {arch(gen)})
void vdPowrI(const MKL_INT n, const double* a, MKL_INT inca, const double* b,
             MKL_INT incb, double* y, MKL_INT incy) NOTHROW;

#if (_OPENMP >= 202011)
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vmdpowr))                     \
    match(construct = {dispatch}, device = {arch(gen)})                        \
        append_args(interop(prefer_type("sycl", "level_zero"), targetsync))    \
            adjust_args(need_device_ptr                                        \
                        : a) adjust_args(need_device_ptr                       \
                                         : b) adjust_args(need_device_ptr      \
                                                          : y)
#endif
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vmdpowr))                     \
    match(construct = {target variant dispatch}, device = {arch(gen)})
void vmdPowr(const MKL_INT n, const double* a, const double* b, double* y,
             MKL_INT64 mode) NOTHROW;

#if (_OPENMP >= 202011)
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vmdpowri))                    \
    match(construct = {dispatch}, device = {arch(gen)})                        \
        append_args(interop(prefer_type("sycl", "level_zero"), targetsync))    \
            adjust_args(need_device_ptr                                        \
                        : a) adjust_args(need_device_ptr                       \
                                         : b) adjust_args(need_device_ptr      \
                                                          : y)
#endif
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vmdpowri))                    \
    match(construct = {target variant dispatch}, device = {arch(gen)})
void vmdPowrI(const MKL_INT n, const double* a, MKL_INT inca, const double* b,
              MKL_INT incb, double* y, MKL_INT incy, MKL_INT64 mode) NOTHROW;

// function powx
#if (_OPENMP >= 202011)
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vspowx))                      \
    match(construct = {dispatch}, device = {arch(gen)})                        \
        append_args(interop(prefer_type("sycl", "level_zero"), targetsync))    \
            adjust_args(need_device_ptr                                        \
                        : a) adjust_args(need_device_ptr                       \
                                         : y)
#endif
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vspowx))                      \
    match(construct = {target variant dispatch}, device = {arch(gen)})
void vsPowx(const MKL_INT n, const float* a, const float b, float* y) NOTHROW;

#if (_OPENMP >= 202011)
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vspowxi))                     \
    match(construct = {dispatch}, device = {arch(gen)})                        \
        append_args(interop(prefer_type("sycl", "level_zero"), targetsync))    \
            adjust_args(need_device_ptr                                        \
                        : a) adjust_args(need_device_ptr                       \
                                         : y)
#endif
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vspowxi))                     \
    match(construct = {target variant dispatch}, device = {arch(gen)})
void vsPowxI(const MKL_INT n, const float* a, MKL_INT inca, const float b,
             float* y, MKL_INT incy) NOTHROW;

#if (_OPENMP >= 202011)
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vmspowx))                     \
    match(construct = {dispatch}, device = {arch(gen)})                        \
        append_args(interop(prefer_type("sycl", "level_zero"), targetsync))    \
            adjust_args(need_device_ptr                                        \
                        : a) adjust_args(need_device_ptr                       \
                                         : y)
#endif
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vmspowx))                     \
    match(construct = {target variant dispatch}, device = {arch(gen)})
void vmsPowx(const MKL_INT n, const float* a, const float b, float* y,
             MKL_INT64 mode) NOTHROW;

#if (_OPENMP >= 202011)
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vmspowxi))                    \
    match(construct = {dispatch}, device = {arch(gen)})                        \
        append_args(interop(prefer_type("sycl", "level_zero"), targetsync))    \
            adjust_args(need_device_ptr                                        \
                        : a) adjust_args(need_device_ptr                       \
                                         : y)
#endif
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vmspowxi))                    \
    match(construct = {target variant dispatch}, device = {arch(gen)})
void vmsPowxI(const MKL_INT n, const float* a, MKL_INT inca, const float b,
              float* y, MKL_INT incy, MKL_INT64 mode) NOTHROW;

#if (_OPENMP >= 202011)
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vdpowx))                      \
    match(construct = {dispatch}, device = {arch(gen)})                        \
        append_args(interop(prefer_type("sycl", "level_zero"), targetsync))    \
            adjust_args(need_device_ptr                                        \
                        : a) adjust_args(need_device_ptr                       \
                                         : y)
#endif
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vdpowx))                      \
    match(construct = {target variant dispatch}, device = {arch(gen)})
void vdPowx(const MKL_INT n, const double* a, const double b,
            double* y) NOTHROW;

#if (_OPENMP >= 202011)
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vdpowxi))                     \
    match(construct = {dispatch}, device = {arch(gen)})                        \
        append_args(interop(prefer_type("sycl", "level_zero"), targetsync))    \
            adjust_args(need_device_ptr                                        \
                        : a) adjust_args(need_device_ptr                       \
                                         : y)
#endif
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vdpowxi))                     \
    match(construct = {target variant dispatch}, device = {arch(gen)})
void vdPowxI(const MKL_INT n, const double* a, MKL_INT inca, const double b,
             double* y, MKL_INT incy) NOTHROW;

#if (_OPENMP >= 202011)
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vmdpowx))                     \
    match(construct = {dispatch}, device = {arch(gen)})                        \
        append_args(interop(prefer_type("sycl", "level_zero"), targetsync))    \
            adjust_args(need_device_ptr                                        \
                        : a) adjust_args(need_device_ptr                       \
                                         : y)
#endif
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vmdpowx))                     \
    match(construct = {target variant dispatch}, device = {arch(gen)})
void vmdPowx(const MKL_INT n, const double* a, const double b, double* y,
             MKL_INT64 mode) NOTHROW;

#if (_OPENMP >= 202011)
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vmdpowxi))                    \
    match(construct = {dispatch}, device = {arch(gen)})                        \
        append_args(interop(prefer_type("sycl", "level_zero"), targetsync))    \
            adjust_args(need_device_ptr                                        \
                        : a) adjust_args(need_device_ptr                       \
                                         : y)
#endif
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vmdpowxi))                    \
    match(construct = {target variant dispatch}, device = {arch(gen)})
void vmdPowxI(const MKL_INT n, const double* a, MKL_INT inca, const double b,
              double* y, MKL_INT incy, MKL_INT64 mode) NOTHROW;

#if (_OPENMP >= 202011)
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vcpowx))                      \
    match(construct = {dispatch}, device = {arch(gen)})                        \
        append_args(interop(prefer_type("sycl", "level_zero"), targetsync))    \
            adjust_args(need_device_ptr                                        \
                        : a) adjust_args(need_device_ptr                       \
                                         : y)
#endif
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vcpowx))                      \
    match(construct = {target variant dispatch}, device = {arch(gen)})
void vcPowx(const MKL_INT n, const MKL_Complex8* a, const MKL_Complex8 b,
            MKL_Complex8* y) NOTHROW;

#if (_OPENMP >= 202011)
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vcpowxi))                     \
    match(construct = {dispatch}, device = {arch(gen)})                        \
        append_args(interop(prefer_type("sycl", "level_zero"), targetsync))    \
            adjust_args(need_device_ptr                                        \
                        : a) adjust_args(need_device_ptr                       \
                                         : y)
#endif
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vcpowxi))                     \
    match(construct = {target variant dispatch}, device = {arch(gen)})
void vcPowxI(const MKL_INT n, const MKL_Complex8* a, MKL_INT inca,
             const MKL_Complex8 b, MKL_Complex8* y, MKL_INT incy) NOTHROW;

#if (_OPENMP >= 202011)
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vmcpowx))                     \
    match(construct = {dispatch}, device = {arch(gen)})                        \
        append_args(interop(prefer_type("sycl", "level_zero"), targetsync))    \
            adjust_args(need_device_ptr                                        \
                        : a) adjust_args(need_device_ptr                       \
                                         : y)
#endif
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vmcpowx))                     \
    match(construct = {target variant dispatch}, device = {arch(gen)})
void vmcPowx(const MKL_INT n, const MKL_Complex8* a, const MKL_Complex8 b,
             MKL_Complex8* y, MKL_INT64 mode) NOTHROW;

#if (_OPENMP >= 202011)
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vmcpowxi))                    \
    match(construct = {dispatch}, device = {arch(gen)})                        \
        append_args(interop(prefer_type("sycl", "level_zero"), targetsync))    \
            adjust_args(need_device_ptr                                        \
                        : a) adjust_args(need_device_ptr                       \
                                         : y)
#endif
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vmcpowxi))                    \
    match(construct = {target variant dispatch}, device = {arch(gen)})
void vmcPowxI(const MKL_INT n, const MKL_Complex8* a, MKL_INT inca,
              const MKL_Complex8 b, MKL_Complex8* y, MKL_INT incy,
              MKL_INT64 mode) NOTHROW;

#if (_OPENMP >= 202011)
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vzpowx))                      \
    match(construct = {dispatch}, device = {arch(gen)})                        \
        append_args(interop(prefer_type("sycl", "level_zero"), targetsync))    \
            adjust_args(need_device_ptr                                        \
                        : a) adjust_args(need_device_ptr                       \
                                         : y)
#endif
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vzpowx))                      \
    match(construct = {target variant dispatch}, device = {arch(gen)})
void vzPowx(const MKL_INT n, const MKL_Complex16* a, const MKL_Complex16 b,
            MKL_Complex16* y) NOTHROW;

#if (_OPENMP >= 202011)
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vzpowxi))                     \
    match(construct = {dispatch}, device = {arch(gen)})                        \
        append_args(interop(prefer_type("sycl", "level_zero"), targetsync))    \
            adjust_args(need_device_ptr                                        \
                        : a) adjust_args(need_device_ptr                       \
                                         : y)
#endif
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vzpowxi))                     \
    match(construct = {target variant dispatch}, device = {arch(gen)})
void vzPowxI(const MKL_INT n, const MKL_Complex16* a, MKL_INT inca,
             const MKL_Complex16 b, MKL_Complex16* y, MKL_INT incy) NOTHROW;

#if (_OPENMP >= 202011)
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vmzpowx))                     \
    match(construct = {dispatch}, device = {arch(gen)})                        \
        append_args(interop(prefer_type("sycl", "level_zero"), targetsync))    \
            adjust_args(need_device_ptr                                        \
                        : a) adjust_args(need_device_ptr                       \
                                         : y)
#endif
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vmzpowx))                     \
    match(construct = {target variant dispatch}, device = {arch(gen)})
void vmzPowx(const MKL_INT n, const MKL_Complex16* a, const MKL_Complex16 b,
             MKL_Complex16* y, MKL_INT64 mode) NOTHROW;

#if (_OPENMP >= 202011)
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vmzpowxi))                    \
    match(construct = {dispatch}, device = {arch(gen)})                        \
        append_args(interop(prefer_type("sycl", "level_zero"), targetsync))    \
            adjust_args(need_device_ptr                                        \
                        : a) adjust_args(need_device_ptr                       \
                                         : y)
#endif
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vmzpowxi))                    \
    match(construct = {target variant dispatch}, device = {arch(gen)})
void vmzPowxI(const MKL_INT n, const MKL_Complex16* a, MKL_INT inca,
              const MKL_Complex16 b, MKL_Complex16* y, MKL_INT incy,
              MKL_INT64 mode) NOTHROW;

// function remainder
#if (_OPENMP >= 202011)
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vsremainder))                 \
    match(construct = {dispatch}, device = {arch(gen)})                        \
        append_args(interop(prefer_type("sycl", "level_zero"), targetsync))    \
            adjust_args(need_device_ptr                                        \
                        : a) adjust_args(need_device_ptr                       \
                                         : b) adjust_args(need_device_ptr      \
                                                          : y)
#endif
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vsremainder))                 \
    match(construct = {target variant dispatch}, device = {arch(gen)})
void vsRemainder(const MKL_INT n, const float* a, const float* b,
                 float* y) NOTHROW;

#if (_OPENMP >= 202011)
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vsremainderi))                \
    match(construct = {dispatch}, device = {arch(gen)})                        \
        append_args(interop(prefer_type("sycl", "level_zero"), targetsync))    \
            adjust_args(need_device_ptr                                        \
                        : a) adjust_args(need_device_ptr                       \
                                         : b) adjust_args(need_device_ptr      \
                                                          : y)
#endif
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vsremainderi))                \
    match(construct = {target variant dispatch}, device = {arch(gen)})
void vsRemainderI(const MKL_INT n, const float* a, MKL_INT inca, const float* b,
                  MKL_INT incb, float* y, MKL_INT incy) NOTHROW;

#if (_OPENMP >= 202011)
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vmsremainder))                \
    match(construct = {dispatch}, device = {arch(gen)})                        \
        append_args(interop(prefer_type("sycl", "level_zero"), targetsync))    \
            adjust_args(need_device_ptr                                        \
                        : a) adjust_args(need_device_ptr                       \
                                         : b) adjust_args(need_device_ptr      \
                                                          : y)
#endif
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vmsremainder))                \
    match(construct = {target variant dispatch}, device = {arch(gen)})
void vmsRemainder(const MKL_INT n, const float* a, const float* b, float* y,
                  MKL_INT64 mode) NOTHROW;

#if (_OPENMP >= 202011)
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vmsremainderi))               \
    match(construct = {dispatch}, device = {arch(gen)})                        \
        append_args(interop(prefer_type("sycl", "level_zero"), targetsync))    \
            adjust_args(need_device_ptr                                        \
                        : a) adjust_args(need_device_ptr                       \
                                         : b) adjust_args(need_device_ptr      \
                                                          : y)
#endif
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vmsremainderi))               \
    match(construct = {target variant dispatch}, device = {arch(gen)})
void vmsRemainderI(const MKL_INT n, const float* a, MKL_INT inca,
                   const float* b, MKL_INT incb, float* y, MKL_INT incy,
                   MKL_INT64 mode) NOTHROW;

#if (_OPENMP >= 202011)
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vdremainder))                 \
    match(construct = {dispatch}, device = {arch(gen)})                        \
        append_args(interop(prefer_type("sycl", "level_zero"), targetsync))    \
            adjust_args(need_device_ptr                                        \
                        : a) adjust_args(need_device_ptr                       \
                                         : b) adjust_args(need_device_ptr      \
                                                          : y)
#endif
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vdremainder))                 \
    match(construct = {target variant dispatch}, device = {arch(gen)})
void vdRemainder(const MKL_INT n, const double* a, const double* b,
                 double* y) NOTHROW;

#if (_OPENMP >= 202011)
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vdremainderi))                \
    match(construct = {dispatch}, device = {arch(gen)})                        \
        append_args(interop(prefer_type("sycl", "level_zero"), targetsync))    \
            adjust_args(need_device_ptr                                        \
                        : a) adjust_args(need_device_ptr                       \
                                         : b) adjust_args(need_device_ptr      \
                                                          : y)
#endif
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vdremainderi))                \
    match(construct = {target variant dispatch}, device = {arch(gen)})
void vdRemainderI(const MKL_INT n, const double* a, MKL_INT inca,
                  const double* b, MKL_INT incb, double* y,
                  MKL_INT incy) NOTHROW;

#if (_OPENMP >= 202011)
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vmdremainder))                \
    match(construct = {dispatch}, device = {arch(gen)})                        \
        append_args(interop(prefer_type("sycl", "level_zero"), targetsync))    \
            adjust_args(need_device_ptr                                        \
                        : a) adjust_args(need_device_ptr                       \
                                         : b) adjust_args(need_device_ptr      \
                                                          : y)
#endif
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vmdremainder))                \
    match(construct = {target variant dispatch}, device = {arch(gen)})
void vmdRemainder(const MKL_INT n, const double* a, const double* b, double* y,
                  MKL_INT64 mode) NOTHROW;

#if (_OPENMP >= 202011)
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vmdremainderi))               \
    match(construct = {dispatch}, device = {arch(gen)})                        \
        append_args(interop(prefer_type("sycl", "level_zero"), targetsync))    \
            adjust_args(need_device_ptr                                        \
                        : a) adjust_args(need_device_ptr                       \
                                         : b) adjust_args(need_device_ptr      \
                                                          : y)
#endif
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vmdremainderi))               \
    match(construct = {target variant dispatch}, device = {arch(gen)})
void vmdRemainderI(const MKL_INT n, const double* a, MKL_INT inca,
                   const double* b, MKL_INT incb, double* y, MKL_INT incy,
                   MKL_INT64 mode) NOTHROW;

// function rint
#if (_OPENMP >= 202011)
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vsrint))                      \
    match(construct = {dispatch}, device = {arch(gen)})                        \
        append_args(interop(prefer_type("sycl", "level_zero"), targetsync))    \
            adjust_args(need_device_ptr                                        \
                        : a) adjust_args(need_device_ptr                       \
                                         : y)
#endif
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vsrint))                      \
    match(construct = {target variant dispatch}, device = {arch(gen)})
void vsRint(const MKL_INT n, const float* a, float* y) NOTHROW;

#if (_OPENMP >= 202011)
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vsrinti))                     \
    match(construct = {dispatch}, device = {arch(gen)})                        \
        append_args(interop(prefer_type("sycl", "level_zero"), targetsync))    \
            adjust_args(need_device_ptr                                        \
                        : a) adjust_args(need_device_ptr                       \
                                         : y)
#endif
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vsrinti))                     \
    match(construct = {target variant dispatch}, device = {arch(gen)})
void vsRintI(const MKL_INT n, const float* a, MKL_INT inca, float* y,
             MKL_INT incy) NOTHROW;

#if (_OPENMP >= 202011)
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vmsrint))                     \
    match(construct = {dispatch}, device = {arch(gen)})                        \
        append_args(interop(prefer_type("sycl", "level_zero"), targetsync))    \
            adjust_args(need_device_ptr                                        \
                        : a) adjust_args(need_device_ptr                       \
                                         : y)
#endif
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vmsrint))                     \
    match(construct = {target variant dispatch}, device = {arch(gen)})
void vmsRint(const MKL_INT n, const float* a, float* y, MKL_INT64 mode) NOTHROW;

#if (_OPENMP >= 202011)
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vmsrinti))                    \
    match(construct = {dispatch}, device = {arch(gen)})                        \
        append_args(interop(prefer_type("sycl", "level_zero"), targetsync))    \
            adjust_args(need_device_ptr                                        \
                        : a) adjust_args(need_device_ptr                       \
                                         : y)
#endif
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vmsrinti))                    \
    match(construct = {target variant dispatch}, device = {arch(gen)})
void vmsRintI(const MKL_INT n, const float* a, MKL_INT inca, float* y,
              MKL_INT incy, MKL_INT64 mode) NOTHROW;

#if (_OPENMP >= 202011)
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vdrint))                      \
    match(construct = {dispatch}, device = {arch(gen)})                        \
        append_args(interop(prefer_type("sycl", "level_zero"), targetsync))    \
            adjust_args(need_device_ptr                                        \
                        : a) adjust_args(need_device_ptr                       \
                                         : y)
#endif
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vdrint))                      \
    match(construct = {target variant dispatch}, device = {arch(gen)})
void vdRint(const MKL_INT n, const double* a, double* y) NOTHROW;

#if (_OPENMP >= 202011)
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vdrinti))                     \
    match(construct = {dispatch}, device = {arch(gen)})                        \
        append_args(interop(prefer_type("sycl", "level_zero"), targetsync))    \
            adjust_args(need_device_ptr                                        \
                        : a) adjust_args(need_device_ptr                       \
                                         : y)
#endif
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vdrinti))                     \
    match(construct = {target variant dispatch}, device = {arch(gen)})
void vdRintI(const MKL_INT n, const double* a, MKL_INT inca, double* y,
             MKL_INT incy) NOTHROW;

#if (_OPENMP >= 202011)
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vmdrint))                     \
    match(construct = {dispatch}, device = {arch(gen)})                        \
        append_args(interop(prefer_type("sycl", "level_zero"), targetsync))    \
            adjust_args(need_device_ptr                                        \
                        : a) adjust_args(need_device_ptr                       \
                                         : y)
#endif
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vmdrint))                     \
    match(construct = {target variant dispatch}, device = {arch(gen)})
void vmdRint(const MKL_INT n, const double* a, double* y,
             MKL_INT64 mode) NOTHROW;

#if (_OPENMP >= 202011)
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vmdrinti))                    \
    match(construct = {dispatch}, device = {arch(gen)})                        \
        append_args(interop(prefer_type("sycl", "level_zero"), targetsync))    \
            adjust_args(need_device_ptr                                        \
                        : a) adjust_args(need_device_ptr                       \
                                         : y)
#endif
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vmdrinti))                    \
    match(construct = {target variant dispatch}, device = {arch(gen)})
void vmdRintI(const MKL_INT n, const double* a, MKL_INT inca, double* y,
              MKL_INT incy, MKL_INT64 mode) NOTHROW;

// function round
#if (_OPENMP >= 202011)
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vsround))                     \
    match(construct = {dispatch}, device = {arch(gen)})                        \
        append_args(interop(prefer_type("sycl", "level_zero"), targetsync))    \
            adjust_args(need_device_ptr                                        \
                        : a) adjust_args(need_device_ptr                       \
                                         : y)
#endif
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vsround))                     \
    match(construct = {target variant dispatch}, device = {arch(gen)})
void vsRound(const MKL_INT n, const float* a, float* y) NOTHROW;

#if (_OPENMP >= 202011)
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vsroundi))                    \
    match(construct = {dispatch}, device = {arch(gen)})                        \
        append_args(interop(prefer_type("sycl", "level_zero"), targetsync))    \
            adjust_args(need_device_ptr                                        \
                        : a) adjust_args(need_device_ptr                       \
                                         : y)
#endif
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vsroundi))                    \
    match(construct = {target variant dispatch}, device = {arch(gen)})
void vsRoundI(const MKL_INT n, const float* a, MKL_INT inca, float* y,
              MKL_INT incy) NOTHROW;

#if (_OPENMP >= 202011)
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vmsround))                    \
    match(construct = {dispatch}, device = {arch(gen)})                        \
        append_args(interop(prefer_type("sycl", "level_zero"), targetsync))    \
            adjust_args(need_device_ptr                                        \
                        : a) adjust_args(need_device_ptr                       \
                                         : y)
#endif
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vmsround))                    \
    match(construct = {target variant dispatch}, device = {arch(gen)})
void vmsRound(const MKL_INT n, const float* a, float* y,
              MKL_INT64 mode) NOTHROW;

#if (_OPENMP >= 202011)
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vmsroundi))                   \
    match(construct = {dispatch}, device = {arch(gen)})                        \
        append_args(interop(prefer_type("sycl", "level_zero"), targetsync))    \
            adjust_args(need_device_ptr                                        \
                        : a) adjust_args(need_device_ptr                       \
                                         : y)
#endif
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vmsroundi))                   \
    match(construct = {target variant dispatch}, device = {arch(gen)})
void vmsRoundI(const MKL_INT n, const float* a, MKL_INT inca, float* y,
               MKL_INT incy, MKL_INT64 mode) NOTHROW;

#if (_OPENMP >= 202011)
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vdround))                     \
    match(construct = {dispatch}, device = {arch(gen)})                        \
        append_args(interop(prefer_type("sycl", "level_zero"), targetsync))    \
            adjust_args(need_device_ptr                                        \
                        : a) adjust_args(need_device_ptr                       \
                                         : y)
#endif
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vdround))                     \
    match(construct = {target variant dispatch}, device = {arch(gen)})
void vdRound(const MKL_INT n, const double* a, double* y) NOTHROW;

#if (_OPENMP >= 202011)
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vdroundi))                    \
    match(construct = {dispatch}, device = {arch(gen)})                        \
        append_args(interop(prefer_type("sycl", "level_zero"), targetsync))    \
            adjust_args(need_device_ptr                                        \
                        : a) adjust_args(need_device_ptr                       \
                                         : y)
#endif
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vdroundi))                    \
    match(construct = {target variant dispatch}, device = {arch(gen)})
void vdRoundI(const MKL_INT n, const double* a, MKL_INT inca, double* y,
              MKL_INT incy) NOTHROW;

#if (_OPENMP >= 202011)
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vmdround))                    \
    match(construct = {dispatch}, device = {arch(gen)})                        \
        append_args(interop(prefer_type("sycl", "level_zero"), targetsync))    \
            adjust_args(need_device_ptr                                        \
                        : a) adjust_args(need_device_ptr                       \
                                         : y)
#endif
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vmdround))                    \
    match(construct = {target variant dispatch}, device = {arch(gen)})
void vmdRound(const MKL_INT n, const double* a, double* y,
              MKL_INT64 mode) NOTHROW;

#if (_OPENMP >= 202011)
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vmdroundi))                   \
    match(construct = {dispatch}, device = {arch(gen)})                        \
        append_args(interop(prefer_type("sycl", "level_zero"), targetsync))    \
            adjust_args(need_device_ptr                                        \
                        : a) adjust_args(need_device_ptr                       \
                                         : y)
#endif
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vmdroundi))                   \
    match(construct = {target variant dispatch}, device = {arch(gen)})
void vmdRoundI(const MKL_INT n, const double* a, MKL_INT inca, double* y,
               MKL_INT incy, MKL_INT64 mode) NOTHROW;

// function sin
#if (_OPENMP >= 202011)
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vssin))                       \
    match(construct = {dispatch}, device = {arch(gen)})                        \
        append_args(interop(prefer_type("sycl", "level_zero"), targetsync))    \
            adjust_args(need_device_ptr                                        \
                        : a) adjust_args(need_device_ptr                       \
                                         : y)
#endif
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vssin))                       \
    match(construct = {target variant dispatch}, device = {arch(gen)})
void vsSin(const MKL_INT n, const float* a, float* y) NOTHROW;

#if (_OPENMP >= 202011)
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vssini))                      \
    match(construct = {dispatch}, device = {arch(gen)})                        \
        append_args(interop(prefer_type("sycl", "level_zero"), targetsync))    \
            adjust_args(need_device_ptr                                        \
                        : a) adjust_args(need_device_ptr                       \
                                         : y)
#endif
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vssini))                      \
    match(construct = {target variant dispatch}, device = {arch(gen)})
void vsSinI(const MKL_INT n, const float* a, MKL_INT inca, float* y,
            MKL_INT incy) NOTHROW;

#if (_OPENMP >= 202011)
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vmssin))                      \
    match(construct = {dispatch}, device = {arch(gen)})                        \
        append_args(interop(prefer_type("sycl", "level_zero"), targetsync))    \
            adjust_args(need_device_ptr                                        \
                        : a) adjust_args(need_device_ptr                       \
                                         : y)
#endif
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vmssin))                      \
    match(construct = {target variant dispatch}, device = {arch(gen)})
void vmsSin(const MKL_INT n, const float* a, float* y, MKL_INT64 mode) NOTHROW;

#if (_OPENMP >= 202011)
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vmssini))                     \
    match(construct = {dispatch}, device = {arch(gen)})                        \
        append_args(interop(prefer_type("sycl", "level_zero"), targetsync))    \
            adjust_args(need_device_ptr                                        \
                        : a) adjust_args(need_device_ptr                       \
                                         : y)
#endif
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vmssini))                     \
    match(construct = {target variant dispatch}, device = {arch(gen)})
void vmsSinI(const MKL_INT n, const float* a, MKL_INT inca, float* y,
             MKL_INT incy, MKL_INT64 mode) NOTHROW;

#if (_OPENMP >= 202011)
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vdsin))                       \
    match(construct = {dispatch}, device = {arch(gen)})                        \
        append_args(interop(prefer_type("sycl", "level_zero"), targetsync))    \
            adjust_args(need_device_ptr                                        \
                        : a) adjust_args(need_device_ptr                       \
                                         : y)
#endif
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vdsin))                       \
    match(construct = {target variant dispatch}, device = {arch(gen)})
void vdSin(const MKL_INT n, const double* a, double* y) NOTHROW;

#if (_OPENMP >= 202011)
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vdsini))                      \
    match(construct = {dispatch}, device = {arch(gen)})                        \
        append_args(interop(prefer_type("sycl", "level_zero"), targetsync))    \
            adjust_args(need_device_ptr                                        \
                        : a) adjust_args(need_device_ptr                       \
                                         : y)
#endif
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vdsini))                      \
    match(construct = {target variant dispatch}, device = {arch(gen)})
void vdSinI(const MKL_INT n, const double* a, MKL_INT inca, double* y,
            MKL_INT incy) NOTHROW;

#if (_OPENMP >= 202011)
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vmdsin))                      \
    match(construct = {dispatch}, device = {arch(gen)})                        \
        append_args(interop(prefer_type("sycl", "level_zero"), targetsync))    \
            adjust_args(need_device_ptr                                        \
                        : a) adjust_args(need_device_ptr                       \
                                         : y)
#endif
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vmdsin))                      \
    match(construct = {target variant dispatch}, device = {arch(gen)})
void vmdSin(const MKL_INT n, const double* a, double* y,
            MKL_INT64 mode) NOTHROW;

#if (_OPENMP >= 202011)
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vmdsini))                     \
    match(construct = {dispatch}, device = {arch(gen)})                        \
        append_args(interop(prefer_type("sycl", "level_zero"), targetsync))    \
            adjust_args(need_device_ptr                                        \
                        : a) adjust_args(need_device_ptr                       \
                                         : y)
#endif
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vmdsini))                     \
    match(construct = {target variant dispatch}, device = {arch(gen)})
void vmdSinI(const MKL_INT n, const double* a, MKL_INT inca, double* y,
             MKL_INT incy, MKL_INT64 mode) NOTHROW;

#if (_OPENMP >= 202011)
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vcsin))                       \
    match(construct = {dispatch}, device = {arch(gen)})                        \
        append_args(interop(prefer_type("sycl", "level_zero"), targetsync))    \
            adjust_args(need_device_ptr                                        \
                        : a) adjust_args(need_device_ptr                       \
                                         : y)
#endif
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vcsin))                       \
    match(construct = {target variant dispatch}, device = {arch(gen)})
void vcSin(const MKL_INT n, const MKL_Complex8* a, MKL_Complex8* y) NOTHROW;

#if (_OPENMP >= 202011)
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vcsini))                      \
    match(construct = {dispatch}, device = {arch(gen)})                        \
        append_args(interop(prefer_type("sycl", "level_zero"), targetsync))    \
            adjust_args(need_device_ptr                                        \
                        : a) adjust_args(need_device_ptr                       \
                                         : y)
#endif
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vcsini))                      \
    match(construct = {target variant dispatch}, device = {arch(gen)})
void vcSinI(const MKL_INT n, const MKL_Complex8* a, MKL_INT inca,
            MKL_Complex8* y, MKL_INT incy) NOTHROW;

#if (_OPENMP >= 202011)
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vmcsin))                      \
    match(construct = {dispatch}, device = {arch(gen)})                        \
        append_args(interop(prefer_type("sycl", "level_zero"), targetsync))    \
            adjust_args(need_device_ptr                                        \
                        : a) adjust_args(need_device_ptr                       \
                                         : y)
#endif
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vmcsin))                      \
    match(construct = {target variant dispatch}, device = {arch(gen)})
void vmcSin(const MKL_INT n, const MKL_Complex8* a, MKL_Complex8* y,
            MKL_INT64 mode) NOTHROW;

#if (_OPENMP >= 202011)
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vmcsini))                     \
    match(construct = {dispatch}, device = {arch(gen)})                        \
        append_args(interop(prefer_type("sycl", "level_zero"), targetsync))    \
            adjust_args(need_device_ptr                                        \
                        : a) adjust_args(need_device_ptr                       \
                                         : y)
#endif
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vmcsini))                     \
    match(construct = {target variant dispatch}, device = {arch(gen)})
void vmcSinI(const MKL_INT n, const MKL_Complex8* a, MKL_INT inca,
             MKL_Complex8* y, MKL_INT incy, MKL_INT64 mode) NOTHROW;

#if (_OPENMP >= 202011)
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vzsin))                       \
    match(construct = {dispatch}, device = {arch(gen)})                        \
        append_args(interop(prefer_type("sycl", "level_zero"), targetsync))    \
            adjust_args(need_device_ptr                                        \
                        : a) adjust_args(need_device_ptr                       \
                                         : y)
#endif
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vzsin))                       \
    match(construct = {target variant dispatch}, device = {arch(gen)})
void vzSin(const MKL_INT n, const MKL_Complex16* a, MKL_Complex16* y) NOTHROW;

#if (_OPENMP >= 202011)
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vzsini))                      \
    match(construct = {dispatch}, device = {arch(gen)})                        \
        append_args(interop(prefer_type("sycl", "level_zero"), targetsync))    \
            adjust_args(need_device_ptr                                        \
                        : a) adjust_args(need_device_ptr                       \
                                         : y)
#endif
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vzsini))                      \
    match(construct = {target variant dispatch}, device = {arch(gen)})
void vzSinI(const MKL_INT n, const MKL_Complex16* a, MKL_INT inca,
            MKL_Complex16* y, MKL_INT incy) NOTHROW;

#if (_OPENMP >= 202011)
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vmzsin))                      \
    match(construct = {dispatch}, device = {arch(gen)})                        \
        append_args(interop(prefer_type("sycl", "level_zero"), targetsync))    \
            adjust_args(need_device_ptr                                        \
                        : a) adjust_args(need_device_ptr                       \
                                         : y)
#endif
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vmzsin))                      \
    match(construct = {target variant dispatch}, device = {arch(gen)})
void vmzSin(const MKL_INT n, const MKL_Complex16* a, MKL_Complex16* y,
            MKL_INT64 mode) NOTHROW;

#if (_OPENMP >= 202011)
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vmzsini))                     \
    match(construct = {dispatch}, device = {arch(gen)})                        \
        append_args(interop(prefer_type("sycl", "level_zero"), targetsync))    \
            adjust_args(need_device_ptr                                        \
                        : a) adjust_args(need_device_ptr                       \
                                         : y)
#endif
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vmzsini))                     \
    match(construct = {target variant dispatch}, device = {arch(gen)})
void vmzSinI(const MKL_INT n, const MKL_Complex16* a, MKL_INT inca,
             MKL_Complex16* y, MKL_INT incy, MKL_INT64 mode) NOTHROW;

// function sincos
#if (_OPENMP >= 202011)
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vssincos))                    \
    match(construct = {dispatch}, device = {arch(gen)})                        \
        append_args(interop(prefer_type("sycl", "level_zero"), targetsync))    \
            adjust_args(need_device_ptr                                        \
                        : a) adjust_args(need_device_ptr                       \
                                         : y) adjust_args(need_device_ptr      \
                                                          : z)
#endif
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vssincos))                    \
    match(construct = {target variant dispatch}, device = {arch(gen)})
void vsSinCos(const MKL_INT n, const float* a, float* y, float* z) NOTHROW;

#if (_OPENMP >= 202011)
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vssincosi))                   \
    match(construct = {dispatch}, device = {arch(gen)})                        \
        append_args(interop(prefer_type("sycl", "level_zero"), targetsync))    \
            adjust_args(need_device_ptr                                        \
                        : a) adjust_args(need_device_ptr                       \
                                         : y) adjust_args(need_device_ptr      \
                                                          : z)
#endif
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vssincosi))                   \
    match(construct = {target variant dispatch}, device = {arch(gen)})
void vsSinCosI(const MKL_INT n, const float* a, MKL_INT inca, float* y,
               MKL_INT incy, float* z, MKL_INT incz) NOTHROW;

#if (_OPENMP >= 202011)
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vmssincos))                   \
    match(construct = {dispatch}, device = {arch(gen)})                        \
        append_args(interop(prefer_type("sycl", "level_zero"), targetsync))    \
            adjust_args(need_device_ptr                                        \
                        : a) adjust_args(need_device_ptr                       \
                                         : y) adjust_args(need_device_ptr      \
                                                          : z)
#endif
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vmssincos))                   \
    match(construct = {target variant dispatch}, device = {arch(gen)})
void vmsSinCos(const MKL_INT n, const float* a, float* y, float* z,
               MKL_INT64 mode) NOTHROW;

#if (_OPENMP >= 202011)
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vmssincosi))                  \
    match(construct = {dispatch}, device = {arch(gen)})                        \
        append_args(interop(prefer_type("sycl", "level_zero"), targetsync))    \
            adjust_args(need_device_ptr                                        \
                        : a) adjust_args(need_device_ptr                       \
                                         : y) adjust_args(need_device_ptr      \
                                                          : z)
#endif
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vmssincosi))                  \
    match(construct = {target variant dispatch}, device = {arch(gen)})
void vmsSinCosI(const MKL_INT n, const float* a, MKL_INT inca, float* y,
                MKL_INT incy, float* z, MKL_INT incz, MKL_INT64 mode) NOTHROW;

#if (_OPENMP >= 202011)
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vdsincos))                    \
    match(construct = {dispatch}, device = {arch(gen)})                        \
        append_args(interop(prefer_type("sycl", "level_zero"), targetsync))    \
            adjust_args(need_device_ptr                                        \
                        : a) adjust_args(need_device_ptr                       \
                                         : y) adjust_args(need_device_ptr      \
                                                          : z)
#endif
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vdsincos))                    \
    match(construct = {target variant dispatch}, device = {arch(gen)})
void vdSinCos(const MKL_INT n, const double* a, double* y, double* z) NOTHROW;

#if (_OPENMP >= 202011)
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vdsincosi))                   \
    match(construct = {dispatch}, device = {arch(gen)})                        \
        append_args(interop(prefer_type("sycl", "level_zero"), targetsync))    \
            adjust_args(need_device_ptr                                        \
                        : a) adjust_args(need_device_ptr                       \
                                         : y) adjust_args(need_device_ptr      \
                                                          : z)
#endif
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vdsincosi))                   \
    match(construct = {target variant dispatch}, device = {arch(gen)})
void vdSinCosI(const MKL_INT n, const double* a, MKL_INT inca, double* y,
               MKL_INT incy, double* z, MKL_INT incz) NOTHROW;

#if (_OPENMP >= 202011)
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vmdsincos))                   \
    match(construct = {dispatch}, device = {arch(gen)})                        \
        append_args(interop(prefer_type("sycl", "level_zero"), targetsync))    \
            adjust_args(need_device_ptr                                        \
                        : a) adjust_args(need_device_ptr                       \
                                         : y) adjust_args(need_device_ptr      \
                                                          : z)
#endif
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vmdsincos))                   \
    match(construct = {target variant dispatch}, device = {arch(gen)})
void vmdSinCos(const MKL_INT n, const double* a, double* y, double* z,
               MKL_INT64 mode) NOTHROW;

#if (_OPENMP >= 202011)
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vmdsincosi))                  \
    match(construct = {dispatch}, device = {arch(gen)})                        \
        append_args(interop(prefer_type("sycl", "level_zero"), targetsync))    \
            adjust_args(need_device_ptr                                        \
                        : a) adjust_args(need_device_ptr                       \
                                         : y) adjust_args(need_device_ptr      \
                                                          : z)
#endif
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vmdsincosi))                  \
    match(construct = {target variant dispatch}, device = {arch(gen)})
void vmdSinCosI(const MKL_INT n, const double* a, MKL_INT inca, double* y,
                MKL_INT incy, double* z, MKL_INT incz, MKL_INT64 mode) NOTHROW;

// function sincospi

// function sind
#if (_OPENMP >= 202011)
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vssind))                      \
    match(construct = {dispatch}, device = {arch(gen)})                        \
        append_args(interop(prefer_type("sycl", "level_zero"), targetsync))    \
            adjust_args(need_device_ptr                                        \
                        : a) adjust_args(need_device_ptr                       \
                                         : y)
#endif
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vssind))                      \
    match(construct = {target variant dispatch}, device = {arch(gen)})
void vsSind(const MKL_INT n, const float* a, float* y) NOTHROW;

#if (_OPENMP >= 202011)
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vssindi))                     \
    match(construct = {dispatch}, device = {arch(gen)})                        \
        append_args(interop(prefer_type("sycl", "level_zero"), targetsync))    \
            adjust_args(need_device_ptr                                        \
                        : a) adjust_args(need_device_ptr                       \
                                         : y)
#endif
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vssindi))                     \
    match(construct = {target variant dispatch}, device = {arch(gen)})
void vsSindI(const MKL_INT n, const float* a, MKL_INT inca, float* y,
             MKL_INT incy) NOTHROW;

#if (_OPENMP >= 202011)
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vmssind))                     \
    match(construct = {dispatch}, device = {arch(gen)})                        \
        append_args(interop(prefer_type("sycl", "level_zero"), targetsync))    \
            adjust_args(need_device_ptr                                        \
                        : a) adjust_args(need_device_ptr                       \
                                         : y)
#endif
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vmssind))                     \
    match(construct = {target variant dispatch}, device = {arch(gen)})
void vmsSind(const MKL_INT n, const float* a, float* y, MKL_INT64 mode) NOTHROW;

#if (_OPENMP >= 202011)
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vmssindi))                    \
    match(construct = {dispatch}, device = {arch(gen)})                        \
        append_args(interop(prefer_type("sycl", "level_zero"), targetsync))    \
            adjust_args(need_device_ptr                                        \
                        : a) adjust_args(need_device_ptr                       \
                                         : y)
#endif
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vmssindi))                    \
    match(construct = {target variant dispatch}, device = {arch(gen)})
void vmsSindI(const MKL_INT n, const float* a, MKL_INT inca, float* y,
              MKL_INT incy, MKL_INT64 mode) NOTHROW;

#if (_OPENMP >= 202011)
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vdsind))                      \
    match(construct = {dispatch}, device = {arch(gen)})                        \
        append_args(interop(prefer_type("sycl", "level_zero"), targetsync))    \
            adjust_args(need_device_ptr                                        \
                        : a) adjust_args(need_device_ptr                       \
                                         : y)
#endif
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vdsind))                      \
    match(construct = {target variant dispatch}, device = {arch(gen)})
void vdSind(const MKL_INT n, const double* a, double* y) NOTHROW;

#if (_OPENMP >= 202011)
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vdsindi))                     \
    match(construct = {dispatch}, device = {arch(gen)})                        \
        append_args(interop(prefer_type("sycl", "level_zero"), targetsync))    \
            adjust_args(need_device_ptr                                        \
                        : a) adjust_args(need_device_ptr                       \
                                         : y)
#endif
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vdsindi))                     \
    match(construct = {target variant dispatch}, device = {arch(gen)})
void vdSindI(const MKL_INT n, const double* a, MKL_INT inca, double* y,
             MKL_INT incy) NOTHROW;

#if (_OPENMP >= 202011)
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vmdsind))                     \
    match(construct = {dispatch}, device = {arch(gen)})                        \
        append_args(interop(prefer_type("sycl", "level_zero"), targetsync))    \
            adjust_args(need_device_ptr                                        \
                        : a) adjust_args(need_device_ptr                       \
                                         : y)
#endif
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vmdsind))                     \
    match(construct = {target variant dispatch}, device = {arch(gen)})
void vmdSind(const MKL_INT n, const double* a, double* y,
             MKL_INT64 mode) NOTHROW;

#if (_OPENMP >= 202011)
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vmdsindi))                    \
    match(construct = {dispatch}, device = {arch(gen)})                        \
        append_args(interop(prefer_type("sycl", "level_zero"), targetsync))    \
            adjust_args(need_device_ptr                                        \
                        : a) adjust_args(need_device_ptr                       \
                                         : y)
#endif
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vmdsindi))                    \
    match(construct = {target variant dispatch}, device = {arch(gen)})
void vmdSindI(const MKL_INT n, const double* a, MKL_INT inca, double* y,
              MKL_INT incy, MKL_INT64 mode) NOTHROW;

// function sinh
#if (_OPENMP >= 202011)
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vssinh))                      \
    match(construct = {dispatch}, device = {arch(gen)})                        \
        append_args(interop(prefer_type("sycl", "level_zero"), targetsync))    \
            adjust_args(need_device_ptr                                        \
                        : a) adjust_args(need_device_ptr                       \
                                         : y)
#endif
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vssinh))                      \
    match(construct = {target variant dispatch}, device = {arch(gen)})
void vsSinh(const MKL_INT n, const float* a, float* y) NOTHROW;

#if (_OPENMP >= 202011)
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vssinhi))                     \
    match(construct = {dispatch}, device = {arch(gen)})                        \
        append_args(interop(prefer_type("sycl", "level_zero"), targetsync))    \
            adjust_args(need_device_ptr                                        \
                        : a) adjust_args(need_device_ptr                       \
                                         : y)
#endif
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vssinhi))                     \
    match(construct = {target variant dispatch}, device = {arch(gen)})
void vsSinhI(const MKL_INT n, const float* a, MKL_INT inca, float* y,
             MKL_INT incy) NOTHROW;

#if (_OPENMP >= 202011)
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vmssinh))                     \
    match(construct = {dispatch}, device = {arch(gen)})                        \
        append_args(interop(prefer_type("sycl", "level_zero"), targetsync))    \
            adjust_args(need_device_ptr                                        \
                        : a) adjust_args(need_device_ptr                       \
                                         : y)
#endif
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vmssinh))                     \
    match(construct = {target variant dispatch}, device = {arch(gen)})
void vmsSinh(const MKL_INT n, const float* a, float* y, MKL_INT64 mode) NOTHROW;

#if (_OPENMP >= 202011)
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vmssinhi))                    \
    match(construct = {dispatch}, device = {arch(gen)})                        \
        append_args(interop(prefer_type("sycl", "level_zero"), targetsync))    \
            adjust_args(need_device_ptr                                        \
                        : a) adjust_args(need_device_ptr                       \
                                         : y)
#endif
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vmssinhi))                    \
    match(construct = {target variant dispatch}, device = {arch(gen)})
void vmsSinhI(const MKL_INT n, const float* a, MKL_INT inca, float* y,
              MKL_INT incy, MKL_INT64 mode) NOTHROW;

#if (_OPENMP >= 202011)
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vdsinh))                      \
    match(construct = {dispatch}, device = {arch(gen)})                        \
        append_args(interop(prefer_type("sycl", "level_zero"), targetsync))    \
            adjust_args(need_device_ptr                                        \
                        : a) adjust_args(need_device_ptr                       \
                                         : y)
#endif
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vdsinh))                      \
    match(construct = {target variant dispatch}, device = {arch(gen)})
void vdSinh(const MKL_INT n, const double* a, double* y) NOTHROW;

#if (_OPENMP >= 202011)
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vdsinhi))                     \
    match(construct = {dispatch}, device = {arch(gen)})                        \
        append_args(interop(prefer_type("sycl", "level_zero"), targetsync))    \
            adjust_args(need_device_ptr                                        \
                        : a) adjust_args(need_device_ptr                       \
                                         : y)
#endif
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vdsinhi))                     \
    match(construct = {target variant dispatch}, device = {arch(gen)})
void vdSinhI(const MKL_INT n, const double* a, MKL_INT inca, double* y,
             MKL_INT incy) NOTHROW;

#if (_OPENMP >= 202011)
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vmdsinh))                     \
    match(construct = {dispatch}, device = {arch(gen)})                        \
        append_args(interop(prefer_type("sycl", "level_zero"), targetsync))    \
            adjust_args(need_device_ptr                                        \
                        : a) adjust_args(need_device_ptr                       \
                                         : y)
#endif
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vmdsinh))                     \
    match(construct = {target variant dispatch}, device = {arch(gen)})
void vmdSinh(const MKL_INT n, const double* a, double* y,
             MKL_INT64 mode) NOTHROW;

#if (_OPENMP >= 202011)
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vmdsinhi))                    \
    match(construct = {dispatch}, device = {arch(gen)})                        \
        append_args(interop(prefer_type("sycl", "level_zero"), targetsync))    \
            adjust_args(need_device_ptr                                        \
                        : a) adjust_args(need_device_ptr                       \
                                         : y)
#endif
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vmdsinhi))                    \
    match(construct = {target variant dispatch}, device = {arch(gen)})
void vmdSinhI(const MKL_INT n, const double* a, MKL_INT inca, double* y,
              MKL_INT incy, MKL_INT64 mode) NOTHROW;

#if (_OPENMP >= 202011)
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vcsinh))                      \
    match(construct = {dispatch}, device = {arch(gen)})                        \
        append_args(interop(prefer_type("sycl", "level_zero"), targetsync))    \
            adjust_args(need_device_ptr                                        \
                        : a) adjust_args(need_device_ptr                       \
                                         : y)
#endif
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vcsinh))                      \
    match(construct = {target variant dispatch}, device = {arch(gen)})
void vcSinh(const MKL_INT n, const MKL_Complex8* a, MKL_Complex8* y) NOTHROW;

#if (_OPENMP >= 202011)
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vcsinhi))                     \
    match(construct = {dispatch}, device = {arch(gen)})                        \
        append_args(interop(prefer_type("sycl", "level_zero"), targetsync))    \
            adjust_args(need_device_ptr                                        \
                        : a) adjust_args(need_device_ptr                       \
                                         : y)
#endif
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vcsinhi))                     \
    match(construct = {target variant dispatch}, device = {arch(gen)})
void vcSinhI(const MKL_INT n, const MKL_Complex8* a, MKL_INT inca,
             MKL_Complex8* y, MKL_INT incy) NOTHROW;

#if (_OPENMP >= 202011)
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vmcsinh))                     \
    match(construct = {dispatch}, device = {arch(gen)})                        \
        append_args(interop(prefer_type("sycl", "level_zero"), targetsync))    \
            adjust_args(need_device_ptr                                        \
                        : a) adjust_args(need_device_ptr                       \
                                         : y)
#endif
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vmcsinh))                     \
    match(construct = {target variant dispatch}, device = {arch(gen)})
void vmcSinh(const MKL_INT n, const MKL_Complex8* a, MKL_Complex8* y,
             MKL_INT64 mode) NOTHROW;

#if (_OPENMP >= 202011)
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vmcsinhi))                    \
    match(construct = {dispatch}, device = {arch(gen)})                        \
        append_args(interop(prefer_type("sycl", "level_zero"), targetsync))    \
            adjust_args(need_device_ptr                                        \
                        : a) adjust_args(need_device_ptr                       \
                                         : y)
#endif
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vmcsinhi))                    \
    match(construct = {target variant dispatch}, device = {arch(gen)})
void vmcSinhI(const MKL_INT n, const MKL_Complex8* a, MKL_INT inca,
              MKL_Complex8* y, MKL_INT incy, MKL_INT64 mode) NOTHROW;

#if (_OPENMP >= 202011)
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vzsinh))                      \
    match(construct = {dispatch}, device = {arch(gen)})                        \
        append_args(interop(prefer_type("sycl", "level_zero"), targetsync))    \
            adjust_args(need_device_ptr                                        \
                        : a) adjust_args(need_device_ptr                       \
                                         : y)
#endif
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vzsinh))                      \
    match(construct = {target variant dispatch}, device = {arch(gen)})
void vzSinh(const MKL_INT n, const MKL_Complex16* a, MKL_Complex16* y) NOTHROW;

#if (_OPENMP >= 202011)
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vzsinhi))                     \
    match(construct = {dispatch}, device = {arch(gen)})                        \
        append_args(interop(prefer_type("sycl", "level_zero"), targetsync))    \
            adjust_args(need_device_ptr                                        \
                        : a) adjust_args(need_device_ptr                       \
                                         : y)
#endif
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vzsinhi))                     \
    match(construct = {target variant dispatch}, device = {arch(gen)})
void vzSinhI(const MKL_INT n, const MKL_Complex16* a, MKL_INT inca,
             MKL_Complex16* y, MKL_INT incy) NOTHROW;

#if (_OPENMP >= 202011)
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vmzsinh))                     \
    match(construct = {dispatch}, device = {arch(gen)})                        \
        append_args(interop(prefer_type("sycl", "level_zero"), targetsync))    \
            adjust_args(need_device_ptr                                        \
                        : a) adjust_args(need_device_ptr                       \
                                         : y)
#endif
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vmzsinh))                     \
    match(construct = {target variant dispatch}, device = {arch(gen)})
void vmzSinh(const MKL_INT n, const MKL_Complex16* a, MKL_Complex16* y,
             MKL_INT64 mode) NOTHROW;

#if (_OPENMP >= 202011)
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vmzsinhi))                    \
    match(construct = {dispatch}, device = {arch(gen)})                        \
        append_args(interop(prefer_type("sycl", "level_zero"), targetsync))    \
            adjust_args(need_device_ptr                                        \
                        : a) adjust_args(need_device_ptr                       \
                                         : y)
#endif
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vmzsinhi))                    \
    match(construct = {target variant dispatch}, device = {arch(gen)})
void vmzSinhI(const MKL_INT n, const MKL_Complex16* a, MKL_INT inca,
              MKL_Complex16* y, MKL_INT incy, MKL_INT64 mode) NOTHROW;

// function sinpi
#if (_OPENMP >= 202011)
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vssinpi))                     \
    match(construct = {dispatch}, device = {arch(gen)})                        \
        append_args(interop(prefer_type("sycl", "level_zero"), targetsync))    \
            adjust_args(need_device_ptr                                        \
                        : a) adjust_args(need_device_ptr                       \
                                         : y)
#endif
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vssinpi))                     \
    match(construct = {target variant dispatch}, device = {arch(gen)})
void vsSinpi(const MKL_INT n, const float* a, float* y) NOTHROW;

#if (_OPENMP >= 202011)
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vssinpii))                    \
    match(construct = {dispatch}, device = {arch(gen)})                        \
        append_args(interop(prefer_type("sycl", "level_zero"), targetsync))    \
            adjust_args(need_device_ptr                                        \
                        : a) adjust_args(need_device_ptr                       \
                                         : y)
#endif
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vssinpii))                    \
    match(construct = {target variant dispatch}, device = {arch(gen)})
void vsSinpiI(const MKL_INT n, const float* a, MKL_INT inca, float* y,
              MKL_INT incy) NOTHROW;

#if (_OPENMP >= 202011)
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vmssinpi))                    \
    match(construct = {dispatch}, device = {arch(gen)})                        \
        append_args(interop(prefer_type("sycl", "level_zero"), targetsync))    \
            adjust_args(need_device_ptr                                        \
                        : a) adjust_args(need_device_ptr                       \
                                         : y)
#endif
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vmssinpi))                    \
    match(construct = {target variant dispatch}, device = {arch(gen)})
void vmsSinpi(const MKL_INT n, const float* a, float* y,
              MKL_INT64 mode) NOTHROW;

#if (_OPENMP >= 202011)
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vmssinpii))                   \
    match(construct = {dispatch}, device = {arch(gen)})                        \
        append_args(interop(prefer_type("sycl", "level_zero"), targetsync))    \
            adjust_args(need_device_ptr                                        \
                        : a) adjust_args(need_device_ptr                       \
                                         : y)
#endif
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vmssinpii))                   \
    match(construct = {target variant dispatch}, device = {arch(gen)})
void vmsSinpiI(const MKL_INT n, const float* a, MKL_INT inca, float* y,
               MKL_INT incy, MKL_INT64 mode) NOTHROW;

#if (_OPENMP >= 202011)
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vdsinpi))                     \
    match(construct = {dispatch}, device = {arch(gen)})                        \
        append_args(interop(prefer_type("sycl", "level_zero"), targetsync))    \
            adjust_args(need_device_ptr                                        \
                        : a) adjust_args(need_device_ptr                       \
                                         : y)
#endif
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vdsinpi))                     \
    match(construct = {target variant dispatch}, device = {arch(gen)})
void vdSinpi(const MKL_INT n, const double* a, double* y) NOTHROW;

#if (_OPENMP >= 202011)
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vdsinpii))                    \
    match(construct = {dispatch}, device = {arch(gen)})                        \
        append_args(interop(prefer_type("sycl", "level_zero"), targetsync))    \
            adjust_args(need_device_ptr                                        \
                        : a) adjust_args(need_device_ptr                       \
                                         : y)
#endif
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vdsinpii))                    \
    match(construct = {target variant dispatch}, device = {arch(gen)})
void vdSinpiI(const MKL_INT n, const double* a, MKL_INT inca, double* y,
              MKL_INT incy) NOTHROW;

#if (_OPENMP >= 202011)
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vmdsinpi))                    \
    match(construct = {dispatch}, device = {arch(gen)})                        \
        append_args(interop(prefer_type("sycl", "level_zero"), targetsync))    \
            adjust_args(need_device_ptr                                        \
                        : a) adjust_args(need_device_ptr                       \
                                         : y)
#endif
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vmdsinpi))                    \
    match(construct = {target variant dispatch}, device = {arch(gen)})
void vmdSinpi(const MKL_INT n, const double* a, double* y,
              MKL_INT64 mode) NOTHROW;

#if (_OPENMP >= 202011)
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vmdsinpii))                   \
    match(construct = {dispatch}, device = {arch(gen)})                        \
        append_args(interop(prefer_type("sycl", "level_zero"), targetsync))    \
            adjust_args(need_device_ptr                                        \
                        : a) adjust_args(need_device_ptr                       \
                                         : y)
#endif
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vmdsinpii))                   \
    match(construct = {target variant dispatch}, device = {arch(gen)})
void vmdSinpiI(const MKL_INT n, const double* a, MKL_INT inca, double* y,
               MKL_INT incy, MKL_INT64 mode) NOTHROW;

// function sqr
#if (_OPENMP >= 202011)
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vssqr))                       \
    match(construct = {dispatch}, device = {arch(gen)})                        \
        append_args(interop(prefer_type("sycl", "level_zero"), targetsync))    \
            adjust_args(need_device_ptr                                        \
                        : a) adjust_args(need_device_ptr                       \
                                         : y)
#endif
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vssqr))                       \
    match(construct = {target variant dispatch}, device = {arch(gen)})
void vsSqr(const MKL_INT n, const float* a, float* y) NOTHROW;

#if (_OPENMP >= 202011)
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vssqri))                      \
    match(construct = {dispatch}, device = {arch(gen)})                        \
        append_args(interop(prefer_type("sycl", "level_zero"), targetsync))    \
            adjust_args(need_device_ptr                                        \
                        : a) adjust_args(need_device_ptr                       \
                                         : y)
#endif
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vssqri))                      \
    match(construct = {target variant dispatch}, device = {arch(gen)})
void vsSqrI(const MKL_INT n, const float* a, MKL_INT inca, float* y,
            MKL_INT incy) NOTHROW;

#if (_OPENMP >= 202011)
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vmssqr))                      \
    match(construct = {dispatch}, device = {arch(gen)})                        \
        append_args(interop(prefer_type("sycl", "level_zero"), targetsync))    \
            adjust_args(need_device_ptr                                        \
                        : a) adjust_args(need_device_ptr                       \
                                         : y)
#endif
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vmssqr))                      \
    match(construct = {target variant dispatch}, device = {arch(gen)})
void vmsSqr(const MKL_INT n, const float* a, float* y, MKL_INT64 mode) NOTHROW;

#if (_OPENMP >= 202011)
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vmssqri))                     \
    match(construct = {dispatch}, device = {arch(gen)})                        \
        append_args(interop(prefer_type("sycl", "level_zero"), targetsync))    \
            adjust_args(need_device_ptr                                        \
                        : a) adjust_args(need_device_ptr                       \
                                         : y)
#endif
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vmssqri))                     \
    match(construct = {target variant dispatch}, device = {arch(gen)})
void vmsSqrI(const MKL_INT n, const float* a, MKL_INT inca, float* y,
             MKL_INT incy, MKL_INT64 mode) NOTHROW;

#if (_OPENMP >= 202011)
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vdsqr))                       \
    match(construct = {dispatch}, device = {arch(gen)})                        \
        append_args(interop(prefer_type("sycl", "level_zero"), targetsync))    \
            adjust_args(need_device_ptr                                        \
                        : a) adjust_args(need_device_ptr                       \
                                         : y)
#endif
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vdsqr))                       \
    match(construct = {target variant dispatch}, device = {arch(gen)})
void vdSqr(const MKL_INT n, const double* a, double* y) NOTHROW;

#if (_OPENMP >= 202011)
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vdsqri))                      \
    match(construct = {dispatch}, device = {arch(gen)})                        \
        append_args(interop(prefer_type("sycl", "level_zero"), targetsync))    \
            adjust_args(need_device_ptr                                        \
                        : a) adjust_args(need_device_ptr                       \
                                         : y)
#endif
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vdsqri))                      \
    match(construct = {target variant dispatch}, device = {arch(gen)})
void vdSqrI(const MKL_INT n, const double* a, MKL_INT inca, double* y,
            MKL_INT incy) NOTHROW;

#if (_OPENMP >= 202011)
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vmdsqr))                      \
    match(construct = {dispatch}, device = {arch(gen)})                        \
        append_args(interop(prefer_type("sycl", "level_zero"), targetsync))    \
            adjust_args(need_device_ptr                                        \
                        : a) adjust_args(need_device_ptr                       \
                                         : y)
#endif
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vmdsqr))                      \
    match(construct = {target variant dispatch}, device = {arch(gen)})
void vmdSqr(const MKL_INT n, const double* a, double* y,
            MKL_INT64 mode) NOTHROW;

#if (_OPENMP >= 202011)
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vmdsqri))                     \
    match(construct = {dispatch}, device = {arch(gen)})                        \
        append_args(interop(prefer_type("sycl", "level_zero"), targetsync))    \
            adjust_args(need_device_ptr                                        \
                        : a) adjust_args(need_device_ptr                       \
                                         : y)
#endif
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vmdsqri))                     \
    match(construct = {target variant dispatch}, device = {arch(gen)})
void vmdSqrI(const MKL_INT n, const double* a, MKL_INT inca, double* y,
             MKL_INT incy, MKL_INT64 mode) NOTHROW;

// function sqrt
#if (_OPENMP >= 202011)
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vssqrt))                      \
    match(construct = {dispatch}, device = {arch(gen)})                        \
        append_args(interop(prefer_type("sycl", "level_zero"), targetsync))    \
            adjust_args(need_device_ptr                                        \
                        : a) adjust_args(need_device_ptr                       \
                                         : y)
#endif
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vssqrt))                      \
    match(construct = {target variant dispatch}, device = {arch(gen)})
void vsSqrt(const MKL_INT n, const float* a, float* y) NOTHROW;

#if (_OPENMP >= 202011)
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vssqrti))                     \
    match(construct = {dispatch}, device = {arch(gen)})                        \
        append_args(interop(prefer_type("sycl", "level_zero"), targetsync))    \
            adjust_args(need_device_ptr                                        \
                        : a) adjust_args(need_device_ptr                       \
                                         : y)
#endif
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vssqrti))                     \
    match(construct = {target variant dispatch}, device = {arch(gen)})
void vsSqrtI(const MKL_INT n, const float* a, MKL_INT inca, float* y,
             MKL_INT incy) NOTHROW;

#if (_OPENMP >= 202011)
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vmssqrt))                     \
    match(construct = {dispatch}, device = {arch(gen)})                        \
        append_args(interop(prefer_type("sycl", "level_zero"), targetsync))    \
            adjust_args(need_device_ptr                                        \
                        : a) adjust_args(need_device_ptr                       \
                                         : y)
#endif
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vmssqrt))                     \
    match(construct = {target variant dispatch}, device = {arch(gen)})
void vmsSqrt(const MKL_INT n, const float* a, float* y, MKL_INT64 mode) NOTHROW;

#if (_OPENMP >= 202011)
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vmssqrti))                    \
    match(construct = {dispatch}, device = {arch(gen)})                        \
        append_args(interop(prefer_type("sycl", "level_zero"), targetsync))    \
            adjust_args(need_device_ptr                                        \
                        : a) adjust_args(need_device_ptr                       \
                                         : y)
#endif
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vmssqrti))                    \
    match(construct = {target variant dispatch}, device = {arch(gen)})
void vmsSqrtI(const MKL_INT n, const float* a, MKL_INT inca, float* y,
              MKL_INT incy, MKL_INT64 mode) NOTHROW;

#if (_OPENMP >= 202011)
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vdsqrt))                      \
    match(construct = {dispatch}, device = {arch(gen)})                        \
        append_args(interop(prefer_type("sycl", "level_zero"), targetsync))    \
            adjust_args(need_device_ptr                                        \
                        : a) adjust_args(need_device_ptr                       \
                                         : y)
#endif
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vdsqrt))                      \
    match(construct = {target variant dispatch}, device = {arch(gen)})
void vdSqrt(const MKL_INT n, const double* a, double* y) NOTHROW;

#if (_OPENMP >= 202011)
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vdsqrti))                     \
    match(construct = {dispatch}, device = {arch(gen)})                        \
        append_args(interop(prefer_type("sycl", "level_zero"), targetsync))    \
            adjust_args(need_device_ptr                                        \
                        : a) adjust_args(need_device_ptr                       \
                                         : y)
#endif
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vdsqrti))                     \
    match(construct = {target variant dispatch}, device = {arch(gen)})
void vdSqrtI(const MKL_INT n, const double* a, MKL_INT inca, double* y,
             MKL_INT incy) NOTHROW;

#if (_OPENMP >= 202011)
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vmdsqrt))                     \
    match(construct = {dispatch}, device = {arch(gen)})                        \
        append_args(interop(prefer_type("sycl", "level_zero"), targetsync))    \
            adjust_args(need_device_ptr                                        \
                        : a) adjust_args(need_device_ptr                       \
                                         : y)
#endif
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vmdsqrt))                     \
    match(construct = {target variant dispatch}, device = {arch(gen)})
void vmdSqrt(const MKL_INT n, const double* a, double* y,
             MKL_INT64 mode) NOTHROW;

#if (_OPENMP >= 202011)
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vmdsqrti))                    \
    match(construct = {dispatch}, device = {arch(gen)})                        \
        append_args(interop(prefer_type("sycl", "level_zero"), targetsync))    \
            adjust_args(need_device_ptr                                        \
                        : a) adjust_args(need_device_ptr                       \
                                         : y)
#endif
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vmdsqrti))                    \
    match(construct = {target variant dispatch}, device = {arch(gen)})
void vmdSqrtI(const MKL_INT n, const double* a, MKL_INT inca, double* y,
              MKL_INT incy, MKL_INT64 mode) NOTHROW;

#if (_OPENMP >= 202011)
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vcsqrt))                      \
    match(construct = {dispatch}, device = {arch(gen)})                        \
        append_args(interop(prefer_type("sycl", "level_zero"), targetsync))    \
            adjust_args(need_device_ptr                                        \
                        : a) adjust_args(need_device_ptr                       \
                                         : y)
#endif
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vcsqrt))                      \
    match(construct = {target variant dispatch}, device = {arch(gen)})
void vcSqrt(const MKL_INT n, const MKL_Complex8* a, MKL_Complex8* y) NOTHROW;

#if (_OPENMP >= 202011)
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vcsqrti))                     \
    match(construct = {dispatch}, device = {arch(gen)})                        \
        append_args(interop(prefer_type("sycl", "level_zero"), targetsync))    \
            adjust_args(need_device_ptr                                        \
                        : a) adjust_args(need_device_ptr                       \
                                         : y)
#endif
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vcsqrti))                     \
    match(construct = {target variant dispatch}, device = {arch(gen)})
void vcSqrtI(const MKL_INT n, const MKL_Complex8* a, MKL_INT inca,
             MKL_Complex8* y, MKL_INT incy) NOTHROW;

#if (_OPENMP >= 202011)
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vmcsqrt))                     \
    match(construct = {dispatch}, device = {arch(gen)})                        \
        append_args(interop(prefer_type("sycl", "level_zero"), targetsync))    \
            adjust_args(need_device_ptr                                        \
                        : a) adjust_args(need_device_ptr                       \
                                         : y)
#endif
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vmcsqrt))                     \
    match(construct = {target variant dispatch}, device = {arch(gen)})
void vmcSqrt(const MKL_INT n, const MKL_Complex8* a, MKL_Complex8* y,
             MKL_INT64 mode) NOTHROW;

#if (_OPENMP >= 202011)
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vmcsqrti))                    \
    match(construct = {dispatch}, device = {arch(gen)})                        \
        append_args(interop(prefer_type("sycl", "level_zero"), targetsync))    \
            adjust_args(need_device_ptr                                        \
                        : a) adjust_args(need_device_ptr                       \
                                         : y)
#endif
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vmcsqrti))                    \
    match(construct = {target variant dispatch}, device = {arch(gen)})
void vmcSqrtI(const MKL_INT n, const MKL_Complex8* a, MKL_INT inca,
              MKL_Complex8* y, MKL_INT incy, MKL_INT64 mode) NOTHROW;

#if (_OPENMP >= 202011)
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vzsqrt))                      \
    match(construct = {dispatch}, device = {arch(gen)})                        \
        append_args(interop(prefer_type("sycl", "level_zero"), targetsync))    \
            adjust_args(need_device_ptr                                        \
                        : a) adjust_args(need_device_ptr                       \
                                         : y)
#endif
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vzsqrt))                      \
    match(construct = {target variant dispatch}, device = {arch(gen)})
void vzSqrt(const MKL_INT n, const MKL_Complex16* a, MKL_Complex16* y) NOTHROW;

#if (_OPENMP >= 202011)
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vzsqrti))                     \
    match(construct = {dispatch}, device = {arch(gen)})                        \
        append_args(interop(prefer_type("sycl", "level_zero"), targetsync))    \
            adjust_args(need_device_ptr                                        \
                        : a) adjust_args(need_device_ptr                       \
                                         : y)
#endif
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vzsqrti))                     \
    match(construct = {target variant dispatch}, device = {arch(gen)})
void vzSqrtI(const MKL_INT n, const MKL_Complex16* a, MKL_INT inca,
             MKL_Complex16* y, MKL_INT incy) NOTHROW;

#if (_OPENMP >= 202011)
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vmzsqrt))                     \
    match(construct = {dispatch}, device = {arch(gen)})                        \
        append_args(interop(prefer_type("sycl", "level_zero"), targetsync))    \
            adjust_args(need_device_ptr                                        \
                        : a) adjust_args(need_device_ptr                       \
                                         : y)
#endif
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vmzsqrt))                     \
    match(construct = {target variant dispatch}, device = {arch(gen)})
void vmzSqrt(const MKL_INT n, const MKL_Complex16* a, MKL_Complex16* y,
             MKL_INT64 mode) NOTHROW;

#if (_OPENMP >= 202011)
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vmzsqrti))                    \
    match(construct = {dispatch}, device = {arch(gen)})                        \
        append_args(interop(prefer_type("sycl", "level_zero"), targetsync))    \
            adjust_args(need_device_ptr                                        \
                        : a) adjust_args(need_device_ptr                       \
                                         : y)
#endif
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vmzsqrti))                    \
    match(construct = {target variant dispatch}, device = {arch(gen)})
void vmzSqrtI(const MKL_INT n, const MKL_Complex16* a, MKL_INT inca,
              MKL_Complex16* y, MKL_INT incy, MKL_INT64 mode) NOTHROW;

// function sub
#if (_OPENMP >= 202011)
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vssub))                       \
    match(construct = {dispatch}, device = {arch(gen)})                        \
        append_args(interop(prefer_type("sycl", "level_zero"), targetsync))    \
            adjust_args(need_device_ptr                                        \
                        : a) adjust_args(need_device_ptr                       \
                                         : b) adjust_args(need_device_ptr      \
                                                          : y)
#endif
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vssub))                       \
    match(construct = {target variant dispatch}, device = {arch(gen)})
void vsSub(const MKL_INT n, const float* a, const float* b, float* y) NOTHROW;

#if (_OPENMP >= 202011)
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vssubi))                      \
    match(construct = {dispatch}, device = {arch(gen)})                        \
        append_args(interop(prefer_type("sycl", "level_zero"), targetsync))    \
            adjust_args(need_device_ptr                                        \
                        : a) adjust_args(need_device_ptr                       \
                                         : b) adjust_args(need_device_ptr      \
                                                          : y)
#endif
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vssubi))                      \
    match(construct = {target variant dispatch}, device = {arch(gen)})
void vsSubI(const MKL_INT n, const float* a, MKL_INT inca, const float* b,
            MKL_INT incb, float* y, MKL_INT incy) NOTHROW;

#if (_OPENMP >= 202011)
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vmssub))                      \
    match(construct = {dispatch}, device = {arch(gen)})                        \
        append_args(interop(prefer_type("sycl", "level_zero"), targetsync))    \
            adjust_args(need_device_ptr                                        \
                        : a) adjust_args(need_device_ptr                       \
                                         : b) adjust_args(need_device_ptr      \
                                                          : y)
#endif
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vmssub))                      \
    match(construct = {target variant dispatch}, device = {arch(gen)})
void vmsSub(const MKL_INT n, const float* a, const float* b, float* y,
            MKL_INT64 mode) NOTHROW;

#if (_OPENMP >= 202011)
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vmssubi))                     \
    match(construct = {dispatch}, device = {arch(gen)})                        \
        append_args(interop(prefer_type("sycl", "level_zero"), targetsync))    \
            adjust_args(need_device_ptr                                        \
                        : a) adjust_args(need_device_ptr                       \
                                         : b) adjust_args(need_device_ptr      \
                                                          : y)
#endif
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vmssubi))                     \
    match(construct = {target variant dispatch}, device = {arch(gen)})
void vmsSubI(const MKL_INT n, const float* a, MKL_INT inca, const float* b,
             MKL_INT incb, float* y, MKL_INT incy, MKL_INT64 mode) NOTHROW;

#if (_OPENMP >= 202011)
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vdsub))                       \
    match(construct = {dispatch}, device = {arch(gen)})                        \
        append_args(interop(prefer_type("sycl", "level_zero"), targetsync))    \
            adjust_args(need_device_ptr                                        \
                        : a) adjust_args(need_device_ptr                       \
                                         : b) adjust_args(need_device_ptr      \
                                                          : y)
#endif
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vdsub))                       \
    match(construct = {target variant dispatch}, device = {arch(gen)})
void vdSub(const MKL_INT n, const double* a, const double* b,
           double* y) NOTHROW;

#if (_OPENMP >= 202011)
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vdsubi))                      \
    match(construct = {dispatch}, device = {arch(gen)})                        \
        append_args(interop(prefer_type("sycl", "level_zero"), targetsync))    \
            adjust_args(need_device_ptr                                        \
                        : a) adjust_args(need_device_ptr                       \
                                         : b) adjust_args(need_device_ptr      \
                                                          : y)
#endif
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vdsubi))                      \
    match(construct = {target variant dispatch}, device = {arch(gen)})
void vdSubI(const MKL_INT n, const double* a, MKL_INT inca, const double* b,
            MKL_INT incb, double* y, MKL_INT incy) NOTHROW;

#if (_OPENMP >= 202011)
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vmdsub))                      \
    match(construct = {dispatch}, device = {arch(gen)})                        \
        append_args(interop(prefer_type("sycl", "level_zero"), targetsync))    \
            adjust_args(need_device_ptr                                        \
                        : a) adjust_args(need_device_ptr                       \
                                         : b) adjust_args(need_device_ptr      \
                                                          : y)
#endif
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vmdsub))                      \
    match(construct = {target variant dispatch}, device = {arch(gen)})
void vmdSub(const MKL_INT n, const double* a, const double* b, double* y,
            MKL_INT64 mode) NOTHROW;

#if (_OPENMP >= 202011)
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vmdsubi))                     \
    match(construct = {dispatch}, device = {arch(gen)})                        \
        append_args(interop(prefer_type("sycl", "level_zero"), targetsync))    \
            adjust_args(need_device_ptr                                        \
                        : a) adjust_args(need_device_ptr                       \
                                         : b) adjust_args(need_device_ptr      \
                                                          : y)
#endif
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vmdsubi))                     \
    match(construct = {target variant dispatch}, device = {arch(gen)})
void vmdSubI(const MKL_INT n, const double* a, MKL_INT inca, const double* b,
             MKL_INT incb, double* y, MKL_INT incy, MKL_INT64 mode) NOTHROW;

#if (_OPENMP >= 202011)
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vcsub))                       \
    match(construct = {dispatch}, device = {arch(gen)})                        \
        append_args(interop(prefer_type("sycl", "level_zero"), targetsync))    \
            adjust_args(need_device_ptr                                        \
                        : a) adjust_args(need_device_ptr                       \
                                         : b) adjust_args(need_device_ptr      \
                                                          : y)
#endif
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vcsub))                       \
    match(construct = {target variant dispatch}, device = {arch(gen)})
void vcSub(const MKL_INT n, const MKL_Complex8* a, const MKL_Complex8* b,
           MKL_Complex8* y) NOTHROW;

#if (_OPENMP >= 202011)
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vcsubi))                      \
    match(construct = {dispatch}, device = {arch(gen)})                        \
        append_args(interop(prefer_type("sycl", "level_zero"), targetsync))    \
            adjust_args(need_device_ptr                                        \
                        : a) adjust_args(need_device_ptr                       \
                                         : b) adjust_args(need_device_ptr      \
                                                          : y)
#endif
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vcsubi))                      \
    match(construct = {target variant dispatch}, device = {arch(gen)})
void vcSubI(const MKL_INT n, const MKL_Complex8* a, MKL_INT inca,
            const MKL_Complex8* b, MKL_INT incb, MKL_Complex8* y,
            MKL_INT incy) NOTHROW;

#if (_OPENMP >= 202011)
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vmcsub))                      \
    match(construct = {dispatch}, device = {arch(gen)})                        \
        append_args(interop(prefer_type("sycl", "level_zero"), targetsync))    \
            adjust_args(need_device_ptr                                        \
                        : a) adjust_args(need_device_ptr                       \
                                         : b) adjust_args(need_device_ptr      \
                                                          : y)
#endif
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vmcsub))                      \
    match(construct = {target variant dispatch}, device = {arch(gen)})
void vmcSub(const MKL_INT n, const MKL_Complex8* a, const MKL_Complex8* b,
            MKL_Complex8* y, MKL_INT64 mode) NOTHROW;

#if (_OPENMP >= 202011)
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vmcsubi))                     \
    match(construct = {dispatch}, device = {arch(gen)})                        \
        append_args(interop(prefer_type("sycl", "level_zero"), targetsync))    \
            adjust_args(need_device_ptr                                        \
                        : a) adjust_args(need_device_ptr                       \
                                         : b) adjust_args(need_device_ptr      \
                                                          : y)
#endif
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vmcsubi))                     \
    match(construct = {target variant dispatch}, device = {arch(gen)})
void vmcSubI(const MKL_INT n, const MKL_Complex8* a, MKL_INT inca,
             const MKL_Complex8* b, MKL_INT incb, MKL_Complex8* y, MKL_INT incy,
             MKL_INT64 mode) NOTHROW;

#if (_OPENMP >= 202011)
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vzsub))                       \
    match(construct = {dispatch}, device = {arch(gen)})                        \
        append_args(interop(prefer_type("sycl", "level_zero"), targetsync))    \
            adjust_args(need_device_ptr                                        \
                        : a) adjust_args(need_device_ptr                       \
                                         : b) adjust_args(need_device_ptr      \
                                                          : y)
#endif
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vzsub))                       \
    match(construct = {target variant dispatch}, device = {arch(gen)})
void vzSub(const MKL_INT n, const MKL_Complex16* a, const MKL_Complex16* b,
           MKL_Complex16* y) NOTHROW;

#if (_OPENMP >= 202011)
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vzsubi))                      \
    match(construct = {dispatch}, device = {arch(gen)})                        \
        append_args(interop(prefer_type("sycl", "level_zero"), targetsync))    \
            adjust_args(need_device_ptr                                        \
                        : a) adjust_args(need_device_ptr                       \
                                         : b) adjust_args(need_device_ptr      \
                                                          : y)
#endif
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vzsubi))                      \
    match(construct = {target variant dispatch}, device = {arch(gen)})
void vzSubI(const MKL_INT n, const MKL_Complex16* a, MKL_INT inca,
            const MKL_Complex16* b, MKL_INT incb, MKL_Complex16* y,
            MKL_INT incy) NOTHROW;

#if (_OPENMP >= 202011)
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vmzsub))                      \
    match(construct = {dispatch}, device = {arch(gen)})                        \
        append_args(interop(prefer_type("sycl", "level_zero"), targetsync))    \
            adjust_args(need_device_ptr                                        \
                        : a) adjust_args(need_device_ptr                       \
                                         : b) adjust_args(need_device_ptr      \
                                                          : y)
#endif
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vmzsub))                      \
    match(construct = {target variant dispatch}, device = {arch(gen)})
void vmzSub(const MKL_INT n, const MKL_Complex16* a, const MKL_Complex16* b,
            MKL_Complex16* y, MKL_INT64 mode) NOTHROW;

#if (_OPENMP >= 202011)
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vmzsubi))                     \
    match(construct = {dispatch}, device = {arch(gen)})                        \
        append_args(interop(prefer_type("sycl", "level_zero"), targetsync))    \
            adjust_args(need_device_ptr                                        \
                        : a) adjust_args(need_device_ptr                       \
                                         : b) adjust_args(need_device_ptr      \
                                                          : y)
#endif
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vmzsubi))                     \
    match(construct = {target variant dispatch}, device = {arch(gen)})
void vmzSubI(const MKL_INT n, const MKL_Complex16* a, MKL_INT inca,
             const MKL_Complex16* b, MKL_INT incb, MKL_Complex16* y,
             MKL_INT incy, MKL_INT64 mode) NOTHROW;

// function tan
#if (_OPENMP >= 202011)
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vstan))                       \
    match(construct = {dispatch}, device = {arch(gen)})                        \
        append_args(interop(prefer_type("sycl", "level_zero"), targetsync))    \
            adjust_args(need_device_ptr                                        \
                        : a) adjust_args(need_device_ptr                       \
                                         : y)
#endif
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vstan))                       \
    match(construct = {target variant dispatch}, device = {arch(gen)})
void vsTan(const MKL_INT n, const float* a, float* y) NOTHROW;

#if (_OPENMP >= 202011)
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vstani))                      \
    match(construct = {dispatch}, device = {arch(gen)})                        \
        append_args(interop(prefer_type("sycl", "level_zero"), targetsync))    \
            adjust_args(need_device_ptr                                        \
                        : a) adjust_args(need_device_ptr                       \
                                         : y)
#endif
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vstani))                      \
    match(construct = {target variant dispatch}, device = {arch(gen)})
void vsTanI(const MKL_INT n, const float* a, MKL_INT inca, float* y,
            MKL_INT incy) NOTHROW;

#if (_OPENMP >= 202011)
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vmstan))                      \
    match(construct = {dispatch}, device = {arch(gen)})                        \
        append_args(interop(prefer_type("sycl", "level_zero"), targetsync))    \
            adjust_args(need_device_ptr                                        \
                        : a) adjust_args(need_device_ptr                       \
                                         : y)
#endif
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vmstan))                      \
    match(construct = {target variant dispatch}, device = {arch(gen)})
void vmsTan(const MKL_INT n, const float* a, float* y, MKL_INT64 mode) NOTHROW;

#if (_OPENMP >= 202011)
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vmstani))                     \
    match(construct = {dispatch}, device = {arch(gen)})                        \
        append_args(interop(prefer_type("sycl", "level_zero"), targetsync))    \
            adjust_args(need_device_ptr                                        \
                        : a) adjust_args(need_device_ptr                       \
                                         : y)
#endif
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vmstani))                     \
    match(construct = {target variant dispatch}, device = {arch(gen)})
void vmsTanI(const MKL_INT n, const float* a, MKL_INT inca, float* y,
             MKL_INT incy, MKL_INT64 mode) NOTHROW;

#if (_OPENMP >= 202011)
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vdtan))                       \
    match(construct = {dispatch}, device = {arch(gen)})                        \
        append_args(interop(prefer_type("sycl", "level_zero"), targetsync))    \
            adjust_args(need_device_ptr                                        \
                        : a) adjust_args(need_device_ptr                       \
                                         : y)
#endif
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vdtan))                       \
    match(construct = {target variant dispatch}, device = {arch(gen)})
void vdTan(const MKL_INT n, const double* a, double* y) NOTHROW;

#if (_OPENMP >= 202011)
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vdtani))                      \
    match(construct = {dispatch}, device = {arch(gen)})                        \
        append_args(interop(prefer_type("sycl", "level_zero"), targetsync))    \
            adjust_args(need_device_ptr                                        \
                        : a) adjust_args(need_device_ptr                       \
                                         : y)
#endif
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vdtani))                      \
    match(construct = {target variant dispatch}, device = {arch(gen)})
void vdTanI(const MKL_INT n, const double* a, MKL_INT inca, double* y,
            MKL_INT incy) NOTHROW;

#if (_OPENMP >= 202011)
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vmdtan))                      \
    match(construct = {dispatch}, device = {arch(gen)})                        \
        append_args(interop(prefer_type("sycl", "level_zero"), targetsync))    \
            adjust_args(need_device_ptr                                        \
                        : a) adjust_args(need_device_ptr                       \
                                         : y)
#endif
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vmdtan))                      \
    match(construct = {target variant dispatch}, device = {arch(gen)})
void vmdTan(const MKL_INT n, const double* a, double* y,
            MKL_INT64 mode) NOTHROW;

#if (_OPENMP >= 202011)
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vmdtani))                     \
    match(construct = {dispatch}, device = {arch(gen)})                        \
        append_args(interop(prefer_type("sycl", "level_zero"), targetsync))    \
            adjust_args(need_device_ptr                                        \
                        : a) adjust_args(need_device_ptr                       \
                                         : y)
#endif
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vmdtani))                     \
    match(construct = {target variant dispatch}, device = {arch(gen)})
void vmdTanI(const MKL_INT n, const double* a, MKL_INT inca, double* y,
             MKL_INT incy, MKL_INT64 mode) NOTHROW;

#if (_OPENMP >= 202011)
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vctan))                       \
    match(construct = {dispatch}, device = {arch(gen)})                        \
        append_args(interop(prefer_type("sycl", "level_zero"), targetsync))    \
            adjust_args(need_device_ptr                                        \
                        : a) adjust_args(need_device_ptr                       \
                                         : y)
#endif
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vctan))                       \
    match(construct = {target variant dispatch}, device = {arch(gen)})
void vcTan(const MKL_INT n, const MKL_Complex8* a, MKL_Complex8* y) NOTHROW;

#if (_OPENMP >= 202011)
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vctani))                      \
    match(construct = {dispatch}, device = {arch(gen)})                        \
        append_args(interop(prefer_type("sycl", "level_zero"), targetsync))    \
            adjust_args(need_device_ptr                                        \
                        : a) adjust_args(need_device_ptr                       \
                                         : y)
#endif
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vctani))                      \
    match(construct = {target variant dispatch}, device = {arch(gen)})
void vcTanI(const MKL_INT n, const MKL_Complex8* a, MKL_INT inca,
            MKL_Complex8* y, MKL_INT incy) NOTHROW;

#if (_OPENMP >= 202011)
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vmctan))                      \
    match(construct = {dispatch}, device = {arch(gen)})                        \
        append_args(interop(prefer_type("sycl", "level_zero"), targetsync))    \
            adjust_args(need_device_ptr                                        \
                        : a) adjust_args(need_device_ptr                       \
                                         : y)
#endif
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vmctan))                      \
    match(construct = {target variant dispatch}, device = {arch(gen)})
void vmcTan(const MKL_INT n, const MKL_Complex8* a, MKL_Complex8* y,
            MKL_INT64 mode) NOTHROW;

#if (_OPENMP >= 202011)
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vmctani))                     \
    match(construct = {dispatch}, device = {arch(gen)})                        \
        append_args(interop(prefer_type("sycl", "level_zero"), targetsync))    \
            adjust_args(need_device_ptr                                        \
                        : a) adjust_args(need_device_ptr                       \
                                         : y)
#endif
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vmctani))                     \
    match(construct = {target variant dispatch}, device = {arch(gen)})
void vmcTanI(const MKL_INT n, const MKL_Complex8* a, MKL_INT inca,
             MKL_Complex8* y, MKL_INT incy, MKL_INT64 mode) NOTHROW;

#if (_OPENMP >= 202011)
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vztan))                       \
    match(construct = {dispatch}, device = {arch(gen)})                        \
        append_args(interop(prefer_type("sycl", "level_zero"), targetsync))    \
            adjust_args(need_device_ptr                                        \
                        : a) adjust_args(need_device_ptr                       \
                                         : y)
#endif
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vztan))                       \
    match(construct = {target variant dispatch}, device = {arch(gen)})
void vzTan(const MKL_INT n, const MKL_Complex16* a, MKL_Complex16* y) NOTHROW;

#if (_OPENMP >= 202011)
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vztani))                      \
    match(construct = {dispatch}, device = {arch(gen)})                        \
        append_args(interop(prefer_type("sycl", "level_zero"), targetsync))    \
            adjust_args(need_device_ptr                                        \
                        : a) adjust_args(need_device_ptr                       \
                                         : y)
#endif
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vztani))                      \
    match(construct = {target variant dispatch}, device = {arch(gen)})
void vzTanI(const MKL_INT n, const MKL_Complex16* a, MKL_INT inca,
            MKL_Complex16* y, MKL_INT incy) NOTHROW;

#if (_OPENMP >= 202011)
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vmztan))                      \
    match(construct = {dispatch}, device = {arch(gen)})                        \
        append_args(interop(prefer_type("sycl", "level_zero"), targetsync))    \
            adjust_args(need_device_ptr                                        \
                        : a) adjust_args(need_device_ptr                       \
                                         : y)
#endif
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vmztan))                      \
    match(construct = {target variant dispatch}, device = {arch(gen)})
void vmzTan(const MKL_INT n, const MKL_Complex16* a, MKL_Complex16* y,
            MKL_INT64 mode) NOTHROW;

#if (_OPENMP >= 202011)
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vmztani))                     \
    match(construct = {dispatch}, device = {arch(gen)})                        \
        append_args(interop(prefer_type("sycl", "level_zero"), targetsync))    \
            adjust_args(need_device_ptr                                        \
                        : a) adjust_args(need_device_ptr                       \
                                         : y)
#endif
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vmztani))                     \
    match(construct = {target variant dispatch}, device = {arch(gen)})
void vmzTanI(const MKL_INT n, const MKL_Complex16* a, MKL_INT inca,
             MKL_Complex16* y, MKL_INT incy, MKL_INT64 mode) NOTHROW;

// function tand
#if (_OPENMP >= 202011)
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vstand))                      \
    match(construct = {dispatch}, device = {arch(gen)})                        \
        append_args(interop(prefer_type("sycl", "level_zero"), targetsync))    \
            adjust_args(need_device_ptr                                        \
                        : a) adjust_args(need_device_ptr                       \
                                         : y)
#endif
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vstand))                      \
    match(construct = {target variant dispatch}, device = {arch(gen)})
void vsTand(const MKL_INT n, const float* a, float* y) NOTHROW;

#if (_OPENMP >= 202011)
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vstandi))                     \
    match(construct = {dispatch}, device = {arch(gen)})                        \
        append_args(interop(prefer_type("sycl", "level_zero"), targetsync))    \
            adjust_args(need_device_ptr                                        \
                        : a) adjust_args(need_device_ptr                       \
                                         : y)
#endif
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vstandi))                     \
    match(construct = {target variant dispatch}, device = {arch(gen)})
void vsTandI(const MKL_INT n, const float* a, MKL_INT inca, float* y,
             MKL_INT incy) NOTHROW;

#if (_OPENMP >= 202011)
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vmstand))                     \
    match(construct = {dispatch}, device = {arch(gen)})                        \
        append_args(interop(prefer_type("sycl", "level_zero"), targetsync))    \
            adjust_args(need_device_ptr                                        \
                        : a) adjust_args(need_device_ptr                       \
                                         : y)
#endif
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vmstand))                     \
    match(construct = {target variant dispatch}, device = {arch(gen)})
void vmsTand(const MKL_INT n, const float* a, float* y, MKL_INT64 mode) NOTHROW;

#if (_OPENMP >= 202011)
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vmstandi))                    \
    match(construct = {dispatch}, device = {arch(gen)})                        \
        append_args(interop(prefer_type("sycl", "level_zero"), targetsync))    \
            adjust_args(need_device_ptr                                        \
                        : a) adjust_args(need_device_ptr                       \
                                         : y)
#endif
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vmstandi))                    \
    match(construct = {target variant dispatch}, device = {arch(gen)})
void vmsTandI(const MKL_INT n, const float* a, MKL_INT inca, float* y,
              MKL_INT incy, MKL_INT64 mode) NOTHROW;

#if (_OPENMP >= 202011)
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vdtand))                      \
    match(construct = {dispatch}, device = {arch(gen)})                        \
        append_args(interop(prefer_type("sycl", "level_zero"), targetsync))    \
            adjust_args(need_device_ptr                                        \
                        : a) adjust_args(need_device_ptr                       \
                                         : y)
#endif
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vdtand))                      \
    match(construct = {target variant dispatch}, device = {arch(gen)})
void vdTand(const MKL_INT n, const double* a, double* y) NOTHROW;

#if (_OPENMP >= 202011)
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vdtandi))                     \
    match(construct = {dispatch}, device = {arch(gen)})                        \
        append_args(interop(prefer_type("sycl", "level_zero"), targetsync))    \
            adjust_args(need_device_ptr                                        \
                        : a) adjust_args(need_device_ptr                       \
                                         : y)
#endif
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vdtandi))                     \
    match(construct = {target variant dispatch}, device = {arch(gen)})
void vdTandI(const MKL_INT n, const double* a, MKL_INT inca, double* y,
             MKL_INT incy) NOTHROW;

#if (_OPENMP >= 202011)
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vmdtand))                     \
    match(construct = {dispatch}, device = {arch(gen)})                        \
        append_args(interop(prefer_type("sycl", "level_zero"), targetsync))    \
            adjust_args(need_device_ptr                                        \
                        : a) adjust_args(need_device_ptr                       \
                                         : y)
#endif
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vmdtand))                     \
    match(construct = {target variant dispatch}, device = {arch(gen)})
void vmdTand(const MKL_INT n, const double* a, double* y,
             MKL_INT64 mode) NOTHROW;

#if (_OPENMP >= 202011)
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vmdtandi))                    \
    match(construct = {dispatch}, device = {arch(gen)})                        \
        append_args(interop(prefer_type("sycl", "level_zero"), targetsync))    \
            adjust_args(need_device_ptr                                        \
                        : a) adjust_args(need_device_ptr                       \
                                         : y)
#endif
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vmdtandi))                    \
    match(construct = {target variant dispatch}, device = {arch(gen)})
void vmdTandI(const MKL_INT n, const double* a, MKL_INT inca, double* y,
              MKL_INT incy, MKL_INT64 mode) NOTHROW;

// function tanh
#if (_OPENMP >= 202011)
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vstanh))                      \
    match(construct = {dispatch}, device = {arch(gen)})                        \
        append_args(interop(prefer_type("sycl", "level_zero"), targetsync))    \
            adjust_args(need_device_ptr                                        \
                        : a) adjust_args(need_device_ptr                       \
                                         : y)
#endif
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vstanh))                      \
    match(construct = {target variant dispatch}, device = {arch(gen)})
void vsTanh(const MKL_INT n, const float* a, float* y) NOTHROW;

#if (_OPENMP >= 202011)
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vstanhi))                     \
    match(construct = {dispatch}, device = {arch(gen)})                        \
        append_args(interop(prefer_type("sycl", "level_zero"), targetsync))    \
            adjust_args(need_device_ptr                                        \
                        : a) adjust_args(need_device_ptr                       \
                                         : y)
#endif
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vstanhi))                     \
    match(construct = {target variant dispatch}, device = {arch(gen)})
void vsTanhI(const MKL_INT n, const float* a, MKL_INT inca, float* y,
             MKL_INT incy) NOTHROW;

#if (_OPENMP >= 202011)
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vmstanh))                     \
    match(construct = {dispatch}, device = {arch(gen)})                        \
        append_args(interop(prefer_type("sycl", "level_zero"), targetsync))    \
            adjust_args(need_device_ptr                                        \
                        : a) adjust_args(need_device_ptr                       \
                                         : y)
#endif
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vmstanh))                     \
    match(construct = {target variant dispatch}, device = {arch(gen)})
void vmsTanh(const MKL_INT n, const float* a, float* y, MKL_INT64 mode) NOTHROW;

#if (_OPENMP >= 202011)
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vmstanhi))                    \
    match(construct = {dispatch}, device = {arch(gen)})                        \
        append_args(interop(prefer_type("sycl", "level_zero"), targetsync))    \
            adjust_args(need_device_ptr                                        \
                        : a) adjust_args(need_device_ptr                       \
                                         : y)
#endif
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vmstanhi))                    \
    match(construct = {target variant dispatch}, device = {arch(gen)})
void vmsTanhI(const MKL_INT n, const float* a, MKL_INT inca, float* y,
              MKL_INT incy, MKL_INT64 mode) NOTHROW;

#if (_OPENMP >= 202011)
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vdtanh))                      \
    match(construct = {dispatch}, device = {arch(gen)})                        \
        append_args(interop(prefer_type("sycl", "level_zero"), targetsync))    \
            adjust_args(need_device_ptr                                        \
                        : a) adjust_args(need_device_ptr                       \
                                         : y)
#endif
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vdtanh))                      \
    match(construct = {target variant dispatch}, device = {arch(gen)})
void vdTanh(const MKL_INT n, const double* a, double* y) NOTHROW;

#if (_OPENMP >= 202011)
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vdtanhi))                     \
    match(construct = {dispatch}, device = {arch(gen)})                        \
        append_args(interop(prefer_type("sycl", "level_zero"), targetsync))    \
            adjust_args(need_device_ptr                                        \
                        : a) adjust_args(need_device_ptr                       \
                                         : y)
#endif
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vdtanhi))                     \
    match(construct = {target variant dispatch}, device = {arch(gen)})
void vdTanhI(const MKL_INT n, const double* a, MKL_INT inca, double* y,
             MKL_INT incy) NOTHROW;

#if (_OPENMP >= 202011)
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vmdtanh))                     \
    match(construct = {dispatch}, device = {arch(gen)})                        \
        append_args(interop(prefer_type("sycl", "level_zero"), targetsync))    \
            adjust_args(need_device_ptr                                        \
                        : a) adjust_args(need_device_ptr                       \
                                         : y)
#endif
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vmdtanh))                     \
    match(construct = {target variant dispatch}, device = {arch(gen)})
void vmdTanh(const MKL_INT n, const double* a, double* y,
             MKL_INT64 mode) NOTHROW;

#if (_OPENMP >= 202011)
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vmdtanhi))                    \
    match(construct = {dispatch}, device = {arch(gen)})                        \
        append_args(interop(prefer_type("sycl", "level_zero"), targetsync))    \
            adjust_args(need_device_ptr                                        \
                        : a) adjust_args(need_device_ptr                       \
                                         : y)
#endif
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vmdtanhi))                    \
    match(construct = {target variant dispatch}, device = {arch(gen)})
void vmdTanhI(const MKL_INT n, const double* a, MKL_INT inca, double* y,
              MKL_INT incy, MKL_INT64 mode) NOTHROW;

#if (_OPENMP >= 202011)
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vctanh))                      \
    match(construct = {dispatch}, device = {arch(gen)})                        \
        append_args(interop(prefer_type("sycl", "level_zero"), targetsync))    \
            adjust_args(need_device_ptr                                        \
                        : a) adjust_args(need_device_ptr                       \
                                         : y)
#endif
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vctanh))                      \
    match(construct = {target variant dispatch}, device = {arch(gen)})
void vcTanh(const MKL_INT n, const MKL_Complex8* a, MKL_Complex8* y) NOTHROW;

#if (_OPENMP >= 202011)
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vctanhi))                     \
    match(construct = {dispatch}, device = {arch(gen)})                        \
        append_args(interop(prefer_type("sycl", "level_zero"), targetsync))    \
            adjust_args(need_device_ptr                                        \
                        : a) adjust_args(need_device_ptr                       \
                                         : y)
#endif
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vctanhi))                     \
    match(construct = {target variant dispatch}, device = {arch(gen)})
void vcTanhI(const MKL_INT n, const MKL_Complex8* a, MKL_INT inca,
             MKL_Complex8* y, MKL_INT incy) NOTHROW;

#if (_OPENMP >= 202011)
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vmctanh))                     \
    match(construct = {dispatch}, device = {arch(gen)})                        \
        append_args(interop(prefer_type("sycl", "level_zero"), targetsync))    \
            adjust_args(need_device_ptr                                        \
                        : a) adjust_args(need_device_ptr                       \
                                         : y)
#endif
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vmctanh))                     \
    match(construct = {target variant dispatch}, device = {arch(gen)})
void vmcTanh(const MKL_INT n, const MKL_Complex8* a, MKL_Complex8* y,
             MKL_INT64 mode) NOTHROW;

#if (_OPENMP >= 202011)
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vmctanhi))                    \
    match(construct = {dispatch}, device = {arch(gen)})                        \
        append_args(interop(prefer_type("sycl", "level_zero"), targetsync))    \
            adjust_args(need_device_ptr                                        \
                        : a) adjust_args(need_device_ptr                       \
                                         : y)
#endif
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vmctanhi))                    \
    match(construct = {target variant dispatch}, device = {arch(gen)})
void vmcTanhI(const MKL_INT n, const MKL_Complex8* a, MKL_INT inca,
              MKL_Complex8* y, MKL_INT incy, MKL_INT64 mode) NOTHROW;

#if (_OPENMP >= 202011)
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vztanh))                      \
    match(construct = {dispatch}, device = {arch(gen)})                        \
        append_args(interop(prefer_type("sycl", "level_zero"), targetsync))    \
            adjust_args(need_device_ptr                                        \
                        : a) adjust_args(need_device_ptr                       \
                                         : y)
#endif
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vztanh))                      \
    match(construct = {target variant dispatch}, device = {arch(gen)})
void vzTanh(const MKL_INT n, const MKL_Complex16* a, MKL_Complex16* y) NOTHROW;

#if (_OPENMP >= 202011)
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vztanhi))                     \
    match(construct = {dispatch}, device = {arch(gen)})                        \
        append_args(interop(prefer_type("sycl", "level_zero"), targetsync))    \
            adjust_args(need_device_ptr                                        \
                        : a) adjust_args(need_device_ptr                       \
                                         : y)
#endif
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vztanhi))                     \
    match(construct = {target variant dispatch}, device = {arch(gen)})
void vzTanhI(const MKL_INT n, const MKL_Complex16* a, MKL_INT inca,
             MKL_Complex16* y, MKL_INT incy) NOTHROW;

#if (_OPENMP >= 202011)
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vmztanh))                     \
    match(construct = {dispatch}, device = {arch(gen)})                        \
        append_args(interop(prefer_type("sycl", "level_zero"), targetsync))    \
            adjust_args(need_device_ptr                                        \
                        : a) adjust_args(need_device_ptr                       \
                                         : y)
#endif
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vmztanh))                     \
    match(construct = {target variant dispatch}, device = {arch(gen)})
void vmzTanh(const MKL_INT n, const MKL_Complex16* a, MKL_Complex16* y,
             MKL_INT64 mode) NOTHROW;

#if (_OPENMP >= 202011)
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vmztanhi))                    \
    match(construct = {dispatch}, device = {arch(gen)})                        \
        append_args(interop(prefer_type("sycl", "level_zero"), targetsync))    \
            adjust_args(need_device_ptr                                        \
                        : a) adjust_args(need_device_ptr                       \
                                         : y)
#endif
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vmztanhi))                    \
    match(construct = {target variant dispatch}, device = {arch(gen)})
void vmzTanhI(const MKL_INT n, const MKL_Complex16* a, MKL_INT inca,
              MKL_Complex16* y, MKL_INT incy, MKL_INT64 mode) NOTHROW;

// function tanpi
#if (_OPENMP >= 202011)
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vstanpi))                     \
    match(construct = {dispatch}, device = {arch(gen)})                        \
        append_args(interop(prefer_type("sycl", "level_zero"), targetsync))    \
            adjust_args(need_device_ptr                                        \
                        : a) adjust_args(need_device_ptr                       \
                                         : y)
#endif
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vstanpi))                     \
    match(construct = {target variant dispatch}, device = {arch(gen)})
void vsTanpi(const MKL_INT n, const float* a, float* y) NOTHROW;

#if (_OPENMP >= 202011)
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vstanpii))                    \
    match(construct = {dispatch}, device = {arch(gen)})                        \
        append_args(interop(prefer_type("sycl", "level_zero"), targetsync))    \
            adjust_args(need_device_ptr                                        \
                        : a) adjust_args(need_device_ptr                       \
                                         : y)
#endif
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vstanpii))                    \
    match(construct = {target variant dispatch}, device = {arch(gen)})
void vsTanpiI(const MKL_INT n, const float* a, MKL_INT inca, float* y,
              MKL_INT incy) NOTHROW;

#if (_OPENMP >= 202011)
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vmstanpi))                    \
    match(construct = {dispatch}, device = {arch(gen)})                        \
        append_args(interop(prefer_type("sycl", "level_zero"), targetsync))    \
            adjust_args(need_device_ptr                                        \
                        : a) adjust_args(need_device_ptr                       \
                                         : y)
#endif
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vmstanpi))                    \
    match(construct = {target variant dispatch}, device = {arch(gen)})
void vmsTanpi(const MKL_INT n, const float* a, float* y,
              MKL_INT64 mode) NOTHROW;

#if (_OPENMP >= 202011)
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vmstanpii))                   \
    match(construct = {dispatch}, device = {arch(gen)})                        \
        append_args(interop(prefer_type("sycl", "level_zero"), targetsync))    \
            adjust_args(need_device_ptr                                        \
                        : a) adjust_args(need_device_ptr                       \
                                         : y)
#endif
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vmstanpii))                   \
    match(construct = {target variant dispatch}, device = {arch(gen)})
void vmsTanpiI(const MKL_INT n, const float* a, MKL_INT inca, float* y,
               MKL_INT incy, MKL_INT64 mode) NOTHROW;

#if (_OPENMP >= 202011)
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vdtanpi))                     \
    match(construct = {dispatch}, device = {arch(gen)})                        \
        append_args(interop(prefer_type("sycl", "level_zero"), targetsync))    \
            adjust_args(need_device_ptr                                        \
                        : a) adjust_args(need_device_ptr                       \
                                         : y)
#endif
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vdtanpi))                     \
    match(construct = {target variant dispatch}, device = {arch(gen)})
void vdTanpi(const MKL_INT n, const double* a, double* y) NOTHROW;

#if (_OPENMP >= 202011)
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vdtanpii))                    \
    match(construct = {dispatch}, device = {arch(gen)})                        \
        append_args(interop(prefer_type("sycl", "level_zero"), targetsync))    \
            adjust_args(need_device_ptr                                        \
                        : a) adjust_args(need_device_ptr                       \
                                         : y)
#endif
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vdtanpii))                    \
    match(construct = {target variant dispatch}, device = {arch(gen)})
void vdTanpiI(const MKL_INT n, const double* a, MKL_INT inca, double* y,
              MKL_INT incy) NOTHROW;

#if (_OPENMP >= 202011)
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vmdtanpi))                    \
    match(construct = {dispatch}, device = {arch(gen)})                        \
        append_args(interop(prefer_type("sycl", "level_zero"), targetsync))    \
            adjust_args(need_device_ptr                                        \
                        : a) adjust_args(need_device_ptr                       \
                                         : y)
#endif
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vmdtanpi))                    \
    match(construct = {target variant dispatch}, device = {arch(gen)})
void vmdTanpi(const MKL_INT n, const double* a, double* y,
              MKL_INT64 mode) NOTHROW;

#if (_OPENMP >= 202011)
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vmdtanpii))                   \
    match(construct = {dispatch}, device = {arch(gen)})                        \
        append_args(interop(prefer_type("sycl", "level_zero"), targetsync))    \
            adjust_args(need_device_ptr                                        \
                        : a) adjust_args(need_device_ptr                       \
                                         : y)
#endif
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vmdtanpii))                   \
    match(construct = {target variant dispatch}, device = {arch(gen)})
void vmdTanpiI(const MKL_INT n, const double* a, MKL_INT inca, double* y,
               MKL_INT incy, MKL_INT64 mode) NOTHROW;

// function tgamma
#if (_OPENMP >= 202011)
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vstgamma))                    \
    match(construct = {dispatch}, device = {arch(gen)})                        \
        append_args(interop(prefer_type("sycl", "level_zero"), targetsync))    \
            adjust_args(need_device_ptr                                        \
                        : a) adjust_args(need_device_ptr                       \
                                         : y)
#endif
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vstgamma))                    \
    match(construct = {target variant dispatch}, device = {arch(gen)})
void vsTGamma(const MKL_INT n, const float* a, float* y) NOTHROW;

#if (_OPENMP >= 202011)
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vstgammai))                   \
    match(construct = {dispatch}, device = {arch(gen)})                        \
        append_args(interop(prefer_type("sycl", "level_zero"), targetsync))    \
            adjust_args(need_device_ptr                                        \
                        : a) adjust_args(need_device_ptr                       \
                                         : y)
#endif
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vstgammai))                   \
    match(construct = {target variant dispatch}, device = {arch(gen)})
void vsTGammaI(const MKL_INT n, const float* a, MKL_INT inca, float* y,
               MKL_INT incy) NOTHROW;

#if (_OPENMP >= 202011)
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vmstgamma))                   \
    match(construct = {dispatch}, device = {arch(gen)})                        \
        append_args(interop(prefer_type("sycl", "level_zero"), targetsync))    \
            adjust_args(need_device_ptr                                        \
                        : a) adjust_args(need_device_ptr                       \
                                         : y)
#endif
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vmstgamma))                   \
    match(construct = {target variant dispatch}, device = {arch(gen)})
void vmsTGamma(const MKL_INT n, const float* a, float* y,
               MKL_INT64 mode) NOTHROW;

#if (_OPENMP >= 202011)
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vmstgammai))                  \
    match(construct = {dispatch}, device = {arch(gen)})                        \
        append_args(interop(prefer_type("sycl", "level_zero"), targetsync))    \
            adjust_args(need_device_ptr                                        \
                        : a) adjust_args(need_device_ptr                       \
                                         : y)
#endif
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vmstgammai))                  \
    match(construct = {target variant dispatch}, device = {arch(gen)})
void vmsTGammaI(const MKL_INT n, const float* a, MKL_INT inca, float* y,
                MKL_INT incy, MKL_INT64 mode) NOTHROW;

#if (_OPENMP >= 202011)
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vdtgamma))                    \
    match(construct = {dispatch}, device = {arch(gen)})                        \
        append_args(interop(prefer_type("sycl", "level_zero"), targetsync))    \
            adjust_args(need_device_ptr                                        \
                        : a) adjust_args(need_device_ptr                       \
                                         : y)
#endif
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vdtgamma))                    \
    match(construct = {target variant dispatch}, device = {arch(gen)})
void vdTGamma(const MKL_INT n, const double* a, double* y) NOTHROW;

#if (_OPENMP >= 202011)
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vdtgammai))                   \
    match(construct = {dispatch}, device = {arch(gen)})                        \
        append_args(interop(prefer_type("sycl", "level_zero"), targetsync))    \
            adjust_args(need_device_ptr                                        \
                        : a) adjust_args(need_device_ptr                       \
                                         : y)
#endif
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vdtgammai))                   \
    match(construct = {target variant dispatch}, device = {arch(gen)})
void vdTGammaI(const MKL_INT n, const double* a, MKL_INT inca, double* y,
               MKL_INT incy) NOTHROW;

#if (_OPENMP >= 202011)
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vmdtgamma))                   \
    match(construct = {dispatch}, device = {arch(gen)})                        \
        append_args(interop(prefer_type("sycl", "level_zero"), targetsync))    \
            adjust_args(need_device_ptr                                        \
                        : a) adjust_args(need_device_ptr                       \
                                         : y)
#endif
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vmdtgamma))                   \
    match(construct = {target variant dispatch}, device = {arch(gen)})
void vmdTGamma(const MKL_INT n, const double* a, double* y,
               MKL_INT64 mode) NOTHROW;

#if (_OPENMP >= 202011)
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vmdtgammai))                  \
    match(construct = {dispatch}, device = {arch(gen)})                        \
        append_args(interop(prefer_type("sycl", "level_zero"), targetsync))    \
            adjust_args(need_device_ptr                                        \
                        : a) adjust_args(need_device_ptr                       \
                                         : y)
#endif
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vmdtgammai))                  \
    match(construct = {target variant dispatch}, device = {arch(gen)})
void vmdTGammaI(const MKL_INT n, const double* a, MKL_INT inca, double* y,
                MKL_INT incy, MKL_INT64 mode) NOTHROW;

// function trunc
#if (_OPENMP >= 202011)
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vstrunc))                     \
    match(construct = {dispatch}, device = {arch(gen)})                        \
        append_args(interop(prefer_type("sycl", "level_zero"), targetsync))    \
            adjust_args(need_device_ptr                                        \
                        : a) adjust_args(need_device_ptr                       \
                                         : y)
#endif
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vstrunc))                     \
    match(construct = {target variant dispatch}, device = {arch(gen)})
void vsTrunc(const MKL_INT n, const float* a, float* y) NOTHROW;

#if (_OPENMP >= 202011)
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vstrunci))                    \
    match(construct = {dispatch}, device = {arch(gen)})                        \
        append_args(interop(prefer_type("sycl", "level_zero"), targetsync))    \
            adjust_args(need_device_ptr                                        \
                        : a) adjust_args(need_device_ptr                       \
                                         : y)
#endif
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vstrunci))                    \
    match(construct = {target variant dispatch}, device = {arch(gen)})
void vsTruncI(const MKL_INT n, const float* a, MKL_INT inca, float* y,
              MKL_INT incy) NOTHROW;

#if (_OPENMP >= 202011)
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vmstrunc))                    \
    match(construct = {dispatch}, device = {arch(gen)})                        \
        append_args(interop(prefer_type("sycl", "level_zero"), targetsync))    \
            adjust_args(need_device_ptr                                        \
                        : a) adjust_args(need_device_ptr                       \
                                         : y)
#endif
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vmstrunc))                    \
    match(construct = {target variant dispatch}, device = {arch(gen)})
void vmsTrunc(const MKL_INT n, const float* a, float* y,
              MKL_INT64 mode) NOTHROW;

#if (_OPENMP >= 202011)
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vmstrunci))                   \
    match(construct = {dispatch}, device = {arch(gen)})                        \
        append_args(interop(prefer_type("sycl", "level_zero"), targetsync))    \
            adjust_args(need_device_ptr                                        \
                        : a) adjust_args(need_device_ptr                       \
                                         : y)
#endif
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vmstrunci))                   \
    match(construct = {target variant dispatch}, device = {arch(gen)})
void vmsTruncI(const MKL_INT n, const float* a, MKL_INT inca, float* y,
               MKL_INT incy, MKL_INT64 mode) NOTHROW;

#if (_OPENMP >= 202011)
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vdtrunc))                     \
    match(construct = {dispatch}, device = {arch(gen)})                        \
        append_args(interop(prefer_type("sycl", "level_zero"), targetsync))    \
            adjust_args(need_device_ptr                                        \
                        : a) adjust_args(need_device_ptr                       \
                                         : y)
#endif
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vdtrunc))                     \
    match(construct = {target variant dispatch}, device = {arch(gen)})
void vdTrunc(const MKL_INT n, const double* a, double* y) NOTHROW;

#if (_OPENMP >= 202011)
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vdtrunci))                    \
    match(construct = {dispatch}, device = {arch(gen)})                        \
        append_args(interop(prefer_type("sycl", "level_zero"), targetsync))    \
            adjust_args(need_device_ptr                                        \
                        : a) adjust_args(need_device_ptr                       \
                                         : y)
#endif
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vdtrunci))                    \
    match(construct = {target variant dispatch}, device = {arch(gen)})
void vdTruncI(const MKL_INT n, const double* a, MKL_INT inca, double* y,
              MKL_INT incy) NOTHROW;

#if (_OPENMP >= 202011)
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vmdtrunc))                    \
    match(construct = {dispatch}, device = {arch(gen)})                        \
        append_args(interop(prefer_type("sycl", "level_zero"), targetsync))    \
            adjust_args(need_device_ptr                                        \
                        : a) adjust_args(need_device_ptr                       \
                                         : y)
#endif
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vmdtrunc))                    \
    match(construct = {target variant dispatch}, device = {arch(gen)})
void vmdTrunc(const MKL_INT n, const double* a, double* y,
              MKL_INT64 mode) NOTHROW;

#if (_OPENMP >= 202011)
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vmdtrunci))                   \
    match(construct = {dispatch}, device = {arch(gen)})                        \
        append_args(interop(prefer_type("sycl", "level_zero"), targetsync))    \
            adjust_args(need_device_ptr                                        \
                        : a) adjust_args(need_device_ptr                       \
                                         : y)
#endif
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vmdtrunci))                   \
    match(construct = {target variant dispatch}, device = {arch(gen)})
void vmdTruncI(const MKL_INT n, const double* a, MKL_INT inca, double* y,
               MKL_INT incy, MKL_INT64 mode) NOTHROW;

// function y0
#if (_OPENMP >= 202011)
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vsy0))                        \
    match(construct = {dispatch}, device = {arch(gen)})                        \
        append_args(interop(prefer_type("sycl", "level_zero"), targetsync))    \
            adjust_args(need_device_ptr                                        \
                        : a) adjust_args(need_device_ptr                       \
                                         : y)
#endif
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vsy0))                        \
    match(construct = {target variant dispatch}, device = {arch(gen)})
void vsY0(const MKL_INT n, const float* a, float* y) NOTHROW;

#if (_OPENMP >= 202011)
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vsy0i))                       \
    match(construct = {dispatch}, device = {arch(gen)})                        \
        append_args(interop(prefer_type("sycl", "level_zero"), targetsync))    \
            adjust_args(need_device_ptr                                        \
                        : a) adjust_args(need_device_ptr                       \
                                         : y)
#endif
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vsy0i))                       \
    match(construct = {target variant dispatch}, device = {arch(gen)})
void vsY0I(const MKL_INT n, const float* a, MKL_INT inca, float* y,
           MKL_INT incy) NOTHROW;

#if (_OPENMP >= 202011)
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vmsy0))                       \
    match(construct = {dispatch}, device = {arch(gen)})                        \
        append_args(interop(prefer_type("sycl", "level_zero"), targetsync))    \
            adjust_args(need_device_ptr                                        \
                        : a) adjust_args(need_device_ptr                       \
                                         : y)
#endif
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vmsy0))                       \
    match(construct = {target variant dispatch}, device = {arch(gen)})
void vmsY0(const MKL_INT n, const float* a, float* y, MKL_INT64 mode) NOTHROW;

#if (_OPENMP >= 202011)
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vmsy0i))                      \
    match(construct = {dispatch}, device = {arch(gen)})                        \
        append_args(interop(prefer_type("sycl", "level_zero"), targetsync))    \
            adjust_args(need_device_ptr                                        \
                        : a) adjust_args(need_device_ptr                       \
                                         : y)
#endif
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vmsy0i))                      \
    match(construct = {target variant dispatch}, device = {arch(gen)})
void vmsY0I(const MKL_INT n, const float* a, MKL_INT inca, float* y,
            MKL_INT incy, MKL_INT64 mode) NOTHROW;

#if (_OPENMP >= 202011)
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vdy0))                        \
    match(construct = {dispatch}, device = {arch(gen)})                        \
        append_args(interop(prefer_type("sycl", "level_zero"), targetsync))    \
            adjust_args(need_device_ptr                                        \
                        : a) adjust_args(need_device_ptr                       \
                                         : y)
#endif
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vdy0))                        \
    match(construct = {target variant dispatch}, device = {arch(gen)})
void vdY0(const MKL_INT n, const double* a, double* y) NOTHROW;

#if (_OPENMP >= 202011)
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vdy0i))                       \
    match(construct = {dispatch}, device = {arch(gen)})                        \
        append_args(interop(prefer_type("sycl", "level_zero"), targetsync))    \
            adjust_args(need_device_ptr                                        \
                        : a) adjust_args(need_device_ptr                       \
                                         : y)
#endif
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vdy0i))                       \
    match(construct = {target variant dispatch}, device = {arch(gen)})
void vdY0I(const MKL_INT n, const double* a, MKL_INT inca, double* y,
           MKL_INT incy) NOTHROW;

#if (_OPENMP >= 202011)
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vmdy0))                       \
    match(construct = {dispatch}, device = {arch(gen)})                        \
        append_args(interop(prefer_type("sycl", "level_zero"), targetsync))    \
            adjust_args(need_device_ptr                                        \
                        : a) adjust_args(need_device_ptr                       \
                                         : y)
#endif
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vmdy0))                       \
    match(construct = {target variant dispatch}, device = {arch(gen)})
void vmdY0(const MKL_INT n, const double* a, double* y, MKL_INT64 mode) NOTHROW;

#if (_OPENMP >= 202011)
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vmdy0i))                      \
    match(construct = {dispatch}, device = {arch(gen)})                        \
        append_args(interop(prefer_type("sycl", "level_zero"), targetsync))    \
            adjust_args(need_device_ptr                                        \
                        : a) adjust_args(need_device_ptr                       \
                                         : y)
#endif
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vmdy0i))                      \
    match(construct = {target variant dispatch}, device = {arch(gen)})
void vmdY0I(const MKL_INT n, const double* a, MKL_INT inca, double* y,
            MKL_INT incy, MKL_INT64 mode) NOTHROW;

// function y1
#if (_OPENMP >= 202011)
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vsy1))                        \
    match(construct = {dispatch}, device = {arch(gen)})                        \
        append_args(interop(prefer_type("sycl", "level_zero"), targetsync))    \
            adjust_args(need_device_ptr                                        \
                        : a) adjust_args(need_device_ptr                       \
                                         : y)
#endif
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vsy1))                        \
    match(construct = {target variant dispatch}, device = {arch(gen)})
void vsY1(const MKL_INT n, const float* a, float* y) NOTHROW;

#if (_OPENMP >= 202011)
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vsy1i))                       \
    match(construct = {dispatch}, device = {arch(gen)})                        \
        append_args(interop(prefer_type("sycl", "level_zero"), targetsync))    \
            adjust_args(need_device_ptr                                        \
                        : a) adjust_args(need_device_ptr                       \
                                         : y)
#endif
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vsy1i))                       \
    match(construct = {target variant dispatch}, device = {arch(gen)})
void vsY1I(const MKL_INT n, const float* a, MKL_INT inca, float* y,
           MKL_INT incy) NOTHROW;

#if (_OPENMP >= 202011)
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vmsy1))                       \
    match(construct = {dispatch}, device = {arch(gen)})                        \
        append_args(interop(prefer_type("sycl", "level_zero"), targetsync))    \
            adjust_args(need_device_ptr                                        \
                        : a) adjust_args(need_device_ptr                       \
                                         : y)
#endif
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vmsy1))                       \
    match(construct = {target variant dispatch}, device = {arch(gen)})
void vmsY1(const MKL_INT n, const float* a, float* y, MKL_INT64 mode) NOTHROW;

#if (_OPENMP >= 202011)
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vmsy1i))                      \
    match(construct = {dispatch}, device = {arch(gen)})                        \
        append_args(interop(prefer_type("sycl", "level_zero"), targetsync))    \
            adjust_args(need_device_ptr                                        \
                        : a) adjust_args(need_device_ptr                       \
                                         : y)
#endif
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vmsy1i))                      \
    match(construct = {target variant dispatch}, device = {arch(gen)})
void vmsY1I(const MKL_INT n, const float* a, MKL_INT inca, float* y,
            MKL_INT incy, MKL_INT64 mode) NOTHROW;

#if (_OPENMP >= 202011)
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vdy1))                        \
    match(construct = {dispatch}, device = {arch(gen)})                        \
        append_args(interop(prefer_type("sycl", "level_zero"), targetsync))    \
            adjust_args(need_device_ptr                                        \
                        : a) adjust_args(need_device_ptr                       \
                                         : y)
#endif
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vdy1))                        \
    match(construct = {target variant dispatch}, device = {arch(gen)})
void vdY1(const MKL_INT n, const double* a, double* y) NOTHROW;

#if (_OPENMP >= 202011)
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vdy1i))                       \
    match(construct = {dispatch}, device = {arch(gen)})                        \
        append_args(interop(prefer_type("sycl", "level_zero"), targetsync))    \
            adjust_args(need_device_ptr                                        \
                        : a) adjust_args(need_device_ptr                       \
                                         : y)
#endif
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vdy1i))                       \
    match(construct = {target variant dispatch}, device = {arch(gen)})
void vdY1I(const MKL_INT n, const double* a, MKL_INT inca, double* y,
           MKL_INT incy) NOTHROW;

#if (_OPENMP >= 202011)
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vmdy1))                       \
    match(construct = {dispatch}, device = {arch(gen)})                        \
        append_args(interop(prefer_type("sycl", "level_zero"), targetsync))    \
            adjust_args(need_device_ptr                                        \
                        : a) adjust_args(need_device_ptr                       \
                                         : y)
#endif
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vmdy1))                       \
    match(construct = {target variant dispatch}, device = {arch(gen)})
void vmdY1(const MKL_INT n, const double* a, double* y, MKL_INT64 mode) NOTHROW;

#if (_OPENMP >= 202011)
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vmdy1i))                      \
    match(construct = {dispatch}, device = {arch(gen)})                        \
        append_args(interop(prefer_type("sycl", "level_zero"), targetsync))    \
            adjust_args(need_device_ptr                                        \
                        : a) adjust_args(need_device_ptr                       \
                                         : y)
#endif
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vmdy1i))                      \
    match(construct = {target variant dispatch}, device = {arch(gen)})
void vmdY1I(const MKL_INT n, const double* a, MKL_INT inca, double* y,
            MKL_INT incy, MKL_INT64 mode) NOTHROW;

// function yn
#if (_OPENMP >= 202011)
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vsyn))                        \
    match(construct = {dispatch}, device = {arch(gen)})                        \
        append_args(interop(prefer_type("sycl", "level_zero"), targetsync))    \
            adjust_args(need_device_ptr                                        \
                        : a) adjust_args(need_device_ptr                       \
                                         : y)
#endif
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vsyn))                        \
    match(construct = {target variant dispatch}, device = {arch(gen)})
void vsYn(const MKL_INT n, const float* a, const float b, float* y) NOTHROW;

#if (_OPENMP >= 202011)
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vsyni))                       \
    match(construct = {dispatch}, device = {arch(gen)})                        \
        append_args(interop(prefer_type("sycl", "level_zero"), targetsync))    \
            adjust_args(need_device_ptr                                        \
                        : a) adjust_args(need_device_ptr                       \
                                         : y)
#endif
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vsyni))                       \
    match(construct = {target variant dispatch}, device = {arch(gen)})
void vsYnI(const MKL_INT n, const float* a, MKL_INT inca, const float b,
           float* y, MKL_INT incy) NOTHROW;

#if (_OPENMP >= 202011)
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vmsyn))                       \
    match(construct = {dispatch}, device = {arch(gen)})                        \
        append_args(interop(prefer_type("sycl", "level_zero"), targetsync))    \
            adjust_args(need_device_ptr                                        \
                        : a) adjust_args(need_device_ptr                       \
                                         : y)
#endif
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vmsyn))                       \
    match(construct = {target variant dispatch}, device = {arch(gen)})
void vmsYn(const MKL_INT n, const float* a, const float b, float* y,
           MKL_INT64 mode) NOTHROW;

#if (_OPENMP >= 202011)
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vmsyni))                      \
    match(construct = {dispatch}, device = {arch(gen)})                        \
        append_args(interop(prefer_type("sycl", "level_zero"), targetsync))    \
            adjust_args(need_device_ptr                                        \
                        : a) adjust_args(need_device_ptr                       \
                                         : y)
#endif
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vmsyni))                      \
    match(construct = {target variant dispatch}, device = {arch(gen)})
void vmsYnI(const MKL_INT n, const float* a, MKL_INT inca, const float b,
            float* y, MKL_INT incy, MKL_INT64 mode) NOTHROW;

#if (_OPENMP >= 202011)
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vdyn))                        \
    match(construct = {dispatch}, device = {arch(gen)})                        \
        append_args(interop(prefer_type("sycl", "level_zero"), targetsync))    \
            adjust_args(need_device_ptr                                        \
                        : a) adjust_args(need_device_ptr                       \
                                         : y)
#endif
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vdyn))                        \
    match(construct = {target variant dispatch}, device = {arch(gen)})
void vdYn(const MKL_INT n, const double* a, const double b, double* y) NOTHROW;

#if (_OPENMP >= 202011)
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vdyni))                       \
    match(construct = {dispatch}, device = {arch(gen)})                        \
        append_args(interop(prefer_type("sycl", "level_zero"), targetsync))    \
            adjust_args(need_device_ptr                                        \
                        : a) adjust_args(need_device_ptr                       \
                                         : y)
#endif
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vdyni))                       \
    match(construct = {target variant dispatch}, device = {arch(gen)})
void vdYnI(const MKL_INT n, const double* a, MKL_INT inca, const double b,
           double* y, MKL_INT incy) NOTHROW;

#if (_OPENMP >= 202011)
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vmdyn))                       \
    match(construct = {dispatch}, device = {arch(gen)})                        \
        append_args(interop(prefer_type("sycl", "level_zero"), targetsync))    \
            adjust_args(need_device_ptr                                        \
                        : a) adjust_args(need_device_ptr                       \
                                         : y)
#endif
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vmdyn))                       \
    match(construct = {target variant dispatch}, device = {arch(gen)})
void vmdYn(const MKL_INT n, const double* a, const double b, double* y,
           MKL_INT64 mode) NOTHROW;

#if (_OPENMP >= 202011)
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vmdyni))                      \
    match(construct = {dispatch}, device = {arch(gen)})                        \
        append_args(interop(prefer_type("sycl", "level_zero"), targetsync))    \
            adjust_args(need_device_ptr                                        \
                        : a) adjust_args(need_device_ptr                       \
                                         : y)
#endif
#pragma omp declare variant(MKL_VARIANT_NAME(vm, vmdyni))                      \
    match(construct = {target variant dispatch}, device = {arch(gen)})
void vmdYnI(const MKL_INT n, const double* a, MKL_INT inca, const double b,
            double* y, MKL_INT incy, MKL_INT64 mode) NOTHROW;

#ifdef __cplusplus
}
#endif // __cplusplus

#endif // MKL_VML_OMP_OFFLOAD
