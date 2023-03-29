#ifndef _VECTOR_OPERATIONS_H_
#define _VECTOR_OPERATIONS_H_

#include "basic.h"

double vector3d_dot_product(vector3d first, vector3d second);
vector3d vector3d_cross_product(vector3d first, vector3d second);

double angle_between_vectors3d(vector3d first, vector3d second, int degree_mode);

double scalar_projection_vector3d(vector3d vector, vector3d onto);
vector3d vector3d_projection(vector3d vector, vector3d onto);

#endif