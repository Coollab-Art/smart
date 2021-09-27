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