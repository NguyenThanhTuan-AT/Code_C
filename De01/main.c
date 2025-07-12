#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <string.h>
/*int main()
{
    int a,x, cnt=0;
    scanf("%d", &x);
    do
    {
        scanf("%d", &a);
        if(a==x) cnt++;
    }
    while(a!=0);
    printf("%d", cnt);
    return 0;
}*/
typedef struct
{
    char ID[5];
    char ho_ten[25];
    char chuc_vu[25];
    char sdt[10];
} Nhanvien;

typedef struct Node
{
    Nhanvien data;
    struct Node *next;
} Node;

typedef struct
{
    Node *first;
    Node *last;
} LinkedList;

LinkedList *create_list()
{
    LinkedList *list=(LinkedList*)malloc(sizeof(LinkedList));
    list->first = NULL;
    list->last = NULL;
    return list;
}

Node *create_newNode()
{
    Node *node=(Node*)malloc(sizeof(Node));
    printf("Nhap ID: ");
    gets(node->data.ID);

    printf("Nhap ten: ");
    gets(node->data.ho_ten);

    printf("Nhap chuc vu: ");
    gets(node->data.chuc_vu);

    printf("Nhap so dien thoai: ");
    gets(node->data.sdt);

    node->next = NULL;
    return node;
}

void add_to_last(LinkedList *list, Node *node)
{
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
    printf("\tDANH SACH NHAN VIEN\n");
    printf("%4s%5s%20s%20s%13s\n", "STT", "ID", "Ho ten", "Chuc vu", "So DT");
    int stt=1;
    for(Node* i = list->first; i!=NULL; i=i->next)
    {
        printf("%4d", stt++);
        printf("%5s", i->data.ID);
        printf("%20s", i->data.ho_ten);
        printf("%20s", i->data.chuc_vu);
        printf("%13s\n", i->data.sdt);
    }
}

Node *search_node(LinkedList *list, char *key, Node** prevNode)
{

    Node *tmp = list->first;
    Node *prev = NULL;
    *prevNode = NULL;
    while(tmp != NULL)
    {
        if(strcmp(tmp->data.ID, key)==0)
        {
            *prevNode = prev;
            return tmp;
        }
        prev = tmp;
        tmp = tmp->next;
    }
    return NULL;
}

void delete_node(LinkedList *list)
{
    Node* prev = NULL;
    char key[10];
    printf("Nhap ID: ");
    gets(key);
    Node *found = search_node(list, key, &prev);
    if(found != NULL)
    {
        if(list->first == found)
        {
            list->first = found->next;
            if(list->last == found) list->last = NULL;
        }
        else if(list->last == found)
        {
            prev->next = NULL;
            list->last = prev;
        }
        else prev->next = found ->next;
        free(found);
        printf("\tDa xoa!\n");
    }
    else   printf("Khong tim thay ID: %s\n", key);
}

void free_list(LinkedList *list)
{
    Node *tmp;
    while(list->first != NULL)
    {
        tmp = list->first;
        list->first = tmp->next;
        free(tmp);
    }
    free(list);
}

void menu()
{
    printf("\tMENU\n");
    printf("1. Nhap danh sach\n");
    printf("2. Hien thi danh sach\n");
    printf("3. Xoa nhan vien\n");
    printf("0. Thoat chuong trinh\n");
    printf("Vui long chon: ");
}
int main()
{
    LinkedList *list = create_list();
    while(1)
    {
        menu();
        int choise;
        int n;
        scanf("%d", &choise);
        getchar();
        switch(choise)
        {
        case 1:
            printf("Nhap so luong nhan vien: ");
            scanf("%d", &n);
            getchar();
            for(int i=1; i<=n; i++)
            {
                printf("Nhap nhan vien thu %d\n", i);
                add_to_last(list, create_newNode());
            }
            break;
        case 2:
            print_list(list);
            break;
        case 3:
            delete_node(list);
            break;
        case 0:
            free_list(list);
            return 0;
        default:
            printf("Vui long nhap lai\n");
            break;
        }
    }
    return 0;
}
