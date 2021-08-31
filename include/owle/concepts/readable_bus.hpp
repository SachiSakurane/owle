#pragma once

#include <concepts>

#include <owle/concepts/base_bus.hpp>

namespace owle {
template <class ReadableBusType>
concept readable_bus = owle::base_bus<ReadableBusType> && requires() {
  typename std::remove_cvref_t<ReadableBusType>::value_type;
  {
    std::declval<const std::remove_cvref_t<ReadableBusType>>().data(std::declval<size_t>())
    } -> std::same_as<const typename std::remove_cvref_t<ReadableBusType>::value_type *>;
};
} // namespace owle
