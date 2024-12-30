#include <stdio.h>
#include <stdlib.h>
typedef struct node
{
    int data;
    struct node *next;
    struct node *prev;
}Node;
Node *head,*tail,*newnode;
void create(int x)
{
    newnode=(Node*)malloc(sizeof(Node));
    newnode->data=x;
    if(head==NULL)
    {
        head=tail=newnode;
        newnode->next=newnode;
        newnode->prev=newnode;
    }
    else
    {
        tail->next=newnode;
        newnode->prev=tail;
        tail=newnode;
        tail->next=head;
        head->prev=tail;
    }
}

void display()
{
    Node *temp;
    temp=head;
    printf("The Circular Doubly Linked List is:\n");
    while(temp->next!=head)
    {
        printf("%d ",temp->data);
        temp=temp->next;
    }
    printf("%d ",temp->data);
    printf("\n");
}

int main()
{
    int n,i,x;
    printf("Enter the number of nodes: ");
    scanf("%d",&n);
    for(i=1;i<=n;i++)
    {
        printf("Enter the %d node :",i);
        scanf("%d",&x);
        create(x);
    }
    display();
    return 0;
}