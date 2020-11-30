//
// Created by SachiSakurane on 2020/11/30.
//

#include <gtest/gtest.h>
#include <owle/pipeline/connectable_pipeline.hpp>

#include "mock.hpp"

using namespace owle;

TEST(ConnectablePipelineConceptTest, ConnectionTest) {
    decltype(auto) connection = Connection<long, int>{} | Connection<int, bool>{};
    ASSERT_TRUE((static_cast<long>(0) | connection).process());
}
