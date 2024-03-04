#pragma once

#include "flexible_array.hpp"
#include "raylib.h"
#include "gamestate_t.hpp"
#include <cmath> 
#include <chrono>
#include <random>
#include <iostream>

// Reads array and draws the entire array on screen
void drawArrayGrid(gamestate_t& gamestate);

// Reverting the drawArrayGrid function to get coordinates of square at mouse cursor position
unsigned int getArrayXFromMousePosition(gamestate_t& gamestateRef);
unsigned int getArrayYFromMousePosition(gamestate_t& gamestateRef);


// This "Paintbrush" selects the square which is directly underneath the mouse cursor position,
// which can not be more than one square at once
// It will therefore only select one Square per frame/drawcall
// gamestateRef.paintbrush_mode determines whether to "paint" or "erase"
void paintbrush_singleSquare(gamestate_t& gamestateRef);

// Paintbrush_mode is overwritten via parameter
void paintbrush_singleSquare(gamestate_t& gamestateRef, enum paintbrush_mode_t mode_overwrite);

// This Paintbrush selects a circular area around the mouse cursor position, radius is determined in gamestate
void paintbrush_circle(gamestate_t& gamestateRef);

// Paintbrush which sets the selected area to random values
void spraybrush_circle(gamestate_t& gamestateRef);

// Helper functions for rasterizing a circle
// mx, my = Origin
// r      = Radius
// Input  = Set to 1 to fill area, Set to 0 to erase area
//
// This function only draws the outline
void rasterizeCircle_JeskoMethod(int mx, int my, int r, int input, gamestate_t& gamestateRef);

// Fills area between two y-axis coordinates, only used by rasterizeCircle_JeskoMethod
void rasterizeCircle_fill_Y_Axis(int x, int y1, int y2, int input, gamestate_t& gamestateRef);

// Returns a random bool value, casted to int
int getRandomBool();

// Rasterizes a circle with random values, used for spraybrush
void rasterizeCircle_random(int mx, int my, int r, gamestate_t& gamestateRef);
