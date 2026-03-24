#pragma once

#include "Components/Component.hpp"
#include <memory>
#include <vector>
namespace ENG
{
  class Object
  {
    public: 
      explicit Object();
      virtual ~Object() = default;

      /// Components main fuctions
      Object& AddComponent(const std::shared_ptr<eComponent>& c);

      template <typename T> Object& CopyComponent(const T *c)
      {
        auto copia = std::make_shared<T>(*c);
        vComponents.push_back(copia);
        return *this;
      }
      
      template <typename T> T* GetComponent()const
      {
        static_assert(std::is_base_of<eComponent, T>::value,"Only sons of eComponent");
        for(auto& c: vComponents)
        {
          T* comp = dynamic_cast<T*>(c.get());
          if(comp)
            return comp;

        }
        return nullptr;
      };
      
      template <typename T> bool HasComponent() const
      {
        static_assert(std::is_base_of<eComponent, T>::value,"Only sons of eComponent");
        for(auto& c: vComponents)
        {
          T* comp = dynamic_cast<T*>(c.get());
          if(comp)
            return true;
        }
          return false;
      };
      
      /// Amount of objects inside of the list (This Object)
      static int GetAmountObj()
      {
        return Amount_Objects;
      }

      /// Getters for eComponents
      std::shared_ptr<eName> GetName()
      {
        return oName;
      }
      std::shared_ptr<eTransform>& GetTransform()
      {
        return oTransform;
      }
      std::shared_ptr<eStats>& GetStats()
      {
        return oStats;
      }
      
      // Raw list of the components
      std::vector<std::shared_ptr<eComponent>>& GetListComponents()
      {
        return vComponents;
      }
      
      void SetPosition(float x, float y);
      virtual void OnUpdate(float dt)=0;

      // ToString fuction
      virtual std::string ToString()
      {
        return oName->name;
      }

    private:
      static int Amount_Objects;
    protected:
      std::shared_ptr<eName> oName;
      std::shared_ptr<eTransform> oTransform;
      std::shared_ptr<eStats> oStats;
      std::vector<std::shared_ptr<eComponent>> vComponents;
  };
}
