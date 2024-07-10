#pragma once

#include "flexible_array.hpp"
#include "raylib.h"
#include "gamestate_t.hpp"
#include <cmath> 
#include <chrono>
#include <random>
#include <iostream>

struct gamestate_t;

// Reads array and draws the entire array on screen
void drawArrayGrid(gamestate_t* gamestate);


// Helper functions for rasterizing a circle
// mx, my = Origin
// r      = Radius
// Input  = Set to 1 to fill area, Set to 0 to erase area
//
// This function only draws the outline
void rasterizeCircle_JeskoMethod(int mx, int my, int r, int input, gamestate_t* gamestateRef);

// Fills area between two y-axis coordinates, only used by rasterizeCircle_JeskoMethod
void rasterizeCircle_fill_Y_Axis(int x, int y1, int y2, int input, gamestate_t* gamestateRef);

// Returns a random bool value, casted to int
int getRandomBool();

// Rasterizes a circle with random values, used for spraybrush
void rasterizeCircle_random(int mx, int my, int r, gamestate_t* gamestateRef);

void shuffleGrid(gamestate_t* gamestateRef);
