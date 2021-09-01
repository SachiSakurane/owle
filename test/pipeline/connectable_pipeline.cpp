#include <gtest/gtest.h>
#include <owle/pipeline/connectable_pipeline.hpp>

#include "mock.hpp"

using namespace owle;

TEST(ConnectablePipelineConceptTest, ConnectionTest) {
  decltype(auto) connection = Connection<long, int>{} | Connection<int, bool>{};
  decltype(auto) value = static_cast<int>(1);
  ASSERT_TRUE((value | Connection<int, long>{}).apply());
  ASSERT_TRUE((static_cast<int>(1) | Connection<int, long>{}).apply());
  ASSERT_TRUE((static_cast<long>(1) | connection).apply());
}
