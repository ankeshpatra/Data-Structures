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

void reverse()
{
    node *prevnode,*currentnode,*nextnode;
    currentnode=tail->next;
    nextnode=currentnode->next;
    if(tail==NULL)
    {
        printf("List is empty.\n");
        return;
    }
    else
    {
        while(currentnode!=tail)
        {
            prevnode=currentnode;
            currentnode=nextnode;
            nextnode=currentnode->next;
            currentnode->next=prevnode;
        }
        nextnode->next=tail;
        tail=nextnode;
    }
}

void display() {
    if (tail == NULL) {
        printf("List is empty.\n");
        return;
    }
    node *temp = tail->next;
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
    printf("The Circular linked list is: ");
    display();
    reverse();
    printf("The Circular linked list after reversing is: ");
    display();
    return 0;
}