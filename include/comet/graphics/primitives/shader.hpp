#pragma once

#include <comet/mathematics/matrix.hpp>
#include <comet/types.hpp>

namespace comet
{
class Shader
{
public:
  Shader(const String& vertex_source, const String& fragment_source);

  Shader(const Shader& other) = delete;

  Shader(Shader&& other);

  ~Shader();

  Shader& operator=(const Shader& other) = delete;

  Shader& operator=(Shader&& other);

  void release();

  void use() const;

  void upload(const Matrix4f& matrix, const String& unifrom_name) const;

private:
  u32 compile_shader(const u32 type, const String& source) const;

  u32 handle;
};
} // namespace comet
