#ifndef SIMWORLD_SRC_UI_H
#define SIMWORLD_SRC_UI_H

#include <vector>

#include <raylib-cpp.hpp>

class Ui {
  public:
    virtual void Init();
    virtual void Draw();
    virtual void OnClick(const raylib::Mouse &mouse);
    virtual void OnHover(const raylib::Mouse &mouse);
};

#endif  // SIMWORLD_SRC_UI_H