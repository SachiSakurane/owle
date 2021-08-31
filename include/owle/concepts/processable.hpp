#pragma once

#include <utility>

namespace owle {
template <class ProcessableType>
concept processable = requires() {
  std::declval<ProcessableType>()();
};
} // namespace owle
