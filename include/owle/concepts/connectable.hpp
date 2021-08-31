#pragma once

#include <utility>

#include <owle/concepts/processable.hpp>

namespace owle {
template <class ConnectableType, class ArgumentType>
concept args_connectable = requires() {
  std::declval<ConnectableType>()(std::declval<ArgumentType>());
};

template <class ConnectionType, class ProcessableType>
concept process_connectable = requires() {
  std::declval<ConnectionType>()(std::declval<ProcessableType>()());
};

template <class ConnectionType, class Type>
concept connectable =
    args_connectable<ConnectionType, Type> || process_connectable<ConnectionType, Type>;
} // namespace owle
