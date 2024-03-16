#include "tile.h"

Tile::Tile(const raylib::Rectangle &rec, raylib::Color col, int height) 
    : rectangle_(rec)
    , color_(col)
    , height_(height)
{};

void Tile::updatePosition(float x, float y) {
    rectangle_.SetX(x);
    rectangle_.SetY(y);
}

void Tile::updateSize(float w, float h) {
    rectangle_.SetWidth(w);
    rectangle_.SetHeight(h);
}

void Tile::updateHeight(int height) {
    height_ = height;
}

void Tile::updateColorByHeightValue(int heightValue) {
    color_ = raylib::Color(heightValue, heightValue, heightValue, 255);
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
