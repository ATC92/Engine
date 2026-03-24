#include "Utils/Vector2.hpp"
#include <cmath>

namespace ENG
{
  Vector2D::Vector2D(){}

  Vector2D::Vector2D(float x, float y)
    : vX(x), vY(y) {}

  Vector2D::Vector2D(const float v)
    : vX(v), vY(v) {}
  
  void Vector2D::SetVector(float x, float y)
  {
    this->vX = x;
    this->vY = y;
  }
  
  void Vector2D::SetVector(float v)
  {
    this->vX = v;
    this->vY = v;
  }
  float Vector2D::Length() const
  {
    return sqrt((vX*vX)+(vY*vY));
  }
  float Vector2D::Magnitude() const
  {
    return this->Length();
  }
  float Vector2D::Distance(const Vector2D& o) const
  {
    return sqrt(
      pow(o.vX - vX,2)+
         pow(o.vY - vY,2));
  } 
  Vector2D& Vector2D::Normalize()
  {
    float mag = Length();
    vX/=mag;
    vY/=mag;
    return *this;
  }

  Vector2D& Vector2D::Scalar(float s)
  {
    vX*=s;
    vY*=s;
    return *this;
  }

  Vector2D& Vector2D::Add(float s)
  {
    vX += s;
    vY += s;
    return *this;
  }  

  Vector2D& Vector2D::Sub(float s)
  {
    vX -= s;
    vY -= s;
    return *this;
  }

  /// Load
  bool Vector2D::operator==(const Vector2D& v) const
  {
    return (this->vX == v.vX && this->vY == v.vY);
  }

  Vector2D Vector2D::operator+(const Vector2D& _v) const
  {
    return Vector2D(this->vX + _v.vX, this->vY + _v.vY);
  }
  Vector2D Vector2D::operator-(const Vector2D& _v) const
  {
    return Vector2D(this->vX - _v.vX, this->vY - _v.vY);
  } 
  Vector2D Vector2D::operator*(const Vector2D& _v) const
  {
    return Vector2D(this->vX * _v.vX, this->vY * _v.vY);
  }
}
    
