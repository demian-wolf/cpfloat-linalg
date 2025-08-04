#include "linalg_core.hpp"

namespace linalg {
    inline double add(double a, double b, optstruct *fpopts) {
        double X;
        cpfloat_add(&X, &a, &b, 1, fpopts);
        return X;
    }

    inline float add(float a, float b, optstruct *fpopts) {
        float X;
        cpfloat_addf(&X, &a, &b, 1, fpopts);
        return X;
    }

    inline double mul(double a, double b, optstruct *fpopts) {
        double X;
        cpfloat_mul(&X, &a, &b, 1, fpopts);
        return X;
    }

    inline float mul(float a, float b, optstruct *fpopts) {
        float X;
        cpfloat_mulf(&X, &a, &b, 1, fpopts);
        return X;
    }

    inline double fma(double a, double b, double c, optstruct *fpopts) {
        double X;
        cpfloat_fma(&X, &a, &b, &c, 1, fpopts);
        return X;
    }

    inline float fma(float a, float b, float c, optstruct *fpopts) {
        float X;
        cpfloat_fmaf(&X, &a, &b, &c, 1, fpopts);
        return X;
    }

    inline double dot(double *X, const double *A, const double *B,
        std::size_t numelem, optstruct *fpopts) {
        return cpfloat_dot(X, A, B, numelem, fpopts);
    }

    inline float dot(float *X, const float *A, const float *B,
        std::size_t numelem, optstruct *fpopts) {
        return cpfloat_dotf(X, A, B, numelem, fpopts);
    }
}
