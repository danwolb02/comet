#pragma once

#include <comet/pch.hpp>

namespace comet
{
using i8 = signed char;
using i16 = signed short int;
using i32 = signed int;
using i64 = signed long int;

using u8 = unsigned char;
using u16 = unsigned short int;
using u32 = unsigned int;
using u64 = unsigned long int;

using f32 = float;
using f64 = double;

using String = std::u32string;

template<typename Type>
using Vec = std::vector<Type>;

template<typename Type>
using Rc = std::shared_ptr<Type>;
} // namespace comet
