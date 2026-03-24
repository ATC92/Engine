#include "Utils/Vector2.hpp"
#include <Components/Component.hpp>
#include <string>

namespace ENG
{
  eName::eName(const std::string& name)
    : eComponent{}, name{name}
  {}

  eTransform::eTransform()
    : eComponent{},
      position{Vector2D{0.f,0.f}},
      prevPosition{Vector2D{0.f,0.f}},
      velocity{Vector2D{0.f,0.f}},
      angle{0}
  {}

  eTransform::eTransform(const Vector2D& pos, const Vector2D& vel, float ang)
    : eComponent{}, position{pos}, velocity{vel}, angle{ang}
  {}
}
