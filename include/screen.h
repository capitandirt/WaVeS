#ifndef SCREEN_H
#define SCREEN_H


#include <raylib.h>
#include <iostream>
#include <stdint.h>
#include <vector>

class Screen
{
    private:
        int screenWidth; // ширина экрана
        int screenHeight; // высота экрана
        Image screen; // данные о пикселях экрана
        Texture2D screen_texture; // дублирующее поле типа Texture
    public:

        const int& width = screenWidth; // константная ссылка на ширину, работает как Геттер
        const int& height = screenHeight; // константная ссылка на высоту, работает как Геттер
        
        Screen(int _screenWidth, int _screenHeight); // конструктор по ширине и высоте
        void clear(Color color = BLACK); // очистить экран и заполнить его цветом аргумента (по умолчанию - черным)
        void setPixel(int x, int y, Color color); // рисует в определённом пикселе определённый цвет
        void draw(); //отрисовывает экран в окне
        ~Screen(); // деструктор, удаляющий текстуру
        std::vector<Color> data; //сырые данные о пикселях на экране
};

#endif // SCREEN_H