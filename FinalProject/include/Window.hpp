#pragma once

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
};
