#include <stdio.h>
#include <math.h>

int main()
{
    unsigned int b, n, a;
    scanf("%u %u", &b, &n);
    a = 0xFFFFFFFF;
    a = (~((a & (1 << n)) ^ (b << n)));
    printf("%x\n", a);
    return 0;
}
