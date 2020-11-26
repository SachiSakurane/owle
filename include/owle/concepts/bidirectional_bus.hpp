//
// Created by SachiP on 2020/11/26.
//

#include <owle/concepts/readable_bus.hpp>
#include <owle/concepts/writable_bus.hpp>

namespace owle {
    template <class BidirectionalBusType>
    concept BidirectionalBus =
        owle::BaseBus<BidirectionalBusType> &&
        owle::ReadableBus<BidirectionalBusType> &&
        owle::WritableBus<BidirectionalBusType>;
}