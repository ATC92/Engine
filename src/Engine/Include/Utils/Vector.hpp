#pragma once

namespace ENG
{
  class  Vector
  {
    public:
      Vector();
      virtual ~Vector(){};

      virtual void SetVector(float x, float y) = 0;
  };
}
