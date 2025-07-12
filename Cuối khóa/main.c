#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

typedef struct
{
    char ten[100];
    int sl;
    int gia;
} sanpham;
typedef struct node
{
    sanpham data;
    struct node* next;
} node;
typedef struct
{
    node* first;
    node* last;
} linklist;

linklist* create_new_linklist()
{
    linklist* list = (linklist*)malloc(sizeof(linklist));
    list->first = NULL;
    list->last = NULL;
    return list;
}
node* create_new_node()
{
    node* new_node = (node*)malloc(sizeof(node));
    sanpham x;
    scanf("%s%d%d", &x.ten, &x.sl, &x.gia);
    new_node->data = x;;
    new_node->next = NULL;
    return new_node;
}

void insert_to_last(linklist* list, node* new_node)
{
    if(list->first == NULL)
    {
        list->first = new_node;
        list->last = new_node;
    }
    else
    {
        list->last->next = new_node;
        list->last = new_node;
    }
}

node* prev;
node* search_node(linklist* list, char key[])
{
    node* node = list->first;
    while(node != NULL)
    {
        if(!strcmp(key, node->data.ten))
        {
            return node;
        }
        prev = node;
        node = node->next;
    }
    return NULL;
}

void xoa_san_pham(linklist* list)
{
    char key[100];
    scanf("%s", &key);
    node* found_node = search_node(list, key);
    if(found_node != NULL)
    {
        if(found_node == list->first)
        {
            list->first = found_node->next;
            if(found_node == list->last)
            {
                list->last = NULL;
            }
            free(found_node);
        }
        else if(found_node == list->last)
        {
            list->last = prev;
            free(found_node);
        }
        else
        {
            prev->next = found_node->next;
            free(found_node);
        }
    }
}
void in_node(node* node)
{
    printf("%s", node->data.ten);
    printf("%10d", node->data.sl);
    printf("%10d", node->data.gia);
    printf("\n");
}

void tim_kiem_va_in(linklist* list)
{
    char key[100];
    scanf("%s", &key);
    node* found_node = search_node(list, key);
    if(found_node == NULL)
    {
        printf("Khong ton tai san pham: %s\n", key);
    }
    else
    {
        in_node(found_node);
    }
}

void sua_node(linklist* list)
{
    char key[100];
    scanf("%s", &key);
    node* found_node = search_node(list, key);
    int new_info, cmd;
    scanf("%d%d", &cmd, &new_info);
    if(found_node == NULL)
    {
        printf("Khong the sua thong tin san pham: %s\n", key);
    }
    else
    {
        if(cmd == 1) found_node->data.sl = new_info;
        else if(cmd == 2) found_node->data.gia = new_info;
    }
}
void in_tb_ds(linklist* list)
{
    node* node = list->first;
    while(node != NULL)
    {
        in_node(node);
        node = node->next;
    }
}

void free_sanpham(linklist *list)
{
    node *tmp;
    while(list->first != NULL)
    {
        tmp = list->first;
        list->first = list->first->next;
        free(tmp);
    }
    list->last = NULL;
    free(list);
}
int main()
{
    //freopen("D:\\Code C\\input.txt","r",stdin);
    linklist* list = create_new_linklist();
    node* new_node;
    int luachon;
    int t;
    scanf("%d", &t);
    while(t--)
    {
        scanf("%d", &luachon);
        switch(luachon)
        {
        case 1:
            new_node = create_new_node();
            insert_to_last(list, new_node);
            break;
        case 2:
            xoa_san_pham(list);
            break;
        case 3:
            tim_kiem_va_in(list);
            break;
        case 4:
            sua_node(list);
            break;
        case 5:
            in_tb_ds(list);
            break;
        }
    }
    free_sanpham(list);
    return 0;
}





/*
#include<stdio.h>
#include<math.h>
long giaithua(int n)
{
    if(n==1) return 1;
    else return n * giaithua(n-1);
}
float sum(int n)
{
    if(n == 1) return 1;
    else return 1.0/ giaithua(n) + sum(n-1);
}
int fibo(int n)
{
    if(n==0) return 0;
    if(n==1) return 1;
    else return fibo(n-1) + fibo(n-2);
}
double mu(int x, int y)
{
    if(y == 0) return 1;
    if(y == 1) return x;
    if(y>0) return x * mu(x, y-1);
    else return 1.0 / mu(x, -y);
}
int main()
{
   int a
   ;
   scanf("%d", &a);
   printf("%d",fibo(a));
    return 0;
}
*/
