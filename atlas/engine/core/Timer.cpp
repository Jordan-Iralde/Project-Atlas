#include "Timer.hpp"
#include <iostream>

void Timer::StartTimer() {
	startTime = Clock::now();
	lastFrameTime = startTime;
}

void Timer::Update() {
	TimePoint currentTime = Clock::now();
	std::chrono::duration<float> delta = currentTime - lastFrameTime;
	deltaTime = delta.count();
	lastFrameTime = currentTime;
	if (deltaTime > 0.0f) {
		fps = 1.0f / deltaTime;
	}
	else {
		fps = 0.0f;
	}
}
float Timer::GetTime() const {
	TimePoint currentTime = Clock::now();
	std::chrono::duration<float> elapsed = currentTime - startTime;
	return elapsed.count();
}

float Timer::GetDeltaTime() const {
	return deltaTime;
}

float Timer::GetFPS() const {
	return fps;
}