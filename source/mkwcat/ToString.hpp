//
//  mkwcat/ToString.hpp
//  nsmbw-project
//

#pragma once

#include "Concepts.hpp"
#include <magic_enum/magic_enum.hpp>
#include <string_view>

namespace mkwcat
{

template <Test<std::is_enum> E>
constexpr std::string_view ToString(E e)
{
    return magic_enum::enum_name(e);
}

constexpr std::string_view ToString(bool i)
{
    return i ? "true" : "false";
}

} // namespace mkwcat