#include "button.h"

void Button::Init(Vector2 pos, Vector2 size, const std::string &text) {
    rec.SetPosition(pos);
    rec.SetSize(size);
    text_.SetText(text);
}

void Button::Draw() {
    rec.Draw(RED);
    text_.Draw(rec.GetPosition());
}

void Button::Update(const raylib::Mouse &mouse) {
}

bool Button::IsPressed(const raylib::Mouse &mouse) {
    if (mouse.IsButtonPressed(MOUSE_BUTTON_LEFT)) {
        if (CheckCollisionPointRec(mouse.GetPosition(), rec)) {
            return true;       
        }
    }

    return false;
}

