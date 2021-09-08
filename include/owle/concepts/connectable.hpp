#pragma once

#include <utility>

#include <owle/concepts/applicable.hpp>

namespace owle {
template <class ConnectableType, class ArgumentType>
concept args_connectable = requires(ConnectableType &c) {
  c.apply(std::declval<ArgumentType>());
};

template <class ConnectionType, class ApplicableType>
concept apply_connectable = owle::applicable<ApplicableType> &&
    requires(ConnectionType &c, ApplicableType &p) {
  c.apply(p.apply());
};

template <class ConnectionType, class Type>
concept connectable =
    args_connectable<ConnectionType, Type> || apply_connectable<ConnectionType, Type>;
} // namespace owle
