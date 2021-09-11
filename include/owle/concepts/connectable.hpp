#pragma once

#include <utility>

#include <owle/concepts/applicable.hpp>

namespace owle {
template <class ArgumentType, class ConnectableType>
concept args_connectable = requires(ConnectableType &c) {
  c.apply(std::declval<ArgumentType>());
};

template <class ApplicableType, class ConnectionType>
concept apply_connectable = owle::applicable<ApplicableType> &&
    requires(ConnectionType &c, ApplicableType &p) {
  c.apply(p.apply());
};

template <class Type, class ConnectionType>
concept connectable =
    args_connectable<Type, ConnectionType> || apply_connectable<Type, ConnectionType>;
} // namespace owle
