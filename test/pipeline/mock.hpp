//
// Created by SachiSakurane on 2020/11/30.
//

#pragma once

template <class From, class To, class = std::enable_if_t<owle::convertible_to<From, To>>>
struct Connection {
    To process(From v) {
        return static_cast<To>(v);
    }
};

template <class Type, Type Value>
struct Process {
    Type process() { return Value; }
};
