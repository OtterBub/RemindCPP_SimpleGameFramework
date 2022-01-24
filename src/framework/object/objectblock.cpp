#include "objectblock.hpp"
#include <iostream>
#include <curses.h>

// gBlockPattern[BlockModel][Rotate][oneBlockPos][0(y), 1(x)]

const std::vector<std::vector<std::vector<std::vector<int>>>> gBlockPattern {
    { 
        { {0, 0}, {0, 1}, {1, 1}, {1, 0} }
    }, // O
    { 
        { {0, -1}, {0, 0}, {0, 1}, {0, 2} },
        { {-1, 0}, {0, 0}, {1, 0}, {2, 0} }
    }, // I
    {
        { {0, 0}, {0, -1}, {0, 1}, {1, 1} },
        { {0, 0}, {1, 0}, {-1, 0}, {-1, 1} },
        { {0, 0}, {0, -1}, {-1, -1}, {0, 1} },
        { {0, 0}, {-1, 0}, {1, 0}, {1, -1} }
    } // L
};

// Maximum One Of Block Num
#define BLOCKNUM 4

ObjectBlock::ObjectBlock() : Object() {
    miSpeed = 1000;
    iTime = 0;
    isStop = false;
    mBlockModel = BLOCKMODEL_L;
    mBlockRotate = 0;
    mBlockRealPos = std::vector<std::vector<int>> (BLOCKNUM, std::vector<int>(2));
}
ObjectBlock::~ObjectBlock(){
    Object::~Object();
}

int ObjectBlock::Draw() {
    // mvprintw(mPos.y, mPos.x, "%c", mModel);
    
    // for (std::vector<int> i : gBlockPattern[mBlockModel][mBlockRotate]) {
    //     mvprintw(mPos.y + i[1], mPos.x + i[0], "%c", mModel);
    // }

    for(std::vector<int> pos : mBlockRealPos) {
       mvprintw(pos[1], pos[0], "%c", mModel); 
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
    // mBlockRealPos Update
    int iIndexRealPos = 0;
    for (std::vector<int> i : gBlockPattern[mBlockModel][mBlockRotate]) {
        mBlockRealPos[iIndexRealPos][0] = mPos.x + i[0]; // x
        mBlockRealPos[iIndexRealPos][1] = mPos.y + i[1]; // y
        iIndexRealPos++;
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

int ObjectBlock::SetBlockModel(int modelNum) {
    mBlockModel = modelNum;
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

int ObjectBlock::BlockRotate(int rot) {
    mBlockRotate = (mBlockRotate + 1) % gBlockPattern[mBlockModel].size();
    return 0;
}