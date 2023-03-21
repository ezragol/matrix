#include "operations.h"

// find the dot product of two 3d vectors
double vector3d_dot_product(vector3d first, vector3d second)
{
    return first.x * second.x + first.y * second.y + first.z * second.z;
}

// returns the cross product of two 3d vectors
vector3d vector3d_cross_product(vector3d first, vector3d second)
{
    vector3d return_vec;
    matrix *cross_prod_matrix = create_matrix(3, 3);
    double vec_value_array[6] = {first.x, first.y, first.z, second.x, second.y, second.z};
    int index = 0;

    fill_matrix(cross_prod_matrix, 1);

    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            set_matrix_value(cross_prod_matrix, i + 1, j, vec_value_array[index]);
            index++;
        }
    }

    matrix_cofactor(cross_prod_matrix, 0, 0, &return_vec.x);
    matrix_cofactor(cross_prod_matrix, 0, 1, &return_vec.y);
    matrix_cofactor(cross_prod_matrix, 0, 2, &return_vec.z);
    delete_matrix(cross_prod_matrix);
    return return_vec;
}