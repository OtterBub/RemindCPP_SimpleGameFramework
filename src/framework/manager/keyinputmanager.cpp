#include "keyinputmanager.hpp"
#include <iostream>

KeyInputManager::KeyInputManager() {
    mWin = initscr();
    keypad(mWin, TRUE);
    noecho();
}
KeyInputManager::~KeyInputManager() {
    endwin();
}

int KeyInputManager::InputKey() {
    
    return wgetch(mWin);
}