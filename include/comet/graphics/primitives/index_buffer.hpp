#pragma once

#include <comet/types.hpp>

namespace comet
{
class IndexBuffer
{
public:
  explicit IndexBuffer(const Vec<u32>& indices);

  IndexBuffer(const IndexBuffer& other) = delete;

  IndexBuffer(IndexBuffer&& other);

  ~IndexBuffer();

  IndexBuffer& operator=(const IndexBuffer& other) = delete;

  IndexBuffer& operator=(IndexBuffer&& other);

  void release();

  void bind() const;

  u32 get_vertex_count() const;

  friend OutputStream& operator<<(OutputStream& output_stream,
                                  const IndexBuffer& index_buffer);

private:
  u32 handle = 0;
  u32 vertex_count;
};
} // namespace comet
