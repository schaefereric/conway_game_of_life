#pragma once

#include "flexible_array.hpp"
#include "raylib.h"
#include "gamestate_class.hpp"

void drawArrayGrid(gamestate_class & gamestate) {

	
	for (unsigned int i = 1; i <= gamestate.gridArray.getSizeY(); i++) { // Column
		for (unsigned int j = 1; j <= gamestate.gridArray.getSizeX(); j++) { // Item per Column

			if (gamestate.gridArray.getItem(j - 1, i - 1) == 0) {
				DrawRectangle((gamestate.squareSize * j) + gamestate.gridOrigin_x,
							  (gamestate.squareSize * i) + gamestate.gridOrigin_y,
							   gamestate.squareSize,
							   gamestate.squareSize,
								WHITE);
			}
			
			else if (gamestate.gridArray.getItem(j - 1, i - 1) == 1) {
				DrawRectangle((gamestate.squareSize * j) + gamestate.gridOrigin_x,
							  (gamestate.squareSize * i) + gamestate.gridOrigin_y,
							   gamestate.squareSize,
							   gamestate.squareSize,
								GREEN);
			}

			DrawRectangleLines((gamestate.squareSize * j) + gamestate.gridOrigin_x,
							   (gamestate.squareSize * i) + gamestate.gridOrigin_y, 
							    gamestate.squareSize,
							    gamestate.squareSize,
								BLACK);
		}
	}
}