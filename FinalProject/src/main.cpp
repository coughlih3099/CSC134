#include "raylib.h"
#include "../include/main.hpp"

// ----


// ----

int main() {
    // Init
    // ---
    const int SCREEN_WIDTH = 1280;
    const int SCREEN_HEIGHT = 720;

    InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "Window");
    SetTargetFPS(60);

    if (IsWindowReady()) {
        game_launch();
    } else {
        TraceLog(LOG_FATAL, "Window was not initialized");
        return 42069;
    }
    //---

    // Main Loop
    while (!WindowShouldClose()) {
        // Update
        // -----
        game_update();
        // Draw
        // ----
        BeginDrawing();

        game_render();

        EndDrawing();
    }

    // De-Init
    // -------
    game_unload();

    CloseWindow();
    return 0;
}


// Initialize the game systems
void game_launch() {
}


// Process the game logic
void game_update() {
}


// Draw the current frame
void game_render() {
}


// Clean up and shutdown
void game_unload() {
}
