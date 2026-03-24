#pragma once

#include "Utils/Vector2.hpp"
#include <cstdint>
#include <string>

namespace ENG
{
  class eComponent
  {
    public:
      virtual ~eComponent() = default;
  };

  class eName : eComponent
  {
    public:
      explicit eName(const std::string& name);
      ~eName () override{};
    public:
      std::string name;
  };

  class eTransform : eComponent
  {
    public:
      eTransform();
      eTransform(const Vector2D& pos, const Vector2D& vel, float ang);
      ~eTransform() override{}
    public:
      Vector2D position;
      Vector2D prevPosition;
      Vector2D velocity;
      float angle;
  };

  class eStats : eComponent
  {
    public:
      ~eStats() override{}
      // 8 bits == 255 decimal.
      std::uint8_t health;
      std::uint8_t max_health;
      std::uint8_t stamina;
      std::uint8_t max_stamina;
      std::uint8_t defense;
      std::uint8_t max_defense;
      std::uint8_t strength;
      std::uint8_t max_strength;
      std::uint8_t agility;
      std::uint8_t max_agility;
  };
}
