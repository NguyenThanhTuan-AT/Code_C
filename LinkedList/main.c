/*#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SV 10

typedef struct
{
    char maSV[11];
    char hoTen[51];
    int namSinh;
    char queQuan[101];
    char gioiTinh[4];
} SinhVien;

void nhapSinhVien(SinhVien *sv)
{
    printf("Nhap ma sinh vien: ");
    scanf("%10s", sv->maSV);
    getchar();

    printf("Nhap ho va ten: ");
    fgets(sv->hoTen, 51, stdin);
    sv->hoTen[strcspn(sv->hoTen, "\n")] = 0;

    printf("Nhap nam sinh: ");
    scanf("%d", &sv->namSinh);
    getchar();

    printf("Nhap que quan: ");
    fgets(sv->queQuan, 101, stdin);
    sv->queQuan[strcspn(sv->queQuan, "\n")] = 0;

    printf("Nhap gioi tinh (Nam/Nu): ");
    scanf("%3s", sv->gioiTinh);
    getchar();
}

void xuatSinhVien(int n, SinhVien sv)
{
    printf("| %-4d | %-10s | %-25s | %-8d | %-20s | %-3s |\n", n,
           sv.maSV, sv.hoTen, sv.namSinh, sv.queQuan, sv.gioiTinh);
}

void ghiFileCSV(SinhVien *danhSach, int n, const char *tenFile)
{

}

int main()
{
    SinhVien *danhSach = (SinhVien *)malloc(MAX_SV * sizeof(SinhVien));
    if (danhSach == NULL)
    {
        printf("Khong the cap phat bo nho!\n");
        return 1;
    }

    printf("\n========================= NHAP THONG TIN SINH VIEN ===============================\n");
    for (int i = 0; i < MAX_SV; i++)
    {
        printf("\nNhap thong tin sinh vien thu %d:\n", i + 1);
        nhapSinhVien(&danhSach[i]);
    }
    printf("\n============================== DANH SACH SINH VIEN ======================================\n");
    printf("| %-4s | %-10s | %-25s | %-8s | %-20s | %-3s |\n", "STT", "Ma SV", "Ho va ten", "Nam sinh", "Que quan", "GT");
    printf("=========================================================================================\n");
    for (int i = 0; i < MAX_SV; i++)
        xuatSinhVien(i+1, danhSach[i]);

    FILE *file = fopen("D:\\Code\\input.txt", "wt");
    if (file == NULL)
    {
        printf("Khong the mo file!\n");
        return;
    }

    fprintf(file, "\n================================ DANH SACH SINH VIEN ===================================\n");
    fprintf(file, "| %-4s | %-10s | %-25s | %-8s | %-20s | %-3s |\n", "STT", "Ma SV", "Ho va ten", "Nam sinh", "Que quan", "GT");
    fprintf(file, "=========================================================================================\n");

    for (int i = 0; i < MAX_SV; i++)
    {
        fprintf(file, "| %-4d | %-10s | %-25s | %-8d | %-20s | %-3s |\n", i+1,
           danhSach[i].maSV, danhSach[i].hoTen, danhSach[i].namSinh, danhSach[i].queQuan, danhSach[i].gioiTinh);
           fprintf(file, "----------------------------------------------------------------------------------------\n");
    }

    fclose(file);
    printf("\n Danh sach sinh vien da duoc luu vao file: %s\n", "D:\\Code\\input.txt");

    free(danhSach);
    return 0;
}*/
#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
typedef struct Node
{
    int ID, std;
    char ho_ten[20], chuc_vu[20];
    struct Node *next ;
} Node;

typedef struct DSLK
{
    Node *dau;
    Node *cuoi;
} DSLK;

Node *nodelt;

DSLK* tao_dslk()
{
    DSLK *dslk=(DSLK*)malloc(sizeof(DSLK));
    dslk->dau=NULL;
    dslk->cuoi=NULL;
    return dslk;
}

Node* tao_node_moi()
{
    Node *node=(Node*)malloc(sizeof(Node));
    printf("Nhap ten: ");
    gets(node->ho_ten);
    printf("Nhap chuc vu: ");
    gets(node->chuc_vu);
    printf("Nhap so thu tu: ");
    scanf("%d",&node->std);
    printf("Nhap id: ");
    scanf("%d",&node->ID);
    node->next=NULL;
    return node;
}

void them_pt_dau_tien(DSLK *dslk,Node *node)
{
    dslk->dau=node;
    dslk->cuoi=node;
}
void them_pt_vao_cuoi(DSLK *dslk, Node *node)
{
    if(dslk->dau==NULL)
        them_pt_dau_tien(dslk,node);
    else
    {
        dslk->cuoi->next=node;
        dslk->cuoi=node;
    }
}
Node* tim_kiem(DSLK *dslk, int id)
{
    Node *node = dslk->dau;
    nodelt=NULL;
    while(node!=NULL)
    {
        if(node->ID==id)return node;
        nodelt = node;
        node = node->next;
    }
    return NULL;
}

void xoa_nv(DSLK *dslk, int id)
{
    Node *node=tim_kiem(dslk,id);
    if(node!=NULL)
    {
        if(node==dslk->dau)
        {
            dslk->dau=node->next;
            if(node == dslk->cuoi) dslk->cuoi = NULL;
        }
        else if(node == dslk->cuoi)
        {
            nodelt->next = NULL;
            dslk->cuoi = nodelt;
        }
        else nodelt->next = node->next;
        free(node);
    }
    else printf("Khong tim thay ID: %d\n", id);
}

void in_danh_sach(DSLK *dslk)
{
    char *file_path = "tuan.txt";
    FILE *fp =fopen(file_path, "wt");
    if(fp != NULL)
    {
        fprintf(fp, "--------------DANH SACH NHAN VIEN----------------\n");
        fprintf(fp, "%-9s %-20s %-14s %-10s\n","ID", "Ho ten", "Chuc vu", "SoDT");
        Node *node=dslk->dau;
        while(node != NULL)
        {
            fprintf(fp, "%-10d",node->ID);
            fprintf(fp, "%-21s",node->ho_ten);
            fprintf(fp, "%-15s",node->chuc_vu);
            fprintf(fp, "%-11d\n",node->std);
            node = node->next;
        }
        printf("Da luu vao tep: %s\n", file_path);
    }
    fclose(fp);
}

void free_dslk(DSLK *dslk)
{
    Node *node = dslk->dau;
    while(node != NULL)
    {
        Node *temp = node;
        node = node->next;
        free(temp);
    }
    free(dslk);
}
int main()
{
    DSLK *dslk=tao_dslk();
    int id,lua_chon;
    Node *node;
    do
    {
        printf("1. Them nhan vien\n");
        printf("2. In danh sach\n");
        printf("3. Xoa nhan vien\n");
        printf("0. Ket thuc\n");
        printf("Nhap lua chon: ");
        scanf("%d", &lua_chon);
        fflush(stdin);
        switch(lua_chon)
        {
        case 1:
            node=tao_node_moi();
            them_pt_vao_cuoi(dslk,node);
            break;

        case 2:
            in_danh_sach(dslk);
            break;
        case 3:
            printf("Nhap ID: ");
            scanf("%d",&id);
            xoa_nv(dslk,id);
            break;
        case 0:
            printf("Thoat\n");
            break;
        default :
            printf("Lua chon khong hop le!\n");
            break;
        }
        printf("\n");
    }
    while(lua_chon != 0);
    free_dslk(dslk);
    return 0;
}

/*
#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

typedef struct Node
{
    int data;
    struct Node *next;
} Node;

Node *prev_node;
typedef struct
{
    Node *first;
    Node *last;
} LinkedList;

LinkedList* create_list()
{
    LinkedList *list = (LinkedList*)malloc(sizeof(LinkedList));
    list->first = NULL;
    list->last = NULL;
    return list;
}

Node* create_new_node(int value)
{
    Node *node = (Node *)malloc(sizeof(Node));
    node->data = value;
    node->next = NULL;
    return node;
}

void add_first_node(LinkedList *list, Node *node)
{
    if(list->first == NULL)
    {
        list->first = node;
        list->last = node;
    }
    else
    {
        node->next=list->first;
        list->first=node;
    }
}

void insert_to_last(LinkedList *list, Node *node)
{
    if(list->last == NULL)
    {
        list->first = node;
        list->last = node;
    }
    else
    {
        list->last->next = node;
        list->last = node;
    }
}

void print_list(LinkedList *list)
{
    Node *node = list->first;
    while(node != NULL)
    {
        printf("%d ", node->data);
        node = node->next;
    }
    printf("\n");
}

Node* search_node(LinkedList *list, int key)
{
    prev_node = NULL;
    Node *node = list->first;
    while(node != NULL)
    {
        if(node->data == key) return node;
        prev_node = node;
        node = node->next;
    }
    return NULL;
}

void insert_after(LinkedList *list, Node *node, int key)
{
    Node *found_node = search_node(list, key);
    if(found_node != NULL)
    {
        node->next = found_node->next;
        found_node->next = node;
        if(found_node == list->last) list->last = node;
    }
    else printf("Not found node with key = %d\n", key);
}

void delete_node(LinkedList *list, int key)
{
    Node *found = search_node(list, key);
    if(found != NULL)
    {
        if(found == list->first)
        {
            list->first = found->next;
            if(list->last == found) list->last = NULL;
        }
        else if(found == list->last)
        {
            prev_node->next = NULL;
            list->last = prev_node;
        }
        else prev_node->next = found->next;
        free(found);
    }
    else printf("Not found node with key = %d\n", key);
}
void delete_list(LinkedList *list)
{
    Node *temp;
    while(list->first != NULL)
    {
        temp = list->first;
        list->first = temp->next;
        free(temp);
    }
    list->last = NULL;
}
void free_list(LinkedList *list)
{
    Node *node = list->first;
    while(node != NULL)
    {
        Node *temp = node;
        node = node->next;
        free(temp);
    }
    free(list);
}
int main()
{
    LinkedList *list = create_list();

    Node *node2 = create_new_node(2);
    add_first_node(list, node2);
    print_list(list);

    Node *node1 = create_new_node(1);
    add_first_node(list, node1);
    print_list(list);

    Node *node4 = create_new_node(4);
    insert_to_last(list, node4);
    print_list(list);

    Node *node3 = create_new_node(3);
    insert_after(list, node3, 2);
    print_list(list);

    Node *node5 = create_new_node(5);
    insert_after(list, node5, 4);
    print_list(list);

    delete_node(list,3);
    print_list(list);

    delete_list(list);
    print_list(list);
    free_list(list);

    return 0;
}

*/
