#include <iostream>
#include <stdlib.h>
#include <vector>
#include <string>

#include <random>

#include <raylib-cpp.hpp>

#include "tile.h"
#include "scene.h"

const size_t AREA_WIDTH = 70;
const size_t AREA_HEIGHT = 40;
const int CELL_WIDTH = 8;
const int CELL_HEIGHT = 8;

int main() {
    raylib::Window window(700, 400, "SimWorld");
    std::vector<Tile> tiles;

    Scene scene(&tiles);

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