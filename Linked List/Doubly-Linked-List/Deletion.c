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

void delatbeg()
{
    printf("\nDeleting the first node\n");
    temp = head;
    head = head->next;
    head->prev = NULL;
    free(temp);
}

void delatend()
{
    printf("\nDeleting the last node\n");
    temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->prev->next = NULL;
    free(temp);
}

void delatpos()
{
    int pos;
    printf("\nEnter the position to delete: ");
    scanf("%d", &pos);
    temp = head;
    for (int i = 0; i < pos - 1; i++)
    {
        temp = temp->next;
    }
    temp->prev->next = temp->next;
    temp->next->prev = temp->prev;
    free(temp);
}

void display()
{
    temp = head;
    printf("The linked list is: ");
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
    display();
    delatbeg();
    display();
    delatend();
    display();
    delatpos();
    display();
    return 0;
}