#include <stdio.h>

/*
    Given a set of positive integers, and a value,
    determine if there is a subset with sum equal to the given value.

    example.
    set = {4, 10, 7, 22, 5, 1}, value = 8
    returns True

    There is a subset {7, 1} which sums to 8
*/

// {1,1}, 2
int SubsetSum(int *a, int l, int sum)
{
    if (l == 0)
    {
        return sum == 0 ? 1 : 0;
    }

    if (SubsetSum(a, l - 1, sum) == 1)
    {
        return 1;
    }

    if (SubsetSum(a, l - 1, sum - a[l - 1]) == 1)
    {
        return 1;
    }

    return 0;
}

void Test()
{
    // {}, 1 - return 0
    int a[] = {};
    if (SubsetSum(a, 0, 1) != 0)
    {
        printf("Failed: subset={}, value=1 - expected 0, got %i\n", SubsetSum(a, 0, 1));
    }
    // {1}, 2 - return 0
    int b[] = {1};
    if (SubsetSum(b, 1, 2) != 0)
    {
        printf("Failed: subset={1}, value=1 - expected 0, got %i\n", SubsetSum(b, 1, 2));
    }

    // {1}, 1 - return 1
    int c[] = {1};
    if (SubsetSum(c, 1, 1) != 1)
    {
        printf("Failed: subset={1}, value=1 - expected 1, got %i\n", SubsetSum(c, 1, 1));
    }

    // {1,1}, 2 - return 1
    int d[] = {1, 1};
    if (SubsetSum(d, 2, 2) != 1)
    {
        printf("Failed: subset={1, 1}, value=2 - expected 1, got %i\n", SubsetSum(d, 2, 2));
    }

    // {1,2,3}, 4 - return 1
    int e[] = {1, 2, 3};
    if (SubsetSum(e, 3, 4) != 1)
    {
        printf("Failed: subset={1, 2, 3}, value=4 - expected 1, got %i\n", SubsetSum(e, 3, 4));
    }
}

int main()
{
    Test();
    return 0;
}