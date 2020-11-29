//
// Created by Himatya on 2020/11/07.
//

#pragma once

#include <owle/utility/utility.hpp>

namespace owle {
    namespace detail {
        template <class ProcessableType>
        static auto has_process_impl(ProcessableType&& processable) -> owle::sfinae_true<decltype(processable.process())>;
        template <class>
        static auto has_process_impl(...) -> std::false_type;

        template <class ProcessableType>
        struct has_process : decltype(has_process_impl(std::declval<ProcessableType>())) {};

        template <class ProcessableType>
        inline constexpr bool has_process_v = has_process<ProcessableType>::value;
    }

    template <class ProcessableType>
    concept Processable = owle::detail::has_process_v<ProcessableType>;
}
