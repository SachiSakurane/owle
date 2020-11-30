//
// Created by SachiSakurane on 2020/11/30.
//

#include <gtest/gtest.h>
#include <owle/concepts/connectable.hpp>

#include "mock_buses.hpp"

bool StaticArgsConnectableTest() {
    static_assert(owle::ArgsConnectable<Connection<int, bool>, int>, "<Connection<int, bool>, int> has ArgsConnectable concept");
    static_assert(!owle::ArgsConnectable<Connection<int, bool>, void>, "<Connection<int, bool>, void> hasn't ArgsConnectable concept");

    return true;
}

bool StaticProcessConnectableTest() {
    static_assert(owle::ProcessConnectable<Connection<int, bool>, Process<int>>, "<Connection<int, bool>, Process<int>> has ProcessConnectable concept");
    static_assert(!owle::ProcessConnectable<Connection<int, bool>, Process<void>>, "<Connection<int, bool>, Process<void>> hasn't ProcessConnectable concept");

    return true;
}

bool StaticConnectableTest() {
    static_assert(owle::Connectable<Connection<int, bool>, int>, "<Connection<int, bool>, int> has Connectable concept");
    static_assert(!owle::Connectable<Connection<int, bool>, void>, "<Connection<int, bool>, void> hasn't Connectable concept");
    static_assert(owle::Connectable<Connection<int, bool>, Process<int>>, "<Connection<int, bool>, Process<int>> has Connectable concept");
    static_assert(!owle::Connectable<Connection<int, bool>, Process<void>>, "<Connection<int, bool>, Process<void>> hasn't Connectable concept");

    return true;
}

TEST(ArgsConnectableTest, StaticTest) {
    ASSERT_TRUE(StaticArgsConnectableTest());
}

TEST(ProcessConnectableTest, StaticTest) {
    ASSERT_TRUE(StaticProcessConnectableTest());
}

TEST(ConnectableTest, StaticTest) {
    ASSERT_TRUE(StaticConnectableTest());
}
