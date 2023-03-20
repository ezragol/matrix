#include "vector.h"

// return magnitude of given vector
double vector2dd_magnitude(vector2dd_s vector)
{
    return sqrt(
        pow(vector.x, 2) + pow(vector.y, 2));
}

// see "vector2dd_magnitude"
double vector2di_magnitude(vector2di_s vector)
{
    vector2dd_s cast = { vector.x, vector.y };
    return vector2dd_magnitude(cast);
}

// return magnitude of given 3d vector
double vector3d_magnitude(vector3d_s vector)
{
    return sqrt(
        pow(vector.x, 2) + pow(vector.y, 2) + pow(vector.z, 2));
}

// check that a vector is positive or equal to the zero vector
int vector2dd_is_positive(vector2dd_s vector)
{
    return vector.x >= 0 && vector.y >= 0;
}

// see "vector2dd_is_nonzero"
int vector2di_is_positive(vector2di_s vector)
{
    return vector.x >= 0 && vector.y >= 0;
}

// check that a 3d vector is positive or equal to the zero vector
int vector3d_is_positive(vector3d_s vector)
{
    return vector.x >= 0 && vector.y >= 0 && vector.z >= 0;
}

// check if two vectors have a difference in value less than DBL_EPSILON
// don't use unless you have to since it is not a perfect comparison
int vectors2dd_are_equal(vector2dd_s first, vector2dd_s second)
{
    return fabs(first.x - second.x) <= __DBL_EPSILON__ && fabs(first.y - second.y) <= __DBL_EPSILON__;
}

// see if two integer vectors are completely equal
int vectors2di_are_equal(vector2di_s first, vector2di_s second)
{
    return first.x == second.x && first.y == second.y;
}

// check if two 3d vectors have a difference in value less than DBL_EPSILON
// see "vectors2dd_are_equal"
int vectors3d_are_equal(vector3d_s first, vector3d_s second)
{
    return fabs(first.x - second.x) <= __DBL_EPSILON__ && fabs(first.y - second.y) <= __DBL_EPSILON__ && fabs(first.z - second.z) <= __DBL_EPSILON__;
}

// calculate the direction of a vector based off
// Arccos(x / magnitude)
double vector2dd_direction(vector2dd_s vector, int degree_mode)
{
    // arc cosine since I couldn't find any noticable performance difference between acos and atan plus acos is easier to work with
    double rads = acos(vector.x / vector2dd_magnitude(vector));

    if (vector.y < 0)
        rads = 2 * M_PI - rads;

    // if mode == DEGREES (since degrees is defined as 1)
    if (degree_mode)
        return 180 * (rads / M_PI);

    return rads;
}

// see "vector2dd_direction"
double vector2di_direction(vector2di_s vector, int degree_mode)
{
    vector2dd_s cast = { vector.x, vector.y };
    return vector2dd_direction(cast, degree_mode);
}