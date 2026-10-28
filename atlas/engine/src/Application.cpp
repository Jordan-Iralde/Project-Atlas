
#include "Application.hpp"
#include "Window.hpp"
#include "Logger.hpp"

#include <SDL3/SDL.h>
#include <string>

void Application::Run()
{
    if (!Initialize()) {
        Logger::Error("Application initialization failed. Aborting execution.");
        Shutdown();
        return;
    }

    timer.StartTimer();

    Logger::Info("Application main loop started");

    while (m_isRunning) {
        Update();
        Render();
    }

    Shutdown();
}

bool Application::Initialize()
{
    Logger::Info("Initializing Application subsystems...");

    // 1. Inicializar SDL3
    if (!SDL_Init(SDL_INIT_VIDEO)) {
        Logger::Error(
            std::string("Failed to initialize SDL3: ") + SDL_GetError()
        );
        return false;
    }

    // 2. Crear la ventana de Atlas
    m_window = new Window("Atlas Engine", 1280, 720);

    if (!m_window->Initialize()) {
        Logger::Error("Failed to initialize Atlas window.");
        return false;
    }

    m_isRunning = true;

    return true;
}

void Application::Update()
{
    timer.Update();

    // Procesar los eventos de la ventana
    if (m_window) {
        m_window->PollEvents();

        if (!m_window->IsOpen()) {
            m_isRunning = false;
        }
    }
}

void Application::Render()
{
    // TODO: Implementar el renderizador de Atlas.
}

void Application::Shutdown()
{
    Logger::Info("Shutting down Application safely...");

    // Liberar la ventana
    if (m_window) {
        delete m_window;
        m_window = nullptr;
    }

    // Cerrar SDL
    SDL_Quit();

    m_isRunning = false;
}

