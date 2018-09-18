#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int size;
    int capacity;
    int *data;
} DynamicArray;

/*
    Init: initializes the dynamic array
*/
DynamicArray *DynamicArray_Init(DynamicArray *a)
{
    int CAPACITY = 1;

    a->size = 0;
    a->capacity = CAPACITY;
    a->data = malloc(sizeof(int) * CAPACITY);

    return a;
}

/*
    Add: inserts a value to the dynamic array at a given integer
*/
int DynamicArray_Add(DynamicArray *a, int index, int value)
{
    /*
        When a value is inserted at a index greater than the capacity,
        the capacity is doubled.
    */
    if (index > a->capacity)
    {
        int CAPACITY = index * 2;
        a->data = realloc(a->data, CAPACITY);
        a->capacity = CAPACITY;
    }

    // insert the value at index
    a->data[index] = value;

    /*
        if the index is greater or equal to the previous size,
        update the size to be index + 1
    */
    if (index >= a->size)
    {
        a->size = ++index;
    }

    return a->size;
}

// Tests

void T_DynamicArray_Init()
{
    int passed = 1;

    DynamicArray a;

    DynamicArray_Init(&a);

    if (a.size != 0)
    {
        printf("Error: T_DynamicArray_Init - size should equal 0\n");
        passed = -1;
    }

    if (a.capacity != 1)
    {
        printf("Error: T_DynamicArray_Init - capacity should equal 1\n");
        passed = -1;
    }

    if (passed == 1)
    {
        printf("Passed: T_DynamicArray_Init\n");
    }
}

void T_DynamicArray_Add()
{
    int passed = 1;

    DynamicArray a;

    DynamicArray_Init(&a);
    DynamicArray_Add(&a, 2, 1);

    if (a.size != 3)
    {
        printf("Error: T_DynamicArray_Add - size should equal 3\n");
        passed = -1;
    }

    if (a.capacity != 4)
    {
        printf("Error: T_DynamicArray_Add - capacity should equal 4\n");
        passed = -1;
    }

    if (a.data[2] != 1)
    {
        printf("Error: T_DynamicArray_Add - data[2] should equal 1\n");
        passed = -1;
    }

    if (passed == 1)
    {
        printf("Passed: T_DynamicArray_Add\n");
    }
}

void Tests_Run()
{
    T_DynamicArray_Init();
    T_DynamicArray_Add();
}

int main()
{
    Tests_Run();

    return 0;
}