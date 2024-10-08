#include <stdio.h>
#define n 10
int queue[n];
int front=-1,rear=-1;

void enqueue()
{
    int x;
    printf("Enter the element to be inserted : ");
    scanf("%d",&x);
    if(front==-1 && rear == -1)
    {
        front=rear=0;
        queue[rear]=x;
    }
    else if((rear+1)%n==front)
    {
        printf("Queue is Overflow\n");
    }
    else
    {
        rear = (rear+1)%n;
        queue[rear]=x;
    }
}

void dequeue()
{
    if(front == -1 && rear == -1)
        printf("Queue is Underflow\n");
    else if(front == rear)
    {
        printf("Element deleted is %d\n",queue[front]);
        front = rear = -1;
    }
    else
    {
        printf("Element deleted is %d\n",queue[front]);
        front = (front+1)%n;
    }
}

void display()
{
    int i=front;
    if (front == -1 && rear == -1)
    {
        printf("Queue is empty\n");
        return;
    }
    printf("Queue elements are: \n");
    while(i!=rear)
    {
        printf("%d ",queue[i]);
        i = (i+1)%n;
    }
    printf("%d\n",queue[rear]);
}

int main()
{
    int choice;
    printf("Circular Queue Operations\n");
    do
    {
        printf("1. Insert\n");
        printf("2. Delete\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter your choice : ");
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
            default:
                printf("Exiting Queue Operations\n");
        }
    } while(choice!=4);
    return 0;
}