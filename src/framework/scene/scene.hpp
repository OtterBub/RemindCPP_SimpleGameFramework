#ifndef __SCENE_HPP__
#define __SCENE_HPP__

#include <vector>
#include <string>
#include <curses.h>
#include "../object/object.hpp"

class Scene {
    public:
        Scene();
        ~Scene();

       virtual int Draw();
       virtual int Update(int time);
       virtual int KeyInput(int key);
       int SetDisplaySize(int width, int height);
       int SetBlankChar(char c);
       
    protected:
        int InitDisplay();

        int miWidth;
        int miHeight;
        std::string mstrDisplay;
        char mcBlankChar;
};

#endif //__SCENE_HPP__