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

private:
    u32 handle = 0;
};

}
