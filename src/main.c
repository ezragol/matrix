#include <stdio.h>

#include "debug.h"
#include "vector.h"

int main()
{
    vector3d point = {2, -1, 7};
    plane3d plane = {4, -8, 1, 5};
    debug("%.0f",
          distance_from_plane3d(point, plane));
}