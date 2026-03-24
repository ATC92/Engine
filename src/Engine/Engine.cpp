#include "Render/Render.hpp"
#include "Inputs/PollEvent.hpp"
#include "System/TraceLog.hpp"
#include "Utils/Utils.hpp"
#include <Engine.hpp>
#include <chrono>
#include <memory>
#include <utility>

namespace ENG
{
  Engine::Engine(const EngineConfig& config, std::unique_ptr<GameLayer> refLayer)
    : eConfig(std::move(config)), app{std::move(refLayer)} {}

  int Engine::OnRun(void)
  {
    OnInit();
    
    auto& window = Render::Get().GetWindow();
    auto& pEvent = PollEvent::Get();
    pEvent.SetWindowsGLFW(window.GetWindow());
    
    auto frame_ant = std::chrono::high_resolution_clock::now();
    float ms = 0.16666f;

    while(app->IsRunning())
    {
      pEvent.ProcessPollEvents();
      //pEvent.UpdatePollEvents();

      app->OnInputs(ms);
      app->OnUpdate(ms);
      app->OnRender(ms);

      window.UpdateWindow();
      window.UpdatePollEvents();
      pEvent.ClearPollEvent();
      /// Update FrameRate
      auto frame_act = std::chrono::high_resolution_clock::now();
      ms= std::chrono::duration_cast<std::chrono::duration<float>>(frame_act-frame_ant).count();
      frame_ant = frame_act;

    } /// End of loop

    window.CloseWindow();
    Render::DoneRender();
    PollEvent::DonePollEvent();
    
    TraceLog::MsgTraceLog(LogContext::LOG_INFO, ">> Engine down");
    TraceLog::MsgTraceLog(LogContext::LOG_INFO, ">> Cya!");

    return EXIT_SUCCESS;
  }

  void Engine::OnInit()
  {
    /// Declarations
    Render::Get().CreateWindow(eConfig);

    glfwSetTime(60.00);
  
    app->OnInit();

    ENG::TraceLog::MsgTraceLog(ENG::LogContext::LOG_INFO, ">> Engine ready.");
  }
}
