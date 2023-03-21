#include "vector.h"

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
int vectors2dd_are_equal(vector2d first, vector2d second)
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

// calculate the direction of a vector based off
// Arccos(x / magnitude)
double vector2d_direction(vector2d vector, int degree_mode)
{
    // arc cosine since I couldn't find any noticable performance difference between acos and atan plus acos is easier to work with
    double rads = acos(vector.x / vector2d_magnitude(vector));

    if (vector.y < 0)
        rads = 2 * M_PI - rads;

    // if mode == DEGREES (since degrees is defined as 1)
    if (degree_mode)
        return 180 * (rads / M_PI);

    return rads;
}

// find the dot product of two 3d vectors
double vector3d_dot_product(vector3d first, vector3d second)
{
    return first.x * second.x + first.y * second.y + first.z * second.z;
}

// returns the cross product of two 3d vectors
vector3d vector3d_cross_product(vector3d first, vector3d second)
{
    vector3d return_vec;
    matrix *cross_prod_matrix = create_matrix(3, 3);
    double vec_value_array[6] = {first.x, first.y, first.z, second.x, second.y, second.z};
    int index = 0;

    fill_matrix(cross_prod_matrix, 1);

    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            set_matrix_value(cross_prod_matrix, i + 1, j, vec_value_array[index]);
            index++;
        }
    }

    matrix_cofactor(cross_prod_matrix, 0, 0, &return_vec.x);
    matrix_cofactor(cross_prod_matrix, 0, 1, &return_vec.y);
    matrix_cofactor(cross_prod_matrix, 0, 2, &return_vec.z);
    delete_matrix(cross_prod_matrix);
    return return_vec;
}