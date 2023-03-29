#ifndef _VECTOR_VECTOR_H_
#define _VECTOR_VECTOR_H_

#include "debug.h"
#include "matrix.h"

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

double convert_trig_mode(double rads, int degree_mode);
double convert_acos(double rads, double y_value, int degree_mode);

double vector2d_magnitude(vector2d vector);
double vector3d_magnitude(vector3d vector);

double vector2d_direction(vector2d vector, int degree_mode);

int vector2d_is_positive(vector2d vector);
int vector3d_is_positive(vector3d vector);

int vectors2d_are_equal(vector2d first, vector2d second);
int vectors3d_are_equal(vector3d first, vector3d second);

void print_vector2d(vector2d vector, int precision);
void print_vector3d(vector3d vector, int precision);

vector2d unit_vector2d(vector2d vector);
vector3d unit_vector3d(vector3d vector);

double vector3d_alpha(vector3d vector, int degree_mode);
double vector3d_beta(vector3d vector, int degree_mode);
double vector3d_gamma(vector3d vector, int degree_mode);

vector2d scalar_multiply_vector2d(vector2d vector, double scalar);
vector3d scalar_multiply_vector3d(vector3d vector, double scalar);

#endif