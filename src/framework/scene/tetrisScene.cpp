#include "tetrisScene.hpp"

#include "testScene.hpp"
#include "../object/object.hpp"
#include <iostream>

// MacOS
#include <curses.h>

// ---- public ----

TestrisScene::TestrisScene() : Scene::Scene() {
    
}

TestrisScene::~TestrisScene() {
    Scene::~Scene();
}

int TestrisScene::Draw() { 
    static int callCount = 0; // Test Draw Call Count
    callCount++;
    
    mvprintw(0, 0, "%s", mstrDisplay.c_str());



    // Test Draw Call Count
    mvprintw(miHeight + 1, 0, "TestrisScene::Draw() Call count: %d", callCount);
    return 0;
}

int TestrisScene::KeyInput(int key) {
    switch(key)
        {
            case KEY_DOWN:
                
                break;
            case KEY_UP:
                
                break;
            case KEY_RIGHT:
                
                break;
            case KEY_LEFT:
                
                break;
            default:
                break;
        }
    return 0;
}

int TestrisScene::SetDisplaySize(int width, int height) {    
    return Scene::SetDisplaySize(width, height);
}

int TestrisScene::SetBlankChar(char c) {
    return Scene::SetBlankChar(c);
}

// ---- protected ----