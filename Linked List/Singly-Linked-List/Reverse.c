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

void reverse()
{
    node *prevnode,*currentnode,*nextnode;
    prevnode=NULL;
    currentnode=nextnode=head;
    while(nextnode!=NULL)
    {
        nextnode=nextnode->next;
        currentnode->next=prevnode;
        prevnode=currentnode;
        currentnode=nextnode;
    }
    head=prevnode;
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
    reverse();
    printf("\nThe reversed linked list is: \n");
    display();
    return 0;
}
