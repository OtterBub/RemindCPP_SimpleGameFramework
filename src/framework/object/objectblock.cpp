#include "objectblock.hpp"
#include <iostream>

ObjectBlock::ObjectBlock() : Object() {
    miSpeed = 1000;
    iTime = 0;
    isStop = false;
}
ObjectBlock::~ObjectBlock(){
    Object::~Object();
}

int ObjectBlock::Draw() {
    return 0;
}

int ObjectBlock::Update(int time) {
    if(!isStop) {
        iTime += time;
        if(iTime > miSpeed) {
            mPos.y++;
            iTime = 0;
        }
    }
    mPos.y++;
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