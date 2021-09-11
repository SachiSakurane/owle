#include <gtest/gtest.h>
#include <owle/range/connectable.hpp>

#include "mock.hpp"

using namespace owle;

TEST(ConnectableRangeConceptTest, ConnectionTest) {
  decltype(auto) connection = Connection<long, int>{} | Connection<int, bool>{};
  decltype(auto) value = static_cast<int>(1);
  ASSERT_TRUE((owle::connect(value) | Connection<int, long>{}).apply());
  ASSERT_TRUE((owle::connect(static_cast<int>(1)) | Connection<int, long>{}).apply());
  ASSERT_TRUE(connection.apply(static_cast<long>(1)));
}
