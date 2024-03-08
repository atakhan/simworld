#include "heightmap.h"

HeightMap::HeightMap(int w, int h)
    : width_(w)
    , height_(h)
{}

int HeightMap::GetRandomIntBetween(int min, int max) {
    return min + (rand() % static_cast<int>(max - min + 1));
}

void HeightMap::Generate() {
    GenerateNoise();
}

void HeightMap::GenerateNoise() {
    for (int i = 0; i < width_; i++) {
        for (int j = 0; j < height_; j++) {
            int rand_val = GetRandomIntBetween(MIN_HEIGHT, MAX_HEIGHT);
            data_.push_back(rand_val);
        }
    }
}

void HeightMap::UpdateNW(int i, int j, int index) {
    if (index > height_) {
        int nw_index = index - height_ - 1;
        int currentCell = data_.at(index);
        int nw_cell = data_.at(nw_index);
        int diff = currentCell - nw_cell;
        if (diff < -ALLOW_DIFF) {
            data_.at(nw_index) = nw_cell - diff + ALLOW_DIFF;
        }
        if (diff > ALLOW_DIFF) {
            data_.at(nw_index) = nw_cell + diff - ALLOW_DIFF;
        }
    }
}

void HeightMap::UpdateNeighbors(int i, int j, int index) {
    UpdateNW(i, j, index);
}

void HeightMap::MakeErosion() {
    int index = 0;

    for (int i = 0; i < width_; i++) {
        for (int j = 0; j < height_; j++) {
            UpdateNeighbors(i, j, index);
            index++;
        }
    }
}
