#ifndef SIMWORLD_SRC_BUTTON_H
#define SIMWORLD_SRC_BUTTON_H

#include <raylib-cpp.hpp>

#include "ui.h"

class Button : public Ui {
  public:
    void Init(Vector2 pos, Vector2 size, const std::string &text) override;
    void Draw() override;
    void Update(const raylib::Mouse &mouse) override;

    bool IsPressed(const raylib::Mouse &mouse);

  private:
    raylib::Rectangle rec;
    raylib::Text text_;
};

#endif  // SIMWORLD_SRC_BUTTON_H