#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *next;
} Node;

Node *newnode, *temp, *top;

void push()
{
    int x;
    newnode = (Node *)malloc(sizeof(Node));
    printf("Enter the element: ");
    scanf("%d", &x);
    newnode->data = x;
    newnode->next = top;
    top = newnode;
}

void pop()
{
    temp = top;
    if (top == NULL)
        printf("Stack is in Underflow Condition\n");
    else
    {
        printf("The popped element is %d\n", temp->data);
        top = top->next;
        free(temp);
    }
}

void peek()
{
    if (top == NULL)
        printf("Stack is Empty\n");
    else
        printf("The top element is %d\n", top->data);
}

void display()
{
    temp = top;
    printf("The Elements in Stack is:\n");
    while (temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main()
{
    int choice;
    top = NULL;
    printf("Stack Operations using Linked List\n");
    do
    {
        printf("1.Push\n2.Pop\n3.Display\n4.Peek\n5.Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            push();
            break;
        case 2:
            pop();
            break;
        case 3:
            display();
            break;
        case 4:
            peek();
            break;
        default:
            printf("Exiting the Stack Operations\n");
        }
    } while (choice >= 1 && choice <= 4);
    return 0;
}