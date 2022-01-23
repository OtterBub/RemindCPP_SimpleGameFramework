#include "objectblock.hpp"
#include <iostream>
#include <curses.h>

std::vector<std::vector<std::vector<int>>> gBlockPattern {
    { {0, 0}, {0, 1}, {1, 1}, {1, 0} }, // O
    { {0, -1}, {0, 0}, {0, 1}, {0, 2} } // I
    
};

ObjectBlock::ObjectBlock() : Object() {
    miSpeed = 1000;
    iTime = 0;
    isStop = false;
}
ObjectBlock::~ObjectBlock(){
    Object::~Object();
}

int ObjectBlock::Draw() {
    // mvprintw(mPos.y, mPos.x, "%c", mModel);
    
    for (std::vector<int> i : gBlockPattern[1]) {
        mvprintw(mPos.y + i[0], mPos.x + i[1], "%c", mModel);
    }

    // Test ObjectBlock Draw()
    // mvprintw(2, 20, "ObjectBlock %c", mModel);
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

int ObjectBlock::SetSpeed(int speed) {
    miSpeed = speed;
    return 0;
}

int ObjectBlock::SetStop(bool stop) {
    isStop = stop;
    return 0;
}