#pragma once

#include <owle/concepts/base_bus.hpp>
#include <owle/utility/convertible_to.hpp>

namespace owle {
template <class WritableBusType>
concept WritableBus = owle::BaseBus<WritableBusType> && requires() {
  typename std::remove_cvref_t<WritableBusType>::value_type;
  {
    std::declval<WritableBusType>().data(std::declval<size_t>())
    } -> owle::convertible_to<typename std::remove_cvref_t<WritableBusType>::value_type *>;
};
} // namespace owle
