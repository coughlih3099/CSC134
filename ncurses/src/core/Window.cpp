/**
 * @file Window.cpp
 *
 * @brief Implementation of Window wrapper for NCurses
 */
#include <ncurses.h>
#include <memory>
#include <stdexcept>
#include <string>
#include "../include/Window.hpp"


Window::Window(int height, int width, int start_y, int start_x) {
    // According to NCurses man page, newwin will fail when any of arguments
    // passed to it are negative.
    // I wonder if there is a more graceful way to accomplish this.
    if (height < 0 || width < 0 || start_y < 0 || start_x < 0) {
        std::string invalid_arguments = "";
        if (height < 0) {
            invalid_arguments += "height";
        }
        if (width < 0) {
            if (!invalid_arguments.empty()) {
               invalid_arguments += ", ";
            }
            invalid_arguments += "width";
        }
        if (start_y < 0) {
            if (!invalid_arguments.empty()) {
               invalid_arguments += ", ";
            }
            invalid_arguments += "start y";
        }
        if (start_x < 0) {
            if (!invalid_arguments.empty()) {
               invalid_arguments += ", ";
            }
            invalid_arguments += "start x";
        }
        throw std::invalid_argument(invalid_arguments + ": can't be less than 0");
    }
    window = std::unique_ptr<WINDOW, WindowDeleter>(
            newwin(height, width, start_y, start_x));
    if (!window) {
        throw std::runtime_error("Failed to create Window");
    }
}

void Window::set_delay(int delay_in_milliseconds) {
    wtimeout(window.get(), delay_in_milliseconds);
}