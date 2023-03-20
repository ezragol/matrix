#ifndef _VECTOR_VECTOR_H_
#define _VECTOR_VECTOR_H_

#include "debug.h"
#include "matrix/operations.h"

#define RADIANS 0
#define DEGREES 1

typedef struct vector2dd {
    double x;
    double y;
} vector2dd_s;

typedef struct vector2di {
    int x;
    int y;
} vector2di_s;

typedef struct vector3d {
    double x;
    double y;
    double z;
} vector3d_s;

double vector2dd_magnitude(vector2dd_s vector);
double vector2di_magnitude(vector2di_s vector);

double vector3d_magnitude(vector3d_s vector);

int vector2dd_is_positive(vector2dd_s vector);
int vector2di_is_positive(vector2di_s vector);

int vector3d_is_positive(vector3d_s vector);

int vectors2dd_are_equal(vector2dd_s first, vector2dd_s second);
int vectors2di_are_equal(vector2di_s first, vector2di_s second);

int vectors3d_are_equal(vector3d_s first, vector3d_s second);

double vector2dd_direction(vector2dd_s vector, int degree_mode);
double vector2di_direction(vector2di_s vector, int degree_mode);

void vector3d_cross_product(vector3d_s *vector, vector3d_s first, vector3d_s second);

#endif