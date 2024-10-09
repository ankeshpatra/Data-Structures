#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node *next;
} node;

node *tail, *newnode;

void create(int data) {
    node *newnode = (node *)malloc(sizeof(node));
    newnode->data = data;
    if (tail == NULL) {
        tail = newnode;
        tail->next = tail;
    } else {
        newnode->next = tail->next;
        tail->next = newnode;
        tail = newnode;
    }
}

void delatbeg()
{
    printf("\nDeleting the first node\n");
    node *temp = tail->next;
    tail->next = temp->next;
    free(temp);
}

void delatend()
{
    printf("\nDeleting the last node\n");
    node *temp = tail->next;
    while (temp->next != tail)
    {
        temp = temp->next;
    }
    temp->next = tail->next;
    free(tail);
    tail = temp;
}

void delatpos()
{
    int pos;
    printf("\nEnter the position to delete: ");
    scanf("%d", &pos);
    node *temp = tail->next;
    for (int i = 1; i < pos - 1; i++)
    {
        temp = temp->next;
    }
    node *del = temp->next;
    temp->next = del->next;
    free(del);
}

void display() {
    if (tail == NULL) {
        printf("List is empty.\n");
        return;
    }
    node *temp = tail->next;
    printf("The Circular linked list is: ");
    do {
        printf("%d ", temp->data);
        temp = temp->next;
    } while (temp != tail->next);
    printf("\n");
}

int main() {
    tail = NULL;
    int n, data;
    printf("Enter the number of nodes: ");
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
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