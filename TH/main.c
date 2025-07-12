#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct Product
{
    char name[100];
    int quantity;
    int price;
    struct Product *next;
} Product;

typedef struct
{
    Product *first;
    Product *last;
} LinkedList;

LinkedList* create_list()
{
    LinkedList *list = (LinkedList *)malloc(sizeof(LinkedList));
    list->first = NULL;
    list->last = NULL;
    return list;
}

Product* create_Product()
{
    Product *newProduct = (Product*)malloc(sizeof(Product));
    scanf("%s %d %d", newProduct->name, &newProduct->quantity, &newProduct->price);
    newProduct->next = NULL;
    return newProduct;
}


void add_Product(LinkedList *list, Product *newProduct)
{
    if (list->first == NULL)
        list->first = list->last = newProduct;
    else
    {
        list->last->next = newProduct;
        list->last = newProduct;
    }
}

Product *prev;

Product* search_Product(LinkedList *list, char *key)
{
    prev = NULL;
    Product *tmp = list->first;
    while(tmp != NULL)
    {
        if(strcmp(tmp->name, key) == 0) return tmp;
        prev = tmp;
        tmp = tmp->next;
    }
    return NULL;
}

void delete_Product(LinkedList *list)
{
    char key[100];
    scanf("%s", key);
    Product *tmp = search_Product(list, key);
    if(tmp != NULL)
    {
        if(tmp == list->first)
        {
            list->first = tmp->next;
            if(tmp == list->last) list->last = NULL;
        }
        else if(tmp == list->last)
        {
            prev->next = NULL;
            list->last = prev;
        }
        else prev->next = tmp->next;
//printf("Da xoa san pham: %s\n", name);
        free(tmp);
    }
    else printf("Khong ton tai san pham: %s\n", key);
}

void updateProduct(LinkedList *list)
{
    char key[100];
    int so, giatri;
    scanf("%s %d %d", key, &so, &giatri);
    Product *temp = list->first;
    while (temp != NULL)
    {
        if (strcmp(temp->name, key) == 0)
        {
            if (so == 1)
                temp->quantity = giatri;
            else if (so == 2)
                temp->price = giatri;
            return;
        }
        temp = temp->next;
    }
    printf("Khong the sua thong tin san pham: %s\n", key);
}


void all_display(LinkedList *list)
{
    Product *tmp = list->first;
    while(tmp != NULL)
    {
        printf("%s%10d%10d\n", tmp->name, tmp->quantity, tmp->price);
        tmp = tmp->next;
    }
}
void display(LinkedList *list)
{
    char key[100];
    scanf("%s", key);
    Product *tmp = search_Product(list, key);
    if(tmp != NULL) printf("%s%10d%10d\n", tmp->name, tmp->quantity, tmp->price);
    else printf("Khong ton tai san pham: %s\n", key);
}

void free_Product(LinkedList *list)
{
    Product *tmp;
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
    freopen("D:\\Code C\\input.txt", "r", stdin);
    LinkedList *list = create_list();
    int T;
    int luachon;
    scanf("%d", &T);
    getchar();
    for(int i=0; i<T; i++)
    {
        scanf("%d", &luachon);
        getchar();
        switch(luachon)
        {
        case 1:
        {
            Product *newProduct = create_Product();
            add_Product(list, newProduct);
            break;
        }
        case 2:
            delete_Product(list);
            break;
        case 3:
            display(list);
            break;
        case 4:
            updateProduct(list);
            break;
        case 5:
            all_display(list);
            break;
        }
    }
    free_Product(list);
    return 0;
}
