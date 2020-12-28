#pragma once

#include <comet/types.hpp>

namespace comet
{
class Window
{
  public:
	Window(const u32 width, const u32 height, const String &title);

	~Window();

	auto update() const -> void;

	auto should_close() const -> bool;

	auto get_width() const -> u32;

	auto get_height() const -> u32;

  private:
	void *handle = nullptr;
};

} // namespace comet
