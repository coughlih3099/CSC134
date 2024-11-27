/**
 * @file Main.cpp
 *
 * @brief Main file for NCurses program
 */
#include <ncurses.h>
#include <cwchar>  // Wide character support in C++
#include <iostream>
#include "../include/NCursesSession.hpp"
#include "../include/Window.hpp"
#include "../include/FrameTimer.hpp"

const int BLOCKING_INPUT = -1;
const int NONBLOCKING_INPUT = 0;


int main() {
    // Initiate the NCurses Session
    NCursesSession session;

    if (!session.is_initialized()) {
        std::cerr << "NCurses Session didn't initialize correctly" << std::endl;
        return 69;
    }
    if (!session.is_utf8_enabled()) {
        std::cerr << "This app needs UTF-8 enabled" << std::endl;
        return 420;
    }

    // Create a frametimer with a target fps of 60
    FrameTimer timer(60);

    try {
        // Doesn't respond to terminal resizes
        Window game_window(session.get_terminal_height(),
                           session.get_terminal_width(), 0, 0);
        // Set game window to blocking input
        game_window.set_delay(BLOCKING_INPUT);

        // Control game loop
        bool running = true;
        while (running) {
            timer.wait_for_next_frame();
        }
    }
    catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
        return 1;
    }
}
