#include <gtest/gtest.h>
#include <owle/concepts/readable_bus.hpp>

#include "mock_buses.hpp"

bool StaticReadableBusTest() {
  static_assert(!owle::ReadableBus<BasicBaseBus>, "BasicBaseBus hasn't ReadableBus concept");
  static_assert(!owle::ReadableBus<MutableReadableBus<int>>,
                "MutableReadableBus<int> hasn't ReadableBus concept");
  static_assert(owle::ReadableBus<ImmutableReadableBus<int>>,
                "ImmutableReadableBus<int> has ReadableBus concept");

  return true;
}

TEST(ReadableBusConceptTest, StaticTest) { ASSERT_TRUE(StaticReadableBusTest()); }
