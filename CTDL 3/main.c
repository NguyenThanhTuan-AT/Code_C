#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int info;
    struct Node *next;
} Node;

void insertLast(Node **pHead, Node *p, int x)
{
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->info = x;
    newNode->next = NULL;
    if(*pHead == NULL || *pHead == p)
    {
        newNode->next = *pHead;
        *pHead = newNode;
        return;
    }
    Node *curr = *pHead;
    while(curr->next != NULL && curr->next != p)
        curr = curr->next;
    if(curr == NULL) return;
    else
    {
        newNode->next = p;
        curr->next = newNode;
    }
}

void deleteLast(Node **pHead)
{
    if (*pHead == NULL) return;
    if ((*pHead)->next == NULL)
    {
        free(*pHead);
        *pHead = NULL;
        return;
    }
    Node *curr = *pHead;
    while (curr->next->next != NULL)
        curr = curr->next;
    free(curr->next);
    curr->next = NULL;
}


Node* searchNode(Node *pHead, int y)
{
    while(pHead != NULL)
    {
        if(pHead->info == y) return pHead;
        pHead = pHead->next;
    }
    return NULL;
}

void print(Node *pHead)
{
    while(pHead != NULL)
    {
        printf("%d->", pHead->info);
        pHead = pHead->next;
    }
    printf("NULL\n");
}

void freeList(Node **pHead)
{
    Node *temp;
    while (*pHead != NULL)
    {
        temp = *pHead;
        *pHead = (*pHead)->next;
        free(temp);
    }
}

int main() {
    Node *head = NULL;


    insertLast(&head, head, 10);
    insertLast(&head, NULL, 20);
    insertLast(&head, NULL, 30);


    printf("Danh sach ban dau:\n");
    print(head);

    Node *found = searchNode(head, 10);
    if (found != NULL) {
        insertLast(&head, found, 15);
    }


    printf("Danh sach sau khi chen 15 truoc 10:\n");
    print(head);

    deleteLast(&head);
    printf("Danh sach sau khi xoa nut cuoi:\n");
    print(head);

    freeList(&head);
    return 0;
}
