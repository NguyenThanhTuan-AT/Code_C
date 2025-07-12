#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

typedef struct Node
{
    int info;
    struct Node *next;
} Node;

void insertAtEnd(Node **pHead, int x)
{
    Node *newNode = (Node*)malloc(sizeof(Node));
    newNode->info = x;
    newNode->next = NULL;

    if (*pHead == NULL) *pHead = newNode;
    else
    {
        Node *temp = *pHead;
        while (temp->next != NULL) temp = temp->next;
        temp->next = newNode;
    }
}

void removeBefore(Node **pHead, Node *p)
{
    if (*pHead == NULL || *pHead == p) return;

    Node *prev = NULL, *curr = *pHead;
    while (curr->next != NULL && curr->next != p)
    {
        prev = curr;
        curr = curr->next;
    }

    if (curr->next == p)
    {
        if (prev == NULL)
        {
            *pHead = p;
        }
        else
        {
            prev->next = p;
        }
        free(curr);
    }
}

void printDivisibleBy7(Node *pHead)
{
    while (pHead != NULL)
    {
        if (pHead->info % 7 == 0)
            printf("%d ", pHead->info);
        pHead = pHead->next;
    }
    printf("\n");
}

void printList(Node *pHead)
{
    while (pHead != NULL)
    {
        printf("%d -> ", pHead->info);
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

int main()
{
    Node *head = NULL;

    insertAtEnd(&head, 10);
    insertAtEnd(&head, 14);
    insertAtEnd(&head, 21);
    insertAtEnd(&head, 28);
    insertAtEnd(&head, 35);
    insertAtEnd(&head, 40);

    printf("Danh sach ban dau:\n");
    printList(head);


    printf("\nCac phan tu chia het cho 7:\n");
    printDivisibleBy7(head);

    // Tìm node có giá trị 28 để xóa node đứng trước nó
    Node *target = head;
    while (target != NULL && target->info != 40)
    {
        target = target->next;
    }

    if (target != NULL)
    {
        removeBefore(&head, target);
        printf("\nDanh sach sau khi xoa node dung truoc node co gia tri 40:\n");
        printList(head);
    }
    else
    {
        printf("\nKhong tim thay node co gia tri 40.\n");
    }

    freeList(&head);

    return 0;
}
