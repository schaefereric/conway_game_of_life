#pragma once
#include "raylib.h"
#include "GlobalDefinitions.hpp"
#include "gamestate_t.hpp"
#include <vector>

Vector2 getMooreNeighborhoodCoordinate(int ix, int iy, moore_direction direction);

int getNumberOfNeighbors(unsigned int ix, unsigned int iy, gamestate_t & gamestateRef);

// Returns TRUE if this square lives in the next generation, or returns FALSE if this square dies in the next generation
bool decideNewStateOfSquare(unsigned int ix, unsigned int iy, gamestate_t& gamestateRef);

void applyGameRulesOnArray(gamestate_t& gamestateRef);