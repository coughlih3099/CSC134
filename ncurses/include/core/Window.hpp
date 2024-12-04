/**
 * @file Window.hpp
 *
 * @brief Header file for Window wrapper class
 */
#pragma once

#include <ncurses.h>
#include <memory>
#include <forward_list>

#define BLOCKING_INPUT -1
#define NONBLOCKING_INPUT 0

struct WindowDeleter {
    void operator()(WINDOW* window) {
        if (window) delwin(window);
    }
};

/**
 * @class Window
 *
 * @brief Wrapper class for NCurses Windows
 *
 * This is a RAII implementation of NCurses Windows that seeks to simplify the
 * usage of Windows and implement some memory safety features that are available
 * in more modern C++.
 * The window is essentially created with a Singleton pattern provided by the
 * use of unique pointers and contains a non-default destructor.
 * The Window class allows the creation of derived windows that must be accessed
 * by reference as they are owned by the parent window and thus their lifetimes
 * are tied to and managed by the parent window.
 */
class Window {
 private:
    int delay;
    int height, width;
    std::unique_ptr<WINDOW, WindowDeleter> window;
    Window* parent;
    std::forward_list<Window> subwindows;
    int relative_y, relative_x;
    // Constructor for derived windows
    Window(Window* parent, int height, int width, int start_y, int start_x);

 public:
    // Constructor for root windows
    Window(int height, int width, int start_y, int start_x);

    /**
     * @brief Sets (non)blocking read for the window.
     *
     * Two macros are provided, BLOCKING_INPUT and NONBLOCKING_INPUT
     * If delay_in_milliseconds < 0, blocking read.
     * If delay_in_milliseconds == 0, non-blocking read.
     * If delay_in_milliseconds > 0, the read is blocked for set time.
     * 
     * @param delay_in_milliseconds The delay to block for in milliseconds
     */
    void set_delay(int delay_in_milliseconds);
    int get_delay() { return delay; }
    const int get_height() const { return height; }
    const int get_width() const { return width; }

    /**
     * @brief Returns a reference to the created derived window.
     *
     * This method ensures derived windows are properly created and managed by
     * the parent.
     * The relative y/x relates to the top-left corner of the derived window.
     *
     * @param height Height of the derived window.
     * @param width Width of the derived window.
     * @param relative_y Y position relative to the parent window.
     * @param relative_x X position relative to the parent window.
     * @return Reference to the newly created derived window.
     */
    Window& create_derived_window(int height, int width, int relative_y, int relative_x);

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
