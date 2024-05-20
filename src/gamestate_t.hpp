#pragma once

#include "flexible_array.hpp"
#include "raylib.h"
#include "GlobalDefinitions.hpp"
#include "logic.hpp"
#include "mouse_tools.hpp"
#include "timer.hpp"

struct mouse_tools;

struct gamestate_t {
    flexible_array gridArray;         // 2D Array
    mouse_tools* mousetools;          // Mouse tools (brush etc.), also grabs mouse input
    Timer timer;                      // Timer for game algorithm
            
    gamestate_t();

    int squareSize;                   // Edge length of one (1) square
    int gridOrigin_x;                 // Origin (left top corner) of rendered Grid
    int gridOrigin_y;

    void setSquareSize(int input);
    int getSquareSize();

    int windowWidth;
    int windowHeight;

    // todo: cleanup, public/private

    // Game Algorithm Handling
    bool runAlgorithm;
    void setRunAlgorithm(bool input); // Setter function for runAlgorithm attribute. Does NOT affect timer!
    void startAlgorithm();            // Invokes setter function AND starts timer
    void stopAlgorithm();             // Invokes setter function AND stops timer
    void singleStep();                // Applys game rules on array once
    void runAlgorithmIfActive();      // If runAlgorithm == true AND timer has elapsed, game rules are applied

    // End of Frame Cleanup function
    void endOfFrame();

    // Cosmetics
    bool drawRectangleOutline;
    bool drawGridOutline;
    bool drawBrushRadiusPreview;
    bool UIHidden;                    // needed for gui_hidden_ui_message

    void updateWindowSize();

    // Timer
    void setDelay(int inputMilliseconds);

    // Keyboard Input
    void runKeyboardActions();

private:


};
