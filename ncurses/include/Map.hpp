/**
 * @file Map.hpp
 *
 * @brief Header for map class
 */
#pragma once

#include <vector>

 /**
  * @brief Struct for Character position
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


/**
 * @brief Struct for the cells that make up the map
 */
typedef struct Cell {
    typedef enum Type {
        Floor,
        Wall
    } Type;
    Type type;
} Cell;


/**
 * @class Map
 *
 * @brief Holds information related to the map
 */
class Map {
 private:
    int grid_height;
    int grid_width;
    std::vector<std::vector<Cell>> grid;

 public:
    /**
     * @brief Constructor can throw
     */
    Map(int height, int width);

    /**
     * @brief Checks to see if a position is within bounds of the map
     */
    bool is_in_bounds(Position position);

    /**
     * @brief Returns a reference to the cell at the given position
     */
    const Cell& get_cell(Position position);
};  // Map
