#pragma once

#include <owle/range/processable.hpp>

namespace owle {
template <class LeftType, class RightType>
struct connectable_binder {
  template <class Type>
  requires owle::connectable<Type, LeftType>
  decltype(auto) apply(Type &&value) {
    return std::forward<RightType>(right).apply(std::forward<LeftType>(left).apply(std::forward<Type>(value)));
  }

  LeftType &&left;
  RightType &&right;
};

// right.process(left.process(value))
template <class LeftType, class RightType>
inline decltype(auto) operator|(LeftType &&left, RightType &&right) {
  return owle::connectable_binder<LeftType, RightType>{std::forward<LeftType>(left),
                                                       std::forward<RightType>(right)};
}

} // namespace owle
