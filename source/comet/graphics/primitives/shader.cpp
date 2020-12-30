#define COMET_IMPLEMENTATION

#include <comet/external.hpp>
#include <comet/graphics/primitives/shader.hpp>

namespace comet
{
Shader::Shader(const String& vertex_source, const String& fragment_source)
: handle(glCreateProgram())
{
  auto vertex_shader_handle = compile_shader(GL_VERTEX_SHADER, vertex_source);
  auto fragment_shader_handle =
    compile_shader(GL_FRAGMENT_SHADER, fragment_source);

  GL_CALL(glAttachShader(handle, vertex_shader_handle));
  GL_CALL(glAttachShader(handle, fragment_shader_handle));
  GL_CALL(glLinkProgram(handle));
  GL_CALL(glValidateProgram(handle));

  GL_CALL(glDetachShader(handle, vertex_shader_handle));
  GL_CALL(glDetachShader(handle, fragment_shader_handle));
}

Shader::Shader(Shader&& other)
: handle(other.handle)
{
  other.handle = 0;
}

Shader::~Shader()
{
  release();
}

Shader& Shader::operator=(Shader&& other)
{
  if(this != &other)
  {
    release();
    handle = other.handle;
    other.handle = 0;
  }

  return *this;
}

void Shader::release()
{
  GL_CALL(glDeleteProgram(handle));
}

void Shader::use() const
{
  GL_CALL(glUseProgram(handle));
}

u32 Shader::compile_shader(const u32 type, const String& source) const
{
  u32 handle = glCreateShader(type);
  auto source_pointer = source.c_str();
  GL_CALL(glShaderSource(handle, 1, &source_pointer, nullptr));
  GL_CALL(glCompileShader(handle));

  i32 is_compiled = 0;
  GL_CALL(glGetShaderiv(handle, GL_COMPILE_STATUS, &is_compiled));

  if(is_compiled == false)
  {
    GLint max_length = 0;
    GL_CALL(glGetShaderiv(handle, GL_INFO_LOG_LENGTH, &max_length));

    char* message = new char[max_length];

    GL_CALL(glGetShaderInfoLog(handle, max_length, &max_length, message));
    GL_CALL(glDeleteShader(handle));

    throw RuntimeError("Unable to compile shader: " + String(message));
  }

  return handle;
}

void Shader::upload(const Matrix4f& matrix, const String& unifrom_name) const
{
  use();
  auto uniform_location = glGetUniformLocation(handle, unifrom_name.c_str());
  GL_CALL(glUniformMatrix4fv(uniform_location, 1, GL_FALSE, matrix.get_data()));
}
}; // namespace comet
