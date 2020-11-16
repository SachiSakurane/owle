//
// Created by SachiP on 2020/11/12.
//

#pragma once

#include <owle/concepts/base_bus.hpp>

namespace owle {
    template <class ReadableBusType>
    concept ReadableBus = owle::BaseBus<ReadableBusType> && requires (const ReadableBusType& bus) {
        typename std::remove_cvref_t<ReadableBusType>::SampleType;
        {bus.getReadPointer(std::declval<int>())} ->
            owle::convertible_to<const typename std::remove_cvref_t<ReadableBusType>::SampleType*>;
    };
}
