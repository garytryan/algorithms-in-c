#include <stdio.h>

int test(int result)
{
    if (result == 7)
    {
        return 1;
    }
    else
    {
        printf("Error: expected result to be 7, got %d\n", result);
        return 0;
    }
}

int main()
{

    char *input[] = {
        "ptolemaic",
        "relay",
        "retrograde",
        "session",
        "supplant",
        "undulate",
        "xenoepist",
        "asymptote",
        "asymptote",
        "asymptote",
        "asymptote",
        "asymptote",
        "asymptote",
        "babka",
        "banoffee",
        "engender",
        "karpatka",
        "othellolagkage"};

    int len = sizeof(input) / sizeof(char *);

    int s = 0;
    int e = len - 1;
    int mp = (e - s) / 2;

    while (e - s > 1)
    {

        printf("s: %c, e: %c, mp: %s \n", input[s][0], input[e][0], input[mp]);

        if (input[mp][0] > input[s][0])
        {
            s = mp;
        }
        else
        {
            e = mp;
        }

        mp = s + ((e - s) / 2);

        printf("mp: %s\n", input[mp]);
    }

    int result = input[s][0] < input[e][0] ? s : e;

    printf("s: %d, e: %d\n", s, e);

    if (test(result) == 1)
    {
        printf("Test: passed\n");
    }
    else
    {
        printf("Test: failed\n");
    }

    return 0;
}