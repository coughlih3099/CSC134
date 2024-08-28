/*******************************************************************************************
*
*   raylib [core] example - Basic window
*
*   Welcome to raylib!
*
*   To test examples, just press F6 and execute raylib_compile_execute script
*   Note that compiled executable is placed in the same folder as .c file
*
*   You can find all basic examples on C:\raylib\raylib\examples folder or
*   raylib official webpage: www.raylib.com
*
*   Enjoy using raylib. :)
*
*   Example originally created with raylib 1.0, last time updated with raylib 1.0
*
*   Example licensed under an unmodified zlib/libpng license, which is an OSI-certified,
*   BSD-like license that allows static linking with closed source software
*
*   Copyright (c) 2013-2023 Ramon Santamaria (@raysan5)
*
********************************************************************************************/

#include "raylib.h"

//------------------------------------------------------------------------------------
// Program main entry point
//------------------------------------------------------------------------------------
int main(void)
{
    // Initialization
    //--------------------------------------------------------------------------------------
    const int screenWidth = 1280;
    const int screenHeight = 720;

    typedef struct Ball {
        float radius;
        Vector2 position;
        Vector2 speed;
    } Ball;

    const int capacity = 5;
    Ball balls[capacity];

    /*
     * Ball zero_ball;
     * zero_ball.radius = 0.0f;
     * zero_ball.position = (Vector2) { 0.0f, 0.0f };
     * zero_ball.speed = (Vector2) { 0.0f, 0.0f };
     * for (int i = 0; i < capacity; i++) {
     *     balls[i] = zero_ball;
     * }
     */

    int amount_of_balls = 0;

    InitWindow(screenWidth, screenHeight, "M2BONUS by CoughlinH");

    SetTargetFPS(60);               // Set our game to run at 60 frames-per-second
    //--------------------------------------------------------------------------------------

    // Main game loop
    while (!WindowShouldClose())    // Detect window close button or ESC key
    {
        // Update
        //----------------------------------------------------------------------------------
        // TODO: Update your variables here
        //----------------------------------------------------------------------------------

        if (IsCursorOnScreen() && IsMouseButtonPressed(MOUSE_BUTTON_LEFT) && amount_of_balls < capacity) {
            DrawText("Click!", 10, 10, 12, YELLOW);
            balls[amount_of_balls].radius = 10.0f;
            balls[amount_of_balls].position = GetMousePosition();
            balls[amount_of_balls].speed = (Vector2) { 5.0f, 5.0f };
            amount_of_balls += 1;
            
            /* 
            * Ball anon;
            * anon.radius = 10.0f;
            * anon.position = GetMousePosition();
            * anon.speed =  (Vector2) { 5.0f, 5.0f };
            * balls[*amount_of_balls] = anon;
            * *amount_of_balls += 1; 
            */

        }

        for (int i = 0; i < amount_of_balls; i++) {
            balls[i].position.x += balls[i].speed.x;
            balls[i].position.y += balls[i].speed.y;
        }

        // Check walls collision for bouncing
        for (int i = 0; i < amount_of_balls; i++) {
            if ((balls[i].position.x >= (GetScreenWidth() - balls[i].radius)) || (balls[i].position.x <= balls[i].radius)) balls[i].speed.x *= -1.0f;
            if ((balls[i].position.y >= (GetScreenHeight() - balls[i].radius)) || (balls[i].position.y <= balls[i].radius)) balls[i].speed.y *= -1.0f;
        }

        // Draw
        //----------------------------------------------------------------------------------

        BeginDrawing();

        ClearBackground(DARKGRAY);

        for (int i = 0; i < amount_of_balls; i++) {
            DrawCircleV(balls[amount_of_balls].position, balls[amount_of_balls].radius, ORANGE);
        }

        EndDrawing();
        //----------------------------------------------------------------------------------
    }

    // De-Initialization
    //--------------------------------------------------------------------------------------
    CloseWindow();        // Close window and OpenGL context
    //--------------------------------------------------------------------------------------

    return 0;
}
