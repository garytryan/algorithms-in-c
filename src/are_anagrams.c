#include <stdio.h>

void count_chars(char *string, int string_length, int *histogram)
{
    for (int i = 0; i < string_length; i++)
    {
        int character_code = string[i];

        if (character_code >= 65 && character_code <= 90)
        {
            character_code += 32;
        }

        if (character_code >= 97 && character_code <= 122)
        {
            character_code -= 97;
            histogram[character_code] = histogram[character_code] + 1;
        }
    }
}

int main()
{
    // true
    // char stringA[] = "rail saftey";
    // char stringB[] = "fairy tales";

    // true
    // char stringA[] = "RAIL SAFTEY";
    // char stringB[] = "fairy tales";

    // false
    char stringA[] = "Hi there";
    char stringB[] = "Bye there";

    int stringALength = sizeof(stringA) / sizeof(char);
    int stringBLength = sizeof(stringB) / sizeof(char);

    int stringAHistogram[25] = {0};
    int stringBHistogram[25] = {0};

    count_chars(stringA, stringALength, stringAHistogram);
    count_chars(stringB, stringBLength, stringBHistogram);

    int isAnagram = 1;

    int i = 0;
    while (isAnagram == 1 && i < 25)
    {
        if (stringAHistogram[i] != stringBHistogram[i])
        {
            isAnagram = 0;
        }

        i++;
    }

    printf("isAnagram: %i\n", isAnagram);

    return 0;
}