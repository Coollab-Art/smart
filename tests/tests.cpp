#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include <doctest/doctest.h>
#include <complex>
#include <smart/smart.hpp>

#define EQUALITY_COMPARABLE_TYPES int32_t, uint32_t, float, double, std::complex<float>
#define TOTALLY_ORDERED_TYPES     int32_t, uint32_t, float, double

TEST_CASE_TEMPLATE("keep_above", T, TOTALLY_ORDERED_TYPES)
{
    constexpr auto keep_above_5 = [](auto x)
    {
        return smart::keep_above(T{5}, x);
    };
    CHECK(keep_above_5(T{7}) == T{7});
    CHECK(keep_above_5(T{6}) == T{6});
    CHECK(keep_above_5(T{5}) == T{5});
    CHECK(keep_above_5(T{4}) == T{5});
    CHECK(keep_above_5(T{3}) == T{5});
}

TEST_CASE_TEMPLATE("keep_below", T, TOTALLY_ORDERED_TYPES)
{
    constexpr auto keep_below_5 = [](auto x)
    {
        return smart::keep_below(T{5}, x);
    };
    CHECK(keep_below_5(T{3}) == T{3});
    CHECK(keep_below_5(T{4}) == T{4});
    CHECK(keep_below_5(T{5}) == T{5});
    CHECK(keep_below_5(T{6}) == T{5});
    CHECK(keep_below_5(T{7}) == T{5});
}