#include <iostream>
#include <stdlib.h>
#include <vector>
#include <string>

#include <random>

#include <raylib-cpp.hpp>

#include "scene.h"

int main() {
    raylib::Window window(1200, 800, "SimWorld");

    Scene scene;
    scene.Init();

    SetTargetFPS(60);

    while (!window.ShouldClose())
    {
        // Update
        scene.Update();

        // Draw
        BeginDrawing();
            ClearBackground(RAYWHITE);
            scene.Draw();
        EndDrawing();
    }

    return 0;
}