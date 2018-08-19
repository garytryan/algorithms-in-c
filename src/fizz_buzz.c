#include <stdio.h>

int main()
{
    // write a program that console logs the numbers
    // from 1 to n
    // for multiples of 3 print 'fizz'
    // for multiples of 5 print 'buzz'
    // for mutliples of both 3 and 5 print fizzbuzz

    int n = 15;
    for (int i = 1; i <= n; i++)
    {
        if (i % 3 == 0 && i % 5 == 0)
        {
            printf("fizzbuzz\n");
        }
        else if (i % 3 == 0)
        {
            printf("fizz\n");
            continue;
        }
        else if (i % 5 == 0)
        {
            printf("buzz\n");
        }
        else
        {
            printf("%i\n", i);
        }
    }
    return 0;
}