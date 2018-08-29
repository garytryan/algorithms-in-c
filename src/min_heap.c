#include <stdio.h>

const int HEAP_CAPACITY = 8;

typedef struct
{
    int nodes[HEAP_CAPACITY];
    int size;
} MinHeap;

int MinHeap_Parent(int i)
{
    if (i == 0)
    {
        return -1;
    }
    else
    {
        return (i - 1) / 2;
    }
}

void MinHeap_Swap(MinHeap *h, int a, int b)
{
    int t = h->nodes[a];

    h->nodes[a] = h->nodes[b];
    h->nodes[b] = t;
}

int MinHeap_Insert(MinHeap *h, int v)
{
    h->nodes[h->size] = v;

    int parentIndex = MinHeap_Parent(h->size);
    int parentValue = h->nodes[parentIndex];

    while (parentValue > v)
    {
        MinHeap_Swap(h, h->size, parentIndex);

        parentIndex = MinHeap_Parent(h->size);
        parentValue = h->nodes[MinHeap_Parent(h->size)];
    }

    h->size++;
    return 1;
}

void MinHeap_Init(MinHeap *h)
{
    h->size = 0;
}

void T_MinHeap_Insert()
{
    int passed = 1;

    MinHeap h;
    MinHeap_Init(&h);

    MinHeap_Insert(&h, 6);

    if (h.nodes[0] != 6)
    {
        printf("T_MinHeap_Insert(6): expected to be inserted at positing 0\n");
        passed = 0;
    }

    MinHeap_Insert(&h, 5);
    if (h.nodes[0] != 5)
    {
        printf("T_MinHeap_Insert(5): expected to be inserted at positing 0\n");
        passed = 0;
    }

    if (h.nodes[1] != 6)
    {
        printf("T_MinHeap_Insert(6): expected to be inserted at positing 1\n");
        passed = 0;
    }

    MinHeap_Insert(&h, 4);
    if (h.nodes[0] != 4)
    {
        printf("T_MinHeap_Insert(4): expected to be inserted at positing 0\n");
    }

    if (h.nodes[1] != 6)
    {
        printf("T_MinHeap_Insert(6): expected to be inserted at positing 1\n");
    }

    if (h.nodes[2] != 5)
    {
        printf("T_MinHeap_Insert(5): expected to be inserted at positing 2\n");
    }

    if (passed == 0)
    {
        printf("T_MinHeap_Insert: failed\n");
    }
    else
    {
        printf("T_MinHeap_Insert: passed\n");
    }
}

int main()
{
    T_MinHeap_Insert();

    return 0;
}