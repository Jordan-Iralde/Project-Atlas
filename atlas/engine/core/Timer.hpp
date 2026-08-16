#pragma once

#include <chrono>

class Timer
{
public:
    void StartTimer();
    void Update();

    float GetTime() const;
    float GetDeltaTime() const;
    float GetFPS() const;

private:
    using Clock = std::chrono::high_resolution_clock;
    using TimePoint = std::chrono::time_point<Clock>;

    TimePoint startTime;
    TimePoint lastFrameTime;

    float deltaTime = 0.0f;
    float fps = 0.0f;
};