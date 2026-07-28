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

int fun1(unsigned word)
{
    return (int)((word << 24) >> 24);
}

int fun2(unsigned word)
{
    return ((int)word << 24) >> 24;
}

/*Warning: This is buggy code */
float sum_elements(float start[], unsigned length)
{
    int i = 0;
    float result = 0;

    for (i; i < length - 1; i++)
    {
        result += start[i];
    }
    return result;
}

int main()
{
    // short x = 12345;
    // short mx = -x;
    // show_bytes((byte_pointer)&x, sizeof(x));
    // show_bytes((byte_pointer)&mx, sizeof(-x));

    // short sx = -12345;
    // unsigned uy = sx;

    // printf("uy = %u: \t ", uy);
    // show_bytes((byte_pointer)&uy, sizeof(uy));

    // printf("fun1 = %x \t ", fun1(0x000000C9));
    // printf("fun2 = %x \t ", fun2(0x000000C9));

    float arr[5] = {1.0, 2.0, 3.0, 4.0, 5.0};
    printf("Sum of elements: %f\n", sum_elements(arr, 0));

    return 0;
}