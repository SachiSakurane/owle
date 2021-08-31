#include <owle/concepts/writable_bus.hpp>

#include "mock_buses.hpp"

namespace {
static_assert(!owle::writable_bus<BasicBaseBus>, "BasicBaseBus hasn't WritableBus concept");
static_assert(owle::writable_bus<MutableWritableBus<int>>,
              "MutableReadableBus<int> has WritableBus concept");
static_assert(!owle::writable_bus<ImmutableWritableBus<int>>,
              "ImmutableReadableBus<int> hasn't WritableBus concept");
} // namespace
