#include "scene.hpp"
#include "../object/object.hpp"
#include <iostream>

// MacOS
#include <curses.h>

// ---- public ----

Scene::Scene() {
    SetDisplaySize(9, 10);
    SetBlankChar('.');
    InitDisplay();
}

Scene::~Scene() {

}

int Scene::Draw() { 
    mvprintw(0, 0, "%s", mstrDisplay.c_str());

    // Test Draw Chars
    mvprintw(mObject.GetPos().y, mObject.GetPos().x, "%c", mObject.GetModel());
    return 0;
}

int Scene::KeyInput(int key) {
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
                
                break;
        }
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
    mstrDisplay = "";
    for(int y = 0; y < miHeight; y++) {
        for(int x = 0; x < miWidth; x++) {
            mstrDisplay.push_back(mcBlankChar);
        }
        mstrDisplay.push_back('\n');
    }

    return 0;
}