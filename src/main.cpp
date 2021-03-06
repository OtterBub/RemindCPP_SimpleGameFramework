#include <iostream>
#include <vector>
#include <string>
#include "framework/gameframe.hpp"
#include "framework/scene/scene.hpp"

// Created by Park SungKyoung
// 2022/01/21 ~ 2022/01/24
// 
// \033[5;6H -> Terminal Cursor Position Control
// by https://rosettacode.org/wiki/Terminal_control/Cursor_positioning#C.2FC.2B.2B

int main (int argc, char *argv[])
{
    std::cout << "Hello Game FrameWork For Tetris!" << std::endl;

    GameFrame frame = GameFrame();
    frame.Run();
    
    return 0;
}