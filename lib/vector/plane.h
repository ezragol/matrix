#ifndef _VECTOR_PLANE_H_
#define _VECTOR_PLANE_H_

#include "operations.h"

typedef struct plane3d {
  double a;
  double b;
  double c;
  double d;
} plane3d;

vector3d plane_normal_vector3d(plane3d plane);
double distance_from_plane3d(vector3d point, plane3d plane);

#endif