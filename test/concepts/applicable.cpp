#include <owle/concepts/applicable.hpp>

#include "mock_buses.hpp"

struct MissApply {
  void proceed();
};

namespace {
static_assert(owle::applicable<Apply<bool>>, "Process<bool> has Processable concept");
static_assert(owle::applicable<Apply<void>>, "Process<void> has Processable concept");
static_assert(!owle::applicable<MissApply>, "VoidProcess has Processable concept");
} // namespace
