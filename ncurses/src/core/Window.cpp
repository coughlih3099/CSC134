/**
 * @file Window.cpp
 *
 * @brief Implementation of Window wrapper for NCurses
 */
#include <ncurses.h>
#include <memory>
#include <stdexcept>
#include <string>
#include <forward_list>
#include <utility>
#include "../../include/core/Window.hpp"


Window::Window(int height, int width, int start_y, int start_x) :
    delay(BLOCKING_INPUT),
    parent(nullptr),
    height(height),
    width(width),
    relative_y(start_y),
    relative_x(start_x) {
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
        throw std::invalid_argument(std::move(invalid_arguments) +
                                    ": can't be less than 0");
    }
    window = std::unique_ptr<WINDOW, WindowDeleter>(
            newwin(height, width, start_y, start_x));
    if (!window) {
        throw std::runtime_error("Failed to create Window");
    }
}

Window::Window(Window* parent, int height, int width, int relative_y, int relative_x) :
    delay(BLOCKING_INPUT),
    parent(parent),
    height(height),
    width(width),
    relative_y(relative_y),
    relative_x(relative_x) {
    if (!parent) {
        throw std::invalid_argument("Parent window cannot be nullptr for derived windows");
    }
    window = std::unique_ptr<WINDOW, WindowDeleter>(derwin(parent->get_pointer(),
                                                    height, width, relative_y, relative_x));
    if (!window) {
        throw std::runtime_error("Failed to create derived window");
    }
}

void Window::set_delay(int delay_in_milliseconds) {
    delay = delay_in_milliseconds;
    wtimeout(window.get(), delay_in_milliseconds);
}

void Window::move_cursor(int y, int x) {
    if (y < 0 || y > this->height || x < 0 || x > this->width) {
        throw std::invalid_argument("Cursor position out of bounds");
    }
    wmove(this->get_pointer(), y, x);
}

void Window::add_char(chtype character) {
    auto val = waddch(this->get_pointer(), character);
    if (val == ERR) {
        throw std::runtime_error("Not possible to add complete character to window.");
    }
}

void Window::move_add_char(chtype character, int y, int x) {
    if (y < 0 || y > this->height || x < 0 || x > this->width) {
        std::string error_message = "Cursor position out of window bounds; Position: ";
        error_message += y;
        error_message += ", ";
        error_message += x;
        throw std::invalid_argument(error_message);
    }
    auto val = mvwaddch(this->get_pointer(), y, x, character);
    if (val == ERR) {
        throw std::runtime_error("Not possible to add complete character to window.");
    }
}

void Window::echo_char(chtype character) {
    auto val = waddch(this->get_pointer(), character);
    if (val == ERR) {
        throw std::runtime_error("Not possible to add complete character to window.");
    }
    auto val = wrefresh(this->get_pointer());
}

Window& Window::create_derived_window(int height, int width, int relative_y, int relative_x) {
    Window derived_window(this, height, width, relative_y, relative_x);
    subwindows.push_front(std::move(derived_window));
    return subwindows.front();
}
