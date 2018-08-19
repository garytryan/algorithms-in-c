#include <stdio.h>
#include <stdlib.h>

// structs
typedef struct node
{
    int value;
    struct node *next;
} node;

typedef struct linked_list
{
    struct node *head;
} linked_list;

// node functions
struct node *node__next(struct node *node)
{
    return node->next;
}

int node__value(struct node *node)
{
    return node->value;
}

// linked_list functions
void linked_list__add(struct linked_list *ll, int v)
{
    struct node *n = malloc(sizeof(linked_list));
    n->value = v;
    n->next = NULL;

    if (ll->head != NULL)
    {
        n->next = ll->head;
    }

    ll->head = n;
}

void linked_list__print(struct linked_list *ll)
{
    struct node *n = ll->head;

    while (n != NULL)
    {
        printf("[%d] ", node__value(n));
        n = node__next(n);
    }

    printf("\n");
}

int linked_list__find_midpoint(struct linked_list *ll)
{
    struct node *p1 = ll->head;
    struct node *p2 = ll->head;

    if (p2 == NULL)
    {
        return -1;
    }

    while (p2->next != NULL)
    {
        p2 = node__next(p2);

        if (p2->next == NULL)
        {
            break;
        }
        else
        {
            p2 = node__next(p2);
            p1 = node__next(p1);
        }
    }

    return p1->value;
}

// tests
int firstTest()
{
    struct linked_list ll = {.head = NULL};

    int midpoint = linked_list__find_midpoint(&ll);

    if (midpoint == -1)
    {
        return 1;
    }

    return midpoint;
}

int secondTest()
{
    struct linked_list ll = {.head = NULL};
    linked_list__add(&ll, 1);

    int midpoint = linked_list__find_midpoint(&ll);

    if (midpoint == -1)
    {
        return 1;
    }

    return midpoint;
}

int thirdTest()
{
    struct linked_list ll = {.head = NULL};
    linked_list__add(&ll, 3);
    linked_list__add(&ll, 2);
    linked_list__add(&ll, 1);

    int midpoint = linked_list__find_midpoint(&ll);

    if (midpoint == -1)
    {
        return 1;
    }

    return midpoint;
}

int fourthTest()
{
    struct linked_list ll = {.head = NULL};
    linked_list__add(&ll, 6);
    linked_list__add(&ll, 5);
    linked_list__add(&ll, 4);
    linked_list__add(&ll, 3);
    linked_list__add(&ll, 2);
    linked_list__add(&ll, 1);

    int midpoint = linked_list__find_midpoint(&ll);

    if (midpoint == -1)
    {
        return 1;
    }

    return midpoint;
}

int main()
{
    if (firstTest() == 1)
    {
        printf("firstTest - link list of size 0: passed\n");
    }
    else
    {
        printf("firstTest: failed, expected 0, got %i\n", firstTest());
    }

    if (secondTest() == 1)
    {
        printf("secondTest - link list of size 1: passed\n");
    }
    else
    {
        printf("secondTest: failed, expected 1, got %i\n", secondTest());
    }

    if (thirdTest() == 2)
    {
        printf("thirdTest - link list of size 3: passed\n");
    }
    else
    {
        printf("thirdTest: failed, expected 2, got %i\n", thirdTest());
    }

    if (fourthTest() == 3)
    {
        printf("fourthTest - link list of size 6: passed\n");
    }
    else
    {
        printf("fourthTest: failed, expected 3, got %i\n", fourthTest());
    }

    return 0;
}