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
       int KeyInput(int key);
       int SetDisplaySize(int width, int height);
       int SetBlankChar(char c);
       
    protected:
        ObjectManager mObjManager;
        std::vector<std::vector<bool>> mvbIsBlock;
        std::string mStrTest;
};



#endif //__TETRISSCENE_HPP__