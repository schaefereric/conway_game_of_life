#pragma once
#include "raylib.h"
#include "GlobalDefinitions.hpp"
#include "flexible_array.hpp"

Vector2 getMooreNeighborhoodCoordinate(int ix, int iy, moore_direction direction);

int getNumberOfNeighbors(unsigned int ix, unsigned int iy, flexible_array* arrayRef);

// Returns TRUE if this square lives in the next generation, or returns FALSE if this square dies in the next generation
bool decideNewStateOfSquare(unsigned int ix, unsigned int iy, flexible_array* arrayRef);

// Applies the game rules on the gridArray ONCE!
void applyGameRulesOnArray(flexible_array* arrayRef);