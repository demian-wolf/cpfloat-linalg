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
            optstruct* get() { return ptr.get(); }
            const optstruct* get() const { return ptr.get(); }

            // prevent copying [because unique_ptr]
            Opt(const Opt&) = delete;
            Opt& operator=(const Opt&) = delete;
            
            // allow moving
            Opt(Opt&&) = default;
            Opt& operator=(Opt&&) = default;
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
