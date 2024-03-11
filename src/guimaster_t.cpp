#include "guimaster_t.hpp"

// Forward Declarations
// Init Functions
GuiGameOfLifeState InitGuiGameOfLife();
GuiDebugMouseState InitGuiDebugMouse();
GuiDebugLogicState InitGuiDebugLogic();
// Draw Functions
void               GuiGameOfLife(gamestate_t* gamestate, GuiGameOfLifeState* state);
void               GuiDebugMouse(gamestate_t* gamestate, GuiDebugMouseState* state);
void               GuiDebugLogic(gamestate_t* gamestate, GuiDebugLogicState* state);


guimaster_t::guimaster_t(gamestate_t* gamestateRef) {
    gamestate = gamestateRef;

    draw_debug_main = true;
    draw_debug_mouse = true;
    draw_debug_logic = true;
    this->init();
}

void guimaster_t::init() {
    guistate_debug_main  = InitGuiGameOfLife();
    guistate_debug_mouse = InitGuiDebugMouse();
    guistate_debug_logic = InitGuiDebugLogic();
}

void guimaster_t::draw() {
    if (draw_debug_main) {
        GuiGameOfLife(gamestate, &guistate_debug_main);
    }

    if (draw_debug_mouse) {
        GuiDebugMouse(gamestate, &guistate_debug_mouse);
    }
    
    if (draw_debug_logic) {
        GuiDebugLogic(gamestate, &guistate_debug_logic);
    }
    
}
