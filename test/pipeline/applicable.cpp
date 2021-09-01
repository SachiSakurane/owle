#include <gtest/gtest.h>
#include <owle/pipeline/applicable.hpp>

#include "mock.hpp"

TEST(ApplicablePipelineTest, LLTest) {
  decltype(auto) value = true;
  decltype(auto) connection = Connection<bool, bool>{};
  decltype(auto) applicable = owle::applied(value) | connection;
  ASSERT_TRUE(applicable.apply());
  ASSERT_TRUE((owle::applied(value) | connection).apply());
}

TEST(ApplicablePipelineTest, LRTest) {
  decltype(auto) value = true;
  decltype(auto) applicable = owle::applied(value) | Connection<bool, bool>{};
  ASSERT_TRUE(applicable.apply());
  ASSERT_TRUE((owle::applied(value) | Connection<bool, bool>{}).apply());
}

TEST(ApplicablePipelineTest, RLTest) {
  decltype(auto) connection = Connection<bool, bool>{};
  decltype(auto) applicable = owle::applied(true) | connection;
  ASSERT_TRUE(applicable.apply());
  ASSERT_TRUE((owle::applied(true) | connection).apply());
}

TEST(ApplicablePipelineTest, RRTest) {
  decltype(auto) applicable = owle::applied(true) | Connection<bool, bool>{};
  ASSERT_TRUE(applicable.apply());
  ASSERT_TRUE((owle::applied(true) | Connection<bool, bool>{}).apply());
}

TEST(ApplicablePipelineTest, ValueTest) {
  decltype(auto) applicable = owle::applied(true) | Connection<bool, bool>{};
  ASSERT_TRUE(applicable.apply());
  ASSERT_TRUE((owle::applied(true) | Connection<bool, bool>{}).apply());
}

TEST(ApplicablePipelineTest, ApplicableTest) {
  decltype(auto) applicable = owle::applied(Applier<bool, true>{}) | Connection<bool, bool>{};
  ASSERT_TRUE(applicable.apply());
  ASSERT_TRUE((owle::applied(Applier<bool, true>{}) | Connection<bool, bool>{}).apply());
}

TEST(ApplicablePipelineTest, ComplexConnectionTest) {
  decltype(auto) applicable0 =
      owle::applied(Applier<bool, true>{}) | Connection<bool, int>{} | Connection<int, long>{};
  decltype(auto) applicable1 = std::move(applicable0) | Connection<long, bool>{};
  ASSERT_TRUE(applicable1.apply());
}
