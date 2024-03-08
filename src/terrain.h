#ifndef SIMWORLD_SRC_TERRAIN_H
#define SIMWORLD_SRC_TERRAIN_H

#include <iostream>

#include <raylib-cpp.hpp>

#include "heightmap.h"
#include "tilemap.h"

class Terrain {
  const size_t AREA_WIDTH = 80;
  const size_t AREA_HEIGHT = 60;
  const int CELL_WIDTH = 12;
  const int CELL_HEIGHT = 12;

  public:
    Terrain();
    void Init();
    void Draw();
    void Update();

    void MakeErosion();
    void Regenerate();
  
  private:
    TileMap tile_map_;
    HeightMap height_map_;

    void GenerateTileMap();
    void GenerateHeightMap();
};

#endif  // SIMWORLD_SRC_TERRAIN_H
