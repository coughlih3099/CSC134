/**
 * @file Window.hpp
 *
 * @brief Header file for Window wrapper class
 */
#pragma once

#include <ncurses.h>
#include <memory>

#define BLOCKING_INPUT -1
#define NONBLOCKING_INPUT 0

struct WindowDeleter {
    void operator()(WINDOW* window) {
        // checking window exists before deletion
        if (window) delwin(window);
    }
};

class Window {
 private:
    std::unique_ptr<WINDOW, WindowDeleter> window;
    int delay;

 public:
    Window(int height, int width, int start_y, int start_x);

    /**
     * @brief Sets (non)blocking read for the window.
     *
     * If delay_in_milliseconds < 0, blocking read.
     * If delay_in_milliseconds == 0, non-blocking read.
     * If delay_in_milliseconds > 0, the read is blocked for set time.
     * 
     * @param delay_in_milliseconds The delay to block for in milliseconds
     */
    void set_delay(int delay_in_milliseconds);
    int get_delay() { return delay; }

    // Get the raw pointer
    WINDOW* get_pointer() { return window.get(); }
    const WINDOW* get_pointer() const { return window.get(); }

    // Prevent copying
    Window(const Window&) = delete;
    Window& operator=(const Window&) = delete;

    // Allow moving
    Window(Window&&) = default;
    Window& operator=(Window&&) = default;
};  // Window
