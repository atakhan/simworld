#ifndef SIMWORLD_SRC_TERRAIN_H
#define SIMWORLD_SRC_TERRAIN_H

#include <iostream>

#include <raylib-cpp.hpp>

#include "heightmap.h"
#include "tilemap.h"

class Terrain {
  const size_t AREA_WIDTH = 160;
  const size_t AREA_HEIGHT = 120;
  const int CELL_WIDTH = 6;
  const int CELL_HEIGHT = 6;

  public:
    Terrain();
    void Init();
    void Draw();
    void Update();

    void MakeErosion();
    void ExpandPeaks();
    void Regenerate();
  
  private:
    TileMap tile_map_;
    HeightMap height_map_;

    void GenerateTileMap();
    void GenerateHeightMap();
};

#endif  // SIMWORLD_SRC_TERRAIN_H
