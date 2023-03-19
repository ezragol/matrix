#ifndef _VECTOR_VECTOR_H_
#define _VECTOR_VECTOR_H_

#include <math.h>

#include "debug.h"

typedef struct sd_vector2d {
    double x;
    double y;
} vector2dd;

typedef struct si_vector2d {
    int x;
    int y;
} vector2di;

double vector2dd_magnitude(vector2dd vector);
double vector2di_magnitude(vector2di vector);

int vector2dd_is_nonzero(vector2dd vector);
int vector2di_is_nonzero(vector2di vector);

int vectors2dd_are_equal(vector2dd first, vector2dd second);
int vectors2di_are_equal(vector2di first, vector2di second);

#endif