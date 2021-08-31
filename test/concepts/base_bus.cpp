#include <gtest/gtest.h>
#include <owle/concepts/base_bus.hpp>

#include "mock_buses.hpp"

struct MissGetNumChannelsBaseBus {
  void channel() const;
  size_t size() const;
};

struct MissGetNumSamplesBaseBus {
  size_t channel() const;
  void size() const;
};

bool BaseBusStaticTest() {
  static_assert(owle::BaseBus<BasicBaseBus>, "BasicBaseBus has BaseBus concept");
  static_assert(!owle::BaseBus<MissGetNumChannelsBaseBus>, "getNumChannels hasn't BaseBus concept");
  static_assert(!owle::BaseBus<MissGetNumSamplesBaseBus>, "getNumSamples hasn't BaseBus concept");

  return true;
}

TEST(BaseBusConceptTest, StaticTest) { ASSERT_TRUE(BaseBusStaticTest()); }
