#pragma once

#include <owle/pipeline/processable_pileline.hpp>

namespace owle {
template <class LeftType, class RightType>
struct connectable_binder {
  template <class Type>
  requires owle::connectable<LeftType, Type> &&
      owle::process_connectable<RightType,
                                decltype(std::declval<Type>() | std::declval<LeftType>())>
  decltype(auto) operator()(Type &&value) {
    return (std::forward<Type>(value) | std::forward<LeftType>(left) |
            std::forward<RightType>(right))();
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
