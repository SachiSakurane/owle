#include <owle/concepts/bidirectional_bus.hpp>

#include "mock_buses.hpp"

namespace {
static_assert(!owle::bidirectional_bus<BasicBaseBus>,
              "BasicBaseBus hasn't BidirectionalBus concept");
static_assert(!owle::bidirectional_bus<ImmutableReadableBus<int>>,
              "ImmutableReadableBus<int> hasn't BidirectionalBus concept");
static_assert(!owle::bidirectional_bus<MutableWritableBus<int>>,
              "MutableWritableBus<int> hasn't BidirectionalBus concept");
static_assert(owle::bidirectional_bus<BidirectionalBus<int>>,
              "BidirectionalBus<int> has BidirectionalBus concept");
} // namespace
