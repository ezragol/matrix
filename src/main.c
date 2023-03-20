#include <stdio.h>

#include "debug.h"
#include "matrix/matrix.h"
#include "matrix/operations.h"

int main()
{
    vector2di_s vec = {2, 2};
    debug("%.0f", vector2di_direction(vec, DEGREES));
    return 0;
}