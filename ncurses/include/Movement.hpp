/**
 * @file Movement.hpp
 *
 * @brief Interface for movement component
 */
#pragma once

#include <string>
#include "./Map.hpp"

class Movement {
 public:
    virtual ~Movement() = default;

    virtual bool can_traverse(const Cell& cell) const = 0;
    virtual std::string to_string() const = 0;
};  // Movement
