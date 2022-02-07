#include "scene.hpp"
#include "../object/object.hpp"
#include <iostream>

// MacOS
#include <curses.h>

// ---- public ----

Scene::Scene() {
    SetDisplaySize(9, 10);
    SetBlankChar('.');
    SetBlankChar(L'.');
    InitDisplay();
}

Scene::~Scene() {

}

int Scene::Draw() { 
    
    return 0;
}

int Scene::Update(int time) {

    return 0;
}

int Scene::KeyInput(int key) {
  
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

int Scene::SetBlankChar(wchar_t c) {
    mcBlockwChar = c;
    return 0;
}

// ---- private ----

int Scene::InitDisplay() {
    mstrDisplay = "";
    mwstrDisplay = L"";
    for(int y = 0; y < miHeight; y++) {
        for(int x = 0; x < miWidth; x++) {
            mstrDisplay.push_back(mcBlankChar);
            mwstrDisplay.push_back(mcBlockwChar);
        }
        mstrDisplay.push_back('\n');
        mwstrDisplay.push_back(L'\n');
    }
    mstrDisplay.push_back(' ');
    mwstrDisplay.push_back(L' ');
    
    return 0;
}