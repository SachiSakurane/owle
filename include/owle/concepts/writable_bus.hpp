#pragma once

#include <concepts>

#include <owle/concepts/base_bus.hpp>

namespace owle {
template <class WritableBusType>
concept writable_bus = owle::base_bus<WritableBusType> && requires(WritableBusType &w) {
  typename WritableBusType::value_type;
  { w.data(std::declval<size_t>()) } -> std::same_as<typename WritableBusType::value_type *>;
};
} // namespace owle
