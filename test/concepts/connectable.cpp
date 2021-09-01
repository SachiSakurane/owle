#include <owle/concepts/connectable.hpp>

#include "mock_buses.hpp"

namespace {
static_assert(owle::args_connectable<Connection<int, bool>, int>,
              "<Connection<int, bool>, int> has ArgsConnectable concept");
static_assert(!owle::args_connectable<Connection<int, bool>, void>,
              "<Connection<int, bool>, void> hasn't ArgsConnectable concept");

static_assert(owle::process_connectable<Connection<int, bool>, Apply<int>>,
              "<Connection<int, bool>, Process<int>> has ProcessConnectable concept");
static_assert(!owle::process_connectable<Connection<int, bool>, Apply<void>>,
              "<Connection<int, bool>, Process<void>> hasn't ProcessConnectable concept");

static_assert(owle::connectable<Connection<int, bool>, int>,
              "<Connection<int, bool>, int> has Connectable concept");
static_assert(!owle::connectable<Connection<int, bool>, void>,
              "<Connection<int, bool>, void> hasn't Connectable concept");
static_assert(owle::connectable<Connection<int, bool>, Apply<int>>,
              "<Connection<int, bool>, Apply<int>> has Connectable concept");
static_assert(!owle::connectable<Connection<int, bool>, Apply<void>>,
              "<Connection<int, bool>, Apply<void>> hasn't Connectable concept");

} // namespace
