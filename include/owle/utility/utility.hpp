//
// Created by SachiSakurane on 2020/11/12.
//

#pragma once

#include <type_traits>

namespace owle{
    template<class>
    struct sfinae_true : std::true_type{};

    template <class T>
    concept floating_point = std::is_floating_point_v<T>;

    template<class From, class To>
    concept convertible_to = std::is_convertible_v<From, To>;
}
