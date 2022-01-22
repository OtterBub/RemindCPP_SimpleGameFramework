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
    s.Draw();
    int result;
    while(1) {
        int keyResult = mKeyManager.InputKey();
        mvprintw(0, 0, "mKeyManager.InputKey(): %c", keyResult);
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

        mvprintw(1, 0, "KeyResultStr %s", keyResultStr.c_str());
            

    }
    return 0;
}