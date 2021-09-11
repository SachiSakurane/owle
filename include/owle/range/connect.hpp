#pragma once

#include <utility>

namespace owle {
template <class ValueType>
struct connect_holder {
  ValueType &&elem;
};

template <class ValueType>
inline decltype(auto) connect(ValueType &&value) {
  return connect_holder<ValueType>{std::forward<ValueType>(value)};
}
} // namespace owle