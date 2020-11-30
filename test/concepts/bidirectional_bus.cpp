//
// Created by SachiSakurane on 2020/11/30.
//

#include <gtest/gtest.h>
#include <owle/concepts/bidirectional_bus.hpp>

#include "mock_buses.hpp"

bool StaticBidirectionalBusTest() {
    static_assert(!owle::BidirectionalBus<BasicBaseBus>, "BasicBaseBus hasn't BidirectionalBus concept");
    static_assert(!owle::BidirectionalBus<ImmutableReadableBus<int>>, "ImmutableReadableBus<int> hasn't BidirectionalBus concept");
    static_assert(!owle::BidirectionalBus<MutableWritableBus<int>>, "MutableWritableBus<int> hasn't BidirectionalBus concept");
    static_assert(owle::BidirectionalBus<BidirectionalBus<int>>, "BidirectionalBus<int> has BidirectionalBus concept");

    return true;
}

TEST(BidirectionalBusConceptTest, StaticTest) {
    ASSERT_TRUE(StaticBidirectionalBusTest());
}
