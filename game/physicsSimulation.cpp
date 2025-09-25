//
////This project uses the Raylib framework to handle graphics, input, GUI, etc.
////Documentation here: https://www.raylib.com/examples.html https://www.raylib.com/index.html
//
//#include "raylib.h"
//#include "raymath.h"
//#define RAYGUI_IMPLEMENTATION
//#include "raygui.h"
//#include "game.h"
//
//const unsigned int TARGET_FPS = 50;
//float time = 0;
//float dt;
//float x = 500;
//float y = 500;
//float frequency = 1.0f;
//float amplitude = 70;
//float speed = 100;
//float angle = 0;
//float startPosX = 500;
//float startPosY = 400;
//
//Vector2 position = { 500, 500 };
//Vector2 velocity = { 0,0 };
//Vector2 accelerationGravity = { 0, 9 };
//
//class physicsSimulation {
//public:
//
//    float dt;
//    float time;
//    float gravity;
//
//
//    class physicsBody {
//
//        float posX;
//        float posY;
//        float vel;
//        float drag;
//        float mass;
//
//        void update() {
//
//
//        }
//    };
//};
//
//
////Change world state
//void update() {
//
//    dt = 1.0 / TARGET_FPS;
//    time += dt;
//
//    //vel = change in position / time, therefore     change in position = vel * time 
//    position = position + velocity * dt;
//
//    //accel = deltaV / time (change in velocity over time) therefore     deltaV = accel * time
//    velocity = velocity + accelerationGravity * dt;
//
//    if (IsKeyPressed(KEY_SPACE))
//    {
//        position = { 100, (float)GetScreenHeight() - 100 };
//        velocity = { speed * (float)cos(angle * DEG2RAD), -speed * (float)sin(angle * DEG2RAD) };
//    }
//
//    //x = x + (-sin(time * frequency)) * frequency * amplitude * dt;
//    //y = y + (cos(time * frequency)) * frequency * amplitude * dt;
//}
//
////Display world state
//void draw() {
//    BeginDrawing();
//    ClearBackground(BLACK);
//    DrawText("nuh uh", 10, 20, 20, WHITE);
//
//
//    // GuiSliderBar(Rectangle{ 10, 15, 1000, 20 }, "", TextFormat("%.2f", time), &time, 0, 240);
//    DrawText(TextFormat("FPS: %.2i, TIME: %.2f", TARGET_FPS, time), GetScreenWidth() - 200, 30, 15, LIGHTGRAY);
//
//    //DrawCircle(x, y, 25, RED);
//
//    GuiSliderBar(Rectangle{ 10, 120, 500, 30 }, "Gravity Y", TextFormat("Gravity Y: %.0f Px/sec^2", accelerationGravity.y), &accelerationGravity.y, -1000, 1000);
//
//    //GuiSliderBar(Rectangle{ 10, 40, 200, 20 }, "", TextFormat("%.0f", speed), &speed, -100, 1000);
//
//    GuiSliderBar(Rectangle{ 10, 60, 200, 20 }, "Angle", TextFormat("Angle: %.0f Degrees", angle), &angle, -180, 180);
//    //GuiSliderBar(Rectangle{ 10, 60, 200, 20 }, "", TextFormat("%.0f", angle), &angle, -180, 180);
//    //GuiSliderBar(Rectangle{ 10, 80, 200, 20 }, "", TextFormat("%.0f", startPosX), &startPosX, 100, GetScreenWidth() - 100);
//    //GuiSliderBar(Rectangle{ 10, 100, 200, 20 }, "", TextFormat("%.0f", startPosY), &startPosY, 100, GetScreenHeight() - 100);
//
//    DrawText(TextFormat("T: %6.2f", time), GetScreenWidth() - 140, 10, 30, LIGHTGRAY);
//
//    Vector2 startPos = { 100, GetScreenHeight() - 100 };
//
//    Vector2 velocity = { speed * cos(angle * DEG2RAD), -speed * sin(angle * DEG2RAD) };
//
//    DrawLineEx(startPos, startPos + velocity, 3, RED);
//
//
//    //DrawCircle(x, y, 70, RED);
//    //DrawCircle(500 + cos(time * frequency) * amplitude, 500 + sin(time * frequency) * amplitude, 70, GREEN);
//    DrawCircle(position.x, position.y, 15, RED);
//
//    EndDrawing();
//
//
//}
//
//int main()
//{
//    InitWindow(InitialWidth, InitialHeight, "Physics Labs : Susana CM 101542567");
//    SetTargetFPS(TARGET_FPS);
//
//    while (!WindowShouldClose())
//    {
//        update();
//        draw();
//    }
//
//    CloseWindow();
//    return 0;
//}
