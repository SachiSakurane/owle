//
// Created by SachiSakurane on 2020/11/30.
//

#include <gtest/gtest.h>
#include <owle/concepts/readable_bus.hpp>

#include "mock_buses.hpp"

namespace afcn {

}

bool StaticReadableBusTest() {
    static_assert(!owle::ReadableBus<BasicBaseBus>, "BasicBaseBus hasn't ReadableBus concept");
    static_assert(!owle::ReadableBus<MutableReadableBus<int>>, "MutableReadableBus<int> hasn't ReadableBus concept");
    static_assert(owle::ReadableBus<ImmutableReadableBus<int>>, "ImmutableReadableBus<int> has ReadableBus concept");

    return true;
}

TEST(ReadableBusConceptTest, StaticTest) {
    ASSERT_TRUE(StaticReadableBusTest());
}
