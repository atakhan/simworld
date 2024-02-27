#ifndef SIMWORLD_SRC_HEIGHTMAP_H
#define SIMWORLD_SRC_HEIGHTMAP_H

#include <vector>

#include <raylib-cpp.hpp>

class HeightMap {
  public:
    HeightMap(size_t area_w, size_t area_h);
    void Generate();
    void GenerateNoise();
    void SelectHeighestNodes();
    int GetRandomIntBetween(int a, int b);
    std::vector<int> &GetData() {return data_; }
    size_t Width() {return width_;}
    size_t Height() {return height_;}

  private:
    size_t width_;
    size_t height_;

    std::vector<int> data_;
};

#endif  // SIMWORLD_SRC_HEIGHTMAP_H