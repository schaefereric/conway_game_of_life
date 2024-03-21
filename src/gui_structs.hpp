#pragma once
#include <raylib.h>

// Main Window
struct GuiMainWindowState {
    Vector2 anchor01;
    Vector2 anchor02;

    bool WindowBox000Active;
    bool Toggle012Active;      // paint
    bool Toggle013Active;      // spray
    bool Toggle014Active;      // move grid
    bool Toggle015Active;      // erase
    float Slider012Value;      // speed
    float SliderBar015Value;   // brush radius
    float Slider017Value;      // array size x
    float Slider018Value;      // array size y
    float Slider025Value;      // square size
    bool CheckBoxEx033Checked; // rectangle outline
    bool CheckBoxEx034Checked; // preview for brush radius


    Rectangle layoutRecs[35];

    char isGameRunning[10];
    char array_size_x[6];
    char array_size_y[6];
    char brushradius_buffer[6];
    char squaresize_buffer[6];
    char speed_buffer[10];
};

// "Hidden UI" Message
struct GuiHiddenState {
    Rectangle layoutRecs[3];
};

// Debug Main
struct GuiDebugMainState {
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

    Rectangle layoutRecs[41];
};

// Debug Mouse
struct GuiDebugMouseState {
    Vector2 anchor01;

    bool WindowBox000Active;
    int Brush_select_ListViewScrollIndex;
    int Brush_select_ListViewActive;

    Rectangle layoutRecs[20];
};

// Debug Logic
struct GuiDebugLogicState {
    Vector2 anchor01;

    bool WindowBox000Active;
    bool Spinner002EditMode;
    int Spinner002Value;
    bool Spinner003EditMode;
    int Spinner003Value;
    bool DropdownBox004EditMode;
    int DropdownBox004Active;

    Rectangle layoutRecs[19];

    char moore_x_buffer[10];
    char moore_y_buffer[10];
    char counted_neighbors[5];
    char state_of_square[10];
};
