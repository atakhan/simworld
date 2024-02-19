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
            color_ = raylib::Color(0,0,0,255);
            break;
        case 2:
            color_ = raylib::Color(20,20,20,255);
            break;
        case 3:
            color_ = raylib::Color(40,40,40,255);
            break;
        case 4:
            color_ = raylib::Color(60,60,60,255);
            break;
        case 5:
            color_ = raylib::Color(80,80,80,255);
            break;
        case 6:
            color_ = raylib::Color(100,100,100,255);
            break;
        case 7:
            color_ = raylib::Color(120,120,120,255);
            break;
        case 8:
            color_ = raylib::Color(140,140,140,255);
            break;
        case 9:
            color_ = raylib::Color(160,160,160,255);
            break;
        case 10:
            color_ = raylib::Color(180,180,180,255);
            break;
        case 11:
            color_ = raylib::Color(200,200,200,255);
            break;
        case 12:
            color_ = raylib::Color(220,220,220,255);
            break;
        case 13:
            color_ = raylib::Color(255,255,255,255);
            break;
    
        default:
            color_ = RED;
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
