#pragma once

#include <type_traits>

namespace owle {
template <class Type>
concept arithmetic = std::is_arithmetic_v<Type>;
}
