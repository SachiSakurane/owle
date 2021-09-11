#include <gtest/gtest.h>
#include <owle/range/processable.hpp>

#include "mock.hpp"

using namespace owle;

TEST(ProcessableRangeConceptTest, LLTest) {
  decltype(auto) value = true;
  decltype(auto) connection = Connection<bool, bool>{};
  decltype(auto) processable = owle::connect(value) | connection;
  ASSERT_TRUE(processable.apply());
  ASSERT_TRUE((owle::connect(value) | connection).apply());
}

TEST(ProcessableRangeConceptTest, LRTest) {
  decltype(auto) value = true;
  decltype(auto) processable = owle::connect(value) | Connection<bool, bool>{};
  ASSERT_TRUE(processable.apply());
  ASSERT_TRUE((owle::connect(value) | Connection<bool, bool>{}).apply());
}

TEST(ProcessableRangeConceptTest, RLTest) {
  decltype(auto) connection = Connection<bool, bool>{};
  decltype(auto) processable = owle::connect(true) | connection;
  ASSERT_TRUE(processable.apply());
  ASSERT_TRUE((owle::connect(true) | connection).apply());
}

TEST(ProcessableRangeConceptTest, RRTest) {
  decltype(auto) processable = owle::connect(true) | Connection<bool, bool>{};
  ASSERT_TRUE(processable.apply());
  ASSERT_TRUE((owle::connect(true) | Connection<bool, bool>{}).apply());
}

TEST(ProcessableRangeConceptTest, ValueTest) {
  decltype(auto) processable = owle::connect(true) | Connection<bool, bool>{};
  ASSERT_TRUE(processable.apply());
  ASSERT_TRUE((owle::connect(true) | Connection<bool, bool>{}).apply());
}

TEST(ProcessableRangeConceptTest, ProcessableTest) {
  decltype(auto) processable = Applier<bool, true>{} | Connection<bool, bool>{};
  ASSERT_TRUE(processable.apply());
  ASSERT_TRUE((Applier<bool, true>{} | Connection<bool, bool>{}).apply());
}

TEST(ProcessableRangeConceptTest, ComplexConnectionTest) {
  decltype(auto) processable0 =
      Applier<bool, true>{} | Connection<bool, int>{} | Connection<int, long>{};
  decltype(auto) processable1 = processable0 | Connection<long, bool>{};
  ASSERT_TRUE(processable1.apply());
}
