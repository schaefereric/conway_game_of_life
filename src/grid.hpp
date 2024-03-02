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

// The actual "paintbrush"
// gamestateRef.paintbrush_mode determines whether to paint or erase
void use_paintbrush(gamestate_t& gamestateRef);

// Paintbrush_mode is overwritten via parameter
void use_paintbrush(gamestate_t& gamestateRef, enum paintbrush_mode_t mode_overwrite);
