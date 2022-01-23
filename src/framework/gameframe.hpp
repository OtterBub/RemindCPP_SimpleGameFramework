#ifndef __GAMEFRAME_HPP__
#define __GAMEFRAME_HPP__

#include "manager/keyinputmanager.hpp"

#define GAMESTATE_EXIT 0
#define GAMESTATE_RUN 1

class GameFrame {
    public:
        GameFrame();
        ~GameFrame();
        
        int Run();
        int SetFPS(int fps);


    private:
        int mGameState;
        KeyInputManager mKeyManager;
        int miFPS;
        int mWaitMilisec;
};

#endif //__GAMEFRAME_HPP__