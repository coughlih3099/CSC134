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
    std::string window_name;

 public:
    // Default params: Window Size = 1280x720, Title = "Raylib Window", no flags
    Window();

    // no flags
    Window(int window_size_x, int window_size_y, std::string title);

    // with flags
    Window(int window_size_x, int window_size_y, ConfigFlags flags, std::string title);
    ~Window();

    /**
     *  searches through all available flags to see which are enabled
     *  @return, a list of string representations of the enabled flags
     */
    std::vector<std::string> get_enabled_flags();

    /**
     * Window width getter
     * @return, window width
     */
    int get_window_width();

    /**
     * Window height getter
     * @return, window height
     */
    int get_window_height();

    /**
     * Window title getter
     * @return, window title
     */
    std::string get_window_title();
};
