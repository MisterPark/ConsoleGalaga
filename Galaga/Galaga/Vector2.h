#pragma once

struct Vector2
{
  float x;
  float y;
  static Vector2 Left;
  static Vector2 Right;
  static Vector2 Up;
  static Vector2 Down;
  static Vector2 Zero;
  Vector2()
  {
    x = y = 0.f;
  }
  Vector2(float x, float y)
  {
    this->x = x;
    this->y = y;
  }
  Vector2(const Vector2& rhs)
  {
    this->x = rhs.x;
    this->y = rhs.y;
  }

  Vector2 operator+(const Vector2& rhs)
  {
    Vector2 result;
    result.x = this->x + rhs.x;
    result.y = this->y + rhs.y;
    return result;
  }

  Vector2 operator-(const Vector2& rhs)
  {
    Vector2 result;
    result.x = this->x - rhs.x;
    result.y = this->y - rhs.y;
    return result;
  }

  Vector2 operator*(float rhs)
  {
    Vector2 result;
    result.x = this->x * rhs;
    result.y = this->y * rhs;
    return result;
  }

  Vector2 operator/(float rhs)
  {
    Vector2 result;
    result.x = this->x / rhs;
    result.y = this->y / rhs;
    return result;
  }

  Vector2& operator+=(const Vector2& rhs)
  {
    this->x += rhs.x;
    this->y += rhs.y;
    return *this;
  }

  Vector2& operator-=(const Vector2& rhs)
  {
    this->x -= rhs.x;
    this->y -= rhs.y;
    return *this;
  }

  Vector2& operator*=(float rhs)
  {
    this->x *= rhs;
    this->y *= rhs;
    return *this;
  }

  Vector2& operator/=(float rhs)
  {
    this->x /= rhs;
    this->y /= rhs;
    return *this;
  }

  bool operator==(const Vector2& other)
  {
    return (this->x == other.x && this->y == other.y);
  }
  bool operator!=(const Vector2& other)
  {
    return (this->x != other.x || this->y != other.y);
  }
  Vector2& operator=(const Vector2& rhs)
  {
    this->x = rhs.x;
    this->y = rhs.y;
  }

  float Length() const
  {
    return sqrtf(x * x + y * y);
  }


  Vector2 Normalized() const
  {
    Vector2 norm = *this;
    float len = this->Length();
    norm /= len;

    return norm;
  }

};