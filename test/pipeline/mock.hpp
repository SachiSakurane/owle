//
// Created by SachiSakurane on 2020/11/30.
//

#pragma once

template <class From, class To>
struct Connection {
    To process(From v) {
        return static_cast<To>(v);
    }
};

template <class Type, Type Value>
struct Process {
    Type process() { return Value; }
};
