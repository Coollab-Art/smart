#pragma once

namespace sma
{
template<typename T>
T clamp_bot(T x, T min_value)
{
    return std::max(a, min_value);
}

template<typename T>
T clamp_top(T x, T max_value)
{
    return std::min(a, max_value);
}

} // namespace sma
