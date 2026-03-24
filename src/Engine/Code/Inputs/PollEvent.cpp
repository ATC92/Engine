#include "Inputs/PollEvent.hpp"
#include "GLFW/glfw3.h"
#include "System/TraceLog.hpp"
#include <endian.h>

namespace ENG
{
  PollEvent& PollEvent::Get()
  {
    if(!instance)
        instance = new PollEvent();
    return *instance;
  }

  void PollEvent::DonePollEvent(void)
  {
    delete instance;
  }

  void PollEvent::SetWindowsGLFW(GLFWwindow* w)
  {
    window = w;
  }

  bool PollEvent::IsKeyPress(int key)
  {
    return keyMap.contains(key);
  }

  bool PollEvent::IsKeyDown(int key)
  {
    return keyMap.contains(key) && prevkeyMap.contains(key);
  }

  bool PollEvent::IsKeyRelease(int key)
  {
    return !keyMap.contains(key) && prevkeyMap.contains(key);
  }

  void PollEvent::ClearPollEvent(void)
  {
    prevkeyMap = keyMap;
    keyMap.clear();
  }

  void PollEvent::UpdatePollEvents()
  {
    for(auto& key : keyMap)
    {
      if (key == 0)
        return;
      TraceLog::MsgTraceLog(LogContext::LOG_INFO, "KeyPressed: ", key);
    }
  }

  void PollEvent::ProcessPollEvents() 
  {
    auto rWindow = window;
    for (int i = 32; i < 349; i++)
    {
      if(glfwGetKey(rWindow, i) == GLFW_PRESS)
      {
        TraceLog::MsgTraceLog(LogContext::LOG_INFO, "Key: ", i);
        keyMap.insert(i);
      }
    }
  }
} // namespace ENG
