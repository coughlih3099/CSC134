/**
 * @file Character.cpp
 *
 * @brief Implementation of Entities class
 */
#include <ncurses.h>

#include "../include/Character.hpp"

Position Character::get_new_position(Direction direction) {
    Position new_position;
    switch (direction) {
        case NORTH:
            new_position = {current_position.y - 1, current_position.x };
            break;
        case EAST:
            new_position = {current_position.y, current_position.x + 1 };
            break;
        case WEST:
            new_position = {current_position.y, current_position.x - 1 };
            break;
        case SOUTH:
            new_position = {current_position.y + 1, current_position.x };
    }
    return new_position;
}

void Character::move_direction(Direction direction) {
    previous_position = current_position;
    current_position = get_new_position(direction);
}
