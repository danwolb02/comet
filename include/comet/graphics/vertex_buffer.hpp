#pragma once

#include <comet/types.hpp>

namespace comet
{
class VertexBuffer
{
public:
    explicit VertexBuffer(const Vec<f32> &data);

    VertexBuffer(const VertexBuffer &other) = delete;

    VertexBuffer(VertexBuffer &&other);

    ~VertexBuffer();

    auto operator=(const VertexBuffer &other) -> VertexBuffer & = delete;

    auto operator=(VertexBuffer &&other) -> VertexBuffer &;

    auto release() -> void;

    auto bind() const -> void;

    friend auto operator<<(OutputStream &output_stream, const VertexBuffer &vertex_buffer) -> OutputStream &;

private:
    u32 handle = 0;
};

}
