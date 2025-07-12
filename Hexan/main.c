#include <stdio.h>
#include <stdlib.h>

int main()
{
    freopen("D:\\Code\\input.txt", "r", stdin);
    int n;
    int i;
    unsigned int x;
    scanf("%d", &n);
    for (i = 0; i < n; i++)
    {
        scanf("%u", &x);
        printf("%10u = ", x);
        for (int j = 31; j >= 0; j--)
        {
            printf("%d", (x >> j) & 1);
        }
        printf("\n");
    }

    return 0;
}
