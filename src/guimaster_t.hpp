#pragma once

// -------------------------------------------
// This Header file has to be included only AFTER 
// the gui_implementation headers have
// already been included in main.cpp !
// -------------------------------------------

// This class stores the "guistates" for all GUIs, initializes, manages and draws them.
// All guistates are initialized in constuctor and GUIs can be drawn via draw();.

#include "gui_structs.hpp"
#include "gamestate_t.hpp"

// Forward Declarations
struct GuiGameOfLifeState;
struct GuiDebugMouseState;
struct GuiDebugLogicState;

struct guimaster_t
{
    gamestate_t* gamestate;

    GuiGameOfLifeState guistate_debug_main;             // Debug Main Window
    GuiDebugMouseState guistate_debug_mouse;            // Debug Mouse Window
    GuiDebugLogicState guistate_debug_logic;            // Debug Logic Window

    // decides whether this window should be visible or not
    bool draw_debug_main;
    bool draw_debug_mouse;
    bool draw_debug_logic;

    guimaster_t(gamestate_t* gamestateRef);

    // initialize the gui structs with default values
    void init();

    // executes the drawcalls for all visible windows
    void draw();

};

