#pragma once

#include <owle/concepts/connectable.hpp>
#include <owle/concepts/processable.hpp>
#include <owle/concepts/readable_bus.hpp>
#include <owle/utility/scalar.hpp>

namespace owle {
template <class ConnectionType, class UnaryArgType>
struct processable_binder {
  decltype(auto) operator()() {
    return std::forward<ConnectionType>(connection)(std::forward<UnaryArgType>(arg));
  }

  ConnectionType &&connection;
  UnaryArgType &&arg;
};

template <class ConnectionType, owle::scalar UnaryArgType>
struct processable_binder<ConnectionType, UnaryArgType> {
  decltype(auto) operator()() { return std::forward<ConnectionType>(connection)(arg); }

  ConnectionType &&connection;
  UnaryArgType arg;
};

template <class ConnectionType, class ProcessableType>
requires owle::processable<ProcessableType> && process_connectable<ConnectionType, ProcessableType>
struct processable_binder<ConnectionType, ProcessableType> {
  decltype(auto) operator()() {
    return std::forward<ConnectionType>(connection)(std::forward<ProcessableType>(processable)());
  }

  ConnectionType &&connection;
  ProcessableType &&processable;
};

// connection.process(value)
template <class Type, class ConnectionType>
requires owle::args_connectable<ConnectionType, Type>
inline decltype(auto) operator|(Type &&value, ConnectionType &&connection) {
  return owle::processable_binder<ConnectionType, Type>{std::forward<ConnectionType>(connection),
                                                       std::forward<Type>(value)};
}

// connection.process(processable.process())
template <class ProcessableType, class ConnectionType>
requires owle::processable<ProcessableType> &&
    owle::process_connectable<ConnectionType, ProcessableType>
inline decltype(auto) operator|(ProcessableType &&processable, ConnectionType &&connection) {
  return owle::processable_binder<ConnectionType, ProcessableType>{
      std::forward<ConnectionType>(connection), std::forward<ProcessableType>(processable)};
}
} // namespace owle
