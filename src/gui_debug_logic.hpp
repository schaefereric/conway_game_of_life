/*******************************************************************************************
*
*   DebugLogic v1.0.0 - user interface
*
*   MODULE USAGE:
*       #define GUI_DEBUG_LOGIC_IMPLEMENTATION
*       #include "gui_debug_logic.h"
*
*       INIT: GuiDebugLogicState state = InitGuiDebugLogic();
*       DRAW: GuiDebugLogic(&state);
*
*   LICENSE: Propietary License
*
*   Copyright (c) 2022 schaefereric. All Rights Reserved.
*
*   Unauthorized copying of this file, via any medium is strictly prohibited
*   This project is proprietary and confidential unless the owner allows
*   usage in any other form by expresely written permission.
*
**********************************************************************************************/
#pragma once

#include "raylib.h"

// WARNING: raygui implementation is expected to be defined before including this header
#undef RAYGUI_IMPLEMENTATION
#include "raygui.h"

#include <string.h>     // Required for: strcpy()

#include "gui_structs.hpp"
#include "gui_button_implementation.hpp"
#include "gamestate_t.hpp"
#include "logic.hpp"



    //----------------------------------------------------------------------------------
    // Defines and Macros
    //----------------------------------------------------------------------------------
    //...

    //----------------------------------------------------------------------------------
    // Types and Structures Definition
    //----------------------------------------------------------------------------------
    // ...

    //----------------------------------------------------------------------------------
    // Module Functions Declaration
    //----------------------------------------------------------------------------------
    GuiDebugLogicState InitGuiDebugLogic(void);
    void GuiDebugLogic(gamestate_t* gamestate, GuiDebugLogicState* state);
    static void Button005(GuiDebugLogicState* state);
    static void Button012(GuiDebugLogicState* state, gamestate_t* gamestateRef);
    static void Button016(GuiDebugLogicState* state, gamestate_t* gamestateRef);



/***********************************************************************************
*
*   GUI_DEBUG_LOGIC IMPLEMENTATION
*
************************************************************************************/

#include "raygui.h"

//----------------------------------------------------------------------------------
// Global Variables Definition
//----------------------------------------------------------------------------------
//...

//----------------------------------------------------------------------------------
// Internal Module Functions Definition
//----------------------------------------------------------------------------------
//...

//----------------------------------------------------------------------------------
// Module Functions Definition
//----------------------------------------------------------------------------------
GuiDebugLogicState InitGuiDebugLogic(void)
{
    GuiDebugLogicState state = { 0 };

    state.anchor01 = { 728, 73 };

    state.WindowBox000Active = true;
    state.Spinner002EditMode = false;
    state.Spinner002Value = 0;
    state.Spinner003EditMode = false;
    state.Spinner003Value = 0;
    state.DropdownBox004EditMode = false;
    state.DropdownBox004Active = 0;

    state.layoutRecs[0] = { state.anchor01.x + 0, state.anchor01.y + 0, 280, 368 };
    state.layoutRecs[1] = { state.anchor01.x + 16, state.anchor01.y + 32, 120, 24 };
    state.layoutRecs[2] = { state.anchor01.x + 32, state.anchor01.y + 56, 96, 24 };
    state.layoutRecs[3] = { state.anchor01.x + 32, state.anchor01.y + 80, 96, 24 };
    state.layoutRecs[4] = { state.anchor01.x + 16, state.anchor01.y + 136, 120, 24 };
    state.layoutRecs[5] = { state.anchor01.x + 16, state.anchor01.y + 160, 120, 24 };
    state.layoutRecs[6] = { state.anchor01.x + 152, state.anchor01.y + 136, 24, 24 };
    state.layoutRecs[7] = { state.anchor01.x + 152, state.anchor01.y + 160, 24, 24 };
    state.layoutRecs[8] = { state.anchor01.x + 168, state.anchor01.y + 136, 56, 24 };
    state.layoutRecs[9] = { state.anchor01.x + 168, state.anchor01.y + 160, 56, 24 };
    state.layoutRecs[10] = { state.anchor01.x + 16, state.anchor01.y + 112, 248, 16 };
    state.layoutRecs[11] = { state.anchor01.x + 16, state.anchor01.y + 192, 248, 16 };
    state.layoutRecs[12] = { state.anchor01.x + 16, state.anchor01.y + 216, 248, 24 };
    state.layoutRecs[13] = { state.anchor01.x + 16, state.anchor01.y + 240, 104, 24 };
    state.layoutRecs[14] = { state.anchor01.x + 128, state.anchor01.y + 240, 104, 24 };
    state.layoutRecs[15] = { state.anchor01.x + 16, state.anchor01.y + 264, 248, 16 };
    state.layoutRecs[16] = { state.anchor01.x + 16, state.anchor01.y + 288, 248, 24 };
    state.layoutRecs[17] = { state.anchor01.x + 16, state.anchor01.y + 312, 40, 24 };
    state.layoutRecs[18] = { state.anchor01.x + 56, state.anchor01.y + 312, 64, 24 };

    // Custom variables initialization

    return state;
}

static void Button005(GuiDebugLogicState* state)
{
    // get moore neighbor
    moore_direction tempDir = (moore_direction)state->DropdownBox004Active;
    Vector2 temp            = getMooreNeighborhoodCoordinate(state->Spinner002Value, state->Spinner003Value, tempDir);

    _itoa_s((int)temp.x, state->moore_x_buffer, 10, 10);
    _itoa_s((int)temp.y, state->moore_y_buffer, 10, 10);
}

static void Button012(GuiDebugLogicState* state, gamestate_t * gamestateRef)
{
    // get number of neighbors
    int temp = getNumberOfNeighbors(state->Spinner002Value, state->Spinner003Value, &gamestateRef->gridArray);
    _itoa_s(temp, state->counted_neighbors, 5, 10);
}

static void Button016(GuiDebugLogicState* state, gamestate_t* gamestateRef)
{
    // get new state of square
    bool temp = decideNewStateOfSquare(state->Spinner002Value, state->Spinner003Value, &gamestateRef->gridArray);
    
    if (temp) {
        strcpy(state->state_of_square, "true");
    }
    if (!temp) {
        strcpy(state->state_of_square, "false");
    }

}


void GuiDebugLogic(gamestate_t* gamestate, GuiDebugLogicState* state)
{
    if (state->DropdownBox004EditMode) GuiLock();


    if (state->WindowBox000Active)
    {
        state->WindowBox000Active = !GuiWindowBox(state->layoutRecs[0], "Logic Debug");
        GuiLabel(state->layoutRecs[1], "Enter Test Field");
        if (GuiSpinner(state->layoutRecs[2], "X: ", &state->Spinner002Value, 0, 100, state->Spinner002EditMode)) state->Spinner002EditMode = !state->Spinner002EditMode;
        if (GuiSpinner(state->layoutRecs[3], "Y: ", &state->Spinner003Value, 0, 100, state->Spinner003EditMode)) state->Spinner003EditMode = !state->Spinner003EditMode;
        if (GuiButton(state->layoutRecs[5], "Get Moore Neighbor")) Button005(state);
        GuiLabel(state->layoutRecs[6], "X: ");
        GuiLabel(state->layoutRecs[7], "Y: ");
        GuiLabel(state->layoutRecs[8], state->moore_x_buffer);
        GuiLabel(state->layoutRecs[9], state->moore_y_buffer);
        GuiLine(state->layoutRecs[10], NULL);
        GuiLine(state->layoutRecs[11], NULL);
        if (GuiButton(state->layoutRecs[12], "Get Number of Neighbors")) Button012(state, gamestate);
        GuiLabel(state->layoutRecs[13], "Counted Neighbors: ");
        GuiLabel(state->layoutRecs[14], state->counted_neighbors);
        GuiLine(state->layoutRecs[15], NULL);
        if (GuiButton(state->layoutRecs[16], "Get New State of Square")) Button016(state, gamestate);
        GuiLabel(state->layoutRecs[17], "Result: ");
        GuiLabel(state->layoutRecs[18], state->state_of_square);
        if (GuiDropdownBox(state->layoutRecs[4], "NW;N;NE;E;SE;S;SW;W", &state->DropdownBox004Active, state->DropdownBox004EditMode)) state->DropdownBox004EditMode = !state->DropdownBox004EditMode;
    }

    GuiUnlock();
}


