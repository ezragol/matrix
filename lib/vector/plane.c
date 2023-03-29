#include "plane.h"

// find the normal vector of the given plane
vector3d plane_normal_vector3d(plane3d plane)
{
  vector3d normal = {plane.a, plane.b, plane.c};
  return normal;
}

// find the distance between a point in space and a plane (always positive)
double distance_from_plane3d(vector3d point, plane3d plane)
{
  vector3d normal = plane_normal_vector3d(plane);
  return fabs(
    vector3d_dot_product(point, normal) - plane.d) / vector3d_magnitude(normal);
}