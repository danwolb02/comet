#pragma once

#include <comet/types.hpp>

namespace comet
{
class Window
{
public:
  Window(const u32 width, const u32 height, const String& title);

  ~Window();

  void update() const;

  bool should_close() const;

  u32 get_width() const;

  u32 get_height() const;

private:
  void* handle = nullptr;
};
} // namespace comet
