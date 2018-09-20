#include <stdio.h>

int Fibonacci(int n, int i, int a, int b)
{
    if (i == n + 1)
    {
        return b;
    }

    if (i <= 2)
    {
        return Fibonacci(n, ++i, 1, 1);
    }

    return Fibonacci(n, ++i, b, a + b);
}

void T_Fibonacci()
{
    if (Fibonacci(1, 0, 0, 0) != 1)
    {
        printf("Failed: Fibonacci(0) - expected 0, got %i\n", Fibonacci(1, 0, 0, 0));
    }

    if (Fibonacci(2, 0, 0, 0) != 1)
    {
        printf("Failed: Fibonacci(2, 0, 0, 0) - expected 1, got %i\n", Fibonacci(2, 0, 0, 0));
    }

    if (Fibonacci(3, 0, 0, 0) != 2)
    {
        printf("Failed: Fibonacci(3, 0, 0, 0) - expected 2, got %i\n", Fibonacci(3, 0, 0, 0));
    }

    if (Fibonacci(4, 0, 0, 0) != 3)
    {
        printf("Failed: Fibonacci(4, 0, 0, 0) - expected 3, got %i\n", Fibonacci(4, 0, 0, 0));
    }

    if (Fibonacci(5, 0, 0, 0) != 5)
    {
        printf("Failed: Fibonacci(5, 0, 0, 0) - expected 5, got %i\n", Fibonacci(5, 0, 0, 0));
    }

    if (Fibonacci(6, 0, 0, 0) != 8)
    {
        printf("Failed: Fibonacci(6, 0, 0, 0) - expected 8, got %i\n", Fibonacci(6, 0, 0, 0));
    }
}

int main()
{
    T_Fibonacci();
    return 0;
}