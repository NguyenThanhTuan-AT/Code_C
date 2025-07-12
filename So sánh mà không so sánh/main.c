#include <stdio.h>
#include <stdlib.h>

int main()
{
    unsigned int a, b ;
    scanf("%u %u", &a, &b);
    int x = (a-b) + abs(a-b);
    int c = x % (2*(a-b)-1);
    printf("%d", c);
    return 0;
}
