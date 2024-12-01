//Circular Queue using Linked List

#include <stdio.h>
#include <stdlib.h>
typedef struct node
{
    int data;
    struct node *next;
}Node;

Node *front,*rear;

void enqueue()
{
    Node *newnode = (Node*)malloc(sizeof(Node));
    int x;
    printf("Enter the element to be inserted: ");
    scanf("%d",&x);
    newnode->data = x;
    newnode->next=NULL;
    if(front==NULL && rear==NULL)
    {
        front=rear=newnode;
        rear->next=front;
    }
    else
    {
        rear->next=newnode;
        rear=newnode;
        rear->next=front;
    }
}

void dequeue()
{
    Node *temp;
    if(front==NULL && rear==NULL)
    {
        printf("Queue is Underflow\n");
    }
    else if(front==rear)
    {
        printf("Deleted element is %d\n",front->data);
        free(front);
        front=rear=NULL;
    }
    else
    {
        temp=front;
        printf("Deleted element is %d\n",front->data);
        front=front->next;
        rear->next=front;
        free(temp);
    }
}

void display()
{
    Node *temp;
    if(front==NULL && rear == NULL)
    {
        printf("Queue is empty\n");
    }
    else
    {
        temp=front;
        while(temp->next!=front)
        {
            printf("%d ",temp->data);
            temp=temp->next;
        }
        printf("%d ",temp->data);
        printf("\n");
    }
}

int main()
{
    front=rear=NULL;
    int choice;
    do
    {
        printf("\n1.Enqueue\n2.Dequeue\n3.Display\n4.Exit\n");
        printf("Enter your choice: ");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1: enqueue();
                    break;
            case 2: dequeue();
                    break;
            case 3: display();
                    break;
            default: 
                    printf("\nExiting Queue Operations...\n");
        }
    }while(choice>=1 && choice<=3);
    return 0;
}