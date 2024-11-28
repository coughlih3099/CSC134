/**
 * @file FrameTimer.hpp
 *
 * @brief Class for managing frame timing
 *
 * This has been shamelessly ripped from Claude.ai
 * Prompt: (context is the NCursesSession/Window classes)
 * Is there way to make a frame timer so I can control the frame pacing. Like how raylib has SetTargetFPS
 */
#pragma once

#include <chrono>
#include <thread>

class FrameTimer {
 private:
    std::chrono::microseconds frame_duration;
    std::chrono::steady_clock::time_point last_frame;

 public:
    explicit FrameTimer(int target_fps)
        : frame_duration(std::chrono::microseconds(1000000 / target_fps))
        , last_frame(std::chrono::steady_clock::now()) {}

    void wait_for_next_frame() {
        auto now = std::chrono::steady_clock::now();
        auto elapsed = now - last_frame;

        if (elapsed < frame_duration) {
            std::this_thread::sleep_for(frame_duration - elapsed);
        }

        last_frame = std::chrono::steady_clock::now();
    }
};
