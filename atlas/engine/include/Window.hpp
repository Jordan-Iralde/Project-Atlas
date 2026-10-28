#pragma once

#include <SDL3/SDL.h>
#include <string>

class Window {
public:
    Window(const std::string& title, int width, int height);
    ~Window();

    bool Initialize();
    void PollEvents();
    void Shutdown();

    bool IsOpen() const { return m_isOpen; }

private:
    SDL_Window* m_window = nullptr;

    std::string m_title;
    int m_width;
    int m_height;

    bool m_isOpen = false;
};
