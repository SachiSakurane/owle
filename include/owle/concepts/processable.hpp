#pragma once

namespace owle {
template <class ProcessableType>
concept Processable = requires() {
  std::declval<ProcessableType>()();
};
} // namespace owle
