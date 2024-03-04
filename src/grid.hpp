#pragma once

#include "flexible_array.hpp"
#include "raylib.h"
#include "gamestate_t.hpp"
#include <cmath> 

// Reads array and draws the entire array on screen
void drawArrayGrid(gamestate_t& gamestate);

// Reverting the drawArrayGrid function to get coordinates of square at mouse cursor position
unsigned int getArrayXFromMousePosition(gamestate_t& gamestateRef);
unsigned int getArrayYFromMousePosition(gamestate_t& gamestateRef);


// This "Paintbrush" selects the square which is directly underneath the mouse cursor position
// It select only one Square per frame/drawcall
// gamestateRef.paintbrush_mode determines whether to paint or erase
void use_paintbrush(gamestate_t& gamestateRef);

// Paintbrush_mode is overwritten via parameter
void use_paintbrush(gamestate_t& gamestateRef, enum paintbrush_mode_t mode_overwrite);

// This Paintbrush selects a circular area around the mouse cursor position, radius is determined in gamestate
void usePaintbrushWithRadius(gamestate_t& gamestateRef);


// Helper functions for rasterizing a circle
// mx, my = Origin
// r      = Radius
// Input  = Set to 1 to fill area, Set to 0 to erase area
//
// This function only draws the outline
void fillCircle_JeskoMethod(int mx, int my, int r, int input, gamestate_t& gamestateRef);

// Fills area between two y-axis coordinates
void fillCircle_fillInBetween(int x, int y1, int y2, int input, gamestate_t& gamestateRef);
