#include <owle/concepts/processable.hpp>

#include "mock_buses.hpp"

struct MissProcess {
  void proceed();
};

namespace {
static_assert(owle::processable<Process<bool>>, "Process<bool> has Processable concept");
static_assert(owle::processable<Process<void>>, "Process<void> has Processable concept");
static_assert(!owle::processable<MissProcess>, "VoidProcess has Processable concept");
} // namespace
