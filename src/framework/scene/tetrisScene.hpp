#ifndef __TETRISSCENE_HPP__
#define __TETRISSCENE_HPP__

#include "scene.hpp"
#include "../manager/objectmanager.hpp"

class TestrisScene : public Scene {
    public:
        TestrisScene();
        ~TestrisScene();

       int Draw();
       int KeyInput(int key);
       int SetDisplaySize(int width, int height);
       int SetBlankChar(char c);
       
    protected:
        ObjectManager mObjManager;
};



#endif //__TETRISSCENE_HPP__