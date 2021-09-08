#include <gtest/gtest.h>
#include <owle/pipeline/processable_pileline.hpp>

#include "mock.hpp"

using namespace owle;

TEST(ProcessablePipelineConceptTest, LLTest) {
  decltype(auto) value = true;
  decltype(auto) connection = Connection<bool, bool>{};
  decltype(auto) processable = value | connection;
  ASSERT_TRUE(processable.apply());
  ASSERT_TRUE((value | connection).apply());
}

TEST(ProcessablePipelineConceptTest, LRTest) {
  decltype(auto) value = true;
  decltype(auto) processable = value | Connection<bool, bool>{};
  ASSERT_TRUE(processable.apply());
  ASSERT_TRUE((value | Connection<bool, bool>{}).apply());
}

TEST(ProcessablePipelineConceptTest, RLTest) {
  decltype(auto) connection = Connection<bool, bool>{};
  decltype(auto) processable = true | connection;
  ASSERT_TRUE(processable.apply());
  ASSERT_TRUE((true | connection).apply());
}

TEST(ProcessablePipelineConceptTest, RRTest) {
  decltype(auto) processable = true | Connection<bool, bool>{};
  ASSERT_TRUE(processable.apply());
  ASSERT_TRUE((true | Connection<bool, bool>{}).apply());
}

TEST(ProcessablePipelineConceptTest, ValueTest) {
  decltype(auto) processable = true | Connection<bool, bool>{};
  ASSERT_TRUE(processable.apply());
  ASSERT_TRUE((true | Connection<bool, bool>{}).apply());
}

TEST(ProcessablePipelineConceptTest, ProcessableTest) {
  decltype(auto) processable = Applier<bool, true>{} | Connection<bool, bool>{};
  ASSERT_TRUE(processable.apply());
  ASSERT_TRUE((Applier<bool, true>{} | Connection<bool, bool>{}).apply());
}

TEST(ProcessablePipelineConceptTest, ComplexConnectionTest) {
  decltype(auto) processable0 =
      Applier<bool, true>{} | Connection<bool, int>{} | Connection<int, long>{};
  decltype(auto) processable1 = processable0 | Connection<long, bool>{};
  ASSERT_TRUE(processable1.apply());
}
