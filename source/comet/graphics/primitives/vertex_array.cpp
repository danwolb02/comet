#define COMET_IMPLEMENTATION

#include <comet/base.hpp>
#include <comet/external.hpp>
#include <comet/graphics/primitives/vertex_array.hpp>

namespace comet
{
VertexArray::VertexArray(IndexBuffer &&index_buffer)
: index_buffer(move(index_buffer))
{
    GL_CALL(glGenVertexArrays(1, &handle));
}

VertexArray::VertexArray(VertexArray &&other)
: handle(other.handle)
, vertex_buffers(std::move(other.vertex_buffers))
, index_buffer(move(other.index_buffer))
{
    other.handle = 0;
}

VertexArray::~VertexArray()
{
    release();
}

auto VertexArray::operator=(VertexArray &&other) -> VertexArray &
{
    if (this != &other)
    {
        release();
        handle = other.handle;
        vertex_buffers = move(other.vertex_buffers);
        index_buffer = move(other.index_buffer);
    }

    return *this;
}

auto VertexArray::release() -> void
{
    glDeleteVertexArrays(1, &handle);
}

auto VertexArray::bind() const -> void
{
    glBindVertexArray(handle);
}

auto VertexArray::upload(VertexBuffer &&vertex_buffer, u32 index, u32 size, u32 stride) -> void
{
    bind();
    vertex_buffer.bind();

    GL_CALL(glEnableVertexAttribArray(index));
    GL_CALL(glVertexAttribPointer(index, size, GL_FLOAT, false, stride, nullptr));

    vertex_buffers.insert(std::make_pair(index, move(vertex_buffer)));
}

auto VertexArray::get_vertex_count() const -> u32
{
    return index_buffer.get_vertex_count();
}

auto VertexArray::draw() const -> void
{
    bind();
    index_buffer.bind();

    for (auto &&entry : vertex_buffers)
    {
        GL_CALL(glEnableVertexAttribArray(entry.first));
    }

    GL_CALL(glDrawElements(GL_TRIANGLES, get_vertex_count(), GL_UNSIGNED_INT, nullptr));
}

auto operator<<(OutputStream &output_stream, const VertexArray &vertex_array) -> OutputStream &
{
    output_stream << "{ handle: " << vertex_array.handle
                  << ", vertex_buffers: " << vertex_array.vertex_buffers
                  << ", index_buffer: " << vertex_array.index_buffer
                  << " }";
    return output_stream;
}

}
