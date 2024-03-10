#pragma once

#include "flexible_array.hpp"
#include "raylib.h"
#include "GlobalDefinitions.hpp"
#include "logic.hpp"
#include "mouse_tools.hpp"

struct mouse_tools;

struct gamestate_t {
    flexible_array gridArray;
    mouse_tools* mousetools;
        
    int squareSize;         // Edge length of one (1) square
    int gridOrigin_x;       // Origin (left top corner) of rendered Grid
    int gridOrigin_y;

    int screenWidth;
    int screenHeight;

    gamestate_t();

    // Game Algorithm Handling
    bool runAlgorithm;
    void setRunAlgorithm(bool input);
    void singleStep();
    void runAlgorithmIfActive();

};
