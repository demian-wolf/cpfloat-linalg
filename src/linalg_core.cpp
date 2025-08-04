#include "linalg_core.hpp"

extern "C" {
    #include "cpfloat.h"
}

namespace linalg {
    int cpfloat_add(double *X, const double *A, const double *B,
                    std::size_t numelem, optstruct *fpopts) {
        return cpf_add(X, A, B, numelem, fpopts);
    }

    int cpfloat_addf(float *X, const float *A, const float *B,
                    std::size_t numelem, optstruct *fpopts) {
        return cpf_addf(X, A, B, numelem, fpopts);
    }

    int cpfloat_mul(double *X, const double *A, const double *B,
                    std::size_t numelem, optstruct *fpopts) {
        return cpf_mul(X, A, B, numelem, fpopts);
    }

    int cpfloat_mulf(float *X, const float *A, const float *B,
        std::size_t numelem, optstruct *fpopts) {
        return cpf_mulf(X, A, B, numelem, fpopts);
    }

    int cpfloat_fma(double *X, const double *A, const double *B, const double *C,
                    std::size_t numelem, optstruct *fpopts) {
        return cpf_fma(X, A, B, C, numelem, fpopts);
    }

    int cpfloat_fmaf(float *X, const float *A, const float *B, const float *C,
        std::size_t numelem, optstruct *fpopts) {
        return cpf_fmaf(X, A, B, C, numelem, fpopts);
    }

    int cpfloat_dot(double *X, const double *A, const double *B,
                    std::size_t numelem, optstruct *fpopts) {
        if (!X || !A || !B) {
            return -1;
        }
        
        int retval = 0;
        double acc = 0.0;
        
        for (std::size_t i = 0; i < numelem; ++i) {
            double prod;
            retval |= cpf_mul(&prod, &A[i], &B[i], 1, fpopts);
            retval |= cpf_add(&acc, &acc, &prod, 1, fpopts);
        }

        *X = acc;
        return retval;
    }

    int cpfloat_dotf(float *X, const float *A, const float *B,
        std::size_t numelem, optstruct *fpopts) {
        if (!X || !A || !B) {
            return -1;
        }

        int retval = 0;
        float acc = 0.0;

        for (std::size_t i = 0; i < numelem; ++i) {
            float prod;
            retval |= cpf_mulf(&prod, &A[i], &B[i], 1, fpopts);
            retval |= cpf_addf(&acc, &acc, &prod, 1, fpopts);
        }

        *X = acc;
        return retval;
    }
}
