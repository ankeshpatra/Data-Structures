#include <stdio.h>
#include <stdlib.h>
#define MAX 10
int stack[MAX],top=-1;

void push()
{
    int x;
    if(top==MAX-1)
    {
        printf("Stack overflow.\n");
        return;
    }
    printf("Enter the element: ");
    scanf("%d",&x);
    stack[++top]=x;
}

void pop()
{
    if(top==-1)
    {
        printf("Stack underflow.\n");
        return;
    }
    printf("The popped element is: %d\n",stack[top--]);
}

void pallindrome()
{
    int i,j;
    for(i=0,j=top;i<=top/2;i++,j--)
    {
        if(stack[i]!=stack[j])
        {
            printf("The stack is not pallindrome.\n");
            return;
        }
    }
    printf("The stack is pallindrome.\n");
}

void display()
{
    if(top==-1)
    {
        printf("Stack is empty.\n");
        return;
    }
    printf("The stack is: ");
    for(int i=0;i<=top;i++)
    {
        printf("%d ",stack[i]);
    }
    printf("\n");
}

int main()
{
    int choice;
    printf("Stack Operations.\n");
    do
    {
        printf("1. Push\n2. Pop\n3. Pallindrome\n4. Display\n5. Exit\nEnter your choice: ");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1: push();
                    break;
            case 2: pop();
                    break;
            case 3: pallindrome();
                    break;
            case 4: display();
                    break;
            default: printf("Exiting Stack Operations.\n");
        }
    }while(choice>=1 && choice<=4);
    return 0;
}