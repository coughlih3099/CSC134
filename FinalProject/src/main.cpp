#include "raylib.h"
#include "../include/main.hpp"
#include "../include/Window.hpp"

// ----


// ----

int main() {
    // Init
    // ---

    Window window;

    if (!window.is_ready()) {
        return 42069;
    }

    SetTargetFPS(60);

    //---

    // Main Loop
    while (window.should_keep_running()) {
        // Update
        // -----

        // Draw
        // ----
        BeginDrawing();

        ClearBackground(WHITE);

        EndDrawing();
    }

    // De-Init
    // -------
    game_unload();

    return 0;
}
