#include "matrix.h"

matrix_s *create_matrix(int rows, int cols)
{
    matrix_s *matrix = calloc(1, sizeof *matrix + sizeof(double[rows][cols]));
    matrix->rows = rows;
    matrix->cols = cols;
    return matrix;
}

int within_matrix_bounds(matrix_s *matrix, int row, int col)
{
    vector2di point = {row, col};
    return within_matrix_bounds_v(matrix, point);
}

// see "set_matrix_value_v"
int within_matrix_bounds_v(matrix_s *matrix, vector2di point)
{
    return point.x < matrix->cols && point.y < matrix->rows && vector2di_is_nonzero(point);
}

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

// matrices use [row,column] so you gotta set the row at the y-coordinate
// since the rows are stacked vertically
int set_matrix_value_v(matrix_s *matrix, vector2di point, double value)
{
    double(*values)[matrix->cols] = (double(*)[matrix->cols])matrix->values;
    if (!within_matrix_bounds_v(matrix, point))
        return 1;
    values[point.x][point.y] = value;
    return 0;
}

int set_matrix_value(matrix_s *matrix, int row, int col, double value)
{
    vector2di point = {row, col};
    return set_matrix_value_v(matrix, point, value);
}

int get_matrix_value_v(matrix_s *matrix, vector2di point, double *value)
{
    double(*values)[matrix->cols] = (double(*)[matrix->cols])matrix->values;
    if (!within_matrix_bounds_v(matrix, point))
        return 1;
    *value = values[point.x][point.y];
    return 0;
}

int get_matrix_value(matrix_s *matrix, int row, int col, double *value)
{
    vector2di point = {row, col};
    return get_matrix_value_v(matrix, point, value);
}

void delete_matrix(matrix_s *matrix)
{
    free(matrix);
}

// TODO work on display
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