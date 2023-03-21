#include "operations.h"

// multiply all values in matrix by a number
void scalar_multiply_matrix(matrix *src, double scalar, matrix *dest)
{
    for (int i = 0; i < src->rows; i++)
    {
        for (int j = 0; j < src->cols; j++)
        {
            double value;
            get_matrix_value(src, i, j, &value);
            set_matrix_value(dest, i, j, value * scalar);
        }
    }
}

// adds all values from second matrix onto first
// checks if they have compatible dimensions
int add_matrices(matrix *first, matrix *second, matrix *dest)
{
    if (first->rows != second->rows || first->cols != second->cols)
        return _ERR_DIMENSIONS_COMPAT;

    for (int i = 0; i < first->rows; i++)
    {
        for (int j = 0; j < first->cols; j++)
        {
            double first_value, second_value;
            get_matrix_value(first, i, j, &first_value);
            get_matrix_value(second, i, j, &second_value);
            set_matrix_value(dest, i, j, first_value + second_value);
        }
    }
    return 0;
}

// multiply two matrices together
// kinda bad ; definitely not perfect
int multiply_matrices(matrix *first, matrix *second, matrix *dest)
{
    if (!have_compatible_dimensions(first, second))
        return _ERR_DIMENSIONS_COMPAT;

    int first_rows = first->rows, first_cols = first->cols;
    double(*first_values)[first->cols] = (double(*)[first->cols])first->values;

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
            set_matrix_value(dest, i, j, sum);
        }
    }
    return 0;
}

// transpose matrix: AxB -> BxA
int transpose_matrix(matrix *src, matrix *dest)
{
    int rows = src->rows, cols = src->cols;
    double(*values)[cols] = (double(*)[cols])src->values;

    if (dest->rows != cols || dest->cols != rows)
        return _ERR_DIMENSIONS_COMPAT;

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            set_matrix_value(dest, j, i, values[i][j]);
        }
    }
    return 0;
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
int get_matrix_minor(matrix *src, int row, int col, matrix *dest)
{
    if (!is_square(src))
        return _ERR_NOT_SQUARE;

    int rows = src->rows;
    int minorI = 0;
    double(*values)[rows] = (double(*)[rows])src->values;

    for (int i = 0; i < rows; i++)
    {
        int minorJ = 0;
        if (i != row)
        {
            for (int j = 0; j < rows; j++)
            {
                if (j != col)
                {
                    set_matrix_value(dest, minorI, minorJ, values[i][j]);
                    minorJ++;
                }
            }
            minorI++;
        }
    }
    return 0;
}

// using LaPlace expansion for finding determinants
// need to create a sum of all sum-determinants using recursion
// assigns value to "dest"
int matrix_cofactor(matrix *src, int row, int col, double *dest)
{
    matrix *minor = create_matrix(src->rows - 1, src->rows - 1);

    double sign = pow(-1.0, row + col);
    double minor_determinant;
    int minortatus = get_matrix_minor(src, row, col, minor);
    int determinanttatus = matrix_determinant(minor, &minor_determinant);

    if (determinanttatus != 0 || minortatus != 0)
        return _ERR_NOT_SQUARE;

    delete_matrix(minor);
    *dest = minor_determinant * sign;
    return 0;
}

// return the determinant of the given matrix
// assigns the value to "dest"
int matrix_determinant(matrix *src, double *dest)
{
    if (!is_square(src))
        return _ERR_NOT_SQUARE;

    int rows = src->rows;
    double sum = 0.0;

    // determinant of 1x1 matrix is just the value inside row 1 col 1
    // assign to double pointer (dest)
    if (rows == 1)
    {
        get_matrix_value(src, 0, 0, dest);
        return 0;
    }

    for (int i = 0; i < rows; i++)
    {
        double current_value, cofactor_value;

        get_matrix_value(src, 0, i, &current_value);
        matrix_cofactor(src, 0, i, &cofactor_value);
        sum += current_value * cofactor_value;
    }

    *dest = sum;
    return 0;
}