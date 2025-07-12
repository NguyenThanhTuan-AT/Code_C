#include <stdio.h>
#include <stdint.h>
uint32_t rotate_right(uint32_t x, int n)
{
    return (x >> n) | (x << (32 - n));
}
uint32_t rotate_left(uint32_t x, int n)
{
    return (x << n) | (x >> (32 - n));
}
int main()
{
    uint32_t x;
    unsigned int n;
    scanf("%u %u", &x, &n);
    printf("x = %u = 0x%08x\n", x, x);
    printf("x >> %u = %u = 0x%08x\n", n, rotate_right(x, n), rotate_right(x, n));
    printf("x << %u = %u = 0x%08x\n", n, rotate_left(x, n), rotate_left(x, n));
    return 0;
}
