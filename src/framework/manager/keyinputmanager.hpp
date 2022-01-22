#ifndef __KEYINPUTMANAGER_HPP__
#define __KEYINPUTMANAGER_HPP__

#include <curses.h>

// <curses.h> need build option
// -lcurses
// # reference by https://stackoverflow.com/questions/13234943/not-able-to-compile-with-curses-on-gcc-os-x
// <curses.h> reference
// # link1: https://developer.apple.com/library/archive/documentation/System/Conceptual/ManPages_iPhoneOS/man3/getch.3x.html
// # link2: http://comedudb6.knue.ac.kr/tykim/Myhome/Cnote/chap4-CursesLecture.pdf

class KeyInputManager {
    public:
        KeyInputManager();
        ~KeyInputManager();

        int InputKey();
    private:
        WINDOW* mWin;
        int mLastKeyInput;
};

#endif