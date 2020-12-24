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
        {std::declval<BaseBusType>().channel()} -> owle::convertible_to<size_t>;
        {std::declval<BaseBusType>().size()} -> owle::convertible_to<size_t>;
    };
#else
    namespace detail {
        OWLE_HAS_SINGLE_TYPE_CLASS_MEMBER(has_channel,
                                          (owle::convertible_to<size_t, decltype(std::declval<Type>().channel())>))
        OWLE_HAS_SINGLE_TYPE_CLASS_MEMBER(has_size,
                                          (owle::convertible_to<size_t, decltype(std::declval<Type>().size())>))
    }

    template <class BaseBusType>
    concept BaseBus = detail::has_channel_v<BaseBusType> && detail::has_size_v<BaseBusType>;
#endif
}
