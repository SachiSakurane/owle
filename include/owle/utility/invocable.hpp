#pragma once

#include <functional>
#include <type_traits>

namespace owle {
template <class F, class... Args>
concept invocable = requires(F &&f, Args &&...args) {
  std::invoke(std::forward<F>(f), std::forward<Args>(args)...);
};

template <class F, class... Args>
concept regular_invocable = invocable<F, Args...>;
} // namespace owle
