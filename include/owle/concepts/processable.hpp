#pragma once

#include <utility>

namespace owle {
template <class ProcessableType>
concept processable = requires(ProcessableType &p) {
  p();
};
} // namespace owle
