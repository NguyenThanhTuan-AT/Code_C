/*#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#define SAP_XEP_DIEM_TOAN 1
#define SAP_XEP_DIEM_LY 2
#define SAP_XEP_DIEM_ANH 3
#define SAP_XEP_TONG_DIEM 4

typedef struct diemthi
{
    char sbd[6];
    float toan, ly, anh, tong;
    char ho_ten[25];
} diemthi;

typedef struct Node
{
    diemthi sv;
    struct Node *next;
}
Node;

typedef struct
{
    Node *first;
    Node *last;
} LinkedList;

LinkedList *create_list()
{
    LinkedList *list = (LinkedList *)malloc(sizeof(LinkedList));
    list->first = NULL;
    list->last = NULL;
    return list;
}

diemthi input()
{
    diemthi sv;
    printf("Nhap sbd: ");
    gets(sv.sbd);
    printf("Nhap ho ten: ");
    gets(sv.ho_ten);
    printf("Nhap diem toan: ");
    scanf("%f", &sv.toan);
    printf("Nhap diem ly: ");
    scanf("%f", &sv.ly);
    printf("Nhap diem anh: ");
    scanf("%f", &sv.anh);
    getchar();
    sv.tong = sv.toan + sv.ly + sv.anh;
    return sv;
}
Node *create_node()
{
    Node *node=(Node *)malloc(sizeof(Node));
    node->sv = input();
    node->next = NULL;
    return node;
}

void add_node(LinkedList *list)
{
    Node *node = create_node();
    if(list->first == NULL)
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
    if(list->first == NULL) return;
    int stt = 1;
    Node *tmp = list->first;
    printf("\tDANH SACH DIEM THI THPT\n");
    printf("%3s %4s %-25s%10s%10s%10s%10s\n", "STT", "SBD", "Ho ten", "DiemToan", "DiemLy", "DiemTA", "Tong");

    while(tmp != NULL)
    {
        printf("%3d ", stt);
        printf("%4s", tmp->sv.sbd);
        printf(" %-25s", tmp->sv.ho_ten);
        printf("%10.1f", tmp->sv.toan);
        printf("%10.1f", tmp->sv.ly);
        printf("%10.1f", tmp->sv.anh);
        printf("%10.1f\n", tmp->sv.tong);
        stt++;
        tmp = tmp->next;
    }
}

void free_list(LinkedList *list)
{
    Node *tmp;
    while(list->last != NULL)
    {
        tmp = list->first;
        list->first = tmp->next;
        free(tmp);
    }
    free(list);
}

float compare_toan(diemthi a, diemthi b)
{
    return a.toan - b.toan;
}
float compare_ly(diemthi a, diemthi b)
{
    return a.ly - b.ly;
}
float compare_anh(diemthi a, diemthi b)
{
    return a.anh - b.anh;
}
float compare_tong(diemthi a, diemthi b)
{
    return a.tong - b.tong;
}
void sort_list(LinkedList *list, float (*cmp)(diemthi a, diemthi b))
{
    for(Node *i = list->first; i!=NULL; i=i->next)
    {
        Node *min = i;
        for(Node *j = i->next; j!=NULL; j=j->next)
        {
            if(cmp(min->sv, j->sv) > 0) min = j;
        }
        if(min != i)
        {
            diemthi tmp = i->sv;
            i->sv = min->sv;
            min->sv = tmp;
        }
    }
}

void menu()
{
    printf("\t\tMENU\n");
    printf("1. Tao danh sach thi sinh\n");
    printf("2. Hien thi danh sach thi sinh\n");
    printf("3. Sap sep diem thi\n");
    printf("0. Ket thuc\n");
    printf("Vui long chon: ");
}
int main()
{
    LinkedList *list = create_list();
    while(1)
    {
        menu();
        int choise;
        scanf("%d", &choise);
        getchar();
        int n;
        int mode;
        switch(choise)
        {
        case 1:
            printf("Nhap so luong sv: ");
            scanf("%d", &n);
            getchar();
            for(int i=1; i<=n; i++)
            {
                printf("Sinh vien thu %d\n", i);
                add_node(list);
            }
            break;
        case 2:
            print_list(list);
            break;
        case 3:
            printf("1. Sap xep theo diem toan\n");
            printf("2. Sap xep theo diem ly\n");
            printf("3. Sap xep theo diem tieng anh\n");
            printf("4. Sap xep theo diem tong diem\n");
            printf("Chon: ");
            scanf("%d", &mode);
            getchar();
            switch(mode)
            {
            case 1:
                sort_list(list, compare_toan);
                print_list(list);
                break;
            case 2:
                sort_list(list, compare_ly);
                print_list(list);
                break;
            case 3:
                sort_list(list, compare_anh);
                print_list(list);
                break;
            case 4:
                sort_list(list, compare_tong);
                print_list(list);
                break;
            default:
                printf("Chi chon tu 1-4: \n");
            }
            break;
        case 0:
            free_list(list);
            return 0;
        default:
            printf("Vui long nhap lai!\n");
            break ;
        }
    }
    return 0;
}*/
