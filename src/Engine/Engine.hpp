#pragma once

#include "App/AppLayer.hpp"
#include "Utils/Utils.hpp"
#include <memory>

namespace ENG
{
  class Engine
  {
    public:
      Engine(const EngineConfig& config, std::unique_ptr<GameLayer> refLayer);
      int OnRun(void);

    private:
      void OnInit(void);
      void OnEventFrame(float dt);
      void OnUpdateFrame(float dt);
      void OnFrameRender(float dt);
  
    private:
      EngineConfig eConfig;
      std::unique_ptr<GameLayer> app;
  };
}
