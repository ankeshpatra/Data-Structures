#include <stdio.h>
#include <stdlib.h>

void create(int *a,int n)
{
    int i;
    for(i=0;i<n;i++)
    {
        printf("Enter the %d element: ",i+1);
        scanf("%d",(a+i));
    }
}


void delete(int *a,int n)
{
    int pos,i;
    printf("Enter the position you want to delete from: ");
    scanf("%d",&pos);
    if(pos>n || pos<0)
    {
        printf("Invalid position\n");
        return;
    }
    for(i=pos-1;i<n-1;i++)
    {
        *(a+i)=*(a+i+1);
    }
    n--;
    display(a,n);
}

void display(int *a,int n)
{
    int i;
    printf("The elements in the array are: \n");
    for(i=0;i<n;i++)
    {
        printf("%d,",*(a+i));
    }
    printf("\n");
}

int main()
{
    int n,*a;
    printf("Enter the number of elements: ");
    scanf("%d",&n);
    a = (int*)malloc(n*sizeof(int));
    create(a,n);
    display(a,n);
    delete(a,n);
    return 0;
}