#pragma once

#include <comet/types.hpp>

namespace comet
{
class Shader
{
public:
    Shader(const String &vertex_source, const String &fragment_source);

    Shader(const Shader &other) = delete;

    Shader(Shader &&other);

    ~Shader();

    auto operator=(const Shader &other) -> Shader & = delete;

    auto operator=(Shader &&other) -> Shader &;

    auto release() -> void;

    auto use() const -> void;

private:
    auto compile_shader(const u32 type, const String &source) const -> u32;

    u32 handle;
};

}
