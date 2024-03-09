#ifndef SIMWORLD_SRC_HEIGHTMAP_H
#define SIMWORLD_SRC_HEIGHTMAP_H

#include <vector>

#include <raylib-cpp.hpp>

class HeightMap {
  const int MIN_HEIGHT = 1;
  const int MAX_HEIGHT = 255;
  const int ALLOW_DIFF = 10;

  public:
    HeightMap(int area_w, int area_h);
    void Generate();
    void GenerateNoise();
    void SelectHighestNodes();
    int GetRandomIntBetween(int a, int b);
    void MakeErosion();
    void Clear() { data_.clear(); }
    
    std::vector<int> &GetData() {return data_; }
    int Width() {return width_;}
    int Height() {return height_;}

  private:
    int width_;
    int height_;

    std::vector<int> data_;

    void UpdateNW(int index);
    void UpdateN(int index);
    void UpdateNE(int index);
    void UpdateE(int index);
    void UpdateSE(int index);
    void UpdateS(int index);
    void UpdateSW(int index);
    void UpdateNeighbors(int index);
};

#endif  // SIMWORLD_SRC_HEIGHTMAP_H