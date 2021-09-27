#pragma once

namespace smart
{
template<typename T>
T clamp_bot(T x, T min_value)
{
    return std::max(x, min_value);
}

template<typename T>
T clamp_top(T x, T max_value)
{
    return std::min(x, max_value);
}

} // namespace smart
