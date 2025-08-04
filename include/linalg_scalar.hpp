#ifndef LINALG_SCALAR_HPP
#define LINALG_SCALAR_HPP

#include <cstddef>

#include "linalg_core.hpp"
#include "linalg_check.hpp"

namespace linalg {
    inline double add(double a, double b, optstruct *fpopts) {
        double X;
        detail::check(cpfloat_add(&X, &a, &b, 1, fpopts), "cpfloat_add");
        return X;
    }

    inline float add(float a, float b, optstruct *fpopts) {
        float X;
        detail::check(cpfloat_addf(&X, &a, &b, 1, fpopts), "cpfloat_addf");
        return X;
    }

    inline double mul(double a, double b, optstruct *fpopts) {
        double X;
        detail::check(cpfloat_mul(&X, &a, &b, 1, fpopts), "cpfloat_mul");
        return X;
    }

    inline float mul(float a, float b, optstruct *fpopts) {
        float X;
        detail::check(cpfloat_mulf(&X, &a, &b, 1, fpopts), "cpfloat_mulf");
        return X;
    }

    inline double fma(double a, double b, double c, optstruct *fpopts) {
        double X;
        detail::check(cpfloat_fma(&X, &a, &b, &c, 1, fpopts), "cpfloat_fma");
        return X;
    }

    inline float fma(float a, float b, float c, optstruct *fpopts) {
        float X;
        detail::check(cpfloat_fmaf(&X, &a, &b, &c, 1, fpopts), "cpfloat_fmaf");
        return X;
    }

    inline double dot(double *X, const double *A, const double *B,
        std::size_t numelem, optstruct *fpopts) {
        detail::check(cpfloat_dot(X, A, B, numelem, fpopts), "cpfloat_dot");
        return *X;
    }

    inline float dot(float *X, const float *A, const float *B,
        std::size_t numelem, optstruct *fpopts) {
        detail::check(cpfloat_dotf(X, A, B, numelem, fpopts), "cpfloat_dotf");
        return *X;
    }
}

#endif /* LINALG_SCALAR_HPP */
