/**
 * @file NCursesSession.hpp
 *
 * @brief Header file for the NCursesSession class
 *
 * This class is a wrapper around ncurses initialization and teardown processes.
 * It also contains information about the ncurses instance.
 */
#pragma once

#include <ncurses.h>


class NCursesSession {
 private:
    bool initialized_correctly;
    bool utf8_enabled;
    bool echo_enabled;
    bool cbreak_enabled;
    bool has_color;
    bool can_change_colors;
    bool cursor_is_visible;
    int terminal_height;
    int terminal_width;
    int amount_of_colors;
    int amount_of_color_pairs;

 public:
    NCursesSession();
    ~NCursesSession();

    bool is_initialized() const { return initialized_correctly; }
    bool is_utf8_enabled() const { return utf8_enabled; }
    bool is_echo_enabled() const { return echo_enabled; }
    bool is_cbreak_enabled() const { return cbreak_enabled; }
    bool is_color_enabled() const { return has_color; }
    bool is_color_changeable() const { return can_change_colors; }
    bool is_cursor_visible() const { return cursor_is_visible; }
    int get_terminal_height() const { return terminal_height; }
    int get_terminal_width() const { return terminal_width; }
    void set_echo_enabled();
    void set_echo_disabled();
    void set_cbreak_enabled();
    void set_cbreak_disabled();
    void set_cursor_visible();
    void set_cursor_invisible();

    // Prevent session copying to ensure only one instance
    NCursesSession(const NCursesSession&) = delete;
    NCursesSession& operator=(const NCursesSession&) = delete;
};  // NCursesSession
