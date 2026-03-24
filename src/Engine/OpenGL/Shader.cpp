#include "Shader.hpp"
#include "System/TraceLog.hpp"
#include "Utils/Archive.hpp"
#include "Vertex.hpp"
#include <GL/glext.h>
#include <cstddef>
#include <fcntl.h>
#include <string>

namespace OGL
{
  bool Shader::CreateShader(std::string vs_Path, std::string fs_Path)
  {
    if(!vs_Path.empty())
    {
      oGLCreateVertixShader(&this->vertexShader);
      std::string t = ENG::Archive::LoadArchive(vs_Path);
      const char* vsPathContent = t.c_str();
      glShaderSource(this->vertexShader,1, &vsPathContent ,NULL);
      glCompileShader(this->vertexShader);
      glGetShaderiv(this->vertexShader, GL_COMPILE_STATUS, &this->vs_Success);

      if(!this->vs_Success)
      {
        glGetShaderInfoLog(this->vertexShader,512,NULL,this->infoLog);
        ENG::TraceLog::MsgTraceLog(ENG::LogContext::LOG_ERROR, ">> | Shader VS FAILED COMPILE: ",this->infoLog);
        return false;
      }
      else
      {
        ENG::TraceLog::MsgTraceLog(ENG::LogContext::LOG_INFO, ">> | Shader VS SUCCESS COMPILE.");
      }
    }
    if(!fs_Path.empty())
    {
      oGLCreateFragmentShader(&this->fragmentShader);
      std::string t = ENG::Archive::LoadArchive(fs_Path).c_str();
      const char* fsPathContent = t.c_str();
      glShaderSource(this->fragmentShader,1,&fsPathContent,NULL);
      glCompileShader(this->fragmentShader);
      glGetShaderiv(this->fragmentShader, GL_COMPILE_STATUS, &this->fs_Success);

      if(!fs_Success)
      {
        glGetShaderInfoLog(this->fragmentShader,512,NULL,this->infoLog);
        ENG::TraceLog::MsgTraceLog(ENG::LogContext::LOG_ERROR, ">> | Shader FAILED COMPILE: ",this->infoLog);
        return false;
      }
      else 
      {
        ENG::TraceLog::MsgTraceLog(ENG::LogContext::LOG_INFO, ">> | Shader SUCCESS COMPILE");
      }
    }
    else
    {
      ENG::TraceLog::MsgTraceLog(ENG::LogContext::LOG_INFO, "Shader is empty, Load Vs and Fs");
      return false;
    }

    /// Create Shader Program.
    this->shaderProgram = glCreateProgram();
    glAttachShader(this->shaderProgram,this->vertexShader);
    glAttachShader(this->shaderProgram,this-> fragmentShader);
    glLinkProgram(this->shaderProgram);
    
    glGetProgramiv(this->shaderProgram,GL_LINK_STATUS,&this->sp_Success);
    if(!this->sp_Success)
    {
      glGetProgramInfoLog(this->shaderProgram,512,NULL,this->infoLog);
      ENG::TraceLog::MsgTraceLog(ENG::LogContext::LOG_ERROR, ">> | Shader Program FAILED: ",this->infoLog);
      return false;
    }
    else
    {
      ENG::TraceLog::MsgTraceLog(ENG::LogContext::LOG_INFO, ">> | Shader Program SUCCES.");
    }

    glDeleteShader(this->vertexShader);
    glDeleteShader(this->fragmentShader);
    
    return true;
  }

  GLuint Shader::GetShaderProgram(void)
  {
    return this->shaderProgram;
  }

  void Shader::DeleteShader(void)
  {
    glDeleteProgram(shaderProgram);
  }



  // Private fuctions
  void Shader::oGLCreateVertixShader(unsigned int* vs)
  {
    *vs = glCreateShader(GL_VERTEX_SHADER);
  }

  void Shader::oGLCreateFragmentShader(unsigned int *fs)
  {
    *fs = glCreateShader(GL_FRAGMENT_SHADER);
  }
}
