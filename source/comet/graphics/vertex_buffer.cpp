#define COMET_IMPLEMENTATION

#include <comet/external.hpp>
#include <comet/graphics/vertex_buffer.hpp>

namespace comet
{
VertexBuffer::VertexBuffer(const Vec<f32> &data)
{
    GL_CALL(glGenBuffers(1, &handle));
    if (!handle) throw RuntimeError("Unable to create vertex buffer.");

    bind();
    GL_CALL(glBufferData(GL_ARRAY_BUFFER, data.size() * sizeof(f32), &data[0], GL_STATIC_DRAW));
}

VertexBuffer::VertexBuffer(VertexBuffer &&other)
: handle(other.handle)
{
    other.handle = 0;
}

VertexBuffer::~VertexBuffer()
{
    release();
}

auto VertexBuffer::operator=(VertexBuffer &&other) -> VertexBuffer &
{
    if (this != &other)
    {
        release();
        handle = other.handle;
        other.handle = 0;
    }

    return *this;
}

auto VertexBuffer::release() -> void
{
    if (handle) glDeleteBuffers(1, &handle);
    handle = 0;
}

auto VertexBuffer::bind() const -> void
{
    GL_CALL(glBindBuffer(GL_ARRAY_BUFFER, handle));
}

auto operator<<(OutputStream &output_stream, const VertexBuffer &vertex_buffer) -> OutputStream &
{
    output_stream << "{ handle: " << vertex_buffer.handle
                  << " }";
    return output_stream;
}

}
