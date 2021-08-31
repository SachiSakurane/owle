#include <owle/concepts/base_bus.hpp>

#include "mock_buses.hpp"

struct MissGetNumChannelsBaseBus {
  void channel() const;
  std::size_t size() const;
};

struct MissGetNumSamplesBaseBus {
  std::size_t channel() const;
  void size() const;
};

namespace {
static_assert(owle::base_bus<BasicBaseBus>, "BasicBaseBus has BaseBus concept");
static_assert(!owle::base_bus<MissGetNumChannelsBaseBus>, "getNumChannels hasn't BaseBus concept");
static_assert(!owle::base_bus<MissGetNumSamplesBaseBus>, "getNumSamples hasn't BaseBus concept");
} // namespace
