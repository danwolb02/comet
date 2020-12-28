#pragma once

#include <comet/types.hpp>

namespace comet
{
template <typename Type>
constexpr typename std::remove_reference<Type>::type &&move(Type &object)
{
	return std::move(object);
}

} // namespace comet
