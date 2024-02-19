#include "heightmap.h"

HeightMap::HeightMap(size_t w, size_t h)
    : width_(w)
    , height_(h)
{}

int HeightMap::GetRandomIntBetween(int min, int max) {
    return min + (rand() % static_cast<int>(max - min + 1));
}

void HeightMap::Generate() {
    GenerateNoise();
    SelectTopestNodes();
}

void HeightMap::SelectTopestNodes() {
    size_t index = 0;
    for (size_t i = 0; i < width_; i++) {
        for (size_t j = 0; j < height_; j++) {
            if ((data_.at(index) >= 0 ) && (data_.at(index) < 7)) {
                data_.at(index) = 3;
            } else if ((data_.at(index) >= 7 ) && (data_.at(index) < 13)) {
                data_.at(index) = 6;
            } else if ((data_.at(index) >= 13)) {
                data_.at(index) = 9;
            } else {
                data_.at(index) = 13;
            }
            index++;
        }
    }
}

void HeightMap::GenerateNoise() {
    for (size_t i = 0; i < width_; i++) {
        for (size_t j = 0; j < height_; j++) {
            int rand_val = 0;
            rand_val =  GetRandomValue(1, 13);
            data_.push_back(rand_val);
        }
    }

}