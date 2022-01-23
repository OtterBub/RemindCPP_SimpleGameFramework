#include "objectmanager.hpp"

// ---- public ----
ObjectManager::ObjectManager() {
    
}
ObjectManager::~ObjectManager() {
    for(Object* obj : mvObject) {
        delete obj;
    }
    mvObject.clear();
}

int ObjectManager::Draw() {
    for(Object* obj : mvObject) {
        obj->Draw();
    }

    return 0;
}

int ObjectManager::Update(int time) {
    for(Object* obj : mvObject) {
        obj->Update(time);
    }
    return 0;
}

Object* ObjectManager::AddObj(Object* obj) {
    mvObject.push_back(obj);
    return obj;
}

std::vector<Object*>& ObjectManager::GetObjectVector() {
    return mvObject;
}