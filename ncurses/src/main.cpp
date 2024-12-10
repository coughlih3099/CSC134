/**
 * @file Main.cpp
 *
 * @brief Main file for NCurses program demonstrating Window pointer usage
 */
#include <ncurses.h>
#include <cwchar>
#include <iostream>
#include "../include/core/NCursesSession.hpp"
#include "../include/core/Window.hpp"

// Note: We're using a raw pointer here because the Window object's lifetime
// is managed by the parent window's subwindows list
void print_menu(Window* menu_window);

int main() {
    NCursesSession session;
    if (!session.is_initialized()) {
        std::cerr << "Session didn't initialize" << std::endl;
        return 1;
    }

    try {
        Window main_window(session.get_terminal_height(),
                         session.get_terminal_width());

        int half_main_y = main_window.get_height() / 2;
        int half_main_x = main_window.get_width() / 2;

        // create_derived_window returns a reference, but we can get a pointer to it
        Window& menu_ref = main_window.create_derived_window(10, 20,
                                                           half_main_y - 5,
                                                           half_main_x - 10);
        Window* menu_window = &menu_ref;

        // Setup main window content
        main_window.add_char_str_at("Main Window", 1, half_main_x - 5);
        main_window.add_char_str_at("Press 'm' to show/hide the menu", 2,
                                   half_main_x - 13);

        main_window.set_attributes(A_REVERSE, 0);
        main_window.add_char_str_at("Press 'q' to quit",
                                   main_window.get_height() - 2,
                                   half_main_x - 8);
        main_window.set_attributes(0, 0);

        main_window.refresh();

        bool keep_running = true;
        bool menu_visible = false;

        while (keep_running) {
            int ch;

            if (menu_visible) {
                ch = menu_window->get_char();
            } else {
                ch = main_window.get_char();
            }

            switch (ch) {
                case 'm':
                    if (menu_visible) {
                        werase(menu_window->get_pointer());
                        wrefresh(menu_window->get_pointer());

                        touchwin(main_window.get_pointer());
                        main_window.refresh();
                    } else {
                        box(menu_window->get_pointer(), 0, 0);
                        print_menu(menu_window);
                        menu_window->refresh();
                    }
                    menu_visible = !menu_visible;
                    break;
                case '1':
                    if (menu_visible) {
                        // Handle option 1
                        menu_window->add_str_at("Selected Option 1!", 6, 1);
                        menu_window->refresh();
                    }
                    break;

                case '2':
                    if (menu_visible) {
                        // Handle option 2
                        menu_window->add_str_at("Selected Option 2!", 6, 1);
                        menu_window->refresh();
                    }
                    break;
                case 'q':
                    keep_running = false;
                    break;
            }
        }
    } catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
    } catch (...) {
        std::cerr << "An unknown error occurred" << std::endl;
    }
    return 0;
}

void print_menu(Window* menu_window) {
    if (!menu_window) {
        throw std::invalid_argument("Menu window pointer is null");
    }

    menu_window->add_str_at("Menu Options:", 1, 1);
    menu_window->add_str_at("1. Option One", 3, 1);
    menu_window->add_str_at("2. Option Two", 4, 1);
    menu_window->add_str_at("Press 'm' to exit",
                           menu_window->get_height() - 2, 1);
}
