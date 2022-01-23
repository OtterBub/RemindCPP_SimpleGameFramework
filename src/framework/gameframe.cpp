#include "gameframe.hpp"
#include "object/object.hpp"
#include "scene/scene.hpp"
#include "scene/testScene.hpp"
#include <iostream>

GameFrame::GameFrame(){
    mGameState = 0;
}
GameFrame::~GameFrame(){

}
        
int GameFrame::Run(){
    std::cout << "GameFrame.Run()" << std::endl;
    TestScene s;
    int result;
    while(1) {
        int inputKeyResult = mKeyManager.InputKey();
        s.KeyInput(inputKeyResult);
        s.Draw();
    }
    return 0;
}