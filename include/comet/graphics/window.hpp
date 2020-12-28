#pragma once

#include <comet/types.hpp>

namespace comet
{
class Window
{
  public:
	Window(const u32 width, const u32 height, const String &title);

	~Window();

	auto update() -> void;

	auto should_close() -> bool;

  private:
	void *handle = nullptr;
};

} // namespace comet
