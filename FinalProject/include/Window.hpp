/**
 * @file Window.hpp
 *
 * @brief Window class header.
 */

#pragma once

#include <raylib.h>
#include <string>
#include <vector>

 /**
  * @class Window
  *
  * @brief Wrapper class for Raylib window.
  */
class Window {
 private:
    int size_current_width = 1280;
    int size_current_height = 720;
    int size_minimum_width = 100;
    int size_minimum_height = 100;
    int size_maximum_width = 7680;  /**< 8K resolution */
    int size_maximum_height = 4320;  /**< 8K resolution */
    ConfigFlags flags = static_cast<ConfigFlags>(0);
    bool is_test_mode;
    std::string title = "Raylib Window";

 public:
    explicit Window(bool is_test_mode = false);
    Window(int size_width, int size_height, std::string initial_title,
           bool is_test_mode = false);
    Window(int size_width, int size_height, ConfigFlags flags,
           std::string initial_title, bool is_test_mode = false);
    ~Window();

    int get_current_width()     const { return size_current_width; }
    int get_current_height()    const { return size_current_height; }
    int get_minimum_width()     const { return size_minimum_width; }
    int get_minimum_height()    const { return size_minimum_height; }
    int get_maximum_width()     const { return size_maximum_width; }
    int get_maximum_height()    const { return size_maximum_height; }
    // Trivial accessor for `title`.
    std::string get_title()     const { return title; }
    ConfigFlags get_flags()     const { return flags; }


    /**
     * @brief Gets string representations of enabled flags.
     *
     *  Searches through all available flags to see which are enabled
     *
     *  @return A vector of string representations of the enabled flags
     */
    std::vector<std::string> get_enabled_flags();


    /**
     * @brief Sets the window size.
     *
     * Sets the window size to width by height. Fails if the width and height
     * are equal to the current width and height.
     *
     * @return True if the internal storage variables got updated.
     */
    bool set_size_current(int width, int height);

    /**
     * @brief Attempts to change minimum window size
     *
     * (Default minimum is 100x100)
     * Tries to set the minimum size for a resizable window.
     * Fails if the resizable flag isn't set or if the width and height are
     * equal to the current minimum width and height.
     *
     * @return true if minimum size changed else false
     */
    bool set_size_minimum(int width, int height);

    /**
     * @brief Attempts to change maximum window size
     *
     * (Default is 7680x4320, 8k resolution)
     * Tries to set the maximum size for a resizable window.
     * Fails if the resizable flag isn't set or if the width and height are
     * equal to the current maximum width and height
     *
     * @return true if maximum size changed else false
     */
    bool set_size_maximum(int width, int height);
};
