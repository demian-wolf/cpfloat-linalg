#include <catch2/catch_test_macros.hpp>
#include <catch2/matchers/catch_matchers_string.hpp>

#include <linalg_check.hpp>

using Catch::Matchers::StartsWith;

TEST_CASE("linalg_check: OK for status 0") {
    REQUIRE_NOTHROW(detail::check(0, "dummy_func"));
}

#ifndef NDEBUG
TEST_CASE("linalg_check: throws on non-zero status in DEBUG") {
    const int err = 5;
    const char* func = "failing_func";
    
    REQUIRE_THROWS_WITH(detail::check(err, func), StartsWith(std::string(func)));
}
#endif
