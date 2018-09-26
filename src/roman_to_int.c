#include <stdio.h>

int romanToInt(char *s)
{
    int count = 0;

    while (*s != '\0')
    {
        if (*s == 'I')
        {
            s++;

            if (*s == 'V' || *s == 'X')
            {
                count -= 1;
            }
            else
            {
                count += 1;
            }
        }
        else if (*s == 'V')
        {
            count += 5;
            s++;
        }
        else if (*s == 'X')

        {
            s++;

            if (*s == 'L' || *s == 'C')
            {
                count -= 10;
            }
            else
            {
                count += 10;
            }
        }
        else if (*s == 'L')
        {
            count += 50;
            s++;
        }
        else if (*s == 'C')
        {
            s++;

            if (*s == 'D' || *s == 'M')
            {
                count -= 100;
            }
            else
            {
                count += 100;
            }
        }
        else if (*s == 'D')
        {
            count += 500;
            s++;
        }
        else if (*s == 'M')
        {
            count += 1000;
            s++;
        }
    }

    return count;
}

int main()
{
    char s[] = "MCMXCIV";
    romanToInt(s);

    return 0;
}