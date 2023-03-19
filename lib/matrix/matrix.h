#include <string.h>

#include "debug.h"
#include "vector.h"

typedef struct matrix {
    int rows;
    int cols;
    double values[];
} matrix_s;

matrix_s *create_matrix(int rows, int cols);

int within_matrix_bounds_v(matrix_s *matrix, vector2di point);
int within_matrix_bounds(matrix_s *matrix, int row, int col);
int fill_matrix(matrix_s *matrix, double value);

int set_matrix_value_v(matrix_s *matrix, vector2di point, double value);
int set_matrix_value(matrix_s *matrix, int row, int col, double value);

int get_matrix_value_v(matrix_s *matrix, vector2di point, double *value);
int get_matrix_value(matrix_s *matrix, int row, int col, double *value);

void delete_matrix(matrix_s *matrix);

void print_matrix(matrix_s *matrix, int precision);