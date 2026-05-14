#ifndef SIMPLE_VEC_2_H
#define SIMPLE_VEC_2_H
#include <cmath>
#include <ostream>

class Vec2 {
  public:
  float x;
  float y;
  Vec2() : x{0}, y{0} {}
  Vec2(float x, float y) : x{x}, y{y} {}
  inline Vec2 operator+(const Vec2 &v) const {
    return {x + v.x, y + v.y};
  }
  inline Vec2 operator-(const Vec2 &v) const {
    return {x - v.x, y - v.y};
  }
  inline Vec2 operator*(float f) const {
    return {x * f, y * f};
  }
  inline Vec2 operator/(float f) const {
    return {x / f, y / f};
  }
  inline Vec2 & operator+=(const Vec2 &v) {
    x += v.x;
    y += v.y;
    return *this;
  }
  inline Vec2 & operator-=(const Vec2 &v) {
    x -= v.x;
    y -= v.y;
    return *this;
  }
  inline Vec2 & operator*=(float f) {
    x *= f;
    y *= f;
    return *this;
  }
  inline Vec2 & operator/=(float f) {
    x /= f;
    y /= f;
    return *this;
  }
  inline float dot(const Vec2& v) const {
    return x * v.x + y * v.y; 
  }
  inline float length() const {
    return std::sqrt(x * x + y * y);
  }
  inline Vec2 normalized() const {
    float len = length();
    if (len < 1e-6f) return {0.0f, 0.0f};
    return  {x/len, y/len};
  }
  inline Vec2 abs() const {
    return {std::abs(x), std::abs(y)};
  }
};
inline Vec2 operator*(float f, const Vec2& v) {
    return {v.x * f, v.y * f};
}
inline Vec2 operator/(float f, const Vec2& v) {
  return {f / v.x, f / v.y};
}
inline std::ostream& operator<<(std::ostream& os, const Vec2& v) {
  return os << "{ " << v.x << " | " << v.y << " }";
}
#endif
