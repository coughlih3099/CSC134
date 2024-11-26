/**
 * @file Entity.hpp
 *
 * @brief Header file for Entities
 */
#pragma once


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
