#include <stdio.h>

int main()
{
    int isPallindrome = 1;

    char string[] = "abcdcba";
    int length = sizeof(string) / sizeof(char);

    int index = 0;
    while (isPallindrome == 1 && index < length / 2)
    {
        if (string[index] != string[length - index - 2])
        {
            isPallindrome = 0;
        }

        index++;
    }

    printf("isPallindrome: %i\n", isPallindrome);
    return 0;
}