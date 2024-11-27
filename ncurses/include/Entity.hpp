/**
 * @file Entity.hpp
 *
 * @brief Header file for Entities
 */
#pragma once

#include <ncurses.h>

 /**
  * @brief Struct for entity position
  *
  * Follows the NCurses style of y, x
  */
typedef struct Position {
    int y, x;
    // returns whether x1 == x2 && y1 == y2
    bool operator==(const Position& other) const {
        return y == other.y && x == other.x;
    }
    // returns y1 - y2, x1 - x2
    Position operator-(const Position& other) const {
        return { y - other.y, x - other.x };
    }
} Position;

// I'm not sold on having this in here
typedef enum Direction {
    NORTH,
    EAST,
    WEST,
    SOUTH
} direction;

class Entity {
 private:
    Position previous_position;
    Position current_position;
    Position get_new_position(Direction direction);
    wchar_t appearance = '@';

 public:
    Position get_position() { return current_position; }
    void move_direction(Direction direction);
};  // Entity
