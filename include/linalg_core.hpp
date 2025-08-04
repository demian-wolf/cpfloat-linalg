#ifndef LINALG_CORE_HPP
#define LINALG_CORE_HPP

#include <cstddef>

extern "C" {
    #include "cpfloat.h" // IWYU pragma: keep
}

namespace linalg {
    int cpfloat_add(double *X, const double *A, const double *B,
                std::size_t numelem, optstruct *fpopts);

    int cpfloat_addf(float *X, const float *A, const float *B,
                std::size_t numelem, optstruct *fpopts);

    int cpfloat_mul(double *X, const double *A, const double *B,
                    std::size_t numelem, optstruct *fpopts);
    int cpfloat_mulf(float *X, const float *A, const float *B,
                    std::size_t numelem, optstruct *fpopts);
    
    int cpfloat_fma(double *X, const double *A, const double *B,
                    const double *C, std::size_t numelem, optstruct *fpopts);
    int cpfloat_fmaf(float *X, const float *A, const float *B,
                    const float *C, std::size_t numelem, optstruct *fpopts);
}

#endif  /* LINALG_CORE_HPP */
