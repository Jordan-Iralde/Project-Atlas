#include <chrono>
#include <iostream>

using namespace std;
using namespace std::chrono;

class Timer {
public:
	void StartTimer();
	void Update();
	void GetTime();
	void GetDeltaTime();
	void GetFPS();

private:
	time_point<high_resolution_clock> startTime;
	time_point<high_resolution_clock> lastFrameTime;
	float deltaTime;
	float fps;
};