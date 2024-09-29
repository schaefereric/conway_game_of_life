/*******************************************************************************************
*
*   Hidden v1.0.0 - user interface
*
*   MODULE USAGE:
*       #define GUI_HIDDEN_UI_MESSAGE_IMPLEMENTATION
*       #include "gui_Hidden_UI_Message.h"
*
*       INIT: GuiHiddenState state = InitGuiHidden();
*       DRAW: GuiHidden(&state);
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


// WARNING: raygui implementation is expected to be defined before including this header
#undef RAYGUI_IMPLEMENTATION
#include "../include/raygui.h"

#include <string.h>     // Required for: strcpy()
#include "gui_structs.hpp"
#include "gui_button_implementation.hpp"
#include "gamestate_t.hpp"
#include "guimaster_t.hpp"


//----------------------------------------------------------------------------------
// Module Functions Declaration
//----------------------------------------------------------------------------------
    GuiHiddenState InitGuiHidden(void);
    void GuiHidden(gamestate_t* gamestate, guimaster_t * guimaster, GuiHiddenState* state);
    static void Button002(gamestate_t* gamestate, guimaster_t* guimaster);



/***********************************************************************************
*
*   GUI_HIDDEN_UI_MESSAGE IMPLEMENTATION
*
************************************************************************************/

//----------------------------------------------------------------------------------
// Module Functions Definition
//----------------------------------------------------------------------------------
GuiHiddenState InitGuiHidden(void)
{
    GuiHiddenState state = { 0 };

    state.layoutRecs[0] = { 1, 1, 200, 72 };
    state.layoutRecs[1] = { 8, 8, 184, 16 };
    state.layoutRecs[2] = { 32, 32, 128, 24 };

    return state;
}

static void Button002(gamestate_t* gamestate, guimaster_t * guimaster)
{
    // show main ui
    gamestate->UIHidden = false;
    guimaster->guistate_main_window.WindowBox000Active = true;
    guimaster->draw_main_window = true;
    guimaster->draw_hidden_ui_message = false;
}

void GuiHidden(gamestate_t* gamestate, guimaster_t* guimaster, GuiHiddenState* state)
{
    GuiPanel(state->layoutRecs[0], NULL);
    GuiLabel(state->layoutRecs[1], "User Interface is currently hidden");
    if (GuiButton(state->layoutRecs[2], "Show User Interface")) Button002(gamestate, guimaster);
}

