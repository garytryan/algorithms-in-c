#include <stdio.h>

int main()
{
    char string[] = "abcdefg";
    int length = sizeof(string) / sizeof(char);

    int lastIndex = length - 2;
    int middelIndex = length / 2;

    for (int i = 0; i < middelIndex; i++)
    {
        char temp = string[i];
        string[i] = string[lastIndex - i];
        string[lastIndex - i] = temp;
    }

    printf("string: %s\n", string);
    return 0;
}