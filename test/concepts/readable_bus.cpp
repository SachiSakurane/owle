#include <owle/concepts/readable_bus.hpp>

#include "mock_buses.hpp"

namespace {
static_assert(!owle::readable_bus<BasicBaseBus>, "BasicBaseBus hasn't ReadableBus concept");
static_assert(!owle::readable_bus<MutableReadableBus<int>>,
              "MutableReadableBus<int> hasn't ReadableBus concept");
static_assert(owle::readable_bus<ImmutableReadableBus<int>>,
              "ImmutableReadableBus<int> has ReadableBus concept");
} // namespace
