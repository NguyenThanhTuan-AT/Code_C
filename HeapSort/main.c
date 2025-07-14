#include <stdio.h>
#include <stdlib.h>

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

//Đệ quy
void Heapify(int k[], int root, int n)
{
    int left = root * 2 + 1;
    int right = root * 2 + 2;
    int largest = root;
    if(left<n && k[largest] < k[left]) largest = left;
    if(right<n && k[largest] < k[right]) largest = right;
    if(root != largest)
    {
        swap(&k[root], &k[largest]);
        Heapify(k, largest, n);
    }
}

//Khử đệ quy
void ADJUST(int k[], int root, int n)
{
    int key = k[root];
    while(root * 2 + 1 < n)
    {
        int c = root * 2 + 1;
        if(c + 1 < n && k[c] < k[c+1]) c++;
        if(k[c] < key) break;
        k[root] = k[c];
        root = c;
    }
    k[root] = key;
}

void Heap_Sort(int k[], int n)
{
    for(int i = n/2 - 1; i>=0; i--) Heapify(k, i, n);
    for(int i = n-1; i>=0; i--)
    {
        swap(&k[0], &k[i]);
        Heapify(k, 0, i);
    }

}
int main()
{
    int n;
    printf("Nhap sl phan tu: ");
    scanf("%d", &n);
    int k[n];
    printf("Nhap phan tu: ");
    for(int i = 0; i<n; i++) scanf("%d", &k[i]);
    Heap_Sort(k, n);
    for(int i = 0; i<n; i++) printf("%d ", k[i]);
    return 0;
}
