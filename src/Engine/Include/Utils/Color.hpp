#pragma once

namespace ENG
{
  class Color
  {
    public:
      constexpr Color()
        : r(1.0f), g(1.0f), b(1.0f), a(1.0f) {};

      constexpr Color(float r, float g, float b, float a = 1.0f)
        : r(r), g(g), b(b), a(a) {};

      void From255(int r, int g, int b);
      void From255(int r, int g, int b, int a);
      

    public:
      float r;
      float g;
      float b;
      float a;
    public:
      static const Color Red;
      static const Color Green;
      static const Color Blue;
      static const Color White;
      static const Color Black;
      static const Color Gray;
  };

  /// Define Color
  inline constexpr Color Color::Red   {1.0f, 0.0f, 0.0f, 1.0f};
  inline constexpr Color Color::Green {0.0f, 1.0f, 0.0f, 1.0f};
  inline constexpr Color Color::Blue  {0.0f, 0.0f, 1.0f, 1.0f};
  inline constexpr Color Color::White {1.0f, 1.0f, 1.0f, 1.0f};
  inline constexpr Color Color::Black {0.0f, 0.0f, 0.0f, 1.0f};
  inline constexpr Color Color::Gray  {0.4f, 0.4f, 0.4f, 1.0f};
}
