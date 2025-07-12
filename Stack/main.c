/*

#include<stdio.h>
#include<stdlib.h>
#define MAX_SIZE 10
typedef struct
{
    int data[MAX_SIZE];
    int top;
} Stack;
void initStack(Stack *s)
{
    s->top = -1;
}
int isEmpty(Stack *s)
{
    return s->top == -1;
}
int isFull(Stack *s)
{
    return s->top == MAX_SIZE -1;
}
void push(Stack *s, int value)
{
    if(isFull(s))
    {
        printf("Stack day, khong the them phan tu\n");
        return;
    }
    s->data[++s->top] = value;
}
int peek(Stack *s)
{
    if(isEmpty(s))
    {
        printf("Stack rong\n");
        return -1;
    }
    return s->data[s->top];
}
int pop(Stack *s)
{
    if(isEmpty(s))
    {
        printf("Stack rong\n");
        return -1;
    }
    return s->data[s->top--];
}
void inputStack(Stack *s, int n)
{
    for(int i=0; i<n; i++)
    {
        int value;
        scanf("%d", &value);
        push(s, value);
    }
}
void outputStack(Stack *s)
{
    while(!isEmpty(s))
    {
        printf("%d ", pop(s));
    }
    printf("\n");
}
void processStack(Stack *s, int n)
{
    int sum = 0, max = 0;
    for(int i=0; i<n; i++)
    {
        int value;
        scanf("%d", &value);
        push(s, value);
        sum += value;
        if(max < value) max = value;
    }
    double avg = (double)sum / n;
    printf("%d %.2f %d\n", sum, avg, max);
}
int main()
{
    //int n;
    Stack s;
    initStack(&s);
   // scanf("%d", &n);
    //processStack(&s, n);
    push(&s, 6);
    push(&s, 7);
    push(&s, 5);
    push(&s, 4);
    push(&s, 8);
    push(&s, 9);
    outputStack(&s);
    //push(&s, 10);
    //outputStack(&s);
    return 0;
}*/

#include<stdio.h>

typedef struct Node
{
    int data;
    struct Node *next;
} Node;

typedef struct
{
    Node *top;
} Stack;

void initStack(Stack *s)
{
    s->top = NULL;
}
int isEmpty(Stack *s)
{
    return s->top == -1;
}

Node *createNode(int value)
{
    Node *node = (Node *)malloc(sizeof(Node));
    node->data = value;
    node->next = NULL;
    return node;
}
void push(Stack *s, int value)
{
    Node *node = createNode(value);
    node->next = s->top;
    s->top = node;
}

int pop(Stack *s)
{
    if(isEmpty(s))
    {
        printf("Stack is empty, so cannot pop\n");
        return -1;
    }
    else
    {
        Node *temp = s->top;
        s->top = temp->next;
        int result = temp->data;
        free(temp);
        return result;
    }
}
int peek(Stack *s)
{
    if(isEmpty(s))
    {
        printf("Stack is empty, not get top element!");
        return -1;
    }
    return s->top->data;
}

void printStack(Stack *s)
{
    printf("Stack elements: \n");
    if(isEmpty(s))
        printf("Stack is empty\n");
    else
    {
        Node *node = s->top;
        while(node != NULL)
        {
            printf("%d ", node->data);
            node = node->next;
        }
        printf("\n");
    }
}

int main()
{
    Stack *s = (Stack *)malloc(sizeof(Stack));
    initStack(s);

   int a, b;
   int r;
   scanf("%d %d", &a, &b);
   while(x != 0)
   {
       r = x%2;
       x/=2;
       push(s, r);
   }

    printStack(s);

    return 0;
}
