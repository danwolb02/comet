#pragma once

#include <comet/graphics/primitives/index_buffer.hpp>
#include <comet/graphics/primitives/vertex_buffer.hpp>
#include <comet/types.hpp>

namespace comet
{
class VertexArray
{
public:
  explicit VertexArray(IndexBuffer&& index_buffer);

  VertexArray(const VertexArray& other) = delete;

  VertexArray(VertexArray&& other);

  ~VertexArray();

  VertexArray& operator=(const VertexArray& other) = delete;

  VertexArray& operator=(VertexArray&& other);

  void release();

  void bind() const;

  void upload(VertexBuffer&& vertex_buffer, u32 index, u32 size, u32 stride);

  u32 get_vertex_count() const;

  void draw() const;

  friend OutputStream& operator<<(OutputStream& output_stream,
                                  const VertexArray& vertex_array);

private:
  u32 handle = 0;
  Map<u32, VertexBuffer> vertex_buffers;
  IndexBuffer index_buffer;
};
} // namespace comet
