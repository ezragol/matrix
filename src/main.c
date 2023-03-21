#include <stdio.h>

#include "debug.h"
#include "vector/vector.h"

int main()
{
    matrix *m = create_matrix(2, 3);
    matrix *n = create_matrix(3, 2);
    matrix *prod = create_matrix(3, 3);
    fill_matrix(m, 4);
    fill_matrix(n, 4);
    multiply_matrices(m, n, prod);

    print_matrix(prod, 1);
    delete_matrix(m);
    delete_matrix(n);
    delete_matrix(prod);
    return 0;
}