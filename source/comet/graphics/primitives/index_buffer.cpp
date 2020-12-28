#define COMET_IMPLEMENTATION

#include <comet/external.hpp>
#include <comet/graphics/primitives/index_buffer.hpp>

namespace comet
{
IndexBuffer::IndexBuffer(const Vec<u32> &indices)
: vertex_count(indices.size())
{
	GL_CALL(glGenBuffers(1, &handle));
	if (!handle) throw RuntimeError("Unable to create vertex buffer.");

	bind();
	GL_CALL(glBufferData(GL_ELEMENT_ARRAY_BUFFER, indices.size() * sizeof(u32),
						 indices.data(), GL_STATIC_DRAW));
}

IndexBuffer::IndexBuffer(IndexBuffer &&other)
: handle(other.handle)
, vertex_count(other.vertex_count)
{
	other.handle = 0;
}

IndexBuffer::~IndexBuffer()
{
	release();
}

auto IndexBuffer::operator=(IndexBuffer &&other) -> IndexBuffer &
{
	if (this != &other) {
		release();
		handle = other.handle;
		vertex_count = other.vertex_count;
		other.handle = 0;
		other.vertex_count = 0;
	}

	return *this;
}

auto IndexBuffer::release() -> void
{
	if (handle) glDeleteBuffers(1, &handle);
}

auto IndexBuffer::bind() const -> void
{
	GL_CALL(glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, handle));
}

auto IndexBuffer::get_vertex_count() const -> u32
{
	return vertex_count;
}

auto operator<<(OutputStream &output_stream, const IndexBuffer &index_buffer)
-> OutputStream &
{
	output_stream << "{ handle: " << index_buffer.handle
				  << ", vertex_count: " << index_buffer.vertex_count << " }";
	return output_stream;
}

} // namespace comet
