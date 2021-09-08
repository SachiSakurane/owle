#pragma once

#include <owle/concepts/applicable.hpp>
#include <owle/concepts/connectable.hpp>
#include <owle/concepts/readable_bus.hpp>
#include <owle/utility/scalar.hpp>

namespace owle {
template <class ConnectionType, class UnaryArgType>
struct processable_binder {
  decltype(auto) apply() {
    return std::forward<ConnectionType>(connection).apply(std::forward<UnaryArgType>(arg));
  }

  ConnectionType &&connection;
  UnaryArgType &&arg;
};

template <class ConnectionType, owle::scalar UnaryArgType>
struct processable_binder<ConnectionType, UnaryArgType> {
  decltype(auto) apply() { return std::forward<ConnectionType>(connection).apply(arg); }

  ConnectionType &&connection;
  UnaryArgType arg;
};

template <class ConnectionType, owle::applicable ApplicableType>
requires apply_connectable<ConnectionType, ApplicableType>
struct processable_binder<ConnectionType, ApplicableType> {
  decltype(auto) apply() {
    return std::forward<ConnectionType>(_connection)
        .apply(std::forward<ApplicableType>(_applicable).apply());
  }

  ConnectionType &&_connection;
  ApplicableType &&_applicable;
};

// connection.process(value)
template <class Type, class ConnectionType>
requires owle::args_connectable<ConnectionType, Type>
inline decltype(auto) operator|(Type &&value, ConnectionType &&connection) {
  return owle::processable_binder<ConnectionType, Type>{std::forward<ConnectionType>(connection),
                                                        std::forward<Type>(value)};
}

// connection.process(processable.process())
template <owle::applicable ApplicableType, class ConnectionType>
requires owle::apply_connectable<ConnectionType, ApplicableType>
inline decltype(auto) operator|(ApplicableType &&applier, ConnectionType &&connection) {
  return owle::processable_binder<ConnectionType, ApplicableType>{
      std::forward<ConnectionType>(connection), std::forward<ApplicableType>(applier)};
}
} // namespace owle
