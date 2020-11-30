//
// Created by SachiP on 2020/11/30.
//

#include <gtest/gtest.h>
#include <owle/concepts/base_bus.hpp>

struct BasicBaseBus {
    size_t getNumChannels() const;
    size_t getNumSamples() const;
};

struct MissGetNumChannelsBaseBus {
    void getNumChannels() const;
    size_t getNumSamples() const;
};

struct MissGetNumSamplesBaseBus {
    size_t getNumChannels() const;
    void getNumSamples() const;
};

bool BaseBusStaticTest() {
    static_assert(owle::BaseBus<BasicBaseBus>, "BasicBaseBus has BaseBus concept");
    static_assert(!owle::BaseBus<MissGetNumChannelsBaseBus>, "getNumChannels out of BaseBus concept");
    static_assert(!owle::BaseBus<MissGetNumSamplesBaseBus>, "getNumSamples out of BaseBus concept");

    return true;
}

TEST(BaseBusConceptTest, StaticTest) {
    ASSERT_TRUE(BaseBusStaticTest());
}
