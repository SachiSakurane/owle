#pragma once

#include <utility>

#include <owle/concepts/processable.hpp>

namespace owle {
template <class ConnectableType, class ArgumentType>
concept args_connectable = requires(ConnectableType &c, ArgumentType &arg) {
  c(arg);
};

template <class ConnectionType, class ProcessableType>
concept process_connectable = requires(ConnectionType &c, ProcessableType &p) {
  c(p());
};

template <class ConnectionType, class Type>
concept connectable =
    args_connectable<ConnectionType, Type> || process_connectable<ConnectionType, Type>;
} // namespace owle
