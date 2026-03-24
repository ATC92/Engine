#pragma once

namespace ENG
{
  class Vector2D
  {
    public:
      Vector2D();
      Vector2D(const float x,const float y);
      Vector2D(const float v);
      ~Vector2D(){};
      
      void SetVector(float x, float y);
      void SetVector(float v);
      void SetVector(Vector2D& v);
      float Length() const;
      float Magnitude() const;
      float Distance(const Vector2D& o) const;
      Vector2D& Normalize();
      Vector2D& Scalar(float s);
      Vector2D& Add(float s);
      Vector2D& Sub(float s);

      bool operator==(const Vector2D& v)const;
      Vector2D operator+(const Vector2D& _v) const;
      Vector2D operator-(const Vector2D& _v) const;
      Vector2D operator*(const Vector2D& _v) const;

    private:
      float vX;
      float vY;
  };

}
