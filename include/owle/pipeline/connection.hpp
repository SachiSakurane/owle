#pragma once

#include <owle/concepts/applicable.hpp>
#include <owle/pipeline/applicable.hpp>

namespace owle {
template <class Type>
struct connect_holder {
  Type &&elem;
};

template <class Type>
connect_holder(Type &&) -> connect_holder<Type>;

template <class Type>
inline constexpr decltype(auto) connected(Type &&value) {
  return connect_holder{std::forward<Type>(value)};
}

template <class LeftType, class RightType>
struct connection_binder {
  template <class Type>
  decltype(auto) apply(Type &&value) {
    return std::forward<LeftType>(left).apply(
        std::forward<RightType>(right).apply(std::forward<Type>(value)));
  }

  LeftType &&left;
  RightType &&right;
};

template <class LeftType, class RightType>
inline decltype(auto) operator|(owle::connect_holder<LeftType> &&left, RightType &&right) {
  return owle::connection_binder<LeftType, RightType>{std::forward<LeftType>(left.elem),
                                                      std::forward<RightType>(right)};
}

template <class BinderLeft, class BinderRight, class RightType>
inline decltype(auto) operator|(owle::connection_binder<BinderLeft, BinderRight> &&left,
                                RightType &&right) {
  using BinderType = owle::connection_binder<BinderLeft, BinderRight>;
  return owle::connection_binder<BinderType, RightType>{std::forward<BinderType>(left),
                                                        std::forward<RightType>(right)};
}
} // namespace owle
