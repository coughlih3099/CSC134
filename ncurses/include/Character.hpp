/**
 * @file Character.hpp
 *
 * @brief Header file for Entities
 */
#pragma once

#include <ncurses.h>
#include "./Map.hpp"

class Character {
 private:
    Position previous_position;
    Position current_position;
    wchar_t appearance = '@';

 public:
};  // Character
