#ifndef SCREEN_H
#define SCREEN_H


#include <raylib.h>
#include <iostream>
#include <stdint.h>
#include <vector>

class Screen
{
    private:
        int screenWidth;
        int screenHeight;
        Image screen;
        Texture2D screen_texture;
    public:

        const int& width = screenWidth;
        const int& height = screenHeight;
        
        Screen(int _screenWidth, int _screenHeight);
        void clear(Color color = BLACK);
        ~Screen();
        std::vector<Color> data;
        void setPixel(int x, int y, Color color);
        void draw();
};

#endif // SCREEN_H