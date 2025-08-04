#include <catch2/catch_test_macros.hpp>
#include <catch2/matchers/catch_matchers_floating_point.hpp>

#include <linalg_vec.hpp>
#include <linalg_core.hpp>

using Catch::Matchers::WithinRel;

TEST_CASE("Vec operations double") {
    linalg::Opt opt = linalg::Opt::binary64();
    using V = linalg::Vec<4, double>;

    V x{1.0}, y{2.0};
    auto z = x.add(y, opt);
    for (int i = 0; i < 4; ++i)
        REQUIRE_THAT(z[i], WithinRel(3.0, 1e-12));

    auto w = x.mul(y, opt);
    for (int i = 0; i < 4; ++i)
        REQUIRE_THAT(w[i], WithinRel(2.0, 1e-12));

    REQUIRE_THAT(x.dot(y, opt), WithinRel(8.0, 1e-12));
}
