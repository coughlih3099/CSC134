/**
 * @file Window.hpp
 *
 * @brief Header file for Window wrapper class
 */
#include <ncurses.h>
#include <memory>

struct WindowDeleter {
    void operator()(WINDOW* window) {
        // checking window exists before deletion
        if (window) delwin(window);
    }
};

class Window {
 private:
    std::unique_ptr<WINDOW, WindowDeleter> window;

 public:
    Window(int height, int width, int start_y, int start_x);

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
