/**
 * @file Map.cpp
 *
 * @brief Implementation of the Map class
 */
#include <string>
#include <stdexcept>
#include "../include/Map.hpp"

Map::Map(int height, int width) :
    grid_height(height),
    grid_width(width) {
    if (grid_height < 0 || grid_width < 0) {
        std::string error = "";
        if (grid_height < 0) {
            error += "height";
        }
        if (grid_width < 0) {
            if (!error.empty()) {
                error += ", ";
            }
            error += "width";
        }
        throw std::invalid_argument(error + ": can't be less than 0");
    }
}

bool Map::is_in_bounds(Position position) {
    return position.y >= 0 && position.y < grid_height &&
           position.x >= 0 && position.x < grid_width;
}

const Cell& Map::get_cell(Position position) {
    return grid[position.y][position.x];
}
