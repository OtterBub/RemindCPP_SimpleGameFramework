#ifndef __OBJECT_HPP__
#define __OBJECT_HPP__
#include "struct.h"

class Object {
    public:
        Object();
        ~Object();

        virtual int Draw();
        virtual int Update(int time);

        iPos2D GetPos();
        int SetPos(int x, int y);
        
        char GetModel();
        int SetModel(char c);

        int SetErase(bool erase);
        bool GetErase();

    protected:
        iPos2D mPos;
        wchar_t mModel;
        bool mErase;
};

#endif //__OBJECT_HPP__