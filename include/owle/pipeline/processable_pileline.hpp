//
// Created by Himatya on 2020/11/09.
//

#pragma once

#include <owle/concepts/connectable.hpp>
#include <owle/concepts/processable.hpp>
#include <owle/concepts/readable_bus.hpp>

namespace owle {

    template <class ConnectionType, class UnaryArgType>
    class ProcessableBinder {
    public:
        explicit ProcessableBinder(ConnectionType&& connection, UnaryArgType arg) :
            connection {std::forward<ConnectionType>(connection)},
            arg {std::forward<UnaryArgType>(arg)} {
        }

        decltype(auto) process() {
            return std::forward<ConnectionType>(connection).process(
                std::forward<UnaryArgType>(arg));
        }

    private:
        ConnectionType&& connection;
        UnaryArgType&& arg;

    };

    template <class ConnectionType, owle::Processable ProcessableType> requires ProcessConnectable<ConnectionType, ProcessableType>
    class ProcessableBinder<ConnectionType, ProcessableType> {
    public:
        ProcessableBinder(ConnectionType&& connection, ProcessableType&& processable) :
            connection {std::forward<ConnectionType>(connection)},
            processable {std::forward<ProcessableType>(processable)} {
        }

        decltype(auto) process() {
            return std::forward<ConnectionType>(connection).process(
                std::forward<ProcessableType>(processable).process());
        }

    private:
        ConnectionType&& connection;
        ProcessableType&& processable;

    };

    // connection.process(value)
    template <class Type, class ConnectionType> requires owle::ArgsConnectable<ConnectionType, Type>
    inline decltype(auto) operator | (Type&& value, ConnectionType&& connection) {
        return owle::ProcessableBinder<ConnectionType, Type>
            {std::forward<ConnectionType>(connection), std::forward<Type>(value)};
    }

    // connection.process(processable.process())
    template <owle::Processable ProcessableType, class ConnectionType>
    requires ProcessConnectable<ConnectionType, ProcessableType>
    inline decltype(auto) operator | (ProcessableType&& processable, ConnectionType&& connection) {
        return owle::ProcessableBinder<ConnectionType, ProcessableType>
            {std::forward<ConnectionType>(connection), std::forward<ProcessableType>(processable)};
    }
}
