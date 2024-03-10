#include "mouse_tools.hpp"

mouse_tools::mouse_tools(gamestate_t* gamestateRef) {
    gamestate = gamestateRef;

    mousePosition.x = 0;
    mousePosition.y = 0;
    mouse_L = false;
    mouse_R = false;

    currentTool = PAINT;
    brushRadius = 2;

}

void mouse_tools::updateMouse() {
    mousePosition = GetMousePosition();

    mouse_L = IsMouseButtonDown(0);
    mouse_R = IsMouseButtonDown(1);
}

void mouse_tools::setCurrentTool(tool_mode_t input) {
    currentTool = input;
}

void mouse_tools::setBrushRadius(int input) {
    brushRadius = input;
}

tool_mode_t mouse_tools::getCurrentTool() {
    return currentTool;
}

int mouse_tools::getBrushRadius() {
    return brushRadius;
}

void mouse_tools::run() {

    this->updateMouse();

    switch (this->currentTool)
    {
    case PAINT:
        runPaintbrush();
        break;

    case ERASE:
        runEraser();
        break;

    case SPRAY:
        runSpraybrush();
        break;

    case MOVE_GRID:
        runMoveGrid();
        break;

    default:
        break;
    }
}

void mouse_tools::runPaintbrush() {
    unsigned int x = getArrayIndexXFromMousePosition();
    unsigned int y = getArrayIndexYFromMousePosition();

    // Return if mouse position is outside of grid
    if (x >= gamestate->gridArray.getSizeX() || y >= gamestate->gridArray.getSizeY()) {
        return;
    }

    if (mouse_L) {

        if (brushRadius == 0) {
            gamestate->gridArray.setItem(x, y, 1);
        }

        else rasterizeCircle_JeskoMethod(x, y, brushRadius, 1, gamestate);
    }

    if (mouse_R && !(mouse_L)) {

        if (brushRadius == 0) {
            gamestate->gridArray.setItem(x, y, 0);
        }

        else rasterizeCircle_JeskoMethod(x, y, brushRadius, 0, gamestate);
    }
}

void mouse_tools::runEraser() {
    unsigned int x = getArrayIndexXFromMousePosition();
    unsigned int y = getArrayIndexYFromMousePosition();

    // Return if mouse position is outside of grid
    if (x >= gamestate->gridArray.getSizeX() || y >= gamestate->gridArray.getSizeY()) {
        return;
    }

    if (mouse_L) {

        if (brushRadius == 0) {
            gamestate->gridArray.setItem(x, y, 0);
        }

        else rasterizeCircle_JeskoMethod(x, y, brushRadius, 0, gamestate);
    }
}

void mouse_tools::runSpraybrush() {
    unsigned int x = getArrayIndexXFromMousePosition();
    unsigned int y = getArrayIndexYFromMousePosition();

    // Return if mouse position is outside of grid
    if (x >= gamestate->gridArray.getSizeX() || y >= gamestate->gridArray.getSizeY()) {
        return;
    }

    if (mouse_L) {
        rasterizeCircle_random(x, y, brushRadius, gamestate);
    }
}

void mouse_tools::runMoveGrid() {

}




unsigned int mouse_tools::getArrayIndexXFromMousePosition() {
    float temp;

    temp = (mousePosition.x - gamestate->gridOrigin_x) / gamestate->squareSize;

    return static_cast<unsigned int> (std::floor(temp));
}

unsigned int mouse_tools::getArrayIndexYFromMousePosition() {
    float temp;

    temp = (mousePosition.y - gamestate->gridOrigin_y) / gamestate->squareSize;

    return static_cast<unsigned int> (std::floor(temp));
}