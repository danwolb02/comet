#pragma once

#include <comet/types.hpp>

namespace comet
{
class IndexBuffer
{
public:
    explicit IndexBuffer(const Vec<u32> &indices);

    IndexBuffer(const IndexBuffer &other) = delete;

    IndexBuffer(IndexBuffer &&other);

    ~IndexBuffer();

    auto operator=(const IndexBuffer &other) -> IndexBuffer & = delete;

    auto operator=(IndexBuffer &&other) -> IndexBuffer &;

    auto release() -> void;

    auto bind() const -> void;

    auto get_vertex_count() const -> u32;

    friend auto operator<<(OutputStream &output_stream, const IndexBuffer &index_buffer) -> OutputStream &;

private:
    u32 handle = 0;
    u32 vertex_count;
};

}
