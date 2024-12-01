#include <stdio.h>
#include <stdlib.h>
typedef struct node
{
    int data;
    struct node *next;
    struct node *prev;
} node;

node *head, *newnode, *temp;

void create(int data)
{
    newnode = (node *)malloc(sizeof(node));
    newnode->data = data;
    newnode->next = NULL;
    newnode->prev = NULL;
    if (head == NULL)
    {
        head = temp = newnode;
    }
    else
    {
        temp->next = newnode;
        newnode->prev = temp;
        temp = newnode;
    }
}

void reverse()
{
    node *currentnode = head;
    node *temp = NULL;
    
    while (currentnode != NULL)
    {
        temp = currentnode->prev;
        currentnode->prev = currentnode->next;
        currentnode->next = temp;
        currentnode = currentnode->prev;
    }
    
    if (temp != NULL)
    {
        head = temp->prev;
    }
}

void display()
{
    temp = head;
    while (temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
}

int main()
{
    head = NULL;
    int n, data;
    printf("Enter the number of nodes: ");
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        printf("Enter the data for %d node: ", i + 1);
        scanf("%d", &data);
        create(data);
    }
    printf("The doubly linked list is: ");
    display();
    reverse();
    printf("\nThe reversed doubly linked list is: ");
    display();
    return 0;
}