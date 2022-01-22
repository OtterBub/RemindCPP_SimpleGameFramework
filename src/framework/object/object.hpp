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

    private:
        iPos2D mPos;
};

#endif //__OBJECT_HPP__