#include <stdio.h>
#define n 5
int deque[n];
int front = -1, rear = -1;

void enqueuefront(int x);
void enqueuerear(int x);
void deqeuefront();
void deqeuerear();

void enqueuefront(int x)
{
    if ((front == 0 && rear == (n - 1)) || (front == (rear + 1)))
        printf("\nQeueue is Overflow\n");
    else if (front == -1 && rear == -1)
    {
        front = rear = 0;
        deque[front] = x;
    }
    else if (front == 0)
    {
        front = n - 1;
        deque[front] = x;
    }
    else
    {
        front--;
        deque[front] = x;
    }
}

void enqueuerear(int x)
{
    if ((front == 0 && rear == (n - 1)) || (front == (rear + 1)))
        printf("\nQeueue is Overflow\n");
    else if (front == -1 && rear == -1)
    {
        front = rear = 0;
        deque[rear] = x;
    }
    else if (rear == (n - 1))
    {
        rear = 0;
        deque[rear] = x;
    }
    else
    {
        rear++;
        deque[rear] = x;
    }
}

void deqeuefront()
{
    if (rear == -1 && front == -1)
        printf("\nQueue is Underflow\n");
    else if (front == rear)
    {
        printf("The dequeued element from the front is %d\n", deque[front]);
        front = rear = -1;
    }
    else if (front == (n - 1))
    {
        printf("The dequeued element from the front is %d\n", deque[front]);
        front = 0;
    }
    else
    {
        printf("The dequeued element from the front is %d\n", deque[front]);
        front++;
    }
}

void deqeuerear()
{
    if (rear == -1 && front == -1)
        printf("\nQueue is Underflow\n");
    else if (front == rear)
    {
        printf("The dequeud element from the rear is %d\n", deque[rear]);
        front = rear = -1;
    }
    else if (rear == 0)
    {
        printf("The dequeud element from the rear is %d\n", deque[rear]);
        rear = n - 1;
    }
    else
    {
        printf("The dequeud element from the rear is %d\n", deque[rear]);
        rear--;
    }
}

void display()
{
    int i=front;
    printf("\nThe Queue is:\n");
    while(i!=rear)
    {
        printf("%d,",deque[i]);
        i=(i+1)%n;
    }
    printf("%d",deque[rear]);
    printf("\n");
}

int main()
{
    int choice;
    int y;
    int x;
    printf("\nThe Double Ended Queue Operations are:\n");
    do
    {
        printf("\n1.Enqueue from front\n");
        printf("2.Enqueue from Rear\n");
        printf("3.Dequeue from Rear\n");
        printf("4.Dequeue from front\n");
        printf("5.Display the Queue\n");
        printf("6.Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("Enter the element you want to enqueue from front:");
            scanf("%d", &x);
            enqueuefront(x);
            break;
        case 2:
            printf("Enter the element you want to enqueue from rear:");
            scanf("%d", &y);
            enqueuerear(y);
            break;
        case 3:
            deqeuefront();
            break;
        case 4:
            deqeuerear();
            break;
        case 5:
            display();
            break;
        case 6:
            printf("Exiting....\n");
            break;
        default:
            printf("Invalid Input");
        }
    } while (choice >= 1 && choice <= 5);
    return 0;
}