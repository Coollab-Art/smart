#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include <doctest/doctest.h>
#include <complex>
#include <smart/smart.hpp>

#define EQUALITY_COMPARABLE_TYPES int32_t, uint32_t, float, double, std::complex<float>, std::complex<double>
#define TOTALLY_ORDERED_TYPES     int32_t, uint32_t, float, double
#define SIGNED_TYPES              int16_t, int32_t, int64_t, float, double
#define SIGNED_INTEGER_TYPES      int16_t, int32_t, int64_t
#define SIGNED_FLOAT_TYPES        float, double

TEST_CASE_TEMPLATE("keep_above", T, TOTALLY_ORDERED_TYPES)
{
    constexpr auto keep_above_5 = [](auto x) {
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
    constexpr auto keep_below_5 = [](auto x) {
        return smart::keep_below(T{5}, x);
    };
    CHECK(keep_below_5(T{3}) == T{3});
    CHECK(keep_below_5(T{4}) == T{4});
    CHECK(keep_below_5(T{5}) == T{5});
    CHECK(keep_below_5(T{6}) == T{5});
    CHECK(keep_below_5(T{7}) == T{5});
}

TEST_CASE_TEMPLATE("sign", T, SIGNED_TYPES)
{
    CHECK(smart::sign(+T{0}) == T{+1});
    CHECK(smart::sign(-T{0}) == T{+1});
    CHECK(smart::sign(T{+3}) == T{+1});
    CHECK(smart::sign(T{-2}) == T{-1});
}

TEST_CASE_TEMPLATE("sign_or_0", T, SIGNED_TYPES)
{
    CHECK(smart::sign_or_0(+T{0}) == T{0});
    CHECK(smart::sign_or_0(-T{0}) == T{0});
    CHECK(smart::sign_or_0(T{+3}) == T{+1});
    CHECK(smart::sign_or_0(T{-2}) == T{-1});
}

TEST_CASE_TEMPLATE("mod", T, SIGNED_INTEGER_TYPES)
{
    CHECK(smart::mod(3, 10) == 3);
    CHECK(smart::mod(12, 10) == 2);
    CHECK(smart::mod(168796512, 10) == 2);
    CHECK(smart::mod(-1, 10) == 9);
    CHECK(smart::mod(-16, 10) == 4);
    CHECK(smart::mod(-46, 10) == 4);
    CHECK(smart::mod(-41265346, 10) == 4);

    CHECK(smart::mod(10, 10) == 0);
    CHECK(smart::mod(0, 10) == 0);
    CHECK(smart::mod(-10, 10) == 0);
    CHECK(smart::mod(-9, 10) == 1);
    CHECK(smart::mod(-11, 10) == 9);
}

TEST_CASE_TEMPLATE("mod", T, SIGNED_FLOAT_TYPES)
{
    CHECK(doctest::Approx{smart::mod(3., 10.)} == 3.);
    CHECK(doctest::Approx{smart::mod(12., 10.)} == 2.);
    CHECK(doctest::Approx{smart::mod(168796512., 10.)} == 2.);
    CHECK(doctest::Approx{smart::mod(-1., 10.)} == 9.);
    CHECK(doctest::Approx{smart::mod(-16., 10.)} == 4.);
    CHECK(doctest::Approx{smart::mod(-46., 10.)} == 4.);
    CHECK(doctest::Approx{smart::mod(-41265346., 10.)} == 4.);

    CHECK(doctest::Approx{smart::mod(10., 10.)} == 0.);
    CHECK(doctest::Approx{smart::mod(0., 10.)} == 0.);
    CHECK(doctest::Approx{smart::mod(-10., 10.)} == 0.);
    CHECK(doctest::Approx{smart::mod(-9., 10.)} == 1.);
    CHECK(doctest::Approx{smart::mod(-11., 10.)} == 9.);

    CHECK(doctest::Approx{smart::mod(0.2, 1.)} == 0.2);
    CHECK(doctest::Approx{smart::mod(8.2, 1.)} == 0.2);
    CHECK(doctest::Approx{smart::mod(-0.3, 1.)} == 0.7);
    CHECK(doctest::Approx{smart::mod(-2.3, 1.)} == 0.7);
}

TEST_CASE("as_fraction")
{
    CHECK(smart::as_fraction(0.5f) == smart::Fraction{1, 2});
    CHECK(smart::as_fraction(1.f) == smart::Fraction{1, 1});
    CHECK(smart::as_fraction(1.77777778) == smart::Fraction{16, 9});
}