#include "objectmanager.hpp"

// ---- public ----
ObjectManager::ObjectManager() {
    
}
ObjectManager::~ObjectManager() {
    
}

int ObjectManager::Draw() {
    for(Object& obj : mvObject) {
        obj.Draw();
    }

    return 0;
}

int ObjectManager::Update(int time) {
    for(Object& obj : mvObject) {
        obj.Update(time);
    }
    return 0;
}

int ObjectManager::AddObj(Object& obj) {
    return 0;
}

std::vector<Object>& ObjectManager::GetObjectVector() {
    return mvObject;
}