//
// Created by SachiSakurane on 2020/11/12.
//

#pragma once

#include <owle/utility/utility.hpp>

#ifndef __cpp_lib_concepts
#include <owle/preprocessor/has_member.hpp>
#endif

namespace owle {
#ifdef __cpp_lib_concepts
    template <class BaseBusType>
    concept BaseBus = requires () {
        {std::declval<BaseBusType>().getNumChannels()} -> owle::convertible_to<size_t>;
        {std::declval<BaseBusType>().getNumSamples()} -> owle::convertible_to<size_t>;
    };
#else
    namespace detail {
        OWLE_HAS_SINGLE_TYPE_CLASS_MEMBER(has_get_num_channels,
                                          (owle::convertible_to<size_t, decltype(std::declval<Type>().getNumChannels())>))
        OWLE_HAS_SINGLE_TYPE_CLASS_MEMBER(has_get_num_samples,
                                          (owle::convertible_to<size_t, decltype(std::declval<Type>().getNumSamples())>))
    }

    template <class BaseBusType>
    concept BaseBus = detail::has_get_num_channels_v<BaseBusType> && detail::has_get_num_samples_v<BaseBusType>;
#endif
}
