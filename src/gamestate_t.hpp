#pragma once

#include "flexible_array.hpp"
#include "raylib.h"
#include "GlobalDefinitions.hpp"
#include "logic.hpp"

struct gamestate_t {
    flexible_array gridArray;
        
    int squareSize;         // Edge length of one (1) square
    int gridOrigin_x;       // Origin (left top corner) of rendered Grid
    int gridOrigin_y;

    int screenWidth;
    int screenHeight;

    gamestate_t();

    // Mouse Input Handling
    Vector2 mousePosition;  // Last recorded mouse position (update via updateMouse();)
    bool mouse_L;           // is left mouse button pressed ? (update via updateMouse();)
    bool mouse_R;           // is right mouse button pressed ? (update via updateMouse();)
    void updateMouse();
    paintbrush_mode_t paintbrush_mode;
    int brushRadius;

    // Game Algorithm Handling
    bool runAlgorithm;
    void setRunAlgorithm(bool input);
    void singleStep();
    void runAlgorithmIfActive();

};
