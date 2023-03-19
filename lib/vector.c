#include "vector.h"

double vector2dd_magnitude(vector2dd vector)
{
    return sqrt(
        pow(vector.x, 2) + pow(vector.y, 2));
}

double vector2di_magnitude(vector2di vector)
{
    vector2dd double_cast = { (double) vector.x, (double) vector.y };
    return vector2dd_magnitude(double_cast);
}

int vector2dd_is_nonzero(vector2dd vector)
{
    return vector.x >= 0.0 && vector.y >= 0.0;
}

int vector2di_is_nonzero(vector2di vector)
{
    return vector.x >= 0 && vector.y >= 0;
}

