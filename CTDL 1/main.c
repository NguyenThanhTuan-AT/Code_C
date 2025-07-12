#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

typedef struct Node
{
    int info;
    struct Node *next;
} Node;

int countNodes(Node *pHead)
{
    int count = 0;
    while(pHead != NULL)
    {
        count++;
        pHead = pHead->next;
    }
    return count;
}

void insertAtK(Node **pHead, int x, int k)
{
    Node *newNode = (Node*)malloc(sizeof(Node));
    newNode->info = x;
    newNode->next = NULL;
    if(k == 0 || *pHead == NULL)
    {
        newNode->next = *pHead;
        *pHead = newNode;
        return;
    }
    Node *temp = *pHead;
    int i = 0;
    while(temp != NULL && i<k-1)
    {
        temp = temp->next;
        i++;
        if(temp == NULL)
        {
            printf("Vi tri k vuot qua chieu dai\n");
            free(newNode);
            return;
        }
    }
    newNode->next = temp->next;
    temp->next = newNode;
}

void delete_y(Node **pHead, int y)
{
    Node * temp = *pHead, *prev = NULL;
    while(temp != NULL)
    {
        if(temp->info == y)
        {
            if(prev == NULL)
            {
                *pHead = temp->next;
                free(temp);
                temp = *pHead;
            }
            else
            {
                prev->next = temp->next;
                free(temp);
                temp = prev->next;
            }
        }
        else
        {
            prev = temp;
            temp = temp->next;
        }
    }
}

void printChia5du2(Node *pHead)
{
    while(pHead != NULL)
    {
        if(pHead->info % 5 == 2) printf("%d ", pHead->info);
        pHead = pHead->next;
    }
    printf("\n");
}


void printList(Node *pHead)
{
    Node *current = pHead;
    while(current != NULL)
    {
        printf("%d->", current->info);
        current = current->next;
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

    printf("--- Ban dau danh sach: ---\n");
    printList(head);
    printf("So nut: %d\n", countNodes(head));

    insertAtK(&head, 10, 0);
    insertAtK(&head, 20, 0);
    insertAtK(&head, 30, 0);
    printf("\n--- Danh sach sau khi them vao dau: ---\n");
    printList(head);
    printf("So nut: %d\n", countNodes(head));

    insertAtK(&head, 15, 1);
    insertAtK(&head, 25, 3);
    printf("\n--- Danh sach sau khi them vao vi tri k: ---\n");
    printList(head);
    printf("So nut: %d\n", countNodes(head));

    insertAtK(&head, 50, 10);

    delete_y(&head, 20);
    delete_y(&head, 25);
    printf("\n--- Danh sach sau khi xoa cac nut co gia tri 20 va 25: ---\n");
    printList(head);
    printf("So nut: %d\n", countNodes(head));

    printf("\n--- Cac nut chia 5 du 2: ---\n");
    printChia5du2(head);

    insertAtK(&head, 7, 0);
    insertAtK(&head, 12, 2);
    printf("\n--- Danh sach sau khi them 7 va 12: ---\n");
    printList(head);
    printf("\n--- Cac nut chia 5 du 2 sau khi them: ---\n");
    printChia5du2(head);

    freeList(&head);

    printf("\n--- Danh sach sau khi giai phong: ---\n");
    printList(head);
    printf("So nut: %d\n", countNodes(head));

    return 0;
}
