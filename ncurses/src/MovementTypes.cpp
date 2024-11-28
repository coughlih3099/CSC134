/**
 * @file MovementTypes.cpp
 *
 * @brief Concrete implementations of Movement
 */
#include <string>
#include "../include/MovementTypes.hpp"

bool Walking::can_traverse(const Cell& cell) const {
    return cell.type == Cell::Floor;
}

std::string Walking::to_string() const {
    return "walking";
}
