//
// Created by SachiSakurane on 2020/11/07.
//

#pragma once

#include <owle/utility/utility.hpp>

#ifndef __cpp_lib_concepts
#include <owle/preprocessor/has_member.hpp>
#endif

namespace owle {
#ifdef __cpp_lib_concepts
    template <class ProcessableType>
    concept Processable = requires () {
        std::declval<ProcessableType>()();
    };
#else
    namespace detail {
        OWLE_HAS_CLASS_VOID_MEMBER(has_process, operator())
    }

    template <class ProcessableType>
    concept Processable = owle::detail::has_process_v<ProcessableType>;
#endif
}
