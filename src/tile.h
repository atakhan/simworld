#ifndef SIMWORLD_SRC_TILE_H
#define SIMWORLD_SRC_TILE_H

#include <iostream>

#include <raylib-cpp.hpp>

class Tile {
  public:

    Tile(const raylib::Rectangle &rec, raylib::Color col, int height = 0);

    void updatePosition(float x, float y);
    void updateSize(float width, float height);
    void updateHeight(int height);
    void updateColorByHeightValue(int value);
    raylib::Color getColor() {return color_;}
    raylib::Color getHeight() {return height_;}

    void Draw();
 
  private:
    raylib::Rectangle rectangle_;
    raylib::Color color_;
    int height_;
};

#endif  // A1_MAZE_1_0_SRC_MAZE_PARSER_H
