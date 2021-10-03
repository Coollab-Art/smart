#pragma once

#include <cmath>
#include <numeric>

namespace smart
{

template<typename T>
T keep_above(T x, T min_value)
{
    return std::max(x, min_value);
}

template<typename T>
T keep_below(T x, T max_value)
{
    return std::min(x, max_value);
}

template<typename T>
T lerp(T a, T b, float t)
{
    return std::lerp(a, b, t);
}

template<typename T>
T midpoint(T a, T b)
{
    return std::midpoint(a, b);
}

} // namespace smart
