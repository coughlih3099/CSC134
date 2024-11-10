#pragma once

// Wrapper class for Raylib window

#include <raylib.h>
#include <string>
#include <vector>

class Window {
 private:
    int window_size_x;
    int window_size_y;
    ConfigFlags flags;
    bool test_mode;
    std::string window_name;

 public:
    // Default params: Window Size = 1280x720, Title = "Raylib Window", no flags
    explicit Window(bool test_mode = false);
    Window(int window_size_x, int window_size_y, std::string title,
           bool test_mode = false);
    Window(int window_size_x, int window_size_y, ConfigFlags flags,
           std::string title, bool test_mode = false);
    ~Window();

    /**
     *  searches through all available flags to see which are enabled
     *  @return, a list of string representations of the enabled flags
     */
    std::vector<std::string> get_enabled_flags();

    int get_width() const { return window_size_x; }
    int get_height() const { return window_size_y; }
    std::string get_title() const { return window_name; }
    ConfigFlags get_flags() const { return flags; }
};
