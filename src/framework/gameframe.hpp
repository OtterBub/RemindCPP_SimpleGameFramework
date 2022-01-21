#ifndef __GAMEFRAME_H__
#define __GAMEFRAME_H__

#define GAMESTATE_EXIT 0
#define GAMESTATE_RUN 1

class GameFrame {
    public:
        GameFrame();
        ~GameFrame();
        
        int Run();


    private:
        int mGameState;
};

#endif