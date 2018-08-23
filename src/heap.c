#include <stdio.h>

const int HEAP_SIZE = 10;

typedef struct
{
    int nodes[HEAP_SIZE + 1];
    int size;
} Heap;

int Heap_Parent(int n)
{
    if (n == 1)
    {
        return -1;
    }

    return n / 2;
}

// left child
int Heap_LChild(int n)
{
    int pos = n * 2;

    if (pos > HEAP_SIZE)
    {
        return -1;
    }
    else
    {
        return n * 2;
    }
}

// right child
int Heap_RChild(int n)
{
    int pos = n * 2 + 1;

    if (pos > HEAP_SIZE)
    {
        return -1;
    }
    else
    {
        return pos;
    }
}

int Heap_Add(Heap *h, int v)
{
    int parent = 1;

    if (h->size >= HEAP_SIZE)
    {
        return -1;
    }

    if (h->size == 0)
    {
        h->nodes[parent] = v;
        h->size++;
        return parent;
    }

    while (h->nodes[parent] != 0 && parent != -1)
    {

        if (h->nodes[parent] > v)
        {
            parent = Heap_LChild(parent);
        }
        else
        {
            parent = Heap_RChild(parent);
        }
    }

    if (parent == -1)
    {
        return -1;
    }
    else
    {
        h->nodes[parent] = v;
        h->size++;
        return parent;
    }
}

void Heap_Init(Heap *h)
{
    h->size = 0;

    for (int i = 0; i < HEAP_SIZE; i++)
    {
        h->nodes[i] = 0;
    }
}

void Heap_Print(Heap *h)
{
    for (int i = 0; i < HEAP_SIZE; i++)
    {
        printf("[%i]: %i\n", i, h->nodes[i]);
    }
}

int Heap_Find(Heap *h, int v)
{
    if (h->nodes[1] == v)
    {
        return 1;
    }

    int i = 1;

    while (h->nodes[i] != v)
    {
        if (h->nodes[i] > v)
        {
            i = Heap_LChild(i);
        }
        else
        {
            i = Heap_RChild(i);
        }

        if (i > h->size || i <= 0)
        {
            return -1;
        }
    }

    return i;
}

int T_Heap_Add()
{
    int passed = 1;
    Heap h;
    Heap_Init(&h);

    Heap_Add(&h, 10);
    Heap_Add(&h, 5);
    Heap_Add(&h, 15);
    Heap_Add(&h, 3);
    Heap_Add(&h, 8);
    Heap_Add(&h, 13);
    Heap_Add(&h, 18);

    int expected[] = {0,
                      10,
                      5,
                      15,
                      3,
                      8,
                      13,
                      18};

    int l = sizeof(expected) / sizeof(int);

    for (int i = 0; i < l; i++)
    {
        if (h.nodes[i] != expected[i])
        {
            passed = -1;
            break;
        }
    }

    return passed;
}

int T_Heap_Find()
{
    Heap h;
    Heap_Init(&h);

    Heap_Add(&h, 10);
    Heap_Add(&h, 5);
    Heap_Add(&h, 15);
    Heap_Add(&h, 3);
    Heap_Add(&h, 8);
    Heap_Add(&h, 13);
    Heap_Add(&h, 18);

    int values[] = {10, 5, 15, 3, 8, 13, 18};
    int results[] = {1, 2, 3, 4, 5, 6, 7};

    for (int i = 0; i < 7; i++)
    {
        int v = values[i];
        int r = results[i];

        int result = Heap_Find(&h, values[i]);

        if (result != r)
        {
            printf("T_Heap_Find(%i): expected %i, got %i", v, r, result);
            return -1;
        }
    }

    return 1;
}

int main()
{
    if (T_Heap_Add() == -1)
    {
        printf("T_Heap_Add: failed\n");
    }
    else
    {
        printf("T_Heap_Add: passed\n");
    }

    if (T_Heap_Find() == -1)
    {
        printf("T_Heap_Find: failed\n");
    }
    else
    {
        printf("T_Heap_Find: passed\n");
    }
    return 0;
}