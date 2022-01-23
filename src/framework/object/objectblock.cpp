#include "objectblock.hpp"
#include <iostream>

ObjectBlock::ObjectBlock() : Object() {
    mPos.x = 0;
    mPos.y = 0;
    mModel = '0';
}
ObjectBlock::~ObjectBlock(){
    Object::~Object();
}

int ObjectBlock::Draw() {
    // std::cout << "ObjectBlock.Draw()" << std::endl;
    return 0;
}

iPos2D ObjectBlock::GetPos() {
    return mPos;
}

int ObjectBlock::SetPos(int x, int y) {
    mPos.x = x;
    mPos.y = y;
    return 0;
}

char ObjectBlock::GetModel() {
    return mModel;
}
int ObjectBlock::SetModel(char c) {
    mModel = c;
    return 0;
}