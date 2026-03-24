#pragma once

#include "GLFW/glfw3.h"

#include <sys/types.h>
#include <unordered_set>

namespace ENG
{
  class PollEvent
  {
    public:
      static PollEvent& Get(void);
      static void DonePollEvent(void);
      PollEvent& GetPollEvent(void);

      void UpdatePollEventsGLFW();
      void UpdatePollEvents();
      void ProcessPollEvents();
      void ClearPollEvent(void);

      /// Old design
      // PollEvent(GLFWwindow* w) : window(w)
      // {
      //   TraceLog::MsgTraceLog(LogContext::LOG_INFO, "    PollEvent initialized successfully.");
      // }
      void SetWindowsGLFW(GLFWwindow* w);
      bool IsKeyPress(int key);
      bool IsKeyDown(int key);
      bool IsKeyRelease(int key);
    private:
      static inline PollEvent* instance;
      GLFWwindow* window;
      std::unordered_set<int> keyMap;
      std::unordered_set<int> prevkeyMap;
  };
}
