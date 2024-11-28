/**
 * @file Character.hpp
 *
 * @brief Header file for Entities
 */
#pragma once

#include <ncurses.h>
#include <memory>
#include "./Map.hpp"
#include "./Movement.hpp"

class Character {
 private:
    int handle;
    Position previous_position;
    Position current_position;
    char32_t appearance;
    std::unique_ptr<Movement> movement_type;
    const Map& map;

 public:
    /**
     * @brief Constructor for a Character
     *
     * @param character_handle Number associated with the character for
     *        identification purposes
     * @param starting_position The starting position for the character
     * @param map_reference Reference to the Map
     * @param starting_appearance UTF-8 character representation
     * @param move_type A unique pointer to the movement type for the character
     */
    Character(int character_handle, Position starting_position,
              const Map& map_reference, char32_t starting_appearance,
              std::unique_ptr<Movement> move_type);

    Position get_current_position() const { return current_position; }
    Position get_previous_position() const { return previous_position; }
    wchar_t get_appearance() const { return appearance; }

    /**
     * @brief Updates previous/current position
     *
     * Updates previous position to current position and current position to
     * new position 
     *
     * @param new_position Position to update current position to.
     */
    void update_positions(Position new_position);
};  // Character
