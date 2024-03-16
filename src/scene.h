#ifndef SIMWORLD_SRC_SCENE_H
#define SIMWORLD_SRC_SCENE_H

#include <iostream>

#include <raylib-cpp.hpp>

#include "tile.h"
#include "terrain.h"
#include "button.h"

class Scene {

  public:
    void Init();
    void Draw();
    void Update();

  private:
    Terrain terrain_;
    raylib::Mouse mouse_;
    Button erosion_btn_;
    Button regenerate_btn_;
    Button elevate_btn_;
};

#endif  // SIMWORLD_SRC_SCENE_H
