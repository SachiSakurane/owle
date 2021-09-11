#include <owle/concepts/connectable.hpp>

#include "mock_buses.hpp"

namespace {
static_assert(owle::args_connectable<int, Connection<int, bool>>,
              "<Connection<int, bool>, int> has ArgsConnectable concept");
static_assert(!owle::args_connectable<void, Connection<int, bool>>,
              "<Connection<int, bool>, void> hasn't ArgsConnectable concept");

static_assert(owle::apply_connectable<Apply<int>, Connection<int, bool>>,
              "<Connection<int, bool>, Process<int>> has ProcessConnectable concept");
static_assert(!owle::apply_connectable<Apply<void>, Connection<int, bool>>,
              "<Connection<int, bool>, Process<void>> hasn't ProcessConnectable concept");

static_assert(owle::connectable<int, Connection<int, bool>>,
              "<Connection<int, bool>, int> has Connectable concept");
static_assert(!owle::connectable<void, Connection<int, bool>>,
              "<Connection<int, bool>, void> hasn't Connectable concept");
static_assert(owle::connectable<Apply<int>, Connection<int, bool>>,
              "<Connection<int, bool>, Apply<int>> has Connectable concept");
static_assert(!owle::connectable<Apply<void>, Connection<int, bool>>,
              "<Connection<int, bool>, Apply<void>> hasn't Connectable concept");

} // namespace
