#include <stdio.h>

/*
    Given a string as an input. Print all non-empty substrings of that given string.
*/

void PrintAllSubstrings(char *string, int length)
{
    for (int i = 1; i <= length; i++)
    {
        for (int j = 0; j <= length - i; j++)
        {
            for (int k = j; k < j + i; k++)
            {
                printf("%c", string[k]);
            }

            printf("\n");
        }
    }
}

int main()
{
    PrintAllSubstrings("abcd", 4);
    return 0;
}