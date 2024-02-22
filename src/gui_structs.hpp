#pragma once
#include <raylib.h>

// Debug Main
struct GuiGameOfLifeState {
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
};

// Debug Mouse
struct GuiDebugMouseState {
    Vector2 anchor01;

    bool WindowBox000Active;
    int Brush_select_ListViewScrollIndex;
    int Brush_select_ListViewActive;

    Rectangle layoutRecs[20];
};