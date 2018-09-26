#include <stdio.h>
#include <stdlib.h>

void Print_Array(int *a, int *b, int l)
{
    for (int i = 0; i < l; i++)
    {
        printf("%i\n", a[b[i]]);
    }
    printf("\n");
}

void All_Permutations(int *a, int *b, int *c, int s, int n)
{
    if (s == n)
    {
        Print_Array(a, c, s);
    }
    else
    {
        for (int i = 0; i < s; i++)
        {
            if (b[i] == 0)
            {
                c[n] = i;
                b[i] = 1;

                All_Permutations(a, b, c, s, n + 1);

                b[i] = 0;
            }
        }
    }
}

int main()
{

    int size = 3;
    int a[] = {1, 2, 3};
    int b[size]; // bit array to track what has been chosen
    int c[size]; // stores the order of the current permutation

    for (int i = 0; i < size; i++)
    {
        b[i] = 0;
    }

    All_Permutations(a, b, c, size, 0);

    return 0;
}