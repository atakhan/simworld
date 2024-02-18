#ifndef SIMWORLD_SRC_TILE_H
#define SIMWORLD_SRC_TILE_H

#include <iostream>

#include <raylib-cpp.hpp>

class Tile {
  public:

    Tile(const raylib::Rectangle &rec, raylib::Color col, size_t h);

    void updatePosition(float x, float y);
    void updateSize(float width, float height);
    void updateColor(raylib::Color color);
    void updateHeight(int height);

    void Draw();
 
  private:
    raylib::Rectangle rectangle_;
    raylib::Color color_;
    size_t height_;
};

#endif  // A1_MAZE_1_0_SRC_MAZE_PARSER_H
