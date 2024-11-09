#pragma once

#include <raylib.h>
#include <string>
#include <vector>

class Window {
    int window_size_x;
    int window_size_y;
    ConfigFlags flags;

 public:
    Window();
    ~Window();

    /**
     *  searches through all available flags to see which are enabled
     *  @return, a list of string representations of the enabled flags
     */
    std::vector<std::string> get_enabled_flags();
};
