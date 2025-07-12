#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct
{
    char maSV[10];
    char hoTen[25];
    int namSinh;
} sinhVien;

void writeFile()
{
    FILE *f = fopen("DS_SV.C", "wb");
    if(f == NULL)
    {
        printf("Khong the mo file de ghi!\n");
        return;
    }
    sinhVien sv;
    int n;
    printf("Nhap so luong sinh vien: ");
    scanf("%d", &n);
    getchar();
    for(int i = 1; i<=n; i++)
    {
        printf("Thong tin sinh vien thu %d\n", i);
        printf("Ma SV: ");
        gets(sv.maSV);
        printf("Ho ten: ");
        gets(sv.hoTen);
        printf("Nam sinh: ");
        scanf("%d", &sv.namSinh);
        getchar();

        fwrite(&sv, sizeof(sinhVien), 1, f);
    }
    fclose(f);
}

void readFile()
{
    FILE *f = fopen("DS_SV.C", "rb");
    if(f == NULL)
    {
        printf("Khong the mo file de doc!\n");
        return ;
    }
    sinhVien sv;
    int i = 1;
    printf("\tDANH SACH SINH VIEN\n");
    printf(" %3s %-10s %-25s %s\n", "STT", "MaSV", "Ho ten", "NamSinh");
    printf("----------------------------------------------------\n");
    while(fread(&sv, sizeof(sinhVien), 1, f))
    {
        printf(" %3d %-10s %-25s %4d\n", i++, sv.maSV, sv.hoTen, sv.namSinh);
    }
    fclose(f);
}

void suaThongtin()
{
    FILE *f = fopen("DS_SV.C", "rb");
    if(f == NULL)
    {
        printf("Khong the mo file1\n");
        return;
    }
    sinhVien ds[100];
    int n = 0;
    while(fread(&ds[n], sizeof(sinhVien), 1, f))
    {
        n++;
    }
    fclose(f);
    char maSVcanSua[10];
    printf("Nhap ma sv can sua: ");
    fflush(stdin);
    gets(maSVcanSua);
    for(int i = 0; i<n; i++)
    {
        if(strcmp(ds[i].maSV, maSVcanSua)==0)
        {
            printf("Thong tin ban dau\n");
            printf("Ma sv: %s\n", ds[i].maSV);
            printf("Ho ten: %s\n", ds[i].hoTen);
            printf("Nam sin: %d\n", ds[i].namSinh);

            printf("Nhap thon tin moi\n");
            printf("Ho ten moi: ");
            gets(ds[i].hoTen);
            printf("Nam sinh moi: ");
            scanf("%d", &ds[i].namSinh);
            break;
        }
        if(i = n -1)
        {
            printf("Khong tin thay ma sv %s\n", maSVcanSua);
            return;
        }
    }
    FILE *fp = fopen("DS_SV.C", "wb");
    if(fp == NULL)
    {
        printf("Khong the mo file de ghi!\n");
        return;
    }
    for(int i=0; i<n; i++)
    {
        fwrite(&ds[i], sizeof(sinhVien), 1, fp);
    }
    fclose(fp);
}

void menu()
{
    printf("\tMENU\n");
    printf("1. Tao dannh sach\n");
    printf("2. Hien thi danh sach\n");
    printf("3. Sua thong tin sinh vien\n");
    printf("4. Ket thuc\n");
    printf("Nhap lua chon: ");
}

int main()
{
    int c;
    while(1)
    {
        menu();
        scanf("%d", &c);
        getchar();
        switch(c)
        {
        case 1:
            writeFile();
            system("pause");
            system("cls");
            break;
        case 2:
            readFile();
            system("pause");
            system("cls");
            break;
        case 3:
            suaThongtin();
            break;
        case 4:
            return 0;
        default:
            printf("Vui long nhap lai!\n");
            break;
        }
    }
    return 0;
}
