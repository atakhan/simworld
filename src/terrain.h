#ifndef SIMWORLD_SRC_TERRAIN_H
#define SIMWORLD_SRC_TERRAIN_H

#include <iostream>

#include <raylib-cpp.hpp>

#include "tile.h"
#include "heightmap.h"
#include "tilemap.h"

class Terrain {
    const size_t AREA_WIDTH = 70;
    const size_t AREA_HEIGHT = 40;
    const int CELL_WIDTH = 8;
    const int CELL_HEIGHT = 8;

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
