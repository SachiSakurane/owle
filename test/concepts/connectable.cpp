//
// Created by Himatya on 2020/11/30.
//

#include <gtest/gtest.h>
#include <owle/concepts/connectable.hpp>

struct Connection {
    bool process(int v);
};

struct IntProcess {
    int process();
};

struct VoidProcess {
    void process();
};

bool StaticArgsConnectableTest() {
    static_assert(owle::ArgsConnectable<Connection, int>, "<Connection, int> has ArgsConnectable concept");
    static_assert(!owle::ArgsConnectable<Connection, void>, "<Connection, void> hasn't ArgsConnectable concept");

    return true;
}

bool StaticProcessConnectableTest() {
    static_assert(owle::ProcessConnectable<Connection, IntProcess>, "<Connection, IntProcess> has ProcessConnectable concept");
    static_assert(!owle::ProcessConnectable<Connection, VoidProcess>, "<Connection, VoidProcess> hasn't ProcessConnectable concept");

    return true;
}

bool StaticConnectableTest() {
    static_assert(owle::Connectable<Connection, int>, "<Connection, int> has Connectable concept");
    static_assert(!owle::Connectable<Connection, void>, "<Connection, void> hasn't Connectable concept");
    static_assert(owle::Connectable<Connection, IntProcess>, "<Connection, IntProcess> has Connectable concept");
    static_assert(!owle::Connectable<Connection, VoidProcess>, "<Connection, VoidProcess> hasn't Connectable concept");

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
