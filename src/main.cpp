// main.cpp 

#define RAYGUI_IMPLEMENTATION
#define _CRT_SECURE_NO_WARNINGS

#include "raylib.h"
#include "raygui.h"
#include "GlobalDefinitions.hpp"
#include "flexible_array.hpp"
#include "gamestate_t.hpp"
#include "grid.hpp"
#include "gui_main_window.hpp"
#include "gui_debug_main.hpp"
#include "gui_debug_mouse.hpp"
#include "gui_debug_logic.hpp"
#include "gui_hidden_ui_message.hpp"
#include "guimaster_t.hpp"
#include "logic.hpp"
#include "mouse_tools.hpp"

// todo: brush preview auf cursor UND evntl bei bewegen des sliders preview in der mitte des grids
// grid outline? (also richtige outline)

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
        gamestate.mousetools->run();
        gamestate.runAlgorithmIfActive();
        

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

