//
// Created by SachiSakurane on 2020/11/12.
//

#pragma once

#include <owle/concepts/base_bus.hpp>

#ifndef __cpp_lib_concepts
#include <owle/preprocessor/has_member.hpp>
#endif

namespace owle {
#ifdef __cpp_lib_concepts
    template <class ReadableBusType>
    concept ReadableBus = owle::BaseBus<ReadableBusType> && requires () {
        typename std::remove_cvref_t<ReadableBusType>::value_type;
        {std::declval<ReadableBusType>().data(std::declval<size_t>())} ->
            owle::same_as<const typename std::remove_cvref_t<ReadableBusType>::value_type*>;
    };
#else
    namespace detail {
        OWLE_HAS_SINGLE_TYPE_CLASS_MEMBER(has_const_data,
                                          (owle::same_as<
                                              const typename std::remove_cvref_t<Type>::value_type*,
                                              decltype(std::declval<const std::remove_cvref_t<Type>>().data(std::declval<size_t>()))>))
    }

    template <class ReadableBusType>
    concept ReadableBus = owle::BaseBus<ReadableBusType> && detail::has_const_data_v<ReadableBusType>;

#endif
}
