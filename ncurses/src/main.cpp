/**
 * @file Main.cpp
 *
 * @brief Main file for NCurses program
 */
#include <exception>
#include <memory>
#include <ncurses.h>
#include <cwchar>  // Wide character support in C++
#include <iostream>
#include <stdexcept>
#include "../include/core/NCursesSession.hpp"
#include "../include/core/Window.hpp"
#include "../include/game/Map.hpp"
#include "../include/game/Character.hpp"
#include "../include/game/Movement.hpp"
#include "../include/game/MovementTypes.hpp"
#include "../include/utils/FrameTimer.hpp"


int main() {
    // Create a frametimer with a target fps of 60
    FrameTimer timer(60);

    try {
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

        const Map map(session.get_terminal_height(), session.get_terminal_width());

        // Doesn't respond to terminal resizes
        Window game_window(session.get_terminal_height(),
                           session.get_terminal_width(), 0, 0);
        // Set game window to blocking input
        game_window.set_delay(BLOCKING_INPUT);

        // Create the player character
        Character player(0, (Position) { 2, 2 }, map, L'@',
                         std::make_unique<Walking>());
        wclear(game_window.get_pointer());
        box(game_window.get_pointer(), 0, 0);
        wrefresh(game_window.get_pointer());

        // Control game loop
        bool running = true;
        while (running) {
            int ch = wgetch(game_window.get_pointer());
            Position current_position = player.get_current_position();

            switch (ch) {
                case 'w':
                    if (current_position.y > 1) {
                        player.update_positions(
                                { current_position.y - 1, current_position.x});
                        }
                    break;
                case 's':
                    if (current_position.y < session.get_terminal_height() - 2) {
                        player.update_positions(
                                { current_position.y + 1, current_position.x});
                        }
                    break;
                case 'a':
                    if (current_position.x > 1) {
                        player.update_positions(
                                { current_position.y, current_position.x - 1});
                        }
                    break;
                case 'd':
                    if (current_position.x < session.get_terminal_width() - 2) {
                        player.update_positions(
                                { current_position.y, current_position.x + 1});
                        }
                    break;
                case 'q':
                case 'Q':
                    running = false;
                    break;
            }
            mvwaddch(game_window.get_pointer(), player.get_previous_position().y,
                    player.get_previous_position().x, ' ');
            mvwaddch(game_window.get_pointer(), player.get_current_position().y,
                    player.get_current_position().x, player.get_appearance());
            wrefresh(game_window.get_pointer());
            timer.wait_for_next_frame();
        }
    }
    catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
        return 1;
    }
}
