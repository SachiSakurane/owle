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
    template <class WritableBusType>
    concept WritableBus = owle::BaseBus<WritableBusType> && requires () {
        typename std::remove_cvref_t<WritableBusType>::value_type;
        {std::declval<WritableBusType>().data(std::declval<size_t>())} ->
            owle::convertible_to<typename std::remove_cvref_t<WritableBusType>::value_type*>;
    };
#else
    namespace detail {
        OWLE_HAS_SINGLE_TYPE_CLASS_MEMBER(has_writable_data,
                                          (owle::convertible_to<
                                              decltype(std::declval<Type>().data(std::declval<size_t>())),
                                              typename std::remove_volatile_t<std::remove_reference_t<Type>>::value_type*>))
    }

    template <class WritableBusType>
    concept WritableBus = owle::BaseBus<WritableBusType> && detail::has_writable_data_v<WritableBusType>;
#endif
}
