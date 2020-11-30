//
// Created by SachiP on 2020/11/12.
//

#pragma once

#include <owle/utility/utility.hpp>

namespace owle {
    template <class BaseBusType>
    concept BaseBus = requires () {
        {std::declval<BaseBusType>().getNumChannels()} -> owle::convertible_to<size_t>;
        {std::declval<BaseBusType>().getNumSamples()} -> owle::convertible_to<size_t>;
    };
}
