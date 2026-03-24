#pragma once

#include <iostream>
#include <stdexcept>



namespace ENG 
{
  enum class LogContext
  {
    LOG_INFO = 0,
    LOG_ERROR,
    LOG_FATAL,
    LOG_DEBUG
  };
  class TraceLog
  {
    public:
      template<typename... Args>
      static void MsgTraceLog(LogContext Context, Args&&... args)
      {
        std::cout << "[" << ToString(Context) << "] ";
        (std::cout << ... << args);
        std::cout << '\n';
        if(Context == LogContext::LOG_FATAL)
        {
          throw std::runtime_error(">>  Error, Stoping the Engine Now.");
        }
      }
    private:
      static const char* ToString(LogContext Context)
      {
        switch (Context)
        {
          case LogContext::LOG_INFO:
            return "LOG_INFO";
            break;
          case LogContext::LOG_ERROR:
            return "LOG_ERROR";
            break;
          case LogContext::LOG_FATAL:
            return "LOG_FATAL";
            break;
          case LogContext::LOG_DEBUG:
            return "LOG_DEBUG";
            break;
          default:
            return "LOG_UNKNOWN";
            break;
        }
      };


  };
}
