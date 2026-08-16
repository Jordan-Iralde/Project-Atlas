#include "Application.hpp";
#include "Logger.hpp";
int main()
{
    Logger logger;
    logger.Info("Starting Application");
    logger.Warning("This is a warning message");
    logger.Error("This is an error message");


    Application app;
    app.Run();


    return 0;
}