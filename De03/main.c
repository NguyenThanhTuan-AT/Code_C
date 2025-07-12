#include <stdio.h>
#include <stdlib.h>
void nhapDayso(int d[], int k)
{
    for(int i=0; i<k; i++)
        scanf("%d", d[i]);
}

void inDayso(int [], int k)
{
    for(int i=0; i<k; i++)
        printf("%d", c[i]);
    printf("\n");
}

void ghep2dayso(int a[], int b[], int c[], int n, int m)
{
    int i=0, j=0, k=0;
    while(i<n && j<m)
    {
        if(a[i] < b[j]) c[k++] = a[i++];
        else c[k++] = b[j++];
    }
 while(i<n) c[k++] = a[i++];
 while(j<m) c[k++] = b[j++];
}
int main()
{

}
