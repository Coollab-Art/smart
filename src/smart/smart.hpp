#pragma once

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

} // namespace smart
