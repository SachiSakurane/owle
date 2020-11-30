//
// Created by Himatya on 2020/11/30.
//

#include <gtest/gtest.h>
#include <owle/concepts/connectable.hpp>

struct Connection {
    bool process(int) const { return true; }
};

struct Process {
    int process() const { return 0; }
};

template <class ConnectionType, class ArgsType> requires owle::ArgsConnectable<ConnectionType, ArgsType>
struct ArgsConnectable {
    bool process() const { return ConnectionType().process(ArgsType{0}); }
};

template <class ConnectionType, class ProcessType> requires owle::ProcessConnectable<ConnectionType, ProcessType>
struct ProcessConnectable {
    bool process() const { return ConnectionType().process(ProcessType().process()); }
};

template <class ConnectionType, class Type> requires owle::Connectable<ConnectionType, Type>
struct Connectable {
    bool process() const {
        if constexpr (owle::ArgsConnectable<ConnectionType, Type>) {
            return ConnectionType().process(Type{0});
        } else if constexpr (owle::ProcessConnectable<ConnectionType, Type>) {
            return ConnectionType().process(Type().process());
        }
    }
};

TEST(ArgsConnectableTest, ArgsConnection) {
    ASSERT_EQ((owle::ArgsConnectable<Connection, int>), true);
    ASSERT_EQ((ArgsConnectable<Connection, int>().process()), true);
}

TEST(ProcessConnectableTest, ProcessConnection) {
    ASSERT_EQ((owle::ProcessConnectable<Connection, Process>), true);
    ASSERT_EQ((ProcessConnectable<Connection, Process>().process()), true);
}

TEST(ConnectableTest, Connection) {
    ASSERT_EQ((owle::Connectable<Connection, int>), true);
    ASSERT_EQ((owle::Connectable<Connection, Process>), true);
    ASSERT_EQ((Connectable<Connection, int>().process()), true);
    ASSERT_EQ((Connectable<Connection, Process>().process()), true);
}
