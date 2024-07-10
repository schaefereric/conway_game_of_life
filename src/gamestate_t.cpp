#include "gamestate_t.hpp"
#include "mouse_tools.hpp"

gamestate_t::gamestate_t() {
    mousetools = new mouse_tools(this);

    squareSize = 15;
    gridOrigin_x = 450;
    gridOrigin_y = 50;

    windowWidth = 0;
    windowHeight = 0;

    runAlgorithm = false;

    drawRectangleOutline = false;
    drawGridOutline = true;
    drawBrushRadiusPreview = false;
    UIHidden = false;
}

void gamestate_t::setSquareSize(int input) {
    this->squareSize = input;
    if (squareSize < 1) {
        this->squareSize = 1;
    }
}

int gamestate_t::getSquareSize() {
    return this->squareSize;
}

void gamestate_t::setRunAlgorithm(bool input) {
    runAlgorithm = input;
}

void gamestate_t::singleStep() {
    applyGameRulesOnArray(&gridArray);
}

void gamestate_t::runAlgorithmIfActive() {
    if (runAlgorithm) {
        if (timer.hasTimeElapsed()) {
            applyGameRulesOnArray(&gridArray);
        }
    }
}

void gamestate_t::endOfFrame() {
    mousetools->mouseWheelZoomTriggered = false;
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

void gamestate_t::runKeyboardActions() {
    if (IsKeyDown(KEY_ONE))   mousetools->setCurrentTool(PAINT);
    if (IsKeyDown(KEY_TWO))   mousetools->setCurrentTool(SPRAY);
    if (IsKeyDown(KEY_THREE)) mousetools->setCurrentTool(ERASE);
    if (IsKeyDown(KEY_FOUR))  mousetools->setCurrentTool(MOVE_GRID);
}

void gamestate_t::updateWindowSize() {
    windowWidth = GetScreenWidth();
    windowHeight = GetScreenHeight();
}