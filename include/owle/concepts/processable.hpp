//
// Created by Himatya on 2020/11/07.
//

#pragma once

#include <owle/utility/utility.hpp>

namespace owle {
    namespace detail {
        template<class ProcessableType, class = void>
        struct has_process_impl : std::false_type {};

        template<class ProcessableType>
        struct has_process_impl<ProcessableType,
                std::enable_if_t<owle::sfinae_true<decltype(std::declval<ProcessableType>().process())>::value>> :
                std::true_type {};

        template <class ProcessableType>
        struct has_process : has_process_impl<ProcessableType> {};

        template <class ProcessableType>
        inline constexpr bool has_process_v = has_process<ProcessableType>::value;
    }

    template <class ProcessableType>
    concept Processable = owle::detail::has_process_v<ProcessableType>;
}
