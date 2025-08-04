#ifndef LINALG_CORE_HPP
#define LINALG_CORE_HPP

#include <cstddef>
#include <memory>

extern "C" {
    #include "cpfloat.h" // IWYU pragma: keep
}

namespace linalg {
    struct OptDeleter {
        void operator()(optstruct *fpopts) { free_optstruct(fpopts); }
    };

    class Opt {
        private:
            std::unique_ptr<optstruct, OptDeleter> ptr;

        public:
            Opt() : ptr(init_optstruct()) {}

            operator optstruct*() { return ptr.get(); }
            operator const optstruct*() const { return ptr.get(); }
            
            optstruct* get() { return ptr.get(); }
            const optstruct* get() const { return ptr.get(); }
            
            optstruct* operator->() { return ptr.get(); }
            const optstruct* operator->() const { return ptr.get(); }

            // prevent copying [because unique_ptr]
            Opt(const Opt&) = delete;
            Opt& operator=(const Opt&) = delete;
            
            // allow moving
            Opt(Opt&&) = default;
            Opt& operator=(Opt&&) = default;

            static Opt binary32() {
                Opt o;
                o->precision = 24;
                o->emin = -126;
                o->emax = 127;
                return o;
            }

            static Opt binary64() {
                Opt o;
                o->precision = 53;
                o->emin = -1022;
                o->emax = 1023;
                return o;
            }

            static Opt custom(int prec, int emin, int emax) {
                Opt o;
                o->precision = prec;
                o->emin = emin;
                o->emax = emax;
                return o;
            }
    };
    
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
    
    int cpfloat_dot(double *X, const double *A, const double *B,
                    std::size_t numelem, optstruct *fpopts);
    int cpfloat_dotf(float *X, const float *A, const float *B,
                    std::size_t numelem, optstruct *fpopts);
}

#endif /* LINALG_CORE_HPP */
