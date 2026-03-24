#include <Game/Game.hpp>
#include "App/AppLayer.hpp"
#include "GLFW/glfw3.h"
#include "Inputs/PollEvent.hpp"
#include "Render/Render.hpp"
#include "Shader.hpp"
#include "System/TraceLog.hpp"
#include "Utils/Color.hpp"
#include "Vertex.hpp"

namespace GAME
{
  Game::Game() 
    : ENG::GameLayer{}
  {
    gl_Done = false;
    
  }
 
  void Game::OnInit()
  {
    bgColor = ENG::Color(0.2f, 0.3f, 0.3f);
    label = 0;
    ENG::TraceLog::MsgTraceLog(ENG::LogContext::LOG_INFO, "    OnInit GameLayer");

    vertices = {
      -0.5f, -0.5f, 0.0f,   // Left
      0.5f, -0.5f, 0.0f,    // Right
      0.0f,0.5f, 0.0f       // Top
    };
    ENG::Render::Get().InitGLBuffer(vertices);

    OGL::Shader shader;
    shader.CreateShader("src/Engine/OpenGL/Shaders/try.vs", "src/Engine/OpenGL/Shaders/try.fs");
    shaders.push_back(shader);
  }

  void Game::OnInputs(float dt)
  {
    (void)dt;
    auto pollEvent = ENG::PollEvent::Get();
    if(pollEvent.IsKeyPress(GLFW_KEY_ESCAPE) == true)
    {
      gl_Done = true;
    }
    if(pollEvent.IsKeyPress(GLFW_KEY_R) == true)
    {
      bgColor.From255(23, 227, 235);
    }
    else if(pollEvent.IsKeyPress(GLFW_KEY_T) == true)
    {
      bgColor.From255(250, 92, 237);
    }
    else if (pollEvent.IsKeyPress(GLFW_KEY_E) == true)
    {
      bgColor = ENG::Color::Gray;
    }

    if(pollEvent.IsKeyDown(GLFW_KEY_Q) == true)
    {
      bgColor.From255(255,255,label,255);
      label+= 1;
    }
    if(pollEvent.IsKeyRelease(GLFW_KEY_Q) == true)
    {
      label = 0;
      bgColor.From255(255,255,label,255);
    }
  }

  void Game::OnUpdate(float dt)
  {
    (void)dt;
  }

  void Game::OnRender(float dt)
  {
    (void)dt;
    ENG::Render::ClearBackground(bgColor);
   
    ENG::Render::Get().DrawShader(shaders);
  }
}
