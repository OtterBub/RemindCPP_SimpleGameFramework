#include "object.hpp"
#include <iostream>

Object::Object(){
    mPosX = 0;
    mPosY = 0;
}
Object::~Object(){
    
}

int Object::Draw() {
    std::cout << "Object.Draw()" << std::endl;
    return 0;
}