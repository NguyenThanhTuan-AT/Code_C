#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

typedef struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
} Node;

Node* create_new_node(int value)  //Tao node moi
{
    Node* newNode=(Node *)malloc(sizeof(Node));
    newNode->data = value;
    newNode->left = newNode->right = NULL;
    return newNode;
}

/*Node* create_random_node()
{
    int value = rand() % 20;
    return create_new_node(value);
}*/

void generateRandomTree(int level, Node** currentNode)   //Tao node ngau nhien theo thu tu truoc
{
    if(level > 0)
    {
        *currentNode = create_new_node(rand() % 20);
        generateRandomTree(level-1, &(*currentNode)->left);
        generateRandomTree(level-1, &(*currentNode)->right);
    }
}

void inputTree(int level, Node** currentNode)              //Nhap gia tri node tu ban phim theo thu tu truoc
{
    int value;
    if(level > 0)
    {
        scanf("%d", &value);
        *currentNode = create_new_node(value);
        inputTree(level-1, &(*currentNode)->left);
        inputTree(level-1, &(*currentNode)->right);
    }
}


void BST(Node** pTree, int x)    //Tim kiem roi bo sung
{
    Node* Q = NULL;
    Node* P = *pTree;
    while(P != NULL)
    {
        if(P->data == x)
        {
            printf("Da ton tai gia tri %d\n", x);
            return;
        }
        Q = P;
        if(P->data < x) P = P->right;
        else P = P->left;
    }
    P = create_new_node(x);
    if(*pTree == NULL) *pTree = P;
    else
    {
        if(Q->data < x) Q->right = P;
        else Q->left = P;
    }
}

void BST_Delete(Node** pTree, int x) //Tim kiem roi loai bo
{
    Node* P = *pTree;
    Node* Q = NULL;
    while(P != NULL)
    {
        if(P->data == x) break;
        Q = P;
        if(x < P->data) P = P->left;
        else P = P->right;
    }
    if(P->left != NULL && P->right != NULL)
    {
        Node* temp = P;
        Q = P;
        P = P->left;
        while(P->right != NULL)
        {
            Q = P;
            P = P->right;
        }
        temp->data = P->data;
    }
    Node* Child = NULL;
    if(P->left != NULL) Child = P->left;
    else Child = P->right;
    if(*pTree == P) *pTree = Child;
    else
    {
        if(Q->left == P) Q->left = Child;
        else Q->right = Child;
    }
    free(P);
}

bool BST_Check(Node* pTree)   //Kiem tra cay nhi phan tim kiem
{
    if(pTree == NULL) return true;
    if(pTree->left != NULL && pTree->left->data > pTree->data) return false;
    if(pTree->right != NULL && pTree->right->data < pTree->data) return false;
    if(BST_Check(pTree->left) == false || BST_Check(pTree->right) == false) return false;
    return true;
}

bool isValueExist(Node *pTree, int value) // Kiem ta gia tri trong cay nhi phan
{
    if(pTree == NULL) return false;
    if(pTree->data == value) return true;
    return isValueExist(pTree->left, value) || isValueExist(pTree->right, value);
}

void Pre_order(Node* node)  //Duyet truoc
{
    if(node == NULL) return;
    else
    {
        printf("%c ", node->data + 'A');
        Pre_order(node->left);
        Pre_order(node->right);
    }
}

void In_order(Node* node)   //Duyet giua
{
    if(node == NULL) return;
    else
    {
        In_order(node->left);
        printf("%c ", node->data + 'A');
        In_order(node->right);
    }
}

void Post_order(Node* node)    //Duyet cuoi
{
    if(node == NULL) return;
    else
    {
        Post_order(node->left);
        Post_order(node->right);
        printf("%c ", node->data + 'A');
    }
}

void free_tree(Node* node)
{
    if(node == NULL) return;
    else
    {
        free_tree(node->left);
        free_tree(node->right);
        free(node);
    }
}

int main()
{
    Node* pTree = NULL;
    //generateRandomTree(3, &pTree);
    //inputTree(3, &pTree);

    int t = 20;
    srand(time(NULL));
    while(t--)
    {
        int x = rand() % 26;
        BST(&pTree, x);
    }

    printf("Duyet truoc: ");
    Pre_order(pTree);
    printf("\nDuyet giua: ");
    In_order(pTree);
    printf("\nDuyet sau: ");
    Post_order(pTree);

    //if(BST_Check(pTree) == false) printf("Khong phai cay nhi phan tim kiem!\n");
    //else  printf("La cay nhi phan tim kiem!\n");

    free_tree(pTree);
    pTree = NULL;

    return 0;
}
