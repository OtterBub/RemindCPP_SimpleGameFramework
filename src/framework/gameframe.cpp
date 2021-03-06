#include "gameframe.hpp"
#include "object/object.hpp"
#include "scene/scene.hpp"
#include "scene/testScene.hpp"
#include "scene/tetrisScene.hpp"
#include <iostream>
#include <chrono>
#include <thread>

GameFrame::GameFrame(){
    mGameState = 0;
    SetFPS(30);
}
GameFrame::~GameFrame(){

}
        
int GameFrame::Run(){
    std::cout << "GameFrame.Run()" << std::endl;

    TetrisScene s;
    s.SetBlankChar(' ');
    s.SetDisplaySize(15, 20);
    
    // Current Time
    std::chrono::system_clock::time_point curTime = std::chrono::system_clock::now();

    // Delta Time
    std::chrono::duration<double> deltaTime;
    int ideltaTime = 0;
    while(1) {
        // Calculate deltaTime
        deltaTime = std::chrono::system_clock::now() - curTime;

        // Convert deltaTime to int
        ideltaTime = (int)(deltaTime.count() * 1000);

        // return KeyInput
        int inputKeyResult = mKeyManager.InputKey();
        s.KeyInput(inputKeyResult);
        
        s.Update(ideltaTime);
        s.Draw();
        
        // For FPS
        curTime = std::chrono::system_clock::now();
        std::this_thread::sleep_for(std::chrono::milliseconds(mWaitMilisec));
        
        // Test Print
        mvprintw(0, 20, "deltatime: %d", ideltaTime);

    }
    return 0;
}

int GameFrame::SetFPS(int fps) {
    miFPS = fps;
    // fps -> Frame Per Second
    // 60fps -> 60 Frame Per Second
    // 1000 milisec = 1 sec
    // 1000 / 60 = 16.6666 ...
    mWaitMilisec = (int)(1000 / miFPS);
    return 0;
}