#pragma once
#include "../include/raylib.h"
#include "GlobalDefinitions.hpp"
#include "flexible_array.hpp"
#include <vector>

// Enter coordinate and moore direction -> returns coordinate of given direction
Vector2 getMooreNeighborhoodCoordinate(int ix, int iy, moore_direction direction);

// counts all neighbors of coordinate in moore neighborhood
int getNumberOfNeighbors(unsigned int ix, unsigned int iy, flexible_array* arrayRef);

// Returns TRUE if this square lives in the next generation, or returns FALSE if this square dies in the next generation
bool decideNewStateOfSquare(unsigned int ix, unsigned int iy, flexible_array* arrayRef);

// This function applys the game rules on the gridArray ONCE!
// This function needs to be optimized in the future
void applyGameRulesOnArray(flexible_array* arrayRef);
