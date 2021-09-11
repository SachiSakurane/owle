#pragma once

#include <owle/concepts/applicable.hpp>
#include <owle/concepts/connectable.hpp>
#include <owle/concepts/readable_bus.hpp>
#include <owle/range/connect.hpp>
#include <owle/utility/scalar.hpp>

namespace owle {
template <class ConnectionType, class UnaryArgType>
struct processable_binder {
  decltype(auto) apply() {
    return std::forward<ConnectionType>(connection).apply(std::forward<UnaryArgType>(arg));
  }

  UnaryArgType &&arg;
  ConnectionType &&connection;
};

template <class ConnectionType, owle::scalar UnaryArgType>
struct processable_binder<ConnectionType, UnaryArgType> {
  decltype(auto) apply() { return std::forward<ConnectionType>(connection).apply(arg); }

  UnaryArgType arg;
  ConnectionType &&connection;
};

template <class ConnectionType, owle::applicable ApplicableType>
requires apply_connectable<ConnectionType, ApplicableType>
struct processable_binder<ConnectionType, ApplicableType> {
  decltype(auto) apply() {
    return std::forward<ConnectionType>(_connection)
        .apply(std::forward<ApplicableType>(_applicable).apply());
  }

  ApplicableType &&_applicable;
  ConnectionType &&_connection;
};

// connection.process(value)
template <class Type, class ConnectionType>
requires owle::args_connectable<ConnectionType, Type>
inline decltype(auto) operator|(owle::connect_holder<Type> &&value, ConnectionType &&connection) {
  return owle::processable_binder<ConnectionType, Type>{std::forward<Type>(value.elem),
                                                        std::forward<ConnectionType>(connection)};
}

// connection.process(processable.process())
template <owle::applicable ApplicableType, class ConnectionType>
requires owle::apply_connectable<ConnectionType, ApplicableType>
inline decltype(auto) operator|(ApplicableType &&applier, ConnectionType &&connection) {
  return owle::processable_binder<ConnectionType, ApplicableType>{
      std::forward<ApplicableType>(applier), std::forward<ConnectionType>(connection)};
}
} // namespace owle
