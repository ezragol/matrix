#include "operations.h"

// multiply all values in matrix by a number
// assignment happens inside if statement - probably not great
int scalar_multiply_matrix(matrix_s *matrix, double scalar)
{
    for (int i = 0; i < matrix->rows; i++)
    {
        for (int j = 0; j < matrix->cols; j++)
        {
            double value;
            if (get_matrix_value(matrix, i, j, &value) || set_matrix_value(matrix, i, j, value * scalar))
                return 1;
        }
    }
    return 0;
}

// adds all values from second matrix onto first
// checks if they have compatible dimensions
// assignment happens inside if statement - probably not great
int add_matrices(matrix_s *first, matrix_s *second)
{
    vector2di_s first_dimensions = {first->rows, first->cols};
    vector2di_s second_dimensions = {second->rows, second->cols};

    if (!vectors2di_are_equal(first_dimensions, second_dimensions))
        return 1;

    for (int i = 0; i < first->rows; i++)
    {
        for (int j = 0; j < first->cols; j++)
        {
            double first_value, second_value;
            if (get_matrix_value(first, i, j, &first_value) || get_matrix_value(second, i, j, &second_value) || set_matrix_value(first, i, j, first_value + second_value))
                return 1;
        }
    }
    return 0;
}

// multiply two matrices together
// kinda bad ; definitely not perfect
matrix_s *multiply_matrices(matrix_s *first, matrix_s *second)
{
    if (!have_compatible_dimensions(first, second))
        fail(1, "cannot multiply incompatible matrices");

    int first_rows = first->rows, first_cols = first->cols;
    double(*first_values)[first->cols] = (double(*)[first->cols])first->values;

    matrix_s *new_matrix = create_matrix(first_rows, second->cols);

    for (int i = 0; i < first_rows; i++)
    {
        for (int j = 0; j < second->cols; j++)
        {
            double sum = 0.0;
            for (int t = 0; t < first_cols; t++)
            {
                double second_value;
                get_matrix_value(second, t, j, &second_value);
                sum += first_values[i][t] * second_value;
            }
            set_matrix_value(new_matrix, i, j, sum);
        }
    }
    return new_matrix;
}

// transpose matrix: AxB -> BxA
// probably fine
matrix_s *transpose_matrix(matrix_s *matrix)
{
    int rows = matrix->rows, cols = matrix->cols;
    double(*values)[cols] = (double(*)[cols])matrix->values;

    matrix_s *new_matrix = create_matrix(cols, rows);

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            set_matrix_value(new_matrix, j, i, values[i][j]);
        }
    }
    return new_matrix;
}

// get a smaller (minor) matrix based off an excluded row and column
// example:
/* [ 01 02 03 04
     05 06 07 08
     09 10 11 12
     13 14 15 16 ]

   -> getminor(1, 1) ->

   [ 01 03 04
     09 11 12
     13 15 16 ]
*/
matrix_s *get_matrix_minor_v(matrix_s *matrix, vector2di_s exclude_basis)
{
    if (!is_square(matrix))
        fail(1, "cannot get minor of a non-square matrix");

    int rows = matrix->rows;
    int minorI = 0;
    double(*values)[rows] = (double(*)[rows])matrix->values;

    matrix_s *new_matrix = create_matrix(rows - 1, rows - 1);

    for (int i = 0; i < rows; i++)
    {
        int minorJ = 0;
        if (i != exclude_basis.x)
        {
            for (int j = 0; j < rows; j++)
            {
                if (j != exclude_basis.y)
                {
                    set_matrix_value(new_matrix, minorI, minorJ, values[i][j]);
                    minorJ++;
                }
            }
            minorI++;
        }
    }

    return new_matrix;
}

// see "get_matrix_minor_v"
matrix_s *get_matrix_minor(matrix_s *matrix, int row, int col)
{
    vector2di_s point = {row, col};
    return get_matrix_minor_v(matrix, point);
}

// using LaPlace expansion for finding determinants
// need to create a sum of all sum-determinants using recursion
int matrix_cofactor(matrix_s *matrix, int row, int col, double *value)
{
    matrix_s *minor = get_matrix_minor(matrix, row, col);
    double sign = pow(-1.0, row + col);
    double minor_determinant;

    if (matrix_determinant(minor, &minor_determinant))
        return 1;

    delete_matrix(minor);
    *value = minor_determinant * sign;
    return 0;
}

// return the determinant of the given matrix
int matrix_determinant(matrix_s *matrix, double *value)
{
    if (!is_square(matrix))
        return 1;

    int rows = matrix->rows;
    double sum = 0.0;

    if (rows == 1)
    {
        if (get_matrix_value(matrix, 0, 0, value))
            return 1;
        return 0;
    }

    for (int i = 0; i < rows; i++)
    {
        double current_value, cofactor_value;
        if (get_matrix_value(matrix, 0, i, &current_value) || matrix_cofactor(matrix, 0, i, &cofactor_value))
            return 1;

        sum += current_value * cofactor_value;
    }

    *value = sum;
    return 0;
}