#include "tetrisScene.hpp"

#include "testScene.hpp"
#include "../object/object.hpp"
#include <iostream>

// MacOS
#include <curses.h>

// ---- public ----

TetrisScene::TetrisScene() : Scene::Scene() {
    mStrTest = "";
}

TetrisScene::~TetrisScene() {
    Scene::~Scene();
}

int TetrisScene::Draw() { 
    static int callCount = 0; // Test Draw Call Count
    callCount++;
    
    mvprintw(0, 0, "%s", mstrDisplay.c_str());



    // Test Draw Call Count
    mvprintw(miHeight + 1, 0, "TetrisScene::Draw() Call count: %d", callCount);
    mvprintw(miHeight + 2, 0, "KeyInput : %s                 ", mStrTest.c_str());
    return 0;
}

int TetrisScene::KeyInput(int key) {
    switch(key)
        {
            case KEY_DOWN:
                mStrTest = "KEY_DOWN";
                break;
            case KEY_UP:
                mStrTest = "KEY_UP";
                break;
            case KEY_RIGHT:
                mStrTest = "KEY_RIGHT";
                break;
            case KEY_LEFT:
                mStrTest = "KEY_LEFT";
                break;
            default:
                break;
        }
    return 0;
}

int TetrisScene::SetDisplaySize(int width, int height) {
    mvprintw(20, 0, "TestrisScene Call SetDisplaySize()");
    mvbIsBlock = std::vector<std::vector<bool>> (width, std::vector<bool>(height, false));
    return Scene::SetDisplaySize(width, height);
}

int TetrisScene::SetBlankChar(char c) {
    return Scene::SetBlankChar(c);
}

// ---- protected ----