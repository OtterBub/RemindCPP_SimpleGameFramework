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
    mLastKeyInput = wgetch(mWin);
    return mLastKeyInput;
}