#include "gamestate_t.hpp"

gamestate_t::gamestate_t() {

    squareSize = 30;
    gridOrigin_x = 30;
    gridOrigin_y = 30;

    screenWidth = 1500;
    screenHeight = 800;

    mousePosition.x = 0; 
    mousePosition.y = 0;
    mouse_L = false;
    mouse_R = false;
}

void gamestate_t::updateMouse() {
    mousePosition = GetMousePosition();

    mouse_L = IsMouseButtonDown(0x01);
    mouse_R = IsMouseButtonDown(0x02);
}
