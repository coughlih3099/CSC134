/**
 * @file Character.cpp
 *
 * @brief Implementation of Entities class
 */
#include <ncurses.h>
#include <memory>
#include <string>
#include <stdexcept>
#include <utility>

#include "../../include/game/Map.hpp"
#include "../../include/game/Character.hpp"

Character::Character(int character_handle, Position starting_position,
                     const Map& map_reference, char32_t starting_appearance,
                     std::unique_ptr<Movement> move_type) :
    handle(character_handle),
    previous_position(starting_position),
    current_position(starting_position),
    map(map_reference),
    appearance(starting_appearance),
    movement_type(std::move(move_type)) {
    std::string error = "";
    if (!map.is_in_bounds(starting_position)) {
        throw std::invalid_argument("Character " + std::to_string(handle)
                                    + " starting position out of bounds.");
    }
    if (!movement_type->can_traverse(map.get_cell(starting_position))) {
        error += "Character " + std::to_string(handle) + "s movement type:";
        error += movement_type->to_string() + " can't traverse ";
        error += map.get_cell_type(starting_position);
        throw std::invalid_argument(error);
    }
}

void Character::update_positions(Position new_position) {
    previous_position = current_position;
    current_position = new_position;
}
