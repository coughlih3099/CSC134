/**
 * @file Window.hpp
 *
 * @brief Header file for Window wrapper class
 */
#pragma once

#include <ncurses.h>
#include <memory>
#include <forward_list>

#define BLOCKING_INPUT -1
#define NONBLOCKING_INPUT 0

struct WindowDeleter {
    void operator()(WINDOW* window) {
        if (window) delwin(window);
    }
};

/**
 * @class Window
 *
 * @brief Wrapper class for NCurses Windows
 *
 * This is a RAII implementation of NCurses Windows that seeks to simplify the
 * usage of Windows and implement some memory safety features that are available
 * in more modern C++.
 * The window is essentially created with a Singleton pattern provided by the
 * use of unique pointers and contains a non-default destructor.
 * The Window class allows the creation of derived windows that must be accessed
 * by reference as they are owned by the parent window and thus their lifetimes
 * are tied to and managed by the parent window.
 */
class Window {
 private:
    int delay;
    int height, width;
    std::unique_ptr<WINDOW, WindowDeleter> window;
    Window* parent;
    std::forward_list<Window> subwindows;
    int relative_y, relative_x;
    // Constructor for derived windows
    Window(Window* parent, int height, int width, int start_y, int start_x);

 public:
    // Constructor for root windows
    Window(int height, int width, int start_y, int start_x);

    /**
     * @brief Sets (non)blocking read for the window.
     *
     * Two macros are provided, BLOCKING_INPUT and NONBLOCKING_INPUT
     * If delay_in_milliseconds < 0, blocking read.
     * If delay_in_milliseconds == 0, non-blocking read.
     * If delay_in_milliseconds > 0, the read is blocked for set time.
     * 
     * @param delay_in_milliseconds The delay to block for in milliseconds
     */
    void set_delay(int delay_in_milliseconds);
    int get_delay() const { return delay; }
    int get_height() const { return height; }
    int get_width() const { return width; }

    /**
     * @brief Moves the cursor to the specified position.
     *
     * This function moves the cursor to the specified position within the
     * window. If the position is outside the bounds of the window, it will fail.
     *
     * @param y Y position to move the cursor to.
     * @param x X position to move the cursor to.
     * @throws std::invalid_argument if position is outside the bounds of the window.
     */
    void move_cursor(int y, int x);

    /**
     * @brief Puts a character at the position of the cursor and then moves
     * the cursor forward
     *
     * If this function is called at the right margin of the window, the cursor
     * will wrap to the next line.
     * Any tab, backspace, or newline will appropriately move the cursor.
     * Will require a refresh to show the character.
     *
     * @param character Character to be put to the screen.
     * @throws std::runtime_error if the character won't fit onto the screen
     */
    void add_char(chtype character);

    /**
     * @brief Moves the cursor to position y, x; puts a character at the position of the
     * cursor and then moves the cursor forward
     * 
     * If this function is called at the right margin of the window, the cursor
     * will wrap to the next line.
     * Any tab, backspace, or newline will appropriately move the cursor.
     * Will require a refresh to show the character.
     * 
     * @param character Character to be put to the window
     * @param y Y position of the cursor
     * @param x X position of the cursor
     * @throws std::runtime_error if the character won't fit onto the screen
     * @throws std::invalid_argument if the y, x position is out of window bounds
     */
    void move_add_char(chtype character, int y, int x);

    /**
     * @brief Puts a character at the position of the cursor, moves the cursor forward, then
     * refreshes the window
     * 
     * @param character Character to be put to the window
     * @throws std::runtime_error if the character won't fit onto the screen
     */
    void echo_char(chtype character);

    /**
     * @brief Returns a reference to the created derived window.
     *
     * This method ensures derived windows are properly created and managed by
     * the parent.
     * The relative y/x relates to the top-left corner of the derived window.
     *
     * @param height Height of the derived window.
     * @param width Width of the derived window.
     * @param relative_y Y position relative to the parent window.
     * @param relative_x X position relative to the parent window.
     * @return Reference to the newly created derived window.
     */
    Window& create_derived_window(int height, int width, int relative_y, int relative_x);

    // Get the raw pointer
    WINDOW* get_pointer() { return window.get(); }
    const WINDOW* get_pointer() const { return window.get(); }

    // Prevent copying
    Window(const Window&) = delete;
    Window& operator=(const Window&) = delete;

    // Allow moving
    Window(Window&&) = default;
    Window& operator=(Window&&) = default;
};  // Window
