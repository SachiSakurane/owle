#pragma once

#include <owle/concepts/connectable.hpp>
#include <owle/concepts/processable.hpp>
#include <owle/concepts/readable_bus.hpp>

namespace owle {
template <class ConnectionType, class UnaryArgType, class = void>
struct ProcessableBinder {
  decltype(auto) operator()() {
    return std::forward<ConnectionType>(connection)(std::forward<UnaryArgType>(arg));
  }

  ConnectionType &&connection;
  UnaryArgType &&arg;
};

template <class ConnectionType, class UnaryArgType>
struct ProcessableBinder<ConnectionType, UnaryArgType,
                         std::enable_if_t<std::is_scalar_v<UnaryArgType>>> {
  decltype(auto) operator()() { return std::forward<ConnectionType>(connection)(arg); }

  ConnectionType &&connection;
  UnaryArgType arg;
};

template <class ConnectionType, class ProcessableType>
struct ProcessableBinder<ConnectionType, ProcessableType,
                         std::enable_if_t<owle::Processable<ProcessableType> &&
                                          ProcessConnectable<ConnectionType, ProcessableType>>> {
  decltype(auto) operator()() {
    return std::forward<ConnectionType>(connection)(std::forward<ProcessableType>(processable)());
  }

  ConnectionType &&connection;
  ProcessableType &&processable;
};

// connection.process(value)
template <class Type, class ConnectionType>
requires owle::ArgsConnectable<ConnectionType, Type>
inline decltype(auto) operator|(Type &&value, ConnectionType &&connection) {
  return owle::ProcessableBinder<ConnectionType, Type>{std::forward<ConnectionType>(connection),
                                                       std::forward<Type>(value)};
}

// connection.process(processable.process())
template <class ProcessableType, class ConnectionType>
requires owle::Processable<ProcessableType> &&
    owle::ProcessConnectable<ConnectionType, ProcessableType>
inline decltype(auto) operator|(ProcessableType &&processable, ConnectionType &&connection) {
  return owle::ProcessableBinder<ConnectionType, ProcessableType>{
      std::forward<ConnectionType>(connection), std::forward<ProcessableType>(processable)};
}
} // namespace owle
