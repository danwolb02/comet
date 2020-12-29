#pragma once

#include <comet/types.hpp>

namespace comet
{
class Matrix4f
{
public:
  Matrix4f() = default;

  explicit Matrix4f(const f32 diagonal);

  ~Matrix4f() = default;

  Matrix4f multiply(const Matrix4f& other) const;

  Matrix4f translate(const f32 x, const f32 y, const f32 z) const;

  Matrix4f rotate(const f32 x, const f32 y, const f32 z) const;

  Matrix4f scale(const f32 x, const f32 y, const f32 z) const;

  const f32* get_data() const;

  Matrix4f operator*(const Matrix4f& other) const;

  friend Matrix4f perspective(const f32 aspect, const f32 angle, const f32 near,
                              const f32 far);

  friend Matrix4f orthographic(const f32 left, const f32 right,
                               const f32 bottom, const f32 top, const f32 near,
                               const f32 far);

private:
  f32 data[4][4] = {{0.0f, 0.0f, 0.0f, 0.0f},
                    {0.0f, 0.0f, 0.0f, 0.0f},
                    {0.0f, 0.0f, 0.0f, 0.0f},
                    {0.0f, 0.0f, 0.0f, 0.0f}};
};

auto perspective(const f32 aspect, const f32 angle, const f32 near,
                 const f32 far) -> Matrix4f;
auto orthographic(const f32 left, const f32 right, const f32 bottom,
                  const f32 top, const f32 near, const f32 far) -> Matrix4f;

} // namespace comet
