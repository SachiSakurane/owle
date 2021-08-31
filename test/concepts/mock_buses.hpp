//
// Created by SachiSakurane on 2020/11/30.
//

#pragma once

struct BasicBaseBus {
    std::size_t channel() const;
    std::size_t size() const;
};

template <class Type>
struct MutableReadableBus : BasicBaseBus {
    using value_type = Type;
    value_type* data(std::size_t);
};

template <class Type>
struct ImmutableReadableBus : BasicBaseBus {
    using value_type = Type;
    const value_type* data(std::size_t) const;
};

template <class Type>
struct MutableWritableBus : BasicBaseBus {
    using value_type = Type;
    value_type* data(std::size_t);
};

template <class Type>
struct ImmutableWritableBus : BasicBaseBus {
    using value_type = Type;
    const value_type* data(std::size_t) const;
};

template <class Type>
struct BidirectionalBus : BasicBaseBus {
    using value_type = Type;
    const value_type* data(std::size_t) const;
    value_type* data(std::size_t);
};

template <class From, class To>
struct Connection {
    To operator()(From v);
};

template <class Type>
struct Process {
    Type operator()();
};
