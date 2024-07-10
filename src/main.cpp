// main.cpp 

#define RAYGUI_IMPLEMENTATION
#define _CRT_SECURE_NO_WARNINGS

#include "../include/raygui.h"
#include "gamestate_t.hpp"
#include "grid.hpp"
#include "guimaster_t.hpp"
#include "mouse_tools.hpp"
#include "raylib.h"

// todo: brush preview auf cursor UND evntl bei bewegen des sliders preview in der mitte des grids
// fix keyboard tools
// "stamps" f-pentomino,...
// 3d?

int main()
{
    gamestate_t gamestate;
    guimaster_t guimaster(&gamestate);

    SetConfigFlags(FLAG_WINDOW_RESIZABLE);
    InitWindow(1600, 900, "Eric's Game of Life v0.0000000000000001");

    SetTargetFPS(60);    
    SetWindowMinSize(1000, 850);


    // Main game loop
    while (!WindowShouldClose())    // Detect window close button or ESC key
    {
        // Checks
        //----------------------------------------------------------------------------------

        gamestate.updateWindowSize();
        gamestate.runKeyboardActions();
        gamestate.mousetools->run();
        gamestate.runAlgorithmIfActive();
        

        // Draw
        //----------------------------------------------------------------------------------
        BeginDrawing();
        ClearBackground(RAYWHITE);


        drawArrayGrid(&gamestate);
        guimaster.draw();
        

        gamestate.endOfFrame();
        EndDrawing();
        //----------------------------------------------------------------------------------
    }


    // De-Initialization
    //--------------------------------------------------------------------------------------
    CloseWindow();        // Close window and OpenGL context
    return 0;
}

