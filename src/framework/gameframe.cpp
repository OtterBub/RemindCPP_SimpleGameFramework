#include "gameframe.hpp"
#include "object/object.hpp"
#include "scene/scene.hpp"
#include <iostream>

GameFrame::GameFrame(){
    mGameState = 0;
}
GameFrame::~GameFrame(){

}
        
int GameFrame::Run(){
    std::cout << "GameFrame.Run()" << std::endl;
    Scene s;
    int result;
    while(1) {
        int keyResult = mKeyManager.InputKey();
        std::string keyResultStr = "";
        switch(keyResult)
        {
            case KEY_DOWN:
                keyResultStr = "KEY_DOWN        ";
                break;
            case KEY_UP:
                keyResultStr = "KEY_UP         ";
                break;
            default:
                keyResultStr = "Default        ";
                break;
        }
        // mvprintw(0, 0, "keyResultStr: %s", keyResultStr.c_str());
        s.KeyInput(keyResult);
        s.Draw();
        
    }
    return 0;
}