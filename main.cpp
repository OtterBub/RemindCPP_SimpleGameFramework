#include <iostream>
#include <vector>
#include <string>
#include "header/define.h"

int main (int argc, char *argv[])
{
    std::cout << "Hello World!";

    std::vector<std::string> testVector;
    testVector.push_back("Hello");
    testVector.push_back("World");
    testVector.push_back("C++ Test");

    for(const std::string& word : testVector ) {
        std::cout << word << " ";
    }
    std::cout << std::endl;

    int iGameState = GAMESTATE_RUN;
    while(iGameState == GAMESTATE_RUN) {

        
    }

    system("clear");
    
    return 0;
}