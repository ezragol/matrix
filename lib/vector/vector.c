#include "vector.h"

// return magnitude of given vector
double vector2dd_magnitude(vector2dd vector)
{
    return sqrt(
        pow(vector.x, 2) + pow(vector.y, 2));
}

// see "vector2dd_magnitude"
double vector2di_magnitude(vector2di vector)
{
    vector2dd double_cast = { (double) vector.x, (double) vector.y };
    return vector2dd_magnitude(double_cast);
}

// check that a vector is positive or equal to the zero vector
int vector2dd_is_nonzero(vector2dd vector)
{
    return vector.x >= 0.0 && vector.y >= 0.0;
}

// see "vector2dd_is_nonzero"
int vector2di_is_nonzero(vector2di vector)
{
    return vector.x >= 0 && vector.y >= 0;
}

// check if two vectors have a difference in value less than DBL_EPSILON
int vectors2dd_are_equal(vector2dd first, vector2dd second)
{
    return first.x - second.x <= __DBL_EPSILON__ && first.y - second.y <= __DBL_EPSILON__;
}

// see if two integer vectors are completely equal
int vectors2di_are_equal(vector2di first, vector2di second)
{
    return first.x == second.x && first.y == second.y;
}