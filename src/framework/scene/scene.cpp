#include "scene.hpp"
#include "../object/object.hpp"
#include <iostream>
// ---- public ----

Scene::Scene() {
    SetDisplaySize(4, 4);
    SetBlankChar('.');
}

Scene::~Scene() {

}

int Scene::Draw() {
    std::cout << "Scene.Draw()" << std::endl;
    return 0;
}

int Scene::SetDisplaySize(int width, int height) {
    miWidth = width;
    miHeight = height;
    InitDisplay();
    
    return 0;
}

int Scene::SetBlankChar(char c)  {
    mcBlankChar = c;

    return 0;
}

// ---- private ----

int Scene::InitDisplay() {
    mvDisplay.push_back(mcBlankChar);

    return 0;
}