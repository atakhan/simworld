#include <iostream>
#include <stdlib.h>
#include <vector>
#include <string>
#include <raylib-cpp.hpp>


struct Pen {
    raylib::Color color;
    Pen(raylib::Color c) : color(c) {}
};

struct DrawTools {
    Pen pen;
    DrawTools() : pen(LIGHTGRAY) {} 
};



struct Settings {
    unsigned screenWidth;
    unsigned screenHeight;
    unsigned cellWidth;
    unsigned cellHeight;
    unsigned landscapeWidth;
    unsigned landscapeHeight;

    Settings(unsigned sw, unsigned sh, unsigned lw, unsigned lh, unsigned cw, unsigned ch)
        : screenWidth(sw)
        , screenHeight(sh)
        , cellWidth(cw)
        , cellHeight(ch)
        , landscapeWidth(lw)
        , landscapeHeight(lh)
    {}
};

struct Cell {
    DrawTools drawTools;
    unsigned x = 0;
    unsigned y = 0;
    unsigned width = 0;
    unsigned height = 0;

    Cell();
    Cell(unsigned x_, unsigned y_, unsigned w, unsigned h)
        : x(x_)
        , y(y_)
        , width(w)
        , height(h)
        , drawTools()
        {}

    void Draw() {
        drawTools.pen.color.DrawRectangle(x, y, width, height);
    }
};

struct Landscape {
    Settings *settings;
    DrawTools drawTools;
    std::vector<Cell> surface;
    
    unsigned width;
    unsigned height;


    Landscape(Settings *s) 
        : settings(s)
        , drawTools() 
        , surface()
        , width(s->landscapeWidth)
        , height(s->landscapeHeight)
        {}

    void generateSurface() {
        surface.clear();
        for (size_t i = 0; i < height; i++)
        {
            for (size_t j = 0; j < width; j++)
            {
                Cell cell(
                    (unsigned) (j * settings->cellWidth + (10 + j)),
                    (unsigned) (i * settings->cellHeight + (10 + i)),
                    settings->cellWidth,
                    settings->cellHeight
                );
                surface.push_back(std::move(cell));
            }
        }
    }

    void Update() {}

    void Draw() {
        for (auto & cell : surface) {
            cell.Draw();
        }
    }
};


struct Game {
    Settings *settings;
    raylib::Window window;
    Landscape landscape;

    Game(Settings *s)
        : settings(s)
        , landscape(s)
        , window(s->screenWidth, s->screenHeight, "SimWorld") 
        {}

    void Init() {
        landscape.generateSurface();
    }

    void Update() {}

    void Draw() {
        landscape.Draw();
    }
};


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