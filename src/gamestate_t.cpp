#include "gamestate_t.hpp"

gamestate_t::gamestate_t() {
    mousetools = new mouse_tools(this);

    squareSize = 15;
    gridOrigin_x = 450;
    gridOrigin_y = 50;

    windowWidth = 0;
    windowHeight = 0;

    runAlgorithm = false;

    drawRectangleOutline = false;
    drawBrushRadiusPreview = false;
    UIHidden = false;
}

void gamestate_t::setRunAlgorithm(bool input) {
    runAlgorithm = input;
}

void gamestate_t::singleStep() {
    applyGameRulesOnArray_VectorMethod(&gridArray);
}

void gamestate_t::runAlgorithmIfActive() {
    if (runAlgorithm) {
        if (timer.hasTimeElapsed()) {
            applyGameRulesOnArray_VectorMethod(&gridArray);
        }
    }
}

void gamestate_t::startAlgorithm() {
    setRunAlgorithm(true);
    timer.start();
}

void gamestate_t::stopAlgorithm() {
    setRunAlgorithm(false);
    timer.stop();
}

void gamestate_t::setDelay(int inputMilliseconds) {
    timer.setDelay(inputMilliseconds);
}

void gamestate_t::updateWindowSize() {
    windowWidth = GetScreenWidth();
    windowHeight = GetScreenHeight();
}