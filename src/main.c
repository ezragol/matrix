#include <stdio.h>

#include "debug.h"
#include "matrix/matrix.h"
#include "matrix/operations.h"

int main()
{
    matrix_s *matrix = create_matrix(4, 4);
    double determinant;
    fill_matrix(matrix, 3.0);
    set_matrix_value(matrix, 0, 0, 1.0);
    set_matrix_value(matrix, 0, 2, 4.0);
    set_matrix_value(matrix, 1, 1, 2.0);
    set_matrix_value(matrix, 3, 3, 1.0);
    print_matrix(matrix, 1);
    matrix_determinant(matrix, &determinant);
    debug("detA = %.2f", determinant);
    delete_matrix(matrix);
    return 0;
}