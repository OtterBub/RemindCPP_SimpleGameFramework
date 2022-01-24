#include "tetrisScene.hpp"

#include "testScene.hpp"
#include "../object/object.hpp"
#include "../object/objectblock.hpp"
#include <iostream>

// MacOS
#include <curses.h>

// ---- public ----

TetrisScene::TetrisScene() : Scene::Scene() {
    mStrTest = "";

    ObjectBlock* o = new ObjectBlock();
    o->SetModel('A');
    o->SetBlockModel(BLOCKMODEL_L);
    o->SetPos(1, 1);
    o->SetSpeed(250);
    mObjManager.AddObj(o);

    o = new ObjectBlock();
    o->SetModel('B');
    o->SetPos(2, 2);
    mObjManager.AddObj(o);

    Object* b = new Object();
    b->SetModel('C');
    b->SetPos(2, 3);
    mObjManager.AddObj(b);

    o = (ObjectBlock*)mObjManager.AddObj(new ObjectBlock());
    o->SetModel('D');
    o->SetPos(5, 5);
    o->SetSpeed(500);
    o->SetStop(true);
    o->SetBlockModel(BLOCKMODEL_L);
    mControlBlock = o;
}

TetrisScene::~TetrisScene() {
    Scene::~Scene();
}

int TetrisScene::Draw() { 
    static int callCount = 0; // Test Draw Call Count
    callCount++;
    
    mvprintw(0, 0, "%s", mstrDisplay.c_str());



    mObjManager.Draw();

    // Test Draw Call Count
    mvprintw(miHeight + 1, 0, "TetrisScene::Draw() Call count: %d", callCount);
    mvprintw(miHeight + 2, 0, "KeyInput : %s                 ", mStrTest.c_str());
    return 0;
}

int TetrisScene::Update(int time) {
    mObjManager.Update(time);
    return 0;
}

int TetrisScene::KeyInput(int key) {
    iPos2D blockPos = {0, 0};
    ObjectBlock* objB;
    if(mControlBlock != nullptr)
        blockPos = mControlBlock->GetPos();
        objB = (ObjectBlock*) mControlBlock;

    switch(key) {
        case KEY_DOWN:
            mStrTest = "KEY_DOWN";
            break;
        case KEY_UP:
            mStrTest = "KEY_UP";
            objB->BlockRotate(1);
            break;
        case KEY_RIGHT:
            mStrTest = "KEY_RIGHT";
            if (mvecIsBlock[blockPos.x+1][blockPos.y] == false)
                mControlBlock->SetPos(blockPos.x+1, blockPos.y);
            break;
        case KEY_LEFT:
            mStrTest = "KEY_LEFT";
            if (mvecIsBlock[blockPos.x-1][blockPos.y] == false)
                mControlBlock->SetPos(blockPos.x-1, blockPos.y);
            break;
        default:
            break;
    }
    return 0;
}

int TetrisScene::SetDisplaySize(int width, int height) {
    Scene::SetDisplaySize(width, height);

    mvbIsBlock = std::vector<std::vector<bool>> (width, std::vector<bool>(height, false));
    mvecIsBlock.clear();
    
    std::vector<std::vector<bool>> v (height, std::vector<bool>(width, false));
    mvecIsBlock = v;

    for(int ix = 0; ix < width; ix++) {
        mvecIsBlock[ix][height] = true;
        mstrDisplay[ix + (height * (width + 1))] = 'O';
    }

    for(int iy = 0; iy < height; iy++) {
        mvecIsBlock[width][iy] = true;
        mvecIsBlock[0][iy] = true;
        mstrDisplay[width - 1 + (iy * (width + 1))] = 'O';
        mstrDisplay[0 + (iy * (width + 1))] = 'O';
    }
    
    return 0;
}

int TetrisScene::SetBlankChar(char c) {
    return Scene::SetBlankChar(c);
}

// ---- protected ----