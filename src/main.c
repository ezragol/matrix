#include <stdio.h>

#include "debug.h"
#include "matrix/operations.h"

// todo test multiplication
int main()
{
    matrix_s *mm = create_matrix(4, 3);
    matrix_s *mn = create_matrix(4, 3);
    matrix_s *dest = create_matrix(4, 3);
    fill_matrix(mm, 4);
    fill_matrix(mn, 3);
    add_matrices(mm, mn, dest);
    print_matrix(dest, 1);
    delete_matrix(mm);
    delete_matrix(mn);
    delete_matrix(dest);
    return 0;
}