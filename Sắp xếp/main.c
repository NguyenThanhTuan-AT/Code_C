#include <stdio.h>
#define LEN_A 6
void doi_cho(int a[], int i, int j)
{
    int temp;
    temp = a[i];
    a[i] = a[j];
    a[j] = temp;
}
void sapXepChon(int a[], int len)
{
    int i, j, index_min;
    for(i=0; i<len-1; i++)
    {
        index_min = i;
        for(j = i+1; j<len; j++)
        {
            if(a[j] < a[index_min])
                index_min = j;
        }

        if(index_min != i)
            doi_cho(a, i, index_min);
    }
}
void sapXepnoibot(int a[], int len)
{
    int i, j;
    for(i=0; i<len-1; i++)
    {
        for(j=0; j<len-i-1; j++)
        {
            if(a[j]>a[j+1])
                doi_cho(a, j, j+1);
        }
    }
}
void sapXepchen(int a[ ], int len)
{
    int i, j;
    for(i =1; i<len; i++)
    {
        j=i;
        while(a[j]<a[j-1] && j>0)
        {
            doi_cho(a, j, j-1);
            j--;
        }
    }
}
void inser(int a[], int n)
{
    for(int i=1; i<n; i++) int x= a[i];
}
void sapXepdemPhanphoi(int a[], int len)

void inMang(int a[], int len)
{
    int i;
    for(i=0; i<len; i++)
        printf("%d ", a[i]);
    printf("\n");
}
int main()
{
    int a[LEN_A] = {170, 168, 172, 165, 169, 171};
    inMang(a, LEN_A);
    sapXepchen(a, LEN_A);
    inMang(a, LEN_A);
    return 0;
}
int cnt[10000001];
int main()
{
    int a[1000], n;
    scanf("%d", &n);
    int m = 0;
    for(int i=0; i<n; i++)
    {
        scanf("%d", &a[i]);
        cnt[a[i]]++;
        if(m<a[i]) m = a[i];
    }
    for(int i=0; i<m; i++)
    {
        if(cnt[i] != 0)
        {
            for(int j=0; j<cnt[i]; j++)
                printf("%d ", i);
        }
    }
    return 0;
}
/*
#include <stdio.h>
#define ROWS 55
#define COLS 55

void nhapMaTran(int a[][COLS], int dong, int cot)
{
    int i, j;
    for (i = 0; i < dong; i++)
    {
        for (j = 0; j < cot; j++) scanf("%d", &a[i][j]);
    }
}

void inMaTran(int a[][COLS], int dong, int cot)
{
    printf("int a[%d][%d] = {\n", dong, cot);
    int i, j;
    for (i = 0; i < dong; i++)
    {
        printf("\t{");
        for (j = 0; j < cot; j++)
        {
            printf("%3d", a[i][j]);
            if (j != cot - 1) printf(", ");
        }
        printf("}\n");
    }
    printf("};");
}
int main()
{
    freopen("D:\\Code\\input.txt", "r", stdin);
    int m, n;
    int a[ROWS][COLS];
    scanf("%d %d", &m, &n);
    nhapMaTran(a, m, n);
    inMaTran(a, m, n);
    return 0;
}
