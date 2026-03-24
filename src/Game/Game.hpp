#pragma once

#include "App/AppLayer.hpp"
#include "Shader.hpp"
#include "Utils/Color.hpp"
#include <vector>

namespace GAME
{
  class Game : public ENG::GameLayer
  {
    public:
      explicit Game();
      ~Game()override{};
      void OnInit(void) override;
      void OnInputs(float dt) override;
      void OnUpdate(float dt) override;
      void OnRender(float dt) override;
    //private:
      //CE::Escena* escena_actual;
      //std::shared_ptr<Entidad> jugador;
    protected:
      std::vector<float> vertices;
      ENG::Color bgColor;
      int label;
      std::vector<OGL::Shader> shaders;
  };
}
