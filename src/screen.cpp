#include <screen.h>

Screen::Screen(int _screenWidth, int _screenHeight)
{
    screenWidth = _screenWidth;
    screenHeight = _screenHeight;

    for(int i = 0; i < _screenWidth * _screenHeight; i++)
    {
        data.push_back(BLACK);
    }
    // data.reserve(_screenWidth * _screenHeight);
    
    std::cout << "\nScreen inited\n";

    for(int i = 0; i < _screenHeight; i++)
    {
        for(int j = 0; j < _screenWidth; j++)
        {
            data[i * _screenWidth + j] = {
                uint8_t(255 * i / _screenHeight), 
                uint8_t(255 * j / _screenWidth), 
                uint8_t(255 - 255 * (i+j)/(_screenWidth+_screenHeight)),//((i*i + j*j) / (_screenWidth*_screenWidth + _screenHeight*_screenHeight))),
                255};
        }
    }
    screen = GenImageColor(screenWidth, screenHeight, RED);
    screen_texture = LoadTextureFromImage(screen);
    UpdateTexture(screen_texture, data.data());
}
void Screen::clear(Color color)
{
    for(int i = 0; i < screenHeight; i++)
    {
        for(int j = 0; j < screenWidth; j++)
        {
            data[j + screenWidth * i] = color;
        }
    }
    // std::cout << "screen cleared\n";
}

void Screen::setPixel(int x, int y, Color color)
{
    if(y < 0 || y > screenHeight)
    {
        // std::cout << "bad y for writePixel: " << y << "\n";
        y = y < 0? 0 : (y > screenHeight? screenHeight : y);
    }
    if(x < 0 || x > screenWidth)
    {
        // std::cout << "bad x for writePixel: " << x << "\n";
        x = x < 0 ? 0 : (x > screenWidth? screenWidth : x);
    }
    data[y * screenWidth + x] = color;
}

Screen::~Screen()
{   
    UnloadImage(screen);
    UnloadTexture(screen_texture);
}

void Screen::draw()
{
    UpdateTexture(screen_texture, data.data());
    DrawTexture(screen_texture, 0, 0, WHITE);
}