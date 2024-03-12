#include "guimaster_t.hpp"

// Forward Declarations
// Init Functions
GuiMainWindowState InitGuiMainWindow();
GuiDebugMainState  InitGuiDebugMain();
GuiDebugMouseState InitGuiDebugMouse();
GuiDebugLogicState InitGuiDebugLogic();
// Draw Functions
void               GuiMainWindow(gamestate_t* gamestate, GuiMainWindowState* state);
void               GuiDebugMain (gamestate_t* gamestate, GuiDebugMainState*  state);
void               GuiDebugMouse(gamestate_t* gamestate, GuiDebugMouseState* state);
void               GuiDebugLogic(gamestate_t* gamestate, GuiDebugLogicState* state);


guimaster_t::guimaster_t(gamestate_t* gamestateRef) {
    gamestate = gamestateRef;

    draw_main_window = true;
    draw_debug_main  = false;
    draw_debug_mouse = false;
    draw_debug_logic = false;
    this->init();
}

void guimaster_t::init() {
    guistate_main_window = InitGuiMainWindow();
    guistate_debug_main  = InitGuiDebugMain();
    guistate_debug_mouse = InitGuiDebugMouse();
    guistate_debug_logic = InitGuiDebugLogic();
}

void guimaster_t::draw() {
    if (draw_main_window) {
        GuiMainWindow(gamestate, &guistate_main_window);
    }

    if (draw_debug_main) {
        GuiDebugMain(gamestate, &guistate_debug_main);
    }

    if (draw_debug_mouse) {
        GuiDebugMouse(gamestate, &guistate_debug_mouse);
    }
    
    if (draw_debug_logic) {
        GuiDebugLogic(gamestate, &guistate_debug_logic);
    }
    
}
