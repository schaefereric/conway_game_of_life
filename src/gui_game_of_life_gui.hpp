/*******************************************************************************************
*
*   GameOfLife v1.0.0 - user interface
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

#include <string>
#include "gamestate_class.hpp"
#include "gui_button_implementation.hpp"
#include "raylib.h"

// WARNING: raygui implementation is expected to be defined before including this header
#undef RAYGUI_IMPLEMENTATION
#include "raygui.h"

#include <string.h>     // Required for: strcpy()

#ifndef GUI_GAME_OF_LIFE_H
#define GUI_GAME_OF_LIFE_H

typedef struct {
    Vector2 anchor01;
    Vector2 anchor02;
    Vector2 anchor03;

    bool WindowBox000Active;
    bool Spinner005EditMode;
    int Spinner005Value;
    bool Spinner006EditMode;
    int Spinner006Value;
    bool ValueBOx017EditMode;
    int ValueBOx017Value;
    bool ValueBOx016EditMode;
    int ValueBOx016Value;
    bool ValueBOx018EditMode;
    int ValueBOx018Value;
    bool Spinner018EditMode;
    int Spinner018Value;
    bool Spinner022EditMode;
    int Spinner022Value;
    bool Spinner026EditMode;
    int Spinner026Value;
    bool Spinner035EditMode;
    int Spinner035Value;
    bool Spinner036EditMode;
    int Spinner036Value;

    Rectangle layoutRecs[39];

    // Custom state variables (depend on development software)
    // NOTE: This variables should be added manually if required

} GuiGameOfLifeState;

#ifdef __cplusplus
//extern "C" {            // Prevents name mangling of functions
#endif

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
    GuiGameOfLifeState InitGuiGameOfLife(void);
    void GuiGameOfLife(gamestate_class & gamestate, GuiGameOfLifeState* state);
    static void Button010(int x, int y, flexible_array& arrayRef);
    static void Button015();
    static void Button016();
    static void Button025(int x, int y, std::string& str, flexible_array& arrayRef);
    static void Button027(int x, int y, flexible_array& arrayRef);
    static void Button028(int x, int y, flexible_array& arrayRef);
    static void Button037(int x, int y);
    static void Button039(int x, int& squaresizeRef);

#ifdef __cplusplus
//}
#endif

#endif // GUI_GAME_OF_LIFE_H

/***********************************************************************************
*
*   GUI_GAME_OF_LIFE IMPLEMENTATION
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
GuiGameOfLifeState InitGuiGameOfLife(void)
{
    GuiGameOfLifeState state = { 0 };

    state.anchor01 = { 712, 64 };
    state.anchor02 = { 728, 112 };
    state.anchor03 = { 728, 616 };

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

    state.layoutRecs[0] = { state.anchor01.x + 0, state.anchor01.y + 8, 336, 672 };
    state.layoutRecs[1] = { state.anchor02.x + 0, state.anchor02.y + 0, 304, 472 };
    state.layoutRecs[2] = { state.anchor02.x + 16, state.anchor02.y + 8, 120, 24 };
    state.layoutRecs[3] = { state.anchor02.x + 16, state.anchor02.y + 136, 120, 24 };
    state.layoutRecs[4] = { state.anchor02.x + 168, state.anchor02.y + 136, 120, 24 };
    state.layoutRecs[5] = { state.anchor02.x + 56, state.anchor02.y + 112, 120, 24 };
    state.layoutRecs[6] = { state.anchor02.x + 208, state.anchor02.y + 112, 120, 24 };
    state.layoutRecs[7] = { state.anchor02.x + 16, state.anchor02.y + 80, 272, 16 };
    state.layoutRecs[8] = { state.anchor02.x + 16, state.anchor02.y + 168, 272, 24 };
    state.layoutRecs[9] = { state.anchor02.x + 16, state.anchor02.y + 192, 272, 16 };
    state.layoutRecs[10] = { state.anchor03.x + 0, state.anchor03.y + 16, 304, 96 };
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
    state.layoutRecs[26] = { 928, 360, 88, 24 };
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

    // Custom variables initialization

    return state;
}
static void Button010(int x, int y, flexible_array & arrayRef)
{
    resize_array(x, y, arrayRef);
}
static void Button015()
{
    // TODO: Implement control logic
}
static void Button016()
{
    // TODO: Implement control logic
}
static void Button025(int x, int y, std::string & str, flexible_array & arrayRef)
{
    read_field(x, y, str, arrayRef);
}
static void Button027(int x, int y, flexible_array& arrayRef)
{
    set_field_false(x, y, arrayRef);
}
static void Button028(int x, int y, flexible_array & arrayRef)
{
    set_field_true(x, y, arrayRef);
}
static void Button037(int x, int y, gamestate_class & gamestate)
{
    set_grid_origin(x, y, gamestate);
}
static void Button039(int x, int & squaresizeRef)
{
    set_square_size(x, squaresizeRef);
}


void GuiGameOfLife(gamestate_class & gamestate, GuiGameOfLifeState* state)
{

    if (state->WindowBox000Active)
    {
        state->WindowBox000Active = !GuiWindowBox(state->layoutRecs[0], "Game of Life");
    }
    static std::string field_readout = "NaN";

    state->ValueBOx017Value = gamestate.gridArray.getSizeX();
    state->ValueBOx016Value = gamestate.gridArray.getSizeY();
    state->ValueBOx018Value = gamestate.squareSize;
    

    GuiGroupBox(state->layoutRecs[1], "Array");
    GuiLabel(state->layoutRecs[2], "Array Size");
    if (GuiSpinner(state->layoutRecs[3], NULL, &state->Spinner005Value, 0, 100, state->Spinner005EditMode)) state->Spinner005EditMode = !state->Spinner005EditMode;
    if (GuiSpinner(state->layoutRecs[4], NULL, &state->Spinner006Value, 0, 100, state->Spinner006EditMode)) state->Spinner006EditMode = !state->Spinner006EditMode;
    GuiLabel(state->layoutRecs[5], "SIZE X");
    GuiLabel(state->layoutRecs[6], "SIZE Y");
    GuiLine(state->layoutRecs[7], NULL);
    if (GuiButton(state->layoutRecs[8], "Resize!")) Button010(state->Spinner005Value, state->Spinner006Value, gamestate.gridArray);
    GuiLine(state->layoutRecs[9], NULL);
    GuiGroupBox(state->layoutRecs[10], "Game Algorithm");
    GuiLabel(state->layoutRecs[11], "Game Status: ");
    if (GuiButton(state->layoutRecs[12], "Start")) Button015();
    if (GuiButton(state->layoutRecs[13], "Stop")) Button016();
    if (GuiValueBox(state->layoutRecs[14], "Size X: ", &state->ValueBOx017Value, 0, 100, state->ValueBOx017EditMode)) state->ValueBOx017EditMode = !state->ValueBOx017EditMode;
    if (GuiValueBox(state->layoutRecs[15], "Size Y: ", &state->ValueBOx016Value, 0, 100, state->ValueBOx016EditMode)) state->ValueBOx016EditMode = !state->ValueBOx016EditMode;
    GuiLabel(state->layoutRecs[16], "Resize Array");
    if (GuiValueBox(state->layoutRecs[17], "Square Size ", &state->ValueBOx018Value, 0, 100, state->ValueBOx018EditMode)) state->ValueBOx018EditMode = !state->ValueBOx018EditMode;
    if (GuiSpinner(state->layoutRecs[18], NULL, &state->Spinner018Value, 0, 100, state->Spinner018EditMode)) state->Spinner018EditMode = !state->Spinner018EditMode;
    GuiLabel(state->layoutRecs[19], "Fields");
    if (GuiSpinner(state->layoutRecs[20], "X: ", &state->Spinner022Value, 0, 100, state->Spinner022EditMode)) state->Spinner022EditMode = !state->Spinner022EditMode;
    GuiLabel(state->layoutRecs[21], "Value: ");
    if (GuiButton(state->layoutRecs[22], "Read")) Button025(state->Spinner022Value, state->Spinner026Value, field_readout, gamestate.gridArray);
    if (GuiSpinner(state->layoutRecs[23], "Y: ", &state->Spinner026Value, 0, 100, state->Spinner026EditMode)) state->Spinner026EditMode = !state->Spinner026EditMode;
    GuiLabel(state->layoutRecs[24], field_readout.c_str());
    if (GuiButton(state->layoutRecs[25], "FALSE")) Button027(state->Spinner022Value, state->Spinner026Value, gamestate.gridArray);
    if (GuiButton(state->layoutRecs[26], "TRUE")) Button028(state->Spinner022Value, state->Spinner026Value, gamestate.gridArray);
    GuiLabel(state->layoutRecs[27], "Coordinates:");
    GuiLabel(state->layoutRecs[28], "Read:");
    GuiLabel(state->layoutRecs[29], "Set:");
    GuiLine(state->layoutRecs[30], NULL);
    GuiLabel(state->layoutRecs[31], "Grid");
    GuiLabel(state->layoutRecs[32], "Origin:");
    if (GuiSpinner(state->layoutRecs[33], "X: ", &state->Spinner035Value, 0, 100, state->Spinner035EditMode)) state->Spinner035EditMode = !state->Spinner035EditMode;
    if (GuiSpinner(state->layoutRecs[34], "Y: ", &state->Spinner036Value, 0, 100, state->Spinner036EditMode)) state->Spinner036EditMode = !state->Spinner036EditMode;
    if (GuiButton(state->layoutRecs[35], "Set")) Button037(state->Spinner035Value, state->Spinner036Value, gamestate);
    GuiLabel(state->layoutRecs[36], "Set Square Size");
    if (GuiButton(state->layoutRecs[37], "Set")) Button039(state->Spinner018Value, gamestate.squareSize);
    GuiLine(state->layoutRecs[38], NULL);
}

