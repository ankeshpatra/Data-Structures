#include <stdio.h>
#include <stdlib.h>
typedef struct node
{
    int data;
    struct node *next;
} node;
node *tail,*newnode;
void create(int data)
{
    newnode=(node*)malloc(sizeof(node));
    newnode->data=data;
    if(tail==NULL)
    {
        tail=newnode;
        tail->next=tail;
    }
    else
    {
        newnode->next=tail->next;
        tail->next=newnode;
        tail=newnode;
    }
}

void display()
{
    if(tail==NULL)
    {
        printf("List is empty.\n");
        return;
    }
    node *temp=tail->next;
    do
    {
        printf("%d ",temp->data);
        temp=temp->next;
    }while(temp!=tail->next);
    printf("\n");
}

void addatbeg()
{
    int data;
    printf("Enter the data you want to insert: ");
    scanf("%d",&data);
    newnode=(node*)malloc(sizeof(node));
    newnode->data=data;
    newnode->next=tail->next;
    tail->next=newnode;
}

void addatend()
{
    int data;
    newnode=(node*)malloc(sizeof(node));
    printf("Enter the data you want to insert: ");
    scanf("%d",&data);
    newnode->data=data;
    newnode->next=tail->next;
    tail->next=newnode;
    tail=newnode;
}

void addatpos()
{
    int data,pos;
    printf("Enter the data you want to insert: ");
    scanf("%d",&data);
    printf("Enter the position you want to insert: ");
    scanf("%d",&pos);
    newnode=(node*)malloc(sizeof(node));
    newnode->data=data;
    node *temp=tail->next;
    for(int i=1;i<pos-1;i++)
    {
        temp=temp->next;
    }
    newnode->next=temp->next;
    temp->next=newnode;
}

int main()
{
    tail=NULL;
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