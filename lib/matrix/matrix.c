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
int within_matrix_bounds(matrix_s *matrix, int row, int col)
{
    return row < matrix->rows && col < matrix->cols && row >= 0 && col >= 0;
}

// fill a matrix with the given value
void fill_matrix(matrix_s *matrix, double value)
{
    for (int i = 0; i < matrix->rows; i++)
    {
        for (int j = 0; j < matrix->cols; j++)
        {
            set_matrix_value(matrix, i, j, value);
        }
    }
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
int set_matrix_value(matrix_s *matrix, int row, int col, double value)
{
    double(*values)[matrix->cols] = (double(*)[matrix->cols])matrix->values;
    if (!within_matrix_bounds(matrix, row, col))
        return 1;
    values[row][col] = value;
}

// get a matrix value at the given position
int get_matrix_value(matrix_s *matrix, int row, int col, double *value)
{
    double(*values)[matrix->cols] = (double(*)[matrix->cols])matrix->values;
    if (!within_matrix_bounds(matrix, row, col))
        return 1;
    *value = values[row][col];
    return 0;
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