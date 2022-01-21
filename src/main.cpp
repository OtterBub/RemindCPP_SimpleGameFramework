#include <iostream>
#include <vector>
#include <string>
#include "framework/gameframe.hpp"

// by Park SungKyoung
// 2022/01/21 

int main (int argc, char *argv[])
{
    std::cout << "Hello Game FrameWork!" << std::endl;

    GameFrame frame = GameFrame();

    frame.Run();

    // system("clear");
    
    return 0;
}