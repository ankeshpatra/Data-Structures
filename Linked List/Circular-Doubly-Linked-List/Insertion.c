#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *next;
    struct node *prev;
} Node;

Node *head, *tail;
int count = 0;

void create(int x)
{
    Node *newnode = (Node *)malloc(sizeof(Node));
    newnode->data = x;
    if (head == NULL)
    {
        head = tail = newnode;
        newnode->next = newnode;
        newnode->prev = newnode;
    }
    else
    {
        tail->next = newnode;
        newnode->prev = tail;
        tail = newnode;
        tail->next = head;
        head->prev = tail;
    }
    count++;
}

void display()
{
    Node *temp = head;
    printf("The Circular Doubly Linked List is:\n");
    if (head != NULL)
    {
        do
        {
            printf("%d ", temp->data);
            temp = temp->next;
        } while (temp != head);
    }
    printf("\n");
}

void addatbeg()
{
    int x;
    printf("Enter the number you want to insert at beginning: ");
    scanf("%d", &x);
    Node *newnode = (Node *)malloc(sizeof(Node));
    newnode->data = x;
    if (head == NULL)
    {
        head = tail = newnode;
        newnode->next = newnode;
        newnode->prev = newnode;
    }
    else
    {
        newnode->next = head;
        head->prev = newnode;
        head = newnode;
        tail->next = newnode;
        head->prev = tail;
    }
    count++;
}

void addatend()
{
    int x;
    printf("Enter the number you want to insert at end: ");
    scanf("%d", &x);
    Node *newnode = (Node *)malloc(sizeof(Node));
    newnode->data = x;
    if (head == NULL)
    {
        head = tail = newnode;
        newnode->next = newnode;
        newnode->prev = newnode;
    }
    else
    {
        tail->next = newnode;
        newnode->prev = tail;
        tail = newnode;
        tail->next = head;
        head->prev = tail;
    }
    count++;
}

void addatspec()
{
    int x, pos, i = 1;
    printf("Enter the number you want to insert: ");
    scanf("%d", &x);
    printf("Enter the position: ");
    scanf("%d", &pos);
    if (pos < 1 || pos > count + 1)
    {
        printf("Enter a valid position\n");
        return;
    }
    Node *newnode = (Node *)malloc(sizeof(Node));
    newnode->data = x;
    if (pos == 1)
    {
        addatbeg();
    }
    else
    {
        Node *temp = head;
        while (i < pos - 1)
        {
            temp = temp->next;
            i++;
        }
        newnode->next = temp->next;
        newnode->prev = temp;
        if (temp->next != NULL)
        {
            temp->next->prev = newnode;
        }
        temp->next = newnode;
        if (pos == count + 1)
        {
            tail = newnode;
            tail->next = head;
            head->prev = tail;
        }
        count++;
    }
}

int main()
{
    int n, i, x;
    printf("Enter the number of nodes: ");
    scanf("%d", &n);
    for (i = 1; i <= n; i++)
    {
        printf("Enter the %d node: ", i);
        scanf("%d", &x);
        create(x);
    }
    display();
    addatbeg();
    display();
    addatend();
    display();
    addatspec();
    display();
    return 0;
}
