// main.cpp 

#define RAYGUI_IMPLEMENTATION
#define _CRT_SECURE_NO_WARNINGS

#include "raylib.h"
#include "raygui.h"
#include "GlobalDefinitions.hpp"
#include "flexible_array.hpp"
#include "gamestate_t.hpp"
#include "grid.hpp"
#include "gui_game_of_life_gui.hpp"
#include "gui_debug_mouse.hpp"
#include "gui_debug_logic.hpp"
#include "guimaster_t.hpp"
#include "logic.hpp"
#include "mouse_tools.hpp"

int main()
{
    gamestate_t gamestate;
    guimaster_t guimaster(&gamestate);

    SetConfigFlags(FLAG_WINDOW_RESIZABLE);
    InitWindow(gamestate.screenWidth, gamestate.screenHeight, "Eric's Game of Life v0.0000000000000001");

    SetTargetFPS(60);     

    gamestate.gridArray.reInitialize(50, 50);
    gamestate.gridArray.setItem(5, 5, 1);
    gamestate.gridArray.setItem(5, 6, 2);
    gamestate.gridArray.setItem(5, 7, 3);

    // Main game loop
    while (!WindowShouldClose())    // Detect window close button or ESC key
    {
        // Checks
        //----------------------------------------------------------------------------------

        gamestate.mousetools->run();
        

        // Draw
        //----------------------------------------------------------------------------------
        BeginDrawing();
        ClearBackground(RAYWHITE);


        drawArrayGrid(gamestate);

        guimaster.draw();

        

        

        EndDrawing();
        //----------------------------------------------------------------------------------
    }


    // De-Initialization
    //--------------------------------------------------------------------------------------
    CloseWindow();        // Close window and OpenGL context
    return 0;
}

