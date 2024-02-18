#include "tilemap.h"

TileMap::TileMap(size_t area_w, size_t area_h, int cell_w, int cell_h) 
    : width_(area_w)
    , height_(area_h)
    , cell_width_(cell_w)
    , cell_height_(cell_h)
{

}

void TileMap::Generate() {
  tiles_.reserve(width_ * height_);

  for (size_t i = 0; i < width_; i++)
  {
      for (size_t j = 0; j < height_; j++)
      {
          float pos_x = i * cell_width_ + i;
          float pos_y = j * cell_height_ + j;
          float width = cell_width_;
          float height = cell_height_;
          size_t tile_height = 2;

          raylib::Rectangle rectanlge(
              raylib::Vector2 {pos_x, pos_y}, 
              raylib::Vector2 {width, height}
          );

          tiles_.push_back(Tile(rectanlge, LIGHTGRAY));
      }
  }
}

void TileMap::ApplyHeightMap(HeightMap *map) {
    raylib::Color color;
    for (size_t i = 0; i < map->Width(); i++)
    {
        for (size_t j = 0; j < map->Height(); j++)
        {
            int heightValue = map->GetData().at(i * j + j);
            
            tiles_.at(i * j + j).updateColorByHeightValue(heightValue);
        }
    }
}

void TileMap::Draw() {
    size_t tile_id = 0;
    for (size_t i = 0; i < width_; i++)
    {
        for (size_t j = 0; j < height_; j++)
        {
            tiles_.at(tile_id).Draw();
            tile_id++;
        }
    }    
    tile_id = 0;
}

void TileMap::Update() {
    for (size_t i = 0; i < width_; i++)
    {
        for (size_t j = 0; j < height_; j++)
        {
            float pos_x = i * cell_width_ + i;
            float pos_y = j * cell_height_ + j;
            float width = cell_width_;
            float height = cell_height_;
            
            raylib::Color color = tiles_.at(i * j + j).getColor();

            raylib::Rectangle rectanlge(
                raylib::Vector2 {pos_x, pos_y}, 
                raylib::Vector2 {width, height}
            );

            tiles_.push_back(Tile(rectanlge, color));
        }
    }
}