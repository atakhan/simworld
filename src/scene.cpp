#include "scene.h"

void Scene::Init() {
    terrain_.Init();
    
    // кнопка для генерации шума
    regenerate_btn_.Init(
        (Vector2){1280 - 140, 20},
        (Vector2){120, 32},
        "Regenerate"
    );

    // кнопка для эрозии (НЕ РАБОТАЕТ!!)
    erosion_btn_.Init(
        (Vector2){1280 - 140, 90},
        (Vector2){120, 32},
        "Erosion"
    );

    // кнопка для поднятия уровня рельефа (самые низкие поднимаем на ступень выше)
    elevate_btn_.Init(
        (Vector2){1280 - 140, 160},
        (Vector2){120, 32},
        "Filter peaks"
    );
}

void Scene::Draw() {
    terrain_.Draw();
    regenerate_btn_.Draw();
    erosion_btn_.Draw();
    elevate_btn_.Draw();
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

    if (elevate_btn_.IsPressed(mouse)) {
        terrain_.filterPeaks();
    }
}