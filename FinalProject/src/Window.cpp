/**
 * @file Window.cpp
 *
 * @brief Implementation of the Window class.
 */

#include <raylib.h>
#include <array>
#include <string>
#include <vector>
#include <utility>
#include "../include/Window.hpp"


Window::Window(bool is_test_mode) :
    is_test_mode(is_test_mode)
{
    if (!is_test_mode) {
        InitWindow(size_current_width, size_current_height, title.c_str());
    }
}

Window::Window(int size_width, int size_height, std::string initial_title,
               bool is_test_mode) :
    size_current_width(size_width),
    size_current_height(size_height),
    title(std::move(initial_title)),
    is_test_mode(is_test_mode)
{
    if (!is_test_mode) {
        InitWindow(size_current_width, size_current_height, title.c_str());
    }
}

Window::Window(int size_width, int size_height, ConfigFlags flags,
               std::string initial_title, bool is_test_mode) :
    size_current_width(size_width),
    size_current_height(size_height),
    flags(flags),
    title(std::move(initial_title)),
    is_test_mode(is_test_mode)
{
    if (!is_test_mode) {
        InitWindow(size_current_width, size_current_height, title.c_str());
        if (flags != 0) {
            SetWindowState(flags);
        }
    }
}

Window::~Window() {
    if (!is_test_mode) {
        CloseWindow();
    }
}


bool Window::get_window_ready() {
    return IsWindowReady();
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
    std::vector<std::string> enabled_flags;

    if (is_test_mode) {
        for (const auto& flag : all_flags) {
            if (flags & flag) {
                enabled_flags.push_back(get_flag_string(flag));
            }
        }
    } else {
        for (const auto& flag : all_flags) {
            if (IsWindowState(flag)) {
                enabled_flags.push_back(get_flag_string(flag));
            }
        }
    }

    return enabled_flags;
}


bool Window::set_size_current(int width, int height) {
    if (width == get_current_width() && height == get_current_height()) {
        TraceLog(LOG_WARNING, "Trying to set window size to it's current size");
        return false;
    }

    if (width <= size_minimum_width || height <= size_minimum_height) {
        TraceLog(LOG_WARNING, "Trying to set window size smaller than the "
                              "minimum allowed: %d x %d",
                              size_minimum_width, size_minimum_height);
        return false;
    }

    if (width >= size_maximum_width || height >= size_maximum_height) {
        TraceLog(LOG_WARNING, "Trying to set window size larger than the "
                              "maximum allowed: %d x %d",
                              size_maximum_width, size_maximum_height);
        return false;
    }

    size_current_width = width;
    size_current_height = height;

    if (!is_test_mode) {
        SetWindowSize(width, height);
    }

    return (width == get_current_width() && height == get_current_height());
}


bool Window::set_size_minimum(int width, int height) {
    const int ABSOLUTE_MINIMUM = 100;

    if (!(flags & FLAG_WINDOW_RESIZABLE)) {
        TraceLog(LOG_WARNING, "The window is not resizable");
        return false;
    }

    if (width < ABSOLUTE_MINIMUM || height < ABSOLUTE_MINIMUM) {
        TraceLog(LOG_WARNING, "Trying to set minimum lower than the absolute "
                              "minimum value of 100 x 100.");
        return false;
    }

    if (width >= get_maximum_width() || height >= get_maximum_height()) {
        TraceLog(LOG_WARNING, "Trying to set minimum higher than the "
                              "maximum: %d x %d",
                              size_maximum_width, size_maximum_height);
        return false;
    }

    if (width == get_minimum_width() && height == get_minimum_height()) {
        TraceLog(LOG_WARNING, "Trying to set minimum to it's current value");
        return false;
    }

    size_minimum_width = width;
    size_minimum_height = height;

    return (width == get_minimum_width() && height == get_minimum_height());
}


bool Window::set_size_maximum(int width, int height) {
    if (!(flags & FLAG_WINDOW_RESIZABLE)) {
        TraceLog(LOG_WARNING, "The window is not resizable");
        return false;
    }

    if (width <= get_minimum_width() || height <= get_minimum_height()) {
        TraceLog(LOG_WARNING, "Tring to set maximum lower that the "
                              "minimum: %d x %d",
                              size_minimum_width, size_minimum_height);
        return false;
    }

    if (width == get_maximum_width() && height == get_maximum_height()) {
        TraceLog(LOG_WARNING, "Maximum size is equal to the current maximum");
        return false;
    }

    size_maximum_width = width;
    size_maximum_height = height;

    if (!is_test_mode) {
        SetWindowSize(width, height);
    }

    return (width == get_maximum_width() && height == get_maximum_height());
}


bool Window::set_flag(ConfigFlags flags_to_set) {
    if (flags_to_set & FLAG_WINDOW_TRANSPARENT) {
        TraceLog(LOG_WARNING, "Transparent window can only be set on initialization");
        return false;
    }

    if (flags_to_set & FLAG_WINDOW_HIGHDPI) {
        TraceLog(LOG_WARNING, "Highdpi can only be set on initialization");
        return false;
    }

    if (flags_to_set & FLAG_MSAA_4X_HINT) {
        TraceLog(LOG_WARNING, "MSAA 4X can only be set on initialization");
        return false;
    }


    if (is_test_mode) {
        flags = static_cast<ConfigFlags>(flags | flags_to_set);
    } else {
        SetWindowState(flags_to_set);
        flags = get_flags();
    }

    return (flags & flags_to_set) == flags_to_set;
}


bool Window::remove_flags() {
    if (flags == 0) {
        TraceLog(LOG_WARNING, "No flags set");
        return false;
    }

    ClearWindowState(flags);
    flags = get_flags();

    return flags == 0;
}


bool Window::remove_flags(ConfigFlags flags_to_remove) {
    if (!(flags & flags_to_remove)) {
        TraceLog(LOG_WARNING, "Trying to remove flags that aren't set");
        return false;
    }

    ClearWindowState(flags_to_remove);
    flags = static_cast<ConfigFlags>(flags & ~flags_to_remove);

    return (flags & flags_to_remove) == 0;
}
