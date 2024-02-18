#include "tile.h"

Tile::Tile(const raylib::Rectangle &rec, raylib::Color col, size_t h) 
    : rectangle_(rec)
    , color_(col)
    , height_(h)
{};

void Tile::updatePosition(float x, float y) {
    rectangle_.SetX(x);
    rectangle_.SetY(y);
}

void Tile::updateSize(float w, float h) {
    rectangle_.SetWidth(w);
    rectangle_.SetHeight(h);
}
void Tile::updateColor(raylib::Color c) {
    color_ = c;
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
