#pragma once

#include <type_traits>

namespace owle {
template <class Type>
concept scalar = std::is_scalar_v<Type>;
}
