#include <stdio.h>
#include <stdlib.h>

typedef struct LL_Node
{
    int value;
    struct LL_Node *next;
} LL_Node;

typedef struct
{
    LL_Node *HEAD;
} LL;

void LL_Insert(LL *ll, int v)
{
    LL_Node *n = malloc(sizeof(LL_Node));
    n->value = v;
    n->next = NULL;

    if (ll->HEAD != NULL)
    {
        n->next = ll->HEAD;
    }

    ll->HEAD = n;
}

void LL_Reverse(LL *ll)
{
    LL_Node *prev = NULL;
    LL_Node *cur = ll->HEAD;
    LL_Node *next = NULL;

    if (ll->HEAD != NULL)
    {
        next = ll->HEAD->next;
    }

    while (cur != NULL)
    {
        cur->next = prev;
        prev = cur;
        cur = next;

        if (next != NULL)
        {
            next = next->next;
        }
    }

    ll->HEAD = prev;
}

void LL_Print(LL *ll)
{
    LL_Node *n = ll->HEAD;

    while (n != NULL)
    {
        printf("[%i]->", n->value);
        n = n->next;
    }

    printf("\n");
}

void T_LL_Reverse()
{
    LL ll;

    LL_Insert(&ll, 6);
    LL_Insert(&ll, 4);
    LL_Insert(&ll, 2);
    LL_Print(&ll);
    LL_Reverse(&ll);
    LL_Print(&ll);
}

/*
    [1] -> [2] -> [3]

    init
    prev = NULL
    cur = [1]
    next = [2]

    while cur
        cur.next = prev
        prev = cur
        cur = next
        next = cur.next

    --
    [1] -> NULL [2] -> [3]
    prev = [1]
    cur = [2]
    next = [3]
    --
    [2] -> [1] -> NULL [3]
    prev = [2]
    cur = [3]
    next = NULL
    --
    [3] -> [2] -> [1] -> NULL
    prev = [3]
    cur = NULL
    next = NULL
*/

int main()
{
    T_LL_Reverse();
    return 0;
}