#include <iostream>
#include <stdlib.h>
#include <vector>
#include <string>
#include <raylib-cpp.hpp>

#include "game.h"

int main() {
    Settings settings(800, 450, 30, 25, 20, 16);
    Game game(&settings);

    game.Init();
    
    SetTargetFPS(60);

    while (!game.window.ShouldClose())
    {
        // Update
        game.Update();
        // Draw
        BeginDrawing();
            ClearBackground(RAYWHITE);
            game.Draw();
        EndDrawing();
    }

    return 0;
}