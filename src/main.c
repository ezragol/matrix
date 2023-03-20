#include <stdio.h>

#include "debug.h"
#include "vector/vector.h"

// todo test multiplication
int main()
{
    vector3d_s first = {1, 2, 3};
    vector3d_s second = {2, 3, 4};
    debug("%.1f",vector3d_dot_product(first, second));
    return 0;
}