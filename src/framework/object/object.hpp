#ifndef __OBJECT_HPP__
#define __OBJECT_HPP__
#include "struct.h"

class Object {
    public:
        Object();
        ~Object();

        int Draw();
        iPos2D GetPos();
        int SetPos(int x, int y);
        
        char GetModel();
        int SetModel(char c);

    private:
        iPos2D mPos;
        char mModel;
};

#endif //__OBJECT_HPP__