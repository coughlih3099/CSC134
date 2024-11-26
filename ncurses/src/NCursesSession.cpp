/**
 * @file NCursesSession.cpp
 *
 * @brief Implementation of NCursesSession.hpp
 */

#include "../include/NCursesSession.hpp"
#include <ncurses.h>
#include <locale>
#include <string>

 /**
  * @brief Checks for POSIX compliant codeset of UTF-8
  */
bool locale_is_utf8() {
    return (std::locale().name().find("UTF-8")
            != std::string::npos);
}

NCursesSession::NCursesSession() :
    initialized_correctly(false),
    utf8_enabled(false),
    echo_enabled(false),
    cbreak_enabled(false),
    has_color(false),
    can_change_colors(false),
    cursor_is_visible(false),
    terminal_height(0),
    terminal_width(0),
    amount_of_colors(0),
    amount_of_color_pairs(0) {
    // Check if initscr succeeded
    initialized_correctly = (initscr() != nullptr);

    if (initialized_correctly) {
        // Use the user's locale
        std::locale::global(std::locale(""));
        if (locale_is_utf8()) {
            utf8_enabled = true;
        }
        terminal_height = LINES;
        terminal_width = COLS;

        // Default flags
        start_color();  // Start color
        noecho();  // Don't echo keystrokes
        cbreak();  // Disable line buffering (get input immediately)
        curs_set(0);  // Hide the cursor

        has_color = has_colors();  // True if term allows colors
        can_change_colors = can_change_color();  // True if you can redefine colors
        if (has_color) {
            amount_of_colors = COLORS;
        }
        amount_of_color_pairs = COLOR_PAIRS;
    }
}

NCursesSession::~NCursesSession() {
    if (initialized_correctly) {
        endwin();
    }
}


void NCursesSession::set_cursor_visible() {
    curs_set(1);
    cursor_is_visible = true;
}

void NCursesSession::set_cursor_invisible() {
    curs_set(0);
    cursor_is_visible = false;
}
