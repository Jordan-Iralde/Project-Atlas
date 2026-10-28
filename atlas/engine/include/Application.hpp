#pragma once

#include "Timer.hpp"

class Window;

class Application {
public:
  void Run();

private:
  bool Initialize();
  void Shutdown();
  void Update();
  void Render();

  bool m_isRunning = false;
  Timer timer;
  Window *m_window = nullptr; // <--- Añadido aquí
};
