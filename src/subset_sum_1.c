#include <stdio.h>

int SubsetSum(int *set, int i, int sum)
{
    if (sum == 0)
    {
        return 1;
    }
    else if (sum < 0)
    {
        return 0;
    }
    else if (i < 0)
    {
        return 0;
    }
    else if (sum < set[i])
    {
        return SubsetSum(set, i - 1, sum);
    }

    else
    {
        return SubsetSum(set, i - 1, sum - set[i]) + SubsetSum(set, i - 1, sum);
    }
}

void T_SubsetSum()
{
    int set[] = {1, 2, 3};

    if (SubsetSum(set, 2, 3) != 2)
    {
        printf("Failed: SubsetSum(set, 2, 3) - expected 2, got %i\n", SubsetSum(set, 2, 3));
    };
}

int main()
{
    T_SubsetSum();
    return 0;
}
