#include "Engine/Include/System/TraceLog.hpp"
#include "Shader.hpp"
#include "Utils/Utils.hpp"
#include "glad/gl.h"
#include "GLFW/glfw3.h"
#include "Engine/Include/Render/Render.hpp"
#include <cstddef>
#include <memory>
#include <stdexcept>
#include <string>
#include <vector>

namespace ENG
{
  ///////////////////////////////////////////////////////////////////////
  /// Render instance
  Render& Render::Get()
  {
    if (!instance)
      instance = new Render();
    return *instance;
  }

  void Render::DoneRender()
  {
    delete instance;
  }

  void Render::CreateWindow(const EngineConfig& config)
  {
    window = std::make_unique<eWindows>(config.title,config.vW,config.vH);
  }

  eWindows& Render::GetWindow()
  {
    return *window;
  }

  ///////////////////////////////////////////////////////////////////////
  /// eWindow Class
  eWindows::eWindows(const std::string Name, int Width, int Height)
    : wName(Name), wWidth(Width), wHeight(Height)
  {
    TraceLog::MsgTraceLog(LogContext::LOG_INFO, ">> Engine loading resources.");
    InitGLFWContext();
    TraceLog::MsgTraceLog(LogContext::LOG_INFO, "    GLFW Context created.");
    this->window = glfwCreateWindow(Width, Height, Name.c_str(), NULL, NULL);
    TraceLog::MsgTraceLog(LogContext::LOG_INFO, "    Window initialized successfully.");
    if (!window)
    {
      ENG::TraceLog::MsgTraceLog(LogContext::LOG_FATAL, "GLFW Window not created.");
      glfwTerminate();
      throw std::runtime_error(">> Window in GLFW Context not Created.");
    }
    glfwSetInputMode(this->window, GLFW_STICKY_KEYS,GLFW_FALSE);
    glfwMakeContextCurrent(this->window);
    TraceLog::MsgTraceLog(LogContext::LOG_INFO, "    Window added to CurrentContext GLFW.");
    InitGladContext();
    TraceLog::MsgTraceLog(LogContext::LOG_INFO, "    GLAD Context created.");
  }

  void eWindows::InitGLFWContext()
  {
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
  }

  void eWindows::InitGladContext()
  {
    if(!gladLoadGL((GLADloadfunc)glfwGetProcAddress))
    {
      TraceLog::MsgTraceLog(LogContext::LOG_ERROR, "Glad not init correctly.");
      return;
    }
    glViewport(0,0,800,600);
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

  }

  GLFWwindow* eWindows::GetWindow()
  {
    return this->window;
  }

  bool eWindows::IsWindowsClose()
  {
    return glfwWindowShouldClose(this->window);
  }

  void eWindows::CloseWindow()
  {
    glfwTerminate();
  }

  void eWindows::UpdateWindow()
  {
    glfwSwapBuffers(this->window);
  }

  void eWindows::UpdatePollEvents()
  {
    glfwPollEvents();
  }

  ///////////////////////////////////////////////////////////////////////
  /// Render Color Background
  void Render::ClearBackground(const Color& color)
  {
    glClearColor(color.r, color.g, color.b, color.a);
    glClear(GL_COLOR_BUFFER_BIT);
  }

  void Render::ClearBackground(float r, float g, float b)
  {
    glClearColor(r,g,b,1.0f);
    glClear(GL_COLOR_BUFFER_BIT);
  }

  void Render::ClearBackground(float r, float g, float b, float a)
  {
    glClearColor(r,g,b,a);
    glClear(GL_COLOR_BUFFER_BIT);
  }

  ///////////////////////////////////////////////////////////////////////
  /// OpenGL Context
  void Render::InitGLBuffer(std::vector<float> vertices)
  {
    VAO = 0;
    VBO = 0;
    glGenVertexArrays(1,&VAO);
    glGenBuffers(1,&VBO);

    glBindVertexArray(VAO);

    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, vertices.size() * sizeof(float), vertices.data(), GL_STATIC_DRAW);

    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);

    glBindBuffer(GL_ARRAY_BUFFER, 0);
    glBindVertexArray(0);
  }

  void Render::DrawShader(std::vector<OGL::Shader> v)
  {
    glViewport(0, 0, 800, 600);
    for(auto& s : v)
    {
      glUseProgram(s.GetShaderProgram());
      glBindVertexArray(VAO);
      glDrawArrays(GL_TRIANGLES, 0, 3);
    }
  }
}


