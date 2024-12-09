/**
 * @file Utils.hpp
 *
 * @brief Header for utility functions
 */

#pragma once

#include <ncurses.h>
#include <string>
#include <vector>


/**
 * @brief Convert a string into a null-terminated array of chtype characters
 */
inline std::vector<chtype> string_to_chtype(const std::string& string) {
    std::vector<chtype> ch_string;
    ch_string.reserve(string.size());
    for (char character : string) {
        ch_string.push_back(static_cast<chtype>(character));
    }
    ch_string.push_back(static_cast<chtype>('\0'));
    return ch_string;
}
