/*******************************************************************************************
*
*   DebugMouse v1.0.0 - user interface
*
*   MODULE USAGE:
*       #define GUI_DEBUG_MOUSE_IMPLEMENTATION
*       #include "gui_debug_mouse.h"
*
*       INIT: GuiDebugMouseState state = InitGuiDebugMouse();
*       DRAW: GuiDebugMouse(&state);
*
*   LICENSE: Propietary License
*
*   Copyright (c) 2024 schaefereric. All Rights Reserved.
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
#include <string>
#include "gui_structs.hpp"
#include "gui_button_implementation.hpp"
#include "gamestate_t.hpp"
#include <iostream>


//----------------------------------------------------------------------------------
// Module Functions Declaration
//----------------------------------------------------------------------------------
   GuiDebugMouseState InitGuiDebugMouse(void);
   void GuiDebugMouse(gamestate_t & gamestate, GuiDebugMouseState* state);



/***********************************************************************************
*
*   GUI_DEBUG_MOUSE IMPLEMENTATION
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
GuiDebugMouseState InitGuiDebugMouse(void)
{
    GuiDebugMouseState state = { 0 };

    int anchor_distance_x = 300;

    state.anchor01 = { float(450 + anchor_distance_x), 448 };

    state.WindowBox000Active = true;
    state.Brush_select_ListViewScrollIndex = 0;
    state.Brush_select_ListViewActive = 0;

    state.layoutRecs[0] = { state.anchor01.x + 0, state.anchor01.y + 0, 256, 336 };
    state.layoutRecs[1] = { state.anchor01.x + 16, state.anchor01.y + 32, 120, 24 };
    state.layoutRecs[2] = { state.anchor01.x + 16, state.anchor01.y + 56, 12, 16 };
    state.layoutRecs[3] = { state.anchor01.x + 32, state.anchor01.y + 56, 40, 16 };
    state.layoutRecs[4] = { state.anchor01.x + 104, state.anchor01.y + 56, 12, 12 };
    state.layoutRecs[5] = { state.anchor01.x + 120, state.anchor01.y + 56, 32, 12 };
    state.layoutRecs[6] = { state.anchor01.x + 16, state.anchor01.y + 136, 224, 16 };
    state.layoutRecs[7] = { state.anchor01.x + 16, state.anchor01.y + 88, 104, 24 };
    state.layoutRecs[8] = { state.anchor01.x + 120, state.anchor01.y + 88, 112, 24 };
    state.layoutRecs[9] = { state.anchor01.x + 128, state.anchor01.y + 168, 120, 72 };
    state.layoutRecs[10] = { state.anchor01.x + 16, state.anchor01.y + 168, 72, 24 };
    state.layoutRecs[11] = { state.anchor01.x + 16, state.anchor01.y + 184, 72, 10 };
    state.layoutRecs[12] = { state.anchor01.x + 16, state.anchor01.y + 104, 104, 24 };
    state.layoutRecs[13] = { state.anchor01.x + 120, state.anchor01.y + 104, 112, 24 };
    state.layoutRecs[14] = { state.anchor01.x + 16, state.anchor01.y + 248, 224, 16 };
    state.layoutRecs[15] = { state.anchor01.x + 16, state.anchor01.y + 264, 120, 24 };
    state.layoutRecs[16] = { state.anchor01.x + 16, state.anchor01.y + 288, 16, 24 };
    state.layoutRecs[17] = { state.anchor01.x + 32, state.anchor01.y + 288, 40, 24 };
    state.layoutRecs[18] = { state.anchor01.x + 80, state.anchor01.y + 288, 16, 24 };
    state.layoutRecs[19] = { state.anchor01.x + 96, state.anchor01.y + 288, 40, 24 };

    // Custom variables initialization

    return state;
}


void GuiDebugMouse(gamestate_t & gamestate, GuiDebugMouseState* state)
{
    if (state->WindowBox000Active)
    {
        static char mou_x_buffer[10];
        _itoa_s((int)gamestate.mousetools->mousePosition.x, mou_x_buffer, 10, 10); // Cast MousePosition.x integer to c_string
        static char mou_y_buffer[10];
        _itoa_s((int)gamestate.mousetools->mousePosition.y, mou_y_buffer, 10, 10); // Cast MousePosition.y integer to c_string

        static char mouse_lval_str[6];
        if (gamestate.mousetools->mouse_L) {
            strcpy(mouse_lval_str, "true");
        }
        else if (!(gamestate.mousetools->mouse_L)) {
            strcpy(mouse_lval_str, "false");
        }

        static char mouse_rval_str[6];
        if (gamestate.mousetools->mouse_R) {
            strcpy(mouse_rval_str, "true");
        }
        else if (!(gamestate.mousetools->mouse_R)) {
            strcpy(mouse_rval_str, "false");
        }

        state->WindowBox000Active = !GuiWindowBox(state->layoutRecs[0], "Mouse Debug");
        GuiLabel(state->layoutRecs[1], "Mouse Position:");
        GuiLabel(state->layoutRecs[2], "X: ");
        GuiLabel(state->layoutRecs[3], mou_x_buffer);
        GuiLabel(state->layoutRecs[4], "Y: ");
        GuiLabel(state->layoutRecs[5], mou_y_buffer);
        GuiLine(state->layoutRecs[6], NULL);
        GuiLabel(state->layoutRecs[7], "Mouse_L pressed?: ");
        GuiLabel(state->layoutRecs[8], mouse_lval_str);
        GuiListView(state->layoutRecs[9], "PAINT; ERASE", &state->Brush_select_ListViewScrollIndex, &state->Brush_select_ListViewActive);
        GuiLabel(state->layoutRecs[10], "Mouse Brush");
        GuiLabel(state->layoutRecs[11], "Settings");
        GuiLabel(state->layoutRecs[12], "Mouse_R pressed?: ");
        GuiLabel(state->layoutRecs[13], mouse_rval_str);
        GuiLine(state->layoutRecs[14], NULL);
        GuiLabel(state->layoutRecs[15], "Last Killed Square:");
        GuiLabel(state->layoutRecs[16], "X: ");
        GuiLabel(state->layoutRecs[17], "lks_x");
        GuiLabel(state->layoutRecs[18], "Y: ");
        GuiLabel(state->layoutRecs[19], "lks_y");

        //if (state->Brush_select_ListViewActive == 0) {
        //    // "Paint" selection
        //    gamestate.paintbrush_mode = PAINT;
        //}
        //if (state->Brush_select_ListViewActive == 1) {
        //    // "Erase" selection
        //    gamestate.paintbrush_mode = ERASE;
        //}


    }
}
