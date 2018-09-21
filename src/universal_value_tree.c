#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int value;
    struct Node *left;
    struct Node *right;
} Node;

void InitNode(Node *n, int value)
{
    n->value = value;
    n->left = NULL;
    n->right = NULL;
}

void GenerateTree(Node *root, int left, int right)
{
    Node *l = malloc(sizeof(Node));
    Node *r = malloc(sizeof(Node));

    InitNode(l, left);
    InitNode(r, right);

    root->left = l;
    root->right = r;
}

int countUnival(Node *root, int *count)
{
    int isUnival = 1;

    if (root->left == NULL && root->right == NULL)
    {
        *count = *count + 1;
        return 1;
    }

    if (root->left != NULL && root->left->value != root->value)
    {
        isUnival = 0;
    }
    else if (root->right != NULL && root->right->value != root->value)
    {
        isUnival = 0;
    }

    if (root->left != NULL && countUnival(root->left, count) == 0)
    {
        isUnival = 0;
    }

    if (root->right != NULL && countUnival(root->right, count) == 0)
    {
        isUnival = 0;
    }

    if (isUnival)
    {
        *count = *count + 1;
    }

    return isUnival;
}

void testCountUnival()
{
    Node n;
    InitNode(&n, 0);
    GenerateTree(&n, 1, 0);
    GenerateTree(n.left, 1, 0);
    GenerateTree(n.right, 1, 0);
    GenerateTree(n.left->left, 1, 0);

    int c = 0;
    countUnival(&n, &c);

    if (c != 5)
    {
        printf("Failed: expected 5, got %i\n", c);
    }
    else
    {
        printf("passed!\n");
    }
}

int main()
{
    testCountUnival();
    return 0;
}