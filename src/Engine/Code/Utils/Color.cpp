#include <GL/gl.h>
#include <Utils/Color.hpp>

namespace ENG 
{ 
  void Color::From255(int r, int g, int b)
  {
    this->r = r / 255.0f;
    this->g = g / 255.0f;
    this->b = b / 255.0f;
    this->a = 255;
  }
  void Color::From255(int r, int g, int b, int a)
  {
    this->r = r / 255.0f;
    this->g = g / 255.0f;
    this->b = b / 255.0f;
    this->a = a / 255.0f;
  }
} // namespace ENG
