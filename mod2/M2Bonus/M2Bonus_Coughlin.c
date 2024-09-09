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
*   Example originally created with raylib 1.0f, last time updated with raylib 1.0f
*
*   Example licensed under an unmodified zlib/libpng license, which is an OSI-certified,
*   BSD-like license that allows static linking with closed source software
*
*   Copyright (c) 2013-2023 Ramon Santamaria (@raysan5)
*
********************************************************************************************/

#include "raylib.h"
#include "stdbool.h"
#include "math.h"
#include "stdlib.h"

//------------------------------------------------------------------------------------
// Program main entry point
//------------------------------------------------------------------------------------
int main(void)
{
    // Initialization
    //--------------------------------------------------------------------------------------

    typedef struct BALL {
        bool attached;
        bool can_collide;
        Vector2 position;
        Vector2 speed;
        float radius;
        Color color;
    } BALL;

    typedef struct BLOCK {
        Rectangle rectangle;
        Color color;
    } BLOCK;

    const int screen_width = 800;
    const int screen_height = 600;

    SetRandomSeed(rand());

    const int paddle_width = 70; 
    const int paddle_height = 15;
    Rectangle paddle = { screen_width / 2.0f - paddle_width / 2.0f, screen_height - screen_height / 5.0f, paddle_width, paddle_height };
    float paddle_speed = 10.0f;

    BALL ball;
    ball.attached = true;
    ball.can_collide = false;
    ball.speed = (Vector2) { 0.0f, 0.0f };
    ball.radius = 10.0f;
    ball.color = ORANGE;
    ball.position = (Vector2) { paddle.x + paddle.width / 2.0, paddle.y - paddle.height + ball.radius / 2.0f - 1 };
    int ball_rand;

    const int blocks_x_cap = 12;
    const int blocks_y_cap = 15;

    BLOCK alive_blocks[blocks_x_cap][blocks_y_cap];
    float block_width = screen_width / (float) blocks_y_cap;
    int block_height = 15;
    int block_pos_x = 0;
    int block_pos_y = 0;
    for (int x = 0; x < blocks_x_cap; x++) {
        for (int y = 0; y < blocks_y_cap; y++) {
            alive_blocks[x][y].rectangle = (Rectangle) { block_pos_x + y * block_width, block_pos_y + x * block_height, block_width, block_height };
            alive_blocks[x][y].color = (Color) { GetRandomValue(1, 255), GetRandomValue(1, 255), GetRandomValue(1, 255), 255 };
        }
    }

    Rectangle reset = { 0, screen_height - screen_height / 6.0f, screen_width, screen_height - screen_height / 6.0f };

    InitWindow(screen_width, screen_height, "Brick Brake by Harley Coughlin");

    SetTargetFPS(60);               // Set our game to run at 60 frames-per-second
    //--------------------------------------------------------------------------------------

    // Main game loop
    while (!WindowShouldClose())    // Detect window close button or ESC key
    {
        // Update
        //----------------------------------------------------------------------------------
        // TODO: Update your variables here
        //----------------------------------------------------------------------------------

        if (IsKeyDown(KEY_A) && (paddle.x > 0)) {
            paddle.x -= paddle_speed;
        }
        if (IsKeyDown(KEY_D) && (paddle.x + paddle.width < screen_width)) {
            paddle.x += paddle_speed;
        }
        if (ball.attached) {
            ball.position.x = paddle.x + paddle_width / 2.0f;
        }

        if (IsKeyPressed(KEY_SPACE) && ball.attached) {
            ball.speed.x -= 4.0f;
            ball.speed.y -= 4.0f;
            ball.attached = false;
            ball.can_collide = true;
        }

        ball.position.x += ball.speed.x;
        ball.position.y += ball.speed.y;
        if (ball.position.x - ball.radius <= 0 || ball.position.x + ball.radius >= screen_width) {
            ball.speed.x *= -1;
        }
        if (ball.position.y - ball.radius <= 0 || ball.position.y + ball.radius >= screen_height) {
            ball.speed.y *= -1;
        }

        // paddle collision
        ball_rand = GetRandomValue(0, 10);
        if (CheckCollisionCircleRec(ball.position, ball.radius, paddle) && ball.can_collide) {
            if (fabs(ball.speed.x) > 5.0f || fabs(ball.speed.x) < 3.0f) {
                if (ball.speed.x < 0) {
                    ball.speed.x = -4.0f;
                } else {
                    ball.speed.x = 4.0f;
                } 
            } else {
                if ((ball_rand & 1) == 0) {
                    ball.speed.x += ball_rand / 10.0;
                    ball.speed.x *= -1;
                } else {
                    ball.speed.x -= ball_rand / 10.0;
                }
            }
            ball.speed.y *= -1;
        }

        // blocks collision
        for (int x = 0; x < blocks_x_cap; x++) {
            for (int y = 0; y < blocks_y_cap; y++) {
                if (CheckCollisionCircleRec(ball.position, ball.radius, alive_blocks[x][y].rectangle)) {
                    if (fabs(ball.speed.x) > 5.0f || fabs(ball.speed.x) < 3.0f) {
                        if (ball.speed.x < 0) {
                            ball.speed.x = -4.0f;
                        } else {
                            ball.speed.x = 4.0f;
                        } 
                    } else {
                        if ((ball_rand & 1) == 0) {
                            ball.speed.x += ball_rand / 10.0;
                            ball.speed.x *= -1;
                        } else {
                            ball.speed.x -= ball_rand / 10.0;
                        }
                    }
                    ball.speed.y *= -1;
                    // "remove the block"
                    alive_blocks[x][y].rectangle = (Rectangle) { 0, 0, 0, 0 };
                }
            }
        }

        // reset collision
        if (CheckCollisionCircleRec(ball.position, ball.radius, reset)) {
            ball.can_collide = false;
            ball.position = (Vector2) { paddle.x + paddle.width / 2.0, paddle.y - paddle.height + ball.radius / 2.0f - 2 };
            ball.speed = (Vector2) { 0.0f, 0.0f };
            ball.attached = true;
        }

        // Draw
        //----------------------------------------------------------------------------------
        BeginDrawing();
        
        ClearBackground(DARKGRAY);

        for (int x = 0; x < blocks_x_cap; x++) {
            for (int y = 0; y < blocks_y_cap; y++) {
                DrawRectangleRec(alive_blocks[x][y].rectangle, alive_blocks[x][y].color);
            }
        }

        DrawRectangleRec(paddle, RED);
        DrawRectangleRec(reset, (Color) { 255, 0, 0, 127 });

        if (ball.attached) {
            DrawText("Press SPACE to launch ball", screen_width / 2.0f - 100, screen_height - screen_height / 6.0f, 20, YELLOW);
        }

        DrawCircleV(ball.position, ball.radius, ball.color);

        EndDrawing();
        //----------------------------------------------------------------------------------
    }

    // De-Initialization
    //--------------------------------------------------------------------------------------
    CloseWindow();        // Close window and OpenGL context
    //--------------------------------------------------------------------------------------

    return 0;
}
