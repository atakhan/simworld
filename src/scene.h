#include <iostream>

#include <raylib-cpp.hpp>

#include "tile.h"

class Scene {
    const size_t AREA_WIDTH = 70;
    const size_t AREA_HEIGHT = 40;
    const int CELL_WIDTH = 8;
    const int CELL_HEIGHT = 8;

  public:
    Scene(std::vector<Tile> *tiles);
    void Init();
    void Draw();
    void Update();
  
  private:
    std::vector<Tile> *tiles_;
};
