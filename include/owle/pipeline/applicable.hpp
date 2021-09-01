#pragma once

#include <owle/concepts/applicable.hpp>

namespace owle {
template <class Type>
struct applicable_holder {
  Type &&elem;
};

template <class Type>
applicable_holder(Type &&) -> applicable_holder<Type>;

template <class Type>
inline constexpr decltype(auto) applied(Type &&value) {
  return applicable_holder{std::forward<Type>(value)};
}

template <class LeftType, class RightType>
struct applicable_binder {
  decltype(auto) apply() {
    return std::forward<RightType>(right).apply(std::forward<LeftType>(left));
  }

  LeftType &&left;
  RightType &&right;
};

template <owle::applicable LeftType, class RightType>
struct applicable_binder<LeftType, RightType> {
  decltype(auto) apply() {
    return std::forward<RightType>(right).apply(std::forward<LeftType>(left).apply());
  }

  LeftType &&left;
  RightType &&right;
};

template <class LeftType, class RightType>
inline decltype(auto) operator|(owle::applicable_holder<LeftType> &&left, RightType &&right) {
  return owle::applicable_binder<LeftType, RightType>{std::forward<LeftType>(left.elem),
                                                      std::forward<RightType>(right)};
}

template <class BinderLeft, class BinderRight, class RightType>
inline decltype(auto) operator|(owle::applicable_binder<BinderLeft, BinderRight> &&left,
                                RightType &&right) {
  using BinderType = owle::applicable_binder<BinderLeft, BinderRight>;
  return owle::applicable_binder<BinderType, RightType>{std::forward<BinderType>(left),
                                                        std::forward<RightType>(right)};
}
} // namespace owle
