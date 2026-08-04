#include "Timer.hpp"
#include <iostream>

void Timer::StartTimer() {
	startTime = high_resolution_clock::now();
	lastFrameTime = startTime;
}

void Timer::Update() {
	auto currentTime = high_resolution_clock::now();
	deltaTime = currentTime - lastFrameTime;
	lastFrameTime = currentTime;
	fps = 1.0f / deltaTime.count();
}
void Timer::GetTime() {
	auto currentTime = high_resolution_clock::now();
	auto elapsedTime = duration_cast<duration<milliseconds>>(currentTime - startTime);
	std::cout << "Elapsed Time: " << elapsedTime.count() << " seconds" << std::endl;
}

void Timer::GetDeltaTime() {
	std::cout << "Delta Time: " << deltaTime.count() << " seconds" << std::endl;
}

void Timer::GetFPS() {
	std::cout << "FPS: " << fps << std::endl;
}