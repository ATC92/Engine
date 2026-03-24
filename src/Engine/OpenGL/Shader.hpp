#pragma once

#include "glad/gl.h"
#include <string>

namespace OGL
{
  enum class ShaderType 
  {
    ENG_VERTEX_SHADER = 0,
    ENG_FRAGMENT_SHADER
  };

  class Shader
  {
    public:
      /// Can use:
      /// * ENG_VERTEX_SHADER
      /// * ENG_FRAGMENT_SHADER
      bool CreateShader(std::string vs_Path, std::string fs_Path);
      GLuint GetShaderProgram(void);
      void DeleteShader();
    private:
      void oGLCreateVertixShader(unsigned int* vs);
      void oGLCreateFragmentShader(unsigned int* fs);

    private:
      GLuint vertexShader;
      int vs_Success;
      GLuint fragmentShader;
      int fs_Success;
      char infoLog[512];

      GLuint shaderProgram;
      int sp_Success;
  };
}
