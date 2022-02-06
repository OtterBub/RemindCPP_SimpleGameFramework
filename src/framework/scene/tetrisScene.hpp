#ifndef __TETRISSCENE_HPP__
#define __TETRISSCENE_HPP__

#include "scene.hpp"
#include "../manager/objectmanager.hpp"
#include <vector>
#include <string>

class TetrisScene : public Scene {
    public:
        TetrisScene();
        ~TetrisScene();

       int Draw();
       int Update(int time);
       int KeyInput(int key);
       int SetDisplaySize(int width, int height);
       int SetBlankChar(char c);
       
    protected:
        ObjectManager mObjManager;
        std::string mStrTest;
        Object* mControlBlock;
        std::vector<std::vector<bool>> mvecIsBlock;
        int mScore;

    private:
        // int clearStartY - Line Clear starting point Y Position
        int LineClear(int clearStartY);
};



#endif //__TETRISSCENE_HPP__