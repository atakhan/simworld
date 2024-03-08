#include "scene.h"

void Scene::Init() {
    terrain_.Init();
    regenerate_btn_.Init(
        (Vector2){1280 - 140, 20},
        (Vector2){120, 50},
        "Regenerate"
    );

    erosion_btn_.Init(
        (Vector2){1280 - 140, 90},
        (Vector2){120, 50},
        "Erosion"
    );
}

void Scene::Draw() {
    terrain_.Draw();
    regenerate_btn_.Draw();
    erosion_btn_.Draw();
}

void Scene::Update() {
    raylib::Mouse mouse;
    terrain_.Update();
    if (regenerate_btn_.IsPressed(mouse)) {
        terrain_.Regenerate();
    }

    if (erosion_btn_.IsPressed(mouse)) {
        terrain_.MakeErosion();
    }
}