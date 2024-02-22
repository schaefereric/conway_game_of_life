#pragma once

#include "flexible_array.hpp"
#include "raylib.h"


struct gamestate_t {
    flexible_array gridArray;

    int squareSize;
    int gridOrigin_x;
    int gridOrigin_y;

    int screenWidth;
    int screenHeight;

    Vector2 mousePosition;
    bool mouse_L;           // is left mouse button pressed ? (update via updateMouse();)
    bool mouse_R;           // is right mouse button pressed ? (update via updateMouse();)

    gamestate_t();

    void updateMouse();

};
