#include "scene.h"

void Scene::Init() {
    terrain_.Init();
}

void Scene::Draw() {
    terrain_.Draw();
}

void Scene::Update() {
    terrain_.Update();
}