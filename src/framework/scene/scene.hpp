#ifndef __SCENE_HPP__
#define __SCENE_HPP__

#include <vector>
#include <string>

class Scene {
    public:
        Scene();
        ~Scene();

       int Draw();
       int SetDisplaySize(int width, int height);
       int SetBlankChar(char c);
       

    private:
        int miWidth;
        int miHeight;
        std::vector<char> mvDisplay;
        char mcBlankChar;

        int InitDisplay();
};

#endif //__SCENE_HPP__