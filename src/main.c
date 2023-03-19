#include <stdio.h>

#include "debug.h"
#include "matrix/matrix.h"

int main()
{
    matrix_s *matrix = create_matrix(4, 4);
    print_matrix(matrix, 1);
    fill_matrix(matrix, 3.0);
    print_matrix(matrix, 1);
    delete_matrix(matrix);
    return 0;
}