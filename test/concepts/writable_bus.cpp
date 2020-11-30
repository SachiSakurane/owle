//
// Created by SachiSakurane on 2020/11/30.
//

#include <gtest/gtest.h>
#include <owle/concepts/writable_bus.hpp>

#include "mock_buses.hpp"

bool StaticWritableBusTest() {
    static_assert(!owle::WritableBus<BasicBaseBus>, "BasicBaseBus hasn't WritableBus concept");
    static_assert(owle::WritableBus<MutableWritableBus<int>>, "MutableReadableBus<int> has WritableBus concept");
    static_assert(!owle::WritableBus<ImmutableWritableBus<int>>, "ImmutableReadableBus<int> hasn't WritableBus concept");

    return true;
}

TEST(WritableBusConceptTest, StaticTest) {
    ASSERT_TRUE(StaticWritableBusTest());
}
