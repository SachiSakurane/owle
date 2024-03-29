#pragma once

#include <owle/concepts/readable_bus.hpp>
#include <owle/concepts/writable_bus.hpp>

namespace owle {
template <class BidirectionalBusType>
concept bidirectional_bus =
    owle::readable_bus<BidirectionalBusType> && owle::writable_bus<BidirectionalBusType>;
}
