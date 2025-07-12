#include<stdio.h>
#include<stdlib.h>
#define MAX_SIZE 100

void nhapMatran(int m[][MAX_SIZE], int dong, int cot)
{
    for(int i = 0; i<dong; i++)
    {
        for(int j = 0; j<cot; i++)
        {
            printf("Nhap m[%d][%d] ", i, j);
            scanf("%d", &m[i][j]);
        }
    }
}

void congMatran(int a[][MAX_SIZE], int b[][MAX_SIZE], int c[][MAX_SIZE], int dong, int cot)
{
    for(int i = 0; i<dong; i++)
    {
        for(int j = 0; j<cot; i++)
        {
            c[i][j] = a[i][j] + b[i][j];
        }
    }
}

void ghiMatran(FILE *f, const char *tieude, int m[][MAX_SIZE], int dong, int cot)
{
    fprintf(f, "\n%s\n", tieude);

}

void menu()
{
    printf("\tMENU\n");
    printf("0. Nhap ma tran\n");
    printf("1. Doc tep ma trann A, B tu tep\n");
    printf("2. Tinh ma tran C roi ghi bo sung vao cuoi tep\n");
    printf("3. Ket thuc\n");
    printf("Nhap lua chon: ");
}

int main()
{
    int a[MAX_SIZE][MAX_SIZE];
    int b[MAX_SIZE][MAX_SIZE];
    int c[MAX_SIZE][MAX_SIZE];
    int dong, cot;
    int chon;
    while(1)
    {
        switch(chon)
        {
        case 1:

        }
    }
}
