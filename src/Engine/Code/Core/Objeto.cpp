#include "Components/Component.hpp"
#include <Core/Object.hpp>
#include <memory>
#include <string>

namespace ENG
{
  int Object::Amount_Objects = 0;

  Object::Object()
  {
    oName       = std::make_shared<eName>("Object: " + std::to_string(Object::Amount_Objects+1));
    oTransform  = std::make_shared<eTransform>();
    oStats      = std::make_shared<eStats>();
  }

  void Object::SetPosition(float x, float y)
  {
    oTransform->prevPosition = oTransform->position;
    oTransform->position.SetVector(x,y);
  }

  Object& Object::AddComponent(const std::shared_ptr<eComponent>& c)
  {
    vComponents.push_back(c);
    return *this;
  }
}
