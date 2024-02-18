#include "tile.h"

Tile::Tile(const raylib::Rectangle &rec, raylib::Color col) 
    : rectangle_(rec)
    , color_(col)
{};

void Tile::updatePosition(float x, float y) {
    rectangle_.SetX(x);
    rectangle_.SetY(y);
}

void Tile::updateSize(float w, float h) {
    rectangle_.SetWidth(w);
    rectangle_.SetHeight(h);
}
void Tile::updateColorByHeightValue(int heightValue) {
    switch (heightValue)
    {
        case 1:
            color_ = LIGHTGRAY;
            break;
        case 2:
            color_ = GRAY;
            break;
        case 3:
            color_ = DARKGRAY;
            break;
        case 4:
            color_ = YELLOW;
            break;
        case 5:
            color_ = GOLD;
            break;
        case 6:
            color_ = ORANGE;
            break;
        case 7:
            color_ = PINK;
            break;
        case 8:
            color_ = GREEN;
            break;
        case 9:
            color_ = MAROON;
            break;
    
        default:
            color_ = GRAY;
            break;
    }
}

void Tile::Draw() {
    DrawRectangle(
        rectangle_.GetX(),
        rectangle_.GetY(),
        rectangle_.GetWidth(), 
        rectangle_.GetHeight(), 
        color_
    );
}
