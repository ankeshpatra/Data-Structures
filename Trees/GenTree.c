#include <stdio.h>
#include <stdlib.h>
typedef struct node
{
    int data;
    struct node *left,*right;
}Node;
Node *create()
{
    int x;
    Node *newnode = (Node*)malloc(sizeof(Node));
    printf("Enter the data(-1 to stop):");
    scanf("%d",&x);
    if(x==-1)
        return NULL;
    newnode->data=x;
    printf("Enter the node to left of %d:\n",x);
    newnode->left=create();
    printf("Enter the node to right of %d:\n",x);
    newnode->right=create();
    return newnode;
}
void preorder(Node *root)
{
    if(root==NULL)
        return;
    printf("%d",root->data);
    preorder(root->left);
    preorder(root->right);
}

void inorder(Node *root)
{
    if(root==NULL)
        return;
    inorder(root->left);
    printf("%d",root->data);
    inorder(root->right);
}

void postorder(Node *root)
{
    if(root==NULL)
        return;
    postorder(root->left);
    postorder(root->right);
    printf("%d",root->data);
}

int main(int argc, char const *argv[])
{
    Node *root=NULL;
    root=create();
    printf("Inorder: ");
    inorder(root);
    printf("\n");

    printf("Preorder: ");
    preorder(root);
    printf("\n");

    printf("Postorder: ");
    postorder(root);
    printf("\n");
    return 0;
}
