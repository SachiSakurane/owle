#include <gtest/gtest.h>
#include <owle/concepts/processable.hpp>

#include "mock_buses.hpp"

struct MissProcess {
  void proceed();
};

bool ProcessableStaticTest() {
  static_assert(owle::Processable<Process<bool>>, "Process<bool> has Processable concept");
  static_assert(owle::Processable<Process<void>>, "Process<void> has Processable concept");
  static_assert(!owle::Processable<MissProcess>, "VoidProcess has Processable concept");
  return true;
}

TEST(ProcessableTest, StaticTest) { ASSERT_TRUE(ProcessableStaticTest()); }
