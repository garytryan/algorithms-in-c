#include <stdio.h>

void PrintArray(int *a, int l)
{
    for (int i = 0; i < l; i++)
    {
        printf("%i, ", a[i]);
    }

    printf("\n");
}

void QuicksortHelper(int *a, int start, int end)
{
    PrintArray(a, 6);

    if (start >= end)
    {
        return;
    }

    int p1 = start;
    int p2 = end;
    int p = a[(start + end) / 2];

    while (p1 < p2)
    {
        while (a[p1] < p)
        {
            p1++;
        }

        while (a[p2] > p)
        {
            p2--;
        }

        int t = a[p1];
        a[p1] = a[p2];
        a[p2] = t;

        p1++;
        p2--;
    }

    QuicksortHelper(a, start, p1 - 1);
    QuicksortHelper(a, p1, end);
}

void Quicksort(int *a, int l)
{
    QuicksortHelper(a, 0, l - 1);
}

void Test()
{
    int a[] = {-1, 0, 1, 2, -1, -4};
    Quicksort(a, 6);

    int expected[] = {-4, -1, -1, 0, 1, 2};

    for (int i = 0; i < 6; i++)
    {
        if (a[i] != expected[i])
        {
            printf("Failed: expeted %i, got %i\n", expected[i], a[i]);
            PrintArray(a, 6);
            break;
        }
    }
}

int main()
{
    Test();
    return 0;
}