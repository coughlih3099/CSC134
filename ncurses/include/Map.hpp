/**
 * @file Map.hpp
 *
 * @brief Header for map class
 */
#pragma once

#include <stdexcept>
#include <vector>
#include <string>

typedef struct Cell {
    typedef enum Type {
        Floor,
        Wall
    } Type;
    Type type;
} Cell;

class Map {
 private:
    int grid_height;
    int grid_width;
    std::vector<std::vector<Cell>> grid;

 public:
    Map(int height, int width) :
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
};  // Map
