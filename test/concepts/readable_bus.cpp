//
// Created by SachiP on 2020/11/30.
//

#include <gtest/gtest.h>
#include <owle/concepts/readable_bus.hpp>

struct BasicBaseBus {
    size_t getNumChannels() const;
    size_t getNumSamples() const;
};

struct MutableIntReadableBus : BasicBaseBus {
    using SampleType = int;
    int* getReadPointer(int);
};

struct ImmutableIntReadableBus : BasicBaseBus {
    using SampleType = int;
    const int* getReadPointer(int) const;
};

bool StaticReadableBusTest() {
    static_assert(!owle::ReadableBus<BasicBaseBus>, "BasicBaseBus hasn't ReadableBus concept");
    static_assert(!owle::ReadableBus<MutableIntReadableBus>, "MutableIntReadableBus hasn't ReadableBus concept");
    static_assert(owle::ReadableBus<ImmutableIntReadableBus>, "ImmutableIntReadableBus hasn't ReadableBus concept");

    return true;
}

TEST(ReadableBusConceptTest, StaticTest) {
    ASSERT_TRUE(StaticReadableBusTest());
}
