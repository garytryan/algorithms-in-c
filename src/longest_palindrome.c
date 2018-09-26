#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
Given a string s, find the longest palindromic substring in s. You may assume that the maximum length of s is 1000.

Input: "babad"
Output: "bab"
Note: "aba" is also a valid answer.

abac
caba
*/

char *LongestPalindrome(char *s)
{
    int longest = 0;
    int start = 0;
    int end = 0;
    int d = 0;

    int len = strlen(s);

    // Expand around an element in the array
    for (int i = 0; i < len; i++)
    {
        while ((i - d > 0 && i + d < len) && (s[i - (d + 1)] == s[i + d + 1]))
        {
            d++;
        }

        if (d * 2 + 1 > longest)
        {
            longest = d * 2 + 1;
            start = i - d;
            end = i + d + 1;
        }

        d = 0;
    }

    // expand arround a pair of matching elements in the array
    for (int i = 0; i < len - 1; i++)
    {
        while ((i - d > 0 && i + d < len) && s[i] == s[i + 1] && s[i - (d + 1)] == s[i + 2 + d])
        {
            d++;
        }

        if (s[i] == s[i + 1] && d * 2 + 2 > longest)
        {
            longest = d * 2 + 2;
            start = i - d;
            end = i + 2 + d;
        }

        d = 0;
    }

    char *string = malloc((sizeof(char) * end - start) + 1);

    for (int i = 0; i < end - start; i++)
    {
        string[i] = s[start + i];
    }

    string[(sizeof(char) * end - start) + 1] = '\0';

    return string;
}

void Test(result, expected)
{
    if (result != expected)
    {
        printf("Failed, expected %i, got %i\n", expected, result);
    }
}

int main()
{
    char s1[] = "babad";
    // Test(LongestPalindrome(s1, 5), 5);

    // char s2[] = "abaaba";
    // Test(LongestPalindrome(s2, 6), 6);

    // char s3[] = "abacc";
    // Test(LongestPalindrome(s3, 5), 3);

    char *s = LongestPalindrome(s1);

    printf("%s\n", s);

    return 0;
}