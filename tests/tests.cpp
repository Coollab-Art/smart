#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include <doctest/doctest.h>
#include <smart/smart.hpp>

TEST_CASE_TEMPLATE("clamp_bot", T, int, float, double)
{
    constexpr auto clamp_bot_5 = [](auto x)
    {
        return smart::clamp_bot(x, T{5});
    };
    CHECK(clamp_bot_5(T{7}) == T{7});
    CHECK(clamp_bot_5(T{6}) == T{6});
    CHECK(clamp_bot_5(T{5}) == T{5});
    CHECK(clamp_bot_5(T{4}) == T{5});
    CHECK(clamp_bot_5(T{3}) == T{5});
}

TEST_CASE_TEMPLATE("clamp_top", T, int, float, double)
{
    constexpr auto clamp_top_5 = [](auto x)
    {
        return smart::clamp_top(x, T{5});
    };
    CHECK(clamp_top_5(T{3}) == T{3});
    CHECK(clamp_top_5(T{4}) == T{4});
    CHECK(clamp_top_5(T{5}) == T{5});
    CHECK(clamp_top_5(T{6}) == T{5});
    CHECK(clamp_top_5(T{7}) == T{5});
}