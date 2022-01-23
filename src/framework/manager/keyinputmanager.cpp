#include "keyinputmanager.hpp"
#include <iostream>

KeyInputManager::KeyInputManager() {
    mWin = initscr();
    keypad(mWin, TRUE);
    noecho();
    mLastKeyInput = ' ';
}
KeyInputManager::~KeyInputManager() {
    endwin();
}

int KeyInputManager::InputKey() {
    timeout(0);    
    mLastKeyInput = wgetch(mWin);
    return mLastKeyInput;
}