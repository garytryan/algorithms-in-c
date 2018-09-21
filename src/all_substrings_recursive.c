#include <stdio.h>

/*

*/

void PrintAllSubstrings(char *string, int length, int start, int end)
{

    if (start >= length && end >= length)
    {
        return;
    }

    for (int i = start; i < end; i++)
    {
        printf("%c", string[i]);
    }
    printf(",\n");

    if (end == length)
    {
        PrintAllSubstrings(string, length, start + 1, start + 2);
    }
    else
    {
        PrintAllSubstrings(string, length, start, end + 1);
    }
}

int main()
{
    char s[] = "abcd";
    PrintAllSubstrings(s, 4, 0, 1);
    return 0;
}