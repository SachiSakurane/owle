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
        typename std::remove_cvref_t<ReadableBusType>::SampleType;
        {std::declval<ReadableBusType>().getReadPointer(std::declval<int>())} ->
            owle::convertible_to<const typename std::remove_cvref_t<ReadableBusType>::SampleType*>;
    };
#else
    namespace detail {
        OWLE_HAS_SINGLE_TYPE_CLASS_MEMBER(has_read_pointer,
                                          (owle::convertible_to<
                                              const typename std::remove_cvref_t<Type>::SampleType*,
                                              decltype(std::declval<Type>().getReadPointer(std::declval<int>()))>))
    }

    template <class ReadableBusType>
    concept ReadableBus = owle::BaseBus<ReadableBusType> && detail::has_read_pointer_v<ReadableBusType>;

#endif
}
