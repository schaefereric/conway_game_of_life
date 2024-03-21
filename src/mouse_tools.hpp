#pragma once
#include "grid.hpp"

struct gamestate_t;

struct mouse_tools {

    mouse_tools(gamestate_t* gamestateRef);

    void run();

    gamestate_t* gamestate;

    // Mouse Input 
    Vector2 mousePosition;  // Last recorded mouse position    (update via updateMouse();)
    bool mouse_L;           // is left  mouse button pressed ? (update via updateMouse();)
    bool mouse_R;           // is right mouse button pressed ? (update via updateMouse();)
    void updateMouse();
    


    void setCurrentTool(tool_mode_t input);
    void setBrushRadius(int input);

    tool_mode_t getCurrentTool() const;
    int getBrushRadius() const;

private:

    // Brush Settings
    tool_mode_t currentTool;
    unsigned int brushRadius;

    // Wrapper Functions for calling tool functions
    void runPaintbrush();
    void runEraser();
    void runSpraybrush();
    void runMoveGrid();

    // Reverting the drawArrayGrid function (grid.hpp) to get array index of square at mouse cursor position
    unsigned int getArrayIndexXFromMousePosition() const;
    unsigned int getArrayIndexYFromMousePosition() const;
};

