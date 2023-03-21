#ifndef _VECTOR_VECTOR_H_
#define _VECTOR_VECTOR_H_

#include "debug.h"
#include "matrix/operations.h"

#define RADIANS 0
#define DEGREES 1

typedef struct vector2d {
    double x;
    double y;
} vector2d;

typedef struct vector3d {
    double x;
    double y;
    double z;
} vector3d;

double vector2d_magnitude(vector2d vector);
double vector3d_magnitude(vector3d vector);

int vector2dd_is_positive(vector2d vector);
int vector3d_is_positive(vector3d vector);

int vectors2dd_are_equal(vector2d first, vector2d second);
int vectors3d_are_equal(vector3d first, vector3d second);

void print_vector2dd(vector2d vector, int precision);
void print_vector3d(vector3d vector, int precision);

//-------------------------//

vector2d unit_vector2dd(vector2d vector);
vector3d unit_vector3d(vector3d vector);

double vector2dd_direction(vector2d vector, int degree_mode);

double vector3d_dot_product(vector3d first, vector3d second);
vector3d vector3d_cross_product(vector3d first, vector3d second);

// TODO (up next)
// double vector3d_alpha_angle(vector3d vector);
// double vector3d_beta_angle(vector3d vector);
// double vector3d_gamma_angle(vector3d vector);

#endif