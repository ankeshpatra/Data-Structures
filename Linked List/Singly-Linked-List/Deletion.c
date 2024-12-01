#include <stdio.h>
#include <stdlib.h>
typedef struct node
{
    int data;
    struct node *next;
} node;
node *head,*newnode,*temp;

void create(int data)
{
    newnode=(node*)malloc(sizeof(node));
    newnode->data=data;
    newnode->next=NULL;
    if(head==NULL)
    {
        head=temp=newnode;
    }
    else
    {
        temp->next=newnode;
        temp=newnode;
    }
}

void delatbeg()
{
    printf("\nAfter the deletion at the beginning: \n");
    temp=head;
    head=head->next;
    free(temp);
}

void delatend()
{
    printf("\nAfter the deletion at the end: \n");
    temp=head;
    while(temp->next->next!=NULL)
    {
        temp=temp->next;
    }
    free(temp->next);
    temp->next=NULL;
}

void delatpos()
{
    int pos;
    printf("\nEnter the position: ");
    scanf("%d",&pos);
    temp=head;
    for(int i=1;i<pos-1;i++)
    {
        temp=temp->next;
    }
    node *t=temp->next;
    temp->next=temp->next->next;
    free(t);
}

void display()
{
    temp=head;
    printf("The linked list is: ");
    while(temp!=NULL)
    {
        printf("%d ",temp->data);
        temp=temp->next;
    }
}

int main()
{
    head=NULL;
    int n,data;
    printf("Enter the number of nodes: ");
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        printf("Enter the data for %d node: ",i+1);
        scanf("%d",&data);
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