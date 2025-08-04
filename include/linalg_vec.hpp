#ifndef LINALG_VEC_HPP
#define LINALG_VEC_HPP

#include <cstddef>
#include <type_traits>

#include "linalg_core.hpp"

namespace linalg {
    template<std::size_t N, typename T>

    struct Vec {
        static_assert(
            std::is_same_v<T, float> || std::is_same_v<T, double>,
            "Vec: T must be float OR double."
        );

        T v[N];

        constexpr Vec() : v{} {}

        constexpr Vec(T value) {
            for (std::size_t i = 0; i < N; ++i) {
                v[i] = value;
            }
        }

        static constexpr Vec load(const T *ptr) {
            Vec X;

            for (std::size_t i = 0; i < N; ++i) {
                X.v[i] = ptr[i];
            }

            return X;
        }

        void store(T *ptr) const {
            for (std::size_t i = 0; i < N; ++i) {
                ptr[i] = v[i];
            }
        }

        // overloads for the subscript operator []
        constexpr T& operator[](std::size_t i) noexcept { return v[i]; }
        constexpr const T& operator[](std::size_t i) const noexcept { return v[i]; }

        Vec add(const Vec &b, optstruct *fpopts) const {
            Vec X;

            for (std::size_t i = 0; i < N; ++i) {
                if constexpr (std::is_same_v<T, double>) {
                    cpfloat_add(&X.v[i], &v[i], &b.v[i], 1, fpopts);
                } else {
                    cpfloat_addf(&X.v[i], &v[i], &b.v[i], 1, fpopts);
                }
            }

            return X;
        }

        Vec mul(const Vec &b, optstruct *fpopts) const {
            Vec X;

            for (std::size_t i = 0; i < N; ++i) {
                if constexpr (std::is_same_v<T, double>) {
                    cpfloat_mul(&X.v[i], &v[i], &b.v[i], 1, fpopts);
                } else {
                    cpfloat_mulf(&X.v[i], &v[i], &b.v[i], 1, fpopts);
                }
            }

            return X;
        }

        Vec fma(const Vec &b, const Vec &c, optstruct *fpopts) const {
            Vec X;

            for (std::size_t i = 0; i < N; ++i) {
                if constexpr (std::is_same_v<T, double>) {
                    cpfloat_fma(&X.v[i], &v[i], &b.v[i], &c.v[i], 1, fpopts);
                } else {
                    cpfloat_fmaf(&X.v[i], &v[i], &b.v[i], &c.v[i], 1, fpopts);
                }
            }

            return X;
        }

        T dot(const Vec& b, optstruct* fpopts) const {
            T X{};
            
            // cpfloat_fma(f) is used instead of cpfloat_dot(f)
            // for future SIMD optimisation.
            for (std::size_t i = 0; i < N; ++i) {
                if constexpr (std::is_same_v<T,double>) {
                    cpfloat_fma(&X, &v[i], &b.v[i], &X, 1, fpopts);
                } else {
                    cpfloat_fmaf(&X, &v[i], &b.v[i], &X, 1, fpopts);
                }
            }
    
            return X;
        }
    };
}

#endif /* LINALG_VEC_HPP */
