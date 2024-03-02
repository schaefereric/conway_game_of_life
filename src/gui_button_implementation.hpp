#pragma once
#include "flexible_array.hpp"
#include <string>

// -------------------------------------------------------
// 
// Debug Main
//  
// -------------------------------------------------------
void resize_array(int x, int y, flexible_array & arrayRef) {
	arrayRef.reInitialize(x, y);
}

void read_field(int x, int y, std::string& str, flexible_array& arrayRef) {

    int num = arrayRef.getItem(x, y);

    str.clear();

    if (num == 0) {
        str.insert(str.begin(), '0');
    }
    else if (num == 1) {
        str.insert(str.begin(), '1');
    }
    else {
        str.insert(str.begin(), '0');
        // todo: error output
    }
}

void set_field_true(int x, int y, flexible_array& arrayRef) {
    // set true
    arrayRef.setItem(x, y, 1);
}

void set_field_false(int x, int y, flexible_array& arrayRef) {
    // set false
    arrayRef.setItem(x, y, 0);
}

void set_square_size(int x, int& squaresizeRef) {
    squaresizeRef = x;
}

void set_grid_origin(int x, int y, gamestate_t& gamestate) {
    gamestate.gridOrigin_x = x;
    gamestate.gridOrigin_y = y;
}

// -------------------------------------------------------
// 
// Debug Mouse
//  
// -------------------------------------------------------

