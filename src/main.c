#include <stdio.h>

#include "debug.h"
#include "vector.h"

int main()
{
    vector3d vec = {0,0,-1};
    debug("%f", vector3d_gamma(vec, DEGREES));
    return 0;
}