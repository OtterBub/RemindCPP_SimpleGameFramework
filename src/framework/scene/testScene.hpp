#ifndef __TESTSCENE_HPP__
#define __TESTSCENE_HPP__

#include "scene.hpp"
#include "../manager/objectmanager.hpp"

class TestScene : public Scene {
    public:
        TestScene();
        ~TestScene();
       int Draw();
       int KeyInput(int key);
       int SetDisplaySize(int width, int height);
       int SetBlankChar(char c);
       
    protected:
        int InitDisplay();

        ObjectManager mObjMgr;
        Object mObject; // Test Object
};

#endif // __TESTSCENE_HPP__