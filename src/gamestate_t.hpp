#pragma once

#include "flexible_array.hpp"
#include "raylib.h"
#include "GlobalDefinitions.hpp"
#include "logic.hpp"

struct gamestate_t {
    flexible_array gridArray;

    int squareSize;
    int gridOrigin_x;
    int gridOrigin_y;

    int screenWidth;
    int screenHeight;

    gamestate_t();

    // Mouse Input Handling
    Vector2 mousePosition;
    bool mouse_L;           // is left mouse button pressed ? (update via updateMouse();)
    bool mouse_R;           // is right mouse button pressed ? (update via updateMouse();)
    void updateMouse();
    paintbrush_mode_t paintbrush_mode;

    // Game Algorithm Handling
    bool runAlgorithm;
    void setRunAlgorithm(bool input);
    void singleStep();
    void runAlgorithmIfActive();

};
