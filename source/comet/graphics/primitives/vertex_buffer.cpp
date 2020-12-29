#define COMET_IMPLEMENTATION

#include <comet/external.hpp>
#include <comet/graphics/primitives/vertex_buffer.hpp>

namespace comet
{
VertexBuffer::VertexBuffer(const Vec<f32>& data)
{
  GL_CALL(glGenBuffers(1, &handle));
  if(!handle) throw RuntimeError("Unable to create vertex buffer.");

  bind();
  GL_CALL(glBufferData(GL_ARRAY_BUFFER, data.size() * sizeof(f32), &data[0],
                       GL_STATIC_DRAW));
}

VertexBuffer::VertexBuffer(VertexBuffer&& other)
: handle(other.handle)
{
  other.handle = 0;
}

VertexBuffer::~VertexBuffer()
{
  release();
}

VertexBuffer& VertexBuffer::operator=(VertexBuffer&& other)
{
  if(this != &other)
  {
    release();
    handle = other.handle;
    other.handle = 0;
  }

  return *this;
}

void VertexBuffer::release()
{
  if(handle) glDeleteBuffers(1, &handle);
  handle = 0;
}

void VertexBuffer::bind() const
{
  GL_CALL(glBindBuffer(GL_ARRAY_BUFFER, handle));
}

OutputStream& operator<<(OutputStream& output_stream,
                         const VertexBuffer& vertex_buffer)
{
  output_stream << "{ handle: " << vertex_buffer.handle << " }";
  return output_stream;
}
} // namespace comet
