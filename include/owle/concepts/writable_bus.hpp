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
    concept WritableBus =
        owle::BaseBus<WritableBusType> &&
        std::is_object_v<typename std::remove_cvref_t<WritableBusType>::SampleType> &&
        requires () {
        {std::declval<WritableBusType>().getWritePointer(std::declval<int>())} ->
            owle::convertible_to<typename std::remove_cvref_t<WritableBusType>::SampleType*>;
    };
#else
    namespace detail {
        OWLE_HAS_SINGLE_TYPE_CLASS_MEMBER(has_write_pointer,
                                          (owle::convertible_to<
                                              decltype(std::declval<Type>().getWritePointer(std::declval<int>())),
                                              typename std::remove_volatile_t<std::remove_reference_t<Type>>::SampleType*>))
    }

    template <class WritableBusType>
    concept WritableBus =
        owle::BaseBus<WritableBusType> &&
        std::is_object_v<typename std::remove_cvref_t<WritableBusType>::SampleType> &&
        detail::has_write_pointer_v<WritableBusType>;
#endif
}
