//
// Created by Himatya on 2020/11/09.
//

#pragma once

#include <utility>

#include <owle/concepts/processable.hpp>
#include <owle/utility/utility.hpp>

namespace owle {
    namespace detail {
        template <class ConnectableType, class ArgumentType>
        static auto has_connectable_impl(ArgumentType&& argument) -> owle::sfinae_true<decltype(std::declval<ConnectableType>().process(argument))>;
        template <class>
        static auto has_connectable_impl(...) -> std::false_type;

        template <class ConnectableType, class ArgumentType>
        struct has_args_connectable : decltype(has_connectable_impl(std::declval<ArgumentType>())) {};

        template <class ConnectableType, class ProcessableType> requires owle::Processable<ProcessableType>
        struct has_process_connectable : decltype(has_connectable_impl(std::declval<ProcessableType>().process)) {};

        template <class ConnectableType, class ArgumentType>
        inline constexpr bool has_args_connectable_v = has_args_connectable<ConnectableType, ArgumentType>::value;

        template <class ConnectableType, class ProcessableType> requires owle::Processable<ProcessableType>
        inline constexpr bool has_process_connectable_v = has_process_connectable<ConnectableType, ProcessableType>::value;
    }

    template <class ConnectableType, class ArgumentType>
    concept ArgsConnectable = detail::has_args_connectable_v<ConnectableType, ArgumentType>;

    template <class ConnectableType, class ProcessableType>
    concept ProcessConnectable = detail::has_process_connectable_v<ConnectableType, ProcessableType>;

    template <class ConnectionType, class Type>
    concept Connectable = ArgsConnectable<ConnectionType, Type> || ProcessConnectable<ConnectionType, Type>;
}
