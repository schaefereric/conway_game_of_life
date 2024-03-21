#pragma once

#include "flexible_array.hpp"
#include "raylib.h"
#include "GlobalDefinitions.hpp"
#include "logic.hpp"
#include "mouse_tools.hpp"
#include "timer.hpp"

struct mouse_tools;

struct gamestate_t {
    flexible_array gridArray;
    mouse_tools* mousetools;
    Timer timer;
        
    gamestate_t();

    int squareSize;             // Edge length of one (1) square
    int gridOrigin_x;           // Origin (left top corner) of rendered Grid
    int gridOrigin_y;

    int windowWidth;
    int windowHeight;

    // Game Algorithm Handling
    bool runAlgorithm;
    void setRunAlgorithm(bool input);
    void startAlgorithm();
    void stopAlgorithm();
    void singleStep();
    void runAlgorithmIfActive();

    // Cosmetics
    bool drawRectangleOutline;
    bool drawBrushRadiusPreview;
    bool UIHidden;              // needed for gui_hidden_ui_message

    void updateWindowSize();

    // Timer
    void setDelay(int inputMilliseconds);
};
