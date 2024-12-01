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

void display()
{
    temp=head;
    printf("The linked list is: ");
    while(temp!=NULL)
    {
        printf("%d,",temp->data);
        temp=temp->next;
    }
    printf("\n");
}

void addatbeg()
{
    int data;
    printf("Enter the data you want to insert: ");
    scanf("%d",&data);
    newnode=(node*)malloc(sizeof(node));
    newnode->data=data;
    newnode->next=head;
    head=newnode;
}

void addatend()
{
    int data;
    newnode=(node*)malloc(sizeof(node));
    printf("Enter the data you want to insert: ");
    scanf("%d",&data);
    newnode->data=data;
    newnode->next=NULL;
    temp=head;
    while(temp->next!=NULL)
    {
        temp=temp->next;
    }
    temp->next=newnode;
}

void addatpos()
{
    int data,pos;
    newnode=(node*)malloc(sizeof(node));
    printf("Enter the data you want to insert: ");
    scanf("%d",&data);
    printf("Enter the position where you want to insert the data: ");
    scanf("%d",&pos);
    newnode->data=data;
    temp=head;
    for(int i=0;i<pos-1;i++)
    {
        temp=temp->next;
        if(temp==NULL)
        {
            printf("The linked list is smaller than the position you entered.\n");
            return;
        }
    }
    newnode->next=temp->next;
    temp->next=newnode;
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
    addatbeg();
    display();
    addatend();
    display();
    addatpos();
    display();
    return 0;
}