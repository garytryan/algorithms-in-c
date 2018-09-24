#include <stdio.h>

int Search(int *array, int length, int num)
{
    int start = 0;
    int end = length;
    int midpoint = start + ((end - start) / 2);

    while (array[midpoint] != num)
    {
        if (midpoint == 0 || midpoint == length - 1)
        {
            midpoint = -1;
            break;
        }

        if (array[midpoint] < num)
        {
            start = midpoint;
        }
        else
        {
            end = midpoint;
        }

        midpoint = start + ((end - start) / 2);
    }

    return midpoint;
}

void Test(int result, int expected)
{
    if (result != expected)
    {
        printf("Failed: expected %i, got %i\n", expected, result);
    };
}

int main()
{
    int arrayA[] = {1, 3, 5, 7, 9};
    Test(Search(arrayA, 5, 1), 0);
    Test(Search(arrayA, 5, 9), 4);
    Test(Search(arrayA, 5, 2), -1);
    Test(Search(arrayA, 5, -1), -1);
    Test(Search(arrayA, 5, 10), -1);

    return 0;
}