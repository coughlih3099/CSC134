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
    if (!session.is_color_enabled()) {
        std::cerr << "This app requires the terminal to have colors" << std::endl;
    }

    // Create a frametimer with a target fps of 60
    FrameTimer timer(60);
}
