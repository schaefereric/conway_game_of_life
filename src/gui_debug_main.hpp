/*******************************************************************************************
*
*   Gui Debug Main v1.0.0 - user interface
*
*   MODULE USAGE:
*       #define GUI_GAME_OF_LIFE_IMPLEMENTATION
*       #include "gui_game_of_life.h"
*
*       INIT: GuiGameOfLifeState state = InitGuiGameOfLife();
*       DRAW: GuiGameOfLife(&state);
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
#define _CRT_SECURE_NO_WARNINGS

#include <string>
#include "gamestate_t.hpp"
#include "gui_button_implementation.hpp"

// WARNING: raygui implementation is expected to be defined before including this header
#undef RAYGUI_IMPLEMENTATION
#include "../include/raygui.h"

#include <cstring>     // Required for: strcpy()
#include "gui_structs.hpp"


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
    GuiDebugMainState InitGuiDebugMain(void);
    void GuiDebugMain(gamestate_t * gamestate, GuiDebugMainState* state);
    static void Button010(int x, int y, flexible_array* arrayRef);
    static void Button015(gamestate_t* gamestate);
    static void Button016(gamestate_t* gamestate);
    static void Button025(int x, int y, std::string& str, flexible_array* arrayRef);
    static void Button027(int x, int y, flexible_array* arrayRef);
    static void Button028(int x, int y, flexible_array* arrayRef);
    static void Button037(int x, int y, gamestate_t* gamestate);
    static void Button039(int x, int* squaresizeRef);
    static void Button040(gamestate_t* gamestate);


/***********************************************************************************
*
*   GUI_GAME_OF_LIFE IMPLEMENTATION
*
************************************************************************************/

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
GuiDebugMainState InitGuiDebugMain(void)
{
    GuiDebugMainState state = { 0 };

    int anchor_distance_x = 300;

    state.anchor01 = { float(712 + anchor_distance_x), 64 };
    state.anchor02 = { float(728 + anchor_distance_x), 112 };
    state.anchor03 = { float(728 + anchor_distance_x), 616 };

    state.WindowBox000Active = true;
    state.Spinner005EditMode = false;
    state.Spinner005Value = 0;
    state.Spinner006EditMode = false;
    state.Spinner006Value = 0;
    state.ValueBOx017EditMode = false;
    state.ValueBOx017Value = 0;
    state.ValueBOx016EditMode = false;
    state.ValueBOx016Value = 0;
    state.ValueBOx018EditMode = false;
    state.ValueBOx018Value = 0;
    state.Spinner018EditMode = false;
    state.Spinner018Value = 0;
    state.Spinner022EditMode = false;
    state.Spinner022Value = 0;
    state.Spinner026EditMode = false;
    state.Spinner026Value = 0;
    state.Spinner035EditMode = false;
    state.Spinner035Value = 0;
    state.Spinner036EditMode = false;
    state.Spinner036Value = 0;

    state.layoutRecs[0] = { state.anchor01.x + 0, state.anchor01.y + 8, 336, 712 };
    state.layoutRecs[1] = { state.anchor02.x + 0, state.anchor02.y + 0, 304, 472 };
    state.layoutRecs[2] = { state.anchor02.x + 16, state.anchor02.y + 8, 120, 24 };
    state.layoutRecs[3] = { state.anchor02.x + 16, state.anchor02.y + 136, 120, 24 };
    state.layoutRecs[4] = { state.anchor02.x + 168, state.anchor02.y + 136, 120, 24 };
    state.layoutRecs[5] = { state.anchor02.x + 56, state.anchor02.y + 112, 120, 24 };
    state.layoutRecs[6] = { state.anchor02.x + 208, state.anchor02.y + 112, 120, 24 };
    state.layoutRecs[7] = { state.anchor02.x + 16, state.anchor02.y + 80, 272, 16 };
    state.layoutRecs[8] = { state.anchor02.x + 16, state.anchor02.y + 168, 272, 24 };
    state.layoutRecs[9] = { state.anchor02.x + 16, state.anchor02.y + 192, 272, 16 };
    state.layoutRecs[10] = { state.anchor03.x + 0, state.anchor03.y + 16, 304, 128 };
    state.layoutRecs[11] = { state.anchor03.x + 16, state.anchor03.y + 24, 120, 24 };
    state.layoutRecs[12] = { state.anchor03.x + 16, state.anchor03.y + 56, 120, 24 };
    state.layoutRecs[13] = { state.anchor03.x + 152, state.anchor03.y + 56, 120, 24 };
    state.layoutRecs[14] = { state.anchor02.x + 56, state.anchor02.y + 32, 40, 24 };
    state.layoutRecs[15] = { state.anchor02.x + 56, state.anchor02.y + 56, 40, 24 };
    state.layoutRecs[16] = { state.anchor02.x + 16, state.anchor02.y + 88, 120, 24 };
    state.layoutRecs[17] = { state.anchor02.x + 240, state.anchor02.y + 312, 40, 24 };
    state.layoutRecs[18] = { state.anchor02.x + 176, state.anchor02.y + 384, 88, 24 };
    state.layoutRecs[19] = { state.anchor02.x + 16, state.anchor02.y + 200, 120, 24 };
    state.layoutRecs[20] = { state.anchor02.x + 24, state.anchor02.y + 248, 96, 24 };
    state.layoutRecs[21] = { state.anchor02.x + 128, state.anchor02.y + 248, 32, 16 };
    state.layoutRecs[22] = { state.anchor02.x + 128, state.anchor02.y + 272, 64, 24 };
    state.layoutRecs[23] = { state.anchor02.x + 24, state.anchor02.y + 272, 96, 24 };
    state.layoutRecs[24] = { state.anchor02.x + 168, state.anchor02.y + 248, 32, 16 };
    state.layoutRecs[25] = { state.anchor02.x + 200, state.anchor02.y + 272, 88, 24 };
    state.layoutRecs[26] = { float(928 + anchor_distance_x), 360, 88, 24 };
    state.layoutRecs[27] = { state.anchor02.x + 16, state.anchor02.y + 224, 80, 24 };
    state.layoutRecs[28] = { state.anchor02.x + 128, state.anchor02.y + 224, 40, 24 };
    state.layoutRecs[29] = { state.anchor02.x + 200, state.anchor02.y + 224, 48, 24 };
    state.layoutRecs[30] = { state.anchor02.x + 16, state.anchor02.y + 296, 272, 16 };
    state.layoutRecs[31] = { state.anchor02.x + 16, state.anchor02.y + 304, 120, 24 };
    state.layoutRecs[32] = { state.anchor02.x + 16, state.anchor02.y + 336, 120, 24 };
    state.layoutRecs[33] = { state.anchor02.x + 32, state.anchor02.y + 360, 88, 24 };
    state.layoutRecs[34] = { state.anchor02.x + 32, state.anchor02.y + 384, 88, 24 };
    state.layoutRecs[35] = { state.anchor02.x + 32, state.anchor02.y + 408, 88, 24 };
    state.layoutRecs[36] = { state.anchor02.x + 176, state.anchor02.y + 360, 88, 24 };
    state.layoutRecs[37] = { state.anchor02.x + 176, state.anchor02.y + 408, 88, 24 };
    state.layoutRecs[38] = { state.anchor02.x + 16, state.anchor02.y + 432, 272, 16 };
    state.layoutRecs[39] = { state.anchor03.x + 88, state.anchor03.y + 24, 72, 24 };
    state.layoutRecs[40] = { state.anchor03.x + 16, state.anchor03.y + 88, 120, 24 };

    // Custom variables initialization

    return state;
}
static void Button010(int x, int y, flexible_array * arrayRef)
{
    resize_array(x, y, arrayRef);
}
static void Button015(gamestate_t* gamestate)
{
    // start algo
    gamestate->setRunAlgorithm(true);
}
static void Button016(gamestate_t* gamestate)
{
    // stop algo
    gamestate->setRunAlgorithm(false);
}
static void Button025(int x, int y, std::string & str, flexible_array * arrayRef)
{
    read_field(x, y, str, arrayRef);
}
static void Button027(int x, int y, flexible_array* arrayRef)
{
    set_field_false(x, y, arrayRef);
}
static void Button028(int x, int y, flexible_array * arrayRef)
{
    set_field_true(x, y, arrayRef);
}
static void Button037(int x, int y, gamestate_t * gamestate)
{
    set_grid_origin(x, y, gamestate);
}
static void Button039(int x, int * squaresizeRef)
{
    set_square_size(x, squaresizeRef);
}
static void Button040(gamestate_t* gamestate)
{
    gamestate->singleStep();
}



void GuiDebugMain(gamestate_t * gamestate, GuiDebugMainState* state)
{

    if (state->WindowBox000Active)
    {
        state->WindowBox000Active = !GuiWindowBox(state->layoutRecs[0], "Game of Life");
    }
    static std::string field_readout = "NaN";

    state->ValueBOx017Value = gamestate->gridArray.getSizeX();
    state->ValueBOx016Value = gamestate->gridArray.getSizeY();
    state->ValueBOx018Value = gamestate->squareSize;
    
    static char isAlgoRunning[10];
    if (gamestate->runAlgorithm == true) {
        #ifdef _WIN32
        strcpy_s(isAlgoRunning, sizeof(isAlgoRunning), "Running");
        #else
        strcpy(isAlgoRunning, "Running");
        #endif
    }
    if (gamestate->runAlgorithm == false) {
        #ifdef _WIN32
        strcpy_s(isAlgoRunning, sizeof(isAlgoRunning), "Stopped");
        #else
        strcpy(isAlgoRunning, "Stopped");
        #endif
    }

    GuiGroupBox(state->layoutRecs[1], "Array");
    GuiLabel(state->layoutRecs[2], "Array Size");
    if (GuiSpinner(state->layoutRecs[3], NULL, &state->Spinner005Value, 0, 16384, state->Spinner005EditMode)) state->Spinner005EditMode = !state->Spinner005EditMode;
    if (GuiSpinner(state->layoutRecs[4], NULL, &state->Spinner006Value, 0, 16384, state->Spinner006EditMode)) state->Spinner006EditMode = !state->Spinner006EditMode;
    GuiLabel(state->layoutRecs[5], "SIZE X");
    GuiLabel(state->layoutRecs[6], "SIZE Y");
    GuiLine(state->layoutRecs[7], NULL);
    if (GuiButton(state->layoutRecs[8], "Resize!")) Button010(state->Spinner005Value, state->Spinner006Value, &gamestate->gridArray);
    GuiLine(state->layoutRecs[9], NULL);
    GuiGroupBox(state->layoutRecs[10], "Game Algorithm");
    GuiLabel(state->layoutRecs[11], "Game Status: ");
    if (GuiButton(state->layoutRecs[12], "Start")) Button015(gamestate);
    if (GuiButton(state->layoutRecs[13], "Stop")) Button016(gamestate);
    if (GuiValueBox(state->layoutRecs[14], "Size X: ", &state->ValueBOx017Value, 0, 16384, state->ValueBOx017EditMode)) state->ValueBOx017EditMode = !state->ValueBOx017EditMode;
    if (GuiValueBox(state->layoutRecs[15], "Size Y: ", &state->ValueBOx016Value, 0, 16384, state->ValueBOx016EditMode)) state->ValueBOx016EditMode = !state->ValueBOx016EditMode;
    GuiLabel(state->layoutRecs[16], "Resize Array");
    if (GuiValueBox(state->layoutRecs[17], "Square Size ", &state->ValueBOx018Value, 0, 16384, state->ValueBOx018EditMode)) state->ValueBOx018EditMode = !state->ValueBOx018EditMode;
    if (GuiSpinner(state->layoutRecs[18], NULL, &state->Spinner018Value, 0, 16384, state->Spinner018EditMode)) state->Spinner018EditMode = !state->Spinner018EditMode;
    GuiLabel(state->layoutRecs[19], "Fields");
    if (GuiSpinner(state->layoutRecs[20], "X: ", &state->Spinner022Value, 0, 16384, state->Spinner022EditMode)) state->Spinner022EditMode = !state->Spinner022EditMode;
    GuiLabel(state->layoutRecs[21], "Value: ");
    if (GuiButton(state->layoutRecs[22], "Read")) Button025(state->Spinner022Value, state->Spinner026Value, field_readout, &gamestate->gridArray);
    if (GuiSpinner(state->layoutRecs[23], "Y: ", &state->Spinner026Value, 0, 16384, state->Spinner026EditMode)) state->Spinner026EditMode = !state->Spinner026EditMode;
    GuiLabel(state->layoutRecs[24], field_readout.c_str());
    if (GuiButton(state->layoutRecs[25], "FALSE")) Button027(state->Spinner022Value, state->Spinner026Value, &gamestate->gridArray);
    if (GuiButton(state->layoutRecs[26], "TRUE")) Button028(state->Spinner022Value, state->Spinner026Value, &gamestate->gridArray);
    GuiLabel(state->layoutRecs[27], "Coordinates:");
    GuiLabel(state->layoutRecs[28], "Read:");
    GuiLabel(state->layoutRecs[29], "Set:");
    GuiLine(state->layoutRecs[30], NULL);
    GuiLabel(state->layoutRecs[31], "Grid");
    GuiLabel(state->layoutRecs[32], "Origin:");
    if (GuiSpinner(state->layoutRecs[33], "X: ", &state->Spinner035Value, 0, 16384, state->Spinner035EditMode)) state->Spinner035EditMode = !state->Spinner035EditMode;
    if (GuiSpinner(state->layoutRecs[34], "Y: ", &state->Spinner036Value, 0, 16384, state->Spinner036EditMode)) state->Spinner036EditMode = !state->Spinner036EditMode;
    if (GuiButton(state->layoutRecs[35], "Set")) Button037(state->Spinner035Value, state->Spinner036Value, gamestate);
    GuiLabel(state->layoutRecs[36], "Set Square Size");
    if (GuiButton(state->layoutRecs[37], "Set")) Button039(state->Spinner018Value, &gamestate->squareSize);
    GuiLine(state->layoutRecs[38], NULL);
    GuiLabel(state->layoutRecs[39], isAlgoRunning);
    if (GuiButton(state->layoutRecs[40], "Single Step")) Button040(gamestate);
}

