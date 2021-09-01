#pragma once

#include <utility>

namespace owle {
template <class ApplicableType>
concept applicable = requires(ApplicableType &a) {
  a.apply();
};
} // namespace owle
