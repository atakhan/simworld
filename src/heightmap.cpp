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
            int rand_val = 0;
            rand_val =  GetRandomValue(MIN_HEIGHT, MAX_HEIGHT);
            data_.push_back(rand_val);
        }
    }
}

void HeightMap::UpdateNW(int i, int j, int index) {
    if (i < 1 || j < 1) 
        return;
    
    int nw_index = ((i - 1) * (j - 1)) + (j - 1);
    // int currentCell = data_.at(i * width_ + j);
    // int neighborCell = data_.at(index);
    // int diff = currentCell - neighborCell;

    // if (diff < -2) {
        data_.at(nw_index) = -2;
        data_.at(index) = 1;
    // }

    // if (diff > 2) {
    //     data_.at(index) = 2;
    // }
}

// void HeightMap::UpdateN(int i, int j) {
//     if (j < 1) {
//         return WHITE;
//     }
//     int index = ((i - 1) * (j)) + (j);

//     return tiles_.at(index).getColor();
// }


// void HeightMap::UpdateNE(int i, int j) {
//     if (i < 1 || j >= width_ - 1) {
//         return WHITE;
//     }
//     int index = ((i - 1) * (j + 1)) + (j + 1);

//     return tiles_.at(index).getColor();
// }

// void HeightMap::UpdateE(int i, int j) {
//     if (j < 1) {
//         return WHITE;
//     }
//     int index = ((i) * (j - 1)) + (j - 1);

//     return tiles_.at(index).getColor();
// }

// void HeightMap::UpdateSE(int i, int j) {
//     if (j < 1) {
//         return WHITE;
//     }
//     int index = ((i) * (j - 1)) + (j - 1);

//     return tiles_.at(index).getColor();
// }

// void HeightMap::UpdateS(int i, int j) {
//     if (j < 1) {
//         return WHITE;
//     }
//     int index = ((i) * (j - 1)) + (j - 1);

//     return tiles_.at(index).getColor();
// }

// void HeightMap::UpdateSW(int i, int j) {
//     if (j < 1) {
//         return WHITE;
//     }
//     int index = ((i) * (j - 1)) + (j - 1);

//     return tiles_.at(index).getColor();
// }

// void HeightMap::UpdateW(int i, int j) {
//     if (j < 1) {
//         return WHITE;
//     }
//     int index = ((i) * (j - 1)) + (j - 1);

//     return tiles_.at(index).getColor();
// }

void HeightMap::UpdateNeighbors(int i, int j, int index) {
    UpdateNW(i, j, index);
    // UpdateN(i, j);
    // UpdateNE(i, j);
    // UpdateE(i, j);
    // UpdateSE(i, j);
    // UpdateS(i, j);
    // UpdateSW(i, j);
    // UpdateW(i, j);
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
