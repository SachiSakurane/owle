//
// Created by Himatya on 2020/11/30.
//

#include <gtest/gtest.h>
#include <owle/concepts/connectable.hpp>

struct Connection {
    bool process(int v) const { return v == 42; }
};

struct Process {
    int process() const { return 42; }
};

template <class ConnectionType, class ArgsType> requires owle::ArgsConnectable<ConnectionType, ArgsType>
struct ArgsConnectable {
    bool process() const { return ConnectionType().process(ArgsType{42}); }
};

template <class ConnectionType, class ProcessType> requires owle::ProcessConnectable<ConnectionType, ProcessType>
struct ProcessConnectable {
    bool process() const { return ConnectionType().process(ProcessType().process()); }
};

template <class ConnectionType, class Type> requires owle::Connectable<ConnectionType, Type>
struct Connectable {
    bool process() const {
        if constexpr (owle::ArgsConnectable<ConnectionType, Type>) {
            return ConnectionType().process(Type{42});
        } else if constexpr (owle::ProcessConnectable<ConnectionType, Type>) {
            return ConnectionType().process(Type().process());
        }
    }
};

TEST(ArgsConnectableTest, ArgsConnection) {
    ASSERT_FALSE(Connection().process(0));
    ASSERT_TRUE(Connection().process(42));
    ASSERT_TRUE((owle::ArgsConnectable<Connection, int>));
    ASSERT_TRUE((ArgsConnectable<Connection, int>().process()));
}

TEST(ProcessConnectableTest, ProcessConnection) {
    ASSERT_TRUE(Connection().process(Process().process()));
    ASSERT_TRUE((owle::ProcessConnectable<Connection, Process>));
    ASSERT_TRUE((ProcessConnectable<Connection, Process>().process()));
}

TEST(ConnectableTest, Connection) {
    ASSERT_TRUE((owle::Connectable<Connection, int>));
    ASSERT_TRUE((owle::Connectable<Connection, Process>));
    ASSERT_TRUE((Connectable<Connection, int>().process()));
    ASSERT_TRUE((Connectable<Connection, Process>().process()));
}
