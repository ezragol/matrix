#ifndef _MATRIX_MATRIX_H_
#define _MATRIX_MATRIX_H_

#include <string.h>

#include "vector/vector.h"

typedef struct matrix {
    int rows;
    int cols;
    double values[];
} matrix_s;

matrix_s *create_matrix(int rows, int cols);

int within_matrix_bounds_v(matrix_s *matrix, vector2di point);
int within_matrix_bounds(matrix_s *matrix, int row, int col);
int fill_matrix(matrix_s *matrix, double value);

int is_square(matrix_s *matrix);
int have_compatible_dimensions(matrix_s *first, matrix_s *second);

int set_matrix_value_v(matrix_s *matrix, vector2di point, double value);
int set_matrix_value(matrix_s *matrix, int row, int col, double value);

int get_matrix_value_v(matrix_s *matrix, vector2di point, double *value);
int get_matrix_value(matrix_s *matrix, int row, int col, double *value);

void delete_matrix(matrix_s *matrix);
void print_matrix(matrix_s *matrix, int precision);

#endif