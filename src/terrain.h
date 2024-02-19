#ifndef SIMWORLD_SRC_TERRAIN_H
#define SIMWORLD_SRC_TERRAIN_H

#include <iostream>

#include <raylib-cpp.hpp>

#include "tile.h"
#include "heightmap.h"
#include "tilemap.h"

class Terrain {
  const size_t AREA_WIDTH = 40;
  const size_t AREA_HEIGHT = 30;
  const int CELL_WIDTH = 24;
  const int CELL_HEIGHT = 24;

  public:
    Terrain();
    void Init();
    void Draw();
    void Update();
  
  private:
    TileMap tile_map_;
    HeightMap height_map_;

    void GenerateTileMap();
    void GenerateHeightMap();
};

#endif  // SIMWORLD_SRC_TERRAIN_H
