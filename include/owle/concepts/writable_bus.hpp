//
// Created by SachiP on 2020/11/12.
//

#pragma once

#include <owle/concepts/base_bus.hpp>

namespace owle {
    template <class WritableBusType>
    concept WritableBus = owle::BaseBus<WritableBusType> && requires (WritableBusType& bus) {
        typename std::remove_cvref_t<WritableBusType>::SampleType;
        {bus.getWritePointer(std::declval<int>())} ->
            owle::convertible_to<typename std::remove_cvref_t<WritableBusType>::SampleType*>;
    };

}
