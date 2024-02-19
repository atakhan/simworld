#ifndef SIMWORLD_SRC_TILEMAP_H
#define SIMWORLD_SRC_TILEMAP_H

#include <iostream>

#include <vector>

#include "tile.h"
#include "heightmap.h"

class TileMap {
  public:
    TileMap(size_t area_w, size_t area_h, int cell_w, int cell_h);

    void Generate();
    void Draw();
    void Update();

    void ParseNeighbors(size_t i, size_t j, std::vector<raylib::Color> *neigbors);
    void ApplyHeightMap(HeightMap *map);
    void MakeErosion();
    void ApplyErosionRules(std::vector<raylib::Color> *neighbors);
    raylib::Color GetNW(size_t i, size_t j);
    raylib::Color GetN(size_t i, size_t j);
    raylib::Color GetNE(size_t i, size_t j);
    raylib::Color GetE(size_t i, size_t j);
    raylib::Color GetSE(size_t i, size_t j);
    raylib::Color GetS(size_t i, size_t j);
    raylib::Color GetSW(size_t i, size_t j);
    raylib::Color GetW(size_t i, size_t j);

  private:
    size_t width_;
    size_t height_;
    int cell_width_;
    int cell_height_;

    std::vector<Tile> tiles_;
};

#endif  // SIMWORLD_SRC_TILEMAP_H