#include <stdio.h>

char max_char(char *string)
{
    int index = 1;

    int frequency[255] = {0};

    while (string[index] != '\0')
    {
        frequency[(int)string[index]] = frequency[(int)string[index]] + 1;
        index++;
    }

    int maxCharIndex = frequency[0];
    for (int i = 1; i < 255; i++)
    {
        if (frequency[maxCharIndex] < frequency[i])
        {
            maxCharIndex = i;
        }
    }

    return (char)maxCharIndex;
}

int main()
{
    // Given a string, return the character that is most commonly used in the string
    printf("aaA1bcccccd: %c - should be c\n", max_char("aaA1bcccccd"));
    printf("1231111: %c - should be 1\n", max_char("apple 1231111"));

    return 0;
}