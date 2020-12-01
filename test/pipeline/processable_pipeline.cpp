//
// Created by SachiSakurane on 2020/11/30.
//

#include <gtest/gtest.h>
#include <owle/pipeline/processable_pileline.hpp>

#include "mock.hpp"

using namespace owle;

TEST(ProcessablePipelineConceptTest, LLTest) {
    decltype(auto) value = true;
    decltype(auto) connection = Connection<bool, bool>{};
    decltype(auto) processable = value | connection;
    ASSERT_TRUE(processable.process());
    ASSERT_TRUE((value | connection).process());
}

TEST(ProcessablePipelineConceptTest, LRTest) {
    decltype(auto) value = true;
    decltype(auto) processable = value | Connection<bool, bool>{};
    ASSERT_TRUE(processable.process());
    ASSERT_TRUE((value | Connection<bool, bool>{}).process());
}

TEST(ProcessablePipelineConceptTest, RLTest) {
    decltype(auto) connection = Connection<int, bool>{};
    decltype(auto) processable = 1 | connection;
    ASSERT_TRUE(processable.process());
    ASSERT_TRUE((1 | connection).process());
    decltype(auto) connection0 = Connection<bool, bool>{};
    decltype(auto) processable0 = true | connection;
    ASSERT_TRUE(processable0.process());
    ASSERT_TRUE((true | connection0).process());
}

TEST(ProcessablePipelineConceptTest, RRTest) {
    decltype(auto) processable = true | Connection<bool, bool>{};
    ASSERT_TRUE(processable.process());
    ASSERT_TRUE((true | Connection<bool, bool>{}).process());
}

TEST(ProcessablePipelineConceptTest, ValueTest) {
    decltype(auto) processable = true | Connection<bool, bool>{};
    ASSERT_TRUE(processable.process());
    ASSERT_TRUE((true | Connection<bool, bool>{}).process());
}

TEST(ProcessablePipelineConceptTest, ProcessableTest) {
    decltype(auto) processable = Process<bool, true>{} | Connection<bool, bool>{};
    ASSERT_TRUE(processable.process());
    ASSERT_TRUE((Process<bool, true>{} | Connection<bool, bool>{}).process());
}

TEST(ProcessablePipelineConceptTest, ComplexConnectionTest) {
    decltype(auto) processable0 = Process<bool, true>{} | Connection<bool, int>{} | Connection<int, long>{};
    decltype(auto) processable1 = processable0 | Connection<long, bool>{};
    ASSERT_TRUE(processable1.process());
}
