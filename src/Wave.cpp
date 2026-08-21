#include <Wave.h>

void WaveDriver::draw()
{
    screen.clear();
    // for(int i = 0; i < dots.size(); i++)
    // {
    //     screen.setPixel(i, (int)-dots[i].z + screen.height/2, WHITE);
    // }
    for(int x = 0; x < length; x++)
    {
        for(int y = 0; y < height; y++)
        {
            uint8_t intensivity = 128 + (int)dots[y*length + x].z / (1<<4);
            if(intensivity > 255) intensivity = 255;
            if(intensivity < 0) intensivity = 0;
            Color color = {intensivity, intensivity, intensivity, intensivity};
            screen.setPixel(x, y, color);
        }
    }
    screen.draw();
}

void WaveDriver::createLine()
{
    for(int x = 0; x < 500; x++)
    {
        dots.push_back(WaveDot{0, 1, 0});
    }
}

void WaveDriver::createPlate(int _length, int _height)
{
    length = _length;
    height = _height;
    for(int x = 0; x < length; x++)
    {
        for(int y = 0; y < height; y++)
        {
            dots.push_back(WaveDot{0, 1, 0});
        }
    }
}

void WaveDriver::setDotAmplitude(IntVec dot, int Amplitude)
{
    dots[dot.y*length + dot.x].z = Amplitude;
}

double WaveDriver::getAcc(int x, int y)
{
    double middle, errL = 0, errR = 0, errB = 0, errU = 0;
    int count = 0;
    if(y != 0)
    {
        errU = dots[(y-1)*length + x].z -  dots[y*length + x].z;
        count++;
    }
    if(x != 0)
    {
        errL = dots[y*length + x-1].z -  dots[y*length + x].z;
        count++;
    }
    if(x != length - 1)
    {
        errR = dots[y*length + x+1].z -  dots[y*length + x].z;
        count++;
    }
    if(y != height - 1)
    {
        errB = dots[(y+1)*length + x].z -  dots[y*length + x].z;
        count++;
    }
    middle = (errL + errR + errU + errB) / count;

    
    return middle / dots[y*length + x].weight * K;
}

void WaveDriver::update()
{
    // std::cout << dots[0].z << "\n";

    std::vector<double> buffer(height * length);
    for(int x = 0; x < length; x++)
    {
        for(int y = 0; y < height; y++)
        {
            dots[y*length + x].v += getAcc(x, y);
            buffer[y*length + x] += dots[y*length + x].v;
        }
    }
    for(int x = 0; x < length; x++)
    {
        for(int y = 0; y < height; y++)
        {
            dots[y*length + x].z += buffer[y*length + x];
        }
    }
    // std::cout << "imheeere";
}

void WaveDriver::clear()
{
    for(int i = 0; i < dots.size(); i++)
    {
        dots[i].z = 0;
        dots[i].v = 0;
    }
}