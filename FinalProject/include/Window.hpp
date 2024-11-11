#pragma once

// Wrapper class for Raylib window

#include <raylib.h>
#include <string>
#include <vector>

class Window {
 private:
    int size_current_width;
    int size_current_height;
    int size_minimum_width;
    int size_minimum_height;
    int size_maximum_width;
    int size_maximum_height;
    ConfigFlags flags;
    bool is_test_mode;
    std::string title;

 public:
    // Default params: Window Size = 1280x720, Title = "Raylib Window", no flags
    explicit Window(bool is_test_mode = false);
    Window(int size_width, int size_height, std::string title,
           bool is_test_mode = false);
    Window(int size_width, int size_height, ConfigFlags flags,
           std::string title, bool is_test_mode = false);
    ~Window();

    /**
     *  searches through all available flags to see which are enabled
     *  @return, a list of string representations of the enabled flags
     */
    std::vector<std::string> get_enabled_flags();

    int get_width() const { return size_current_width; }
    int get_height() const { return size_current_height; }
    std::string get_title() const { return title; }
    ConfigFlags get_flags() const { return flags; }

    void set_size(int width, int height);
    void set_size_minimum(int width, int height);
    void set_size_maximum(int width, int height);
};
