#include <catch2/catch_test_macros.hpp>
#include <catch2/matchers/catch_matchers_floating_point.hpp>

#include <linalg_core.hpp>

using Catch::Matchers::WithinRel;

TEST_CASE("linalg_core: cpfloat_add / cpfloat_mul") {
    linalg::Opt opt = linalg::Opt::binary64();
    double a = 1.5, b = 2.0, r = 0.0;

    REQUIRE(linalg::cpfloat_add(&r, &a, &b, 1, opt) == 0);
    REQUIRE_THAT(r, WithinRel(3.5, 1e-12));

    REQUIRE(linalg::cpfloat_mul(&r, &a, &b, 1, opt) == 0);
    REQUIRE_THAT(r, WithinRel(3.0, 1e-12));
}

TEST_CASE("linalg_core: cpfloat_dot (double)") {
    linalg::Opt opt = linalg::Opt::binary64();

    double A[3] = {1.0, 2.0, 3.0};
    double B[3] = {1.0, 1.0, 1.0};
    double res = 0.0;

    REQUIRE(linalg::cpfloat_dot(&res, A, B, 3, opt) == 0);
    REQUIRE_THAT(res, WithinRel(6.0, 1e-12));
}

TEST_CASE("linalg_core: cpfloat_dotf (float)") {
    linalg::Opt opt = linalg::Opt::binary32();

    float A[4] = {1.0f, 1.0f, 2.0f, 2.0f};
    float B[4] = {2.0f, 2.0f, 1.0f, 1.0f};
    float res = 0.0f;

    REQUIRE(linalg::cpfloat_dotf(&res, A, B, 4, opt) == 0);
    REQUIRE_THAT(res, WithinRel(8.0f, 1e-6f)); // Looser tolerance for float
}
