// main.cpp 

#define RAYGUI_IMPLEMENTATION
#define _CRT_SECURE_NO_WARNINGS

#include "flexible_array.hpp"
#include "gamestate_t.hpp"
#include "grid.hpp"
#include "raylib.h"
#include "raygui.h"
#include "gui_game_of_life_gui.hpp"

int main()
{
    gamestate_t gamestate;

    GuiGameOfLifeState guiState = InitGuiGameOfLife();

    gamestate.gridArray.reInitialize(15, 15);
    gamestate.gridArray.setItem(5, 5, 1);

    SetConfigFlags(FLAG_WINDOW_RESIZABLE);
    InitWindow(gamestate.screenWidth, gamestate.screenHeight, "Eric's Game of Life v0.0000000000000001");

    SetTargetFPS(60);               

    // Main game loop
    while (!WindowShouldClose())    // Detect window close button or ESC key
    {
        // Checks
        //----------------------------------------------------------------------------------




        // Draw
        //----------------------------------------------------------------------------------
        BeginDrawing();

        ClearBackground(RAYWHITE);

        drawArrayGrid(gamestate);

        GuiGameOfLife(gamestate, &guiState);

        

        

        EndDrawing();
        //----------------------------------------------------------------------------------
    }


    // De-Initialization
    //--------------------------------------------------------------------------------------
    CloseWindow();        // Close window and OpenGL context
    return 0;
}

