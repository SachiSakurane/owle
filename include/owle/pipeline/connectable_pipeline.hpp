//
// Created by SachiSakurane on 2020/11/30.
//

#pragma once

#include <owle/pipeline/processable_pileline.hpp>

namespace owle {
    template <class LeftType, class RightType>
    struct ConnectableBinder {
        template <class Type> requires
            owle::Connectable<LeftType, Type> &&
            owle::ProcessConnectable<RightType, decltype(std::declval<Type>() | std::declval<LeftType>())>
        decltype(auto) operator()(Type&& value) {
            return (std::forward<Type>(value) | std::forward<LeftType>(left) | std::forward<RightType>(right))();
        }

        LeftType&& left;
        RightType&& right;

    };

    // right.process(left.process(value))
    template <class LeftType, class RightType, class = std::enable_if_t<!owle::Connectable<RightType, LeftType>>>
    inline decltype(auto) operator | (LeftType&& left, RightType&& right) {
        return owle::ConnectableBinder<LeftType, RightType> {
            std::forward<LeftType>(left),
            std::forward<RightType>(right)
        };
    }
}
