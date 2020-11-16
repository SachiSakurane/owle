//
// Created by Himatya on 2020/11/16.
//

#pragma once

#include <owle/pipeline/processable_pileline.hpp>

namespace owle {
    // left.process(right.process(value))
    template <class LeftType, class RightType>
    class ConnectableBinder {
    public:
        ConnectableBinder(LeftType&& left, RightType&& right) :
            left {std::forward<LeftType>(left)},
            right {std::forward<RightType>(right)} {}

        template <class Type> requires
            owle::Connectable<RightType, Type> &&
            owle::Connectable<LeftType, decltype(std::declval<RightType>().process(std::declval<Type>()))>
        decltype(auto) process(Type&& value) {
            return std::forward<Type>(value) | std::forward<RightType>(right) | std::forward<LeftType>(left);
        }

    private:
        LeftType&& left;
        RightType&& right;
    };

    template <class LeftType, class RightType>
    inline decltype(auto) operator | (LeftType&& left, RightType&& right) {
        return owle::ConnectableBinder<LeftType, RightType> {
            std::forward<LeftType>(left),
            std::forward<RightType>(right)
        };
    }
}
