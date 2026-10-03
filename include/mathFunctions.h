#ifndef MATHFUNCTIONS_H
#define MATHFUNCTIONS_H

#include <math.h>

struct IntVec //структура, хранящая двумерный вектор в целочисленных координатах
{
    int x, y;
};

inline double getDistance(int x1, int y1, int x2, int y2)
{
    /* возвращает расстояние между двумя точками по теореме Пифагора
        Аргументы:
            x1, y1 - координаты первой точки
            x1, x2 - координаты второй точки
    */
    return sqrt((x1 - x2)*(x1 - x2) + (y1 - y2)*(y1 - y2));
}

#endif // MATHFUNCTIONS_H