#include <raylib.h>
#include <array>
#include <string>
#include <vector>
#include <utility>
#include "../include/Window.hpp"


Window::Window() :
    window_size_x(1280),
    window_size_y(720),
    flags(),  // Flags initialized to zero in Raylib
    window_name("Raylib Window")
{
    InitWindow(window_size_x, window_size_y, window_name.c_str());
}

Window::Window(int window_size_x, int window_size_y, std::string title) :
    window_size_x(window_size_x),
    window_size_y(window_size_y),
    flags(),  // Flags initialized to zero in Raylib
    window_name(std::move(title))
{
    InitWindow(window_size_x, window_size_y, window_name.c_str());
}

Window::Window(int window_size_x, int window_size_y, ConfigFlags flags, std::string title) :
    window_size_x(window_size_x),
    window_size_y(window_size_y),
    flags(flags),
    window_name(std::move(title))
{
    InitWindow(window_size_x, window_size_y, window_name.c_str());
}

Window::~Window() {
    CloseWindow();
}


const std::array<ConfigFlags, 16> all_flags = {
    // These flags can be set whenever
    FLAG_VSYNC_HINT,   // Set to try enabling V-Sync on GPU
    FLAG_FULLSCREEN_MODE,   // Set to run program in fullscreen
    FLAG_WINDOW_RESIZABLE,   // Set to allow resizable window
    FLAG_WINDOW_UNDECORATED,   // Set to disable window decoration (frame and buttons)
    FLAG_WINDOW_HIDDEN,   // Set to hide window
    FLAG_WINDOW_MINIMIZED,   // Set to minimize window (iconify)
    FLAG_WINDOW_MAXIMIZED,   // Set to maximize window (expanded to monitor)
    FLAG_WINDOW_UNFOCUSED,   // Set to window non focused
    FLAG_WINDOW_TOPMOST,   // Set to window always on top
    FLAG_WINDOW_ALWAYS_RUN,   // Set to allow windows running while minimized
    FLAG_WINDOW_MOUSE_PASSTHROUGH, // Set to support mouse passthrough, only supported when FLAG_WINDOW_UNDECORATED
    FLAG_BORDERLESS_WINDOWED_MODE, // Set to run program in borderless windowed mode
    FLAG_INTERLACED_HINT,    // Set to try enabling interlaced video format (for V3D)
    // These flags can only be set before window creation
    FLAG_WINDOW_TRANSPARENT,   // Set to allow transparent framebuffer
    FLAG_WINDOW_HIGHDPI,   // Set to support HighDPI
    FLAG_MSAA_4X_HINT   // Set to try enabling MSAA 4X
};


std::string get_flag_string(ConfigFlags flag) {
    std::string flag_string;
    switch (flag) {
        case FLAG_VSYNC_HINT:
            flag_string = "V-Sync";
            break;
        case FLAG_FULLSCREEN_MODE:
            flag_string = "Fullscreen";
            break;
        case FLAG_WINDOW_RESIZABLE:
            flag_string = "Resizable";
            break;
        case FLAG_WINDOW_UNDECORATED:
            flag_string = "Undecorated";
            break;
        case FLAG_WINDOW_HIDDEN:
            flag_string = "Hidden";
            break;
        case FLAG_WINDOW_MINIMIZED:
            flag_string = "Minimized";
            break;
        case FLAG_WINDOW_MAXIMIZED:
            flag_string = "Maximized";
            break;
        case FLAG_WINDOW_UNFOCUSED:
            flag_string = "Unfocused";
            break;
        case FLAG_WINDOW_TOPMOST:
            flag_string = "On top";
            break;
        case FLAG_WINDOW_ALWAYS_RUN:
            flag_string = "Run while minimized";
            break;
        case FLAG_WINDOW_MOUSE_PASSTHROUGH:
            flag_string = "Mouse passthrough";
            break;
        case FLAG_BORDERLESS_WINDOWED_MODE:
            flag_string = "Borderless windowed mode";
            break;
        case FLAG_INTERLACED_HINT:
            flag_string = "Interlaced";
            break;
        case FLAG_WINDOW_TRANSPARENT:
            flag_string = "Allow transparent framebuffer";
            break;
        case FLAG_WINDOW_HIGHDPI:
            flag_string = "HighDPI support";
            break;
        case FLAG_MSAA_4X_HINT:
            flag_string = "MSAA 4X enabled";
            break;
    }
    return flag_string;
}


std::vector<std::string> Window::get_enabled_flags() {
    // There is a max of 16 flags that can be enabled
    std::vector<std::string> enabled_flags(16);
    for (const auto& flag : all_flags) {
        if (IsWindowState(flag)) {
            enabled_flags.push_back(get_flag_string(flag));
        }
    }
    if (enabled_flags.size() < 16) {
        enabled_flags.shrink_to_fit();
    }
    return enabled_flags;
}


int Window::get_window_width() {
    return window_size_x;
}


int Window::get_window_height() {
    return window_size_y;
}


std::string Window::get_window_title() {
    return window_name;
}
