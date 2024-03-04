#include "gamestate_t.hpp"

gamestate_t::gamestate_t() {

    squareSize = 15;
    gridOrigin_x = 30;
    gridOrigin_y = 30;

    screenWidth = 1500;
    screenHeight = 800;

    mousePosition.x = 0; 
    mousePosition.y = 0;
    mouse_L = false;
    mouse_R = false;

    paintbrush_mode = PAINT;
    brushRadius = 2;

    runAlgorithm = false;
}

void gamestate_t::updateMouse() {
    mousePosition = GetMousePosition();

    mouse_L = IsMouseButtonDown(0);
    mouse_R = IsMouseButtonDown(1);
}

void gamestate_t::setRunAlgorithm(bool input) {
    runAlgorithm = input;
}

void gamestate_t::singleStep() {
    applyGameRulesOnArray_VectorMethod(&gridArray);
}

void gamestate_t::runAlgorithmIfActive() {
    if (runAlgorithm) {
        applyGameRulesOnArray_VectorMethod(&gridArray);
    }
}
