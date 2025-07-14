#include <stdio.h>
#include <stdlib.h>
void doi_cho(int a[], int i, int j)
{
    int temp = a[i];
    a[i] = a[j];
    a[j] = temp;
}

int Partition(int a[], int t, int p)
{
    int chot = a[t];
    int i = t+1;
    int j = p;
    do
    {
        while(i<=j && a[i]<= a[t]) i++;
        while(i<=j && a[j]> a[t]) j--;
        if(i< j)
        {
            doi_cho(a, i, j);
            i++;
            j--;
        }
    }
    while(i<=j);
    doi_cho(a, j, t);
    return j;
}

void Quick_sort(int a[], int t, int p)
{
    if (t < p)
    {

        int j = Partition(a, t, p);
        Quick_sort(a, t, j - 1);
        Quick_sort(a, j + 1, p);
    }
}
int main()
{
    int n;
    printf("Nhap sl phan tu: ");
    scanf("%d", &n);
    int a[n];
    printf("Nhap phan tu: ");
    for(int i = 0; i<n; i++) scanf("%d", &a[i]);
    Quick_sort(a, 0, n-1);
    for(int i = 0; i<n; i++) printf("%d ", a[i]);
    return 0;
}
