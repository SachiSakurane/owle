#include <gtest/gtest.h>
#include <owle/pipeline/connection.hpp>

#include "mock.hpp"

TEST(ConnectionPipelineTest, ConnectTest) {
  decltype(auto) connection = owle::connected(Connection<long, int>{}) | Connection<int, bool>{};
  decltype(auto) value = static_cast<long>(1);
  ASSERT_TRUE(connection.apply(value));
}
