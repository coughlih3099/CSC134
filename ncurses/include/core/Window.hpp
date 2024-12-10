/**
 * @file Window.hpp
 *
 * @brief Header file for Window wrapper class
 */
#pragma once

#include <ncurses.h>
#include <string>
#include <forward_list>
#include <memory>

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
    int cursor_y, cursor_x;
    int relative_y, relative_x;
    std::unique_ptr<WINDOW, WindowDeleter> window;
    Window* parent;
    std::forward_list<Window> subwindows;

    void update_cursor_position();  // Implementation under the class

    // Constructor for derived windows
    Window(Window* parent, int height, int width, int start_y, int start_x);

 public:
    // Constructor for root windows
    Window(int height, int width);
    Window(int height, int width, int start_y, int start_x);

    int get_delay() const { return delay; }
    int get_height() const { return height; }
    int get_width() const { return width; }
    int get_cursor_y() const { return cursor_y; }
    int get_cursor_x() const { return cursor_x; }

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
     * @brief Refreshes the window
     */
    void refresh();

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
     * @brief Moves the cursor to position y, x; 
     * puts a character at the position of the cursor and then moves the
     * cursor forward
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
    void add_char_at(chtype character, int y, int x);

    /**
     * @brief Puts a character at the position of the cursor, moves the cursor
     * forward, then refreshes the window
     * 
     * @param character Character to be put to the window
     * @throws std::runtime_error if the character won't fit onto the screen
     */
    void echo_char(chtype character);

    /**
     * @brief Copy a null-terminated character array into the window structure
     * starting at the current cursor position.
     *
     * If number_characters = -1, the whole character array will be copied up to
     * the max number of characters that fit into the current line, otherwise,
     * it will copy at most number_characters elements.
     *
     * This function does not advance the cursor and is faster than add_str
     * function, however:
     * - does not perform checking (such as for newline, backspace,
     *                              carriage return).
     * - does not expand other control character to ^-escapes.
     * - truncate the string if it crosses the right margin insteac of wrapping.
     *
     * @param string String to put to screen
     * @param number_characters The number of characters to print
     * @throws std::runtime_error if the string argument is nullptr
     */
    void add_char_str(const std::string& string, int number_characters = -1);

    /**
     * @brief Moves the cursor, then copies a null-terminated character array
     * into the window structure starting at the current cursor position.
     *
     * If number_characters = -1, the whole character array will be copied up to
     * the max number of characters that fit into the current line, otherwise,
     * it will copy at most number_characters elements.
     *
     * This function does not advance the cursor and is faster than add_str
     * function, however:
     * - does not perform checking (such as for newline, backspace,
     *                              carriage return).
     * - does not expand other control character to ^-escapes.
     * - truncate the string if it crosses the right margin insteac of wrapping.
     *
     * @param string String to put to screen
     * @param number_characters The number of characters to print
     * @param y Y position of the cursor
     * @param x X position of the cursor
     * @throws std::runtime_error if the string argument is nullptr
     * @throws std::invalid_argument if the y, x position is out of window bounds
     */
    void add_char_str_at(const std::string& string, int y, int x, int number_characters = -1);

    /**
     * @brief Writes the characters of a string to the window. Similar to
     * to calling add_char for each char in the string.
     *
     * If number_characters = -1, the whole string will be written to the window
     * otherwise, up to number_characters characters of the string will be
     * written.
     * Processes control characters.
     *
     * @param string String to write to the screen
     * @param number_characters The number of characters to print
     * @throws std::runtime_error if the string argument is a nullptr
     */
    void add_str(const std::string& string, int number_characters = -1);

    /**
     * @brief Moves the cursor, then writes the characters of a string to the
     * window. Similar to to calling move then add_char for each char in the
     * string.
     *
     * If number_characters = -1, the whole string will be written to the window
     * otherwise, up to number_characters characters of the string will be
     * written.
     * Processes control characters.
     *
     * @param string String to write to the screen.
     * @param number_characters The number of characters to print.
     * @throws std::runtime_error if the string argument is a nullptr.
     * @throws std::invalid_argument if the y/x position is out of window bounds.
     */
    void add_str_at(const std::string& string, int y, int x, int number_characters = -1);

    /**
     * @brief Gathers a key stroke from the terminal keyboard associated with
     * the window.
     *
     * When input is pending, returns an integer identifying the keystroke;
     * for alphanumeric and punctuation keys, this value corresponds to the
     * character encoding used by the terminal.
     * Use of the control key as a modifier often results in a distinct code.
     * The behavior of other keys depends on whether the window has keypad
     * enabled.
     *
     * @return int
     * - Keycode for the associated keypress.
     * - ERR: returns ERR if non-blocking input is set for the window or if
     *   there is no input after the amount of time specified in the windows
     *   delay.
     */
    int get_char();

    /**
     * @brief Moves the cursor, then gathers a key stroke from the terminal
     * keyboard associated with the window.
     *
     * When input is pending, returns an integer identifying the keystroke;
     * for alphanumeric and punctuation keys, this value corresponds to the
     * character encoding used by the terminal.
     * Use of the control key as a modifier often results in a distinct code.
     * The behavior of other keys depends on whether the window has keypad
     * enabled.
     *
     * @return int
     * - Keycode for the associated keypress.
     * - ERR: returns ERR if non-blocking input is set for the window or if
     *   there is no input after the amount of time specified in the windows
     *   delay
     * @throws std::invalid_argument if the y/x position is out of window bounds.
     */
    int get_char_at(int y, int x);

    /**
     * @brief Returns character to the input queue for the next call to get_char.
     *
     * @throws std::runtime_error if the input buffer is full
     */
    void unget_char(char character);

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


/**
 * @brief Helper function for maintaining internal cursor position
 */
inline void Window::update_cursor_position() {
    getyx(window.get(), cursor_y, cursor_x);
}
