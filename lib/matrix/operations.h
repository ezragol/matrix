#ifndef _MATRIX_OPERATIONS_H_
#define _MATRIX_OPERATIONS_H_

#include "debug.h"
#include "matrix.h"

#define _ERR_NOT_SQUARE 10
#define _ERR_DIMENSIONS_COMPAT 11

void scalar_multiply_matrix(matrix_s *matrix, double scalar, matrix_s *dest);
int add_matrices(matrix_s *first, matrix_s *second, matrix_s *dest);

int multiply_matrices(matrix_s *first, matrix_s *second, matrix_s *dest);
int transpose_matrix(matrix_s *matrix, matrix_s *dest);

int get_matrix_minor(matrix_s *matrix, int row, int col, matrix_s *dest);

int matrix_cofactor(matrix_s *matrix, int row, int col, double *dest);
int matrix_determinant(matrix_s *matrix, double *dest);

#endif