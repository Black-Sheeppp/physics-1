//This project uses the Raylib framework to handle graphics, input, GUI, etc.
//Documentation here: https://www.raylib.com/examples.html https://www.raylib.com/index.html

#include "raylib.h"
#include "raymath.h"
#define RAYGUI_IMPLEMENTATION
#include "raygui.h"
#include "game.h"

const unsigned int TARGET_FPS = 50;
float time = 0;
float dt;
float x = 500;
float y = 500;
float frequency = 1.0f;
float amplitude = 70;

//Change world state
void update() {

    dt = 1.0 / TARGET_FPS;
    time += dt;

    x = x + (-sin(time * frequency)) * frequency * amplitude * dt;
    y = y + (cos(time * frequency)) * frequency * amplitude * dt;
}

//Display world state
void draw() {
    BeginDrawing();
    ClearBackground(DARKPURPLE);
    DrawText("nuh uh", 10, 20, 20, LIGHTGRAY);


    GuiSliderBar(Rectangle{ 60, 5, 1000, 10 }, "Time", TextFormat("%.2f", time), &time, 0, 240);
    DrawText(TextFormat("FPS: %.2i, TIME: %.2f", TARGET_FPS, time), GetScreenWidth() - 200, 30, 15, LIGHTGRAY);

    DrawCircle(x, y, 25, RED);

    EndDrawing();
}

int main()
{
    InitWindow(InitialWidth, InitialHeight, "Physics Labs : Susana CM 101542567");
    SetTargetFPS(TARGET_FPS);

    while (!WindowShouldClose())
    {
        update();
        draw();
    }

    CloseWindow();
    return 0;
}