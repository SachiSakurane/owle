#pragma once

#include <type_traits>

namespace owle {
template <class From, class To>
concept convertible_to = std::is_convertible_v<From, To> &&
    requires(std::add_rvalue_reference_t<From> (&f)()) {
  static_cast<To>(f());
};
} // namespace owle
