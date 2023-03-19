#include "matrix.h"

// create an AxB matrix
matrix_s *create_matrix(int rows, int cols)
{
    matrix_s *matrix = calloc(1, sizeof *matrix + sizeof(double[rows][cols]));
    matrix->rows = rows;
    matrix->cols = cols;
    return matrix;
}

// check if a given position is within the range of a matrix
int within_matrix_bounds_v(matrix_s *matrix, vector2di point)
{
    return point.x < matrix->cols && point.y < matrix->rows && vector2di_is_nonzero(point);
}

// see "set_matrix_value_v"
int within_matrix_bounds(matrix_s *matrix, int row, int col)
{
    vector2di point = {row, col};
    return within_matrix_bounds_v(matrix, point);
}

// fill a matrix with the given value
int fill_matrix(matrix_s *matrix, double value)
{
    for (int i = 0; i < matrix->rows; i++)
    {
        for (int j = 0; j < matrix->cols; j++)
        {
            if (set_matrix_value(matrix, i, j, value))
                return 1;
        }
    }
    return 0;
}

// make sure matrix is AxA
int is_square(matrix_s *matrix)
{
    return matrix->cols == matrix->rows;
}

// make sure that the first matrix is BxA and second is AxC
int have_compatible_dimensions(matrix_s *first, matrix_s *second)
{
    return first->cols == second->rows;
}

// set the matrix value at the given position
int set_matrix_value_v(matrix_s *matrix, vector2di point, double value)
{
    double(*values)[matrix->cols] = (double(*)[matrix->cols])matrix->values;
    if (!within_matrix_bounds_v(matrix, point))
        return 1;
    values[point.x][point.y] = value;
    return 0;
}

// see "set_matrix_value_v"
int set_matrix_value(matrix_s *matrix, int row, int col, double value)
{
    vector2di point = {row, col};
    return set_matrix_value_v(matrix, point, value);
}

// get a matrix value at the given position
int get_matrix_value_v(matrix_s *matrix, vector2di point, double *value)
{
    double(*values)[matrix->cols] = (double(*)[matrix->cols])matrix->values;
    if (!within_matrix_bounds_v(matrix, point))
        return 1;
    *value = values[point.x][point.y];
    return 0;
}

// see "get_matrix_value_v"
int get_matrix_value(matrix_s *matrix, int row, int col, double *value)
{
    vector2di point = {row, col};
    return get_matrix_value_v(matrix, point, value);
}

// free matrix
void delete_matrix(matrix_s *matrix)
{
    free(matrix);
}

// print all values in the matrix
void print_matrix(matrix_s *matrix, int precision)
{
    printf("[");
    char print_organizer[10];
    sprintf(print_organizer, " %%.%df ", precision);
    for (int i = 0; i < matrix->rows; i++)
    {
        for (int j = 0; j < matrix->cols; j++)
        {
            double current_val = 0.0;
            get_matrix_value(matrix, i, j, &current_val);
            printf(print_organizer, current_val);
        }
        if (i < matrix->rows - 1)
            printf("\n ");
    }
    printf("]\n");
}