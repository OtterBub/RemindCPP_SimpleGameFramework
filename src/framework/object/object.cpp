#include "object.hpp"
#include <iostream>
#include <ncurses.h>

Object::Object(){
    mPos.x = 0;
    mPos.y = 0;
    mModel = '0';
}
Object::~Object(){
    
}

int Object::Draw() {
    // std::cout << "Object.Draw()" << std::endl;
    mvprintw(mPos.y, mPos.x, "%c", mModel);
    return 0;
}

int Object::Update(int time) {
    
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