#include <catch2/catch_test_macros.hpp>
#include <catch2/matchers/catch_matchers_floating_point.hpp>

#include <linalg_core.hpp>
#include <linalg_scalar.hpp>

using Catch::Matchers::WithinRel;

TEST_CASE("linalg_scalar: add / mul / fma, binary64") {
    linalg::Opt opt = linalg::Opt::binary64();

    double a = 1.25, b = 2.75;

    REQUIRE_THAT(linalg::add(a, b, opt), WithinRel(4.0, 1e-12));
    REQUIRE_THAT(linalg::mul(a, b, opt), WithinRel(3.4375, 1e-12));
    REQUIRE_THAT(linalg::fma(a, b, 3.0, opt), WithinRel(6.4375, 1e-12));
}

TEST_CASE("linalg_scalar: add / mul / fma, binary32") {
    linalg::Opt opt = linalg::Opt::binary32();

    float a = 1.25f, b = 2.75f;

    REQUIRE_THAT(linalg::add(a, b, opt), WithinRel(4.0f, 1e-6f));
    REQUIRE_THAT(linalg::mul(a, b, opt), WithinRel(3.4375f, 1e-6f));
}
