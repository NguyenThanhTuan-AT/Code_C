#include <stdio.h>
void doiCho(int a[], int i, int j)
{
    int temp = a[i];
    a[i] = a[j];
    a[j] = temp;
}
void sapXepGiamDan(int b[], int n)
{
    int i, j;
    for(i=0; i<n-1; i++)
    {
        for(j=n-1; j>i; j--)
            if(b[j] > b[j-1]) doiCho(b, j, j-1);
    }
}
void nhapMaTran(int m, int n, int a[m][n])
{
    int i, j;
    for(i=0; i<m; i++)
        for(j=0; j<n; j++) scanf("%d", &a[i][j]);
}
void inMaTran(int dong, int cot, int a[dong][cot])
{
    int i, j;
    for(i=0; i< dong; i++)
    {
        for(j=0; j<cot; j++) printf("%4d", a[i][j]);
        printf("\n");
    }
}
void mang2ChieuVe1Chieu(int m, int n, int a[m][n], int b[])
{
    int i, j, k=0;
    for(i=0; i<m; i++)
    {
        for(j=0; j<n; j++) b[k++] = a[i][j];
    }
}
void mang1ChieuVe2Chieu(int dong, int cot, int a[dong][cot], int b[])
{
    int i, j, k=0;
    for(j=0; j< cot; j++)
    {
        if(j % 2 != 0)
        {
            for(i=0; i<dong; i++) a[i][j] = b[k++];
        }
        else
        {
            for(i=dong-1; i>=0; i--) a[i][j] = b[k++];
        }
    }
}

int main()
{
    //freopen("D:\\Code\\input.txt", "r", stdin);
    int m, n;
    scanf("%d %d", &m, &n);
    int a[m][n];
    int b[m*n];
    nhapMaTran(m, n, a);
    mang2ChieuVe1Chieu(m, n, a, b);
    sapXepGiamDan(b, m*n);
    mang1ChieuVe2Chieu(m, n, a, b);
    inMaTran(m, n, a);
    return 0;
}
