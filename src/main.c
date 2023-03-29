#include <stdio.h>

#include "debug.h"
#include "vector.h"

int main()
{
    vector3d first = {-2, -2, 1};
    vector3d second = {1, 1, 0};
    print_vector3d(
        vector3d_projection(first, second), 1);
    return 0;
}