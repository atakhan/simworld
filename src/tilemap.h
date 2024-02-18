#ifndef SIMWORLD_SRC_TILEMAP_H
#define SIMWORLD_SRC_TILEMAP_H

#include <vector>

#include "tile.h"
#include "heightmap.h"

class TileMap {
  public:
    TileMap(size_t area_w, size_t area_h, int cell_w, int cell_h);

    void Generate();
    void Draw();
    void Update();

    void ApplyHeightMap(HeightMap *map);

  private:
    size_t width_;
    size_t height_;
    int cell_width_;
    int cell_height_;

    std::vector<Tile> tiles_;
};

#endif  // SIMWORLD_SRC_TILEMAP_H