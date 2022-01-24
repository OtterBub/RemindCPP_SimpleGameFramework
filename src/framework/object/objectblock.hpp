#ifndef __OBJECTBLOCK_HPP__
#define __OBJECTBLOCK_HPP__

#include <vector>
#include "object.hpp"

#define BLOCKMODEL_O 0
#define BLOCKMODEL_I 1
#define BLOCKMODEL_L 2

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
        int SetBlockModel(int modelNum);

        int SetSpeed(int speed);
        int SetStop(bool stop);

        int BlockRotate(int rot);

    private:
        bool isStop;
        int iTime;
        int miSpeed;
        int mBlockModel;
        int mBlockRotate;
};

#endif