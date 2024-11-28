/**
 * @file Map.cpp
 *
 * @brief Implementation of the Map class
 */
#include <exception>
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
        throw std::invalid_argument("Map " + error + ": can't be less than 0");
    }
}

bool Map::is_in_bounds(Position position) const {
    return position.y >= 0 && position.y < grid_height &&
           position.x >= 0 && position.x < grid_width;
}

const Cell& Map::get_cell(Position position) const {
    return grid[position.y][position.x];
}

const std::string Map::get_cell_type(Position position) const {
    Cell cell = grid[position.y][position.x];
    std::string result;
    switch (cell.type) {
        case Cell::Floor:
            result = "floor";
            break;
        case Cell::Wall:
            result = "wall";
            break;
        default:
            result = "Why doesn't this have a type?";
            break;
    }
    return result;
}
