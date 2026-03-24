//////////////////////////////////////////////////////////////////
#include "Engine.hpp"
#include "Game/Game.hpp"
#include "Utils/Utils.hpp"
#include <GL/gl.h>
#include <GLFW/glfw3.h>
#include <memory>
//////////////////////////////////////////////////////////////////
int main(void)
{
  ENG::EngineConfig config;
  config.vW=1080;
  config.vH=720;
  config.title="Engine";

  ENG::Engine engine{config,std::make_unique<GAME::Game>()};

  return engine.OnRun();
}
//////////////////////////////////////////////////////////////////
