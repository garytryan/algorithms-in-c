#include <stdio.h>

int GretestProductOfThree(int *a, int l)
{
    /*
        if the array has less then 3 items, a product of 3 can't be found
    */
    if (l < 3)
    {
        return -1;
    }

    /*
        Find the minimun and maximum values in the array
    */
    int min = a[0], max = a[0];

    for (int i = 1; i < l; i++)
    {
        if (a[i] > min)
        {
            max = a[i];
        }

        if (a[i] < max)
        {
            min = a[i];
        }
    }

    /*
        Initialize three integers to track the 3 max values and 2 min values
    */
    int maxA = min, maxB = min, maxC = min, minA = max, minB = max;

    for (int i = 0; i < l; i++)
    {
        /*
            If a greater value then a max value is found bubble the max down and replace
        */
        if (a[i] > maxA)
        {
            maxC = maxB;
            maxB = maxA;
            maxA = a[i];
        }
        else if (a[i] > maxB)
        {
            maxC = maxB;
            maxB = a[i];
        }
        else if (a[i] > maxC)
        {
            maxC = a[i];
        }

        /*
            If a smaller value then a min value is found bubble the min down and replace
        */
        if (a[i] < minA)
        {
            minB = minA;
            minA = a[i];
        }
        else if (a[i] < minB)
        {
            minB = a[i];
        }
    }

    /*
        There are two ways of getting the max prod of three values.
        Try them both, and compare them.
    */
    int greatestProdA = maxA * maxB * maxC;
    int greatestProdB = minA * minB * maxA;

    return greatestProdA > greatestProdB ? greatestProdA : greatestProdB;
}

void Test()
{
    // {}: return -1
    int a[] = {};
    if (GretestProductOfThree(a, 0) != -1)
    {
        printf("Failed: expected {} to be -1, got %i\n", GretestProductOfThree(a, 0));
    }

    // {1}: return -1
    int b[] = {1};
    if (GretestProductOfThree(a, 1) != -1)
    {
        printf("Failed: expected {1} to be -1, got %i\n", GretestProductOfThree(b, 1));
    }

    // {1,2}: return -1
    int c[] = {1, 2};
    if (GretestProductOfThree(c, 2) != -1)
    {
        printf("Failed: expected {1,2} to be -1, got %i\n", GretestProductOfThree(c, 2));
    }

    // {1,2,3}: return 6
    int d[] = {1, 2, 3};
    if (GretestProductOfThree(d, 3) != 6)
    {
        printf("Failed: expected {1,2,3} to be 6, got %i\n", GretestProductOfThree(d, 3));
    }

    // {1,2,3,4}: return 24
    int e[] = {1, 2, 3, 4};
    if (GretestProductOfThree(e, 4) != 24)
    {
        printf("Failed: expected {1,2,3,4} to be 24, got %i\n", GretestProductOfThree(e, 4));
    }

    // {1,2,3,-4,-5}: return 60
    int f[] = {1, 2, 3, -4, -5};
    if (GretestProductOfThree(f, 5) != 60)
    {
        printf("Failed: expected {1,2,3,-4,-5} to be 60, got %i\n", GretestProductOfThree(f, 5));
    }

    // {-1, -2, -3, -4, -5}: return -6
    int g[] = {-1, -2, -3, -4, -5};
    if (GretestProductOfThree(g, 5) != -6)
    {
        printf("Failed: expected {-1,-2,-3,-4,-5} to be -6, got %i\n", GretestProductOfThree(g, 5));
    }
}

int main()
{
    Test();
    return 0;
}