#include "guimaster_t.hpp"

// Forward Declarations
GuiGameOfLifeState InitGuiGameOfLife();
GuiDebugMouseState InitGuiDebugMouse();
void GuiGameOfLife(gamestate_t& gamestate, GuiGameOfLifeState* state);
void GuiDebugMouse(gamestate_t& gamestate, GuiDebugMouseState* state);


guimaster_t::guimaster_t() {
    draw_debug_main = true;
    draw_debug_mouse = true;
    this->init();
}

void guimaster_t::init() {
    guistate_debug_main  = InitGuiGameOfLife();
    guistate_debug_mouse = InitGuiDebugMouse();
}

void guimaster_t::draw(gamestate_t & gamestateRef) {
    if (draw_debug_main) {
        GuiGameOfLife(gamestateRef, &guistate_debug_main);
    }

    if (draw_debug_mouse) {
        GuiDebugMouse(gamestateRef, &guistate_debug_mouse);
    }
    
    
}
