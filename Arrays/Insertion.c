//Insertion of an element in an array at any position.
#include<stdlib.h>
#include<stdio.h>

void create(int *a,int n)
{
    int i;
    for(i=0;i<n;i++)
    {
        printf("Enter the %d element: ",i+1);
        scanf("%d",(a+i));
    }
}

void display(int *a,int n)
{
    int i;
    printf("The Elements of the array are: ");
    for(i=0;i<n;i++)
    {
        printf("%d,",*(a+i));
    }
    printf("\n");
}

void insert(int *a,int n)
{
    int pos,key,i;
    printf("Enter the element to insert: ");
    scanf("%d",&key);
    printf("Enter the position to insert the element: ");
    scanf("%d",&pos);
    if(pos>n || pos<0)
    {
        printf("The position is invalid\n");
        return;
    }
    for(i=n-1;i>=pos-1;i--)
    {
        *(a+i+1)=*(a+i);
    }
    *(a+pos-1)=key;
    n++;
    display(a,n);
}

int main()
{
    int n,i;
    int *a;
    printf("Enter the number of elements: ");
    scanf("%d",&n);
    a=(int*)malloc(n*sizeof(int));
    create(a,n);
    display(a,n);
    insert(a,n);
    return 0;
}