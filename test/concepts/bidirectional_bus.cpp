#include <owle/concepts/bidirectional_bus.hpp>

#include "mock_buses.hpp"

namespace {
static_assert(!owle::BidirectionalBus<BasicBaseBus>,
              "BasicBaseBus hasn't BidirectionalBus concept");
static_assert(!owle::BidirectionalBus<ImmutableReadableBus<int>>,
              "ImmutableReadableBus<int> hasn't BidirectionalBus concept");
static_assert(!owle::BidirectionalBus<MutableWritableBus<int>>,
              "MutableWritableBus<int> hasn't BidirectionalBus concept");
static_assert(owle::BidirectionalBus<BidirectionalBus<int>>,
              "BidirectionalBus<int> has BidirectionalBus concept");
} // namespace
