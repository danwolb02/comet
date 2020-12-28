#pragma once

#include <comet/graphics/primitives/index_buffer.hpp>
#include <comet/graphics/primitives/vertex_buffer.hpp>
#include <comet/types.hpp>

namespace comet
{
class VertexArray
{
  public:
	explicit VertexArray(IndexBuffer &&index_buffer);

	VertexArray(const VertexArray &other) = delete;

	VertexArray(VertexArray &&other);

	~VertexArray();

	auto operator=(const VertexArray &other) -> VertexArray & = delete;

	auto operator=(VertexArray &&other) -> VertexArray &;

	auto release() -> void;

	auto bind() const -> void;

	auto upload(VertexBuffer &&vertex_buffer, u32 index, u32 size, u32 stride)
	-> void;

	auto get_vertex_count() const -> u32;

	auto draw() const -> void;

	friend auto operator<<(OutputStream &output_stream,
						   const VertexArray &vertex_array) -> OutputStream &;

  private:
	u32 handle = 0;
	Map<u32, VertexBuffer> vertex_buffers;
	IndexBuffer index_buffer;
};

} // namespace comet
