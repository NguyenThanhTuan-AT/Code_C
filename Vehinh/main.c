#include <stdio.h>
#include <stdlib.h>
void hinhThoi(int count, char ch)
{
    for(int i=0; i<count; i++)
    {
        printf("%c", ch);
    }
}
void dong(int r, int c, int s)
{
    for(int i=0; i<r; i++)
    {
        for(int k=0; k<s; k++)
        {
            for(int j=0; j<c; j++)
            {
                hinhThoi(s - k - 1,'.');
                printf("/");
                hinhThoi(2 * k, '*');
                printf("\\");
                hinhThoi(s - k - 1, '.');
            }
            printf("\n");
        }
        for(int k=0; k<s; k++)
        {
            for(int j=0; j<c; j++)
            {
                hinhThoi(k, '.');
                printf("\\");
                hinhThoi(2*(s - k - 1), '*');
                printf("/");
                hinhThoi(k, '.');
            }
            printf("\n");
        }

    }
}
int main()
{
    freopen("D:\\Code\\input.txt", "r", stdin);
    int t;
    scanf("%d", &t);
    while(t--)
    {
        int r, c, s;
        scanf("%d %d %d", &r, &c, &s);
        dong(r, c, s);
        printf("\n");
    }
    return 0;
}
