/**
 * @file Map.hpp
 *
 * @brief Header for map class
 */
#pragma once

#include <stdexcept>
#include <vector>
#include <string>

class Map {
 private:
    typedef struct Tile {
        enum Type {
            FLOOR,
            WALL
        } Type;
        bool traversable;  // Able to be crossed
        bool occupied;  // Whether or not another entity is in the tile
    } Tile;
    int grid_height;
    int grid_width;
    std::vector<std::vector<Tile>> grid;

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
