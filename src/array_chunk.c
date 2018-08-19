#include <stdio.h>
#include <stdlib.h>

void print_int_matrix(int x, int y, int **matrix)
{
    for (int i = 0; i < x; i++)
    {
        printf("[");
        for (int j = 0; j < y; j++)
        {
            printf("%i, ", matrix[i][j]);
        }
        printf("]\n");
    }
    printf("\n");
}

int **chunk(int *array, int length, int size)
{
    int rows = length % size == 0 ? length / size : length / size + 1;
    int **m = calloc(sizeof(int *), rows);

    for (int i = 0; i < rows; i++)
    {
        m[i] = calloc(sizeof(int), size);

        int cols = length - (size * i) >= size ? size : (length - (size * i)) % size;
        for (int j = 0; j < cols; j++)
        {
            m[i][j] = array[i * size + j];
        }
    }

    return m;
}

int main()
{
    // Given an array and chunk size, divide the array into many subarray
    // where each subarray is of length size
    int a[] = {1, 2, 3, 4};
    print_int_matrix(2, 2, chunk(a, 4, 2));

    int b[] = {1, 2, 3, 4, 5};
    print_int_matrix(3, 2, chunk(b, 5, 2));

    int c[] = {1, 2, 3, 4, 5, 6, 7, 8};
    print_int_matrix(3, 3, chunk(c, 8, 3));

    int d[] = {1, 2, 3, 4, 5};
    print_int_matrix(2, 4, chunk(d, 5, 4));

    int e[] = {1, 2, 3, 4, 5};
    print_int_matrix(1, 10, chunk(e, 5, 10));

    return 0;
}