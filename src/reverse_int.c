#include <stdio.h>

int reverseInt(int integer)
{
    int length = 1;
    int magnitude = (integer < 0 ? integer * -1 : integer);
    int divider = 1;

    while (magnitude / divider >= 1)
    {
        length++;
        divider *= 10;
    }

    if (integer < 0)
    {
        length++;
    }

    char string[length];
    sprintf(string, "%d", integer);
    string[length - 1] = '\0';

    int prefix = (integer < 0 ? 1 : 0);

    printf("%i\n", length);
    for (int i = 0; i < (length / 2) - prefix; i++)
    {
        int firstIndex = prefix + i;
        int lastIndex = length - i - 2;
        char temp = string[firstIndex];
        string[firstIndex] = string[lastIndex];
        string[lastIndex] = temp;
    }

    printf("string: %s\n", string);

    return integer;
}

int main()
{
    printf("15: %i\n", reverseInt(15));   // 51
    printf("981: %i\n", reverseInt(981)); // 189
    printf("500: %i\n", reverseInt(500)); // 5
    printf("-15: %i\n", reverseInt(-15)); // -51
    printf("-90: %i\n", reverseInt(-90)); // -9
    return 0;
}