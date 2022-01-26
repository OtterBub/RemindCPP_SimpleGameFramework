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
    ObjectBlock* o;
    o = (ObjectBlock*)mObjManager.AddObj(new ObjectBlock());
    o->SetModel('D');
    o->SetPos(5, 0);
    o->SetSpeed(500);
    o->SetStop(false);
    o->SetBlockModel(rand() % (BLOCKMODEL_NUM+1));
    mControlBlock = o;
    mScore = 0;
}

TetrisScene::~TetrisScene() {
    Scene::~Scene();
}

int TetrisScene::Draw() { 
    static int callCount = 0; // Test Draw Call Count
    callCount++;
    
    // Draw Display
    mvprintw(0, 0, "%s", mstrDisplay.c_str());

    // Draw Object
    mObjManager.Draw();
    
    // Draw UI
    mvprintw(2, 20, "Score: %d", mScore);

    // Test Draw Call Count
    mvprintw(miHeight + 1, 0, "TetrisScene::Draw() Call count: %d", callCount);
    mvprintw(miHeight + 2, 0, "KeyInput : %s                 ", mStrTest.c_str());
    return 0;
}

int TetrisScene::Update(int time) {

    // Update Object
    mObjManager.Update(time);

    // Update ControlBlock
    if(mControlBlock != nullptr) {
        ObjectBlock* objB = (ObjectBlock*) mControlBlock;

        // if ControlBlock Arrived Down Time
        if(objB->GetIsDownMove()){
            bool downIsBlock = false;
            std::vector<iPos2D> objBPosVec = objB->GetRealPos();
            
            // Collision Check Between Control Block And Fixed Block
            for(iPos2D pos : objBPosVec) {
                if(mvecIsBlock[pos.x][pos.y+1]) {
                   downIsBlock = true; 
                };
            }
            if(downIsBlock) {
                // Set Display Fixed Block
                for(iPos2D pos : objBPosVec) {
                    mvecIsBlock[pos.x][pos.y] = true;
                    mstrDisplay[pos.x + (pos.y * (miWidth + 1))] = objB->GetModel();
                }

                // Line Clear (Working)
                std::vector<int> vecClearStartY; // Clear Height
                bool isThislineClear = true;
                int ClearCount = 0;
                for(int iy = 0; iy < miHeight; iy++) {
                    isThislineClear = true;
                    for(int ix = 1; ix < miWidth - 1; ix++) {
                        if(mvecIsBlock[ix][iy] == false) {
                            isThislineClear = false;
                        }
                    }
                    if(isThislineClear){
                        vecClearStartY.push_back(iy);
                    }
                }
                // Down Block
                for(int startY : vecClearStartY) {
                    for(int delY = startY; delY > 0; delY--) {
                        for(int delX = 1; delX < miWidth - 1; delX++) {
                            mvecIsBlock[delX][delY] = mvecIsBlock[delX][delY-1];
                            mstrDisplay[delX + (delY * (miWidth + 1))] = mstrDisplay[delX + ((delY - 1) * (miWidth + 1))];
                        }
                    }
                    mScore++;
                }
                
                // Erase Current Block Object from ObjectManager
                objB->SetErase(true);

                // Add New Block Object
                ObjectBlock* o;
                o = (ObjectBlock*)mObjManager.AddObj(new ObjectBlock(5, 0));
                o->SetModel('D');
                o->SetSpeed(500);
                o->SetStop(false);
                o->SetBlockModel(rand() % (BLOCKMODEL_NUM+1));

                // Set Control Block
                mControlBlock = o;
            } else {
                objB->DownMove();
            }
        }
            
    }
    return 0;
}

int TetrisScene::KeyInput(int key) {
    iPos2D blockPos = {0, 0};
    ObjectBlock* objB;
    if(mControlBlock != nullptr){ 
            objB = (ObjectBlock*) mControlBlock;
            blockPos = objB->GetPos();
            std::vector<iPos2D> objpos = objB->GetRealPos();
            bool move = true;

            switch(key) {
                case KEY_DOWN:
                    mStrTest = "KEY_DOWN";
                    // Block Down Control
                    objB->SetIsDownMove(true);
                    break;
                case KEY_UP:
                    mStrTest = "KEY_UP";
                    // Block Rotation
                    objB->BlockRotate(1);
                    break;
                case KEY_RIGHT:
                    mStrTest = "KEY_RIGHT";
                    // RIGHT Collision Check
                    for(iPos2D pos : objpos) {
                        if(mvecIsBlock[pos.x+1][pos.y] == true)
                            move = false;
                    }
                    // Move Controlblock to the RIGHT
                    if (move)
                        mControlBlock->SetPos(blockPos.x+1, blockPos.y);
                    break;

                case KEY_LEFT:
                    mStrTest = "KEY_LEFT";
                    // LEFT Collision Check
                    for(iPos2D pos : objpos) {
                        if(mvecIsBlock[pos.x-1][pos.y] == true)
                            move = false;
                    }
                    // Move Controlblock to the LEFT
                    if (move)
                        mControlBlock->SetPos(blockPos.x-1, blockPos.y);
                    break;
                case 'a':
                    for(int delY = miHeight-1; delY > 0; delY--) {
                        for(int delX = 1; delX < miWidth - 1; delX++) {
                            mvecIsBlock[delX][delY] = mvecIsBlock[delX][delY-1];
                            mstrDisplay[delX + (delY * (miWidth + 1))] = mstrDisplay[delX + ((delY - 1) * (miWidth + 1))];
                        }
                    }
                    break;
                default:
                    mStrTest = key;
                    break;
            }
        }
    return 0;
}

int TetrisScene::SetDisplaySize(int width, int height) {
    Scene::SetDisplaySize(width, height);

    mvecIsBlock.clear();
    
    std::vector<std::vector<bool>> v (height, std::vector<bool>(width, false));
    mvecIsBlock = v;

    // Set Width Wall
    for(int ix = 0; ix < width; ix++) {
        mvecIsBlock[ix][height] = true;
        mstrDisplay[ix + (height * (width + 1))] = '-';
    }

    // Set Height Wall
    for(int iy = 0; iy < height; iy++) {
        mvecIsBlock[width - 1][iy] = true;
        mvecIsBlock[0][iy] = true;
        mstrDisplay[width - 1 + (iy * (width + 1))] = '|';
        mstrDisplay[0 + (iy * (width + 1))] = '|';
    }
    
    return 0;
}

int TetrisScene::SetBlankChar(char c) {
    return Scene::SetBlankChar(c);
}

// ---- protected ----