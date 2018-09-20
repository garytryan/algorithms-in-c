#include <stdio.h>

int Fibonacci(int n)
{
    if (n == 1 | n == 2)
    {
        return 1;
    }
    else
    {
        return Fibonacci(n - 1) + Fibonacci(n - 2);
    }
}

void T_Fibonacci()
{
    if (Fibonacci(1) != 1)
    {
        printf("Failed: Fibonacci(0) - expected 0, got %i\n", Fibonacci(1));
    }

    if (Fibonacci(2) != 1)
    {
        printf("Failed: Fibonacci(2) - expected 1, got %i\n", Fibonacci(2));
    }

    if (Fibonacci(3) != 2)
    {
        printf("Failed: Fibonacci(3) - expected 2, got %i\n", Fibonacci(3));
    }

    if (Fibonacci(4) != 3)
    {
        printf("Failed: Fibonacci(4) - expected 3, got %i\n", Fibonacci(4));
    }

    if (Fibonacci(5) != 5)
    {
        printf("Failed: Fibonacci(5) - expected 5, got %i\n", Fibonacci(5));
    }

    if (Fibonacci(6) != 8)
    {
        printf("Failed: Fibonacci(6) - expected 8, got %i\n", Fibonacci(6));
    }
}

int main()
{
    T_Fibonacci();
    return 0;
}