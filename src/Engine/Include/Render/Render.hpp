#pragma once

#include "Shader.hpp"
#include "GLFW/glfw3.h"
#include "Utils/Color.hpp"
#include "Utils/Utils.hpp"
#include <memory>
#include <string>
#include <vector>

namespace ENG 
{
  class eWindows
  {
    public:
      eWindows(const std::string WindowsName, int Width, int Height);
      bool ChangeSizeWindow(int NewWidth, int NewHeight);
      void CloseWindow();
      bool IsWindowsClose();
      GLFWwindow* GetWindow();
      void UpdateWindow();
      void UpdatePollEvents();
    private:
      static void InitGLFWContext();
      static void InitGladContext();
    private:
      std::string wName;
      int wWidth;
      int wHeight;
      GLFWwindow* window;
  };

  class Render
  {
    public: 
      static Render& Get(void);
      static void DoneRender(void);
      void CreateWindow(const EngineConfig& config);
      eWindows& GetWindow();

    public:
      static void ClearBackground(const Color& c);
      static void ClearBackground(float r, float g, float b);
      static void ClearBackground(float r, float g, float b, float a);


    private:
      explicit Render()=default;
      static inline Render* instance = nullptr;
      std::unique_ptr<eWindows> window;
    
    //// GLSL Context
    public:
      static void InitGLBuffer(std::vector<float> vertices);
      static void DrawShader(std::vector<OGL::Shader> v);
    public:
      static inline unsigned int VAO;
      static inline unsigned int VBO;

  };
}
