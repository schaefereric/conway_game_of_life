#include "gamestate_t.hpp"

gamestate_t::gamestate_t() {
    mousetools = new mouse_tools(this);

    squareSize = 15;
    gridOrigin_x = 450;
    gridOrigin_y = 50;

    screenWidth = 1600;
    screenHeight = 900;

    runAlgorithm = false;

    drawRectangleOutline = false;
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
