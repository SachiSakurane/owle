#pragma once

#include <utility>

#include <owle/concepts/processable.hpp>

namespace owle {
template <class ConnectableType, class ArgumentType>
concept ArgsConnectable = requires() {
  std::declval<ConnectableType>()(std::declval<ArgumentType>());
};

template <class ConnectionType, class ProcessableType>
concept ProcessConnectable = requires() {
  std::declval<ConnectionType>()(std::declval<ProcessableType>()());
};

template <class ConnectionType, class Type>
concept Connectable =
    ArgsConnectable<ConnectionType, Type> || ProcessConnectable<ConnectionType, Type>;
} // namespace owle
