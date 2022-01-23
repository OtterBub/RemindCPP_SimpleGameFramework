#include "testScene.hpp"
#include "../object/object.hpp"
#include <iostream>

// MacOS
#include <curses.h>

// ---- public ----

TestScene::TestScene() : Scene::Scene() {
    
}

TestScene::~TestScene() {
    Scene::~Scene();
}

int TestScene::Draw() { 
    static int callCount = 0; // Test Draw Call Count
    callCount++;
    
    mvprintw(0, 0, "%s", mstrDisplay.c_str());

    // Test Draw Chars
    mvprintw(mObject.GetPos().y, mObject.GetPos().x, "%c", mObject.GetModel());

    // Test Draw Call Count
    mvprintw(miHeight + 1, 0, "TestScene::Draw() Call count: %d", callCount);
    return 0;
}

int TestScene::KeyInput(int key) {
    switch(key)
        {
            case KEY_DOWN:
                mObject.SetPos(mObject.GetPos().x, mObject.GetPos().y+1);
                break;
            case KEY_UP:
                mObject.SetPos(mObject.GetPos().x, mObject.GetPos().y-1);
                break;
            case KEY_RIGHT:
                mObject.SetPos(mObject.GetPos().x+1, mObject.GetPos().y);
                break;
            case KEY_LEFT:
                mObject.SetPos(mObject.GetPos().x-1, mObject.GetPos().y);
                break;
            default:
                break;
        }
    return 0;
}

int TestScene::SetDisplaySize(int width, int height) {    
    return Scene::SetDisplaySize(width, height);
}

int TestScene::SetBlankChar(char c) {
    return Scene::SetBlankChar(c);
}

// ---- protected ----

int TestScene::InitDisplay() {
    return Scene::InitDisplay();
}