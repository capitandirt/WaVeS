#ifndef WAVE_H
#define WAVE_H


#include "mathFunctions.h"
#include <vector>
#include "screen.h"


struct WaveDot // z, weight, v
{
    double z;
    double weight;
    double v;
};

class WaveDriver
{
private:
    static constexpr double K = 1;
    std::vector<WaveDot> dots;
    int length, height;
    Screen& screen;
    double getAcc(int x, int y);
public:
    WaveDriver(Screen& _screen): screen(_screen){}
    void update();
    void setDotAmplitude(IntVec dot, int Amplitude);
    void draw();
    void clear();

    void createLine();
    void createPlate(int _length = 1280, int _height = 720);
};

#endif //WAVE_H