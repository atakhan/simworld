#ifndef SIMWORLD_SRC_HEIGHTMAP_H
#define SIMWORLD_SRC_HEIGHTMAP_H

#include <vector>

#include <raylib-cpp.hpp>

class HeightMap {
  const int MIN_HEIGHT = 1;
  const int MAX_HEIGHT = 255;
  public:
    HeightMap(int area_w, int area_h);
    void Generate();
    void GenerateNoise();
    void SelectHighestNodes();
    int GetRandomIntBetween(int a, int b);
    std::vector<int> &GetData() {return data_; }
    int Width() {return width_;}
    int Height() {return height_;}
    void MakeErosion();

  private:
    int width_;
    int height_;

    std::vector<int> data_;

    void UpdateNW(int i, int j, int index);
    void UpdateNeighbors(int i, int j, int index);
};

#endif  // SIMWORLD_SRC_HEIGHTMAP_H