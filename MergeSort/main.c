#include <stdio.h>
#include <stdlib.h>

void MERGE(int k[], int x[], int b, int m, int n)
{
    int t = b, i = b;
    int j = m + 1;
    while(i<=m && j<=n)
    {
        if(k[i] <= k[j]) x[t++] = k[i++];
        else x[t++] = k[j++];
    }
    while(i<=m) x[t++] = k[i++];
    while(j<=n) x[t++] = k[j++];
}

void MPASS(int k[], int x[], int n, int h)
{
    int i = 0;
    while(i + 2 * h < n )
    {
        MERGE(k, x, i, i+h-1, i+2*h-1);
        i += 2*h;
    }
    if(i + h < n) MERGE(k, x, i, i+h-1, n-1);
    else for(; i<n; i++) x[i] = k[i];
}

int STRAGHT_MSORT(int k[], int x[], int n)
{
    int h = 1;
    int pass_count = 0;
    while(h<n)
    {
        MPASS(k, x, n, h);
        pass_count++;
        h = 2 * h;
        if(h>=n) break;
        MPASS(x, k, n, h);
        pass_count++;
        h = h * 2;
    }
    return pass_count;
}

int main()
{
    int n;
    printf("Nhap sl phan tu: ");
    scanf("%d", &n);
    int k[n], x[n];
    printf("Nhap phan tu: ");
    for(int i = 0 ; i<n; i++) scanf("%d", &k[i]);
    if(STRAGHT_MSORT(k, x, n) % 2 == 0)
        for(int i = 0 ; i<n; i++) printf("%d ", k[i]);
    else for(int i = 0 ; i<n; i++) printf("%d ", x[i]);
    return 0;
}
