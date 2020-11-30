//
// Created by SachiSakurane on 2020/11/30.
//

#pragma once

struct BasicBaseBus {
    size_t getNumChannels() const;
    size_t getNumSamples() const;
};

template <class Type>
struct MutableReadableBus : BasicBaseBus {
    using SampleType = Type;
    SampleType* getReadPointer(int);
};

template <class Type>
struct ImmutableReadableBus : BasicBaseBus {
    using SampleType = Type;
    const SampleType* getReadPointer(int) const;
};

template <class Type>
struct MutableWritableBus : BasicBaseBus {
    using SampleType = Type;
    SampleType* getWritePointer(int);
};

template <class Type>
struct ImmutableWritableBus : BasicBaseBus {
    using SampleType = Type;
    const SampleType* getWritePointer(int) const;
};

template <class Type>
struct BidirectionalBus : BasicBaseBus {
    using SampleType = Type;
    const SampleType* getReadPointer(int) const;
    SampleType* getWritePointer(int);
};

template <class From, class To>
struct Connection {
    To process(From v);
};

template <class Type>
struct Process {
    Type process();
};
