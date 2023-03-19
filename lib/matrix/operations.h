#ifndef _MATRIX_OPERATIONS_H_
#define _MATRIX_OPERATIONS_H_

#include "debug.h"
#include "matrix.h"

int scalar_multiply_matrix(matrix_s *matrix, double scalar);
int add_matrices(matrix_s *first, matrix_s *second);
matrix_s *multiply_matrices(matrix_s *first, matrix_s *second);

matrix_s *transpose_matrix(matrix_s *matrix);

matrix_s *get_matrix_minor_v(matrix_s *matrix, vector2di exclude_basis);
matrix_s *get_matrix_minor(matrix_s *matrix, int row, int col);

int matrix_cofactor(matrix_s *matrix, int row, int col, double *value);
int matrix_determinant(matrix_s *matrix, double *value);

#endif