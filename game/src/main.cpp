#include "raylib.h"
#include "raymath.h"
#include <vector>
#define RAYGUI_IMPLEMENTATION
#include "raygui.h"

class PhysicsBody {
public:
    Vector2 position;
    Vector2 velocity;
    float drag;
    float mass;

    PhysicsBody(Vector2 pos = { 0,0 }, Vector2 vel = { 0,0 }, float d = 0.0f, float m = 1.0f) {
        position = pos;
        velocity = vel;
        drag = d;
        mass = m;
    }

    void Update(float dt, Vector2 gravity) {
        // Apply gravity to velocity
        velocity.x += gravity.x * dt;
        velocity.y += gravity.y * dt;

        // Apply drag (currently 0)
        //velocity.x *= (1.0f - drag * dt);
        //velocity.y *= (1.0f - drag * dt);

        // Update position
        position.x += velocity.x * dt;
        position.y += velocity.y * dt;
    }
};

class PhysicsSimulation {
public:
    float deltaTime;
    float time;
    Vector2 gravity;

    PhysicsSimulation(float dt = 1.0f / 60.0f, Vector2 g = { 0, 200 }) {
        deltaTime = dt;
        time = 0;
        gravity = g;
    }

    void Update(PhysicsBody& body) {
        body.Update(deltaTime, gravity);
        time += deltaTime;
    }
};

const unsigned int TARGET_FPS = 50;
PhysicsSimulation sim(1.0f / TARGET_FPS, { 0, 200 });
//PhysicsBody ball({ 100, 500 }, { 0, 0 }, 0.01f, 1.0f);

std::vector<PhysicsBody> balls;
float launchAngle = 90.0f;   // degrees
float launchSpeed = 200.0f; 
Vector2 launchPosition = { 100, 700 }; // start position

void LaunchBall() {
    PhysicsBody newBall;
    newBall.position = launchPosition;
    newBall.velocity = {
        launchSpeed * cosf(launchAngle * DEG2RAD),
        -launchSpeed * sinf(launchAngle * DEG2RAD)
    };
    balls.push_back(newBall); // add new ball to vector
}


void update() {

    if (IsKeyPressed(KEY_SPACE)) {  //spawn demon
        LaunchBall(); // Add new ball
    }

    for (auto& ball : balls) {
        sim.Update(ball);  // physics update each frame
    }
   // sim.Update(ball);  // physics update each frame
}


void draw() {
    BeginDrawing();
    ClearBackground(BLACK);

    // draw the little demon(s)
    for (auto& ball : balls) {
        DrawCircleV(ball.position, 15, RED);
    }

    // Slide controls
    GuiSliderBar(Rectangle{ 10, 40, 200, 20 }, "Angle", TextFormat("%.0f", launchAngle), &launchAngle, -180, 180);
    GuiSliderBar(Rectangle{ 10, 70, 200, 20 }, "Speed", TextFormat("%.0f", launchSpeed), &launchSpeed, 0, 400);
    GuiSliderBar(Rectangle{ 10, 100, 200, 20 }, "Gravity X", TextFormat("%.1f", sim.gravity.x), &sim.gravity.x, -1000, 1000);  //you have no idea how confused I got doing x vs y
    GuiSliderBar(Rectangle{ 10, 130, 200, 20 }, "Gravity Y", TextFormat("%.1f", sim.gravity.y), &sim.gravity.y, -1000, 1000);

    // Press space to yeet bird
    DrawText(TextFormat("Time: %.2f", sim.time), GetScreenWidth() - 200, 20, 20, LIGHTGRAY);
    DrawText("Press SPACE to launch birdie", 10, GetScreenHeight() - 40, 20, LIGHTGRAY);


    Vector2 launchVel = {
        launchSpeed * cosf(launchAngle * DEG2RAD),
        -launchSpeed * sinf(launchAngle * DEG2RAD)
    };
    DrawLineEx(launchPosition, launchPosition + launchVel * 0.2f, 3, PURPLE);

    EndDrawing();
}

int main() {
    InitWindow(1200, 800, "Physics Labs : Susana CM 101542567");
    SetTargetFPS(TARGET_FPS);

    while (!WindowShouldClose()) {
        update();
        draw();
    }

    CloseWindow();
    return 0;
}
