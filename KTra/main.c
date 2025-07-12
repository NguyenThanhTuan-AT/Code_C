
#include <stdio.h>
#include <stdlib.h>
typedef struct
{
    char hoten[50];
    int sogiolam;
    int luongtong;
} nv;
nv arr[100];
int cnt=0;
void nhap(nv *a)
{
    getchar();
    printf("nhap ten: ");
    gets(a->hoten);
    printf("nhap gio lam: ");
    scanf("%d",&a->sogiolam);
    printf("nhap luong tong: ");
    scanf("%d",&a->luongtong);
    cnt++;
    arr[cnt]=*a;
}
void in()
{
    for(int i=1; i<=cnt; i++)
        printf("%5s % 6.d % 9.d\n",arr[i].hoten,arr[i].sogiolam,arr[i].luongtong);
}
void swap(nv* a, nv* b)
{
    nv temp = *a;
    *a = *b;
    *b = temp;
}
void sx1()
{
    for(int i=1; i<cnt; i++)
    {
        double mini=arr[i].luongtong*1.0/arr[i].sogiolam;
        for(int j=i+1; j<=cnt; j++)
        {
            double minj=arr[j].luongtong*1.0/arr[j].sogiolam;
            if(mini<minj) swap(&arr[i],&arr[j]);
        }
    }
}
void in2()
{
    for(int i=1; i<=cnt; i++)
        printf("%s %.2lf\n",arr[i].hoten,arr[i].luongtong*1.0/arr[i].sogiolam);
}
void findmax()
{
    int luongmax=0,giomax=0,posluong,posgio;
    for(int i=1; i<=cnt; i++)
    {
        if(arr[i].luongtong>luongmax)
        {
            luongmax=arr[i].luongtong;
            posluong=i;
        }
        if(arr[i].sogiolam>giomax)
        {
            giomax=arr[i].sogiolam;
            posgio=i;
        }
    }
    printf("maxluong\n");
    printf("%5s % 6.d % 9.d\n",arr[posluong].hoten,arr[posluong].sogiolam,arr[posluong].luongtong);
    printf("maxgio\n");
    printf("%5s % 6.d % 9.d\n",arr[posgio].hoten,arr[posgio].sogiolam,arr[posgio].luongtong);
}
void firstout()
{
    printf("MENU\n");
    printf("1.Tao danh sach nhan vien\n");
    printf("2.Hien thi danh sach nhan vien\n");
    printf("3.In nhan vien luong cao  nhat va gio lam nhieu nhat\n");
    printf("4.Ket thuc\n");
    printf("Nhap chuc nang: ");
}
int main()
{
    while(1)
    {
        firstout();
        int n;
        scanf("%d",&n);
        nv a;
        switch(n)
        {
        case 1:
            nhap(&a);
            break;
        case 2:
            sx1();
            in2();
            break;
        case 3:
            findmax();
            break;
        case 4:
            return 0;
        }
    }
    return 0;
}
