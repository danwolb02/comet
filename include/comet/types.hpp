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

using String = std::string;

template <typename Type>
using Vec = std::vector<Type>;

template <typename Type>
using Rc = std::shared_ptr<Type>;

using RuntimeError = std::runtime_error;

template <typename Type1, typename Type2>
using Map = std::map<Type1, Type2>;

using OutputStream = std::ostream;

template <typename Type1, typename Type2>
auto operator<<(OutputStream &output_stream, const Map<Type1, Type2> &map)
-> OutputStream &
{
	output_stream << "{ ";

	for (auto it = map.begin(); it != map.end(); it++) {
		output_stream << "{ index: " << it->first
					  << ", vertex_array: " << it->second << " } ";
	}

	output_stream << "}";
	return output_stream;
}

} // namespace comet
