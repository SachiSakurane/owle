//
// Created by Himatya on 2020/11/12.
//

#pragma once

#include <type_traits>

namespace owle{
    template <class T>
    concept floating_point = std::is_floating_point_v<T>;

    template<class From, class To>
    concept convertible_to = std::is_convertible_v<From, To> && requires(std::add_rvalue_reference_t<From> (&f)()) {
        static_cast<To>(f());
    };


}
