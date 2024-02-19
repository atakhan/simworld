#include "tilemap.h"

TileMap::TileMap(size_t area_w, size_t area_h, int cell_w, int cell_h)
    : width_(area_w)
    , height_(area_h)
    , cell_width_(cell_w)
    , cell_height_(cell_h)
{}

void TileMap::Generate() {
    tiles_.reserve(width_ * height_);
    for (size_t i = 0; i < width_; i++) {
        for (size_t j = 0; j < height_; j++) {
            float cell_width = static_cast<float>(cell_width_);
            float cell_height = static_cast<float>(cell_height_);

            float pos_x = i * cell_width;
            float pos_y = j * cell_height;

            raylib::Rectangle rectanlge(
                raylib::Vector2 {pos_x, pos_y}, 
                raylib::Vector2 {cell_width, cell_height}
            );

            tiles_.push_back(Tile(rectanlge, LIGHTGRAY));
        }
    }
}

void TileMap::ApplyHeightMap(HeightMap *map) {
    size_t index = 0;

    for (size_t i = 0; i < width_; i++) {
        for (size_t j = 0; j < height_; j++) {
            int heightValue = map->GetData().at(index);
            tiles_.at(index).updateColorByHeightValue(heightValue);
            index++;
        }
    }
}

raylib::Color TileMap::GetNW(size_t i, size_t j) {
    if (i < 1 || j < 1) {
        return WHITE;
    }
    size_t index = ((i - 1) * (j - 1)) + (j - 1);

    return tiles_.at(index).getColor();
}

raylib::Color TileMap::GetN(size_t i, size_t j) {
    if (j < 1) {
        return WHITE;
    }
    size_t index = ((i - 1) * (j)) + (j);

    return tiles_.at(index).getColor();
}


raylib::Color TileMap::GetNE(size_t i, size_t j) {
    if (i < 1 || j >= width_ - 1) {
        return WHITE;
    }
    size_t index = ((i - 1) * (j + 1)) + (j + 1);

    return tiles_.at(index).getColor();
}

raylib::Color TileMap::GetE(size_t i, size_t j) {
    if (j < 1) {
        return WHITE;
    }
    size_t index = ((i) * (j - 1)) + (j - 1);

    return tiles_.at(index).getColor();
}

raylib::Color TileMap::GetSE(size_t i, size_t j) {
    if (j < 1) {
        return WHITE;
    }
    size_t index = ((i) * (j - 1)) + (j - 1);

    return tiles_.at(index).getColor();
}

raylib::Color TileMap::GetS(size_t i, size_t j) {
    if (j < 1) {
        return WHITE;
    }
    size_t index = ((i) * (j - 1)) + (j - 1);

    return tiles_.at(index).getColor();
}

raylib::Color TileMap::GetSW(size_t i, size_t j) {
    if (j < 1) {
        return WHITE;
    }
    size_t index = ((i) * (j - 1)) + (j - 1);

    return tiles_.at(index).getColor();
}

raylib::Color TileMap::GetW(size_t i, size_t j) {
    if (j < 1) {
        return WHITE;
    }
    size_t index = ((i) * (j - 1)) + (j - 1);

    return tiles_.at(index).getColor();
}

void TileMap::ParseNeighbors(size_t i, size_t j, std::vector<raylib::Color> *neigbors) {
    neigbors->push_back(GetNW(i, j));
    neigbors->push_back(GetN(i, j));
    neigbors->push_back(GetNE(i, j));
    neigbors->push_back(GetE(i, j));
    neigbors->push_back(GetSE(i, j));
    neigbors->push_back(GetS(i, j));
    neigbors->push_back(GetSW(i, j));
    neigbors->push_back(GetW(i, j));
}

void TileMap::ApplyErosionRules(std::vector<raylib::Color> *neighbors) {

}

void TileMap::MakeErosion() {
    size_t index = 0;

    for (size_t i = 0; i < width_; i++) {
        for (size_t j = 0; j < height_; j++) {
            raylib::Color color = tiles_.at(index).getColor();
            std::vector<raylib::Color> neigbors;
            ParseNeighbors(i, j, &neigbors);
            ApplyErosionRules(&neigbors);
            // tiles_.at(index).updateColorByHeightValue(heightValue);
            index++;
        }
    }
}

void TileMap::Draw() {
    size_t tile_id = 0;
    for (size_t i = 0; i < width_; i++) {
        for (size_t j = 0; j < height_; j++) {
            tiles_.at(tile_id).Draw();
            tile_id++;
        }
    }    
    tile_id = 0;
}

void TileMap::Update() {
    size_t index = 0;
    for (size_t i = 0; i < width_; i++) {
        for (size_t j = 0; j < height_; j++) {
            float pos_x = i * cell_width_ + i;
            float pos_y = j * cell_height_ + j;
            float width = cell_width_;
            float height = cell_height_;
            
            raylib::Color color = tiles_.at(index).getColor();

            raylib::Rectangle rectanlge(
                raylib::Vector2 {pos_x, pos_y}, 
                raylib::Vector2 {width, height}
            );

            tiles_.push_back(Tile(rectanlge, color));
        }
    }
}