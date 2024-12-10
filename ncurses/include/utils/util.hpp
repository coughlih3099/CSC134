/**
 * @file Utils.hpp
 *
 * @brief Header for utility functions
 */

#pragma once

#include <ncurses.h>
#include <string>
#include <vector>
#include "../core/Window.hpp"


/**
 * @brief Convert a string into a null-terminated array of chtype characters
 */
inline std::vector<chtype> string_to_chtype(const std::string& string, Window* window) {
    std::vector<chtype> ch_string;
    ch_string.reserve(string.size());
    chtype attrs = window->get_attributes();
    for (char character : string) {
        ch_string.push_back(static_cast<chtype>(character) | attrs);
    }

    ch_string.push_back(static_cast<chtype>('\0'));
    return ch_string;
}
