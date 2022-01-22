#include "object.hpp"
#include <iostream>

Object::Object(){
    mPos.x = 0;
    mPos.y = 0;
}
Object::~Object(){
    
}

int Object::Draw() {
    std::cout << "Object.Draw()" << std::endl;
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