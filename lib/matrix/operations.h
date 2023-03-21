#ifndef _MATRIX_OPERATIONS_H_
#define _MATRIX_OPERATIONS_H_

#include "debug.h"
#include "basic.h"

#define _ERR_NOT_SQUARE 10
#define _ERR_DIMENSIONS_COMPAT 11

void scalar_multiply_matrix(matrix *src, double scalar, matrix *dest);
int add_matrices(matrix *first, matrix *second, matrix *dest);

int multiply_matrices(matrix *first, matrix *second, matrix *dest);
int transpose_matrix(matrix *src, matrix *dest);

int get_matrix_minor(matrix *src, int row, int col, matrix *dest);

int matrix_cofactor(matrix *src, int row, int col, double *dest);
int matrix_determinant(matrix *src, double *dest);

#endif