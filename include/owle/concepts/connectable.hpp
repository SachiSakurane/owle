//
// Created by Himatya on 2020/11/09.
//

#pragma once

#include <utility>

namespace owle {
    template <class ConnectableType, class ArgumentType>
    concept ArgsConnectable = requires (ConnectableType &connectable) {
        connectable.process(std::declval<ArgumentType>());
    };

    template <class ConnectionType, class ProcessableType>
    concept ProcessConnectable = requires (ConnectionType& connectable, ProcessableType& processable) {
        connectable.process(processable.process());
    };

    template <class ConnectionType, class Type>
    concept Connectable = ArgsConnectable<ConnectionType, Type> || ProcessConnectable<ConnectionType, Type>;
}
