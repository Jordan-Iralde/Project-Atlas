#include "Application.hpp"
#include "Logger.hpp"

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
    Logger::Info("Running Application");
    for (int i = 0; i < 5; ++i)
    {
        std::cout << "Hello, World! " << i + 1 << std::endl;
    }

    Shutdown();
}