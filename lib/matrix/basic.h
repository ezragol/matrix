#ifndef _MATRIX_MATRIX_H_
#define _MATRIX_MATRIX_H_

#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif

#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "debug.h"

typedef struct matrix
{
    int rows;
    int cols;
    double values[];
} matrix;

matrix *create_matrix(int rows, int cols);

int within_matrix_bounds(matrix *matrix, int row, int col);
void fill_matrix(matrix *matrix, double value);

int is_square(matrix *matrix);
int have_compatible_dimensions(matrix *first, matrix *second);

int set_matrix_value(matrix *matrix, int row, int col, double value);

int get_matrix_value(matrix *matrix, int row, int col, double *value);

void delete_matrix(matrix *matrix);
void print_matrix(matrix *matrix, int precision);

#endif