#ifndef MATHFUNCTIONS_H
#define MATHFUNCTIONS_H

#include <math.h>

struct IntVec
{
    int x, y;
};

inline double getDistance(int x1, int y1, int x2, int y2)
{
    return sqrt((x1 - x2)*(x1 - x2) + (y1 - y2)*(y1 - y2));
}

#endif // MATHFUNCTIONS_H