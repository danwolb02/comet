#define COMET_IMPLEMENTATION

#include <cmath>
#include <comet/mathematics/matrix.hpp>

namespace comet
{
Matrix4f::Matrix4f(const f32 diagonal)
{
  data[0][0] = diagonal;
  data[1][1] = diagonal;
  data[2][2] = diagonal;
  data[3][3] = diagonal;
}

Matrix4f Matrix4f::multiply(const Matrix4f& other) const
{
  Matrix4f ret;

  for(u32 i = 0; i < 4; i++)
  {
    for(u32 j = 0; j < 4; j++)
    {
      for(u32 k = 0; k < 4; k++)
      {
        ret.data[i][j] += data[k][j] * other.data[i][k];
      }
    }
  }

  return ret;
}

Matrix4f Matrix4f::translate(const f32 x, const f32 y, const f32 z) const
{
  Matrix4f ret(1.0f);

  ret.data[3][0] = x;
  ret.data[3][1] = y;
  ret.data[3][2] = z;

  return multiply(ret);
}

Matrix4f Matrix4f::rotate(const f32 x, const f32 y, const f32 z) const
{
  Matrix4f ret(1.0f);

  ret.data[0][0] = cos(-z) * cos(-y);
  ret.data[0][1] = cos(-z) * sin(-y) * sin(-x) - sin(-z) * cos(-x);
  ret.data[0][2] = cos(-z) * sin(-y) * cos(-x) + sin(-z) * sin(-x);
  ret.data[1][0] = sin(-z) * cos(-y);
  ret.data[1][1] = sin(-z) * sin(-y) * sin(-x) + cos(-z) * cos(-x);
  ret.data[1][2] = sin(-z) * sin(-y) * cos(-x) - cos(-z) * sin(-x);
  ret.data[2][0] = -sin(-y);
  ret.data[2][1] = cos(-y) * sin(-x);
  ret.data[2][2] = cos(-y) * cos(-x);

  return multiply(ret);
}

Matrix4f Matrix4f::scale(const f32 x, const f32 y, const f32 z) const
{
  Matrix4f ret(1.0f);

  ret.data[0][0] = x;
  ret.data[1][1] = y;
  ret.data[2][2] = z;

  return multiply(ret);
}

const f32* Matrix4f::get_data() const
{
  return data[0];
}

Matrix4f Matrix4f::operator*(const Matrix4f& other) const
{
  return multiply(other);
}

Matrix4f perspective(const f32 aspect, const f32 angle, const f32 near,
                     const f32 far)
{
  Matrix4f ret(0.0f);

  ret.data[0][0] = 1.0f / (aspect * tan(angle / 2.0f));
  ret.data[1][1] = 1.0f / (tan(angle / 2.0f));
  ret.data[2][2] = -1.0f * ((near + far) / (far - near));
  ret.data[2][3] = -1.0f;
  ret.data[3][2] = (2.0f * far * near) / (near - far);

  return ret;
}

Matrix4f orthographic(const f32 left, const f32 right, const f32 bottom,
                      const f32 top, const f32 near, const f32 far)
{
  Matrix4f ret(1.0f);

  ret.data[0][0] = 2.0f / (right - left);
  ret.data[1][1] = 2.0f / (top - bottom);
  ret.data[2][2] = -2.0f / (far - near);
  ret.data[3][0] = -(right + left) / (right - left);
  ret.data[3][1] = -(top + bottom) / (top - bottom);
  ret.data[3][2] = -(far + near) / (far - near);

  return ret;
}
} // namespace comet
