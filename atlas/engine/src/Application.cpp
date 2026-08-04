#include "Application.hpp"
#include "Logger.hpp"
#include "Timer.hpp"


void Application::Initialize()
{
    Logger::Info("Initializing Application");
}

void Application::Shutdown()
{
    Logger::Info("Shutting down Application");
    exit(0);
}

void Application::Run()
{
    Initialize();
    timer.StartTimer();

    Logger::Info("Running Application");
    for (int i = 0; i < 5; ++i)
    {
        timer.Update();

        std::cout << "Hello, World! " << i + 1 << std::endl;
    }

    Logger::Info("Running Application");
    for (int i = 0; i < 5; ++i)
    {
        timer.Update();

        std::cout << "Hello, World! " << i + 1 << std::endl;
    }

    Shutdown();
}