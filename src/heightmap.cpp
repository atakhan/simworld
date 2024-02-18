#include "heightmap.h"

HeightMap::HeightMap(size_t w, size_t h)
    : width_(w)
    , height_(h)
{}

int HeightMap::GetRandomIntBetween(int min, int max) {
    return min + (rand() % static_cast<int>(max - min + 1));
}

void HeightMap::Generate() {
    for (size_t i = 0; i < width_; i++)
    {
        for (size_t j = 0; j < height_; j++)
        {
            data_.push_back(GetRandomIntBetween(1,9));
        }
    }

}