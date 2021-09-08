#include <owle/concepts/bidirectional_bus.hpp>

#include "mock_buses.hpp"

namespace {
static_assert(!owle::bidirectional_bus<BasicBaseBus>,
              "BasicBaseBus hasn't bidirectional_bus concept");
static_assert(!owle::bidirectional_bus<ImmutableReadableBus<int>>,
              "ImmutableReadableBus<int> hasn't bidirectional_bus concept");
static_assert(!owle::bidirectional_bus<MutableWritableBus<int>>,
              "MutableWritableBus<int> hasn't bidirectional_bus concept");
static_assert(owle::bidirectional_bus<BidirectionalBus<int>>,
              "BidirectionalBus<int> has bidirectional_bus concept");
} // namespace
