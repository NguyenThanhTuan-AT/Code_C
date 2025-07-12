#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
/*
void write(char *file_path)
{
    FILE *fp = fopen(file_path, "wt");
    if(fp != NULL)
    {
        char str[100];
        fgets(str, sizeof(str), stdin);
        fprintf(fp, "%s", str);
        fputs("2006\n", fp);
        fputs("Thai Binh\n", fp);
        fprintf(fp, "Lap trinh C60\n");
        int i;
        for(i=0; i<100; i++)
        {
            fprintf(fp, "%d ", i);
        }
    }
    fclose(fp);
}
void read(char *file_path)
{
    FILE *fp = fopen(file_path, "rt");
    char tuan[100];
    int cnt=0;
    if(fp != NULL)
    {
        while(!feof(fp))
        {
            fgets(tuan, sizeof(tuan), fp);
            printf("%s", tuan);
            ++cnt;
        }
        printf("\n");
        printf("%d", cnt);
    }
    fclose(fp);
}
void random_array(int a[], int n)
{
    srand(time(NULL));
    int i;
    for(i=0; i<n; i++) a[i] = rand() % 101;
}
void print_array(int a[], int n)
{
    int i;
    for(i=0; i<n; i++)
    {
        printf("%d ", a[i]);
    }
    printf("\n");
}
void write_binary(char *file_path, int a[], int n)
{
    FILE *fp = fopen(file_path, "wb");
    if(fp != NULL)
    {
        fwrite(a, sizeof(int), n, fp);
    }
    fclose(fp);
}
void read_binary(char *file_path)
{
    FILE *fp = fopen(file_path, "rb");
    if(fp != NULL)
    {
        fseek(fp, -3 * sizeof(int), SEEK_END);
        int x;
        fread(&x, sizeof(int), 1, fp);
        printf("%d", x);
    }
    fclose(fp);
}
int main()
{
    char *file_path = "D:\\Code\\data.txt";
    //write(file_path);
    //read(file_path);
    int a[100];
    int n = 100;
    random_array(a, n);
    print_array(a, n);
    write_binary(file_path, a, n);
    read_binary(file_path);

    return 0;
}*/
typedef struct
{
    int ngay;
    int thang;
    int nam;
} ngaysinh;
int main()
{
    ngaysinh n1;
    FILE *fp = fopen("tuan.bin", "rb");
    if(fp != NULL)
    {
        fread(&n1, sizeof(ngaysinh), 1, fp);
        printf("%d/%d/%d", n1.ngay, n1.thang, n1.nam);
    }
    fclose(fp);
    return 0;
}
