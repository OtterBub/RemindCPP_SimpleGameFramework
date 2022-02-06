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
    }, // L
    {
        { {0, 0}, {0, -1}, {0, 1}, {-1, 1} },
        { {0, 0}, {1, 0}, {-1, 0}, {-1, -1} },
        { {0, 0}, {0, -1}, {1, -1}, {0, 1} },
        { {0, 0}, {-1, 0}, {1, 0}, {1, 1} }
    }, // J
    {
        { {0, 0}, {0, -1}, {-1, 0}, {1, 0} },
        { {0, 0}, {0, -1}, {0, 1}, {1, 0} },
        { {0, 0}, {-1, 0}, {0, 1}, {1, 0} },
        { {0, 0}, {-1, 0}, {0, 1}, {0, -1} }
    }, // T
    {
        { {0, 0}, {0, 1}, {1, 0}, {1, -1} },
        { {0, 0}, {-1, 0}, {0, 1}, {1, 1} }
    }, // N
    {
        { {0, 0}, {0, 1}, {-1, 0}, {-1, -1} },
        { {0, 0}, {-1, 0}, {0, -1}, {1, -1} }        
    }, // S
    
};

// Maximum One Of Block Num
#define BLOCKNUM 4

// Public

ObjectBlock::ObjectBlock() : Object() {
    miSpeed = 1000;
    iTime = 0;
    isStop = false;
    mBlockModel = BLOCKMODEL_L;
    mBlockRotate = 0;
    mBlockRealPos = std::vector<iPos2D> (BLOCKNUM, {0, 0});
    isDownMove = false;
}

ObjectBlock::ObjectBlock(int x, int y) : Object(x, y) {
    miSpeed = 1000;
    iTime = 0;
    isStop = false;
    mBlockModel = BLOCKMODEL_L;
    mBlockRotate = 0;
    mBlockRealPos = std::vector<iPos2D> (BLOCKNUM, {0, 0});
    isDownMove = false;
}

ObjectBlock::~ObjectBlock(){
    Object::~Object();
}

int ObjectBlock::Draw() {
    // mvprintw(mPos.y, mPos.x, "%c", mModel);
    
    // for (std::vector<int> i : gBlockPattern[mBlockModel][mBlockRotate]) {
    //     mvprintw(mPos.y + i[1], mPos.x + i[0], "%c", mModel);
    // }

    for(iPos2D pos : mBlockRealPos) {
       mvprintw(pos.y, pos.x, "%c", mModel); 
    }

    // Test ObjectBlock Draw()
    // mvprintw(2, 20, "ObjectBlock %c", mModel);
    return 0;
}

int ObjectBlock::Update(int time) {
    if(!isStop) {
        iTime += time;
        if(iTime > miSpeed) {
            iTime = 0;
            isDownMove = true;
        }    
    }
    // mBlockRealPos Update
    ObjectBlock::UpdateRealPos();
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
    mBlockRotate = 0;
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

int ObjectBlock::DownMove() {
    mPos.y++;
    isDownMove = false;
    return 0;
}

bool ObjectBlock::SetIsDownMove(bool setDownMove) {
    isDownMove = setDownMove;
    return isDownMove;
}

bool ObjectBlock::GetIsDownMove() {
    return isDownMove;
}

int ObjectBlock::BlockRotate(int rot) {
    mBlockRotate = (mBlockRotate + rot) % gBlockPattern[mBlockModel].size();
    ObjectBlock::UpdateRealPos();
    return 0;
}

std::vector<iPos2D> ObjectBlock::GetRealPos() {
    return mBlockRealPos;
}

// Private

int ObjectBlock::UpdateRealPos() {
    int iIndexRealPos = 0;
    for (std::vector<int> i : gBlockPattern[mBlockModel][mBlockRotate]) {
        mBlockRealPos[iIndexRealPos].x = mPos.x + i[0]; // x
        mBlockRealPos[iIndexRealPos].y = mPos.y + i[1]; // y
        iIndexRealPos++;
    }
    return 0;
}