/**
 * @file MovementTypes.hpp
 *
 * @brief Header file for extending Movement
 */
#pragma once

#include <string>
#include "./Movement.hpp"

class Walking : public Movement {
 public:
    bool can_traverse(const Cell& cell) const override;
    std::string to_string() const override;
};
