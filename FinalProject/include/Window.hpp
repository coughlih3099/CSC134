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
     * @brief Check if the window should keep running
     *
     * @return False if the window should stop running
     */
    bool should_keep_running();

    /**
     * @brief Check if the window has been initialized successfully
     *
     * @return True if the window has been initialized
     */
    bool is_ready();

    /**
     * @brief Check if the window is in fullscreen mode
     *
     * TODO(coughlih3099): Test if borderless fullscreen counts as fullscreen
     *
     * @return True if the window is fullscreen
     */
    bool is_fullscreen();

    /**
     * @brief Check if the window is hidden
     *
     * @return True if the window is hidden
     */
    bool is_hidden();

    /**
     * @brief Check if the window is minimized
     *
     * @return True if the window is minimized
     */
    bool is_minimized();

     /**
      * @brief Check if the window is maximized
      *
      * @return True if the window is maximized
      */
    bool is_maximized();

    /**
     * @brief Check if the window is focused
     *
     * @return True if the window is focused
     */
    bool is_focused();

    /**
     * @brief Check if the window has been resized
     *
     * Checks if the window has been resized since the last frame
     *
     * @return True if the window has been resized
     */
    bool has_been_resized();


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
     * @param width The width of the window in pixels.
     * @param heigh The height of the window in pixels.
     * @return True if the internal storage variables got updated.
     */
    bool set_size_current(int width, int height);

    /**
     * @brief Attempts to change minimum window size
     *
     * (Absolute minimum is 100x100)
     * Tries to set the minimum size for a resizable window.
     * Fails if the resizable flag isn't set or if the width and height are
     * equal to the current minimum width and height.
     *
     * @param width The minimum width of the window in pixels.
     * @param heigh The minimum height of the window in pixels.
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
     * @param width The maximum width of the window in pixels.
     * @param heigh The maximum height of the window in pixels.
     * @return true if maximum size changed else false
     */
    bool set_size_maximum(int width, int height);

    /**
     * @brief Set flags on active window
     *
     * Will set a flag or flags for the active window. Will fail if you try to
     * set FLAG_WINDOW_TRANSPARENT, FLAG_WINDOW_HIGHDPI, or FLAG_MSAA_4X_HINT,
     * as those can only be set before window creation
     *
     * @return true if success
     */
    bool set_flag(ConfigFlags flags_to_set);

    /**
     * @brief Removes state flags from window
     *
     * Depending on which overload is used, this function will remove all flags,
     * or specified flags.
     *
     * @return true if the flag has been removed
     */
    bool remove_flags();
    bool remove_flags(ConfigFlags flags_to_remove);

    /**
     * @brief Toggles fullscreen for window.
     */
    void toggle_fullscreen();

    /**
     * @brief Toggles borderless windowed mode.
     */
    void toggle_borderless();

    /**
     * @brief Minimizes window if resizable.
     */
    void minimize();

    /**
     * @brief Maximizes window if resizable.
     */
    void maximize();

    /**
     * @brief Restores window, not minimized/maximized.
     */
    void restore();

    /**
     * @brief Sets cursor visible within the window
     */
    void show_cursor();

    /**
     * @brief Sets cursor invisible within the window
     */
    void hide_cursor();

    /**
     * @brief Checks if the cursor is hidden
     *
     * @return True if the cursor is hidden
     */
    bool is_cursor_hidden();

    /**
     * @brief Enables the cursor
     */
    void enable_cursor();

    /**
     * @brief Disables the cursor
     */
    void disable_cursor();

    /**
     * @brief Checks if the cursor is in the window
     *
     * @return True if the cursor is within the window
     */
    bool is_cursor_on_screen();
};
