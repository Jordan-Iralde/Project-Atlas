#include "Window.hpp"
#include "Logger.hpp"

Window::Window(const std::string &title, int width, int height)
    : m_title(title), m_width(width), m_height(height) {}

Window::~Window() { Shutdown(); }

bool Window::Initialize() {
  m_window = SDL_CreateWindow(m_title.c_str(), m_width, m_height, 0);

  if (!m_window) {
    Logger::Error(std::string("Failed to create SDL3 window: ") +
                  SDL_GetError());
    return false;
  }

  m_isOpen = true;

  Logger::Info("SDL3 window created successfully.");
  return true;
}

void Window::PollEvents() {
  SDL_Event event;
  while (SDL_PollEvent(&event)) {
    if (event.type == SDL_EVENT_QUIT) {
      m_isOpen = false;
    }
  }
}

void Window::Shutdown() {
  if (m_window) {
    SDL_DestroyWindow(m_window);
    m_window = nullptr;
    Logger::Info("SDL3 window destroyed safely.");
  }
}
