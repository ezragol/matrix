#include <stdio.h>

#include "debug.h"
#include "vector.h"

int main()
{
    vector3d first = {0,0,1};
    vector3d second = {1,1,0};
    debug("%f", angle_between_vectors3d(first, second, DEGREES));
    return 0;
}