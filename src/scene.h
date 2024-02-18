#ifndef SIMWORLD_SRC_SCENE_H
#define SIMWORLD_SRC_SCENE_H

#include <iostream>

#include <raylib-cpp.hpp>

#include "tile.h"
// #include "heightmap.h"
#include "terrain.h"

class Scene {

  public:
    void Init();
    void Draw();
    void Update();

  private:
    Terrain terrain_;
};

#endif  // SIMWORLD_SRC_SCENE_H
