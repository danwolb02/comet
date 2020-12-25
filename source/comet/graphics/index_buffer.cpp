#define COMET_IMPLEMENTATION

#include <comet/external.hpp>
#include <comet/graphics/index_buffer.hpp>

namespace comet
{
IndexBuffer::IndexBuffer(const Vec<u32> &indices)
{
    GL_CALL(glGenBuffers(1, &handle));
    if (!handle) throw RuntimeError("Unable to create vertex buffer.");

    bind();
    GL_CALL(glBufferData(GL_ELEMENT_ARRAY_BUFFER, indices.size() * sizeof(u32), indices.data(), GL_STATIC_DRAW));
}

IndexBuffer::IndexBuffer(IndexBuffer &&other)
: handle(other.handle)
{
    other.handle = 0;
}

IndexBuffer::~IndexBuffer()
{
    release();
}

auto IndexBuffer::operator=(IndexBuffer &&other) -> IndexBuffer &
{
    if (this != &other)
    {
        release();
        handle = other.handle;
        other.handle = 0;
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

}
