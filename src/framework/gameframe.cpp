#include "gameframe.hpp"
#include "object/object.hpp"
#include <iostream>

GameFrame::GameFrame(){
    mGameState = 0;
}
GameFrame::~GameFrame(){

}
        
int GameFrame::Run(){
    std::cout << "GameFrame.Run()" << std::endl;
    Object o;
    o.Draw();
    return 0;
}