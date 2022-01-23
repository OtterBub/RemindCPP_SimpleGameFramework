#ifndef __OBJECTBLOCK_HPP__
#define __OBJECTBLOCK_HPP__

#include "object.hpp"

class ObjectBlock : public Object {
    public:
        ObjectBlock();
        ~ObjectBlock();

        int Draw();
        int Update(int time);

        iPos2D GetPos();
        int SetPos(int x, int y);
        
        char GetModel();
        int SetModel(char c);

        int SetSpeed(int speed);

    private:
        bool isStop;
        int iTime;
        int miSpeed;
};

#endif