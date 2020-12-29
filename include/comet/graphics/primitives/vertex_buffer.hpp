#pragma once

#include <comet/types.hpp>

namespace comet
{
class VertexBuffer
{
public:
  explicit VertexBuffer(const Vec<f32>& data);

  VertexBuffer(const VertexBuffer& other) = delete;

  VertexBuffer(VertexBuffer&& other);

  ~VertexBuffer();

  VertexBuffer& operator=(const VertexBuffer& other) = delete;

  VertexBuffer& operator=(VertexBuffer&& other);

  void release();

  void bind() const;

  friend OutputStream& operator<<(OutputStream& output_stream,
                                  const VertexBuffer& vertex_buffer);

private:
  u32 handle = 0;
};
} // namespace comet
