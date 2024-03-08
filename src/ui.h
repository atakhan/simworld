#ifndef SIMWORLD_SRC_UI_H
#define SIMWORLD_SRC_UI_H

#include <vector>

#include <raylib-cpp.hpp>

class Ui {
  public:
    virtual void Init(Vector2 pos, Vector2 size, const std::string &text) = 0;
    virtual void Draw() = 0;
    virtual void Update(const raylib::Mouse &mouse) = 0;
};

#endif  // SIMWORLD_SRC_UI_H