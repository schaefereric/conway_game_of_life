#include "mouse_tools.hpp"

mouse_tools::mouse_tools(gamestate_t* gamestateRef) {
    gamestate = gamestateRef;

    if (gamestate == NULL) {
        throw;
    }

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

tool_mode_t mouse_tools::getCurrentTool() const {
    return currentTool;
}

int mouse_tools::getBrushRadius() const {
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

    if (mouse_L) {
        unsigned int x = getArrayIndexXFromMousePosition();
        unsigned int y = getArrayIndexYFromMousePosition();

        // Return if mouse position is outside of grid
        if (x >= gamestate->gridArray.getSizeX() || y >= gamestate->gridArray.getSizeY()) {
            return;
        }

        if (brushRadius == 0) {
            gamestate->gridArray.setItem(x, y, 1);
        }

        else rasterizeCircle_JeskoMethod(x, y, brushRadius, 1, gamestate);
    }

    if (mouse_R && !(mouse_L)) {
        unsigned int x = getArrayIndexXFromMousePosition();
        unsigned int y = getArrayIndexYFromMousePosition();

        // Return if mouse position is outside of grid
        if (x >= gamestate->gridArray.getSizeX() || y >= gamestate->gridArray.getSizeY()) {
            return;
        }

        if (brushRadius == 0) {
            gamestate->gridArray.setItem(x, y, 0);
        }

        else rasterizeCircle_JeskoMethod(x, y, brushRadius, 0, gamestate);
    }
}

void mouse_tools::runEraser() {

    if (mouse_L) {
        unsigned int x = getArrayIndexXFromMousePosition();
        unsigned int y = getArrayIndexYFromMousePosition();

        // Return if mouse position is outside of grid
        if (x >= gamestate->gridArray.getSizeX() || y >= gamestate->gridArray.getSizeY()) {
            return;
        }

        if (brushRadius == 0) {
            gamestate->gridArray.setItem(x, y, 0);
        }

        else rasterizeCircle_JeskoMethod(x, y, brushRadius, 0, gamestate);
    }
}

void mouse_tools::runSpraybrush() {

    if (mouse_L) {
        unsigned int x = getArrayIndexXFromMousePosition();
        unsigned int y = getArrayIndexYFromMousePosition();
                           
        // Return if mouse position is outside of grid
        if (x >= gamestate->gridArray.getSizeX() || y >= gamestate->gridArray.getSizeY()) {
            return;        
        }

        rasterizeCircle_random(x, y, brushRadius, gamestate);
    }
}

void mouse_tools::runMoveGrid() {
    static int state = 0;
    static int previous_x = 0;
    static int previous_y = 0;

    if (mouse_L) {
        if (mousePosition.x < 415 && !(gamestate->UIHidden)) {
            return;
        }

        if (state == 0) {
            previous_x = static_cast<int> (mousePosition.x);
            previous_y = static_cast<int> (mousePosition.y);
            state = 1;
            return;
        }
        if (state == 1) {
            gamestate->gridOrigin_x -= (previous_x - static_cast<int> (mousePosition.x));
            gamestate->gridOrigin_y -= (previous_y - static_cast<int> (mousePosition.y));
            previous_x = static_cast<int> (mousePosition.x);
            previous_y = static_cast<int> (mousePosition.y);
            state = 1;
            return;

        }
    }

    if (!(mouse_L) && state == 1) {
        state = 0;
        previous_x = 0;
        previous_y = 0;
        return;
    }

    
}




unsigned int mouse_tools::getArrayIndexXFromMousePosition() const {
    float temp;

    temp = (mousePosition.x - gamestate->gridOrigin_x) / gamestate->squareSize;

    return static_cast<unsigned int> (std::floor(temp));
}

unsigned int mouse_tools::getArrayIndexYFromMousePosition() const {
    float temp;

    temp = (mousePosition.y - gamestate->gridOrigin_y) / gamestate->squareSize;

    return static_cast<unsigned int> (std::floor(temp));
}