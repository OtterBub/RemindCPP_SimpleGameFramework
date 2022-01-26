#include "object.hpp"
#include <iostream>
#include <ncurses.h>

Object::Object(){
    mPos.x = 5;
    mPos.y = 0;
    mModel = '0';
    mErase = false;
}

Object::Object(int x, int y) : Object::Object() {
    mPos.x = x;
    mPos.y = y;
}

Object::~Object(){
    
}

int Object::Draw() {
    // std::cout << "Object.Draw()" << std::endl;
    mvprintw(mPos.y, mPos.x, "%c", mModel);
    return 0;
}

int Object::Update(int time) {
    // Test Object.Update()
    // mPos.y ++;
    
    return 0;
}

iPos2D Object::GetPos() {
    return mPos;
}

int Object::SetPos(int x, int y) {
    mPos.x = x;
    mPos.y = y;
    return 0;
}

char Object::GetModel() {
    return mModel;
}
int Object::SetModel(char c) {
    mModel = c;
    return 0;
}

int Object::SetErase(bool erase) {
    mErase = erase;
    return 0;
}

bool Object::GetErase() {
    return mErase;
}