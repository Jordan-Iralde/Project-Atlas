#include "Timer.hpp";
class Application
{
public:

    void Run();

private:

    void Initialize();
    void Shutdown();
	void Update();
	void Render();
    Timer::Timer()
        : deltaTime(0.0f),
        fps(0)
    {
    }
};