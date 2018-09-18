#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int leftX;
    int bottomY;
    int width;
    int height;
} Rectangle;

// SCAN X-AXIS
// [(a, 1), (b, 5), (a, 7), (b, 8)]

Rectangle *intersection(Rectangle *a, Rectangle *b)
{
    Rectangle *i = malloc(sizeof(Rectangle));

    if (a->leftX < b->leftX)
    {
        i->leftX = b->leftX;
        i->width = b->leftX + b->width;

        if (a->leftX + a->width < i->width)
        {
            i->width -= (a->leftX + a->width) - i->width;
        }
    }
    else
    {
    }

    return i;
}

int main()
{

    return 0;
}