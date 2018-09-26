#include <stdio.h>
#include <stdlib.h>

char *LongestCommonPrefix(char **strs, int strsSize)
{
    int end = -1;

    for (int i = 1; i < strsSize; i++)
    {
        int p = 0;
        int c = strs[i][p];

        while (c != '\0' && c == strs[i - 1][p] && (end == -1 || end > p))
        {
            p++;
            c = strs[i][p];
        }

        end = p;
    }

    char *r = malloc(sizeof(char) * end);

    for (int i = 0; i < end; i++)
    {
        r[i] = strs[0][i];
    }

    r[end] = '\0';

    return r;
}

int main()
{
    char *str[] = {"leet", "leetcode", "leeds"};
    char *s = LongestCommonPrefix(str, 3);

    printf("s: %s\n", s);

    return 0;
}