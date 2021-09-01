#pragma once

#include <concepts>

#include <owle/concepts/base_bus.hpp>

namespace owle {
template <class ReadableBusType>
concept readable_bus = owle::base_bus<ReadableBusType> && requires(const ReadableBusType &r) {
  typename ReadableBusType::value_type;
  {
    r.data(std::declval<std::size_t>())
    } -> std::same_as<const typename ReadableBusType::value_type *>;
};
} // namespace owle
