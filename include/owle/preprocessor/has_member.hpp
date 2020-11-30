//
// Created by SachiSakurane on 2020/11/30.
//

// TODO: いつか殺す

#pragma once

#include <owle/utility/utility.hpp>

#define OWLE_UNPACK(x) x

#define OWLE_HAS_CLASS_MEMBER(name, template_types, types, statements)      \
template <OWLE_UNPACK template_types, class = void>                         \
struct name##_impl : std::false_type {};                                    \
template <OWLE_UNPACK template_types>                                       \
struct name##_impl<types, std::enable_if_t<statements>> : std::true_type {};\
template <OWLE_UNPACK template_types> struct name : name##_impl<types> {};  \
template <OWLE_UNPACK template_types>                                       \
inline constexpr bool name##_v = name<types>::value;

#define OWLE_HAS_SINGLE_TYPE_CLASS_MEMBER(name, statements) OWLE_HAS_CLASS_MEMBER(name, (class Type), Type, (statements))

#define OWLE_HAS_CLASS_VOID_MEMBER(name, member) OWLE_HAS_SINGLE_TYPE_CLASS_MEMBER(name, owle::sfinae_true<decltype(std::declval<Type>().member())>::value)
