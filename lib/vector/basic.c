#include "basic.h"

double convert_trig_mode(double rads, int degree_mode)
{
    // if mode == DEGREES (since degrees is defined as 1)
    if (degree_mode)
        return 180 * (rads / M_PI);
    return rads;
}

double convert_acos(double rads, double y_value, int degree_mode)
{
    if (y_value < 0)
        rads = 2 * M_PI - rads;
    return convert_trig_mode(rads, degree_mode);
}

// return magnitude of given vector
double vector2d_magnitude(vector2d vector)
{
    return sqrt(
        pow(vector.x, 2) + pow(vector.y, 2));
}

// return magnitude of given 3d vector
double vector3d_magnitude(vector3d vector)
{
    return sqrt(
        pow(vector.x, 2) + pow(vector.y, 2) + pow(vector.z, 2));
}

// calculate the direction of a vector based off
// Arccos(x / magnitude)
double vector2d_direction(vector2d vector, int degree_mode)
{
    // arc cosine since I couldn't find any noticable performance difference between acos and atan plus acos is easier to work with
    double rads = acos(vector.x / vector2d_magnitude(vector));

    return convert_acos(rads, vector.y, degree_mode);
}

// check that a vector is positive or equal to the zero vector
int vector2d_is_positive(vector2d vector)
{
    return vector.x >= 0 && vector.y >= 0;
}

// check that a 3d vector is positive or equal to the zero vector
int vector3d_is_positive(vector3d vector)
{
    return vector.x >= 0 && vector.y >= 0 && vector.z >= 0;
}

// check if two vectors have a difference in value less than DBL_EPSILON
// don't use unless you have to since it is not a perfect comparison
int vectors2d_are_equal(vector2d first, vector2d second)
{
    return fabs(first.x - second.x) <= __DBL_EPSILON__ && fabs(first.y - second.y) <= __DBL_EPSILON__;
}

// check if two 3d vectors have a difference in value less than DBL_EPSILON
// see "vectors2dd_are_equal"
int vectors3d_are_equal(vector3d first, vector3d second)
{
    return fabs(first.x - second.x) <= __DBL_EPSILON__ && fabs(first.y - second.y) <= __DBL_EPSILON__ && fabs(first.z - second.z) <= __DBL_EPSILON__;
}

// print all values in 2d vector
void print_vector2d(vector2d vector, int precision)
{
    char print_organizer[15];
    sprintf(print_organizer, "<%%.%df, %%.%df>\n", precision, precision);
    printf(print_organizer, vector.x, vector.y);
}

// print all values in 3d vector
void print_vector3d(vector3d vector, int precision)
{
    char print_organizer[23];
    sprintf(print_organizer, "<%%.%df, %%.%df, %%.%df>\n", precision, precision, precision);
    printf(print_organizer, vector.x, vector.y, vector.z);
}

// calculate unit vector of 2d vector
vector2d unit_vector2d(vector2d vector)
{
    vector2d unit_v = vector;
    double magnitude = vector2d_magnitude(vector);
    // magnitude == 0 -> can't divide by zero
    if (!magnitude)
        fail(1, "can't file unit vector of the zero vector");

    unit_v.x /= magnitude;
    unit_v.y /= magnitude;
    return unit_v; 
}

// calculate unit vector of a 3d vector
vector3d unit_vector3d(vector3d vector)
{
    vector3d unit_v = vector;
    double magnitude = vector3d_magnitude(vector);
    // magnitude == 0 -> can't divide by zero
    if (!magnitude)
        fail(1, "can't file unit vector of the zero vector");

    unit_v.x /= magnitude;
    unit_v.y /= magnitude;
    unit_v.z /= magnitude;
    return unit_v; 
}

// Alpha/Beta/Gamma angles for vector <x,y,z>
// angles are always between [0,180] so
// acos doesn't need to be adjusted at all
// since it has the same range

// calculate the alpha angle of a 3d vector
double vector3d_alpha(vector3d vector, int degree_mode)
{
    vector3d cosine_vec = unit_vector3d(vector);
    return convert_trig_mode(
        acos(cosine_vec.x), degree_mode);
}

// calculate the beta angle of a 3d vector
double vector3d_beta(vector3d vector, int degree_mode)
{
    vector3d cosine_vec = unit_vector3d(vector);
    return convert_trig_mode(
        acos(cosine_vec.y), degree_mode);
}

// calculate the gamma angle of a 3d vector
double vector3d_gamma(vector3d vector, int degree_mode)
{
    vector3d cosine_vec = unit_vector3d(vector);
    return convert_trig_mode(
        acos(cosine_vec.z), degree_mode);
}