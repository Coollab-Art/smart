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

/**
 * @brief Returns +1, -1 or 0 depending on the sign of val
 */
template<typename T>
int sign_or_0(T val)
{
    return (T{0} < val) - (val < T{0});
}

/**
 * @brief Returns T{+1} or T{-1} depending on the sign of val.
 * It will never return T{0}. If val is T{0}, it returns T{+1}.
 */
template<typename T>
T sign(T val)
{
    return val < T{0} ? T{-1} : T{1};
}

} // namespace smart
