//
// Created by SachiSakurane on 2020/11/26.
//

#pragma once

#include <owle/concepts/readable_bus.hpp>
#include <owle/concepts/writable_bus.hpp>

namespace owle {
    template <class BidirectionalBusType>
    concept BidirectionalBus = owle::ReadableBus<BidirectionalBusType> && owle::WritableBus<BidirectionalBusType>;
}