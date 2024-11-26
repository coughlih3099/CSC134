#include <ncurses.h>
#include <cwchar>  // Wide character support in C++
#include <iostream>
#include <chrono>
#include <thread>
#include "../include/NCursesSession.hpp"
#include "../include/Window.hpp"

typedef struct Player {
    int y = 2, x = 2;
    char appearance = '@';
} player;

void draw_background(WINDOW* window);
void draw_player(WINDOW* window, const Player& player);

// Helper function to determine if a position should have a dot
bool should_have_dot(int y, int x) {
    return (y + x) % 7 == 0;
}

class FrameTimer {
 private:
    std::chrono::microseconds frame_duration;
    std::chrono::steady_clock::time_point last_frame;

 public:
    explicit FrameTimer(int target_fps)
        : frame_duration(std::chrono::microseconds(1000000 / target_fps))
        , last_frame(std::chrono::steady_clock::now()) {}

    void wait_for_next_frame() {
        auto now = std::chrono::steady_clock::now();
        auto elapsed = now - last_frame;

        if (elapsed < frame_duration) {
            std::this_thread::sleep_for(frame_duration - elapsed);
        }

        last_frame = std::chrono::steady_clock::now();
    }
};

int main() {
    // RAII class for session management
    NCursesSession session;

    if (!session.is_initialized()) {
        std::cerr << "The session did not initialize" << std::endl;
        return 69;
    }

    if (!session.is_utf8_enabled()) {
        std::cerr << "This program requires UTF-8 support" << std::endl;
        return 420;
    }

    if (!session.is_color_enabled()) {
        std::cerr << "This program requires terminal color support" << std::endl;
        return 69420;
    }

    try {
        Window game_window(LINES, COLS, 0, 0);
        // nodelay(game_window.get_pointer(), TRUE);
        // keypad(game_window.get_pointer(), TRUE);

        uint64_t frameCounter = 0;
        Player player;
        bool running = true;

        FrameTimer timer(60);

        // Initial draw of background (only done once)
        draw_background(game_window.get_pointer());
        draw_player(game_window.get_pointer(), player);
        wrefresh(game_window.get_pointer());

        while (running) {
            int ch = wgetch(game_window.get_pointer());

            if (ch != ERR) {  // Only process if we got input
                // Store old position
                int old_y = player.y;
                int old_x = player.x;

                switch (ch) {
                    case 'w':
                        if (player.y > 1) player.y--;
                        break;
                    case 's':
                        if (player.y < LINES - 2) player.y++;
                        break;
                    case 'a':
                        if (player.x > 1) player.x--;
                        break;
                    case 'd':
                        if (player.x < COLS - 2) player.x++;
                        break;
                    case 'q':
                    case 'Q':
                        running = false;
                        break;
                }

                // Only update if position changed
                if (old_y != player.y || old_x != player.x) {
                    // Restore the old position with either a dot or space
                    mvwaddch(game_window.get_pointer(), old_y, old_x,
                            should_have_dot(old_y, old_x) ? '.' : ' ');

                    // Draw player at new position
                    mvwaddch(game_window.get_pointer(), player.y, player.x, player.appearance);
                    mvwprintw(game_window.get_pointer(), 25, 30, "Cols: %d; Lines: %d", session.get_terminal_width(), session.get_terminal_height());
                    mvwprintw(game_window.get_pointer(), 30, 30, "Cols: %d; Lines: %d", COLS, LINES);
                    wrefresh(game_window.get_pointer());
                }
            }
            mvwprintw(game_window.get_pointer(), 10, 10, "Frame %lu", frameCounter);
            frameCounter++;
            timer.wait_for_next_frame();
        }
    }
    catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
        return 1;
    }
    return 0;
}

void draw_background(WINDOW* window) {
    int maxy, maxx;
    getmaxyx(window, maxy, maxx);
    box(window, 0, 0);

    for (int i = 1; i < maxy - 1; i++) {
        for (int j = 1; j < maxx - 1; j++) {
            if (should_have_dot(i, j)) {
                mvwaddch(window, i, j, '.');
            }
        }
    }
}

void draw_player(WINDOW* window, const Player& player) {
    mvwaddch(window, player.y, player.x, player.appearance);
}
