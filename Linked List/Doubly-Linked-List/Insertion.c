#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node *next;
    struct node *prev;
} node;

node *head, *newnode, *temp;

void create(int data) {
    newnode = (node *)malloc(sizeof(node));
    newnode->data = data;
    newnode->next = NULL;
    newnode->prev = NULL;
    if (head == NULL) {
        head = temp = newnode;
    } else {
        temp->next = newnode;
        newnode->prev = temp;
        temp = newnode;
    }
}

void display() {
    temp = head;
    printf("The linked list is: ");
    while (temp != NULL) {
        printf("%d,", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

void addatbeg() {
    int data;
    printf("Enter the data you want to insert: ");
    scanf("%d", &data);
    newnode = (node *)malloc(sizeof(node));
    newnode->data = data;
    newnode->next = head;
    newnode->prev = NULL;
    head->prev = newnode;
    head = newnode;
}

void addatend() {
    int data;
    newnode = (node *)malloc(sizeof(node));
    printf("Enter the data you want to insert: ");
    scanf("%d", &data);
    newnode->data = data;
    newnode->next = NULL;
    temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newnode;
    newnode->prev = temp;
}

void addatpos()
{
    int data,pos,i=1;
    printf("Enter the position you want to insert: ");
    scanf("%d",&pos);
    printf("Enter the data you want to insert: ");
    scanf("%d",&data);
    newnode=(node*)malloc(sizeof(node));
    newnode->data=data;
    temp=head;
    while(i<pos-1)
    {
        temp=temp->next;
        i++;
    }
    newnode->next=temp->next;
    temp->next->prev=newnode;
    temp->next=newnode;
    newnode->prev=temp;
}

int main() {
    head = NULL;
    int n, data;
    printf("Enter the number of nodes: ");
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        printf("Enter the data for %d node: ", i + 1);
        scanf("%d", &data);
        create(data);
    }
    display();
    addatbeg();
    display();
    addatend();
    display();
    addatpos();
    display();
    return 0;
}