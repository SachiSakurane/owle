#pragma once

#include <owle/utility/convertible_to.hpp>

template <class From, class To>
requires owle::convertible_to<From, To>
struct Connection {
  To operator()(From v) { return static_cast<To>(v); }
};

template <class Type, Type Value>
struct Process {
  Type operator()() { return Value; }
};
