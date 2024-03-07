#include "terrain.h"

Terrain::Terrain()
    : tile_map_(AREA_WIDTH, AREA_HEIGHT, CELL_WIDTH, CELL_HEIGHT)
    , height_map_(AREA_WIDTH, AREA_HEIGHT) 
{}

void Terrain::Init() {
    height_map_.Generate();
    height_map_.MakeErosion();
    tile_map_.Generate();
    tile_map_.ApplyHeightMap(&height_map_);
}

void Terrain::Draw() {
    tile_map_.Draw();
}

void Terrain::Update() {
    tile_map_.Update();
}