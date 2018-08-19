#include <stdio.h>

void printMatrix(int ROW, int COL, int *matrix)
{
    for (int i = 0; i < ROW; i++)
    {
        for (int j = 0; j < COL; j++)
        {
            printf("[%d] ", *(matrix + i * COL + j));
        }

        printf("\n");
    }
}

int test(int ROW, int COL, int *input)
{
    int passed = 1;

    int result[][3] = {{1, 2, 3}, {8, 9, 4}, {7, 6, 5}};

    for (int i = 0; i < ROW; i++)
    {
        for (int j = 0; j < COL; j++)
        {
            int resultVal = result[i][j];
            int inputVal = *(input + i * COL + j);

            if (inputVal != resultVal)
            {
                printf("Error: expected [%d][%d] to equal %d, got %d\n", i, j, resultVal, inputVal);
                passed = 0;

                break;
            }
        }

        if (passed == 0)
        {
            break;
        }
    }

    return passed;
}

int main()
{
    int ROW = 3;
    int COL = 3;

    int input[][3] = {{0, 0, 0}, {0, 0, 0}, {0, 0, 0}};

    int rs = 0;        // row start
    int re = ROW;      // rew end
    int cs = 0;        // column start
    int ce = COL;      // column end
    int c = 1;         // count
    int e = ROW * COL; // end

    // loop around the most outter ring of the matrix until it is filled
    while (c <= e)
    {

        // fill the the top row
        // [1] [2] [3]
        // [0] [0] [0]
        // [0] [0] [0]
        int i = cs;
        while (i < ce && c <= e)
        {
            input[rs][i] = c;
            c++;
            i++;
        }
        rs++;

        // fill the right column
        // [1] [2] [3]
        // [0] [0] [4]
        // [0] [0] [5]
        i = rs;
        while (i < re && c <= e)
        {
            input[i][ce - 1] = c;
            c++;
            i++;
        }
        ce--;

        // fill the bottom row
        // [1] [2] [3]
        // [0] [0] [4]
        // [7] [6] [5]
        i = ce - 1;
        while (i >= cs && c <= e)
        {
            input[re - 1][i] = c;
            c++;
            i--;
        }
        re--;

        // fill the left row
        // [1] [2] [3]
        // [8] [0] [4]
        // [7] [6] [5]
        i = re - 1;
        while (i >= rs && c <= e)
        {
            input[i][cs] = c;
            c++;
            i--;
        }
        cs++;
    }

    printMatrix(ROW, COL, &input[0][0]);

    if (test(ROW, COL, &input[0][0]) == 1)
    {
        printf("Test: passed\n");
    }
    else
    {
        printf("Test: failed\n");
    }

    return 0;
}