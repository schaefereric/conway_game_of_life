#pragma once

// -------------------------------------------
// This Header file has to be included only AFTER 
// the gui_implementation headers have
// already been included in main.cpp !
// -------------------------------------------

// This class stores the "guistates" for all GUIs, initializes, manages and draws them.
// All guistates are initialized in constuctor and GUIs can be drawn via draw();.

#include "gamestate_t.hpp"
#include "gui_structs.hpp"


struct guimaster_t
{
    gamestate_t* gamestate;

    GuiMainWindowState guistate_main_window;            // Main Window
    GuiDebugMainState  guistate_debug_main;             // Debug Main 
    GuiDebugMouseState guistate_debug_mouse;            // Debug Mouse 
    GuiDebugLogicState guistate_debug_logic;            // Debug Logic 
    GuiHiddenState     guistate_hidden_ui;              // Displays message if Main Window is hidden

    // decides whether this window should be visible or not
    bool draw_main_window;
    bool draw_debug_main;
    bool draw_debug_mouse;
    bool draw_debug_logic;
    bool draw_hidden_ui_message;

    guimaster_t(gamestate_t* gamestateRef);

    // initialize the gui structs with default values
    void init();

    // executes the drawcalls for all visible windows
    void draw();

};

