#include "terrain.h"

Terrain::Terrain()
    : tile_map_(AREA_WIDTH, AREA_HEIGHT, CELL_WIDTH, CELL_HEIGHT)
    , height_map_(AREA_WIDTH, AREA_HEIGHT) 
{}

void Terrain::Init() {
    height_map_.Generate();
    tile_map_.Generate();
    tile_map_.ApplyHeightMap(&height_map_);
}

void Terrain::Draw() {
    tile_map_.Draw();
}

void Terrain::Update() {
    tile_map_.Update();
}

void Terrain::MakeErosion() {
    height_map_.MakeErosion();
    tile_map_.ApplyHeightMap(&height_map_);
}

void Terrain::Regenerate() {
    height_map_.Clear();
    height_map_.Generate();
    tile_map_.Generate();
    tile_map_.ApplyHeightMap(&height_map_);
    std::cout << "regenerate.." << std::endl;
}

void Terrain::Elevate() {
    height_map_.Elevate();
    tile_map_.ApplyHeightMap(&height_map_);
    std::cout << "regenerate.." << std::endl;
}
