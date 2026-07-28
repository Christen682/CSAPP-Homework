#include <stdio.h>
#include <stdlib.h>

typedef unsigned char *byte_pointer;

void show_bytes(byte_pointer start, size_t len)
{
    size_t i;
    for (i = 0; i < len; i++)
    {
        printf("%.2x ", start[i]);
    }
    printf("\n");
}

int main()
{
    // short x = 12345;
    // short mx = -x;
    // show_bytes((byte_pointer)&x, sizeof(x));
    // show_bytes((byte_pointer)&mx, sizeof(-x));

    short sx = -12345;
    unsigned uy = sx;

    printf("uy = %u: \t ", uy);
    show_bytes((byte_pointer)&uy, sizeof(uy));

    return 0;
}