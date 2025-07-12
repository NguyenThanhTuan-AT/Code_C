#include <stdio.h>
#include <stdlib.h>
int main()
{
    //freopen("D:\\Code\\input.txt","r", stdin);
    unsigned int a, b;
    int r;
    scanf("%u %u", &a, &b);
    while(b != 0)
    {
        r = b;
        b = a % b;
        a = r;
    }
    printf("%u\n", a);
    return 0;
}
