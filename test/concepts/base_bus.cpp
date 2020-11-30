//
// Created by SachiSakurane on 2020/11/30.
//

#include <gtest/gtest.h>
#include <owle/concepts/base_bus.hpp>

#include "mock_buses.hpp"

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
    static_assert(!owle::BaseBus<MissGetNumChannelsBaseBus>, "getNumChannels hasn't BaseBus concept");
    static_assert(!owle::BaseBus<MissGetNumSamplesBaseBus>, "getNumSamples hasn't BaseBus concept");

    return true;
}

TEST(BaseBusConceptTest, StaticTest) {
    ASSERT_TRUE(BaseBusStaticTest());
}
