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

int MinHeap_RightChild(MinHeap *h, int i)
{
    int index = (i + 1) * 2;

    if (index > HEAP_CAPACITY)
    {
        return -1;
    }

    return index;
}

int MinHeap_LeftChild(MinHeap *h, int i)
{
    int index = ((i + 1) * 2) - 1;

    if (index > HEAP_CAPACITY)
    {
        return -1;
    }

    return index;
}

void MinHeap_Bubble_Down(MinHeap *h, int i)
{
    int min = h->nodes[i];

    int rc = MinHeap_RightChild(h, i);
    int lc = MinHeap_LeftChild(h, i);

    int minIndex = i;

    if (lc <= h->size && h->nodes[lc] < min)
    {
        min = h->nodes[lc];
        minIndex = lc;
    }
    else if (rc <= h->size && h->nodes[rc] < min)
    {
        min = h->nodes[rc];
        minIndex = rc;
    }

    if (minIndex != i)
    {
        MinHeap_Swap(h, i, minIndex);
        MinHeap_Bubble_Down(h, minIndex);
    }
}

int MinHeap_Delete_Min(MinHeap *h)
{
    if (h->size <= 0)
    {
        printf("Warning: MinHeap is empty");
        return -1;
    }
    else
    {
        MinHeap_Swap(h, 0, h->size - 1);
        h->size--;

        MinHeap_Bubble_Down(h, 0);
    }

    return -1;
}

void MinHeap_Init(MinHeap *h)
{
    h->size = 0;
}

// TESTS

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

void T_MinHeap_Delete_Min()
{
}

void T_MinHeap_Bubble_Down()
{
    MinHeap h;
    MinHeap_Init(&h);

    MinHeap_Insert(&h, 1);
    MinHeap_Insert(&h, 2);
    MinHeap_Insert(&h, 3);
    MinHeap_Insert(&h, 4);

    int min_node = h.nodes[0];
    h.nodes[0] = h.nodes[3];
    h.nodes[3] = min_node;
    h.size--;

    MinHeap_Bubble_Down(&h, 0);

    if (h.nodes[0] != 2)
    {
        printf("T_MinHeap_Bubble_Down(0): expected h.nodes[0] to be 2. got=%i\n", h.nodes[0]);
    }
    else if (h.nodes[3] != 4)
    {
        printf("T_MinHeap_Bubble_Down(0): expected h.nodes[3] to be 4. got=%i\n", h.nodes[3]);
    }
    else
    {
        printf("T_MinHeap_Bubble_Down: passed\n");
    }
}

void T_MinHeap_Left_Child()
{
    MinHeap h;
    MinHeap_Init(&h);

    if (MinHeap_LeftChild(&h, 0) != 1)
    {
        printf("T_MinHeap_Left_Child(0): expected h.nodes[0] to be 1. got=%i\n", h.nodes[0]);
    }
    else if (MinHeap_LeftChild(&h, 1) != 3)
    {
        printf("T_MinHeap_Left_Child(1): expected h.nodes[1] to be 3. got=%i\n", h.nodes[0]);
    }
    else
    {
        printf("T_MinHeap_Left_Child: passed\n");
    }
}

void T_MinHeap_Right_Child()
{
    MinHeap h;
    MinHeap_Init(&h);

    if (MinHeap_RightChild(&h, 0) != 2)
    {
        printf("T_MinHeap_Left_Child(0): expected h.nodes[0] to be 2. got=%i\n", h.nodes[0]);
    }
    else if (MinHeap_RightChild(&h, 1) != 4)
    {
        printf("T_MinHeap_Left_Child(1): expected h.nodes[1] to be 4. got=%i\n", h.nodes[0]);
    }
    else
    {
        printf("T_MinHeap_Right_Child: passed\n");
    }
}
int main()
{
    T_MinHeap_Insert();
    T_MinHeap_Left_Child();
    T_MinHeap_Right_Child();
    T_MinHeap_Bubble_Down();

    return 0;
}
