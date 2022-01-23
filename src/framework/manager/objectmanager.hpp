#ifndef __OBJECTMANAGER_HPP__
#define __OBJECTMANAGER_HPP__

#include "../object/object.hpp"
#include <vector>

class ObjectManager {
    public:
        ObjectManager();
        ~ObjectManager();

        int Draw();
        int Update(int time);
        Object* AddObj(Object* obj);

        std::vector<Object*>& GetObjectVector();

    private:
        std::vector<Object*> mvObject;
};


#endif //__OBJECTMANAGER_HPP__