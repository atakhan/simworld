#include "scene.h"

Scene::Scene(std::vector<Tile> *tiles) : tiles_(tiles) {

}

void Scene::Init() {
    tiles_->reserve(AREA_WIDTH * AREA_HEIGHT);

    for (size_t i = 0; i < AREA_WIDTH; i++)
    {
        for (size_t j = 0; j < AREA_HEIGHT; j++)
        {
            float pos_x = i * CELL_WIDTH + i;
            float pos_y = j * CELL_HEIGHT + j;
            float width = CELL_WIDTH;
            float height = CELL_HEIGHT;
            size_t tile_height = 2;

            raylib::Rectangle rectanlge(
                raylib::Vector2 {pos_x, pos_y}, 
                raylib::Vector2 {width, height}
            );

            tiles_->push_back(Tile(rectanlge, LIGHTGRAY, 2));
        }
    }
}

void Scene::Draw() {
    size_t tile_id = 0;
    for (size_t i = 0; i < AREA_WIDTH; i++)
    {
        for (size_t j = 0; j < AREA_HEIGHT; j++)
        {
            tiles_->at(tile_id).Draw();
            tile_id++;
        }
    }    
    tile_id = 0;
}

void Scene::Update() {
    tiles_->clear();

    for (size_t i = 0; i < AREA_WIDTH; i++)
    {
        for (size_t j = 0; j < AREA_HEIGHT; j++)
        {
            float pos_x = i * CELL_WIDTH + i;
            float pos_y = j * CELL_HEIGHT + j;
            float width = CELL_WIDTH;
            float height = CELL_HEIGHT;
            raylib::Color color = LIGHTGRAY;

            raylib::Rectangle rectanlge(
                raylib::Vector2 {pos_x, pos_y}, 
                raylib::Vector2 {width, height}
            );

            size_t tile_height = 2;

            tiles_->push_back(Tile(rectanlge, color, tile_height));
        }
    }
}