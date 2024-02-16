#include "structs.h"

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
                    (float) (j * settings->cellWidth + (10 + j)),
                    (float) (i * settings->cellHeight + (10 + i)),
                    (float) settings->cellWidth,
                    (float) settings->cellHeight
                );

                surface.push_back(std::move(cell));
            }
        }
    }

    void Update() {
        Vector2 mousePos = GetMousePosition();
        for (auto & cell : surface) {
            if (CheckCollisionPointRec(mousePos, cell.rect)) {
                cell.color = DARKGREEN;
            } else {
                cell.color = LIGHTGRAY;
            }
        }

    }

    void Draw() {
        for (auto & cell : surface) {
            cell.Draw();
        }
    }
};