/**
 * @file Window.cpp
 *
 * @brief Implementation of Window wrapper for NCurses
 */
#include <ncurses.h>
#include <forward_list>
#include <memory>
#include <stdexcept>
#include <string>
#include <utility>
#include <vector>
#include "../../include/core/Window.hpp"
#include "../../include/utils/util.hpp"

Window::Window(int height, int width) :
    delay(BLOCKING_INPUT),
    parent(nullptr),
    height(height),
    width(width),
    relative_y(0),
    relative_x(0) {
    window = std::unique_ptr<WINDOW, WindowDeleter>(
            newwin(height, width, relative_y, relative_x));
    if (!window) {
        throw std::runtime_error("Failed to create Window");
    }
}

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

void Window::add_char_at(chtype character, int y, int x) {
    if (y < 0 || y > this->height || x < 0 || x > this->width) {
        std::string error_message = "Cursor position out of window bounds; Position: ";
        error_message += y;
        error_message += ", ";
        error_message += x;
        throw std::invalid_argument(std::move(error_message));
    }
    auto val = mvwaddch(this->get_pointer(), y, x, character);
    if (val == ERR) {
        throw std::runtime_error("Not possible to add complete character to window.");
    }
}

void Window::echo_char(chtype character) {
    auto val = wechochar(this->get_pointer(), character);
    if (val == ERR) {
        throw std::runtime_error("Not possible to add complete character to window.");
    }
}

void Window::add_char_str(const std::string& string, int number_characters) {
    std::vector<chtype> chtype_string = string_to_chtype(string);
    auto val = waddchnstr(this->get_pointer(), chtype_string.data(), number_characters);
    if (val == ERR) {
        throw std::runtime_error("String is nullptr");
    }
}

void Window::add_char_str_at(const std::string& string, int y, int x, int number_characters) {
    std::vector<chtype> chtype_string = string_to_chtype(string);
    auto val = mvwaddchnstr(this->get_pointer(), y, x, chtype_string.data(), number_characters);
    if (val == ERR) {
        throw std::runtime_error("String is nullptr");
    }
}

void Window::add_str(const std::string& string, int number_characters) {
    auto val = waddnstr(this->get_pointer(), string.c_str(), number_characters);
    if (val == ERR) {
        throw std::runtime_error("String is nullptr");
    }
}

void Window::add_str_at(const std::string& string, int y, int x, int number_characters) {
    auto val = mvwaddnstr(this->get_pointer(), y, x, string.c_str(), number_characters);
    if (val == ERR) {
        throw std::runtime_error("String is nullptr");
    }
}

Window& Window::create_derived_window(int height, int width, int relative_y, int relative_x) {
    Window derived_window(this, height, width, relative_y, relative_x);
    subwindows.push_front(std::move(derived_window));
    return subwindows.front();
}
