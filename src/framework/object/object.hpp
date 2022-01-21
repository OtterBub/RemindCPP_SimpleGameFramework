#ifndef __OBJECT_H__
#define __OBJECT_H__

class Object {
    public:
        Object();
        ~Object();

        int Draw();

    private:
        int mPosX;
        int mPosY;
};

#endif