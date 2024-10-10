#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node *next;
}Node;

Node *front,*rear;

void enqueue()
{
    int x;
    printf("Enter the data: ");
    scanf("%d",&x);
    Node *newnode = (Node*)malloc(sizeof(Node));
    newnode->data=x;
    newnode->next=NULL;
    if(front==NULL && rear==NULL)
        front=rear=newnode;
    else
    {
        rear->next=newnode;
        rear=newnode;
    }
}

void dequeue()
{
        Node *temp;
    if(front==NULL && rear==NULL)
        printf("Queue is Underflow\n");
    else if(front==rear)
    {
        temp=front;
        printf("The dequeued element is %d\n",temp->data);
        free(temp);
        front=rear=NULL;
    }
    else
    {
        temp=front;
        front=front->next;
        printf("The dequeued element is %d\n",temp->data);
        free(temp);
    }
}

void display()
{
    if(front==NULL && rear==NULL)
    {
        printf("The Queue is Empty\n");
    }
    else
    {
        Node *temp;
        temp=front;
        printf("The Queue is: ");
        while(temp!=NULL)
        {
            printf("%d ",temp->data);
            temp=temp->next;
        }
        printf("\n");
    }
}

void peek()
{
    if(front==NULL && rear==NULL)
    {
        printf("The Queue is Empty\n");
    }
    else
    {
        printf("The Front element is %d\n",front->data);
        printf("and the Rear element is %d\n",rear->data);
    }
}

int main()
{
    front=NULL;
    rear=NULL;
    int choice;
    printf("Queue Operations using Linked List are:\n");
    do
    {
        printf("1.Enqueue\n");
        printf("2.Dequeue\n");
        printf("3.Display\n");
        printf("4.Peek\n");
        printf("5.Exit\n");
        printf("Enter your choice: ");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
                enqueue();
                break;
            case 2:
                dequeue();
                break;
            case 3:
                display();
                break;
            case 4:
                peek();
                break;
            default:
                printf("Exiting Queue Operations\n");
        }
    }while(choice>=1 && choice<=4);
    return 0;
}