#include <stdio.h>
void doiCho(int a[], int i, int j)
{
    int temp = a[i];
    a[i] = a[j];
    a[j] = temp;
}
void nhapMaTran(int m, int n, int a[m][n])
{
    int i, j;
    for(i=0; i<m; i++)
        for(j=0; j<n; j++) scanf("%d", &a[i][j]);
}
void inMaTra(int m, int n, int a[m][n])
{
    int i, j;
    for(i=0; i<m; i++)
    {
        for(j=0; j<n; j++) printf("%5d", a[i][j]);
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
void sapXepGiamDan(int b[], int n)
{
    int i, j;
    for(i=0; i< n-1; i++)
    {
        for(j=0; j< n-1-i; j++)
            if(b[j] > b[j+1]) doiCho(b, j, j+1);
    }
}
void mang1ChieuVe2Chieu(int dong, int cot, int a[dong][cot], int b[])
{
    int i, j, k=0;
    int vong=0;
    while(k < dong * cot)
    {
        for(i=dong-1-vong; i>= vong; i--)
            if(k < dong * cot) a[i][cot-1-vong] = b[k++];
        for(j=cot-2-vong; j>=vong; j--)
            if(k < dong * cot) a[vong][j] = b[k++];
        for(i=1; i<dong-vong; i++)
            if(k < dong * cot) a[i][vong] = b[k++];
        for(j=1; j<cot-1-vong; j++)
            if(k < dong * cot) a[dong-1-vong][j] = b[k++];
        vong++;
    }
}
int main()
{
    freopen("D:\\Code\\input.txt", "r", stdin);
    int m, n;
    scanf("%d %d", &m, &n);
    int b[m*n];
    int a[m][n];
    nhapMaTran(m, n, a);
    mang2ChieuVe1Chieu(m, n, a, b);
    sapXepGiamDan(b, m*n);
    mang1ChieuVe2Chieu(m, n, a, b);
    inMaTra(m, n, a);
    return 0;
}
