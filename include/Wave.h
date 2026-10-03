#ifndef WAVE_H
#define WAVE_H


#include "mathFunctions.h"
#include <vector>
#include "screen.h"


struct WaveDot // z, weight, v
{
    /*структура, описывающая точку колебания
        z       - значение положения по оси колебания
        weight  - вес точки для колебания, от него зависит инертность точки
        v       - скорость скосроти точки по оси колебания 
    */
    double z;
    double weight;
    double v;
};

class WaveDriver // класс-обработчик колебаний и создатель волн
{
private:
    static constexpr double K = 1; // константа ксиления волн
    std::vector<WaveDot> dots; // вектор всех точек колебания
    int length, height; // длина и высота поля волн
    Screen& screen; // ссылка на экран, на который будет выводится поле волн
    double getAcc(int x, int y); // функция, возвращающая ускорение данной точки
public:
    WaveDriver(Screen& _screen): screen(_screen){} //конструктор класса, вызывающий конструктор экрана
    void update(); // обновить данные, пройти 1 тик программы
    void setDotAmplitude(IntVec dot, int Amplitude); // установить положение точки в данное
    void draw(); // вывести на экран поле волн
    void clear(); // очистить поле волн, поставить все точки на 0

    void createPlate(int _length = 1280, int _height = 720); // создание рабочей области - поля волн с заданной шириной и высотой
};

#endif //WAVE_H