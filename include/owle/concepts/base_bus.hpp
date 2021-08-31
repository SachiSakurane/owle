#pragma once

#include <concepts>

namespace owle {
template <class BaseBusType>
concept base_bus = requires(const BaseBusType &b) {
  { b.channel() } -> std::same_as<std::size_t>;
  { b.size() } -> std::same_as<std::size_t>;
};
} // namespace owle
