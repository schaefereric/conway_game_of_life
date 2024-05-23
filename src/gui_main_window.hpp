/*******************************************************************************************
*
*   MainWindow v1.0.0 - user interface
*   Automatically generated via rguilayout
*
*   MODULE USAGE:
*       #define GUI_MAIN_WINDOW_IMPLEMENTATION
*       #include "gui_main_window.h"
*
*       INIT: GuiMainWindowState state = InitGuiMainWindow();
*       DRAW: GuiMainWindow(&state);
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
#include "../include/raygui.h"

#include <string.h>     // Required for: strcpy()
#include <iostream>
#include "gui_structs.hpp"
#include "gui_button_implementation.hpp"
#include "gamestate_t.hpp"
#include "grid.hpp"
#include "guimaster_t.hpp"

struct guimaster_t;

//----------------------------------------------------------------------------------
// Module Functions Declaration
//----------------------------------------------------------------------------------
GuiMainWindowState InitGuiMainWindow();
       void GuiMainWindow(gamestate_t* gamestate, guimaster_t* guimaster, GuiMainWindowState* state);
static void Button004(gamestate_t* gamestate);
static void Button005(gamestate_t* gamestate);
static void Button006(gamestate_t* gamestate);
static void Button023(gamestate_t* gamestate);
static void Button024(gamestate_t* gamestate);
static void Button028();
static void Button032();
static void stretchGUIToWindowHeight(gamestate_t* gamestate, GuiMainWindowState* state);


/***********************************************************************************
*
*   GUI_MAIN_WINDOW IMPLEMENTATION
*
************************************************************************************/

// redundant
#define spray_toggle Toggle012Active
#define paint_toggle Toggle013Active
#define erase_toggle Toggle015Active
#define movegrid_toggle Toggle014Active


//----------------------------------------------------------------------------------
// Module Functions Definition
//----------------------------------------------------------------------------------
GuiMainWindowState InitGuiMainWindow()
{
    GuiMainWindowState state = { 0 };

    state.anchor01 = { 0, 0 };
    state.anchor02 = { 0, 900 };

    state.WindowBox000Active = true;
    state.Toggle012Active = false;
    state.Toggle013Active = false;
    state.Toggle014Active = false;
    state.Toggle015Active = false;
    state.Slider012Value = 200.0f;
    state.SliderBar015Value = 2.0f;
    state.Slider017Value = 40.0f;
    state.Slider018Value = 40.0f;
    state.Slider025Value = 18.0f;
    state.CheckBoxEx033Checked = true;
    state.CheckBoxEx034Checked = false;

    state.layoutRecs[0]  = { state.anchor01.x + 0, state.anchor01.y + 0, 410, 900 };
    state.layoutRecs[1]  = { state.anchor01.x + 24, state.anchor01.y + 32, 360, 16 };
    state.layoutRecs[2]  = { state.anchor01.x + 24, state.anchor01.y + 56, 64, 24 };
    state.layoutRecs[3]  = { state.anchor01.x + 88, state.anchor01.y + 56, 72, 24 };
    state.layoutRecs[4]  = { state.anchor01.x + 32, state.anchor01.y + 96, 104, 24 };
    state.layoutRecs[5]  = { state.anchor01.x + 144, state.anchor01.y + 96, 112, 24 };
    state.layoutRecs[6]  = { state.anchor01.x + 264, state.anchor01.y + 96, 112, 24 };
    state.layoutRecs[7]  = { state.anchor01.x + 24, state.anchor01.y + 192, 360, 16 };
    state.layoutRecs[8]  = { state.anchor01.x + 32, state.anchor01.y + 224, 168, 24 };
    state.layoutRecs[9]  = { state.anchor01.x + 208, state.anchor01.y + 224, 168, 24 };
    state.layoutRecs[10] = { state.anchor01.x + 208, state.anchor01.y + 256, 168, 24 };
    state.layoutRecs[11] = { state.anchor01.x + 32, state.anchor01.y + 256, 168, 24 };
    state.layoutRecs[12] = { state.anchor01.x + 96, state.anchor01.y + 144, 216, 16 };
    state.layoutRecs[13] = { state.anchor01.x + 328, state.anchor01.y + 144, 48, 16 };
    state.layoutRecs[14] = { state.anchor01.x + 336, state.anchor01.y + 304, 40, 16 };
    state.layoutRecs[15] = { state.anchor01.x + 136, state.anchor01.y + 304, 176, 16 };
    state.layoutRecs[16] = { state.anchor01.x + 24, state.anchor01.y + 392, 360, 16 };
    state.layoutRecs[17] = { state.anchor01.x + 80, state.anchor01.y + 456, 264, 16 };
    state.layoutRecs[18] = { state.anchor01.x + 80, state.anchor01.y + 480, 264, 16 };
    state.layoutRecs[19] = { state.anchor01.x + 32, state.anchor01.y + 424, 88, 16 };
    state.layoutRecs[20] = { state.anchor01.x + 360, state.anchor01.y + 456, 24, 16 };
    state.layoutRecs[21] = { state.anchor01.x + 360, state.anchor01.y + 480, 24, 16 };
    state.layoutRecs[22] = { state.anchor01.x + 32, state.anchor01.y + 528, 88, 16 };
    state.layoutRecs[23] = { state.anchor01.x + 32, state.anchor01.y + 552, 168, 24 };
    state.layoutRecs[24] = { state.anchor01.x + 208, state.anchor01.y + 552, 168, 24 };
    state.layoutRecs[25] = { state.anchor01.x + 136, state.anchor01.y + 592, 176, 16 };
    state.layoutRecs[26] = { state.anchor01.x + 328, state.anchor01.y + 592, 56, 16 };
    // anchor02
    state.layoutRecs[27] = { state.anchor02.x + 24, state.anchor02.y + -192, 360, 16 };
    state.layoutRecs[28] = { state.anchor02.x + 32, state.anchor02.y + -160, 344, 24 };
    state.layoutRecs[29] = { state.anchor02.x + 24, state.anchor02.y + -88, 360, 16 };
    state.layoutRecs[30] = { state.anchor02.x + 32, state.anchor02.y + -56, 184, 24 };
    state.layoutRecs[31] = { state.anchor02.x + 32, state.anchor02.y + -40, 272, 24 };
    state.layoutRecs[32] = { state.anchor02.x + 32, state.anchor02.y + -128, 344, 24 };
    state.layoutRecs[33] = { state.anchor01.x + 32, state.anchor01.y + 632, 18, 18 };
    state.layoutRecs[34] = { state.anchor01.x + 32, state.anchor01.y + 336, 18, 18 };


    // Custom variables initialization
    

    return state;
}
static void Button004(gamestate_t* gamestate)
{
    // start algorithm
    gamestate->startAlgorithm();
}
static void Button005(gamestate_t* gamestate)
{
    // stop algorithm
    gamestate->stopAlgorithm();
}
static void Button006(gamestate_t* gamestate)
{
    // single step algorithm
    gamestate->singleStep();
}
static void Button023(gamestate_t* gamestate)
{
    // clear grid
    gamestate->gridArray.clearArray();
}
static void Button024(gamestate_t* gamestate)
{
    // shuffle grid
    shuffleGrid(gamestate);
}
static void Button028()
{
    // Open Debug Window Picker
}
static void Button032()
{
    // open github repository
    OpenURL("https://github.com/schaefereric/conway_game_of_life");
}

// very very weird algorithm. reconsider
static void checkToolSelection(GuiMainWindowState* state, gamestate_t* gamestate) {

    // Get amount of active GUI toggles
    int numOfActiveToggles = 0;
    for (auto iter : state->toggles) {
        if (*iter.first) numOfActiveToggles++;
    }
    
    // If no toggles are active
    if (numOfActiveToggles == 0 || numOfActiveToggles == 1) {
        for (auto& iter : state->toggles) {
            // Get pair of current tool and activate toggle
            if (iter.second == gamestate->mousetools->getCurrentTool()) {
                *iter.first = true;
                return;
            }
            // else, deactivate all other toggles
            else *iter.first = false;
        }
        throw; // HANDLE EXCEPTION PROPERLY !!!!!
    }

    // CurrentTool will be replaced
    if (numOfActiveToggles >= 2) {
        for (auto& iter : state->toggles) {

            // bool = true, tool = false
            // Toggle is active but tool is not selected -> select this tool
            if (*iter.first && (iter.second != gamestate->mousetools->getCurrentTool())) {          
                gamestate->mousetools->setCurrentTool(iter.second);
                // new tool has been set, deactivate all other toggle bools
                for (auto& iter2 : state->toggles) {
                    if (iter.second != iter2.second) {
                        *iter2.first = false;
                    }
                }
                continue;
            }

            // bool = true, tool = true
            if (*iter.first && (iter.second == gamestate->mousetools->getCurrentTool())) {
                *iter.first = false;
            }

        }
        return;
    }

    return;
}

// GUI Height is clipped to window height via this function
static void stretchGUIToWindowHeight(gamestate_t* gamestate, GuiMainWindowState* state) {

    // resizing is only performed if window size has been changed
    if (state->anchor02.y != gamestate->windowHeight) {

        state->anchor02.y           = static_cast<float> (gamestate->windowHeight);
        state->layoutRecs[0].height = static_cast<float> (gamestate->windowHeight);

        // re-calculate distances from anchor
        state->layoutRecs[27] = { state->anchor02.x + 24, state->anchor02.y + -192, 360, 16 };
        state->layoutRecs[28] = { state->anchor02.x + 32, state->anchor02.y + -160, 344, 24 };
        state->layoutRecs[29] = { state->anchor02.x + 24, state->anchor02.y + -88,  360, 16 };
        state->layoutRecs[30] = { state->anchor02.x + 32, state->anchor02.y + -56,  184, 24 };
        state->layoutRecs[31] = { state->anchor02.x + 32, state->anchor02.y + -40,  272, 24 };
        state->layoutRecs[32] = { state->anchor02.x + 32, state->anchor02.y + -128, 344, 24 };
        state->layoutRecs[33] = { state->anchor01.x + 32, state->anchor01.y +  632,  18, 18 };
        state->layoutRecs[34] = { state->anchor01.x + 32, state->anchor01.y +  336,  18, 18 };
    }
}


void GuiMainWindow(gamestate_t* gamestate, guimaster_t * guimaster, GuiMainWindowState *state) {

    if (state->WindowBox000Active) {

        // GUI Height is clipped to window height via this function
        stretchGUIToWindowHeight(gamestate, state);

        // Game Status
        if (gamestate->runAlgorithm == true) {
            strcpy(state->isGameRunning, "Running");
        }
        if (gamestate->runAlgorithm == false) {
            strcpy(state->isGameRunning, "Stopped");
        }

        // Set Speed/Delay
        //_itoa_s(gamestate->timer.getDelay(), state->speed_buffer, 10, 10);
        snprintf(state->speed_buffer, sizeof(state->speed_buffer), "%d", gamestate->timer.getDelay());
        strcat(state->speed_buffer, "ms");

        // Brush Radius
        //_itoa_s(gamestate->mousetools->getBrushRadius(), state->brushradius_buffer, 6, 10);
        snprintf(state->brushradius_buffer, sizeof(state->brushradius_buffer), "%d", gamestate->mousetools->getBrushRadius());
        strcat(state->brushradius_buffer, "px");

        // Array Size
        //_itoa_s(gamestate->gridArray.getSizeX(), state->array_size_x, 6, 10);
        //_itoa_s(gamestate->gridArray.getSizeY(), state->array_size_y, 6, 10);
        snprintf(state->array_size_x, sizeof(state->array_size_x), "%d", gamestate->gridArray.getSizeX());
        snprintf(state->array_size_y, sizeof(state->array_size_y), "%d", gamestate->gridArray.getSizeY());

        // Square Size
        //_itoa_s(gamestate->squareSize, state->squaresize_buffer, 6, 10);
        snprintf(state->squaresize_buffer, sizeof(state->squaresize_buffer), "%d", gamestate->getSquareSize());
        strcat(state->squaresize_buffer, "px");


        // Drawcalls
        state->WindowBox000Active = !GuiWindowBox(state->layoutRecs[0], "Game of Life");

        GuiLine(state->layoutRecs[1], "Game Algorithm");
        GuiLabel(state->layoutRecs[2], "#191#Status: ");
        GuiLabel(state->layoutRecs[3], state->isGameRunning);
        if (GuiButton(state->layoutRecs[4], "#131#Start")) Button004(gamestate); 
        if (GuiButton(state->layoutRecs[5], "#132#Stop")) Button005(gamestate);
        if (GuiButton(state->layoutRecs[6], "#060#Single Step")) Button006(gamestate);

        GuiLine(state->layoutRecs[7], "Mouse Options");
        GuiToggle(state->layoutRecs[8], "#024#Paint", &state->Toggle012Active);
        GuiToggle(state->layoutRecs[9], "#092#Spray", &state->Toggle013Active);
        GuiToggle(state->layoutRecs[10], "#068#Move Grid", &state->Toggle014Active);
        GuiToggle(state->layoutRecs[11], "#028#Erase", &state->Toggle015Active);
        
        GuiSlider(state->layoutRecs[12], "#139#Speed   ", NULL, &state->Slider012Value, 1, 1000);
        GuiLabel(state->layoutRecs[13], state->speed_buffer); 
        GuiLabel(state->layoutRecs[14], state->brushradius_buffer); 
        GuiSliderBar(state->layoutRecs[15], "#032#Brush Radius   ", NULL, &state->SliderBar015Value, 0, 10);

        GuiLine(state->layoutRecs[16], "Grid Options");
        GuiSlider(state->layoutRecs[17], "X-Axis: ", NULL, &state->Slider017Value, 3, 200);
        GuiSlider(state->layoutRecs[18], "Y-Axis: ", NULL, &state->Slider018Value, 3, 200);
        GuiLabel(state->layoutRecs[19], "#162#Resize Grid");
        GuiLabel(state->layoutRecs[20], state->array_size_x); 
        GuiLabel(state->layoutRecs[21], state->array_size_y); 

        GuiLabel(state->layoutRecs[22], "#140#Tools");
        if (GuiButton(state->layoutRecs[23], "#094#Clear Grid")) Button023(gamestate); 
        if (GuiButton(state->layoutRecs[24], "#093#Shuffle Grid")) Button024(gamestate); 
        GuiSlider(state->layoutRecs[25], "#096#Square Size    ", NULL, &state->Slider025Value, 3, 75);
        GuiLabel(state->layoutRecs[26], state->squaresize_buffer);

        GuiCheckBox(state->layoutRecs[33], "#108#Rectangle Outline", &state->CheckBoxEx033Checked);
        GuiCheckBox(state->layoutRecs[34], "#135#Show Preview for Brush Radius", &state->CheckBoxEx034Checked);

        GuiLine(state->layoutRecs[27], "Extras");
        if (GuiButton(state->layoutRecs[28], "Open Debug Window Picker")) Button028(); 

        GuiLine(state->layoutRecs[29], "Credits");
        GuiLabel(state->layoutRecs[30], "#186#Developed by Eric Schaefer");
        GuiLabel(state->layoutRecs[31], "#185#github.com/schaefereric/conway_game_of_life");
        if (GuiButton(state->layoutRecs[32], "Open Github Repository")) Button032(); 



        // Set Speed/Delay
        int tempDelay = static_cast<int> (state->Slider012Value);
        if (tempDelay != gamestate->timer.getDelay()) {
            gamestate->timer.setDelay(tempDelay);
        }
        
        
        // Ugly Hack
        // Both GUI and mousetools overwrite squaresize -> changes are immediatly overwritten by the other function
        // Cheap flag in gamestate determines whether mouse wheel has been used or not and therefore decides if GUI can overwrite value
        // If mouse wheel has been used, GUISlider needs to be changed to current squaresize value so it doesnt overwrite in next frame
        // But: All other sliders are NOT aware of gamestate changes! Reconsider

        if (gamestate->mousetools->mouseWheelZoomTriggered) {
            // Do not change squaresize and change slider value to new squaresize value
            state->Slider025Value = static_cast<float>(gamestate->getSquareSize());
        }
        // Set Square Size via GUI if mouse wheel zoom isn't used
        else gamestate->squareSize = static_cast<int> (state->Slider025Value);
        


        
        // Set Brush Radius
        gamestate->mousetools->setBrushRadius(static_cast<int> (state->SliderBar015Value));

        // Set Array Size
        // reInitialize is only called when GUI input doesnt match gamestate
        if ((gamestate->gridArray.getSizeX() != static_cast<unsigned int> (state->Slider017Value))
            ||
            (gamestate->gridArray.getSizeY() != static_cast<unsigned int> (state->Slider018Value)))
        {

            gamestate->gridArray.reInitialize(static_cast<unsigned int> (state->Slider017Value), 
                                              static_cast<unsigned int> (state->Slider018Value));
        }

        // Set Checkboxes
        gamestate->drawRectangleOutline = state->CheckBoxEx033Checked;
        gamestate->drawBrushRadiusPreview = state->CheckBoxEx034Checked;

        // Check Tool Selection
        checkToolSelection(state, gamestate);



    }

    // Hide UI if [x] is clicked
    if (!(state->WindowBox000Active)) {
        gamestate->UIHidden = true;
        guimaster->draw_hidden_ui_message = true;
        guimaster->draw_main_window = false;
    }

}

