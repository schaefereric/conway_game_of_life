#pragma once

// -------------------------------------------
// This Header file has to be included only AFTER 
// the gui_implementation headers have
// already been included in main.cpp !
// -------------------------------------------


#include "gui_structs.hpp"
#include "gamestate_t.hpp"

// Forward Declarations
struct GuiGameOfLifeState;
struct GuiDebugMouseState;

struct guimaster_t
{
    GuiGameOfLifeState guistate_debug_main;             // Debug Main Window
    GuiDebugMouseState guistate_debug_mouse;            // Debug Mouse Window

    bool draw_debug_main;
    bool draw_debug_mouse;

    guimaster_t();

    void init();

    void draw(gamestate_t& gamestateRef);

};

