#include <stdio.h>
#include <stdlib.h>

int main()
{
    unsigned int x;
    scanf("%x", &x);
    int a = (x & 0x000000ff) << 24;
    int b = (x & 0x0000ff00) << 8;
    int c = (x & 0x00ff0000) >> 8;
    int d = (x & 0xff000000) >> 24;
    int h = a + b + c + d;
    printf("0x%08x ~ %10u\n", x, x);
    printf("0x%08x ~ %10u", h, h);
    return 0;
}
