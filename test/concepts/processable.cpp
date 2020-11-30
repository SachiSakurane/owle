//
// Created by Himatya on 2020/11/30.
//

#include <gtest/gtest.h>
#include <owle/concepts/processable.hpp>

struct BoolProcess {
    bool process();
};

struct VoidProcess {
    void process();
};

struct MissProcess {
    void proceed();
};

bool ProcessableStaticTest() {
    static_assert(owle::Processable<BoolProcess>, "BoolProcess has Processable concept");
    static_assert(owle::Processable<VoidProcess>, "VoidProcess has Processable concept");
    static_assert(!owle::Processable<MissProcess>, "VoidProcess has Processable concept");
    return true;
}

TEST(ProcessableTest, StaticTest) {
    ASSERT_TRUE(ProcessableStaticTest());
}
