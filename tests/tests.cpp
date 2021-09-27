#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include <doctest/doctest.h>
#include <smart/smart.hpp>

TEST_CASE("clamp_bot")
{
    {
        constexpr auto x = 10;
        CHECK(smart::clamp_bot(x, 0) == x);
        CHECK(smart::clamp_bot(x, 11) == 11);
        CHECK(smart::clamp_bot(x, x) == x);
    }
    {
        constexpr auto x = 10.f;
        CHECK(smart::clamp_bot(x, 0.f) == x);
        CHECK(smart::clamp_bot(x, 11.f) == 11.f);
        CHECK(smart::clamp_bot(x, x) == x);
    }
}

TEST_CASE("clamp_top")
{
    {
        constexpr auto x = 3;
        CHECK(smart::clamp_top(x, 10) == x);
        CHECK(smart::clamp_top(x, 2) == 2);
        CHECK(smart::clamp_top(x, x) == x);
    }
    {
        constexpr auto x = 3.f;
        CHECK(smart::clamp_top(x, 10.f) == x);
        CHECK(smart::clamp_top(x, 2.f) == 2.f);
        CHECK(smart::clamp_top(x, x) == x);
    }
}