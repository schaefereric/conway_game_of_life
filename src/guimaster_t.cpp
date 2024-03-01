#include "guimaster_t.hpp"

// Forward Declarations
// Init Functions
GuiGameOfLifeState InitGuiGameOfLife();
GuiDebugMouseState InitGuiDebugMouse();
GuiDebugLogicState InitGuiDebugLogic();
// Draw Functions
void               GuiGameOfLife(gamestate_t& gamestate, GuiGameOfLifeState* state);
void               GuiDebugMouse(gamestate_t& gamestate, GuiDebugMouseState* state);
void               GuiDebugLogic(gamestate_t& gamestate, GuiDebugLogicState* state);


guimaster_t::guimaster_t() {
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

void guimaster_t::draw(gamestate_t & gamestateRef) {
    if (draw_debug_main) {
        GuiGameOfLife(gamestateRef, &guistate_debug_main);
    }

    if (draw_debug_mouse) {
        GuiDebugMouse(gamestateRef, &guistate_debug_mouse);
    }
    
    if (draw_debug_logic) {
        GuiDebugLogic(gamestateRef, &guistate_debug_logic);
    }
    
}
